#pragma once
/*
C����û�й̶��Ķ����Ʊ�ʾ����
bitset ���Կ��������Ƶ����������ṩ����صĲ�������
����õ�bitset�Ƚ϶࣬λ�����ڴ洢״̬��ģ���ж��������ܶ෽�����ŷǳ��޴�����ƣ���������ת��һƪbitset�Ļ����÷���

==========================================================

1 ���캯��
bitset<n> b;
b��nλ��ÿλ��Ϊ0.����n����Ϊһ�����ʽ.
��bitset<5> b0;��"b0"Ϊ"00000";

bitset<n> b(unsigned long u);
b��nλ,����u��ֵ;���u����nλ,�򶥶˱��س�
��:bitset<5>b0(5);��"b0"Ϊ"00101";

bitset<n> b(string s);
b��string����s�к��е�λ���ĸ���
string bitval ( "10011" );
bitset<5> b0 ( bitval4 );
��"b0"Ϊ"10011";


bitset<n> b(s, pos);
b��s�д�λ��pos��ʼλ�ĸ���,ǰ��Ķ���λ�Զ����0;
string bitval ("01011010");
bitset<10> b0 ( bitval5, 3 );
��"b0" Ϊ "0000011010";

bitset<n> b(s, pos, num);
b��s�д�λ��pos��ʼ��num��λ�ĸ���,���num<n,��ǰ��Ŀ�λ�Զ����0;
string bitval ("11110011011");
bitset<6> b0 ( bitval5, 3, 6 );
��"b0" Ϊ "100110";


os << b
��b�е�λ�������os��
os >>b
���뵽b��,��"cin>>b",�������Ĳ���0��1���ַ�,ֻȡ���ַ�ǰ��Ķ�����λ.

2 ��������������
bool any( ) �Ƿ������Ϊ1�Ķ�����λ����none()�෴
bool none( ) �Ƿ񲻴�����Ϊ1�Ķ�����λ,��ȫ��Ϊ0����any()�෴.
size_t count( ) ������λΪ1�ĸ���.
size_t size( ) ������λ�ĸ���
flip() �����ж�����λ��λȡ��
flip(size_t pos) ����pos���Ķ�����λȡ��
bool operator[](   size_type _Pos ) ��ȡ��pos���Ķ�����λ
set() �����ж�����λ����Ϊ1
set(pos) ����pos���Ķ�����λ��Ϊ1
reset() �����ж�����λ����Ϊ0
reset(pos) ����pos���Ķ�����λ��Ϊ0
test(size_t pos) ��pos���Ķ�����λ�Ƿ�Ϊ1��
unsigned long to_ulong( ) ��ͬ���Ķ�����λ����һ��unsigned longֵ
string to_string () ���ض�Ӧ���ַ���.
*/


#include <iostream>
#include <string>
#include <bitset>
#include <vector>
#include <fstream>
using namespace std;
//��ʾ��
void hu_bitset()
{
	bitset<6>s1;//��ʼ��һ��������6λ���ڴ�ռ�
	cout << "��ʼ�ڴ�ռ䣺" << s1.to_string() << endl;
	cout << "λ�����ռ�(size):" << s1.size() << "\t" << "�� 1 ������count()��" << s1.count() << endl;
	s1.set(2, true);//�� �ڶ�λ ��1
	cout << "�ڶ�λ��1 ��" << s1.to_string() << endl;
	s1[4] = 1;//��һ�ֽ� ��4 λ��1��ʽ�������±귨
	cout << "����λ��1 ��" << s1.to_string() << endl;

	s1.set();//����λ��1
	cout << "����λ��1��set����" << s1.to_string() << endl;

	bitset<6>ss = s1;
	cout << "���Ʋ�����" << ss.to_string() << endl;


	bitset<8>s2(7);
	cout << "ͨ��������������������" << s2.to_string() << endl;

	bitset<12>s3("1111101");
	cout << "ͨ���ַ�������������" << s3.to_string() << endl;
}

void hu_bitset_operator()
{
	bitset<5>s1("01011");
	bitset<5>s2("11100");

	cout << "s1:" << s1.to_string() << endl
		<< "s2:" << s2.to_string() << endl;
	s1 &= s2;//����޸���s1
	cout << "s1=s1&s2:" << s1.to_string() << endl;


	bitset<5>s3("11011");
	bitset<5>s4("11100");

	cout << "s1:" << s3.to_string() << endl
		<< "s2:" << s4.to_string() << endl;
	s3 |= s4;//����޸���s1
	cout << "s3`d`=s3|s4:" << s3.to_string() << endl;


}

/*
�߼������ ����
bitset<n>s1;
bitset<n>s2;

s1&=s2 �����������ã����޸�s1
s1|=s2 ���ػ������ã����޸�s1
s1^s2 ������������ã����޸�s1
s1<<=n ����s1 ����nλ������ã����޸�s1
s1>>=n ����s1 ����nλ������ã����޸�s1

s1<<n ����s1 ����nλ��ı��ݣ�s1����
s1>>n ����s1 ����nλ��ı��ݣ�s1����
s1&s2 ����s1 s2 �����ı��ݣ�s1 s2����
s1|s2 ����s1 s2 ����ı��ݣ�s1 s2����
s1^s2 ����s1 s2 ������ı��ݣ�s1 s2����


*/
void hu_bitset_and_or()
{
	bitset<4>s1("0001");
	bitset<4>s2("0010");
	cout << "ԭʼs1:" << s1
		<< "ԭʼs2��" << s2 << endl;
	bitset<4>s3;
	cout << "ԭʼs3:"<<s3<<endl;
	/*cout << s1 << "ȡ��filp()��:";
	s3 = s1.flip();
	cout<<"s1�ı�:"<<s1<<"s3:"<< s3 <<endl;
	s3 = s1 << 2;
	cout <<s1<<"����2λ"<< s3 <<endl;

	s3.reset();
	cout << "s3���ã�" << s3 << endl;
	cout << "s1:" << s1 << "s2:" << s2 << endl;
	s3 = s1^s2;
	cout << s2 << "���" << s1 << "=" <<s3<< endl;*/
	cout << s1 << "&=" << s2 << "="  ;
	cout << (s1 |= s2);
	cout << endl << "s1" << s1 << "s2" << s2 << endl;
	//cout << "s1[1]" << s1[1] << endl;//ȡֵ[i]
	cout <<s1<<"ʮ���ƣ�"<< s1.to_ullong()<<endl;
}

/*
�ۺϲ�����
ͳ��ÿ�³���������
������
��ÿ�¶�����31����㣬����������״̬�����ڻ�ȱ�ڣ��ʲ���bitset λ���������������ʡ�ռ��
ÿ��31��״ֻ̬��31λ������4���ֽ�

*/
//size_t ����unsigned int ����
template<size_t N>
class MyAttend
{
	int month;//�·�
	bitset<N>b;//����λ����
public:
	MyAttend(int m, string str) :
		month(m), b(str)
	{

	}

	int GetMonth()
	{
		return month;
	}

	int GetAttendDays()
	{
		return b.count();//count��������1�ĸ���
	}

};

class Student
{
public:
	Student(string strname);
	~Student();
	void Add(MyAttend<31>& m);
	void ShowAttendDays();

private:
	string name;//ĳѧ������
	vector<MyAttend<31>>v;//���ڼ���

};

Student::Student(string strname)
{
	name = strname;
}

Student::~Student()
{
}

void Student::Add(MyAttend<31>& m)
{
	v.push_back(m);
}

void Student::ShowAttendDays()
{
	cout << "������" << name << endl;
	cout << "�·�\t��������" << endl;
	for (int i = 0; i < v.size(); i++)
	{
		MyAttend<31>& m = v.at(i);
		int month = m.GetMonth();
		int days = m.GetAttendDays();
		cout << month << "\t" << days << endl;
	}
}


void hu_student_attend()
{
	Student stud("�½���");
	string s1 = "100011110111001111";//����1�·ݳ���
	string s2 = "111111000111";//����2�·ݳ���
	MyAttend<31>m1(1, s1);
	MyAttend<31>m2(2, s2);

	stud.Add(m1);
	stud.Add(m2);
	stud.ShowAttendDays();
}

/*
�ۺ�ʾ��2��ѹ���ļ�
��֪n ���������飬���ȶ���10 ��Ԫ�ض���[1,20]֮�䣬�Ҿ������������ظ�����

ʹ��bitset ѹ����Щ���ݣ��������ļ���

������
����һ���������� {1,2,3,4,5,6,7,8,9,10} ����������ʽ�����ļ�������10*4=40�ֽ�
������ĿҪ�󣬿���һ��20λ��bitset ��������������飺������ĳλΪn���Ͱѵ�nλ��1,20λ�൱��2.5�ֽڣ����ļ�������С��λ���ֽ�
���޷���д2.5�ֽڣ����bitset����ѡ�� 24 λ��С���� 3�ֽڣ���ԭ�� 40�ֽ�С�˺ܶࡣ
*/


template<size_t N>
class MyNum
{
public:
	bitset<N>b;//λ����
public:
	void Set(int arr[], int size)
	{
		//����������ѹ����λ����
		b.reset();//��λ����
		for (int i = 0; i < size; i++)
		{
			b.set(arr[i] - 1, 1);
		}
	}
};

void hu_num_yasuo()
{
	//����ѹ������
	int a[3][10] = {{1,2,3,4,5,6,7,8,9,10},
				{1,3,4,5,6,8,9,12,13,14},
				{2,3,5,6,8,9,11,12,14,15}};
	ofstream out("data.txt",ios::trunc);
	MyNum<24>m;
	for (int i = 0; i < 3; i++)
	{
		m.Set(a[i], 10);
		out.write((char *)&m.b, 3);//����1 ��������ָ�� ����2 ��������С 3�ֽ�
		//cout << i << "\t";

	}
	out.close();

}

//��ȡ�������ļ�����
void hu_read_binary()
{
	ifstream in("data.txt");
	bitset<24>b;
	while (!in.eof())
	{	
		in.read((char*)&b, 3);
		for (int i = 0; i < 24; i++)
		{
		
			if (b.test(i))
			{
				cout << (i + 1) << "\t";
			}
		}
		cout << endl;

	}
	in.close();
}

