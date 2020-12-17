#include "utility_functions.h"
#include <iostream>
#include <map>
#include <iterator>

using namespace std;

void primefactor_util(int, map <int,int>&);
int gcd_util(int a, int b);

int main()
{
    int n;
    cin >> n;
    map <int,int> prim;
    primefactor_util(n, prim);

    map<int, int>:: iterator itr;
    for (itr=prim.begin(); itr!=prim.end(); ++itr)
    {
        cout << itr->first << ":" << itr->second << endl;
    }
    return 0;
}