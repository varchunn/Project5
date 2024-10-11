#include <iostream>
#include "MyString.h"
using namespace std;
ostream& operator<<(ostream& os, MyString& str)
{
	for (int i = 0; i < str.length; i++)
	{
		os << str.str[i] << "\t";
	}
	return os;
}

istream& operator>>(istream& is, MyString& str)
{
	for (int i = 0; i < str.length; i++)
	{
		cout << i << ": ";
		is >> str.str[i];
	}
	return is;
}

int main()
{
	/*MyString str1("I love world");
	MyString str2("I love you");
	MyString str3 = str1;
	MyString str4;
	str4.Input();
	str1.Output();
	str2.Output();
	str3.Output();
	str4.Output();*/

	MyString str5{ 'I', 'L', 'U' };
	str5.Output();
	MyString str6 = move(str5);
}