#pragma once
#include <iostream>
using namespace std;

class CintArr
{
	int a[10];
public:
	CintArr()
	{
		for (int i = 0; i<10; i++)
		{
			a[i] = i + 1;
		}
	}

	int Sum(int t)
	{
		int sum = 0;
		for (int i; i<10; i++)
		{
			sum += a[i];
		}
		return sum *= t;
	}
};

class CfloatArr
{
	float a[10];
public:
	CfloatArr()
	{
		for (int i = 0; i<10; i++)
		{
			a[i] = 1.5f*i;
		}
	}

	float Sum(float t)
	{
		float sum = 0;
		for (int i; i<10; i++)
		{
			sum += a[i];
		}
		return sum *= t;
	}
};


template<class T>
class T2
{

};

template<>
class T2<CintArr>
{
public:
	typedef int hur;
	typedef int huin;
};

template<>
class T2<CfloatArr>
{
public:
	typedef float hur;
	typedef float huin;
};


template<class T>
class App
{
public:
	
	//typedef T2<T> ::hur rr;
	//typedef T2<T>::huin ii;
	float Sum(T& t, int in)
	{
		return t.Sum(in);
	}
};

void hu_trait()
{
	CintArr hui;
	CfloatArr huf;
	App<CintArr>c1;
	App<CfloatArr>c2;
	cout << c1.Sum(hui, 3) <<"end1"<< endl;
	cout << c2.Sum(huf, 3.2f) << endl;
}