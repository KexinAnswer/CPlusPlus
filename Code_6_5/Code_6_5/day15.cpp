//#include <iostream>
//#include <vector>
//
//using namespace std;
//	int findMinimum(int n, vector<int> left, vector<int> right) {
//		// write code here
//		int left_max = 0;
//		int right_max = 0;
//		int left_zero = 0;
//		int right_zero = 0;
//		int zero = 0;
//
//		for (int i = 0; i < n; ++i)
//		{
//			//�ҳ����� ��ɫ�������׺���ɫ�������׸���������ǰ��ɫû�����׵��������
//			if (left[i] > left_max)
//			{
//				left_max = left[i];
//			}
//
//			if (left[i] == 0)
//			{
//				left_zero++;
//			}
//
//			//�ҳ����� ��ɫ�������׺���ɫ�������׸���������ǰ��ɫû�����׵��������
//			if (right[i] > right_max)
//				right_max = right[i];
//
//			if (right[i] == 0)
//				right_zero++;
//
//			if (left[i] & right[i] == 0)
//				zero++;
//
//		}
//		int left_min = left_max;
//		int right_min = right_max;
//		for (int i = 0; i < n; ++i)
//		{
//			if (left[i] < left_min && left[i] > 0)
//			{
//				left_min = left[i];
//			}
//			if (right[i] < right_min && right[i] > 0)
//				right_min = right[i];
//		}
//		int ret = 0;
//		int max = 0;
//		int min = 0;
//
//		if (left_zero >= n - 2)
//		{
//			return left_min + 1 + right_max + n - right_zero - 1;
//		}
//
//		if (right_zero >= n - 2)
//		{
//			return right_min + 1 + left_max + n - left_zero - 1;
//		}
//
//		if (left_min <= right_min)
//		{
//			ret = left_min + 1;
//			ret += right_max + n - right_zero - 1;
//		}
//
//		if (ret > right_min + 1 + left_max + n - left_zero - 1)
//			ret = right_min + 1 + left_max + n - left_zero - 1;
//		return ret;
//
//
//	}
//
//
//int main()
//{
//	vector<int> left;
//	vector<int> right;
//	int num = 0;
//	while (std::cin >> num)
//	{
//
//		
//
//	}
//
//
//	return 0;
//}
//
//#include <iostream>
//
//int main()
//{
//	int num;
//	while (std::cin >> num)
//	{
//		int count = 0;
//		while (num)
//		{
//			if (num % 2 == 1)
//			{
//				count++;
//			}
//			num /= 2;
//		}
//
//		std::cout << count << std::endl;
//
//	}
//
//	return 0;
//}

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

	int findMinimum(int n, vector<int> left, vector<int> right) {
		// write code here
		int sum = 0;
		int left_min = 30;
		int right_min = 30;
		int left_sum = 0;
		int right_sum = 0;
		for (int i = 0; i < n; ++i)
		{
			if (left[i] * right[i] == 0)
				sum = sum + left[i] + right[i];
			else
			{
				left_sum += left[i];
				right_sum += right[i];
				left_min = min(left[i], left_min);
				right_min = min(right[i], right_min);
			}

		}
		int min = (left_sum - left_min + 1 , right_sum - right_min +1 );

		int ret =  sum + min + 1;
		return ret;
	}

	int main()
	{

		int n;
		while (std::cin >> n)
		{
			vector<int> left;
			vector<int> right;
			for (int i = 0; i < n; ++i)
			{
				int val = 0;
				std::cin >> val;
				left.push_back(val);
			}

			for (int i = 0; i < n; ++i)
			{
				int val = 0;
				std::cin >> val;
				right.push_back(val);
			}

			int ret = findMinimum(n, left, right);

			cout << ret << endl;
		}

		return 0;
}