#pragma once
//���������������� operator() �����һ��ʵ�� operator() �Ǻ������������
//operator()�����������֣�
/*
0���������� һ��û�в����ҷ���һ����������ֵ�ú����������������������
1����һԪ���� һ��ֻ��һ���������͵Ĳ������ҷ���һ���������͵ĺ�������
2������Ԫ���� һ���������������͵Ĳ������ҷ���һ���������͵ĺ�������
һԪ�ж�����������bool�͵�һԪ����
��Ԫ�ж�����������bool�͵Ķ�Ԫ����
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

//һԪ���� ԭ��
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

//ϵͳ����

void hu_system_function()
{
	//ʵ������������
	plus<int>plusObj;//�ӷ�
	minus<int>minusObj;//����

	cout << plusObj(2, 4) << endl;
	cout << minusObj(6, 3 )<< endl;
	cout << divides<int>()(8, 2) << endl;
}