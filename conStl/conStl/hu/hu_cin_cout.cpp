//��׼��������������̣�������׼�������������������ʾ������
/*
����������
int rdstate()�޲���������ֵ����״̬��Ϣ������ֵ cin.rdstate()
bool good()������true һ������
bool eof() ���� true �����ﵽ����ĩβ
bool fail() ����true ����I/O����ʧ�ܣ������˷Ƿ����ݣ������ȡ����ʱ������ĸ�������Լ���ʹ��
bool bad() �����������ϵĴ��������ܼ���ʹ��

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
	//����1 ָ���ַ���������ָ�룬���ڱ�����
	//����2 ����������
	//����3 �����ַ�
	cout << "First get() read ASCII is:" << n << endl;
	cout << "The buf receive string is :" << buf << endl;
	cout << "The buf2 receive string is :" << buf2 << endl;
	//system("pause");
	return 0;
}

//�ж��Ƿ��������κ���
void hu_int()
{
	int a;
	cout << "������һ������:";
	cin >> a;
	cout << "״̬��" << cin.rdstate() << endl;
	if (cin.good())
	{
		cout << "����������ȷ" << endl;

	}
	if (cin.fail())
	{
		cout << "�������ʹ�����";

	}
	cout << "�õ�������Ϊ��" << a << endl;
	//system("pause");
}


//ȷ������һ����������

void hu_int_sure()
{
	int a;
	while (1)
	{
		cout << "����һ���������ݣ�" << endl;
		cin >> a;
		if (cin.fail())
		{
			cout << "�������Ͳ������Σ����������룡";
			cin.clear();//���״̬��ʶλ
			cin.get();//�����������
			
		}
		else
		{
			cout << "�õ��������� ��" << a << endl;
			break;
		}
	}

}