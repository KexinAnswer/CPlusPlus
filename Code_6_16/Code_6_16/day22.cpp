���ӣ�https://www.nowcoder.com/questionTerminal/e896d0f82f1246a3aa7b232ce38029d4
��Դ��ţ����

�ҳ��ַ����е�һ��ֻ����һ�ε��ַ�


��������:
����һ���ǿ��ַ���

������� :
�����һ��ֻ����һ�ε��ַ��������������� - 1

ʾ��1
����
asdfasdfo
���
o

#include <iostream>
#include <string>

int main()
{
	using namespace std;
	string str;
	while (getline(cin, str))
	{
		unsigned int i;
		for (i = 0; i < str.size(); i++)
		{
			if (str.find(str[i]) == str.rfind(str[i]))
			{
				cout << str[i] << endl;
				break;
			}
		}
		if (i == str.size())
			cout << '.';
	}
	return 0;
}

���ӣ�https://www.nowcoder.com/questionTerminal/fe6c73cb899c4fe1bdd773f8d3b42c3d
��Դ��ţ����

С�׾���������������Ϸ.��һ��, ������һ�������������Ϸ, ���Ľ�ɫ�ĳ�ʼ����ֵΪ a.�ڽ�������һ��ʱ����, ��������������n������, ÿ������ķ�����Ϊb1, b2, b3...bn.��������Ĺ��������biС�ڵ���С�׵ĵ�ǰ����ֵc, ��ô���������ɴ�ܹ���, �� ��ʹ���Լ�������ֵ����bi; ���bi����c, ����Ҳ�ܴ�ܹ���, ����������ֵֻ������bi ��c�����Լ��.��ô��������, ��һϵ�еĶ�����, С�׵���������ֵΪ���� ?

�������� :
	����ÿ������, ��һ������������n(1��n < 100000)��ʾ�����������a��ʾС�׵ĳ�ʼ����ֵ.
	�ڶ���n������, b1, b2...bn(1��bi��n)��ʾÿ������ķ�����


	������� :
����ÿ������, ���һ��.ÿ�н�����һ������, ��ʾС�׵���������ֵ

����
3 50
50 105 200
5 20
30 20 15 40 100
���
110
205

���ӣ�https://www.nowcoder.com/questionTerminal/fe6c73cb899c4fe1bdd773f8d3b42c3d
��Դ��ţ����

#include<iostream>
using namespace std;
int GCD(int a, int b) {//շת���������֤��
	int temp;
	while (b) {
		temp = b; b = a % b; a = temp;
	}
	return (a);
}
int main() {
	int n, c;
	while (cin >> n >> c) {
		int i, temp;
		for (i = 0; i < n; i++) {
			cin >> temp;
			if (c >= temp)
				c += temp;
			else
				c += GCD(c, temp);
		}
		cout << c << endl;
	}
}