#pragma once
/*
�ַ������������
ֱ�Ӷ��ڴ�����Ƕ��ļ����в���
�����ַ��������������������ͷ�ļ� <sstream>��

��׼�ⶨ����3�����͵��ַ�����
istringstream �ַ������������ṩ��string����
ostringstream �ַ�����������ṩдstring����
stringstream  �ַ���������������ṩ��дstring ����
�����ַ�����������������Է���ذѸ��ֻ�������������ϳ��ַ�����Ҳ���԰��ַ��������ֱ�����ֵ
*/

#include <sstream>
#include <iostream>
using namespace std;

int hu_string_to_int();//�����ַ��������ֱ���
int hu_int_string();//������������ַ���

int hu_string_to_int()
{
	int n;
	float f;
	string str;
	string strText = "12 3.2�½���";
	istringstream s(strText);
	s >> n;
	s >> f;
	s >> str;
	cout << "int n=" << n <<endl<< "float f=" << f <<endl<< "string str=" << str << endl;
	return 0;
}

int hu_int_string()
{
	cout << "�������λ򸡵��ͻ��ַ���" << endl;
	int i;
	float f;
	string stuff;
	cin >> i >> f;
	getline(cin, stuff);
	ostringstream writeStr;
	/*writeStr << "���Σ�" << i ;
	writeStr << "float ��" << f;*/
	writeStr <<i<<f<< stuff << endl;
	string strResult = writeStr.str();
	cout <<"�ϲ��ַ���Ϊ:"<<endl<< strResult << endl;
	return 0;
}
