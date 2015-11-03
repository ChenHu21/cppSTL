#pragma once
/*
C++���ļ��Ķ�д�� (���� ��--��д--�رգ� 
ifstream ��ȡ�ļ�����
ofstream д���ļ�����
fstream  �����ڶ�ȡ��д���ļ�����

3�����඼���ù��캯���� open�������ļ�
���캯����
ifstream(const char* szNmae,int nMode=ios::in,int nProt=filebuf::openprot)
ofstream(const char* szNmae,int nMode=ios::out,int nProt=filebuf::openprot)
fstream(const char* szNmae,int nMode,int nProt=filebuf::openprot)

open(�ļ���,�򿪷�ʽ)����
void ifstream::open(const char* fileName,int openmode=ios::in)
void ofstream::open(const char* fileName,int openmode=ios::out|ios::trunc)
void fstream::open(const char* fileName,int openmode=ios::in|ios:out)

�򿪷�ʽ�У�
ios::in ��ȡ��ʽ��
ios::out д�뷽ʽ��
ios::app ׷�����ݵ��ļ�ĩβ
ios::ate ����ʼʱ���ļ�ָ���Ƶ�ĩβ���Կ�������λ��д������
ios::trunc д������ǰ�����ԭ���ļ����ݣ��ļ������ڣ��½��ļ�
ios::binary �Զ����Ʒ�ʽ���ļ�

�ļ��ر�
���� close();�޲��� �ͷ��ļ���Դ ��open() �ɶԳ���

*/

#include <fstream>
#include <iostream>
using namespace std;
int hu_ifstream();//�ļ���
void hu_ofstream();
int hu_write_binary();//д��������ļ�
int hu_read_binary();//��ȡ�������ļ�
/*
ͨ�� read write ������ɶ�д�������ļ��Ĺ���
ostream& write(const char*,int size)
istream& read(char*,int size)
��һ����������д ��������ͷָ��
�ڶ�����������д�������Ĵ�С
*/

int hu_streambuf();//�������������

/*
��λ���������
����λ�ñ�ʶ��3����
iOS::beg ��ʼ
ios::cur ��ǰ
ios::end ����

��λ������Ҫ2����
�����������
istream& seekg(long pos,ios::seek_dir dir)
����1 �ƶ����ַ���Ŀ�������ɸ�
����2 �ƶ���������3��λ�ñ�ʶ֮һ

����������
ostream& seekp(long pos,ios::seek_dir dir)
��������ͬ��
*/
//��д�ļ���Ȼ���ȡ��ʾ
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
	MyStruct str1 = { "����",23 };
	MyStruct str2 = { "����",43 };
	out << str1.name << "\t" << str1.age << endl;//��out<<����Ϣ�浽�ı���
	out << str2.name << "\t" << str2.age << endl;
	out.close();
	cout << "д��ɹ�";
	
}

int hu_ifstream()
{
	char buf[40];
	ifstream in("a.txt");//ͨ�����캯�������ļ�������
	if (!in) { return 0; }//���ļ������ڣ�����
	while (in.getline(buf, 40))//ͨ�� getline()�������ж�ȡ����
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
	MyStruct str1 = { "����",23 };
	MyStruct str2 = { "����",43 };
	out.write((const char*)&str1, sizeof(MyStruct));//����������ļ�
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
	//	in.read((char*)&str1, sizeof(MyStruct));//��ȡ�������ļ�
	//	cout << str1.name << "\t" << str1.age << endl;


	//}
	in.read((char*)&str1, sizeof(MyStruct));//��ȡ�������ļ�
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
	cout << fin.rdbuf();//ͨ��rbuf()������� ������ streambuf��ָ��

	fin.close();
	return 0;
}

int  hu_fstream()
{
	fstream in_out;
	in_out.open("c.txt",ios::in|ios::out|ios::trunc);
	in_out.write("hello", 5);//д���ļ���ʽ1
	in_out << "���ǳ½���";//д���ļ���ʽ2
	in_out.seekg(0, ios::beg);//��ָ���Ƶ��ļ�ͷ
	cout << in_out.rdbuf();
	in_out.close();
	return 0;

}