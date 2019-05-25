#include <iostream>
#include <string>


//
//int main()
//{
//	int n[][3] = { 10,20,30,40,50,60 };
//	int(*p)[3] = n;
//	std::cout << p[0][0] << ' ' << *(p[0] + 1) << ' ' << (*p)[2] <<std::endl;
//
//	return 0;
//}

//
//int main()
//{
//
//	std::string str1;
//	std::string str2;
//	std::cin >> str1 >> str2;
//	std::string end;
//	end = str1.substr(2,str1.size());
//	//获取中间插入位置前的字符串
//	std::string begin = str1.substr(0,2);
//
//	std::string judge = begin + str2 + end;
//
//	std::cout << judge << std::endl;
//
//	return 0;
//}
//
//#include <iostream>
//#include <string>
//#include <algorithm>
//
//int main()
//{
//	std::string str1;
//	std::string str2;
//	while (std::cin >> str1 >> str2)
//	{
//		int count = 0;
//		for (int i = 0; i < str1.size(); ++i)
//		{
//			//获取中间插入位置后的字符串
//			std::string end;
//			end = str1.substr(i, str1.size());
//			//获取中间插入位置前的字符串
//			std::string begin = str1.substr(0, i);
//
//			std::string judge = begin + str2 + end;
//			std::string pdrome(judge);
//			std::reverse(judge.begin(), judge.end());
//			if (judge == pdrome)
//			{
//				count++;
//			}
//		}
//
//		std::cout << count << std::endl;
//	}
//
//	return 0;
//}
//
//#include <iostream>
//#include <vector>
//
//int main()
//{
//	int n = 0;
//	while (std::cin >> n)
//	{
//		std::vector<int> num;
//		num.resize(n);
//		for (int i = 0; i < n; ++i)
//		{
//			std::cin >> num[i];
//		}
//
//		//求连续子数组最大和
//		int count = 0;
//		for (int i = 0; i < num.size(); ++i)
//		{
//			int add = 0;
//			while (num[i] > 0 && i < num.size())
//			{
//				add += num[i];
//				++i;
//
//				if (add >= count)
//				{
//					count = add;
//				}
//			}
//		}
//
//		std::cout << count << std::endl;
//
//	}
//
//
//	return 0;
//}


#include <stdio.h>

int main()
{
	//C语言 字符串转整数
	//atoi
	//sprintf/sscanf

	//c++
	//stringstream
	//std::stio
	//boost

}