#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

set <int, greater <int> > s1;
enum StringValue{add, del, qry, quit};
map <string, StringValue> mapStringValues;

void init_strings();
void add_com(int i);
void del_com(int i);
void qry_com(int i);

int main()
{   
    init_strings();
    string command;
    int i;
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

void add_com(int i)
{
    s1.insert(i);
}

void del_com(int i)
{
    s1.erase(i);
}

void qry_com(int i)
{   
    if(s1.count(i)){
        cout << "T";
    }
    else{
        cout << "F";
    }
}