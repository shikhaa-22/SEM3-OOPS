#include<iostream.>
using namespace std;
class nodeclass{
public:
    int info;
    class nodeclass *link;
    nodeclass(){
        link=NULL;
    }
    void disp(){
        cout<<"\t"<<info;
    }
    friend void* operator new(size_t n,){
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
};
int main(){
    int n;
    //nodeclass *node;
    cout<<"Enter number of objects\n";
    cin>>n;
    nodeclass* node=new nodeclass[n];
    for(int j=0;j<n;j++)
        node[j].info=j+2;
    for(int i=0;i<n;i++){
    node=node+2;
    node=node-3;
    }
    for(int i=0;i<n;i++){
        node[i].disp();
    }
}
