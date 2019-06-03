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
		//判断字符串是否按字典排序
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

		//判断字符串是否按长度排序
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
	cout << "求两个数的最大公约数及最小公倍数" << endl << endl;
	cout << "请输入两个数：";
	cin >> num1 >> num2;
	gcd = GCD(num1, num2);
	lcm = LCM(num1, num2);//输出最大公约数和最小公倍数
	cout << "最大公约数为：" << gcd << endl;
	cout << "最小公倍数为：" << lcm << endl;
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
	temp_lcm = a * b / GCD(a, b);//最小公倍数等于两数之积除以最大公约数
	return temp_lcm;
}