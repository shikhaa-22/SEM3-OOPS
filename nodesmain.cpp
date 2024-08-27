#include<iostream>
using namespace std;
class Node{
    int data;
    Node *next;
    public:
        Node(int v){
            data=v;
            next=NULL;
        }
        void *operator new(size_t size){
            void *node=::operator new(size);
            return node;
        }
        void operator delete(void *node){
            ::operator delete(node);
        }
        friend class linkedList;
};
class linkedList{
    public:
        Node *head;
        linkedList(){
            head=NULL;
        }
        linkedList &operator +(int val){
            Node *temp=new Node(val);
            temp->data=val;
            temp->next=NULL;
            if(head==NULL){
                head=temp;
                return *this;
            }
            Node *p=head;
            while(p->next!=NULL)
                p=p->next;
            p->next=temp;
            return *this;
        }   
        linkedList &operator -(int val){
            Node *temp=head;
            if(head==NULL)
                return *this;
            if(head->data==val){
                head=head->next;
                delete head;
                return *this;
            }
            while(temp->next && temp->next->data!=val)
                temp=temp->next;
            if(temp->next){
                Node *d=temp->next;
                temp->next=temp->next->next;
                delete d;
            }
            return *this;
        }  
        void display(){
            Node *temp=head;
            while(temp){
                cout<<temp->data<<"\t";
                temp=temp->next;
            }
        }
};
int main(){
    linkedList l;
    l=l+1;
    l=l+2;
    l=l+3;
    l.display();
    printf("\n");
    l=l-3;
    l.display();
}