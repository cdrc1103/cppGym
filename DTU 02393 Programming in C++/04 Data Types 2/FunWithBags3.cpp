#include <iostream>
#include <set>
#include <map>
#include <string>
#include <iterator>

using namespace std;

multiset <double, greater <double> > s1;
multiset<double> :: iterator itr;
enum StringValue{add, del, qry, quit};
map <string, StringValue> mapStringValues;

void init_strings();
void add_com(double i);
void del_com(double i);
void qry_com(double i);

int main()
{   
    init_strings();
    string command;
    double i;
    bool q=0;

    while(true)
    {
        cin >> command;
        
        switch(mapStringValues[command])
        {
            case add:
                cin >> i;
                add_com(i);
                break;
            case del:
                cin >> i;
                del_com(i);
                break;
            case qry:
                cin >> i;
                qry_com(i);
                break;
            case quit:
                q=1;
                break;
        } 

        if(q==1){
            break;
        }
    }

return 0;
}

void init_strings()
{
    mapStringValues["add"] = add;
    mapStringValues["del"] = del;
    mapStringValues["qry"] = qry;
    mapStringValues["quit"] = quit;
}

void add_com(double i)
{
    s1.insert(i);
}

void del_com(double i)
{
    itr = s1.find(i);
    if(itr!=s1.end()){
        s1.erase(itr);
    }
}

void qry_com(double i)
{   
    if(s1.count(i)){
        cout << "T";
    }
    else{
        cout << "F";
    }
}