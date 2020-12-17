#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int sort_data(vector<int>&, vector<int>&);

int main()
{
    vector<int> a_dataset;
    vector<int> b_dataset;
    vector<int> out_dataset;
    char dataset_id;
    int value;

    // while there is an input from cin
    while(cin >> dataset_id >> value)
    {
        if(dataset_id == 'a'){
            a_dataset.push_back(value);
        }
        else if(dataset_id == 'b'){
            b_dataset.push_back(value);
        }        
    }

    int c = sort_data(a_dataset, b_dataset);

    cout << c << endl;

    return 0;
}

int sort_data(vector<int>& a_dataset, vector<int>&  b_dataset)
{
    int a_size = a_dataset.size();
    int b_size = b_dataset.size();
    int max_size = max(a_size, b_size);
    int a = 0;
    int b = 0;
    int c = 0;
    for(int i=0; i<max_size; ++i)
    {
        if(i < a_size){
            a = a_dataset[i];
        }
        else{a = 0;}
        if(i < b_size){
            b = b_dataset[i];
        }
        else{b = 0;}
        c += a * b;
    }

    return c;
}