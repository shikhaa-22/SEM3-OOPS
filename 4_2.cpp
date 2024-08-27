#include<iostream>
using namespace std;
class calc{
    int a;
    public:
    calc(){
        a=0;
    }
    calc(int y){
        a=y;
    }
    friend calc operator +(int q,calc & c22){
        calc c2;
        c2.a=q+c22.a;
        return c2;
    }
    calc operator -(int r){
        calc c3;
        c3.a=a-r;
        return c3;
    }
    calc operator *(calc s){
        calc c4;
        c4.a=a* s.a;
        return c4;
    }
    void display(){
        cout<<"Result is : "<<a<<endl;
    }
};
int main()
{
    calc y(10),x;
    x=5+y;
    x.display();
    x= x*y;
    x.display();
    x=y-5;
    x.display();
    return 0;
}