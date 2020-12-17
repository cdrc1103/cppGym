#include <iostream>
#include <math.h>
using namespace std;


void histogram(int l, int n, int arr[])
{
    int max = 0;
    for(int i=0; i<n; i++)
    {
        if(arr[i] > max){
            max = arr[i];
        }
    }

    int k = ceil(max / l);
    int lb = 0;
    int ub = k;

    for(int i=1; i<=l; i++)
    {   
        int c = 0;
        for(int j=0; j<n; j++)
        {
            if(lb <= arr[j] && arr[j] <= ub){
                c++;
            }
        }

        cout << lb << ": " << c << endl;

        lb = ub + 1;
        ub = lb + k;
    }
}

int main()
{   
    int l;
    int n;
    cin >> l;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    histogram(l, n, arr);

    return 0;
}