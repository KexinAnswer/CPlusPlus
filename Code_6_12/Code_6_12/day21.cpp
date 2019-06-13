//#include <vector>
//#include <iostream>
//#include <algorithm>
//
//std::vector<int> shuffle(std::vector<int> vec, int n)
//{
//	if (n == 0)
//	{
//		return vec;
//	}
//	std::vector<int> ret;
//	//ret.resize(vec.size());
//	auto it = ret.begin();
//	for (int i = vec.size() - 1; i >= vec.size() / 2; i--)
//	{
//		it = ret.begin();
//		ret.insert(it, vec[i]);
//		it = ret.begin();
//		ret.insert(it, vec[i - (vec.size() / 2)]);
//	}
//
//
//	return shuffle(ret, n - 1);
//
//}
//
//int main()
//{
//	int T;
//	while (std::cin >> T)
//	{
//		std::vector<int> ret;
//
//		for (int i = 0; i < T; ++i)
//		{
//			int n, k;
//			std::cin >> n >> k;
//			std::vector<int> vec;
//			vec.resize(2 * n);
//			for (int j = 0; j < 2 * n; ++j)
//			{
//				int num;
//				std::cin >> num;
//				vec[j] = num;
//			}
//
//			std::vector<int> sf = shuffle(vec, n);
//
//			for (int i = 0; i < sf.size(); ++i)
//			{
//				ret.push_back(sf[i]);
//			}
//		}
//
//		for (int i = 0; i < ret.size(); ++i)
//		{
//			if (i != ret.size() - 1)
//			{
//				std::cout << ret[i] << ' ';
//			}
//			else {
//				std::cout << ret[i] << std::endl;
//			}
//		}
//
//	}
//
//	return 0;
//}


链接：https://www.nowcoder.com/questionTerminal/5a0a2c7e431e4fbbbb1ff32ac6e8dfa0
来源：牛客网

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int T, n, k;
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
		int num = 2 * n;
		vector<int> table(num);
		for (int i = 0; i < num; ++i)
			cin >> table[i];
		while (k--)
		{
			vector<int> n1(table.begin(), table.end());
			for (int i = 0; i < n; ++i)
			{
				table[2 * i] = n1[i];
				table[2 * i + 1] = n1[i + n];
			}
		}
		for (int i = 0; i < num - 1; ++i)
			cout << table[i] << " ";
		cout << table[num - 1] << endl;
	}
	return 0;
}

//
//#include <iostream>
//#include <string>
//int main()
//{
//	int num;
//	while (std::cin >> num)
//	{
//		std::string input;
//		std::cin >> input;
//		int n = 1;
//		int flag = 1;
//		for (int i = 0; i < input.size(); ++i)
//		{
//			if (input[i] == 'U')
//			{
//				if (n == 1)
//				{
//					n = num;
//					flag = 4;
//				}
//				else
//				{
//					n--;
//					flag--;
//					if (flag == 0)
//					{
//						flag = 1;
//					}
//
//				}
//			}
//			else if (input[i] == 'D')
//			{
//				if (n == num)
//				{
//					n = 1;
//					flag = 1;
//				}
//				else
//				{
//					n++;
//					flag++;
//					if (flag == 5)
//					{
//						flag = 4;
//					}
//				}
//
//			}
//		}
//
//		if (num <= 4)
//		{
//			for (int i = 1; i <= num; ++i)
//			{
//				std::cout << i << ' ';
//			}
//		}
//		else {
//			if (n + 3 > num)
//			{
//				for (int i = 3; i >= 0; ++i)
//				{
//					std::cout << num - i << ' ';
//				}
//			}
//			else {
//				if (flag == 1)
//				{
//					std::cout << n << ' ' << n + 1 << ' ' << n + 2 << ' ' << n + 3;
//				}
//				else if (flag == 2) {
//					std::cout << n - 1 << ' ' << n << ' ' << n + 1 << ' ' << n + 2;
//				}
//				else if (flag == 3)
//				{
//					std::cout << n - 2 << ' ' << n - 1 << ' ' << n << ' ' << n + 1;
//				}
//				else if (flag == 4)
//				{
//					std::cout << n - 3 << ' ' << n - 2 << ' ' << n - 1 << ' ' << n;
//				}
//			}
//		}
//		std::cout << std::endl;
//		std::cout << n << std::endl;
//	}
//
//	return 0;
//}

链接：https://www.nowcoder.com/questionTerminal/eaf5b886bd6645dd9cfb5406f3753e15
来源：牛客网

#include <iostream>
#include <string>
using namespace std;
int main() {
	int n;
	string order;
	while (cin >> n >> order)
	{
		int num = 1, first = 1; //将n首歌曲编号1：n , num为光标当前所在歌曲的编号,first为当前屏幕显示页的第一首歌曲的编号
		if (n <= 4) //歌曲总数不超过4时，所有歌曲一页即可显示完，不需翻页，first始终不变
		{
			for (int i = 0; i < order.size(); i++)
			{
				if (num == 1 && order[i] == 'U') num = n;
				else if (num == n && order[i] == 'D') num = 1;
				else if (order[i] == 'U') num--;
				else  num++;
			}
			for (int i = 1; i <= n - 1; i++)
				cout << i << ' ';
			cout << n << endl;
			cout << num << endl;
		}
		else  //歌曲总数大于4时，显示完全所有歌曲需要翻页，屏幕总是显示4首歌曲
		{
			for (int i = 0; i < order.size(); i++)
			{
				if (first == 1 && num == 1 && order[i] == 'U') { first = n - 3; num = n; } //特殊翻页1
				else if (first == n - 3 && num == n && order[i] == 'D') { first = 1; num = 1; } //特殊翻页2
				else if (first != 1 && num == first && order[i] == 'U') { first--; num--; } //一般翻页1
				else if (first != n - 3 && num == first + 3 && order[i] == 'D') { first++; num++; } //一般翻页2
				else if (order[i] == 'U') num--; //其他情况1
				else num++; //其他情况2
			}
			for (int i = first; i < first + 3; i++)
				cout << i << ' ';
			cout << first + 3 << endl;
			cout << num << endl;
		}
	}
	return 0;
}