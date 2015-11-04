#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//书籍基本信息类
class Book
{
public:
	string mstrBookNo;
	string mstrBookName;
	string sstrBookPublish;

public:
	Book(string No, string Name, string Publish) :mstrBookNo(No), mstrBookName(Name), sstrBookPublish(Publish)
	{
		//构造函数
	}
};
//作者基本信息类
class Writer
{
public:
	string mstrWriterNo;
	string mstrWriterName;
	vector<Book>mvBook;//作者拥有的书籍集合 
	//基本信息也可以有集合——集合类多层嵌套是常用的编程方法：数据关系可以划分为树形结构，且均满足一个根节点对应多个子节点
	//那么编程时就要考虑到集合类嵌套方法
public:
	Writer(string no, string name) :mstrWriterNo(no), mstrWriterName(name)
	{

	}

	void AddBook(Book& book)
	{
		//向该作者添加书籍
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

//作者集合信息类
class WriterCollect
{
public:
	vector<Writer>mvWriter;
public:
	void AddWriter(Writer& w)
	{
		mvWriter.push_back(w);//添加新的作者
	}
	void Display()
	{
		unsigned int i;
		for (i = 0; i < mvWriter.size(); i++)
		{
			cout << mvWriter[i].mstrWriterNo << "\t" << mvWriter[i].mstrWriterName << endl;
			mvWriter[i].Display_book();//输出作者信息以及作者的书籍
		}
	}
};

//函数调用
void hu_book_writer()
{
	Writer w1("1001", "张敏");//产生作者对象
	Book b1("b001", "历史的天空", "清华大学出版社");
	Book b2("b002", "程序设计逻辑", "机械出版社");
	w1.AddBook(b1);
	w1.AddBook(b2);

	Writer w2("1002", "高华");
	Book b3("b003", "数学之美", "华中师范大学出版社");
	w2.AddBook(b3);

	WriterCollect collect;
	collect.AddWriter(w1);
	collect.AddWriter(w2);
	collect.Display();
}