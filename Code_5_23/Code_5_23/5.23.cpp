#include <iostream>
#include <vector>

//int main()
//{
//	int num;
//	std::vector<int> vec;
//	while (std::cin >> num);
//	vec.push_back(num);
//
//	int A = (vec[0] + vec[2]) / 2;
//	int B = (vec[1] + vec[3]) / 2;
//	int C = vec[3] - B;
//	std::cout << A << " " << B << " " << C << std::endl;
//
//	return 0;
//}

int main()
{
	int i = 5;
	char ch = 5 + '0';
	char a = '16';
	char b = '2';
	char c = a / b;


	std::cout << c << std::endl;

	return 0;
}

//#include <iostream>
//#include <algorithm>
//#include <string>
//
//int main()
//{
//	int M;
//	int N;
//	while (std::cin >> M >> N)
//	{
//		long long num = M;
//		int n = N;
//		std::string str;
//		str.reserve(32);
//		while (num != 0)
//		{
//			long ret = num % n;
//			if (ret < 10)
//				str += ('0' + ret);
//			else
//				str += (ret - 10 + "A");
//			num /= n;
//		}
//
//		std::reverse(str.begin(), str.end());
//
//		std::cout << str << std::endl;
//	}
//	return 0;
//}