#include <iostream>
#include <string>
#include <vector>
#include <string.h>

int main()
{
	int n;
	while (std::cin >> n)
	{
		std::vector<std::string> vec;
		std::string str;
		for (int i = 0; i < n; ++i)
		{
			std::cin >> str;
			vec.push_back(str);
		}
		int i = 0;
		//�ж��ַ����Ƿ��ֵ�����
		int isDic = 0;
		for (i = 0; i < vec.size() - 1; ++i)
		{
			if ((vec[i].size()) > (vec[i + 1].size()))
				break;
		}

		if (i < vec.size()-1)
			isDic = 0;
		else
			isDic = 1;

		//�ж��ַ����Ƿ񰴳�������
		int isSort = 0;
		for (i = 0; i < vec.size() - 1; ++i)
		{
			if (vec[i] > vec[i + 1])
				break;
		}
		if (i < vec.size()-1)
			isSort = 0;
		else
			isSort = 1;

		if (isDic == 1 && isSort == 1)
		{
			std::cout << "both" << std::endl;
		}
		else if (isDic == 0 && isSort == 1)
		{
			std::cout << "lengths" << std::endl;
		}
		else if (isDic == 1 && isSort == 0)
		{
			std::cout << "lexicographically" << std::endl;
		}
		else
		{
			std::cout << "none" << std::endl;
		}

	}

	return 0;
}



#include<iostream>
using namespace std;
int GCD(int a, int b);
int LCM(int a, int b);
int main()
{
	int num1, num2, gcd, lcm;
	cout << "�������������Լ������С������" << endl << endl;
	cout << "��������������";
	cin >> num1 >> num2;
	gcd = GCD(num1, num2);
	lcm = LCM(num1, num2);//������Լ������С������
	cout << "���Լ��Ϊ��" << gcd << endl;
	cout << "��С������Ϊ��" << lcm << endl;
	system("pause");
	return 0;
}
int GCD(int num1, int num2)
{
	if (num1%num2 == 0)
		return num2;
	else return  GCD(num2, num1%num2);
}
int LCM(int a, int b)
{
	int temp_lcm;
	temp_lcm = a * b / GCD(a, b);//��С��������������֮���������Լ��
	return temp_lcm;
}