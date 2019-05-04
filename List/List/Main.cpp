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

//������ʵ�֣�ͨ����װ�ڵ㣬ʹ�ýڵ�Ĳ�����ɵ������� ++ * -- != == ����
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
	//�ƶ�����һ���ڵ��λ��
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
	//�ƶ�����һ���ڵ��λ��
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
	//��ȡ�ڵ��val
	T& operator*()
	{
		return _node->val;
	}

	//iterator != l.end()
	//�Ƚ�������������װ�Ľڵ��Ƿ�һ��
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
	//const �����ܵ��÷�const ��Ա���� ��ֻ�ܵ���const��Ա����
	//����const��Ա����operator++ , operator-- ���Ͳ����޸ĳ�Ա_node��ֵ
	//����const �������޷�ִ��++ �� -- ������ �����¶���const ����������

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

//������
//1.���Ԫ�صķ��ʣ�����������ָ��� ++ �� -- �� * ����=�� == ��Щ����
//2.���������ڵ�ռ䲻������ԭ��ָ�� ++ �� -- �������ƶ�����һ���ڵ��λ�ã�������������ԭ��ָ��ʵ��
//3.��ͨ����װ�ڵ㣬���ʵ�ֵ���������ز���
//++ �� --��ͨ���ڵ��->next �� ->prevʵ��
//��= ==��ͨ���жϽڵ�ĵ�ַ�Ƿ����ʵ��

//iterator �� const_terator Ψһ��ͬ�ĵط����ڣ������� * �� -> ����ֵ��ͬ
//iterator �� * �� ->�������ǿɶ���д�Ĳ����� ����ֵ����const
//const_iterator �� * �� -> ����ֻ�ǿɶ�����������ֵ��const

//list��Ҫʵ�����������ǳ����ֻ��������ģ���е�ͷָ��