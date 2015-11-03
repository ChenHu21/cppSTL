#pragma once
/*
vector 类称作向量类（动态数组）用于元素数量变化的对象数组

常用函数;
1 构造函数：
vector(): 创建一个空vector
vector(int size): 创建一个元素个数为size的vector
vector(int size ,const T& t): 创建一个元素个数为size ,且值均为t的vector
vector(const vector&): 复制构造函数

2 增加函数：
void push_back(const T& t) 向量尾部增加一个元素 t
iterator insert(iterator it,const T& t):向量某一元素前增加一个元素 t
void insert(iterator it,int n,const T& t) 向量某一元素前增加n个相同元素t
void insert(iterator it,const_iterator first,const_iterator last) 向量某一元素前插入另一个相同类型的向量的[first,last]之间的数据

3 删除函数：
iterator erase(iterator it) 删除向量中某一元素
iterator erase(iterator first,iterator last) 删除向量中[first,last]元素
void pop_back() 删除向量最后一个元素
void clear() 删除向量所有元素

4 遍历函数
at(int pos) 返回pos位置的元素引用
front() 返回首元素的引用
back() 返回尾元素的用于
begin() 返回向量头指针，指向第一个ys
end() 返回向量尾指针，不包括最后一个元素
rbegin() 反向迭代器，最后一个元素的迭代指针
rend() 反向迭代器，第一个元素之前的迭代指针

5 判断函数：
empty() const: 向量是否为空，返回true，向量为空

6 大小函数：
size() 返回向量元素个数
capacity() 返回当前向量所能容纳最大元素个数
max_size() 返回最大可允许的vector元素数量值

7 其他函数：
swap(vector&) 交换两个同类型的向量数据
assign(int n,const T& t）向量中第n个元素设置成 t
assign(const_iterator first,const_iterator last) 向量中[first,last]中元素设置成当前元素
*/

#include <vector>
#include <iostream>
#include <typeinfo>//输出数据类型
using namespace std;

//向量初始化
class A
{
	//..
public:
	int n;
public:
	A(int n)
	{
		this->n = n;
	}
};
vector<int>int_v;
vector<float>float_v;
vector<A>A_v;
vector<A*>A_pv;

//初始化 2
//优点：易于维护 
//例如，若把vector<int>改成vector<double> 上面必须把主程序所有相关都修改 
//下面，只需要修改typedef vector<int> INT_VECT---->typedef vector<double> INT_VECT;即可
typedef vector<int> INT_VECT;
typedef vector<float> FLOAT_VECT;
typedef vector<A> A_VECT;
typedef vector<A*> AP_VECT;

void hu_vector_push_back()
{
	vector<int>huv;
	huv.push_back(1);//通过push_back()函数添加
	huv.push_back(2);
	huv.push_back(3);
	int n = huv.size();//获得元素个数
	cout << "通过数组方式输出:";
	for (int i = 0;i < n;i++)
	{
		cout << huv[i] << endl;
	}

	cout << "通过获得引用输出：";
	for (int i = 0;i < n;i++)
	{
		int &tv = huv.at(i);
		cout << tv << endl;
		//cout << huv.at(i) << endl;
	}

	cout << "通过迭代器输出：";
	vector<int>::iterator int_vec_iter = huv.begin();
	while (int_vec_iter != huv.end())
	{
		cout << *int_vec_iter << endl;
		int_vec_iter++;
	}

}

//针对类的向量增加 元素获得

void hu_vector_class_push_back()
{
	vector<A>huv;
	A a1(1);
	A a2(2);
	A a3(3);
	huv.push_back(a1);//通过push_back()函数添加
	huv.push_back(a2);
	huv.push_back(a3);
	int n = huv.size();//获得元素个数
	cout << "通过数组方式输出:";
	for (int i = 0;i < n;i++)
	{
		cout << huv[i].n << endl;
	}

	cout << "通过获得引用输出：";
	for (int i = 0;i < n;i++)
	{
		A &tv = huv.at(i);
		cout << tv.n << endl;
		//cout << huv.at(i) << endl;
	}

	cout << "通过迭代器输出：";
	vector<A>::iterator int_vec_iter = huv.begin();
	while (int_vec_iter != huv.end())
	{
		cout << (*int_vec_iter).n << endl;
		int_vec_iter++;
	}

}

//针对类的指针向量增加 元素获得

void hu_vector_Pclass_push_back()
{
	vector<A*>huv;
	A* a1 = new A(1);
	A* a2 = new A(2);
	A* a3 = new A(3);
	huv.push_back(a1);//通过push_back()函数添加
	huv.push_back(a2);
	huv.push_back(a3);
	int n = huv.size();//获得元素个数
	cout << "通过数组方式输出:";
	for (int i = 0;i < n;i++)
	{
		cout << huv[i]->n << endl;
	}

	cout << "通过获得引用输出：";
	for (int i = 0;i < n;i++)
	{
		A* &tv = huv.at(i);
		cout << tv->n << endl;
		//cout << huv.at(i) << endl;
	}

	cout << "通过迭代器输出：";
	vector<A*>::iterator int_vec_iter = huv.begin();
	while (int_vec_iter != huv.end())
	{
		cout << (**int_vec_iter).n << endl;
		int_vec_iter++;
	}

}

//修改元素
//针对类的向量增加 元素获得

void hu_vector_update()
{
	vector<int>huv;
	huv.push_back(1);//通过push_back()函数添加
	huv.push_back(2);
	huv.push_back(3);
	int n = huv.size();//获得元素个数
	cout << "通过数组方式修改:";
	huv[1] = 222;
	for (int i = 0;i < n;i++)
	{
		cout << huv[i] << endl;
	}

	cout << "通过获得引用修改：";
	int &m = huv.at(1);
	m = 222;
	for (int i = 0;i < n;i++)
	{
		int &tv = huv.at(i);
		cout << tv << endl;
		//cout << huv.at(i) << endl;
	}

	cout << "通过迭代器输出：";
	vector<int>::iterator int_vec_iter = huv.begin() + 1;
	*int_vec_iter = 222;
	for (int i = 0;i < n;i++)
	{
		cout << huv[i] << endl;
	}

}

//删除元素
//针对类的向量增加 元素获得

void hu_vector_delete()
{
	vector<int>huv;
	for (int i = 0;i < 10;i++)
	{
		huv.push_back(i);
	}
	//huv.push_back(1);//通过push_back()函数添加
	//huv.push_back(2);
	//huv.push_back(3);
	//int n = huv.size();//获得元素个数
	//vector<int>::iterator poshu = huv.begin() + 1;
	//cout << "huv.begin()我的类型是" << typeid(poshu).name() << endl;
	cout << "删除第二个元素";

	huv.erase(huv.begin()+1);
	
	for (unsigned int i = 0;i < huv.size();i++)
	{
		cout << huv[i] << endl;
	}

	//删除2~5个元素
	huv.erase(huv.begin() + 1, huv.begin() + 4);
	cout << "删除2--5之间数据后：";
	for (unsigned int i = 0;i < huv.size();i++)
	{
		cout << huv[i] << "\t";
	}
	cout << endl;

}



