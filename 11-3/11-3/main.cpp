#include <cstdio>
#include <iostream>

/*
	��д��������һ�������ַ������жϸ��ַ����Ƿ����ٰ���
	��д��ĸ��Сд��ĸ���������������ַ���������
*/
#if 0
bool CheckPassword(const char* str, int len) {
	// �Ƿ�������
	int num = 0;
	// �Ƿ���Сд��ĸ
	int str1 = 0;
	// �Ƿ����д�д��ĸ
	int str2 = 0;

	// �����ַ���
	for (int i = 0; i < len; ++i) {
		if (str[i] >= '0' && str[i] <= '9') {
			num = 1;
		}
		if (str[i] >= 'a' && str[i] <= 'z') {
			str1 = 1;
		}
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str2 = 1;
		}

		if (num + str1 + str2 >= 2) {
			return true;
		}
	}
	return false;
}

int main() {
	const char* str = "asdf";
	int len = strlen(str);
	std::cout << CheckPassword(str, len) << std::endl;

	return 0;
}
#endif


