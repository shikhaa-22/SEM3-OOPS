#include<iostream>
using namespace std;
class test{
    int a;
    public:
    test(int p){
        a=p;
    }
    void operator - (){
        a=-a;
    }
    void operator ++(){
        a=a+1;
    }
    void operator ++(int){
        a=a+1;
    }
    void operator --(){
        a=a-1;
    }
    void operator --(int){
        a=a-1;
    }
    void display(){
        cout<<"Result : "<<a<<endl;;
    }

};
int main(){
    test t1(1);
    t1++;
    t1.display();
    ++t1;
    t1.display();
    t1--;
    t1.display();
    --t1;
    t1.display();
    -t1;
    t1.display();
    return 0;
}
