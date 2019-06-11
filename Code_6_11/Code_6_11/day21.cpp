#include <string>
#include <iostream>

int main()
{
	std::string str1;
	std::string str2;
	while (std::cin >> str1 >> str2)
	{
		int p1 = str1.size();
		int p2 = str2.size();
		int count = 0;
		for (int i = 0; i < p1; ++i)
		{
			for (int j = 0; j < p2; ++j)
			{
				int k = 0;
				while (str1[k + i] == str2[j + k] && k <= p1 && k <= p2)
				{
					++k;
				}

				if (count < k)
				{
					count = k;
				}
			}
		}

		std::cout << count << std::endl;
	}

	return 0;
}


#include <algorithm>
#include <iostream>
#include <string>
int main()
{
	std::string str;
	while (std::cin >> str)
	{
		std::string ret;
		for (int i = str.size() - 1; i >= 0; --i)
		{
			ret += str[i];
		}

		std::cout << ret << std::endl;
	}

	return 0;
}