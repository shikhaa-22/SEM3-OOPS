//write cpp program to enter a number and to check if that number is even or odd.check if it is prime or not.
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int n;
    int flag=0;
    cout<<"Enter a number"<<endl;
    cin>>n;
    if(n==0||n==1)
    cout<<n<<" is neither prime nor composite"<<endl;
    else if(n%2==0)
    {
        if(n==2)
        cout<<n<<" is even and prime"<<endl;
        else
        cout<<n<<" is even and composite"<<endl;
    }
    else{
        for(int i=1;i<=n;i++)
        {
            if(n%i==0)
            flag++;
        }
        if(flag==2)
        cout<<n<<" is odd and prime"<<endl;
        else
        cout<<n<<" is odd and composite"<<endl;
    }
return 0;

}