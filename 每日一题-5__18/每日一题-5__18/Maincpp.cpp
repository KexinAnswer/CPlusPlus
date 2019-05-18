#include <iostream>
#include <string>
using namespace std;


//链接：https://www.nowcoder.com/questionTerminal/52d382c2a7164767bca2064c1c9d5361?pos=7&orderByHotValue=1
//来源：牛客网
//
//一、密码长度 :
//
//5 分 : 小于等于4 个字符
//
//10 分 : 5 到7 字符
//
//25 分 : 大于等于8 个字符
//
//二、字母 :
//
//0 分 : 没有字母
//
//10 分 : 全都是小（大）写字母
//
//20 分 : 大小写混合字母
//
//三、数字 :
//
//0 分 : 没有数字
//
//10 分 : 1 个数字
//
//20 分 : 大于1 个数字
//
//四、符号 :
//
//0 分 : 没有符号
//
//10 分 : 1 个符号
//
//25 分 : 大于1 个符号
//
//五、奖励 :
//
//2 分 : 字母和数字
//
//3 分 : 字母、数字和符号
//
//5 分 : 大小写字母、数字和符号
//
//最后的评分标准 :
//
//>= 90 : 非常安全
//
//>= 80 : 安全（Secure）
//
//>= 70 : 非常强
//
//>= 60 : 强（Strong）
//
//>= 50 : 一般（Average）
//
//>= 25 : 弱（Weak）
//
//>= 0 : 非常弱
//
//
//
//对应输出为：
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
//请根据输入的密码字符串，进行安全评定。
//
//注：
//
//字母：a - z, A - Z
//
//数字： - 9
//
//符号包含如下：(ASCII码表可以在UltraEdit的菜单view->ASCII Table查看)
//
//!"#$%&'()*+,-./     (ASCII码：x21~0x2F)
//
//	:; <= > ? @             (ASCII <= > <= > <= > <= > <= > 码：x3A~0x40)
//
//	[\] ^ _`              (ASCII码：x5B~0x60)
//
//{
//	|
//}~(ASCII码：x7B~0x7E)
//
//接口描述：
//
//
//
//Input Param
//String pPasswordStr : 密码，以字符串方式存放。
//
//Return Value
//根据规则评定的安全等级。


//
//
//public static Safelevel GetPwdSecurityLevel(String pPasswordStr)
//	{
//		/*在这里实现功能*/
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
			//密码长度
			pLen++;

			//如果密码中有大写字母
			if ('A' <= *it && *it <= 'Z')
			{
				pLetter_large = 10;
			}

			//如果密码中有小写字母
			if ('a' <= *it && *it <= 'z')
			{
				pLetter_small = 10;
			}

			//密码中数字的个数
			if (48 <= *it && *it <= 57)
			{
				pNum++;
			}
			//如果密码中有字符
			if ((0x21 <= *it && *it <= 0x2F) || (0x3A <= *it && *it <= 0x40) || (0x5B <= *it && *it <= 0x60) || (0x7B <= *it && *it <= 0x7E))
			{
				pSignal++;
			}


		}

		//长度小于4位 5分
		//长度大于5位 小于7位 10分
		//长度大于7位 25分
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

		//只有小写字母或者大写字母只10分 两种字母20分
		pLetter = pLetter_small + pLetter_large;

		//一个数字 10 分 大于1个数字20分
		if (pNum == 1)
		{
			pNum = 10;
		}
		else if (pNum > 1)
		{
			pNum = 20;
		}

		//一个字母10分
		//大于一个字母 20分
		if (pSignal == 1)
		{
			pSignal = 10;
		}
		else if (pSignal > 1)
		{
			pSignal = 25;
		}
		
		//2 分 : 字母和数字
		//
		//3 分 : 字母、数字和符号
		//
		//5 分 : 大小写字母、数字和符号
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
			cout << "输出错误" << val << endl;
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

