#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

/*
优先队列既 priority_queue 类
带有优先权的队列，优先权高的元素先出队

1 构造函数
priority_queue(const Pred& pr=Pred(),const allocator_type& al=allocator_type())
创建元素类型为T的空优先队列，Pred是二元比较函数，默认 less<T>
priority_queue(const value_type* first,const value_type* last,const Pred& pr=Pred(),const allocator_type& al=allocator_type())
一迭代器[first,last]指向元素，创建元素类型为T的优先队列，Pred是二元比较函数，默认 less<T>
2 操作函数
bool empty()
int size()
void push(const T& t) t元素压入优先队列
void pop() 非空时，删除优先级最高元素
T& top() 非空时，返回优先级最高元素的引用
*/

void showQueue(priority_queue<int>obj)
{
	while (!obj.empty())
	{
		cout << obj.top() << "\t";
		obj.pop();
	}
	cout << endl;
}
void hu_priority_queue()
{
	int a[] = { 1,2,3,4,9,7,6,5,8 };
	priority_queue<int>pr(a, a + 8);
	pr.push(88);
	cout << "进队时";
	//copy(a, a + 7, ostream_iterator<int>(cout, "\t"));
	showQueue(pr);
	//copy(a, a + 8, ostream_iterator<int>(cout, "\t"));



}