#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int StrToInt(string str) {
		int ret = 0;
		int flag = 1;
		if (str[0] == '-')
			flag = -1;
		for (int i = 1; i < str.size(); ++i)
		{
			if (str[i]< '0' || str[i]>'9')
			{
				return 0;
			}
			int num = str[i] - '0';
			ret = ret * 10 + num;
		}

		return ret * flag;
	}
};

int main()
{
	Solution str1;
	int i = str1.StrToInt("+123456");

	cout << i << endl;
	return 0;
}