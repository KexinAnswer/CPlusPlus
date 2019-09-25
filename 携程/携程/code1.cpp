#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;

class ListNode {
public:
	int val;
	ListNode* next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	};
};

/*请完成下面这个函数，实现题目要求的功能
******************************开始写代码******************************/
ListNode* partition(ListNode* head, int m) {
	ListNode* smallHead = NULL;
	ListNode* maxHead = NULL;
	ListNode* cur1 = NULL;
	ListNode* cur2 = NULL;
	while (head != NULL) {
		if (head->val <= m) {
			if (smallHead == NULL) {
				smallHead = head;
				cur1 = head;
			}
			else {
				cur1->next = head;
				cur1 = head;
			}
		}
		else {
			if (maxHead == NULL) {
				maxHead = head;
				cur2 = head;
			}
			else {
				cur2->next = head;
				cur2 = head;
			}
		}
	}

	cur2->next = NULL;
	cur1->next = maxHead;
	return smallHead;

}
/******************************结束写代码******************************/


int main() {
	ListNode* head = NULL;
	ListNode* node = NULL;
	int m;
	cin >> m;
	int v;
	while (cin >> v) {
		if (head == NULL) {
			node = new ListNode(v);
			head = node;
		}
		else {
			node->next = new ListNode(v);
			node = node->next;
		}
	}
	head = partition(head, m);
	if (head != NULL) {
		cout << head->val;
		node = head->next;
		delete head;
		head = node;
		while (head != NULL) {
			cout << "," << head->val;
			node = head->next;
			delete head;
			head = node;
		}
	}
	cout << endl;
	return 0;
}