#include <iostream>
#include <string>
using namespace std;


//���ӣ�https://www.nowcoder.com/questionTerminal/52d382c2a7164767bca2064c1c9d5361?pos=7&orderByHotValue=1
//��Դ��ţ����
//
//һ�����볤�� :
//
//5 �� : С�ڵ���4 ���ַ�
//
//10 �� : 5 ��7 �ַ�
//
//25 �� : ���ڵ���8 ���ַ�
//
//������ĸ :
//
//0 �� : û����ĸ
//
//10 �� : ȫ����С����д��ĸ
//
//20 �� : ��Сд�����ĸ
//
//�������� :
//
//0 �� : û������
//
//10 �� : 1 ������
//
//20 �� : ����1 ������
//
//�ġ����� :
//
//0 �� : û�з���
//
//10 �� : 1 ������
//
//25 �� : ����1 ������
//
//�塢���� :
//
//2 �� : ��ĸ������
//
//3 �� : ��ĸ�����ֺͷ���
//
//5 �� : ��Сд��ĸ�����ֺͷ���
//
//�������ֱ�׼ :
//
//>= 90 : �ǳ���ȫ
//
//>= 80 : ��ȫ��Secure��
//
//>= 70 : �ǳ�ǿ
//
//>= 60 : ǿ��Strong��
//
//>= 50 : һ�㣨Average��
//
//>= 25 : ����Weak��
//
//>= 0 : �ǳ���
//
//
//
//��Ӧ���Ϊ��
//
//VERY_WEAK,
//
//WEAK,
//
//AVERAGE,
//
//STRONG,
//
//VERY_STRONG,
//
//SECURE,
//
//VERY_SECURE
//
//
//
//���������������ַ��������а�ȫ������
//
//ע��
//
//��ĸ��a - z, A - Z
//
//���֣� - 9
//
//���Ű������£�(ASCII��������UltraEdit�Ĳ˵�view->ASCII Table�鿴)
//
//!"#$%&'()*+,-./     (ASCII�룺x21~0x2F)
//
//	:; <= > ? @             (ASCII <= > <= > <= > <= > <= > �룺x3A~0x40)
//
//	[\] ^ _`              (ASCII�룺x5B~0x60)
//
//{
//	|
//}~(ASCII�룺x7B~0x7E)
//
//�ӿ�������
//
//
//
//Input Param
//String pPasswordStr : ���룬���ַ�����ʽ��š�
//
//Return Value
//���ݹ��������İ�ȫ�ȼ���


//
//
//public static Safelevel GetPwdSecurityLevel(String pPasswordStr)
//	{
//		/*������ʵ�ֹ���*/
//		return null;
//	}

int main()
{
	string pPaasswordStr;
	while (cin >> pPaasswordStr)
	{
		int pLen = 0;
		int pLetter_small = 0;
		int pLetter_large = 0;
		int pLetter = 0;
		int pNum = 0;
		int pSignal = 0;
		int pReward = 0;
		int Value = 0;

		for (string::iterator it = pPaasswordStr.begin(); it != pPaasswordStr.end(); ++it)
		{
			//���볤��
			pLen++;

			//����������д�д��ĸ
			if ('A' <= *it && *it <= 'Z')
			{
				pLetter_large = 10;
			}

			//�����������Сд��ĸ
			if ('a' <= *it && *it <= 'z')
			{
				pLetter_small = 10;
			}

			//���������ֵĸ���
			if (48 <= *it && *it <= 57)
			{
				pNum++;
			}
			//������������ַ�
			if ((0x21 <= *it && *it <= 0x2F) || (0x3A <= *it && *it <= 0x40) || (0x5B <= *it && *it <= 0x60) || (0x7B <= *it && *it <= 0x7E))
			{
				pSignal++;
			}


		}

		//����С��4λ 5��
		//���ȴ���5λ С��7λ 10��
		//���ȴ���7λ 25��
		if (pLen <= 4)
		{
			pLen = 5;
		}
		else if (5 <= pLen && pLen <= 7)
		{
			pLen = 10;
		}
		else
		{
			pLen = 25;
		}

		//ֻ��Сд��ĸ���ߴ�д��ĸֻ10�� ������ĸ20��
		pLetter = pLetter_small + pLetter_large;

		//һ������ 10 �� ����1������20��
		if (pNum == 1)
		{
			pNum = 10;
		}
		else if (pNum > 1)
		{
			pNum = 20;
		}

		//һ����ĸ10��
		//����һ����ĸ 20��
		if (pSignal == 1)
		{
			pSignal = 10;
		}
		else if (pSignal > 1)
		{
			pSignal = 25;
		}
		
		//2 �� : ��ĸ������
		//
		//3 �� : ��ĸ�����ֺͷ���
		//
		//5 �� : ��Сд��ĸ�����ֺͷ���
		if (pLetter > 0 && pNum > 0)
		{
			pReward = 2;
			if (pSignal > 0 && pSignal <= 10)
			{
				pReward = 3;
			}
			else if (pSignal > 10)
			{
				pReward = 5;
			}
		}

		Value = pLen + pLetter + pNum + pSignal + pReward;


		int val = Value;

		if (val < 0 || val > 100)
		{
			cout << "�������" << val << endl;
		}

		if (val >= 90)
			cout << "VERY_SECURE" << endl;
		else if (val >= 80)
			cout << "SECURE" << endl;
		else if (val >= 70)
			cout << "VERY_STRONG" << endl;
		else if (val >= 60)
			cout << "STROMG" << endl;
		else if (val >= 50)
			cout << "AVERAGE" << endl;
		else if (val >= 25)
			cout << "WEAK" << endl;
		else if (val >= 0)
			cout << "VERY_WEAK" << endl;
	}



	return 0;
}

