//ÿ������������� n���ո�ָ��n��������n������100��
//������һ���������ִ������ڵ���n / 2��
//������ִ������ڵ���n / 2����
#include<iostream>
using namespace std;
int main() {
	int a[1000] = { 0 };	//������0��Ȼ������n�����Ӧλ�ü�1������������
	int n, num = 0;		 //�ҵ����ڵ���һ��������Ǹ�
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