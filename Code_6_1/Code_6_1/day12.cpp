//#include <iostream>
//
//int isPrime(int num)
//{
//	int count = 0;
//	for (int i = 2; i < num; ++i)
//	{
//		if (num % i == 0)
//			count++;
//	}
//
//	if (count == 0)
//		return num;
//	return -1;
//
//}
//
//int main()
//{
//	int num = 0;
//	while (std::cin >> num)
//	{
//		int p1 = 0;
//		int p2 = 0;
//		int val = num;
//		for (int i = 2; i < num / 2 + 1; i++)
//		{
//			if (isPrime(i) != -1 && isPrime(num - i) != -1)
//			{
//				p1 = i;
//
//
//				p2 = num - i;
//
//			}
//
//		}
//		std::cout << p1 << std::endl;
//		std::cout << p2 << std::endl;
//	}
//
//	return 0;
//}

class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		// write code here

		int low = (1 << j) - 1;
		//保存低位
		low = low & n;
		//清除中间位
		int cur = n;
		cur = cur >> i;
		cur = cur << (i - j);

		cur += m;
		cur = cur << j;
		cur += low;

		return cur;
	}
};