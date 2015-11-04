#pragma once
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

/*
���ȶ��м� priority_queue ��
��������Ȩ�Ķ��У�����Ȩ�ߵ�Ԫ���ȳ���

1 ���캯��
priority_queue(const Pred& pr=Pred(),const allocator_type& al=allocator_type())
����Ԫ������ΪT�Ŀ����ȶ��У�Pred�Ƕ�Ԫ�ȽϺ�����Ĭ�� less<T>
priority_queue(const value_type* first,const value_type* last,const Pred& pr=Pred(),const allocator_type& al=allocator_type())
һ������[first,last]ָ��Ԫ�أ�����Ԫ������ΪT�����ȶ��У�Pred�Ƕ�Ԫ�ȽϺ�����Ĭ�� less<T>
2 ��������
bool empty()
int size()
void push(const T& t) tԪ��ѹ�����ȶ���
void pop() �ǿ�ʱ��ɾ�����ȼ����Ԫ��
T& top() �ǿ�ʱ���������ȼ����Ԫ�ص�����
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
	cout << "����ʱ";
	//copy(a, a + 7, ostream_iterator<int>(cout, "\t"));
	showQueue(pr);
	//copy(a, a + 8, ostream_iterator<int>(cout, "\t"));



}