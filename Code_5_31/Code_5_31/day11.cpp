#include <iostream>

int main()
{
	int num;
	while (std::cin >> num)
	{
		//记录最大连续数
		int count = 0;
		int ret = 0;

		int cur = num;
		while (cur > 0)
		{
			count = 0;
			while (cur & 1 == 1 && cur & 2 == 2)
			{
				count++;
				cur = cur >> 1;
			}
			count++;

			if (ret < count)
			{
				ret = count;
			}

			if (cur == 0)
				break;
			else
				cur = cur >> 1;
		}

		std::cout << ret << std::endl;


	}

	return 0;
}