#pragma once
//#pragma execution_character_set("utf-8")


/*

再论迭代器
STL有一些可用的预迭代器

1 输入迭代器 按顺序只读一次 完成的功能有：构造/默认构造 复制/赋值 相等行比较 逐行向前移动 按行读取值
重载主要操作符：
operate*	访问迭代元素值
operate++()	前置迭代指针++
operate++(int)	后置迭代指针++
operate==	迭代元素相等比较
operate!=	迭代元素不等比较
STL提供的主要输入迭代器是：
istream_iterator
构造函数：
istream_iterator() 默认的构造函数，创建了一个流结束的迭代器
istream_iterator(istream &) 参数是输入流。含义是：从输入流读数据，遇到结束符时停止
例如：
istream_iterator<int>a(cin);//建立键盘输入流，并用istream_iterator 枚举整型数据
istream_iterator<int>b;//建立输入流结束迭代器
while(1)
{
cout<<*a;//调用 operator * ()-->输出整型数据
a++;//调用  operator ++ (int) -->迭代器指针指向下一元素
if(a==b)//调用 operator == -->当前迭代器等于结束迭代器
{
break;
}
}

2 输出迭代器 只写一次 完成的功能有： 构造/默认构造 复制/赋值 行相等比较 逐行向前移动 按行写入值
重载主要操作符：
operate*	分配迭代元素值空间
operate++()	前置迭代指针++
operate++(int)	后置迭代指针++
operate=	写入元素值

STL提供的主要输入迭代器是：
ostream_iterator
构造函数：
istream_iterator(ostream& out) 创建了一个流输出迭代器，用来迭代out输出流
istream_iterator(ostream& out,const char* delim ) 	创建了一个流输出迭代器，用来迭代out输出流,输出数据之间用 delim字符串分隔
例如：
ostream_iterator<int>myout(cout,"\t");//创建标准输出迭代器
*myout=1;//输出1
*myout=2;//输出1	2

3 插入迭代器 模板参数都是容器Cont
插入迭代器功能就是改变操作符 operator= 的实现来替代赋值操作；
构造函数都使用一个基本的序列容器对象 ——(vector/list 等)作为参数。
back_insert_iterator(Cont& x) 容器后插入迭代器：通过调用Push_back()函数完成的后插功能，即支持push_back()函数的容器才支持该迭代器:vecter/deque/list
front_insert_iterator(Cont& x) 容器前插入迭代器：通过调用Push_front()函数完成的后插功能，即支持push_front()函数的容器才支持该迭代器:deque/list
insert_iterator(Cont& x,Cont::iterator it) 容器某指定位置插入迭代器：通过调用insert()函数完成的插入功能，插入位置由 Cont::iterator it 迭代指针决定，对所有基本序列容器都适用

另外，还有两个迭代模板 函数 经常用到：
back_insert_iterator<Cont> back_inserter(Cont& x) 返回容器 x 的后插迭代器
front_insert_iterator<Cont> front_inserter(Cont& x) 返回容器 x 的前插迭代器
这两个函数的功能和back_insert_iterator(Cont& x)/front_insert_iterator(Cont& x) 功能是一样的，只不过从编程角度来说可以少些一些的代码，
但是，要注意：front_insert_iterator 是类；front_inserter 是函数

4 逆向迭代器
reverse_iterator(Ranit x)	Ranit 表示随机迭代器
reverse_bidirectional_iterator(Bidit x)	Bidit 表示双向迭代器
逆向迭代器的主要目的是逆向遍历容器元素序列，一般需要两个模板参数：1 迭代器类型 ，2 容器元素类型
例如：创建一个vector整型元素逆向迭代器（其中 v 表示已经创建的 vectot<int>容器）
		reverse_iterator<vector<int>::iterator,int>r(v.begin());
如何使用：
		一般来说，若容器中迭代器是随机迭代器，则应用 reverse_iterator；
		若容器中迭代器是双向迭代器，则应用 reverse_bidirectional_iterator。

5 迭代器函数
两个常用的函数：
advance 前移迭代指针
template<class InIt,class Dist>
void advance(InIt& it,Dist n)
distance 计算迭代器起止指针之间元素个数
template<class InIt,class Dist>
ptrdiff_t advance(InIt first,InIt last)

*/
#include <iostream>
#include <list>
#include <vector>
#include <iterator>
using namespace std;

void hu_test_ostream_iterator()
{//输出迭代器
	ostream_iterator<int>m(cout, "--");
	m = 2;
	m = 4;
	m = 3;//*m=2/3/4等效

}

void hu_test_istream_iterator()
{
	cout << "输入数字，非数字退出：";
	istream_iterator<int>m(cin);
	istream_iterator<int>b;//结束迭代器
	while (1)
	{
		cout << *m << endl;
		m++;
		if (m==b)
		{
			break;
		}

	}

}


void display(list<int>& v)
{//显示列表
	for (list<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "\t";
	}
	cout << endl;
}

void hu_test_STL()
{//插入迭代器示例
	list<int>v;
	back_insert_iterator<list<int>>backit(v);
	*backit++ = 1;
	*backit++ = 2;
	cout << "back_insert_iterator后插方式："<<endl;
	display(v);
	

	*back_inserter(v) = 3;
	*back_inserter(v) = 4;
	cout << "back_inserter后插方式："<<endl;

	display(v);

	front_insert_iterator<list<int>>frontit(v);
	*frontit++ = 5;
	*frontit++ = 6;
	cout << "front_insert_iterator前插方式："<<endl;

	display(v);

	*front_inserter(v) = 7;
	*front_inserter(v) = 8;
	cout << "front_inserter前插方式："<<endl;

	display(v);

	list<int>::iterator it = v.begin();
	for (int i = 0; i < 3; i++)
	{
		it++;//获得list 容器 v 的第 4 个元素迭代指针
	}

	insert_iterator<list<int>>insertit(v, it);
	*insertit++ = 9;
	*insertit++ = 10;
	cout << "insert_iterator前插方式："<<endl;

	display(v);
}

template<class T>
void show_reverse(T first, T last)
{
	//通用模板逆向显示函数
	while (first!=last)
	{
		cout << *first << "\t";
		first++;
	}
	cout << endl;
}
void hu_test_reverse()
{
	//逆向迭代器示例
	vector<int>v;
	list<int>l;
	for (int i = 0; i < 6; i++)
	{
		v.push_back(i);
		l.push_back(i);
	}

	cout << "vector 元素逆向显示：" << endl;
	reverse_iterator<vector<int>::iterator>first(v.end());
	reverse_iterator<vector<int>::iterator>last(v.begin());
	show_reverse(first, last);

	/*cout << "list 元素逆向显示：" << endl;
	reverse_bidirectional_iterator<list<int>::iterator,int>f(l.end());
	reverse_bidirectional_iterator<list<int>::iterator,int>l(l.begin());
	show_reverse(f, l);*/

}


//迭代器函数示例
//已知整型list容器序列 {1，2，3，4，5} 求：3 是第几个元素；显示3前面第2个元素
//分析：先用find函数查找3所在的迭代指针 mid；然后用 distance(l.begin(),mid) 获得3是第几个元素；最后用 advance(mid,2)前移2位指针，也就获得了3的前面第2个元素的迭代指针，显示值。
void hu_fumction_test()
{
	int a[] = { 1,2,3,4,5,6,7 };
	list<int>l(a, a + 7);
	cout << "list容器元素："<<endl;
	//list<int>l2(l);
	list<int>::iterator it = l.begin();
	while (it!=l.end())
	{
		cout << *it << "\t";
		it++;
	}

	cout << endl;
	list<int>::iterator mid = find(l.begin(), l.end(), 3);
	cout << "元素 3 位置：" << distance(l.begin(), mid)<<endl;
	advance(mid, 2);//参数2 正数 向前移动指针
	cout << "元素 3 前面第2 个元素是：" << *mid << endl;
	advance(mid, -4);//参数2 负数 向后移动指针
	cout << "元素 3 后面第2 个元素是：" << *mid << endl;



}