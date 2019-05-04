#include <list>
#include <iostream>
#include <vector>

using namespace std;

template <class T>
struct ListNode
{
	ListNode(const T& val = t())
		:_prev(nullptr)
		,_next(nullptr)
		,_val(val)
	{}
	ListNode<T>* _prev;
	ListNode<T>* _next;
	T _val;
 
};

//迭代器实现：通过封装节点，使用节点的操作完成迭代器的 ++ * -- != == 功能
template <class T>
class ListIterator
{
	typedef ListNode<T>* pNode;
	typedef ListIterator<T> self;
	pNode _node;
	ListIterator(pNode node)
		:_node(node)
	{}

	//++iterator
	ListIterator<T>& operator++()
	{
		_node = _node->next;
		return *this;
	}

	//iterator++
	//移动都下一个节点的位置
	ListIterator<T> operator++(int)
	{
		self tmp(*this);
		_node = _node->next;
		return tmp;
	}

	//--iterator
	ListIterator<T>& operator--()
	{
		_node = _node->prev;
		return *this;
	}

	//iterator--
	//移动都上一个节点的位置
	ListIterator<T> operator--(int)
	{
		self tmp(*this);
		_node = _node->prev;
		return tmp;
	}

	//struct a{ int b , int c , int d} a *pa pa->b
	//iterator->->
	T* operator->()
	{
		return _node->_val;
	}

	//*iterator
	//获取节点的val
	T& operator*()
	{
		return _node->val;
	}

	//iterator != l.end()
	//比较两个迭代器封装的节点是否一样
	bool operator!=(const self& if)
	{
		return _node != it._node;
	}

};


template <class T>
class List
{

public:
	typedef ListNode<T> Node;
	typedef Node* pNode;
	typedef ListIterator<T> iterator;
	//const 对象不能调用非const 成员函数 ，只能调用const成员函数
	//单数const成员函数operator++ , operator-- ，就不能修改成员_node的值
	//导致const 迭代器无法执行++ ， -- 操作， 故如下定义const 迭代器不行

	typedef const ListIterator<T> iterator;

	ListNode(const T& val = T())
		:_head(new Node(val))
	{
		_head->next = _head->prev = _head;
	}

	void PushBack(const T& val)
	{
		pNode curNode = new Node(val);
		pNode prev = head
	}

	iterator begin()
	{
		return iterator(_head->_next);
	}

	iterator end()
	{
		return iterator(_head);
	}

private:
	void CreatHead()
	{

	}
private:
	pNode _head;
};

int main()
{

	List<int> lst;

	lst.PushBack(1);


	return 0;

}

//迭代器
//1.完成元素的访问，具有类似于指针的 ++ ， -- ， * ，！=， == 这些操作
//2.对于链表，节点空间不连续，原生指针 ++ ， -- 不能以移动到下一个节点的位置，迭代器不能用原生指针实现
//3.故通过封装节点，间接实现迭代器的相关操作
//++ ， --：通过节点的->next ， ->prev实现
//！= ==：通过判断节点的地址是否相等实现

//iterator 和 const_terator 唯一不同的地方在于：操作符 * 和 -> 返回值不同
//iterator 的 * 和 ->操作都是可读可写的操作， 返回值不加const
//const_iterator 的 * 和 -> 操作只是可读操作，返回值加const

//list需要实现深拷贝，否则浅拷贝只拷贝对象模型中的头指针