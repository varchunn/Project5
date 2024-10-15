#pragma once
#include <iostream>
#include <initializer_list>
using namespace std;

class MyString 
{
private:
    char* str;
    int length;
    static int count;

public:
    const char* GetStr() const;
    void SetStr(const char* string);
    int GetLength() const;
    
    static int GetCount();

    MyString();
    MyString(const char* str);
    MyString(const MyString& str);
    MyString(MyString& obj);
    MyString(const char* obj);
    MyString(const char* chars); 
    MyString(MyString&& obj); 
    MyString& operator=(MyString&& obj);

    ~MyString();

    void Input();
    void Output();
    
    void Print(ostream& os) const;   
    void Read(istream& is);          

    MyString& operator=(const MyString& obj);
    MyString& operator=(MyString& obj);
    MyString& operator+=(const MyString& obj);

    char operator[](int index);
    void operator()();

    MyString operator+(char c); 
    MyString operator+(int num); 

    static MyString AddChar(char c, const MyString& obj); 
    static MyString AddNum(int num, const MyString& obj); 

    void MyStrcpy(MyString& obj);
    bool MyStrStr(const char* str);
    int MyChr(char c);
    int MyStrLen();
    void MyStrCat(MyString& obj);
    void MyDelChr(char c);
    int MyStrCmp(MyString& b);
};
