#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
using namespace std;

template <class T>
class Vector
{
public:

	typedef T* iterator;
	typedef const T* const_iterator;
	Vector()
		:_start(nullptr)
		,_finish(nullptr)
		,_endOfStorage(nullptr)
	{

	}
	Vector(const Vector<T>& v)
	{

		//���ٿռ�
		T* _start = new T[v.Size()];

		//�������ݣ���� ������memcpy
		for (int i = 0; i < v.Size(); i++)
		{
			_start[i] = v[i];

		}

		//����
		_finish = _start + v.Size();
		_endOfStorage = _start + v.Capacity();
	}

	~Vector()
	{
		if (_start)
		{
			delete[] _start;
			_start = _finish = _endOfStorage = nullptr;
		}
	}

	void Swap(Vector<T>& v)
	{
		Swap(_start, v._start);
		Swap(_finish, v._finish);
		Swap(_endOfStorage, v._endOfStorage);
	}

	Vector<T>& operator=(Vector<T> v)
	{
		Swap(v);
		return *this;
	}

	size_t Size()const
	{
		return _finish - _start;
	}

	size_t Capacity()
	{
		return _endOfStorage - _start;
	}

	void Reserve(size_t n)
	{
		if (n > Capacity())
		{
			size_t size = Size();
			T* newC = new T[n];

			//���ռ��Ƿ�Ϊ��
			if (_start)
			{
				//����ԭ�пռ������,ǳ����
				//memcpy(newC , _start , sizeof(T) * Size());

				//���������T���͵ĸ�ֵ�����������ɿ���
				for (size_t i = 0; i < size; i++)
				{
					newC[i] = _start[i];
				}

				delete[] _start;
			}

			//����
			_start = newC;
			_finish = _start + size;
			_endOfStorage = _start + n;
		}
	}

	void PushBack(const T& val)
	{
		if (_finish == _endOfStorage)
		{
			size_t newC = (_start == _endOfStorage ? 1 : 2 * Capacity());
			Reserve(newC);
		}
		*_finish = val;

		//����size
		++_finish;
	}

	T& operator[](size_t pos)
	{
		assert(pos < Size());
		return _start[pos];
	}

	iterator Begin()
	{
		return _start;
	}

	iterator End()
	{
		return _finish;
	}

	const_iterator Begin() const
	{
		return _start;
	}

	const_iterator End() const
	{
		return _finish;
	}

	//insert , erase ���ڵ�����ʧЧ������
	//intsert: ���ݵ��ӵ�����ʧЧ �� ���ݺ���µ�����

	void Insert(iterator pos, const T& val)
	{
		assert(pos >= _start && pos <= _finish);
		size_t len = pos - _start;
		//�ռ䲻��������
		if (_finish == _endOfStorage)
		{
			size_t newC = (_start == nullptr ? 1 : 2 * Capacity());
			Reserve(newC);
			//�������������µ�����
		}
		pos = _start + _start;
		iterator end = _finish;

		while (end > pos)
		{
			*end = *(end - 1);
			end--;
		}
		//��pos������val
		*pos = val;
		//����_finishָ��
		++_finish;
		
	}

	// Erase ���µ�����ʧЧ�����ܵ��µ���������Խ�磬����λ�÷����쳣
	//����Erase �ķ���ֵ�����µ�����

	iterator Erase(iterator pos)
	{
		assert(pos < _finish && pos > _start);
		iterator begin = pos + 1;
		while (begin < _finish)
		{
			*(begin - 1) = *begin;
			begin++;
		}
		--_finish;
		return pos;
	}

	void Resize(size_t n, const T& val = T())
	{
		if (n < Size())
		{
			_finish = _start + n;
			return;
		}
		else
		{
			if (n > Capacity())
			{
				Reserve(n);
			}

			while (_finish != _start + n)
			{
				*_finish = val;
				_finish++;
			}
		}
	}
private:
	T* _start;
	T* _finish;
	T* _endOfStorage;
};

template<class T>
void PrintVector( Vector<T>& const v)
{
	for (size_t i = 0; i < v.Size(); ++i)
	{
		cout << v[i]  << " ";
	}
	cout << endl;
}

void testVector_iterator()
{
	Vector<int> v1;
	v1.PushBack(1);
	v1.PushBack(2);
	v1.PushBack(3);
	v1.PushBack(4);
	v1.PushBack(5);

	PrintVector(v1);

	Vector<string> v2;
	v2.PushBack("h");
	v2.PushBack("e");
	v2.PushBack("l");
	v2.PushBack("l");
	v2.PushBack("o");

	PrintVector(v2);
}