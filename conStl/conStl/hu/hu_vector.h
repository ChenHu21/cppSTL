#pragma once
/*
vector ����������ࣨ��̬���飩����Ԫ�������仯�Ķ�������

���ú���;
1 ���캯����
vector(): ����һ����vector
vector(int size): ����һ��Ԫ�ظ���Ϊsize��vector
vector(int size ,const T& t): ����һ��Ԫ�ظ���Ϊsize ,��ֵ��Ϊt��vector
vector(const vector&): ���ƹ��캯��

2 ���Ӻ�����
void push_back(const T& t) ����β������һ��Ԫ�� t
iterator insert(iterator it,const T& t):����ĳһԪ��ǰ����һ��Ԫ�� t
void insert(iterator it,int n,const T& t) ����ĳһԪ��ǰ����n����ͬԪ��t
void insert(iterator it,const_iterator first,const_iterator last) ����ĳһԪ��ǰ������һ����ͬ���͵�������[first,last]֮�������

3 ɾ��������
iterator erase(iterator it) ɾ��������ĳһԪ��
iterator erase(iterator first,iterator last) ɾ��������[first,last]Ԫ��
void pop_back() ɾ���������һ��Ԫ��
void clear() ɾ����������Ԫ��

4 ��������
at(int pos) ����posλ�õ�Ԫ������
front() ������Ԫ�ص�����
back() ����βԪ�ص�����
begin() ��������ͷָ�룬ָ���һ��ys
end() ��������βָ�룬���������һ��Ԫ��
rbegin() ��������������һ��Ԫ�صĵ���ָ��
rend() �������������һ��Ԫ��֮ǰ�ĵ���ָ��

5 �жϺ�����
empty() const: �����Ƿ�Ϊ�գ�����true������Ϊ��

6 ��С������
size() ��������Ԫ�ظ���
capacity() ���ص�ǰ���������������Ԫ�ظ���
max_size() �������������vectorԪ������ֵ

7 ����������
swap(vector&) ��������ͬ���͵���������
assign(int n,const T& t�������е�n��Ԫ�����ó� t
assign(const_iterator first,const_iterator last) ������[first,last]��Ԫ�����óɵ�ǰԪ��
*/

#include <vector>
#include <iostream>
#include <typeinfo>//�����������
using namespace std;

//������ʼ��
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

//��ʼ�� 2
//�ŵ㣺����ά�� 
//���磬����vector<int>�ĳ�vector<double> ��������������������ض��޸� 
//���棬ֻ��Ҫ�޸�typedef vector<int> INT_VECT---->typedef vector<double> INT_VECT;����
typedef vector<int> INT_VECT;
typedef vector<float> FLOAT_VECT;
typedef vector<A> A_VECT;
typedef vector<A*> AP_VECT;

void hu_vector_push_back()
{
	vector<int>huv;
	huv.push_back(1);//ͨ��push_back()�������
	huv.push_back(2);
	huv.push_back(3);
	int n = huv.size();//���Ԫ�ظ���
	cout << "ͨ�����鷽ʽ���:";
	for (int i = 0;i < n;i++)
	{
		cout << huv[i] << endl;
	}

	cout << "ͨ��������������";
	for (int i = 0;i < n;i++)
	{
		int &tv = huv.at(i);
		cout << tv << endl;
		//cout << huv.at(i) << endl;
	}

	cout << "ͨ�������������";
	vector<int>::iterator int_vec_iter = huv.begin();
	while (int_vec_iter != huv.end())
	{
		cout << *int_vec_iter << endl;
		int_vec_iter++;
	}

}

//�������������� Ԫ�ػ��

void hu_vector_class_push_back()
{
	vector<A>huv;
	A a1(1);
	A a2(2);
	A a3(3);
	huv.push_back(a1);//ͨ��push_back()�������
	huv.push_back(a2);
	huv.push_back(a3);
	int n = huv.size();//���Ԫ�ظ���
	cout << "ͨ�����鷽ʽ���:";
	for (int i = 0;i < n;i++)
	{
		cout << huv[i].n << endl;
	}

	cout << "ͨ��������������";
	for (int i = 0;i < n;i++)
	{
		A &tv = huv.at(i);
		cout << tv.n << endl;
		//cout << huv.at(i) << endl;
	}

	cout << "ͨ�������������";
	vector<A>::iterator int_vec_iter = huv.begin();
	while (int_vec_iter != huv.end())
	{
		cout << (*int_vec_iter).n << endl;
		int_vec_iter++;
	}

}

//������ָ���������� Ԫ�ػ��

void hu_vector_Pclass_push_back()
{
	vector<A*>huv;
	A* a1 = new A(1);
	A* a2 = new A(2);
	A* a3 = new A(3);
	huv.push_back(a1);//ͨ��push_back()�������
	huv.push_back(a2);
	huv.push_back(a3);
	int n = huv.size();//���Ԫ�ظ���
	cout << "ͨ�����鷽ʽ���:";
	for (int i = 0;i < n;i++)
	{
		cout << huv[i]->n << endl;
	}

	cout << "ͨ��������������";
	for (int i = 0;i < n;i++)
	{
		A* &tv = huv.at(i);
		cout << tv->n << endl;
		//cout << huv.at(i) << endl;
	}

	cout << "ͨ�������������";
	vector<A*>::iterator int_vec_iter = huv.begin();
	while (int_vec_iter != huv.end())
	{
		cout << (**int_vec_iter).n << endl;
		int_vec_iter++;
	}

}

//�޸�Ԫ��
//�������������� Ԫ�ػ��

void hu_vector_update()
{
	vector<int>huv;
	huv.push_back(1);//ͨ��push_back()�������
	huv.push_back(2);
	huv.push_back(3);
	int n = huv.size();//���Ԫ�ظ���
	cout << "ͨ�����鷽ʽ�޸�:";
	huv[1] = 222;
	for (int i = 0;i < n;i++)
	{
		cout << huv[i] << endl;
	}

	cout << "ͨ����������޸ģ�";
	int &m = huv.at(1);
	m = 222;
	for (int i = 0;i < n;i++)
	{
		int &tv = huv.at(i);
		cout << tv << endl;
		//cout << huv.at(i) << endl;
	}

	cout << "ͨ�������������";
	vector<int>::iterator int_vec_iter = huv.begin() + 1;
	*int_vec_iter = 222;
	for (int i = 0;i < n;i++)
	{
		cout << huv[i] << endl;
	}

}

//ɾ��Ԫ��
//�������������� Ԫ�ػ��

void hu_vector_delete()
{
	vector<int>huv;
	for (int i = 0;i < 10;i++)
	{
		huv.push_back(i);
	}
	//huv.push_back(1);//ͨ��push_back()�������
	//huv.push_back(2);
	//huv.push_back(3);
	//int n = huv.size();//���Ԫ�ظ���
	//vector<int>::iterator poshu = huv.begin() + 1;
	//cout << "huv.begin()�ҵ�������" << typeid(poshu).name() << endl;
	cout << "ɾ���ڶ���Ԫ��";

	huv.erase(huv.begin()+1);
	
	for (unsigned int i = 0;i < huv.size();i++)
	{
		cout << huv[i] << endl;
	}

	//ɾ��2~5��Ԫ��
	huv.erase(huv.begin() + 1, huv.begin() + 4);
	cout << "ɾ��2--5֮�����ݺ�";
	for (unsigned int i = 0;i < huv.size();i++)
	{
		cout << huv[i] << "\t";
	}
	cout << endl;

}



