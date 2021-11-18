#include <iostream>
class String
{
private:
    char *str;
    int length;
public:
    String();
    String(unsigned int,char);
    String(const char *str);
    String(const String &other);
    String(String &&other);
    ~String();
    char& at (const unsigned int index);
    const char& at (const unsigned int index)const;
    String& operator +=(String& other); 
    String& operator +=(char other);   
    String& operator =(const String &other);
    String operator+(const String &other);
    bool operator >(const String & other); 
    bool operator <(const String & other);  
    bool operator <=(const String & other); 
    bool operator >=(const String & other); 
    bool operator ==(const String & other);
    bool operator !=(const String & other);
    char& operator [](unsigned int index);
    void push_back(char simbol); 
    void pop_back(); 
    void push_front(char simbol); 
    void pop_front(); 
    void resize(const int count); 
    void clear();  
    bool empty();  
    void substr(int,int); 
    void Print();  
    friend std::ostream& operator <<(std::ostream&, String&);
    friend std::istream& operator >>(std::istream&, String&);
};