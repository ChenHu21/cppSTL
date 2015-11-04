#pragma once
//#pragma execution_character_set("utf-8")

/*
常用映射类 map 和 multimap <key,value> 形式容器
map 单映射中 key与value 是一对一关系
multimap中，key 与value可以是一对多关系

常用函数

1 构造函数：
map(const Pred& comp=Pred(),const A& al=A()) 创建空映射
map(const map& x) 复制构造函数
map(const value_type* first,const_vaoue_type *last,const Pred& comp=Pred(),const A& al=A()) 复制[first,last]之间的元素构成新映射

multimap(const Pred& comp=Pred(),const A& al=A()) 创建空映射
multimap(const map& x) 复制构造函数
multimap(const value_type* first,const_vaoue_type *last,const Pred& comp=Pred(),const A& al=A()) 复制[first,last]之间的元素构成新映射

2 大小判断空函数
int size()  返回映射元素个数
bool empty() const判断容器是否为空，返回true ，映射为空


3 增加 删除函数
iterator insert(const value_type& x) 插入元素x
iterator insert(iterator it,const value_type& x) 在迭代器指针it处插入元素x
void insert(const value_type* first,const_type* last) 插入[first,last]迭代器指针之间的元素

iterator erase(iterator it) 删除迭代指针it处元素
iterator erase(iterator first,iterator last) 删除[first,last] 迭代指针之间的元素
size_type erase(const Key& key) 删除元素值等于 key 的元素

4 遍历函数
iterator begin() 返回首元素的迭代器指针
iterator end() 返回尾元素后的迭代器指针
reverse_iterator rbegin() 返回尾元素的逆向迭代器指针，用于逆向遍历容器
reverse_iterator rend() 返回首元素的逆向迭代器指针，用于逆向遍历容器

5 操作函数
const_iterator lower_bound(const Key& key) 返回容器元素小于等于<=key的迭代指针，否则返回end()
const_iterator upper_bound(const Key& key) 返回容器元素大于等于>=key的迭代指针，否则返回end()
const_iterator find(const Key& key) 查找功能，返回容器元素大于等于=key的迭代指针
pair<const_iterator,const_iterator>equal_range(const Key& key) 返回容器中元素等于=key 的迭代指针[first,last)
int count(const Key& key) 返回容器中元素值等于key的元素个数

void swap(map& s) 交换单映射元素
void swap(multimap& s) 交换多映射元素

6 特殊函数
reference operator[](const Key& key) 仅用在单映射map中，可以以数组的形式给映射添加 键值对，并返回值得引用
*/

//两种常用的产生映射方法
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
using namespace std;


void showmap(map<int, string>& m)
{//显示map 内容
	map<int, string>::iterator it = m.begin();
	while (it!=m.end())
	{
		cout << (*it).first << "\t" << (*it).second << endl;
		it++;
	}
}
void hu_create_map()
{
	map<int, string>m;
	pair<int, string>s1(1, "化学的传奇");
	pair<int, string>s2(2, "物理的世界");
	pair<int, string>s3(6, "美丽的天使");
	pair<int, string>s4(4, "大海该在哪里");
	pair<int, string>s5(2, "爱因斯坦的思维");
	pair<int, string>s6(5, "畅想未来");//pair是两个模板参数的模板类，正好符合映射类的 <key,value>要求

	m.insert(s1);
	m.insert(s2);
	m.insert(s3);
	m.insert(s4);
	m.insert(s5);
	m.insert(s6);//map映射结果 升序排序，无重复记录

	cout << "通过insert函数创建map：" << endl;
	showmap(m);
	cout << "通过复制构造函数创建map：" << endl;
	map<int, string>mm(m);
	showmap(mm);


	//map映射的operator[]方法 构造映射
	map<int, string>marry;
	marry[1] = "Love";
	marry[2] = "home";
	marry[3] = "friend";
	showmap(marry);

	string str;
	str = m[6];
	cout << "取得map元素m[6]：" << str << endl;
	str = marry[1];
	cout << "取得map元素marry[6]：" << str << endl;
	
}

//综合示例

/*
编写一个同义词字典功能类，每个单词后面跟他的同义词：
one uniquee single
true right correct
...

需要解决的问题：形成上述同义词字典，根据给定的单词查出相应的同义词

分析：
一般来说形成字典的文件是按照字母排序的，又由于一个单词有很多同义词，因此用multimap 多映射类解决该问题。
*/

class Word
{
	//基础单词类
private:
	string mainiword;//一个单词
	vector<string>v;//可以有多个同义词
public:
	Word(string w)
	{
		istringstream in(w);//转化为字符串流
		in >> mainiword;//第一个单词是关键字
		string mid = "";
		while (!in.eof())
		{
			in >> mid;//其余单词是近义词
			v.push_back(mid);//插入向量容器

		}

	}

	string GetMainWord()
	{
		return mainiword;
	}

	void show()
	{//显示单词及同义词
		cout << endl;
		cout << "单词：" << "\t" << mainiword << endl;
		cout << "同义词：" << "\t";
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << "\t";
		}

		cout << endl;
	}

};

class WordManage
{
	//同义词集合类
	multimap<string, Word>m;
public:
	bool add(string str)
	{
		Word w(str);
		pair<string, Word>p(w.GetMainWord(), w);
		m.insert(p);
		return true;
	}

	void show(string strFind)
	{
		//显示待查找的同义词
		multimap<string, Word>::iterator it = m.find(strFind);//查找
		if (it!=m.end())
		{
			//如果有同义词
			Word& obj = (*it).second;
			obj.show();//同义词显示
		}
		else
		{
			cout << strFind << "字典里没有记录同义词" << endl;
		}
	}

	void show()
	{
		//显示字典里所有同义词信息
		multimap<string, Word>::iterator it = m.begin();//从头开始
		while (it!=m.end())
		{
			Word& obj = (*it).second;
			obj.show();
			it++;
		}
	}
};

//字典查找测试函数
void hu_word_test()
{
	string s[5] = {
		string("one single unique"),
		string("near close here"),
		string("happy please laught"),
		string("strong power biger"),
		string("right true croect")
	};

	WordManage m;
	for (int i = 0; i < 5; i++)
	{
		m.add(s[i]);//形成同义词字典
	}

	m.show();//显示所有信息


	cout << "亲，输入一个单词:";
	string strtemp;
	cin >> strtemp;
	m.show(strtemp);
}