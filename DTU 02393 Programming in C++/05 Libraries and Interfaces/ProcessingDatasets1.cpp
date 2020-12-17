#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> a_dataset;
vector<int> b_dataset;


int main()
{
    char dataset_id;
    int value;

    // while there is an input from cin
    string input;
    getline(cin, input);
    char substr;

    for(int i=0; i<input.length(); ++i)
    {
        substr = input[i];

        if(isalpha(substr))
        {
            dataset_id = substr;
        }
        else if(isdigit(substr))
        {
            // assign values to vectors
            value = (int) substr -48;
            if(dataset_id == 'a'){
                a_dataset.push_back(value);
            }
            else if(dataset_id == 'b'){
                b_dataset.push_back(value);
            }
        }
        
    }


    sort(a_dataset.begin(), a_dataset.end());
    sort(b_dataset.begin(), b_dataset.end());
    
    // write sorted values to cout
    for(auto i = a_dataset.begin(); i != a_dataset.end(); ++i)
    {
        /*  * is the dereference operator because i is a pointer that stores
            the memory address of the respective value in the vector.
            The dereference operator allows to access the variable that is
            pointed to directly
        */ 
        cout << *i << " ";
    }

    // measure size of dataset to know when the last space should be set
    int b_size = b_dataset.size();
    int c = 1;
    for(auto i = b_dataset.begin(); i != b_dataset.end(); ++i)
    {
        (b_size == c) ? cout << *i << endl : cout << *i << " ";
        c++;
    }

    return 0;
}