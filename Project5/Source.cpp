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
    MyString str1("I love world");
    MyString str2("I love you");

    MyString str3 = str1;

    MyString str4;
    str4.Input();

    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    cout << "str3: " << str3 << endl;
    cout << "str4: " << str4 << endl;

    MyString str7 = str6 + '!';
    cout << "str7 (str6 + '!'): " << str7 << endl;

    MyString str8 = 'A' + str6;
    cout << "str8 ('A' + str6): " << str8 << endl;

    MyString str9 = str6 + 10;
    cout << "str9 (str6 + 10): " << str9 << endl;

    MyString str10 = 10 + str6;
    cout << "str10 (10 + str6): " << str10 << endl;

    MyString obj{'H', 'e', 'l', 'l', 'o'};
    obj.Output(); 
    
    MyString obj2 = move(obj);
    obj2.Output(); 
    
    MyString obj3;
    obj3 = move(obj2);
    obj3.Output();
    
    return 0;
}
