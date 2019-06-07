//链接：https://www.nowcoder.com/questionTerminal/8ef655edf42d4e08b44be4d777edbf43
//来源：牛客网
//
//[编程题]iNOC产品部 - 杨辉三角的变形
//热度指数：9391时间限制：1秒空间限制：32768K
//算法知识视频讲解
//1
//
//1  1  1
//
//1  2  3  2  1
//
//1  3  6  7  6  3  1
//
//1  4  10 16 19  16 10  4  1
//
//以上三角形的数阵，第一行只有一个数1，以下每行的每个数，是恰好是它上面的数，左上角数到右上角的数，3个数之和（如果不存在某个数，认为该数就是0）。
//
//求第n行第一个偶数出现的位置。如果没有偶数，则输出 - 1。例如输入3, 则输出2，输入4则输出3。

//
//输入n(n <= 1000000000)
//
//输入描述:
//输入一个int整数
//
//
//
//输出描述 :
//输出返回的int值
//
//示例1
//输入
//4
//输出
//3
#include <iostream>
#include <vector>

int main()
{
	int num;
	while (std::cin >> num)
	{
		if (num <= 2)
		{
			std::cout << -1 << std::endl;
		}
		else
		{
			std::vector< std::vector <int> > vec;
			vec.resize(num);
			int i = 0;
			int j = 0;
			for (i = 0; i < num; ++i)
			{
				vec[i].resize(2 * (i + 1) + 1);

				for (j = 0; j < 2 * (i + 1) - 1; ++j)
				{
					if (j == 0)
						vec[i][j] = 1;
					else if (j == 1)
						vec[i][j] = vec[i - 1][j - 1] + vec[i - 1][j];
					else
						vec[i][j] = vec[i - 1][j - 2] + vec[i - 1][j - 1] + vec[i - 1][j];
				}
			}
			int ret = -1;
			for (i = 0; i < 2 * num - 1; ++i)
			{
				if (vec[num - 1][i] % 2 == 0)
				{
					ret = i + 1;
					break;
				}
			}

			std::cout << ret << std::endl;
		}



	}
	return 0;
}
//
//链接：https://www.nowcoder.com/questionTerminal/5821836e0ec140c1aa29510fd05f45fc
//来源：牛客网
//
//[编程题]超长正整数相加
//热度指数：10241时间限制：1秒空间限制：32768K
//算法知识视频讲解
//请设计一个算法完成两个超长正整数的加法。

//接口说明

//
///*
//请设计一个算法完成两个超长正整数的加法。
//输入参数：
//String addend：加数
//String augend：被加数
//返回值：加法结果
//*/
//
//public String AddLongInteger(String addend, String augend)
//{
//	/*在这里实现功能*/
//
//
//	return null;
//}
//
//

//输入描述:
//输入两个字符串数字

//
//输出描述 :
//输出相加后的结果，string型
//
//示例1
//输入
//99999999999999999999999999999999999999999999999999
//1
//输出
//100000000000000000000000000000000000000000000000000

#include <iostream>
#include <string>

int main()
{
	std::string str1;
	std::string str2;
	while (std::cin >> str1 >> str2)
	{
		std::string str_long;
		std::string str_short;
		if (str1.size() > str2.size())
		{
			str_long = str1;
			str_short = str2;
		}
		else
		{
			str_short = str1;
			str_long = str2;
		}
		int _long = str_long.size();
		int _short = str_short.size();
		int carry = 0;
		while (_short >= 0)
		{
			str_long[_long] += str_short[_short] - '0';
			if (str_long[_long] > '9' && _long > 0)
			{
				str_long[_long] -= 10;
				str_long[_long - 1] += 1;
			}
			if (str_long[_long] > '9' && _long == 0)
			{
				str_long.insert(0, 1, '1');
			}

			_short--;
			_long--;
		}

		while (str_long[_long] > '9' && _long > 0)
		{
			str_long[_long] -= 10;
			str_long[_long - 1] += 1;
			if (str_long[_long] > '9' && _long == 0)
			{
				str_long.insert(0, 1, '1');
			}

			_long--;
		}
		std::cout << str_long << std::endl;
	}


	return 0;
}