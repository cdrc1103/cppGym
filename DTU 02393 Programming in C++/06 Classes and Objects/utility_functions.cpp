#include <map>
#include <math.h>

using namespace std;

// Counts the unique primefactors of an integer
void primefactor_util(int n, map<int, int> &primefactors)
{   
    int exponent;
    int primenumber;

    // Get all primefactors that are 2
    // start number of exponents is alway zero
    primenumber = 2;
    exponent = 0;
    while(n % 2 == 0){
        exponent++;
        n = n / 2;
    }
    primefactors.insert(pair<int, int>(primenumber, exponent));

    // Get all primefactors greater than 2
    // must be odd because else it would be a multiple of 2 therefore i+2
    // checking half of n is enough because symmetry, float numbers are casted to int
    for(int i=3; i<=sqrt(n); i=i+2)
    {
        // while i divides n, print i and divide n
        primenumber = i;
        exponent = 0;
        while(n % i == 0){
            exponent++;
            n = n / i;
        }
        primefactors.insert(pair<int, int>(primenumber, exponent));
    }

    // Get all primefactors greater than 2 but smaller than n/2
    if(n > 2){
        primenumber = n;
        exponent = 1;
        primefactors.insert(pair<int, int>(primenumber, exponent));
    }

}

// Function that finds the greatest common divisor of two integers
int gcd_util(int a, int b)
{
    if(a == 0){
        return b;
    }

    return gcd_util(b%a, a);
}