//#include <iostream>
//#include <stack>
//#include <queue>
//
//using namespace std;
//
//class MyStack {
//public:
//	/** Initialize your data structure here. */
//	MyStack() {
//
//	}
//
//	/** Push element x onto stack. */
//	void push(int x) {
//		if (queueS2.size() == 0)
//		{
//			queueS1.push(x);
//		}
//		if (queueS1.size() == 0)
//		{
//			queueS2.push(x);
//		}
//	}
//
//	/** Removes the element on top of the stack and returns that element. */
//	int pop() {
//		int ret;
//		if (queueS2.size() == 0)
//		{
//			while (queueS1.size() > 1)
//			{
//				queueS2.push(queueS1.front());
//				queueS1.pop();
//			}
//
//			ret = queueS1.front();
//			queueS1.pop();
//		}
//		if (queueS1.size() == 0)
//		{
//			while (queueS2.size() > 1)
//			{
//				queueS1.push(queueS2.front());
//				queueS2.pop();
//			}
//
//			ret = queueS2.front();
//			queueS2.pop();
//		}
//
//		return ret;
//	}
//
//	/** Get the top element. */
//	int top() {
//		int ret;
//		if (queueS1.size() == 0)
//		{
//			while (queueS2.size() > 1)
//			{
//				queueS1.push(queueS2.front());
//				queueS2.pop();
//			}
//
//			ret = queueS2.front();
//			queueS1.push(ret);
//			queueS2.pop();
//		}
//		if (queueS2.size() == 0)
//		{
//			while (queueS1.size() > 1)
//			{
//				queueS2.push(queueS1.front());
//				queueS1.pop();
//			}
//
//			ret = queueS1.front();
//			queueS2.push(ret);
//			queueS1.pop();
//		}
//		return ret;
//	}
//
//	/** Returns whether the stack is empty. */
//	bool empty() {
//		return queueS1.empty() && queueS2.empty();
//	}
//private:
//	queue<int> queueS1;
//	queue<int> queueS2;
//};
//
///**
// * Your MyStack object will be instantiated and called as such:
// * MyStack* obj = new MyStack();
// * obj->push(x);
// * int param_2 = obj->pop();
// * int param_3 = obj->top();
// * bool param_4 = obj->empty();
// */
//int main()
//{
//	MyStack	s;
//	s.push(1);
//	s.push(2);
//	s.push(3);
//
//	int pop = s.pop();
//	pop = s.pop();
//	pop = s.pop();
//
//
//	return 0;
//}
//
///**
// * Your MyStack object will be instantiated and called as such:
// * MyStack* obj = new MyStack();
// * obj->push(x);
// * int param_2 = obj->pop();
// * int param_3 = obj->top();
// * bool param_4 = obj->empty();
// */



#include <iostream>
#include  <queue>
#include <stack>

using namespace std;

template <class T, class Container = deque<T>>
class Queue
{
	void Push(const T& x)
	{
		_con.push_back(x);
	}

	void Pop()
	{
		_con.pop_front();
	}

	T& Front()
	{
		return _con.front();
	}

	size_t Size()
	{
		return _con.size();
	}

	bool Empty()
	{
		return _con.empty();
	}

	T& Back()
	{
		return _con.back();
	}

private:
	Container _con;
};