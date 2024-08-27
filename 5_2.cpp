#include<iostream>
using namespace std;
class student{
    protected:int roll;
    public:void setroll(int p){
        roll=p;
    }
};
class test:virtual public student{
    protected:int sub1,sub2;
    public:void setsub(int q,int r){
        sub1=q;
        sub2=r;
    }
};
class sport:virtual public student{
    protected:int spt;
    public:void setsport(int s){
        spt=s;
    }
};
class res:public test,public sport{
    private:int total;
    public:void compute(){
        total=sub1+sub2+spt;
    }
    void display(){
        cout<<roll<<"\t"<<sub1<<"\t"<<sub2<<"\t"<<spt<<"\t"<<total;
    }
};
int main(){
    res r;
    r.setroll(222);
    r.setsub(99,98);
    r.setsport(95);
    r.compute();
    r.display();
}