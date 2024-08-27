#include<iostream>
#include<string>
using namespace std;
class String{
    string str;
    int len;
    public:
        String(){
            str="";
        }
        friend istream &operator>>(istream &in,String &s){
            cout<<"Enter a string: ";
            in>>s.str;
            s.len=s.str.length();
            return in;
        }
        friend ostream &operator<<(ostream &out,String &s){
            out<<"The string is: ";
            out<<s.str;
            out<<"\nThe length of the string is: ";
            out<<s.len<<endl;
            return out;
        }
        String operator+(String &s){
            String temp;
            temp.str=str+ " " +s.str;
            cout<<"The string is: "<<temp.str;
            return temp;
        }
        friend void compare(String &s2,String &s3){
            if(s2.len>s3.len)
                cout<<"\nLength of "<<s2.str<<" > "<<"Length of "<<s3.str;
            else if(s2.len<s3.len)
                cout<<"\nLength of "<<s3.str<<" > "<<"Length of "<<s2.str;
            else
                cout<<"\nLength of "<<s3.str<<" = "<<"Length of "<<s2.str;

        }
};
int main(){
    String s1,s2,s3;
    cin>>s2;
    cin>>s3;
    cout<<s2;
    cout<<s3;
    s1=s2+s3;
    compare(s2,s3);
}