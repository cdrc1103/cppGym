#include <iostream>
#include <math.h>
using namespace std;

double pi(int n)
{
    double sum = 0;

    for(int i=0; i<n; i++)
    {
        double r = pow(-1, i) / (2*i+1);
        sum = sum + r;
    }

    sum = sum*4;
    return sum;
}

int main()
{
    int n=0;
    cin >> n;
    cout << (double)pi(n) << endl;

    return 0;
}