#include <iostream>
#include <string>
#include <vector>
#include "utility_functions.h"

using namespace std;


class Fraction {
private:
    // Internal representation of a fraction as two integers
    int numerator;
    int denominator;
    //vector<vector <int>> n_exps;
    //vector<vector <int>> d_exps;

public:
    // Class constructor
    Fraction(int n, int d)
    {
        numerator = n;
        denominator = d;
    }

    // Methods to update the fraction
    void add(Fraction f);
    void mult(Fraction f);
    void div(Fraction f);
    // Display method
    void display(void);
};

void Fraction::add(Fraction f)
{
    numerator = numerator * f.denominator + f.numerator * denominator;
    denominator = denominator * f.denominator;
}

void Fraction::mult(Fraction f)
{
    numerator = numerator * f.numerator;
    denominator = denominator * f.denominator;
}

void Fraction::div(Fraction f) 
{
    numerator = numerator * f.denominator;
    denominator = denominator * f.numerator;
}

void Fraction::display()
{
    // Shorten fraction by dividing by the greatest common divisor
    int gcd = gcd_util(numerator, denominator);
    // If gcd is not 1 then do division
    if (gcd != 1) {
        numerator = numerator / gcd;
        denominator = denominator / gcd;
    }
    cout << numerator << " / " << denominator << endl;
}   

int main() 
{
    string operation;
    char frac;
    int a; int b; int c; int d;

    // while there is input from cin --> break if EOF character
    while(cin >> a >> frac >> b >> operation >> c >> frac >> d)
    {

        Fraction fraction1(a, b);
        Fraction fraction2(c, d);

        if (operation.compare("+") == 0) {
            fraction1.add(fraction2);
        }
        else if (operation.compare("*") == 0) {
            fraction1.mult(fraction2);
        }
        else if (operation.compare("div") == 0) {
            fraction1.div(fraction2);
        }

        fraction1.display();
    }

    return 0;
}