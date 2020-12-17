#include <iostream>
using namespace std;

int gaussian_sum(int n)
{
    int sum = 0;
    for(int i=1; i<=n; i++)
    {
        sum = sum + i;
    }

    return sum;
}

int main()
{
    int n=0;

    cin >> n;

    cout << gaussian_sum(n);

    return 0;
}