#include <iostream>
#include <string.h>
#include <vector>

int main() {
	int n;
	while (std::cin >> n) {
		int m = n - 1;
		std::vector<int> num;
		std::vector<char> op;
		int _num;
		char _op;
		for (int i = 0; i < m; ++i) {
			std::cin >> _num;
			std::cin >> _op;
			num.push_back(_num);
			op.push_back(_op);
		}
		std::cin >> _num;
		num.push_back(_num);
		int flag = 0;
		do {
			flag = 0;
			for (int i = 0; i < m; ++i) {
				if (op[i] == '-' || op[i] == '/') {
					continue;
				}
				else if (i == 0) {
					if (num[i] > num[i + 1] && op[i] == '+'  && op[i + 1] != '*' && op[i + 1] != '/') {
						std::swap(num[i], num[i + 1]);
						flag = 1;
					}
					else if (num[i] > num[i + 1] && op[i] == '*') {
						std::swap(num[i], num[i + 1]);
						flag = 1;
					}
				}
				else if (i == m - 1) {
					if (num[i] > num[i + 1] && op[i] == '+'  && op[i - 1] == '+') {
						std::swap(num[i], num[i + 1]);
						flag = 1;
					}
					else if (num[i] > num[i + 1] && op[i] == '*' && op[i - 1] != '/') {
						std::swap(num[i], num[i + 1]);
						flag = 1;
					}
				}
				else {
					if (num[i] > num[i + 1] && op[i] == '+' &&  op[i - 1] == '+'  &&  op[i + 1] != '*' && op[i + 1] != '/') {
						std::swap(num[i], num[i + 1]);
						flag = 1;
					}
					else if (num[i] > num[i + 1] && op[i] == '*'&& op[i - 1] != '/') {
						std::swap(num[i], num[i + 1]);
						flag = 1;
					}
				}
			} // end for
		} while (flag == 1);

		for (int i = 0; i < m; ++i) {
			std::cout << num[i] << " " << op[i] << " ";
		}
		std::cout << num[n - 1];
	}

	return 0;
}