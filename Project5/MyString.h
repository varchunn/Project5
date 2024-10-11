#pragma once
#include<iostream>
using namespace std;

class MyString
{
	char* str;
	int length;
	static int count;
	friend ostream& operator<<(ostream& os, MyString& str);
	friend istream& operator>>(istream& is, MyString& str);
public:
	static int GetCount();
	MyString();
	MyString(const char* str);
	MyString(const MyString& str);
	MyString(MyString&& obj);
	MyString(initializer_list <char>obj);

	void Input();
	void Output();
	void MyStrcpy(MyString& obj);
	bool MyStrStr(const char* str);
	int  MyChr(char c);
	int MyStrLen();
	void MyStrCat(MyString& obj);
	void MyDelChr(char c);
	int MyStrCmp(MyString& b);

	MyString& operator=(const MyString& obj);
	MyString& operator= (MyString&& obj);
	MyString& operator +=(const MyString& obj);

	char operator[] (int index);
	void operator() ();

        MyString operator+(char c);       
        friend MyString operator+(char c, const MyString& obj); 
        MyString operator+(int num);       
        friend MyString operator+(int num, const MyString& obj); 
	~MyString();
};
