#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
class employee
{
public:
    string name;
    int cursalary;
    int newsalary;
    char status[10];
    void input()
    {
        cout<<"Enter name"<<endl;
        cin>>name;
        cout<<"Enter current salary"<<endl;
        cin>>cursalary;
    }
    void increase()
    {
        int x;
        cout<<"Enter incremented amount"<<endl;
        cin>>x;
        newsalary=x+cursalary;
    }
    void decrease()
    {
        int y;
        cout<<"Enter decremented amount"<<endl;
        cin>>y;
        newsalary=cursalary-y;
    }
    void statuss()
    {
        if(newsalary>=50000)
            strcpy(status,"promoted");
        else
            strcpy(status,"demoted");

    }
    void display()
    {
        int n=48;
        cout<<setw(15)<<left<<name;
        cout<<setw(5)<<left<<n;
        n++;
        cout<<setw(15)<<left<<cursalary;
        cout<<setw(15)<<left<<newsalary;
        cout<<setw(15)<<left<<status <<"\n";
    }
};

int main()
{
    employee e[10];
    int i, n,c;
    cout<<"Enter number of employees"<<endl;
    cin>>n;
    e[n];
    for (int i=0; i<n; i++)
    {
        e[i].input();
        cout<<"Do you want to 1.increment or 2.decrement the salary\n";
        cin>>c;
        if(c==1)
            e[i].increase();
        else
            e[i].decrease();
        e[i].statuss();
    }
    cout<<setw(15)<<left<<"NAME"<<setw(5)<<left<<"ID"<<setw(15)<<left<<"CURRENT SALARY"<<setw(15)<<left<<"NEW SALARY"<<setw(15)<<left<<"STATUS"<<endl;
    for(int i=0; i<n; i++)
    {
        e[i].display();
    }
    return 0;
}
