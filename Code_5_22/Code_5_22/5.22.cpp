//每个测试输入包含 n个空格分割的n个整数，n不超过100，
//其中有一个整数出现次数大于等于n / 2。
//输出出现次数大于等于n / 2的数
#include<iostream>
using namespace std;
int main() {
	int a[1000] = { 0 };	//数组置0，然后输入n，则对应位置加1，最后遍历数组
	int n, num = 0;		 //找到大于等于一半次数的那个
	while (cin >> n) {
		a[n]++;
		num++;
	}
	for (int i = 0; i < num; i++) {
		if (a[i] >= num / 2)
			cout << i << endl;
	}
	return 0;
}