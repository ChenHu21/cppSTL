#pragma once
/*
deque 容器也叫双端队列
为一个给定类型的元素进行线性处理，与向量一样，它能够快速地随机访问每一个元素，并且能够高效的插入和删除容器的尾部元素，但又与vector不同，deque还支持高效插入删除容器的头部元素

常用函数：

1 构造函数
deque() 创建一个空deque
deque(int size) 创建一个元素个数为 size 的deque
deque(int size,const T& t) 创建一个大小为size,且值均为 t 的deque
deque(const deque&) 复制构造函数

2 增加函数：
void push_front(const T& t) 双端队列队头增加一个元素 t
void push_back(const T& t) 双端队列队尾增加一个元素 t
iterator insert(iterator it,const T& t) 双端队列中某元素前增加一个元素 t
void insert(iterator it,int n,const T& t) 双端队列中某一元素前增加 n 个元素 t
void insert(iterator it,const_it first,const_it last) 双端队列中某一元素前插入另一个相同类型向量的[first,last]之间的数据

3 删除函数：
iterator erase(iterator it) 删除双端队列中某一元素
iterator erase(iterator first,iterator last) 删除双端队列中[first,last] 之间数据
void pop_front() 删除双端队列最前一个元素——队头
void pop_back() 删除双端队列最后一个元素——队尾
void clear() 清空双端队列

4 遍历函数
reference at(int pos) 返回pos位置元素的引用
reference front() 返回首元素的引用
reference back() 返回尾元素的引用
iterator begin() 返回向量头指针，指向第一个元素
iterator end() 返回向量尾指针，不包括最后一个元素，在其下面
reverse_iterator rbegin() 反向迭代器，最后一个元素的迭代指针
recerse_iterator rend() 反向迭代器，第一个元素前的迭代指针

5 大小函数：
int size() const 返回向量元素个数
int max_size() const 返回最大可允许的双端队列元素数量值

6 判断函数;
bool empty() const 向量时候为空，若返回 true，这表明 向量为空

7 其他
void swap(vector&) 交换两个同类型向量的数据
void assign(int n,const T& t) 向量中第n 个元素设置成元素t
void assign(const_iterator first,const_iterator last) 向量中[first,last]中的元素设置成当前向量元素

*/

#include <iostream>
#include <deque>
#include <string>
using namespace std;

//双端队列 队尾 队头操作
void hu_deque_push(int n)
{
	deque<int> md;
	for (int i = 0; i < n; i++)
	{
		md.push_back(i);
	}
	cout << "从队尾插入成功！";
	for (unsigned int i = 0; i < md.size(); i++)
	{
		cout << md[i] << "\t";//数组访问元素
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		md.push_front(n + i);
	}
	cout << "从队头插入成功！";
	for (unsigned int i = 0; i < md.size(); i++)
	{
		cout << md.at(i) << "\t";//at()函数访问元素
	}
	cout << endl;
}

//双端队列 删除
void hu_deque_pop(int n)
{
	deque<int> md;
	for (int i = 0; i < n; i++)
	{
		md.push_back(i);
	}
	cout << "从队尾插入成功！";
	for (unsigned int i = 0; i < md.size(); i++)
	{
		cout << md[i] << "\t";//数组访问元素
	}
	cout << endl;
	cout << "删除头部：";
	md.pop_front();
	for (unsigned int i = 0; i < md.size(); i++)
	{
		cout << md[i] << "\t";//数组访问元素
	}
	cout << endl;

	cout << "删除尾部元素：";
	md.pop_back();                                                                                        
	for (unsigned int i = 0; i < md.size(); i++)
	{
		cout << md[i] << "\t";//数组访问元素
	}
	cout << endl;

}

//deque 和vector内存分配比较
/*
在建立 vector 容器时：
建立空间-->填充数据-->重建更大空间-->复制源空间-->删除源空间-->添加新华数据：：保证vector始终是一块独立的连续内存空间

在建立deque 容器时：
建立空间--》填充数据--》建立新空间--》填充新华数据--》：：没有源空间的复制、删除过程，是由多个分段连续的内存空间组成的
*/

//我的先进先出队列类
template<class T>
class MyQueue
{
	deque<T>d;
public:
	void push(const T& t)
	{
		d.push_back(t);//先进
	}
	void pop()
	{
		d.pop_front();//先出
	}
	int size()
	{
		return d.size();
	}

	bool empty()
	{
		return d.empty();
	}

	T& front()
	{
		return *d.begin();//取得队头
	}

	T& end()
	{
		return *(--d.end());//取得队尾
	}

	void diaplay()
	{
		//输出队列所有元素
		for (unsigned int i = 0; i < d.size(); i++)
		{
			cout << d[i] << "\t";
		}
		cout << endl;
	}
};

//我的MyQueue 调用
void hu_myqueue()
{
	MyQueue<int>m;
	for (int i = 0; i < 5; i++)
	{
		m.push(i);
	}
	m.diaplay();
	cout << "删除队头";
	m.pop();
	m.diaplay();
	cout << "插入";
	m.push(888);
	m.diaplay();
	cout << "当前队头：" << m.front() << "当前队尾：" << m.end() << endl;

}

void hu_myqs()
{
	MyQueue<string>m;
	m.push("l love");
	m.push(" you!");
	m.push("How are you");
	m.diaplay();
	cout << "删除队头：" << m.front() << endl;

	m.pop();
	m.diaplay();
}