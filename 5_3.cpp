#include<iostream>
using namespace std;
class alpha{
    int x;
    public:alpha(int p){
        x=p;
        cout<<"alpha initialised\n";
    }
    void show1(){
        cout<<"x= "<<x;
    }
};

class beta{
    float y;
    public:beta(float q){
        y=q;
        cout<<"beta initialised\n";
    }
    void show2(){
        cout<<"y= "<<y;
    }
};

class gamma:public beta,public alpha{
    int m,n;
    public:gamma(int a,float b,int c,int d):alpha(a),beta(b)
    {
        m=c;
        n=d;
        cout<<"gamma initialised\n";
    }
    void show3(){
        cout<<"m= "<<m;
        cout<<"n= "<<n;
    }
};
int main(){
    gamma g(5,10.5,21,22);
    g.show1();
    g.show2();
    g.show3();
    return 0;
}