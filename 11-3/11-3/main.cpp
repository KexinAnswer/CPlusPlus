#include <cstdio>
#include <iostream>

/*
	编写程序输入一个任意字符串，判断该字符串是否至少包含
	大写字母，小写字母，数字三种类型字符串的两类
*/
#if 1
bool CheckPassword(const char* str, int len) {
	// 是否有数组
	int num = 0;
	// 是否有小写字母
	int str1 = 0;
	// 是否有有大写字母
	int str2 = 0;

	// 遍历字符串
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

// arr:双向队列  begin:队列头   end:队列尾
int WOfQ(int arr[], int begin, int end) {
	int sum = 0;
	int i = 0; // i 表示第几次出队
	while (begin <= end) {
		++i;
		if (arr[begin] < arr[end]) {
			// 如果队头元素小于队尾元素 出队头元素
			sum += arr[begin] * i;
			++begin;
		}
		else {
			// 如果队尾元素小 那么出队尾元素 
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




