#pragma once
/*
队列 和栈
1 构造函数
queue(class T,class Container==deque<T>) 创建元素类型为T的空队列，默认容器是 deque--（还可以：list）

stack(class T,class Container==deque<T>) 创建元素类型为T的空堆栈，默认容器是 deque--（还可以：vector/list）

2 操作函数
bool empty() 如果队列（栈）为空，返回 true
int size() 返回队列（栈）中元素个数
void push(const T& t) 把元素 t压入队尾（栈顶）
void pop() 当前队列（栈）非空时，删除队头（栈顶）元素

3 队列独有函数：
T& front() 队列非空时，返回队列的队头元素
T& back() 队列非空时，返回队列的队尾元素

4 堆栈独有函数
T& top() 栈非空情况下，返回栈顶元素
*/

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

//堆栈遍历函数1
void Display(stack<int, vector<int>>obj)
{
	while (!obj.empty())
	{
		cout << obj.top() << "\t";
		obj.pop();

	}
}

//堆栈遍历函数2
void Display(stack<string, list<string>>obj)
{
	while (!obj.empty())
	{
		cout << obj.top() << "\t";
		obj.pop();

	}
}

//堆栈遍历模板函数
template<class T, class Container>
void Display(stack<T, Container>obj)
{

	while (!obj.empty())
	{
		cout << obj.top() << "\t";
		obj.pop();

	}
}

void hu_stack()
{
	stack<int, vector<int>>s;
	for (int i = 0; i < 6; i++)
	{
		s.push(i);
	}
	Display(s);

	cout << endl;
	//字符串堆栈
	string str = "a";
	stack<string, list<string>>sl;
	for (int i = 0; i < 5; i++)
	{
		sl.push(str);
		str += "a";
	}
	Display(sl);

	cout << endl;
	//浮点堆栈
	stack<float, deque<float>>sf;
	for (int i = 0; i < 5; i++)
	{
		sf.push(i + 0.3);
	}
	Display(sf);

	cout << endl;
}

//队列操作

//队列遍历模板函数
template<class T, class Container>
void Display(queue<T, Container>obj)
{

	while (!obj.empty())
	{
		cout << obj.front() << "\t";
		obj.pop();
		
	}
	cout << endl;
}
void hu_queue()
{
	//字符串队列
	string str = "a";
	queue<string, deque<string>>qs;
	for (int i = 0; i < 5; i++)
	{
		qs.push(str);
		str += "a";
	}

	Display(qs);
	//浮点队列

	queue<float, list<float>>qf;
	for (int i = 0; i < 5; i++)
	{
		qf.push(i + 0.1);
	}

	Display(qf);
	cout <<"队头："<< qf.back() <<"队尾："<< qf.front()<<endl;
	qf.pop();
	cout << "pop()之后：";
	Display(qf);

}


//一个固定大小的堆栈,我的堆栈
template<class T,class C>
class HuStack:public stack<T,C>//继承stack
{
private:
	int mMaxSize;
public:
	HuStack(int m)
	{
		mMaxSize = m;
	}

	void push(const T& t)
	{
		if (size() < mMaxSize)
		{
			stack<T, C>::push(t);
		}
		else
		{
			cout << "堆栈已满" << t << "没有入堆栈";
		}
	}
};

void hu_mystack()
{
	HuStack<int, deque<int>>ms(2);
	for (int i = 0; i < 5; i++)
	{
		ms.push(i);
		cout << endl;
	}

	Display(ms);

}

