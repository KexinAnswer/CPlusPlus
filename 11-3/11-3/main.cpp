#include <cstdio>
#include <iostream>

/*
	��д��������һ�������ַ������жϸ��ַ����Ƿ����ٰ���
	��д��ĸ��Сд��ĸ���������������ַ���������
*/
#if 1
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


#include <cstdio>
#define maxsize 100

// arr:˫�����  begin:����ͷ   end:����β
int WOfQ(int arr[], int begin, int end) {
	int sum = 0;
	int i = 0; // i ��ʾ�ڼ��γ���
	while (begin <= end) {
		++i;
		if (arr[begin] < arr[end]) {
			// �����ͷԪ��С�ڶ�βԪ�� ����ͷԪ��
			sum += arr[begin] * i;
			++begin;
		}
		else {
			// �����βԪ��С ��ô����βԪ�� 
			sum += arr[end] * i;
			--end;
		}
	}
	return sum;
}


int main() {
	int arr[] = { 3,1,7,9,10,2,6 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int sum = WOfQ(arr, 0, len - 1);
	printf("%d\n", sum);
	return 0;
}




