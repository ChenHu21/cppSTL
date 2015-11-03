#pragma once
/*
C++对文件的读写是 (依照 打开--读写--关闭） 
ifstream 读取文件数据
ofstream 写入文件数据
fstream  可用于读取和写入文件数据

3中流类都是用构造函数或 open函数打开文件
构造函数：
ifstream(const char* szNmae,int nMode=ios::in,int nProt=filebuf::openprot)
ofstream(const char* szNmae,int nMode=ios::out,int nProt=filebuf::openprot)
fstream(const char* szNmae,int nMode,int nProt=filebuf::openprot)

open(文件名,打开方式)函数
void ifstream::open(const char* fileName,int openmode=ios::in)
void ofstream::open(const char* fileName,int openmode=ios::out|ios::trunc)
void fstream::open(const char* fileName,int openmode=ios::in|ios:out)

打开方式有：
ios::in 读取方式打开
ios::out 写入方式打开
ios::app 追加数据到文件末尾
ios::ate 仅初始时将文件指针移到末尾，仍可在任意位置写入数据
ios::trunc 写入数据前，清空原有文件数据，文件不存在，新建文件
ios::binary 以二进制方式打开文件

文件关闭
都用 close();无参数 释放文件资源 与open() 成对出现

*/

#include <fstream>
#include <iostream>
using namespace std;
int hu_ifstream();//文件读
void hu_ofstream();
int hu_write_binary();//写入二进制文件
int hu_read_binary();//读取二进制文件
/*
通过 read write 函数完成读写二进制文件的功能
ostream& write(const char*,int size)
istream& read(char*,int size)
第一个参数：读写 缓存区的头指针
第二个参数：读写缓存区的大小
*/

int hu_streambuf();//输入输出流缓存

/*
定位输出输入流
流的位置标识有3个：
iOS::beg 开始
ios::cur 当前
ios::end 结束

定位函数主要2个：
针对输入流：
istream& seekg(long pos,ios::seek_dir dir)
参数1 移动的字符数目，可正可负
参数2 移动方向，上面3个位置标识之一

针对输出流：
ostream& seekp(long pos,ios::seek_dir dir)
参数含义同上
*/
//先写文件，然后读取显示
int hu_fstream();
struct MyStruct
{
	char name[20];
	int age;
};
void hu_ofstream()
{
	ofstream out;
	out.open("a.txt");
	MyStruct str1 = { "张三",23 };
	MyStruct str2 = { "李四",43 };
	out << str1.name << "\t" << str1.age << endl;//用out<<把信息存到文本中
	out << str2.name << "\t" << str2.age << endl;
	out.close();
	cout << "写入成功";
	
}

int hu_ifstream()
{
	char buf[40];
	ifstream in("a.txt");//通过构造函数创建文件读入流
	if (!in) { return 0; }//若文件不存在，返回
	while (in.getline(buf, 40))//通过 getline()函数按行读取内容
	{
		cout << buf << endl;

	}
	in.close();
	return 0;
}

int hu_write_binary()
{
	ofstream out;
	out.open("b.txt");
	MyStruct str1 = { "张三",23 };
	MyStruct str2 = { "李四",43 };
	out.write((const char*)&str1, sizeof(MyStruct));//存入二进制文件
	out.write((const char*)&str2, sizeof(MyStruct));
	out.close();
	return 0;


}


int hu_read_binary()
{
	ifstream in;
	in.open("b.txt");
	if (!in)
	{
		return 0;
	}
	MyStruct str1, str2;
	//char buf[20];
	//while (in.get(buf, sizeof(MyStruct)))
	//{
	//	in.read((char*)&str1, sizeof(MyStruct));//读取二进制文件
	//	cout << str1.name << "\t" << str1.age << endl;


	//}
	in.read((char*)&str1, sizeof(MyStruct));//读取二进制文件
	in.read((char*)&str2, sizeof(MyStruct));

	cout << str1.name << "\t" << str1.age << endl;
	cout << str2.name << "\t" << str2.age << endl;
	in.close();
	return 0;

}

int hu_streambuf()
{
	ifstream fin("a.txt");
	if (!fin)
	{
		return 0;
	}
	cout << fin.rdbuf();//通过rbuf()函数获得 缓存区 streambuf的指针

	fin.close();
	return 0;
}

int  hu_fstream()
{
	fstream in_out;
	in_out.open("c.txt",ios::in|ios::out|ios::trunc);
	in_out.write("hello", 5);//写入文件方式1
	in_out << "我是陈讲清";//写入文件方式2
	in_out.seekg(0, ios::beg);//读指针移到文件头
	cout << in_out.rdbuf();
	in_out.close();
	return 0;

}