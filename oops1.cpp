#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int a[20],i,n,d,maxm,minm;
    cout<<"Enter number of elements in array"<<endl;
    cin>>n;
    a[n];
    cout<<"Enter elements"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    maxm=a[0];
    minm=a[0];
    for(i=0;i<n;i++)
    {
        if(maxm<a[i])
            maxm=a[i];
        if(a[i]<minm)
            minm=a[i];
    }
    cout<<"Highest element :"<<maxm<<endl;
    cout<<"Lowest element :"<<minm<<endl;
    d=maxm-minm;
    cout<<"Difference between highest and lowest element is :"<<d<<endl;
    return 0;
}
