#pragma once

/*
�����vector ���������Կռ䣬list ��һ��˫������
��Ҫ���ʣ������ɾ���������������ԭ�е�list������ʧЧ
Ҳ����˵�������κ�λ�õ��ϲ���ɾ����list ���ǳ���ʱ��

���ú�����
1 ���캯��
list<elem>c ����һ���յ�list
list<elem>c(c1) ������һ��ͬ���͵�list��c1
list<elem>c(n) ����һ����СΪn ��list
list<elem>c(n,x) ����һ����СΪn ��list��ÿһ��Ԫ�ض�Ϊ x
list<elem>c(begin,end) �е���������list����������Ϊ[begin,end]

2 ��С �ж� �պ���
int size() const ��������Ԫ�ظ���
bool empty() const ����true������list Ϊ��

3 ���� ɾ������
void push_back(const T& x) listβ������һ��Ԫ�� x
void push_front(const T& x) list ��Ԫ��֮ǰ����һ��Ԫ�� x
void pop_back() ��list �ǿ�ʱ��ɾ��βԪ��
void pop_front() ��list�ǿ�ʱ��ɾ����Ԫ��
void remove(const T& x) ɾ��list �����е���x ��Ԫ��
void clear() ���list

iterator insert(iterator it,const T& x=T()) �ڵ�����ָ��itǰ����x,���ص�����ָ��
void insert(iterator it,int n,const T& x)   �ڵ�����ָ��itǰ����n��x
void insert(it,first,last) ��[first,last]֮��Ԫ�ز��������ָ��itǰ

iterator erase(iterator it) ɾ��������ָ��it��Ӧ��Ԫ��
iterator erase(iterator first,iterator last) ɾ��������ָ��[first,last]֮���Ԫ��

4 ��������
iterator begin() ������Ԫ�صĵ�����ָ��
iterator end() ����βԪ�� ֮��ĵ�����ָ��
reverse_iterator rend() ������Ԫ�ص����������ָ�룬�����������list
reverse_iterator rbegin() ����βԪ�ص����������ָ�룬�����������list

reference front() ������Ԫ�ص�����
reference back() ����βԪ�ص�����

5 ��������
void sort() list������Ԫ����������
template<class Pred>void sort(Pred pre) list����Ԫ�ظ���Ԥ�ж�����pre����
void swap(list& str) ����list������������
void unique() ����������Ԫ�������ظ��ģ��������һ��
void splice(iterator it,list& x) ���кϲ�����������x ����Ԫ�ز������ָ��it ǰ��x���
void splice(iterator it,list&x,iterator first) ����x �Ƴ�[first,end]֮��Ԫ�ز���itǰ
void splice(iterator it,list&x,iterator first,iterator last) ����x �Ƴ�[first,last]֮��Ԫ�ز���itǰ
void reverse() ��תlistԪ��˳��


*/
#include <iostream>
#include <list>
#include <string>
using namespace std;
//list����ʾ��
void hu_list()
{
	list<string>test;
	test.push_back("back");
	test.push_front("middle");
	test.push_front("front");
	
	cout <<"front()"<< test.front() << endl;
	cout << "*(test.begin())" << *test.begin() << endl;
	cout << "back����" << test.back() << endl;
	cout << "rbegin()" << *test.rbegin() << endl;
	test.pop_front();
	test.pop_back();
	cout << "ɾ����β֮��" << test.front() << endl;

}

//list ����ʾ��

void hu_list_each()
{
	list<int>s;
	for (int i; i < 8; i++)
	{
		s.push_back(i+1);
	}

	//show
	list<int>::iterator it;
	for (it = s.begin(); it != s.end(); it++)
	{
		cout << *it << "\t";
	}

	//reverse show
	list<int>::reverse_iterator itr;
	for (itr = s.rbegin(); itr != s.rend(); itr++)
	{
		cout << *itr << "\t";
	}
}

//sort merge splice ʾ��
void hu_sort()
{
	list<int>s;
	s.push_back(1);
	s.push_back(4);
	s.push_back(6);
	s.push_back(2);
	s.push_back(20);
	list<int>ss;
	ss.push_back(12);
	ss.push_back(11);
	ss.push_back(7);
	ss.push_back(80);
	ss.push_back(43);
	cout << "s.size()" << s.size() << endl;
	cout << "ss.size()" << ss.size() << endl;
	s.sort();//����
	ss.sort();//����

	//s.merge(ss);//����list �ϲ� �����ƶ�������ss��Ԫ��һ�β��뵽s����λ��
	s.splice(s.begin(), ss);//splice() ƴ�ӹ��ܣ�Ҳ���ǰ�ss ��Ԫ���ƶ���s��ǰ��

for (list<int>::iterator it = s.begin(); it != s.end(); it++)
{
	cout << *it << "\t";
}
cout << "s.size()" << s.size() << endl;
cout << "ss.size()" << ss.size() << endl;


}

//�ۺ�ʾ��
//�����ı��ļ�����ĳЩѧ���ĸ߿��ɼ������� ׼��֤���ؼ��֣�����������ѧ���ܳɼ���Ϣ
//����ĳЩԭ�������ļ������ظ���¼����Ҫ��ϲ������ļ���ȥ���ظ���¼��������׼��֤����������

/*
������
1 �������ļ�����ӳ��� ����list �����е�Ԫ��
2 ���� sort() ����������list ��������׼��֤����������
3 ���� merge() �����ϲ����ź�˳���list
4 ���� unique() ����ȥ���ظ��ļ�¼

*/

//����ѧ����Ϣ��
class Student
{
private:
	string strNo;
	string strName;
	string strSchool;
	int mTotal;

public:
	Student(string no, string name, string sc, int tol) :
		strNo(no), strName(name), strSchool(sc), mTotal(tol)
	{

	}

	bool operator<(Student& s)
	{
		//���ڶ�list��������׼��֤������Ҫ���ػ����operator<������
		return strNo < s.strNo;
	}
	bool operator==(Student& s)
	{
		//���ڶ�list��������׼��֤������ȥ���ظ��Ҫ���ػ����operator==������
		return strNo == s.GetNo();
	}

	string GetNo()
	{
		return strNo;
	}

	string GetName()
	{
		return strName;
	}
	string GetSchool()
	{
		return strSchool;
	}
	int GetTotal()
	{
		return mTotal;
	}
};

//Ҫ��cout<<���Student����
//���� ostream& operator<<������
ostream& operator<<(ostream& os, Student& s)
{
	cout << "����cout<<�������";
	os<< s.GetNo() << "\t" << s.GetName() << "\t" << s.GetSchool() << "\t" << s.GetTotal();
	return os;
}

//�����࣬��װ������list �����򣬺ϲ��Լ�ȥ���ظ�����
class StudentManage
{
private:
	list<Student>ls;
public:
	bool Add(const Student& s)
	{
		ls.push_back(s);
		return true;
	}

	bool Merge(StudentManage& sm)
	{
		ls.sort();//��һ��list����
		sm.ls.sort();//�ڶ���list����
		ls.merge(sm.ls);//�ϲ�
		ls.unique();//ȥ��
		return true;
	}
	void Show()
	{
		for (list<Student>::iterator it = ls.begin(); it != ls.end(); it++)
		{
			cout << *it << endl;//cout<<���Student��
			
		}
		cout << endl;
		for (list<Student>::iterator it = ls.begin(); it != ls.end(); it++)
		{
			cout << "��ֱ�������" << (*it).GetNo() << "\t"
				<< (*it).GetName() << "\t"
				<< (*it).GetSchool() << "\t"
				<< (*it).GetTotal() << endl;
		}
	}
};

void hu_list_stu_merge()
{
	StudentManage sm1;
	StudentManage sm2;

	Student s1("1001", "��Ϊ��", "�廪", 678);
	Student s2("1002", "κ��", "����", 653);
	Student s3("1003", "����", "�Ͼ�Ժ", 432);
	Student s4("1004", "����÷", "���ϴ�ѧ", 543);

	sm1.Add(s1);
	sm1.Add(s2);
	sm1.Add(s4);

	sm2.Add(s2);
	sm2.Add(s1);
	sm2.Add(s3);
	

	sm1.Merge(sm2);//�ϲ�
	sm1.Show();

}

