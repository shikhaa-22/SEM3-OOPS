#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;
class Course;
class Student{
    string name;
    int rank;
    public:
    void getdata(){
        cout<<"Enter name\n";
        cin>>name;
        cout<<"Enter rank\n";
        cin>>rank;
    }
    friend void showStudentCourseInfo(Student &s1,Course &c1);
};
class Course{
    string course;
    public:
    void getcourse(){
        cout<<"Enter course name\n";
        cin>>course;
    }
    friend void showStudentCourseInfo(Student &s1,Course &c1);
};
void showStudentCourseInfo(Student &s1,Course &c1){
    cout<<left<<setw(15)<<s1.name<<setw(15)<<s1.rank<<setw(15)<<c1.course<<"\n";
}
int main()
{
    int n;
    cout<<"Enter the number of students\n";
    cin>>n;
    Student s[n];
    Course c[n];
    for(int i=0;i<n;i++){
        s[i].getdata();
        c[i].getcourse();
    }
    cout<<setw(15)<<"NAME"<<setw(15)<<"RANK"<<setw(15)<<"COURSE\n";
    for(int j=0;j<n;j++){
        showStudentCourseInfo(s[j],c[j]);
    }
}
