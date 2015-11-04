#pragma once
#include <iostream>
#include <string>

using namespace std;

template<class U,class V>
bool MyBiger(U u, V v)
{
	return u > v;
}

class HU
{
	string name;
	int age;
public:
	HU(string str,int m):name(str),age(m)
	{

	}

	bool operator()(int v)
	{
		return h.age > v;
	}
};


