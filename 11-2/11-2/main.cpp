#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>

#define MAX 1000

#if 0
int Binary(int arr[MAX], int num) {
	int len = 0;
	while (num) {
		arr[len] = num % 2;
		num /= 2;
		len++;
	}
	int left = 0;
	int right = len - 1;
	while (left <= right) {
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
	return len;
}

int add(int arr[MAX], int len) {
	int carry = 1;
	for (int i = len-1; i >= 0; --i) {
		int sum = arr[i] + carry;
		arr[i] = sum % 2;
		carry = sum / 2;
	}
	if (carry == 1) {
		for (int i = len; i > 0; --i) {
			arr[i] = arr[i - 1];
		}
		arr[0] = carry;
		len++;
	}
	return len;
}
void Print(int arr[MAX], int len) {
	for (int i = 0; i < len; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main() {
	int arr[MAX] = { 0 };
	int len = 0;
	int num = 0;
	scanf("%d", &num);
	len = Binary(arr, num);
	Print(arr, len);
	len = add(arr, len);
	Print(arr, len);

	return 0;
}
#endif

void Print(int arr[MAX], int len) {
	for (int i = 0; i < len; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void function(int arr1[], int len1, int arr2[], int len2) {
	int res1[MAX] = { 0 };
	int res2[MAX] = { 0 };
	int Small = 0;
	int Long = 0;
	if (len1 < len2) {
		Small = len1;
		Long = len2;
	}
	else {
		Small = len2;
		Long = len1;
	}

	for (int i = 0; i < Small; ++i) {
		if (arr1[i] == 1 && arr2[i] == 1) {
			res1[i] = 1;
		}
		else {
			res1[i] = 0;
		}
	}
	Print(res1, Small);
	for (int i = 0; i < Long; ++i) {
		if (arr1[i] == 1 || arr2[i] == 1) {
			res2[i] = 1;
		}
		else {
			res2[i] = 0;
		}
	}
	Print(res2, Long);
}
int main() {
	
	int arr1[] = { 0,0,0,1,1,0,1,0,1 };
	int len1 = sizeof(arr1) / sizeof(arr1[0]);
	Print(arr1, len1);
	int arr2[] = { 0,0,1,1,1,1,1 };
	int len2 = sizeof(arr2) / sizeof(arr2[0]);
	Print(arr2, len2);
	function(arr1, len1, arr2, len2);

	return 0;
}