//���ӣ�https://www.nowcoder.com/questionTerminal/668603dc307e4ef4bb07bcd0615ea677
//��Դ��ţ����
//
//�������������������
//
//xcopy / s c : \ d : \��
//
//�����������£�
//
//����1��������xcopy
//
//����2���ַ��� / s
//
//����3���ַ���c : \
//
//	����4 : �ַ���d : \
//
//	���дһ��������������ʵ�ֽ������и�����������������
//
//
//
//	��������
//
//	1.�����ָ���Ϊ�ո�
//	2.�����á������������Ĳ���������м��пո񣬲��ܽ���Ϊ�������������������������xcopy / s ��C : \program files�� ��d : \��ʱ��������Ȼ��4������3������Ӧ�����ַ���C : \program files��������C : \program��ע���������ʱ����Ҫ������ȥ�������Ų�����Ƕ�������
//	3.����������
//	4.������������֤��������ֲ�����Ҫ�������
//
//
//
//
//
//��������:
//����һ���ַ����������пո�
//
//
//
//������� :
//��������������ֽ��Ĳ�����ÿ����������ռһ��
//
//ʾ��1
//����
//xcopy / s c : \\ d:\\
//���
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
//���ӣ�https://www.nowcoder.com/questionTerminal/4284c8f466814870bae7799a07d49ec8
//��Դ��ţ����
//
//С��������һ��ʯ��·ǰ��ÿ��ʯ���ϴ�1���ű��Ϊ��1��2��3.......
//����ʯ��·Ҫ��������Ĺ������ǰ��������С�׵�ǰ���ڵı��ΪK�� ʯ�壬С�׵���ֻ����ǰ��K��һ��Լ��(����1��K)����������K + X(XΪK��һ����1�ͱ����Լ��)��λ�á� С�׵�ǰ���ڱ��ΪN��ʯ�壬�����������ǡ��ΪM��ʯ��ȥ��С����֪��������Ҫ��Ծ���ο��Ե��
//���磺
//N = 4��M = 24��
//4->6->8->12->18->24
//����С��������Ҫ��Ծ5�Σ��Ϳ��Դ�4��ʯ������24��ʯ��
//
//�������� :
//����Ϊһ�У�����������N��M���Կո������(4 �� N �� 100000) (N �� M �� 100000)
//
//
//������� :
//	���С��������Ҫ��Ծ�Ĳ���, ������ܵ������ - 1
//	ʾ��1
//	����
//	4 24
//	���
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