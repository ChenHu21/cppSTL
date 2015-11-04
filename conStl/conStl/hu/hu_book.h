#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//�鼮������Ϣ��
class Book
{
public:
	string mstrBookNo;
	string mstrBookName;
	string sstrBookPublish;

public:
	Book(string No, string Name, string Publish) :mstrBookNo(No), mstrBookName(Name), sstrBookPublish(Publish)
	{
		//���캯��
	}
};
//���߻�����Ϣ��
class Writer
{
public:
	string mstrWriterNo;
	string mstrWriterName;
	vector<Book>mvBook;//����ӵ�е��鼮���� 
	//������ϢҲ�����м��ϡ�����������Ƕ���ǳ��õı�̷��������ݹ�ϵ���Ի���Ϊ���νṹ���Ҿ�����һ�����ڵ��Ӧ����ӽڵ�
	//��ô���ʱ��Ҫ���ǵ�������Ƕ�׷���
public:
	Writer(string no, string name) :mstrWriterNo(no), mstrWriterName(name)
	{

	}

	void AddBook(Book& book)
	{
		//�����������鼮
		mvBook.push_back(book);
	}
	void Display_book()
	{
		unsigned int i;
		for (i = 0; i < mvBook.size(); i++)
		{
			cout << mvBook[i].mstrBookNo << "\t"
				<< mvBook[i].mstrBookName << "\t"
				<< mvBook[i].sstrBookPublish << endl;
		}
	}
};

//���߼�����Ϣ��
class WriterCollect
{
public:
	vector<Writer>mvWriter;
public:
	void AddWriter(Writer& w)
	{
		mvWriter.push_back(w);//����µ�����
	}
	void Display()
	{
		unsigned int i;
		for (i = 0; i < mvWriter.size(); i++)
		{
			cout << mvWriter[i].mstrWriterNo << "\t" << mvWriter[i].mstrWriterName << endl;
			mvWriter[i].Display_book();//���������Ϣ�Լ����ߵ��鼮
		}
	}
};

//��������
void hu_book_writer()
{
	Writer w1("1001", "����");//�������߶���
	Book b1("b001", "��ʷ�����", "�廪��ѧ������");
	Book b2("b002", "��������߼�", "��е������");
	w1.AddBook(b1);
	w1.AddBook(b2);

	Writer w2("1002", "�߻�");
	Book b3("b003", "��ѧ֮��", "����ʦ����ѧ������");
	w2.AddBook(b3);

	WriterCollect collect;
	collect.AddWriter(w1);
	collect.AddWriter(w2);
	collect.Display();
}