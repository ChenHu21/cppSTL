#pragma once
#include <string>
#include <iostream>
using namespace std;

int hu_string_create()
{
	//�ַ�����������ʾ����s1_s4��ͨ�����캯���½�string
	string s1;
	string s2("hello you");
	string s3(s2);
	string s4(s2, 5, 4);//����1 �����ַ���������2 ��ʼλ�� ����3 ���Ƴ���
	string s5 = "Fine good";
	string s6 = s2 + s5 + "endString";
	string s7 = "This is before "+s2;


	//������������ʽ
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

	cout << "����length()" << s6.length() <<"����size()"<<s6.size()<< endl;
	
	return 0;
}

//�ַ����������
void hu_string_insert()
{
	string s = "you";
	cout << "Inition size is :" << s.size() << endl;
	s.insert(0, "How are ");//insert(����Ԫ�ַ���λ�ã�Ҫ������ַ��� )
	s.append(" Nice to meet you");//append�����ַ���ĩβ׷���ַ�����
	s += "End Inser string..";//+�ַ�������
	cout << "Final size is :" << s.size() << endl;
	cout << s;


}

//�ַ����滻����
void hu_string_replace()
{
	string str = "What is your name";
	cout << "�滻ǰ��" << str << endl;
	str.replace(0, 4, "Chen_jQ");
	cout << "�滻��" << str << endl;
}


//�ַ�����ѯ
void hu_string_find()
{
	/*
	string::npos  ����string���һ����Ա������һ��Ӧ�����жϲ�ѯ�����ķ���ֵ�ϣ������ڸ�ֵ������û�з��ϲ�ѯ�����Ľ��

	s.find("str",pos) ��s�д� ǰ���� ���ҵ����ַ����ַ���str������ҵ��������״�ƥ��Ŀ�ʼλ�ã����򷵻�string::npos 
	����1 ����ѯ���ַ���������2����ѯ�Ŀ�ʼλ�ã�Ĭ��Ϊ 0

	s.find_first_of("str",pos) ��s�в��ң�����ֵ�ǵ�һ����str���κ��ַ�ƥ����ַ�λ�ã�û���ҵ�������string::npos
	s.find_last_of("str",pos) ��s�в��ң�����ֵ�����һ����str���κ��ַ�ƥ����ַ�λ�ã�û���ҵ�������string::npos
	s.find_first_not_of("str",pos) ��s�в��ң�����ֵ�ǵ�һ����str���κ��ַ�����ƥ����ַ�λ�ã�û���ҵ�������string::npos
	s.find_last_not_of("str",pos) ��s�в��ң�����ֵ�����һ����str���κ��ַ�����ƥ����ַ�λ�ã�û���ҵ�������string::npos
	s.rfind("str",pos)  ��s�� ��ǰ ����ָ�����ַ� str �� ����ҵ��������״�ƥ��Ŀ�ʼλ�ã����򷵻� string::npos
	����2��pos Ĭ��ΪSβ��
	*/

	string s = "I love you,my name is you name first word,and why you love me?";
	int n = s.find("you");
	cout << "The firs you pos is:" << n << endl;
	n = s.find("you", 10);
	cout << "The firs you pos begin from 10 is:" << n << endl;
	n = s.find_first_of("abcd");
	cout << "�����ַ��� " << s << "��һ�γ��� abcd ֮һ���ַ�λ�ã�" << n << endl;
	n = s.rfind("you");
	cout << "The last you pos is:" << n << endl;



}

//�ַ���ɾ��
//s.erase(��ʼλ�ã�����λ��)
void hu_string_erase()
{
	string s = "How are you and me";
	cout << s;
	s.erase(s.end() - 3, s.end());
	cout<< "ɾ�����3λ�ַ���" << s << endl;

}

//�ַ����Ƚ�  ��򵥵���ʹ�����ص������ operator==/ !=/ >/ </ >=/ <= �Ƚ�ASCIIֵ��С
void hu_string_compare()
{
	string s1 = "this";
	string s2 = "that";
	cout <<s1<< "< "<<s2<<"?" << (s1 < s2) << endl;
	cout << s1 << "> " << s2 << "?" << (s1 > s2) << endl;
}

//����ַ���
void hu_string_spilt()
{
	string strResult = "";
	string str = "L love you,and you?";
	istringstream istr(str);//���ַ�����������װ�ַ���
	while (!istr.eof())//��û�дﵽ�ַ���������ĩβ
	{
		//istr >> strResult;//�ո��� �ȼ��� getline(istr,strResult,' ');
		getline(istr, strResult, ',');//���ն��Ų���ַ�����getline(ԭʼ�ַ���������ֵĿ���ַ���������ַ���
		cout << strResult << endl;
	}
}


//ʵ���ַ�������ȥ�ո�
void hu_string_trim()
{
	string s = "     I love you      ";
	cout << s;
	s.erase(0, s.find_first_not_of(" "));//ɾ�����ո�
	s.erase(s.find_last_not_of(" ") + 1);//ɾ���ҿո�
	cout << "ɾ�����߿ո��" << s << endl;
}

