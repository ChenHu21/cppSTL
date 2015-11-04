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

	int a[] = { 2,3,4,6,5,6,7,78,8,2 };
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

	set<int>m4(a,a+alen);
	cout << "通过复制构造函数set(*first,*last) 创建集合：（没有重复元素）" << endl;
	show_set(m4);



}

