# include <iostream> 
// This imports the library iostream ,
// which contains useful functions for
// reading and writing data

using namespace std; // This allows us to use some abbreviations
// For example , we can write cin instead of std :: cin
int main () // This the main entry of the program
{
string input; // We declare a string variable named " input "
cin >> input; // We read a string into variable " input "
cout << "Hello " + input + "!" << endl ; // We print the string " input " and a new line ( endl ).
return 0; // This is used to signal correct termination (0)
}