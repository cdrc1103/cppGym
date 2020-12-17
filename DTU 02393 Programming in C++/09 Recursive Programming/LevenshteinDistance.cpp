#include <iostream>
#include <string>
using namespace std;

int levenshtein(string & u, string & v)
{   
    int f;
    if(u[0] == v[0]){
        f = 0;
    }else{f = 1;}
    // cout << 'f' << f << endl;
    
    if(u.size()==0){
        return v.size();
    }
    else if (v.size()==0)
    {
        return u.size();
    }
    else{
        string u_red = u;
        u_red.erase(u_red.begin());
        string v_red = v;
        v_red.erase(v_red.begin());
        
        int a = levenshtein(u_red, v) + 1;
        int b = levenshtein(u, v_red) + 1;
        int c = levenshtein(u_red, v_red) + f;
        // cout << "a:" << a << " b:" << b << " c:" << c << endl;

        return min(min(a, b), c);
    }
}

int main()
{
    string u;
    string v;
    cin >> u >> v;

    cout << levenshtein(u, v) << endl;
    return 0;
}