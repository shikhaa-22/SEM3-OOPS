#include<iostream>
using namespace std;
class child{
    string ch;
    public:void setchildname(string c)
    {
        ch=c;
    }
   void show3(){
    cout<<"child name = "<<ch<<endl;
   }
};
class father:public child{
    string dad;
    public:void setname_dad(string p){
        dad=p;      
    }
    void show1(){
        cout<<"dads name = "<<dad<<endl;
    }
 };

class mother:public child{
    string mom;
    public:void setname_mom(string m){
        mom=m;
    }
    void show2(){
        cout<<"moms name = "<<mom<<endl;
    }
};


int main()
{
    mother m;
    father f;
    m.setname_mom("gauri");
    m.show2();
    f.setname_dad("abhay");
    f.show1();
    f.show3();
    m.show3();
    
    return 0;
}
