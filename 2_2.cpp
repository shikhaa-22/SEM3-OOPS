#include <iostream>
using namespace std;

class larger
{
private:
    int a, b,c,l,s;

public:
    cout << "Enter 2 numbers\n";
    cin >> a >> b;
    l = friend int larger(a, b);
    cout << "Largest number is\n"<< l;
    cout<<"Enter a number\n";
    cin>>c;
    s=inline int square(c){
          return c*c;
}

   
};

  

int larger(int a,int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    larger d;
    return 0;
}
