#pragma once

/*
相对于vector 的连续线性空间，list 是一个双向链表
重要性质：插入和删除操作都不会造成原有的list迭代器失效
也就是说，对于任何位置的上插入删除，list 都是常数时间

常用函数：
1 构造函数
list<elem>c 创建一个空的list
list<elem>c(c1) 复制另一个同类型的list：c1
list<elem>c(n) 创建一个大小为n 的list
list<elem>c(n,x) 创建一个大小为n 的list，每一个元素都为 x
list<elem>c(begin,end) 有迭代器创建list，迭代区间为[begin,end]

2 大小 判断 空函数
int size() const 返回容器元素个数
bool empty() const 返回true，表明list 为空

3 增加 删除函数
void push_back(const T& x) list尾部增加一个元素 x
void push_front(const T& x) list 首元素之前增加一个元素 x
void pop_back() 当list 非空时，删除尾元素
void pop_front() 当list非空时，删除首元素
void remove(const T& x) 删除list 中所有等于x 的元素
void clear() 清空list

iterator insert(iterator it,const T& x=T()) 在迭代器指针it前插入x,返回迭代器指针
void insert(iterator it,int n,const T& x)   在迭代器指针it前插入n个x
void insert(it,first,last) 把[first,last]之间元素插入迭代器指针it前

iterator erase(iterator it) 删除迭代器指针it对应的元素
iterator erase(iterator first,iterator last) 删除迭代器指针[first,last]之间的元素

4 遍历函数
iterator begin() 返回首元素的迭代器指针
iterator end() 返回尾元素 之后的迭代器指针
reverse_iterator rend() 返回首元素的逆向迭代器指针，用于逆向遍历list
reverse_iterator rbegin() 返回尾元素的逆向迭代器指针，用于逆向遍历list

reference front() 返回首元素的引用
reference back() 返回尾元素的引用

5 操作函数
void sort() list内所有元素升序排序
template<class Pred>void sort(Pred pre) list所有元素根据预判定函数pre排序
void swap(list& str) 两个list容器交换功能
void unique() 容器内相邻元素若有重复的，则仅保留一个
void splice(iterator it,list& x) 队列合并函数，队列x 所有元素插入迭代指针it 前，x变空
void splice(iterator it,list&x,iterator first) 队列x 移除[first,end]之间元素插入it前
void splice(iterator it,list&x,iterator first,iterator last) 队列x 移除[first,last]之间元素插入it前
void reverse() 翻转list元素顺序


*/
#include <iostream>
#include <list>
#include <string>
using namespace std;
//list操作示例
void hu_list()
{
	list<string>test;
	test.push_back("back");
	test.push_front("middle");
	test.push_front("front");
	
	cout <<"front()"<< test.front() << endl;
	cout << "*(test.begin())" << *test.begin() << endl;
	cout << "back（）" << test.back() << endl;
	cout << "rbegin()" << *test.rbegin() << endl;
	test.pop_front();
	test.pop_back();
	cout << "删除收尾之后" << test.front() << endl;

}

//list 遍历示例

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

//sort merge splice 示例
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
	s.sort();//排序
	ss.sort();//排序

	//s.merge(ss);//两个list 合并 数据移动操作，ss中元素一次插入到s合适位置
	s.splice(s.begin(), ss);//splice() 拼接功能，也就是把ss 的元素移动到s的前面

for (list<int>::iterator it = s.begin(); it != s.end(); it++)
{
	cout << *it << "\t";
}
cout << "s.size()" << s.size() << endl;
cout << "ss.size()" << ss.size() << endl;


}

//综合示例
//两个文本文件包含某些学生的高考成绩：包含 准考证（关键字）、姓名、大学、总成绩信息
//由于某些原因，两个文件包含重复记录，现要求合并两个文件，去除重复记录，并按照准考证号升序排序

/*
分析：
1 把两个文件数据映射成 两个list 容器中的元素
2 利用 sort() 函数对两个list 容器按照准考证号升序排序
3 利用 merge() 函数合并已排好顺序的list
4 利用 unique() 函数去除重复的记录

*/

//构造学生信息类
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
		//由于对list容器按照准考证号排序，要重载基类的operator<操作符
		return strNo < s.strNo;
	}
	bool operator==(Student& s)
	{
		//由于对list容器按照准考证号排序，去除重复项，要重载基类的operator==操作符
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

//要用cout<<输出Student对象
//重载 ostream& operator<<操作符
ostream& operator<<(ostream& os, Student& s)
{
	cout << "我是cout<<重载输出";
	os<< s.GetNo() << "\t" << s.GetName() << "\t" << s.GetSchool() << "\t" << s.GetTotal();
	return os;
}

//管理类，封装了两个list 的排序，合并以及去除重复功能
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
		ls.sort();//第一个list排序
		sm.ls.sort();//第二个list排序
		ls.merge(sm.ls);//合并
		ls.unique();//去重
		return true;
	}
	void Show()
	{
		for (list<Student>::iterator it = ls.begin(); it != ls.end(); it++)
		{
			cout << *it << endl;//cout<<输出Student类
			
		}
		cout << endl;
		for (list<Student>::iterator it = ls.begin(); it != ls.end(); it++)
		{
			cout << "我直接输出：" << (*it).GetNo() << "\t"
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

	Student s1("1001", "张为民", "清华", 678);
	Student s2("1002", "魏玉华", "北大", 653);
	Student s3("1003", "赵信", "南京院", 432);
	Student s4("1004", "陈玉梅", "河南大学", 543);

	sm1.Add(s1);
	sm1.Add(s2);
	sm1.Add(s4);

	sm2.Add(s2);
	sm2.Add(s1);
	sm2.Add(s3);
	

	sm1.Merge(sm2);//合并
	sm1.Show();

}

