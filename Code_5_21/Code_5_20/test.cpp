//#include <iostream>
//#include <vector>
//
//int main()
//{
//	int n;
//	while (std::cin >> n)
//	{
//		std::vector<int> a;
//		a.resize(n);
//
//		for (int i = 0; i < n; ++i)
//		{
//			std::cin >> a[i];
//		}
//
//		int count = 0;
//		for (int i = 0; i < n; ++i)
//		{
//			while (a[i] <= a[i + 1] && i < n)
//			{
//				i++;
//				if (a[i] > a[i + 1])
//					count++;
//			}
//
//			while (a[i] >= a[i + 1] && i < n)
//			{
//				++i;
//				if (a[i] < a[i + 1])
//					count++;
//			}
//		}
//		//count++;
//
//		std::cout << count << std::endl;
//	}
//
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <string.h>
//#include <vector>
//int main()
//{
//	std::string str;
//	getline(std::cin, str);
//	std::vector<std::string> ret;
//	char* pch;
//	pch = strtok(str.begin(), " ");
//	int i = 0;
//	while (pch != NULL)
//	{
//		ret[i] = pch;
//		pch = strtok(NULL, " ");
//	}
//
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <string.h>
//#include <vector>
//int main()
//{
//	std::string str;
//	getline(std::cin, str);
//	//int begin = 0;
//	int end = str.size() - 1;
//	//std::vector<std::string> ret;
//	size_t pos = 0;
//	while(end >= 0)
//	{
//		pos = str.rfind(' ', end);
//		std::string ret(str.substr(pos+1, end - pos));
//		std::cout << ret << ' ';
//		end = end - ret.size() - 1;
//	}
//
//	return 0;
//}

//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//	string str("I like beijing.");
//	size_t size = str.size();
//	size_t pos = str.rfind(' ', 5);
//	if (pos == string::npos)
//	{
//		cout << "error" << endl;
//		return 1;
//	}
//
//	string output = str.substr(pos + 1, 6 - pos - 1);
//
//	cout << output << endl;
//
//	return 0;
//}

#include<iostream> 
#include<vector>
using namespace std; int main()
{
	int n;
	cin >> n;
	vector<int> v;
	v.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	int ret = 1;
	for (int i = 1; i < n - 1; i++) {
		//找出波峰波谷
		if ((v[i - 1] < v[i] && v[i] > v[i + 1])
			|| (v[i - 1] > v[i] && v[i] < v[i + 1]))
		{
			ret++;
			// 这里对应处理的就是上面情况二描述的问题
			if (i != n - 3)
				i++;
		}
		
	}
	cout << ret << endl;
	return 0;
}