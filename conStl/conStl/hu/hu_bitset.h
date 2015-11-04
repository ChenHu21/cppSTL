#pragma once
/*
C语言没有固定的二进制表示方法
bitset 可以看做二进制的容器，并提供了相关的操作函数
最近用的bitset比较多，位运算在存储状态、模拟行动、搜索很多方面有着非常巨大的优势，所以特意转了一篇bitset的基本用法。

==========================================================

1 构造函数
bitset<n> b;
b有n位，每位都为0.参数n可以为一个表达式.
如bitset<5> b0;则"b0"为"00000";

bitset<n> b(unsigned long u);
b有n位,并用u赋值;如果u超过n位,则顶端被截除
如:bitset<5>b0(5);则"b0"为"00101";

bitset<n> b(string s);
b是string对象s中含有的位串的副本
string bitval ( "10011" );
bitset<5> b0 ( bitval4 );
则"b0"为"10011";


bitset<n> b(s, pos);
b是s中从位置pos开始位的副本,前面的多余位自动填充0;
string bitval ("01011010");
bitset<10> b0 ( bitval5, 3 );
则"b0" 为 "0000011010";

bitset<n> b(s, pos, num);
b是s中从位置pos开始的num个位的副本,如果num<n,则前面的空位自动填充0;
string bitval ("11110011011");
bitset<6> b0 ( bitval5, 3, 6 );
则"b0" 为 "100110";


os << b
把b中的位集输出到os流
os >>b
输入到b中,如"cin>>b",如果输入的不是0或1的字符,只取该字符前面的二进制位.

2 其他操作函数：
bool any( ) 是否存在置为1的二进制位？和none()相反
bool none( ) 是否不存在置为1的二进制位,即全部为0？和any()相反.
size_t count( ) 二进制位为1的个数.
size_t size( ) 二进制位的个数
flip() 把所有二进制位逐位取反
flip(size_t pos) 把在pos处的二进制位取反
bool operator[](   size_type _Pos ) 获取在pos处的二进制位
set() 把所有二进制位都置为1
set(pos) 把在pos处的二进制位置为1
reset() 把所有二进制位都置为0
reset(pos) 把在pos处的二进制位置为0
test(size_t pos) 在pos处的二进制位是否为1？
unsigned long to_ulong( ) 用同样的二进制位返回一个unsigned long值
string to_string () 返回对应的字符串.
*/


#include <iostream>
#include <string>
#include <bitset>
#include <vector>
#include <fstream>
using namespace std;
//简单示例
void hu_bitset()
{
	bitset<6>s1;//初始化一个至少有6位的内存空间
	cout << "初始内存空间：" << s1.to_string() << endl;
	cout << "位容器空间(size):" << s1.size() << "\t" << "置 1 个数（count()）" << s1.count() << endl;
	s1.set(2, true);//将 第二位 置1
	cout << "第二位置1 后：" << s1.to_string() << endl;
	s1[4] = 1;//另一种将 第4 位置1方式，数组下标法
	cout << "第四位置1 后：" << s1.to_string() << endl;

	s1.set();//所有位置1
	cout << "所有位置1（set）：" << s1.to_string() << endl;

	bitset<6>ss = s1;
	cout << "复制操作：" << ss.to_string() << endl;


	bitset<8>s2(7);
	cout << "通过长整型数建立容器：" << s2.to_string() << endl;

	bitset<12>s3("1111101");
	cout << "通过字符串建立容器：" << s3.to_string() << endl;
}

void hu_bitset_operator()
{
	bitset<5>s1("01011");
	bitset<5>s2("11100");

	cout << "s1:" << s1.to_string() << endl
		<< "s2:" << s2.to_string() << endl;
	s1 &= s2;//结果修改了s1
	cout << "s1=s1&s2:" << s1.to_string() << endl;


	bitset<5>s3("11011");
	bitset<5>s4("11100");

	cout << "s1:" << s3.to_string() << endl
		<< "s2:" << s4.to_string() << endl;
	s3 |= s4;//结果修改了s1
	cout << "s3`d`=s3|s4:" << s3.to_string() << endl;


}

/*
逻辑运算符 与或非
bitset<n>s1;
bitset<n>s2;

s1&=s2 返回与后的引用，并修改s1
s1|=s2 返回或后的引用，并修改s1
s1^s2 返回异或后的引用，并修改s1
s1<<=n 返回s1 左移n位后的引用，并修改s1
s1>>=n 返回s1 右移n位后的引用，并修改s1

s1<<n 返回s1 左移n位后的备份，s1不变
s1>>n 返回s1 右移n位后的备份，s1不变
s1&s2 返回s1 s2 相与后的备份，s1 s2不变
s1|s2 返回s1 s2 相或后的备份，s1 s2不变
s1^s2 返回s1 s2 相异或后的备份，s1 s2不变


*/
void hu_bitset_and_or()
{
	bitset<4>s1("0001");
	bitset<4>s2("0010");
	cout << "原始s1:" << s1
		<< "原始s2：" << s2 << endl;
	bitset<4>s3;
	cout << "原始s3:"<<s3<<endl;
	/*cout << s1 << "取反filp()后:";
	s3 = s1.flip();
	cout<<"s1改变:"<<s1<<"s3:"<< s3 <<endl;
	s3 = s1 << 2;
	cout <<s1<<"左移2位"<< s3 <<endl;

	s3.reset();
	cout << "s3重置：" << s3 << endl;
	cout << "s1:" << s1 << "s2:" << s2 << endl;
	s3 = s1^s2;
	cout << s2 << "异或" << s1 << "=" <<s3<< endl;*/
	cout << s1 << "&=" << s2 << "="  ;
	cout << (s1 |= s2);
	cout << endl << "s1" << s1 << "s2" << s2 << endl;
	//cout << "s1[1]" << s1[1] << endl;//取值[i]
	cout <<s1<<"十进制："<< s1.to_ullong()<<endl;
}

/*
综合操作：
统计每月出勤天数：
分析：
若每月都按照31天计算，出勤有两种状态：出勤或缺勤：故采用bitset 位向量来描述是最节省空间的
每月31天状态只用31位，不到4个字节

*/
//size_t 即：unsigned int 类型
template<size_t N>
class MyAttend
{
	int month;//月份
	bitset<N>b;//出勤位容器
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
		return b.count();//count（）返回1的个数
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
	string name;//某学生姓名
	vector<MyAttend<31>>v;//出勤集合

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
	cout << "姓名：" << name << endl;
	cout << "月份\t出勤天数" << endl;
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
	Student stud("陈讲清");
	string s1 = "100011110111001111";//定义1月份出勤
	string s2 = "111111000111";//定义2月份出勤
	MyAttend<31>m1(1, s1);
	MyAttend<31>m2(2, s2);

	stud.Add(m1);
	stud.Add(m2);
	stud.ShowAttendDays();
}

/*
综合示例2：压缩文件
已知n 个整型数组，长度都是10 ，元素都在[1,20]之间，且均递增排序，无重复数据

使用bitset 压缩这些数据，并存入文件中

分析：
假设一个整型数组 {1,2,3,4,5,6,7,8,9,10} 若按正常方式存入文件，共有10*4=40字节
根据题目要求，可用一个20位的bitset 容器保存这个数组：若数组某位为n，就把第n位置1,20位相当于2.5字节，但文件操作最小单位是字节
，无法读写2.5字节，因此bitset容器选择 24 位大小，即 3字节，比原来 40字节小了很多。
*/


template<size_t N>
class MyNum
{
public:
	bitset<N>b;//位容器
public:
	void Set(int arr[], int size)
	{
		//把整型数组压缩成位容器
		b.reset();//复位容器
		for (int i = 0; i < size; i++)
		{
			b.set(arr[i] - 1, 1);
		}
	}
};

void hu_num_yasuo()
{
	//数组压缩操作
	int a[3][10] = {{1,2,3,4,5,6,7,8,9,10},
				{1,3,4,5,6,8,9,12,13,14},
				{2,3,5,6,8,9,11,12,14,15}};
	ofstream out("data.txt",ios::trunc);
	MyNum<24>m;
	for (int i = 0; i < 3; i++)
	{
		m.Set(a[i], 10);
		out.write((char *)&m.b, 3);//参数1 缓存区的指针 参数2 缓存区大小 3字节
		//cout << i << "\t";

	}
	out.close();

}

//读取二进制文件数据
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

