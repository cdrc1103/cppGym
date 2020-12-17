#include <iostream>
using namespace std;

void primefactor(int n)
{   
    // Get all primefactors that are 2
    while(n % 2 == 0){
        cout << 2;
        n = n / 2;
        if(n == 1){
            cout << endl;
        }
        else{
            cout << " * ";
        }
    }

    // Get all primefactors greater than 2
    // must be odd because else it would be a multiple of 2 therefore i+2
    // checking half of n is enough because symmetry, float numbers are casted to int
    for(int i=3; i<=n/2; i=i+2)
    {
        // while i divides n, print i and divide n
        while(n % i == 0){
            cout << i;
            n = n / i;
            if(n == 1){
            cout << endl;
            }
            else{
                cout << " * ";
            }
        }
    }

    // Get all primefactors greater than 2 but smaller than n/2
    if(n > 2){
        cout << n << endl;
    }
}

int main()
{
    int n = 0;
    cin >> n;

    primefactor(n);

    return 0;
}