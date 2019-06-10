#include <iostream>
#include <string>

int main()
{
	std::string str1;
	std::string str2;
	while (std::cin >> str1 >> str2)
	{
		int count = 0;
		std::string long_str = str1;
		std::string short_str = str2;
		if (str1.size() < str2.size())
		{
			long_str = str2;
			short_str = str1;
		}

		std::string ret;

		for (int i = 0; i < short_str.size(); ++i)
		{
			for (int j = 0; j < long_str.size(); ++j)
			{
				if (short_str[i] == long_str[j])
				{
					std::string short_sub = short_str.substr(i);
					std::string long_sub = long_str.substr(j);

					int k = 0;
					while (short_sub[k] == long_sub[k])
					{
						++k;
					}

					if (k > count)
					{
						count = k;
						ret = short_sub.substr(0, k);
					}

				}
			}
		}

		std::cout << ret << std::endl;
	}

	return 0;
}