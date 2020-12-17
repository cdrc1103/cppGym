# include <iostream> 
// This imports the library iostream ,
// which contains useful functions for
// reading and writing data

using namespace std; // This allows us to use some abbreviations
// For example , we can write cin instead of std :: cin
int main () // This the main entry of the program
{
int x; // We declare a string variable named " input "
int y;
cin >> x; // We read a string into variable " input "
cin >> y;
if (x==y)
{
    cout << x << " is equal to " << y << endl;
}
else if (x > y)
{
    cout << x << " is bigger than " << y << endl;
}
else
{
    cout << x << " is smaller than " << y << endl;
}

return 0;
}