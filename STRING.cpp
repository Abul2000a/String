#include "STRING.hpp"
using std::cout;
using std::cin;

int main()
{
String str("Hello");
String str2("World");
char c = 'a';
String result("He;;");
result += c;
String result_1("Hi");
result_1+=str;
result_1.Print();
result.Print();
str.substr(0,2);
str2.pop_back();
str2.push_front('a');
str2.Print();
str.Print();
String s3;
cin >> s3;
cout << s3;
String s4 = s3+str;
cout << s4;
cout << endl << endl;
return 0;
}