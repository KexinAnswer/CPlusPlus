//链接：https://www.nowcoder.com/questionTerminal/668603dc307e4ef4bb07bcd0615ea677
//来源：牛客网
//
//在命令行输入如下命令：
//
//xcopy / s c : \ d : \，
//
//各个参数如下：
//
//参数1：命令字xcopy
//
//参数2：字符串 / s
//
//参数3：字符串c : \
//
//	参数4 : 字符串d : \
//
//	请编写一个参数解析程序，实现将命令行各个参数解析出来。
//
//
//
//	解析规则：
//
//	1.参数分隔符为空格
//	2.对于用“”包含起来的参数，如果中间有空格，不能解析为多个参数。比如在命令行输入xcopy / s “C : \program files” “d : \”时，参数仍然是4个，第3个参数应该是字符串C : \program files，而不是C : \program，注意输出参数时，需要将“”去掉，引号不存在嵌套情况。
//	3.参数不定长
//	4.输入由用例保证，不会出现不符合要求的输入
//
//
//
//
//
//输入描述:
//输入一行字符串，可以有空格
//
//
//
//输出描述 :
//输出参数个数，分解后的参数，每个参数都独占一行
//
//示例1
//输入
//xcopy / s c : \\ d:\\
//输出
//4
//xcopy
/// s
//c : \\
//	d:\\

#include <iostream>
#include <string>

int main()
{
	std::string str;
	while (std::getline(std::cin, str))
	{
		int i = 0;
		int count = 1;
		for (i = 0; i < str.size(); ++i)
		{
			if (str[i] == ' ')
			{
				str[i] = '\n';
				count++;
			}
		}
		std::cout << count << std::endl;
		std::cout << str << std::endl;
	}

	return 0;
}


//
//链接：https://www.nowcoder.com/questionTerminal/4284c8f466814870bae7799a07d49ec8
//来源：牛客网
//
//小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3.......
//这条石板路要根据特殊的规则才能前进：对于小易当前所在的编号为K的 石板，小易单次只能往前跳K的一个约数(不含1和K)步，即跳到K + X(X为K的一个非1和本身的约数)的位置。 小易当前处在编号为N的石板，他想跳到编号恰好为M的石板去，小易想知道最少需要跳跃几次可以到达。
//例如：
//N = 4，M = 24：
//4->6->8->12->18->24
//于是小易最少需要跳跃5次，就可以从4号石板跳到24号石板
//
//输入描述 :
//输入为一行，有两个整数N，M，以空格隔开。(4 ≤ N ≤ 100000) (N ≤ M ≤ 100000)
//
//
//输出描述 :
//	输出小易最少需要跳跃的步数, 如果不能到达输出 - 1
//	示例1
//	输入
//	4 24
//	输出
//	5

#include <iostream>
#include <math.h>

int isprime(int num)
{
	int result = sqrt(num);

	for (int i = 2; i <= result; ++i)
	{
		if (num % i == 0)
			return -1;
	}

	return num;
}

int main()
{
	int n, m;



	while (std::cin >> n >> m)
	{
		int result = isprime(n);
		if (result != -1)
		{
			std::cout << -1 << std::endl;
		}
		else
		{
			int count = 0;
			int cur = n;

			while (cur < m)
			{
				int val = 0;
				for (int i = cur - 1; i > 0; --i)
				{
					if (cur % i == 0)
					{
						cur += i;
						if (cur <= m)
						{
							count++;
							break;
						}
						else {
							cur -= i;
						}
					}
				}
			}

			std::cout << count << std::endl;
		}


	}


	return 0;
}