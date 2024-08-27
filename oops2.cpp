#include<iostream>
#include<string.h>
using namespace std;
int main()




{
    int i,j,s,k,flag=0;
    char c[4][4],str[20];
    cout<<"Enter characters"<<endl;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cin>>c[i][j];
        }
    }
     for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            cout<<c[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"Enter a string"<<endl;
    cin>>str;
    s=strlen(str);
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            for(k=0;k<s;k++)
            {
                if(c[i][j]==str[k])
                {
                    cout<<str[k]<<" found at "<<i<<","<<j<<endl;
                    flag++;
                }
            }
        }
    }
    if(flag==s)
        cout<<"TRUE"<<endl;
    else
        cout<<"FALSE"<<endl;
    return 0;
}

