#include<iostream>
using namespace std;
class operations
{
    int a,b;
public:
    void input()
    {
        cout<<"Enter two numbers"<<endl;
        cin>>a>>b;
    }
    inline int sum()
    {
        return a+b;
    }
    friend int prod(operations o)
    {
        return o.a*o.b;
    }
};
int main()
{
    operations o;;
    o.input();
    cout<<"The sum is :"<<o.sum()<<endl;
    cout<<"The product is :"<<prod(o)<<endl;
}
