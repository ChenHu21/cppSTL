//标准输入流ｃｉｎ——键盘＞＞　标准输出流　ｃｏｕｔ——显示器＜＜
/*
处理流错误：
int rdstate()无参数，返回值既是状态信息的特征值 cin.rdstate()
bool good()若返回true 一切正常
bool eof() 返回 true 表明达到流的末尾
bool fail() 返回true 表明I/O操作失败，发生了非法数据（例如读取数字时遇到字母）流可以继续使用
bool bad() 发生了物理上的错误，流不能继续使用

*/
#include "hu_cin_cout.h"
int hu_cin_cout()
{
	int i;
	char str[20];
	cout << "Please Enter Int_number and Char_str:";
	cin >> i >> str;
	cout << "i=" << i << endl;
	cout << "str=" << str << endl;
	//system("pause");
	return 0;
}

int hu_get_getline()
{
	char buf[20];
	char buf2[20];
	cout << "Please Enter a String:";
	int n = cin.get();
	cin.get(buf, 20);
	cin.getline(buf2,20);
	//get(unsigned char* pszBuf,int nBufLen,char delim='\n')
	//getline(unsigned char* pszBuf,int nBufLen,char delim='\n')
	//参数1 指向字符缓存区的指针，用于保存结果
	//参数2 缓存区长度
	//参数3 结束字符
	cout << "First get() read ASCII is:" << n << endl;
	cout << "The buf receive string is :" << buf << endl;
	cout << "The buf2 receive string is :" << buf2 << endl;
	//system("pause");
	return 0;
}

//判断是否输入整形函数
void hu_int()
{
	int a;
	cout << "请输入一个数据:";
	cin >> a;
	cout << "状态：" << cin.rdstate() << endl;
	if (cin.good())
	{
		cout << "输入类型正确" << endl;

	}
	if (cin.fail())
	{
		cout << "输入类型错误了";

	}
	cout << "得到的数据为：" << a << endl;
	//system("pause");
}


//确保输入一个整型数据

void hu_int_sure()
{
	int a;
	while (1)
	{
		cout << "输入一个整形数据：" << endl;
		cin >> a;
		if (cin.fail())
		{
			cout << "输入类型不是整形，请重新输入！";
			cin.clear();//清空状态标识位
			cin.get();//清空流缓存区
			
		}
		else
		{
			cout << "得到整形数据 ：" << a << endl;
			break;
		}
	}

}