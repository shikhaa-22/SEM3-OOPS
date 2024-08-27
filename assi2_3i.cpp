#include <iostream>
#include <cmath>
using namespace std;
double solution(double x, double accuracy) {
    //double term = x;
    double sum = 0;
    int n = 1;
    while (fabs(x) >= accuracy * fabs(sum) ) {
        x = pow(1/n,n);
        sum += x;
        n++;
    }
    return sum;
}
int main() {
    double x;
    cout << "Enter the number of terms ";
    cin >> x;
    double accuracy= 0.0001 / 100.0;

    double value = solution(x, accuracy);

    cout << "SUM of series is = " << value <<endl;
   
    return 0;
}
