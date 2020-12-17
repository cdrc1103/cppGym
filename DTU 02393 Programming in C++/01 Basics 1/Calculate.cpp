# include <iostream> 
// This imports the library iostream ,
// which contains useful functions for
// reading and writing data

using namespace std; // This allows us to use some abbreviations
// For example , we can write cin instead of std :: cin
int main () // This the main entry of the program
{
float x; // We declare a string variable named " input "
float y;
float z;
cin >> x; // We read a string into variable " input "
cin >> y;
cin >> z;
float result = (x + y) -z;
cout << result << endl;
return 0;
}