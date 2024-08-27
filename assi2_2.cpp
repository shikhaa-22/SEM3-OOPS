#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
class cric{
    int run,inns,no;
    float avg;
    string name;
    public:
    void input()
    {
        cout<<"Enter name\n";
        cin>>name;
        cout<<"Enter number of runs\n";
        cin>>run;
        cout<<"Enter number of innings\n";
        cin>>inns;
        cout<<"Enter number of times not out\n";
        cin>>no;
        if(no>inns){
            cout<<"Re-Enter number of times not out\n";
            cin>>no;
        }
        avg=(float)run/(inns-no);
    }
    void display()
    {
        cout<<"\n"<<setw(15)<<left<<name<<setw(15)<<left<<run<<setw(10)<<left<<inns<<setw(20)<<left<<no<<setw(10)<<left<<avg;
        
    }
};
int  main()
{
    int n;
    cout<<"Enter number of cricketers\n";
    cin>>n;
    cric c[n];
    for(int i=0;i<n;i++){
        c[i].input();
    }
    cout<<endl;
    cout<<setw(15)<<left<<"NAME"<<setw(15)<<"RUNS"<<setw(10)<<"INNINGS"<<setw(20)<<"TIMES NOT OUT"<<setw(10)<<"AVERAGE";
    for(int j=0;j<n;j++)
    {
        c[j].display();
    }   
    return 0; 
}