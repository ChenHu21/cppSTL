#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student
{//ѧ����Ϣ��
public:
	string m_strNo;
	string m_strNmae;
	string m_strSex;
	string m_strDate;
public:
	Student(string strNo, string strName, string strSex, string strDate) :
		m_strNo(strNo), m_strNmae(strName), m_strSex(strSex), m_strDate(strDate)
	{
		//���캯��
		Display();
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
		m_vStu.push_back(s);//���ѧ����Ϣ��vector

	}

	Student* Find(string strNo)
	{
		bool bFind = false;
		unsigned int i;
		for (i = 0; i < m_vStu.size(); i++)
		{
			Student& s = m_vStu.at(i);
			//cout << "In for" << s.m_strNo;
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
	Student s1("1001", "����ƽ", "��", "2015-4-6");
	Student s2("1002", "jobth", "Ů", "2015-6-12");
	Student s3("1003", "������", "Ů", "2016-9-1");
	Student s4("1004", "Ī����", "��", "2015-10-21");
	Student s5("1005", "����", "Ů", "2016-9-1");
	Student s6("1006", "Ī��", "��", "2015-10-21");
	StudCollect sc;
	sc.Add(s1);
	sc.Add(s2);
	sc.Add(s3);
	sc.Add(s4), sc.Add(s5), sc.Add(s6);
	Student* ps = sc.Find(str);
	if (ps)
	{
		cout << "Find it! m_strNo=" << str << "Sdudent infromation" << endl;
		ps->Display();
	}
	cout << "end"<<endl;
}