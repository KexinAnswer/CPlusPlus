//#include <iostream>
//
//int main()
//{
//	int N = 0;
//	while (std::cin >> N)
//	{
//		int fib = 0;
//		if (N >= 0 && N <= 3)
//			return 0;
//		int i = 0;
//		int f1 = 0;
//		int f2 = 1;
//		for (i = 2; fib < N; ++i)
//		{
//			fib = f1 + f2;
//			f1 = f2;
//			f2 = fib;
//		}
//
//		std::cout << (N - f1) << std::endl;
//	}
//
//	return 0;
//}

#include <iostream>
#include <stack>
#include <string>


bool chkParenthesis(std::string A, int n) {
	// write code here
	if (n % 2 == 1)
		return false;

	std::stack<char> st;
	int i = 0;
	while (i < n)
	{
		if (A[i] == '(')
			st.push(A[i]);

		if (A[i] == ')' && !st.empty())
		{
			st.pop();
		}
		++i;
	}
	if (!st.empty())
		return false;

	return true;
}

int main()
{
	std::string str("()(()()");
	
	std::cout << chkParenthesis(str,7) << std::endl;

	return 0;
}