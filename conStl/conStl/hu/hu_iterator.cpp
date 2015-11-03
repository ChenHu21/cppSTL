#include "hu_iterator.h"
int hu_iterator()
{	//输入迭代器
	cout << "请输入数据（如1 2 3 ，）";
	istream_iterator<int>b;//建立输入流结束迭代器
	istream_iterator<int>a(cin);//建立键盘输入流，并用istream_iterator 枚举整形数据
	while (1)
	{
		cout << *a << endl;
		a++;
		if (a == b)
		{
			break;
		}
	}

	cout << "输出迭代器：";
	ostream_iterator<int>myout(cout, "\t");
	*myout = 1;
	//myout++;

	*myout = 3;
	myout++;
	*myout = 4;


	system("pause");
	return 0;
}
