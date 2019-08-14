#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n;
	while (std::cin >> n)
	{
		int num;
		std::vector<int> vec;
		for (int i = 0; i < n; ++i)
		{
			std::cin >> num;
			vec.push_back(num);
		}

		std::sort(vec.begin(),vec.end());



	}

	return 0;
}