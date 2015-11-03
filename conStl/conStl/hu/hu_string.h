#pragma once
#include <string>
#include <iostream>
using namespace std;

int hu_string_create()
{
	//字符串基本创建示例：s1_s4均通过构造函数新建string
	string s1;
	string s2("hello you");
	string s3(s2);
	string s4(s2, 5, 4);//参数1 引用字符串，参数2 开始位置 参数3 复制长度
	string s5 = "Fine good";
	string s6 = s2 + s5 + "endString";
	string s7 = "This is before "+s2;


	//迭代器创建方式
	string s8(s7.begin(), s7.end());
	string s9(s7.begin(), s7.end()-4);
	cout << "s1" << s1 << endl;
	cout << "s2" << s2 << endl;
	cout << "s3" << s3 << endl;
	cout << "s4" << s4 << endl;
	cout << "s5" << s5 << endl;
	cout << "s6" << s6 << endl;
	cout << "s7:" << s7 << endl;
	cout << "s8:" << s8 << endl;
	cout << "s9:" << s9 << endl;

	cout << "长度length()" << s6.length() <<"长度size()"<<s6.size()<< endl;
	
	return 0;
}

//字符串插入操作
void hu_string_insert()
{
	string s = "you";
	cout << "Inition size is :" << s.size() << endl;
	s.insert(0, "How are ");//insert(插入元字符串位置，要插入的字符串 )
	s.append(" Nice to meet you");//append（在字符串末尾追加字符串）
	s += "End Inser string..";//+字符串连接
	cout << "Final size is :" << s.size() << endl;
	cout << s;


}

//字符串替换操作
void hu_string_replace()
{
	string str = "What is your name";
	cout << "替换前：" << str << endl;
	str.replace(0, 4, "Chen_jQ");
	cout << "替换后：" << str << endl;
}


//字符串查询
void hu_string_find()
{
	/*
	string::npos  这是string类的一个成员变量，一般应用在判断查询函数的返回值上，若等于该值，表明没有符合查询条件的结果

	s.find("str",pos) 在s中从 前往后 查找单个字符或字符串str，如果找到，返回首次匹配的开始位置，否则返回string::npos 
	参数1 待查询的字符串，参数2：查询的开始位置，默认为 0

	s.find_first_of("str",pos) 在s中查找，返回值是第一个与str中任何字符匹配的字符位置，没有找到，返回string::npos
	s.find_last_of("str",pos) 在s中查找，返回值是最后一个与str中任何字符匹配的字符位置，没有找到，返回string::npos
	s.find_first_not_of("str",pos) 在s中查找，返回值是第一个与str中任何字符都不匹配的字符位置，没有找到，返回string::npos
	s.find_last_not_of("str",pos) 在s中查找，返回值是最后一个与str中任何字符都不匹配的字符位置，没有找到，返回string::npos
	s.rfind("str",pos)  对s从 后到前 查找指定的字符 str ， 如果找到，返回首次匹配的开始位置，否则返回 string::npos
	参数2：pos 默认为S尾部
	*/

	string s = "I love you,my name is you name first word,and why you love me?";
	int n = s.find("you");
	cout << "The firs you pos is:" << n << endl;
	n = s.find("you", 10);
	cout << "The firs you pos begin from 10 is:" << n << endl;
	n = s.find_first_of("abcd");
	cout << "查找字符串 " << s << "第一次出现 abcd 之一的字符位置：" << n << endl;
	n = s.rfind("you");
	cout << "The last you pos is:" << n << endl;



}

//字符串删除
//s.erase(开始位置，结束位置)
void hu_string_erase()
{
	string s = "How are you and me";
	cout << s;
	s.erase(s.end() - 3, s.end());
	cout<< "删除最后3位字符后：" << s << endl;

}

//字符串比较  最简单的是使用重载的运算符 operator==/ !=/ >/ </ >=/ <= 比较ASCII值大小
void hu_string_compare()
{
	string s1 = "this";
	string s2 = "that";
	cout <<s1<< "< "<<s2<<"?" << (s1 < s2) << endl;
	cout << s1 << "> " << s2 << "?" << (s1 > s2) << endl;
}

//拆分字符串
void hu_string_spilt()
{
	string strResult = "";
	string str = "L love you,and you?";
	istringstream istr(str);//用字符串输入流封装字符串
	while (!istr.eof())//当没有达到字符串输入流末尾
	{
		//istr >> strResult;//空格拆分 等价于 getline(istr,strResult,' ');
		getline(istr, strResult, ',');//按照逗号拆分字符串，getline(原始字符串流，赋值目标字符串，拆分字符）
		cout << strResult << endl;
	}
}


//实现字符串两端去空格
void hu_string_trim()
{
	string s = "     I love you      ";
	cout << s;
	s.erase(0, s.find_first_not_of(" "));//删除做空格
	s.erase(s.find_last_not_of(" ") + 1);//删除右空格
	cout << "删除两边空格后：" << s << endl;
}

