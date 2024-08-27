#include<iostream>
using namespace std;
class nodeclass{
public:
    int a[100];
    int info;
    nodeclass(){
        for(int i=0;i<100;i++)
            a[i]=0;
    }
    void* operator new(size_t n){
        nodeclass node[n];
    }
    void operator delete(void* s){
        free(s);
    }
    void operator +(int p){
        info=p;
    }
    void operator -(int q){
        nodeclass *node;
            if(node->info==q)
                delete node;

    }
    /*int operator[](int h){
        return a[h];
    }*/
};
int main(){
    int n;
    //nodeclass *node;
    cout<<"Enter number of objects\n";
    cin>>n;
    nodeclass* node=new node[n];
    for(int j=0;j<n;j++)
        node[j].info=j++;
    for(int i=0;i<n;i++){
    node=node+2;
    node=node-3;
    }
}
