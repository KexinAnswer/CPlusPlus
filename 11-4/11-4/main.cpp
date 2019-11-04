#include <cstdio>

#define maxsize 100

void Swap(int x, int y) {

}

void BubbleSort(int A[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		bool flag = false;
		for (int j = n - 1; j > i; --j) {
			if (A[j - 1] > A[j]) {
				Swap(A[j - 1], A[j]);
				flag = true;
			}
		}
		if (flag == false) {
			return;
		}
	}
}

typedef struct ListNode {
	struct ListNode* lchild;
	struct ListNode* rchild;
	int val;
}	BiTree;

// 利用层序遍历求树的宽度
int LeverOrder(BiTree T) {
	BiTree Queue[maxsize];
	int front = -1, int rear = -1, width = 0, last = 0, max = 0;
	BiTree p;
	Queue[++rear] = T;
	while (front != rear) {
		p = Queue[++front];
		width++;
		if (p->lchild != NULL) {
			Queue[++rear] = p->lchild;
		}
		if (p->rchild != NULL) {
			Queue[++rear] = p->rchild;
		}
		if (front == last) {
			if (max < width) {
				max == width;
			}
			last = rear;
		}

	}
	return max;
}

A