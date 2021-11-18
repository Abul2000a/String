#include "STRING.h"
#include <iostream>
#include <cstring>
using namespace std;

ostream& operator <<(std::ostream& ccout, String&obj)
{
ccout<<obj.str;
return ccout;
}
istream& operator >>(std::istream&ccin, String&obj)
{
char val[20];
cout << "Enter String >> ";
ccin >> val;

obj.length = strlen(val);
obj.str = new char[obj.length+1];
strcpy(obj.str,val);
return ccin;
}
String::String(unsigned int n,char c){
        length = n;
        str = new  char[length + 1];
        for(int i = 0;i<length;i++){
            str[i]= c;
        }
        str[length]='\0';
    }
void String::Print()
{
cout << str;
}
char& String::at(const unsigned int index)
{
    return str[index];
}
const char& String::at(const unsigned int index)const
{
    return str[index];
}

void String::clear()
{
str = new char[length+1];
for(int i = 0;i < length;i++){
    str[i]='\0';
}
}
bool String::empty()
{
if(this->str[0]=='\0'){return true;}
return false;    
}

void String::substr(int x,int y){
    for(int i = x;i < y;i++){
        cout << this->str[i];
    }
}
String::String()
{
str = nullptr;
length = 0;
}

void String::push_front(char simbol)
{
char * p = new char[this->length+1];
for(int i = 0;i < this->length;i++){
    p[i] = this->str[i];
}
p[length] = '\0';
for(int i = 1;i < length;i++){
    this->str[i] = p[i];
}
this->str[0] = simbol;
this->str[length] = '\0';
delete [] p;
p = nullptr;
}
void String::pop_front()
{
    char * p = new char[length+1];
for(int i = 1;i<this->length;i++){
    p[i] = this->str[i];
}
for (int j = 1;j < length;j++){
    this->str[j] = p[j];
}
this->str[length] = '\0';
delete [] p;
p = nullptr;
}

String::String(const char *str)
{
length = strlen(str);
this->str = new char[length + 1];
for (int i = 0; i < length; i++)
{
this->str[i] = str[i];
}
this->str[length] = '\0';
}

void String::push_back(char simbol)
{
str[length]=simbol;
str[length+1] = '\0'; 
}
void String::pop_back()
{
    this->str[length-1] = '\0';
}

String::String(const String &other)
{
length = strlen(other.str);
this->str = new char[length + 1];

for (int i = 0; i < length; i++)
{
this->str[i] = other.str[i];
}

this->str[length] = '\0';
}

String& String::operator =(const String &other)
{

if (this->str != nullptr)
{
delete[] str;
}

length = strlen(other.str);
this->str = new char[length + 1];

for (int i = 0; i < length; i++)
{
this->str[i] = other.str[i];
}

this->str[length] = '\0';

return *this;

}
void String::resize(const int count)
{
    this->str = new char[count+1];
    for(int i = 0;i<count;i++){
        this->str[i] = str[i];
        this->str[count] = '\0';
    }
}
String& String::operator +=(char other)
{
str[length]=other;
str[length+1] = '\0';
return *this; 
}
String& String::operator +=(String& other)
{
strcat(this->str,other.str);
return *this;
}

String String::operator+(const String &other)
{
String newStr;
int thisLength = strlen(this->str);
int otherLength = strlen(other.str);
newStr.length = thisLength + otherLength;
newStr.str = new char[thisLength + otherLength + 1];
int i = 0;
for (; i < thisLength; i++)
{
newStr.str[i] = this->str[i];
}
for (int j = 0; j < otherLength; j++, i++)
{
newStr.str[i] = other.str[j];
}
newStr.str[thisLength + otherLength] = '\0';
return newStr;
}
String::~String()
{
delete[] this->str;
}
bool String::operator >(const String & other)
{
if(this->length > other.length){
    return true;
}    
return false;
}
bool String::operator <(const String & other)
{
if(this->length < other.length){
    return true;
}
return false;
}

bool String::operator <=(const String & other)
{
if((this->length == other.length) || (this->length < other.length)){
    return true;
}    
    return false;
}

bool String::operator >=(const String & other)
{
if((this->length == other.length) || (this->length > other.length)){
    return true;
}    
    return false;
}

bool String::operator ==(const String & other)
{
if (this->length != other.length)
{
return false;
}
for (int i = 0; i < this->length; i++)
{
if (this->str[i] != other.str[i])
{
return false;
}
}
return true;
}


char& String::operator [](unsigned int index)
{
return this->str[index];
}


bool String::operator !=(const String & other)
{
return !(this->operator==(other));
}

String::String(String &&other)
{
this->length = other.length;
this->str = other.str;
other.str = nullptr;
}
