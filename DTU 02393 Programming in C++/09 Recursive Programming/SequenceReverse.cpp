#include <iostream>
using namespace std;

void reverse()
{
    int value;
    if(cin >> value){
        reverse();
        cout << value << " ";
    }
}

int main()
{
    reverse();
    return 0;
}