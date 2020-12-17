#include <iostream>
using namespace std;

int fibonacci(int counter)
{
    if(counter == 0 || counter == 1){
        return 1;
    }
    else{
        return fibonacci(counter-1) + fibonacci(counter-2);
    }
}

int main()
{
    int counter;
    while(cin >> counter)
    {
        int value = fibonacci(counter);
        cout << value << " ";
    }
    return 0;
}