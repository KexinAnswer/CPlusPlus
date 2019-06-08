#include <iostream>
#include <string>

int main()
{
	std::string str1;
	std::string str2;
	while (std::cin >> str1 >> str2)
	{
		int i = 0;
		int j = 0;
		while (i < str1.size() && j < str2.size())
		{
			if (str1[i] == '?')
			{
				i++;
				j++;
				continue;
			}
			else if ((str1[i] == '*' && str1[i + 1] != str2[j])
				&& (str2[j] > '0' || str2[j] < '9'
					|| str2[j] >= 'a' || str2[j] <= 'z'
					|| str2[j] >= 'A' || str2[j] <= 'z'))
			{
				//Æ¥Åäµ½Í¨Åä·û * 
				j++;
				continue;
			}
			else if (str1[i] == '*' && str1[i + 1] == str2[j])
			{
				i++;
			}
			else if (str1[i] != str2[j]) {
				break;
			}
			else
			{
				i++;
				j++;
			}


		}
		if (j == str2.size())
		{
			std::cout << "true" << std::endl;;
		}
		else {
			std::cout << "false" << std::endl;
		}
	}

	return 0;
}