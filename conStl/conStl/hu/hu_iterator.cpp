#include "hu_iterator.h"
int hu_iterator()
{	//���������
	cout << "���������ݣ���1 2 3 ����";
	istream_iterator<int>b;//��������������������
	istream_iterator<int>a(cin);//��������������������istream_iterator ö����������
	while (1)
	{
		cout << *a << endl;
		a++;
		if (a == b)
		{
			break;
		}
	}

	cout << "�����������";
	ostream_iterator<int>myout(cout, "\t");
	*myout = 1;
	//myout++;

	*myout = 3;
	myout++;
	*myout = 4;


	system("pause");
	return 0;
}
