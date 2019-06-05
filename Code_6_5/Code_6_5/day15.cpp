#include <iostream>
#include <vector>

using namespace std;
	int findMinimum(int n, vector<int> left, vector<int> right) {
		// write code here
		int left_max = 0;
		int right_max = 0;
		int left_zero = 0;
		int right_zero = 0;
		int zero = 0;

		for (int i = 0; i < n; ++i)
		{
			//找出左手 颜色最多的手套和颜色最少手套个数，及当前颜色没有手套的种类个数
			if (left[i] > left_max)
			{
				left_max = left[i];
			}

			if (left[i] == 0)
			{
				left_zero++;
			}

			//找出右手 颜色最多的手套和颜色最少手套个数，及当前颜色没有手套的种类个数
			if (right[i] > right_max)
				right_max = right[i];

			if (right[i] == 0)
				right_zero++;

			if (left[i] & right[i] == 0)
				zero++;

		}
		int left_min = left_max;
		int right_min = right_max;
		for (int i = 0; i < n; ++i)
		{
			if (left[i] < left_min && left[i] > 0)
			{
				left_min = left[i];
			}
			if (right[i] < right_min && right[i] > 0)
				right_min = right[i];
		}
		int ret = 0;
		int max = 0;
		int min = 0;

		if (left_zero >= n - 2)
		{
			return left_min + 1 + right_max + n - right_zero - 1;
		}

		if (right_zero >= n - 2)
		{
			return right_min + 1 + left_max + n - left_zero - 1;
		}

		if (left_min <= right_min)
		{
			ret = left_min + 1;
			ret += right_max + n - right_zero - 1;
		}

		if (ret > right_min + 1 + left_max + n - left_zero - 1)
			ret = right_min + 1 + left_max + n - left_zero - 1;
		return ret;


	}


int main()
{
	vector<int> left;
	vector<int> right;
	int num = 0;
	while (std::cin >> num)
	{

		

	}


	return 0;
}

#include <iostream>

int main()
{
	int num;
	while (std::cin >> num)
	{
		int count = 0;
		while (num)
		{
			if (num % 2 == 1)
			{
				count++;
			}
			num /= 2;
		}

		std::cout << count << std::endl;

	}

	return 0;
}