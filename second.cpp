#include<iostream>
#include<string.h>
using namespace std;
class String{
    string str;
    public:
    String()
    {
        str="";
    }
    String(string x)
    {
        str=x+" ";
    }
    friend String join(String &s1,String &s2)
    {
        String s3;
        s3=s1+s2;
        return s3;
    }
    friend String operator +(String &s1,String &s2)
    {
        String s6;
        s6=s1.str+s2.str;
        return s6;
    }
    void display()
    {
        cout<<"String is "<<str<<endl;
    }
    ~String()
    {
        cout<<"Object Deleted\n";
    }
};
int main(){
    string str1,str2;
    cout<<"Enter string 1\n";
    cin>>str1;
    cout<<"Enter string 2\n";
    cin>>str2;
    String s1(str1),s2(str2);
    s1.display();
    s2.display();
    String s4;
    s4=join(s1,s2);
    s4.display();
    return 0;
}
