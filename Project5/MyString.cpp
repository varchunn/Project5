#include <iostream>   
#include "MyString.h" 
using namespace std;

int MyString::GetCount()//ñòàòè÷íà ïàì'ÿòü
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
    length = strlen(string + 1);
    count++;
}
MyString::MyString(const MyString& string)//êîíñòðóêòîð êîï³þâàííÿ
{
    str = new char[strlen(string.str) + 1];
    strcpy_s(str, strlen(string.str) + 1, string.str);
    length = strlen(string.str + 1);
}
MyString::MyString(MyString&& obj)
{
    str = obj.str;
    length = obj.length;
    obj.str = nullptr;
    obj.length = 0;

    cout << "Move constr" << endl;
}

MyString::MyString(initializer_list<char> arr)
{
    cout << "initializer list" << endl;
    cout << arr.size() << endl;
    length = arr.size();
    str = new char[length + 1];
    for (auto x = arr.begin(); x != arr.end(); x++)
    {
        *str = *x;
        str++;
    }
    str -= length;
}

void MyString::Input()
{
    char string[225];
    cout << "Enter text: ";
    cin.getline(string, 225);
    str = new char[strlen(string) + 1];
    strcpy_s(str, strlen(string) + 1, string);
}
void MyString::Output()
{
    cout << str;
}

void MyString::MyStrcpy(MyString& obj)//êîïèðîâàíèå ñòðîê   
{
    str = new char[strlen(obj.str) + 1];
    strcpy_s(str, strlen(obj.str) + 1, obj.str);
    length = obj.length;
}
bool MyString::MyStrStr(const char* string)//ïîèñê ïîäñòðîêè â ñòðîêå   
{
    for (int i = 0; i < strlen(string); i++)
    {
        for (int j = 0; j < strlen(str); j++)
        {
            if (string[i] == str[j])
            {
                return true;
                cout << "Found!";
                break;
            }
            else
            {
                return false;
                cout << "Not found";
            }

        }
    }
}
int MyString::MyChr(char c)//ïîèñê ñèìâîëà â ñòðîêå(èíäåêñ íàéäåííîãî ñèìâîëà, ëèáî -1)   
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == c)
        {
            return i + 1;
        }
    }
}
int MyString::MyStrLen()//âîçâðàùàåò äëèíó ñòðîêè   
{
    return strlen(str);
}
void MyString::MyStrCat(MyString& obj)//îáúåäèíåíèå ñòðîê   
{
    str = new char[strlen(str) + strlen(obj.str) + 1];
    strcpy_s(str, strlen(obj.str) + 1, obj.str);
    for (int i = 0; i < strlen(obj.str); i++)
    {
        str[i] = obj.str[i];
    }
    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = obj.str[i];
    }
    str[strlen(obj.str) + strlen(str)] = '\0';
}
void MyString::MyDelChr(char c)// óäàëÿåò óêàçàííûé ñèìâîë    
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
int MyString::MyStrCmp(MyString& obj)/*ñðàâíåíèå ñòðîê
- 1 – ïåðâàÿ ñòðîêà ìåíüøå ÷åì âòîðàÿ
1 – ïåðâàÿ áîëüøå ÷åì âòîðàÿ
0 – ñòðîêè ðàâíû!*/
{
    if (strlen(str) == strlen(obj.str))
    {
        return 0;
    }
    if (strlen(str) > strlen(obj.str))
    {
        return  -1;
    }
    if (strlen(str) < strlen(obj.str))
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
    if (str != nullptr)
    {
        delete[] str;
    }
    length = obj.length;

    str = new char[strlen(obj.str) + 1];
    strcpy_s(str, strlen(obj.str) + 1, obj.str);

    return*this;
}
MyString& MyString::operator=(MyString&& obj)
{
    if (str != nullptr)
    {
        delete[] str;
    }
    str = obj.str;
    length = obj.length;
    obj.str = nullptr;
    obj.length = 0;

    cout << "Move =" << endl;
    return *this;
}

MyString& MyString::operator+=(const MyString& obj)
{
    MyString temp = *this;
    int* temp1 = new int[length + obj.length];
    for (int i = 0; i < length; i++)
    {
        temp1[i] = str[i];
    }
    for (int i = length; i < length + obj.length; i++)
    {
        temp1[i] = obj.str[i];
    }
    delete[] str;
    *str = *temp1;
    length += obj.length;
    return temp;
}

char MyString::operator[](int index)
{
    return str[index];
}
void MyString::operator()()
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


MyString operator+(char c, const MyString& obj)
{
    char* newStr = new char[obj.length + 2]; 
    newStr[0] = c;                           
    strcpy_s(newStr + 1, obj.length + 1, obj.str); 
    MyString temp(newStr);
    delete[] newStr;
    return temp;
}


MyString MyString::operator+(int num) 
{
    if (num <= 0) return *this; // Нічого не додаємо, якщо число <= 0
    char* newStr = new char[length + num + 1]; 
    strcpy_s(newStr, length + 1, str);         
    for (int i = 0; i < num; ++i) {
        newStr[length + i] = ' ';              
    }
    newStr[length + num] = '\0';               
    MyString temp(newStr);
    delete[] newStr;
    return temp;
}

MyString operator+(int num, const MyString& obj)
{
    if (num <= 0) return obj; // Нічого не додаємо, якщо число <= 0
    char* newStr = new char[obj.length + num + 1]; 
    strcpy_s(newStr, obj.length + 1, obj.str);     
    for (int i = 0; i < num; ++i) {
        newStr[obj.length + i] = ' ';              
    }
    newStr[obj.length + num] = '\0';               
    MyString temp(newStr);
    delete[] newStr;
    return temp;
}
MyString::~MyString()
{
    delete[]str;
    length = 0;
    count--;
}
