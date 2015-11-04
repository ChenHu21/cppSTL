#pragma once
/*
set/multiset 都是集合类，差别在于 set中不允许有重复元素，multiset 允许有重复

常用函数：

1 构造函数：
set(const Pred& comp=Pred(),const A& al=A()) 创建空集合
set(const set& x) 复制构造函数
set(const value_type* first,const_vaoue_type *last,const Pred& comp=Pred(),const A& al=A()) 复制[first,last]之间的元素构成新集合

multiset(const Pred& comp=Pred(),const A& al=A()) 创建空集合
multiset(const set& x) 复制构造函数
multiset(const value_type* first,const_vaoue_type *last,const Pred& comp=Pred(),const A& al=A()) 复制[first,last]之间的元素构成新集合

2 大小判断空函数
int size()  返回集合元素个数
bool empty() const判断容器是否为空，返回true ，集合为空


3 增加 删除函数
pair<iterator,bool>insert(const value_type& x) 插入元素x
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

void swap(set& s) 交换单集合元素
void swap(multiset& s) 交换多集合元素

*/

#include <iostream>
#include <set>
#include <string>
using namespace std;
//三种形成集合的方法

void show_set(set<int>& s)
{//显示集合输出函数
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << "\t";
		it++;
	}
	cout << endl;
}

void show_multiset(multiset<int>& s)
{//显示集合输出函数
	multiset<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << "\t";
		it++;
	}
	cout << endl;
}
void hu_create_set()
{

	int a[] = { 2,3,4,6,5,6,7,7,6,6,8,8,2 };
	int alen = sizeof(a) / sizeof(int);//求得集合元素个数
	multiset<int>m;//默认集合升序排序
	for (int i = 0; i < alen; i++)
	{
		m.insert(a[i]);

	}
	cout << "通过insert() 添加集合：" << endl;
	show_multiset(m);

	multiset<int>m2(m);//复制集合m
	cout << "通过复制构造函数 multiset(const set& x)创建集合：" << endl;
	show_multiset(m2);

	multiset<int>m3(a, a + alen);
	cout << "通过复制构造函数multiset(*first,*last) 创建集合：" << endl;
	show_multiset(m3);

	set<int>m4(a, a + alen);
	cout << "通过复制构造函数set(*first,*last) 创建集合：（没有重复元素）" << endl;
	show_set(m4);
	//上面为集合的构造

	//下面为集合的操作
	pair<set<int>::iterator, set<int>::iterator>rangeSet;//范围单集合
	pair<multiset<int>::iterator, multiset<int>::iterator>rangemultiSet;//范围多集合

	//equal_range(key)返回等于键值——首次等于和最后一次等于 key 的一对迭代指针，封装在模板类 pair对象中
	rangeSet = m4.equal_range(6);//返回集合中等于6的迭代器指针，用pair接收
	rangemultiSet = m3.equal_range(6);//返回多集合中等于6的迭代器指针，用pair接收

	int setCount = m4.count(6);//返回集合中等于6的元素个数
	int multiSetCount = m3.count(6);//返回多集合中等于6的元素个数
	show_set(m4);
	set<int>::iterator itset;//集合结果搜索遍历
	cout << "set 搜索值等于6的元素：";
	for (itset = rangeSet.first; itset != rangeSet.second; itset++)
	{
		cout << *itset << "\t";
	}
	cout << endl;
	cout << "\t个数是：" << setCount << endl;
	cout << "\tset集合总个数是：" << m4.size() << endl;

	show_multiset(m3);
	multiset<int>::iterator itmset;//多集合结果遍历
	cout << "multiset 搜索值等于6的元素：";
	for (itmset = rangemultiSet.first; itmset != rangemultiSet.second; itmset++)
	{
		cout << *itmset << "\t";
	}
	cout << endl;
	cout << "\t个数是：" << multiSetCount << endl;
	cout << "\tmultiset集合总个数是：" << m3.size() << endl;
}

/*
综合操作：
	编一个集合类，包括交、并、差 三种主要功能，不允许有重复数据。用学生类Student测试

分析：
	很明显要用到 set类，但是 set本身并没有两个集合的交、并、差函数；
	因此，要从set类派生，增加交、并、差 三种函数即可。
*/

class Student
{
private:
	string strName;//姓名
	string strNo;//学号
public:
	Student(string no, string name) :strNo(no), strName(name)
	{

	}
	bool operator<(const Student& s)const //必须重载，按照学号升序排序
	{
		int mark = strNo.compare(s.strNo);
		return mark < 0 ? true : false;
	}

	string GetNo()
	{
		return strNo;
	}
	string GetName()
	{
		return strName;
	}

};

ostream& operator <<(ostream& os, Student& s)
{
	//为Student对象标准输出 重载
	os << s.GetNo() << "\t" << s.GetName() << endl;
	return os;
}


template<class T, class Pred = less<T>, class A = allocator<T>>
class MySet :public set<T, Pred, A> //继承集合set类
{
public:
	MySet(const T* first, const T* last) :set<T>(first, last)
	{

	}

	//两集合并集
	void add(MySet& second)
	{
		iterator it = second.begin();
		while (it != second.end())
		{
			insert(*it);
			it++;
		}
	}


	//两集合交集
	void Intersection(MySet& second)
	{
		set<T>mid;
		iterator it = begin();
		while (it != end())
		{
			if (second.find(*it) != second.end())//说明集合1的元素在second找到了，即共有的元素
			{
				mid.insert(*it);
			}
			it++;
		}
		swap(mid);
	}

	//两集合差集
	void Different(MySet& second)
	{
		set<T>mid;
		iterator it = begin();
		while (it != end())
		{
			if (second.find(*it) == second.end())//说明集合1的元素在second中没有发现
			{
				mid.insert(*it);
			}
			it++;
		}
		swap(mid);
	}
	
	////显示集合
	//void show()
	//{
	//	MySet<Student>::iterator it = begin();
	//	while (it != end())
	//	{
	//		cout << *it << endl;
	//	}
	//	cout << endl;
	//}
};


//我的集合测试函数
void hu_myset_test()
{
	Student s[2] = { {Student("1001","Tom")}, {Student("10002","Smith")} };
	Student t[3] = { {Student("1001","Yeelink") },{Student("1003","Bob")},{Student("1004","Flank")} };

	MySet<Student>m1(s, s + 2);
	MySet<Student>m2(t, t + 3);

	cout << "原始集合m1:";
	//m1.show();
	
	cout << "原始集合m2:";
	//m2.show();

	cout << "合并 m1 m2:" << endl;
	m1.add(m2);
	//m1.show();



	int a[] = { 1,2,3,4,5,6 };
	int b[] = { 2,3,6,7,8 };

	MySet<int>ms(a,a+6);
	MySet<int>ms2(b,b+5);

	show_set(ms);
	show_set(ms2);

	//ms.add(ms2);//并集
	//ms.Different(ms2);//差集
	ms.Intersection(ms2);//交集
	show_set(ms);

}


