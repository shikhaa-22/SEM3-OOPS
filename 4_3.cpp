#include<iostream>
using namespace std;
class test{
    int a;
    public:
    test(){
        a=0;
    }
    friend void operator >> (istream &c1,test &t11){
        c1>>t11.a;
    }
    friend void operator << (ostream &c2,test &t11){
        c2<<t11.a;
    }
};
int main(){
    test t;
    cout<<"Enter a number"<<endl;
    cin>>t;
    cout<<"The number entered was \n";
    cout<<t;
    return 0;
}
