#include <vector>
#include <iostream>
#include <stdlib.h>
#include "vector.h"
using namespace std;

//void Test_vector1()
//{
//	vector<int> v1;
//	v1.push_back(1);
//	v1.push_back(2);
//	//vector<int> = v1.begin();
//	//auto vit = v1.begin();
//	//v1.erase(vit);
//	//*vit = 10;
//
//	//������inset�ӿڣ����»�ȡ����������ֹ������ʧЧ
//	//v1.insert(vim,10);
//	//*vit = 20;        //���ʣ�Ұָ��
//	v1.push_back(3);
//	v1.push_back(4);
//
//	auto vit = v1.begin();
//	while (vit != v1.end())
//	{
//		if (*vit % 2 == 0)
//		{
//			//������erase�ӿڣ���ȡerase�ӿڵķ���ֵ����ֹ������ʧЧ
//			v1.erase(vit);
//		}
//		else
//		{
//			vit++;
//		}
//	}
//
//
//
//
//}
//
//int main()
//{
//	vector<int> v1(5, 1);
//	vector<int> v2(5, 3);
//
//
//	//ȫ�ֽ�������
//	swap(v1, v2);
//
//	//��Ա����
//	v1.swap(v2);
//
//	return 0;
//}

//int main()
//{
//	
//	vector<int> v1(50, 1);
//	cout << v1.capacity() << endl;
//	//�ֶ��ͷ�vector
//	v1.resize(0);
//
//	{
//		vector<int> v2;
//		v2.swap(v1);
//	}
//
//
//	return 0;
//
//}

//int main()
//{
//	cout << "�����뺺��" << endl;
//	system("pause");
//	return 0;
//}

int main()
{

	testVector_iterator();

	system("pause");

	return 0;
}