#pragma once
/*
set/multiset ���Ǽ����࣬������� set�в��������ظ�Ԫ�أ�multiset �������ظ�

���ú�����

1 ���캯����
set(const Pred& comp=Pred(),const A& al=A()) �����ռ���
set(const set& x) ���ƹ��캯��
set(const value_type* first,const_vaoue_type *last,const Pred& comp=Pred(),const A& al=A()) ����[first,last]֮���Ԫ�ع����¼���

multiset(const Pred& comp=Pred(),const A& al=A()) �����ռ���
multiset(const set& x) ���ƹ��캯��
multiset(const value_type* first,const_vaoue_type *last,const Pred& comp=Pred(),const A& al=A()) ����[first,last]֮���Ԫ�ع����¼���

2 ��С�жϿպ���
int size()  ���ؼ���Ԫ�ظ���
bool empty() const�ж������Ƿ�Ϊ�գ�����true ������Ϊ��
 

3 ���� ɾ������
pair<iterator,bool>insert(const value_type& x) ����Ԫ��x
iterator insert(iterator it,const value_type& x) �ڵ�����ָ��it������Ԫ��x
void insert(const value_type* first,const_type* last) ����[first,last]������ָ��֮���Ԫ��

iterator erase(iterator it) ɾ������ָ��it��Ԫ��
iterator erase(iterator first,iterator last) ɾ��[first,last] ����ָ��֮���Ԫ��
size_type erase(const Key& key) ɾ��Ԫ��ֵ���� key ��Ԫ��

4 ��������
iterator begin() ������Ԫ�صĵ�����ָ��
iterator end() ����βԪ�غ�ĵ�����ָ��
reverse_iterator rbegin() ����βԪ�ص����������ָ�룬���������������
reverse_iterator rend() ������Ԫ�ص����������ָ�룬���������������

5 ��������
const_iterator lower_bound(const Key& key) ��������Ԫ��С�ڵ���<=key�ĵ���ָ�룬���򷵻�end()
const_iterator upper_bound(const Key& key) ��������Ԫ�ش��ڵ���>=key�ĵ���ָ�룬���򷵻�end()
const_iterator find(const Key& key) ���ҹ��ܣ���������Ԫ�ش��ڵ���=key�ĵ���ָ��
pair<const_iterator,const_iterator>equal_range(const Key& key) ����������Ԫ�ص���=key �ĵ���ָ��[first,last)
int count(const Key& key) ����������Ԫ��ֵ����key��Ԫ�ظ���

void swap(set& s) ����������Ԫ��
void swap(multiset& s) �����༯��Ԫ��

*/

#include <iostream>
#include <set>
using namespace std;
//�����γɼ��ϵķ���

void show_set(set<int>& s)
{//��ʾ�����������
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << "\t";
		it++;
	}
	cout << endl;
}

void show_multiset(multiset<int>& s)
{//��ʾ�����������
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
	int alen = sizeof(a) / sizeof(int);//��ü���Ԫ�ظ���
	multiset<int>m;//Ĭ�ϼ�����������
	for (int i = 0; i < alen; i++)
	{
		m.insert(a[i]);

	}
	cout << "ͨ��insert() ��Ӽ��ϣ�" << endl;
	show_multiset(m);

	multiset<int>m2(m);//���Ƽ���m
	cout << "ͨ�����ƹ��캯�� multiset(const set& x)�������ϣ�" << endl;
	show_multiset(m2);

	multiset<int>m3(a, a + alen);
	cout << "ͨ�����ƹ��캯��multiset(*first,*last) �������ϣ�" << endl;
	show_multiset(m3);

	set<int>m4(a,a+alen);
	cout << "ͨ�����ƹ��캯��set(*first,*last) �������ϣ���û���ظ�Ԫ�أ�" << endl;
	show_set(m4);



}

