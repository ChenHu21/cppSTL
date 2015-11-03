#pragma once
/*
字符串输入输出流
直接对内存而不是对文件进行操作
所有字符串流类的声明都包含在头文件 <sstream>中

标准库定义了3种类型的字符串流
istringstream 字符串输入流，提供读string功能
ostringstream 字符串输出流，提供写string功能
stringstream  字符串输入输出流，提供读写string 功能
利用字符串输入输出流，可以方便地把各种基本数据类型组合成字符串，也可以把字符串给各种变量赋值
*/

#include <sstream>
#include <iostream>
using namespace std;

int hu_string_to_int();//反解字符串给各种变量
int hu_int_string();//各种类型组合字符串

int hu_string_to_int()
{
	int n;
	float f;
	string str;
	string strText = "12 3.2陈讲清";
	istringstream s(strText);
	s >> n;
	s >> f;
	s >> str;
	cout << "int n=" << n <<endl<< "float f=" << f <<endl<< "string str=" << str << endl;
	return 0;
}

int hu_int_string()
{
	cout << "输入整形或浮点型或字符串" << endl;
	int i;
	float f;
	string stuff;
	cin >> i >> f;
	getline(cin, stuff);
	ostringstream writeStr;
	/*writeStr << "整形：" << i ;
	writeStr << "float ：" << f;*/
	writeStr <<i<<f<< stuff << endl;
	string strResult = writeStr.str();
	cout <<"合并字符串为:"<<endl<< strResult << endl;
	return 0;
}
