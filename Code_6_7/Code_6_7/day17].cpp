//���ӣ�https://www.nowcoder.com/questionTerminal/8ef655edf42d4e08b44be4d777edbf43
//��Դ��ţ����
//
//[�����]iNOC��Ʒ�� - ������ǵı���
//�ȶ�ָ����9391ʱ�����ƣ�1��ռ����ƣ�32768K
//�㷨֪ʶ��Ƶ����
//1
//
//1  1  1
//
//1  2  3  2  1
//
//1  3  6  7  6  3  1
//
//1  4  10 16 19  16 10  4  1
//
//���������ε����󣬵�һ��ֻ��һ����1������ÿ�е�ÿ��������ǡ������������������Ͻ��������Ͻǵ�����3����֮�ͣ����������ĳ��������Ϊ��������0����
//
//���n�е�һ��ż�����ֵ�λ�á����û��ż��������� - 1����������3, �����2������4�����3��

//
//����n(n <= 1000000000)
//
//��������:
//����һ��int����
//
//
//
//������� :
//������ص�intֵ
//
//ʾ��1
//����
//4
//���
//3
#include <iostream>
#include <vector>

int main()
{
	int num;
	while (std::cin >> num)
	{
		if (num <= 2)
		{
			std::cout << -1 << std::endl;
		}
		else
		{
			std::vector< std::vector <int> > vec;
			vec.resize(num);
			int i = 0;
			int j = 0;
			for (i = 0; i < num; ++i)
			{
				vec[i].resize(2 * (i + 1) + 1);

				for (j = 0; j < 2 * (i + 1) - 1; ++j)
				{
					if (j == 0)
						vec[i][j] = 1;
					else if (j == 1)
						vec[i][j] = vec[i - 1][j - 1] + vec[i - 1][j];
					else
						vec[i][j] = vec[i - 1][j - 2] + vec[i - 1][j - 1] + vec[i - 1][j];
				}
			}
			int ret = -1;
			for (i = 0; i < 2 * num - 1; ++i)
			{
				if (vec[num - 1][i] % 2 == 0)
				{
					ret = i + 1;
					break;
				}
			}

			std::cout << ret << std::endl;
		}



	}
	return 0;
}
//
//���ӣ�https://www.nowcoder.com/questionTerminal/5821836e0ec140c1aa29510fd05f45fc
//��Դ��ţ����
//
//[�����]�������������
//�ȶ�ָ����10241ʱ�����ƣ�1��ռ����ƣ�32768K
//�㷨֪ʶ��Ƶ����
//�����һ���㷨������������������ļӷ���

//�ӿ�˵��

//
///*
//�����һ���㷨������������������ļӷ���
//���������
//String addend������
//String augend��������
//����ֵ���ӷ����
//*/
//
//public String AddLongInteger(String addend, String augend)
//{
//	/*������ʵ�ֹ���*/
//
//
//	return null;
//}
//
//

//��������:
//���������ַ�������

//
//������� :
//�����Ӻ�Ľ����string��
//
//ʾ��1
//����
//99999999999999999999999999999999999999999999999999
//1
//���
//100000000000000000000000000000000000000000000000000

#include <iostream>
#include <string>

int main()
{
	std::string str1;
	std::string str2;
	while (std::cin >> str1 >> str2)
	{
		std::string str_long;
		std::string str_short;
		if (str1.size() > str2.size())
		{
			str_long = str1;
			str_short = str2;
		}
		else
		{
			str_short = str1;
			str_long = str2;
		}
		int _long = str_long.size();
		int _short = str_short.size();
		int carry = 0;
		while (_short >= 0)
		{
			str_long[_long] += str_short[_short] - '0';
			if (str_long[_long] > '9' && _long > 0)
			{
				str_long[_long] -= 10;
				str_long[_long - 1] += 1;
			}
			if (str_long[_long] > '9' && _long == 0)
			{
				str_long.insert(0, 1, '1');
			}

			_short--;
			_long--;
		}

		while (str_long[_long] > '9' && _long > 0)
		{
			str_long[_long] -= 10;
			str_long[_long - 1] += 1;
			if (str_long[_long] > '9' && _long == 0)
			{
				str_long.insert(0, 1, '1');
			}

			_long--;
		}
		std::cout << str_long << std::endl;
	}


	return 0;
}