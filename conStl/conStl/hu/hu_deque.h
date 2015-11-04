#pragma once
/*
deque ����Ҳ��˫�˶���
Ϊһ���������͵�Ԫ�ؽ������Դ���������һ�������ܹ����ٵ��������ÿһ��Ԫ�أ������ܹ���Ч�Ĳ����ɾ��������β��Ԫ�أ�������vector��ͬ��deque��֧�ָ�Ч����ɾ��������ͷ��Ԫ��

���ú�����

1 ���캯��
deque() ����һ����deque
deque(int size) ����һ��Ԫ�ظ���Ϊ size ��deque
deque(int size,const T& t) ����һ����СΪsize,��ֵ��Ϊ t ��deque
deque(const deque&) ���ƹ��캯��

2 ���Ӻ�����
void push_front(const T& t) ˫�˶��ж�ͷ����һ��Ԫ�� t
void push_back(const T& t) ˫�˶��ж�β����һ��Ԫ�� t
iterator insert(iterator it,const T& t) ˫�˶�����ĳԪ��ǰ����һ��Ԫ�� t
void insert(iterator it,int n,const T& t) ˫�˶�����ĳһԪ��ǰ���� n ��Ԫ�� t
void insert(iterator it,const_it first,const_it last) ˫�˶�����ĳһԪ��ǰ������һ����ͬ����������[first,last]֮�������

3 ɾ��������
iterator erase(iterator it) ɾ��˫�˶�����ĳһԪ��
iterator erase(iterator first,iterator last) ɾ��˫�˶�����[first,last] ֮������
void pop_front() ɾ��˫�˶�����ǰһ��Ԫ�ء�����ͷ
void pop_back() ɾ��˫�˶������һ��Ԫ�ء�����β
void clear() ���˫�˶���

4 ��������
reference at(int pos) ����posλ��Ԫ�ص�����
reference front() ������Ԫ�ص�����
reference back() ����βԪ�ص�����
iterator begin() ��������ͷָ�룬ָ���һ��Ԫ��
iterator end() ��������βָ�룬���������һ��Ԫ�أ���������
reverse_iterator rbegin() ��������������һ��Ԫ�صĵ���ָ��
recerse_iterator rend() �������������һ��Ԫ��ǰ�ĵ���ָ��

5 ��С������
int size() const ��������Ԫ�ظ���
int max_size() const �������������˫�˶���Ԫ������ֵ

6 �жϺ���;
bool empty() const ����ʱ��Ϊ�գ������� true������� ����Ϊ��

7 ����
void swap(vector&) ��������ͬ��������������
void assign(int n,const T& t) �����е�n ��Ԫ�����ó�Ԫ��t
void assign(const_iterator first,const_iterator last) ������[first,last]�е�Ԫ�����óɵ�ǰ����Ԫ��

*/

#include <iostream>
#include <deque>
#include <string>
using namespace std;

//˫�˶��� ��β ��ͷ����
void hu_deque_push(int n)
{
	deque<int> md;
	for (int i = 0; i < n; i++)
	{
		md.push_back(i);
	}
	cout << "�Ӷ�β����ɹ���";
	for (unsigned int i = 0; i < md.size(); i++)
	{
		cout << md[i] << "\t";//�������Ԫ��
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		md.push_front(n + i);
	}
	cout << "�Ӷ�ͷ����ɹ���";
	for (unsigned int i = 0; i < md.size(); i++)
	{
		cout << md.at(i) << "\t";//at()��������Ԫ��
	}
	cout << endl;
}

//˫�˶��� ɾ��
void hu_deque_pop(int n)
{
	deque<int> md;
	for (int i = 0; i < n; i++)
	{
		md.push_back(i);
	}
	cout << "�Ӷ�β����ɹ���";
	for (unsigned int i = 0; i < md.size(); i++)
	{
		cout << md[i] << "\t";//�������Ԫ��
	}
	cout << endl;
	cout << "ɾ��ͷ����";
	md.pop_front();
	for (unsigned int i = 0; i < md.size(); i++)
	{
		cout << md[i] << "\t";//�������Ԫ��
	}
	cout << endl;

	cout << "ɾ��β��Ԫ�أ�";
	md.pop_back();                                                                                        
	for (unsigned int i = 0; i < md.size(); i++)
	{
		cout << md[i] << "\t";//�������Ԫ��
	}
	cout << endl;

}

//deque ��vector�ڴ����Ƚ�
/*
�ڽ��� vector ����ʱ��
�����ռ�-->�������-->�ؽ�����ռ�-->����Դ�ռ�-->ɾ��Դ�ռ�-->����»����ݣ�����֤vectorʼ����һ������������ڴ�ռ�

�ڽ���deque ����ʱ��
�����ռ�--���������--�������¿ռ�--������»�����--������û��Դ�ռ�ĸ��ơ�ɾ�����̣����ɶ���ֶ��������ڴ�ռ���ɵ�
*/

//�ҵ��Ƚ��ȳ�������
template<class T>
class MyQueue
{
	deque<T>d;
public:
	void push(const T& t)
	{
		d.push_back(t);//�Ƚ�
	}
	void pop()
	{
		d.pop_front();//�ȳ�
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
		return *d.begin();//ȡ�ö�ͷ
	}

	T& end()
	{
		return *(--d.end());//ȡ�ö�β
	}

	void diaplay()
	{
		//�����������Ԫ��
		for (unsigned int i = 0; i < d.size(); i++)
		{
			cout << d[i] << "\t";
		}
		cout << endl;
	}
};

//�ҵ�MyQueue ����
void hu_myqueue()
{
	MyQueue<int>m;
	for (int i = 0; i < 5; i++)
	{
		m.push(i);
	}
	m.diaplay();
	cout << "ɾ����ͷ";
	m.pop();
	m.diaplay();
	cout << "����";
	m.push(888);
	m.diaplay();
	cout << "��ǰ��ͷ��" << m.front() << "��ǰ��β��" << m.end() << endl;

}

void hu_myqs()
{
	MyQueue<string>m;
	m.push("l love");
	m.push(" you!");
	m.push("How are you");
	m.diaplay();
	cout << "ɾ����ͷ��" << m.front() << endl;

	m.pop();
	m.diaplay();
}