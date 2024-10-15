#include <iostream>
#include "MyString.h" 
using namespace std;

int MyString::GetCount()
{
    return count;
}

MyString::MyString() 
{
    str = nullptr;
    length = 0;
    count++;
}

MyString::MyString(const char* string) 
{
    str = new char[strlen(string) + 1];
    strcpy_s(str, strlen(string) + 1, string);
    length = strlen(string);
    count++;
}

MyString::MyString(const MyString& string) 
{
    str = new char[strlen(string.str) + 1];
    strcpy_s(str, strlen(string.str) + 1, string.str);
    length = strlen(string.str);
}

MyString::MyString(MyString& obj) 
{
    str = obj.str;
    length = obj.length;
    obj.str = nullptr;
    obj.length = 0;
    cout << "Move constr" << endl;
}

MyString::MyString(const char* arr) 
{
    cout << "initializer list" << endl;
    length = strlen(arr);
    str = new char[length + 1];

    for (int i = 0; i < length; i++) 
    {
        str[i] = arr[i]; 
    }

    str[length] = '\0';
}

void MyString::Input()
{
    char string[225];
    cout << "Enter text: ";
    cin.getline(string, 225);
    SetStr(string);  
}

void MyString::Output() const
{
    cout << GetStr(); 
}

const char* MyString::GetStr() const 
{
    return str;
}

void MyString::SetStr(const char* newStr) 
{
    if (str != nullptr) 
    {
        delete[] str;
    }
    str = new char[strlen(newStr) + 1];
    strcpy_s(str, strlen(newStr) + 1, newStr);
    length = strlen(newStr);
}

ostream& operator<<(ostream& out, const MyString& obj)
{
    out << obj.GetStr(); 
    return out;
}

istream& operator>>(istream& in, MyString& obj)
{
    char buffer[256];
    in.getline(buffer, 256);
    obj.SetStr(buffer);  
    return in;
}

void MyString::MyStrcpy(MyString& obj) 
{
    SetStr(obj.GetStr()); 
}

bool MyString::MyStrStr(const char* string) 
{
    for (int i = 0; i < strlen(string); i++)
        {
        for (int j = 0; j < strlen(str); j++)
            {
            if (string[i] == str[j]) {
                cout << "Found!";
                return true;
                break;
            } else {
                cout << "Not found";
                return false;
            }
        }
    }
}

int MyString::MyChr(char c)
{
    for (int i = 0; i < strlen(str); i++)
        {
        if (str[i] == c)
        {
            return i + 1;
        }
    }
    return -1;
}

int MyString::MyStrLen() const
{
    return strlen(str);
}

void MyString::MyStrCat(MyString& obj)
{
    str = new char[strlen(str) + strlen(obj.GetStr()) + 1];
    strcat_s(str, strlen(str) + strlen(obj.GetStr()) + 1, obj.GetStr());
}

void MyString::MyDelChr(char c) 
{
    for (int i = 0; i < strlen(str); i++)
        {
        if (str[i] == c) 
        {
            length--;
            str[i] = str[i + 1];
        }
    }
}

int MyString::MyStrCmp(MyString& obj)
{
    if (strlen(str) == strlen(obj.GetStr()))
    {
        return 0;
    } else if (strlen(str) > strlen(obj.GetStr())) 
    {
        return -1;
    } else 
    {
        return 1;
    }
}

MyString& MyString::operator=(const MyString& obj)
{
    if (this == &obj) 
    {
        return *this;
    }
    SetStr(obj.GetStr());  
    return *this;
}

MyString& MyString::operator=(MyString& obj)
{
    if (this != &obj)
    {
        SetStr(obj.GetStr());
        length = obj.length;
        obj.str = nullptr;
        obj.length = 0;
    }
    cout << "Move =" << endl;
    return *this;
}

MyString& MyString::operator+=(const MyString& obj) 
{
    int newLength = length + obj.length;
    char* tempStr = new char[newLength + 1];
    strcpy_s(tempStr, length + 1, str);
    strcat_s(tempStr, newLength + 1, obj.str);
    
    delete[] str;
    str = tempStr;
    length = newLength;
    
    return *this;
}

char MyString::operator[](int index) const
{
    return str[index];
}

void MyString::operator()() const
{
    cout << str << endl;
}

MyString MyString::operator+(char c) 
{
    char* newStr = new char[length + 2];
    strcpy_s(newStr, length + 1, str);
    newStr[length] = c;
    newStr[length + 1] = '\0';
    MyString temp(newStr);
    delete[] newStr;
    return temp;
}

MyString MyString::operator+(int num)
{
    if (num <= 0) return *this;
    char* newStr = new char[length + num + 1];
    strcpy_s(newStr, length + 1, str);
    for (int i = 0; i < num; ++i) 
    {
        newStr[length + i] = ' ';
    }
    newStr[length + num] = '\0';
    MyString temp(newStr);
    delete[] newStr;
    return temp;
}

MyString::~MyString() 
{
    delete[] str;
    length = 0;
    count--;
}

MyString::MyString(const char* chars) 
{
    length = chars.size();
    str = new char[length + 1];
    int i = 0;
    for (auto ch : chars) 
    {
        str[i++] = ch;
    }
    str[length] = '\0';
    count++;
}

MyString::MyString(MyString&& obj) 
{
    str = obj.str;
    length = obj.length;
    obj.str = nullptr;
    obj.length = 0;
    cout << "Move constructor called" << endl;
}

MyString& MyString::operator=(MyString&& obj) 
{
    if (this != &obj) 
    {
        if (str != nullptr) 
        {
            delete[] str;
        }
        str = obj.str;
        length = obj.length;
        obj.str = nullptr;
        obj.length = 0;
    }
    cout << "Move assignment operator called" << endl;
    return *this;
}
