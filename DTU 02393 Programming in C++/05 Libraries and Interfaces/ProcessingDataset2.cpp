#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void sort_data(vector<int>&, vector<int>&, vector<int>&);

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

    sort_data(a_dataset, b_dataset, out_dataset);

    // measure size of dataset to know when the last space should be set
    int out_size = out_dataset.size();
    for(int i = 0; i<out_size; ++i)
    {
        (out_size == i+1) ? cout << out_dataset[i] << endl : cout << out_dataset[i] << " ";
    }

    return 0;
}

void sort_data(vector<int>& a_dataset, vector<int>&  b_dataset, vector<int>&  out_dataset)
{
    int a_size = a_dataset.size();
    int b_size = b_dataset.size();
    int max_size = max(a_size, b_size);
    
    for(int i=0; i<max_size; ++i)
    {
        if(i < a_size){
            out_dataset.push_back(a_dataset[i]);
        }
        if(i < b_size){
            out_dataset.push_back(b_dataset[i]);
        }
    }
}