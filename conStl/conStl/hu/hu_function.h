#pragma once
//函数对象是重载了 operator() 的类的一个实例 operator() 是函数调用运算符
//operator()参数个数划分：
/*
0个：发生器 一种没有参数且返回一个任意类型值得函数对象，例如随机数发生器
1个：一元函数 一种只有一个任意类型的参数，且返回一个任意类型的函数对象
2个：二元函数 一种有两个任意类型的参数，且返回一个任意类型的函数对象
一元判定函数：返回bool型的一元函数
二元判定函数：返回bool型的二元函数
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
class MyClass
{
public:
	MyClass()
	{
		sum = 0;
	}

	void operator()(int n)
	{
		sum += n;
	}
	int GetSum()
	{
		return sum;
	}

private:
	int sum;
};

void hu_sum()
{
	vector<int>v;
	for (int i = 1;i <= 100;i++)
	{
		v.push_back(i);
	}
	MyClass husum = for_each(v.begin(), v.end(), MyClass());
	cout << husum.GetSum();
}

//一元函数 原型
template<class A,class B>
struct Hu_one
{
	typedef A input_type;
	typedef B output_type;

};


//template<class _invar,class _outvar>
//class CSum :public Hu_one<class _invar, class _outvar>
//{
//public:
//	_outvar sum;
//	CSum() { sum = 0; }
//	void operator()(_invar n)
//	{
//		sum += n;
//	}
//	_outvar GetSum() { return sum; }
//
//};
//
//void hu_sum_one()
//{
//	vector<float>v2;
//	float f = 1.3f;
//	for (int i = 1;i <= 99;i++)
//	{
//		v2.push_back(f);
//		f += 1.0f;
//
//	}
//
//	CSum<float, float>fobj = for_each(v2.begin(), v2.end(), CSum<float, float>());
//	cout << "sum(float)=" << fobj.GetSum();
//}

//系统函数

void hu_system_function()
{
	//实例化算术对象
	plus<int>plusObj;//加法
	minus<int>minusObj;//减法

	cout << plusObj(2, 4) << endl;
	cout << minusObj(6, 3 )<< endl;
	cout << divides<int>()(8, 2) << endl;
}