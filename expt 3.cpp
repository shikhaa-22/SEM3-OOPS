#include<iostream>
using namespace std;
class assign
{
    int a,b;
    public:
    assign(int x,int y)
    {
        a=x;
        b=y;
    }
    assign(assign &t)
    {
        a=t.a;
        b=t.b;
    }

    void display(int i)
    {
        cout<<"Data of object "<<i<<" is :\n";
        cout<<a<<"\n"<<b<<"\n";
    }
    ~assign()
    {
        cout<<"Object Destroyed\n";
    }
};
int main()
{
    int i=1;
    assign a1(15,20);
    assign a2(a1);
    a1.display(i);
    i++;
    a2.display(i);
    return 0;

}
