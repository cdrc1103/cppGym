#include <iostream>
#include <vector>
using namespace std;

bool palindrome(vector<int> & vecref, int s, int e)
{
    // if vector consists of only one element, it is a palindrome
    if(s == e){
        return true;
    }
    // if the fist element of the vector is unequal to the last element
    // of the vector it is not a palindrome
    if(vecref[s] != vecref[e]){
        return false;
    }
    // the start index s will be incremented each recursion
    // the end index e will be decremented each recursion
    // they meet in the center
    // thus, it only makes sense to check for palindrome if the checked sequence
    // has at least a lenght of three values
    if(s<e+1){
        return palindrome(vecref, s+1, e-1);
    }

    // if the recursion finishes it is a palindrome of length > 1
    return true;
}

int main()
{
    int value;
    vector<int> value_vec;
    // index of first element in vector
    int s = 0;
    // index of last element in vector
    // will be incremented each iteration
    int e = -1;
    // read values from cin and save them to a vector
    while(cin >> value){
        value_vec.push_back(value);
        e++;
    }

    // conditions for output
    if(palindrome(value_vec, s, e)){
        cout << "yes" << endl;
    }
    else{
        cout << "no" << endl;
    }
    return 0;
}