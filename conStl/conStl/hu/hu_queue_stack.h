#pragma once
/*
���� ��ջ
1 ���캯��
queue(class T,class Container==deque<T>) ����Ԫ������ΪT�Ŀն��У�Ĭ�������� deque--�������ԣ�list��

stack(class T,class Container==deque<T>) ����Ԫ������ΪT�Ŀն�ջ��Ĭ�������� deque--�������ԣ�vector/list��

2 ��������
bool empty() ������У�ջ��Ϊ�գ����� true
int size() ���ض��У�ջ����Ԫ�ظ���
void push(const T& t) ��Ԫ�� tѹ���β��ջ����
void pop() ��ǰ���У�ջ���ǿ�ʱ��ɾ����ͷ��ջ����Ԫ��

3 ���ж��к�����
T& front() ���зǿ�ʱ�����ض��еĶ�ͷԪ��
T& back() ���зǿ�ʱ�����ض��еĶ�βԪ��

4 ��ջ���к���
T& top() ջ�ǿ�����£�����ջ��Ԫ��
*/

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

//��ջ��������1
void Display(stack<int, vector<int>>obj)
{
	while (!obj.empty())
	{
		cout << obj.top() << "\t";
		obj.pop();

	}
}

//��ջ��������2
void Display(stack<string, list<string>>obj)
{
	while (!obj.empty())
	{
		cout << obj.top() << "\t";
		obj.pop();

	}
}

//��ջ����ģ�庯��
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
	//�ַ�����ջ
	string str = "a";
	stack<string, list<string>>sl;
	for (int i = 0; i < 5; i++)
	{
		sl.push(str);
		str += "a";
	}
	Display(sl);

	cout << endl;
	//�����ջ
	stack<float, deque<float>>sf;
	for (int i = 0; i < 5; i++)
	{
		sf.push(i + 0.3);
	}
	Display(sf);

	cout << endl;
}

//���в���

//���б���ģ�庯��
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
	//�ַ�������
	string str = "a";
	queue<string, deque<string>>qs;
	for (int i = 0; i < 5; i++)
	{
		qs.push(str);
		str += "a";
	}

	Display(qs);
	//�������

	queue<float, list<float>>qf;
	for (int i = 0; i < 5; i++)
	{
		qf.push(i + 0.1);
	}

	Display(qf);
	cout <<"��ͷ��"<< qf.back() <<"��β��"<< qf.front()<<endl;
	qf.pop();
	cout << "pop()֮��";
	Display(qf);

}


//һ���̶���С�Ķ�ջ,�ҵĶ�ջ
template<class T,class C>
class HuStack:public stack<T,C>//�̳�stack
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
			cout << "��ջ����" << t << "û�����ջ";
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

