#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student
{//学生信息类
public:
	string m_strNo;
	string m_strNmae;
	string m_strSex;
	string m_strDate;
public:
	Student(string strNo, string strName, string strSex, string strDate) ://初始化变量
		m_strNo(m_strNo), m_strNmae(strName), m_strSex(strSex), m_strDate(strDate)
	{
		//构造函数
	}
	void Display()
	{
		cout << m_strNo << "\t" << m_strNmae << "\t" << m_strSex << "\t" << m_strDate << endl;
	}
};


class StudCollect
{
	vector<Student>m_vStu;
public:
	void Add(Student& s)
	{
		m_vStu.push_back(s);//添加学生信息到vector

	}

	Student* Find(string strNo)
	{
		bool bFind = false;
		for (int i = 0; i < m_vStu.size(); i++)
		{
			Student& s = m_vStu.at(i);
			if (s.m_strNo == strNo)
			{
				bFind = true;
				break;
			}
		}
		Student* s = NULL;
		if (bFind)
		{
			s = &m_vStu.at(i);
		}
		return s;
	}


};


void hu_vector_student(string str)
{
	Student s1("1001", "张亚平", "男", "2015-4-6");
	Student s2("1002", "jobth", "女", "2015-6-12");
	Student s3("1003", "韩雨芹", "女", "2016-9-1");
	StudCollect sc;
	sc.Add(s1);
	sc.Add(s2);
	sc.Add(s3);
	Student* ps = sc.Find(str);
	if (ps)
	{
		ps->Display();
	}
}