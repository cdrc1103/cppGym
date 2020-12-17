#include <iostream>
using namespace std;

int another_sum(int n)
{
    int sum = 0;
    for(int i=0; i<=n; i++)
    {
        if(i % 2 == 0){
            sum = sum + i;
        }
    }
    return sum;
}

int main()
{
    int n=0;

    cin >> n;
    cout << another_sum(n) << endl;

    return 0; 
}