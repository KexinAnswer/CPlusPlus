#include <iostream>
#include <algorithm>
#include <cassert>

template <typename T>
class Vector{
public:
  typedef T* Iterator;
  typedef const T* ConstIterator;
  //////////////////////////////////////////////
  // 迭代器
  Iterator Begin() {return _begin;}
  Iterator End() {return _end;}

  Iterator rBegin() {return _end;}
  Iterator rEnd() {return _begin;}
  //////////////////////////////////////////
  
  // 构造函数
  Vector()
    :_begin(NULL)
     ,_end(NULL)
     ,_endOfStorage(NULL)
  {}
  
  Vector(size_t n,const T value = T())
  :_begin(NULL)
   ,_end(NULL)
   ,_endOfStorage(NULL)
  {
    Reverse(n);
    for(int i = 0; i < n; ++i){
      PushBack(value);
    }
  }

  // 不能使用 成员成员函数的迭代器 ？
  // 重新创建迭代器
  Vector(Iterator begin, Iterator end, const T value = T()){
    size_t capacity = end - begin;
    Reverse(capacity);
    Iterator it = begin;
    while(it != end){
      PushBack(value);
      it++;
    }
  }

  // 拷贝构造

  Vector(const Vector& v)
    :_begin(NULL)
     ,_end(NULL)
     ,_endOfStorage(NULL)
  {
    Reverse(v.Capacity());
    Iterator it = Begin();
    Iterator vit = v._beign;
    while(it != v._end){
      *it++ = *vit++;
    }
    _end = _begin + Size();
    _endOfStorage = _begin + Capacity();
  }
  // 析构函数
  ~Vector(){
    if(_begin){
      delete[] _begin;
    }
    _begin = _end = _endOfStorage = NULL;
  }
  /////////////////////////////////////////////////////////////////////
  // 赋值运算符重载
  Vector<T>& operator=(Vector<T> v){
    Swap(v);
    return *this;
  }

  T& operator[](size_t pos){
    return _begin[pos];
  }
  ///////////////////////////////////////////////////////////////
  // 增删查改
  Iterator Insert(Iterator pos, const T& val){
    assert(pos < Size());
    if(_end == _endOfStorage){
      size_t size = pos - _begin;
      size_t newcapacity = Capacity() == 0 ? 1 : 2 * Capacity();
      Reverse(newcapacity);

      // 更新 pos
      pos = _begin + size;
    }

    Iterator end = _end - 1;
    while(end > pos){
      *(end+1) = *end;
      end--;
    }
    *pos = val;
    _end++;
    return pos;
  }

  Iterator Erase(Iterator pos){
    Iterator it = pos + 1;
    while(it != _end){
      *(it - 1) = *it;
      it++;
    }
    _end--;
    return pos;
  }
  void Swap(Vector<int>& v){
    swap(_begin, v._begin);
    swap(_end, v._end);
    swap(_endOfStorage = v._endOfStorage);
  }
  
  
  void PushBack(const T val){
    Insert(End(),val);
  }

  void PopBack(){
    Erase(End());
  }

  /////////////////////////////////////////////////////////////////
  // 容量
  size_t Capacity(){
    return _endOfStorage - _begin;
  }

  size_t Size(){
    return _end - _begin;
  }
  
  void Resize(size_t n, const T& val = T()){
    // 如果 n < size 将空间缩减到n
    if(n < Size()){
      _end = _begin + n;
      return;
    }
    // 如果 n > size 进行增容
    if(n > Size()){
      Reverse(n);
    }
    // 将size扩大到 n
    Iterator it = _end;
    while(it < _begin + n){
      *it = val;
      ++it;
    }
    _end = _begin + n;
  }

  void Reverse(size_t n){
    // 检查是否需要增容
    if(n > Capacity()){
      // 创建新的空间
      T* tmp = new T[n];
      assert(tmp);

      // 进行 搬运 不能用memset why？
      if(_begin){
        for(int i = 0; i < Size(); ++i){
          tmp[i] = _begin[i];
        }

      }
      // 更新 数据
      _begin = tmp;
      _end = _begin + Size();
      _endOfStorage = _begin + n;
    }
  }
private:
  Iterator _begin;
  Iterator _end;
  Iterator _endOfStorage;
};

