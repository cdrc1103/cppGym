#include <math.h>
#include "shapes.h"
using namespace std;

Rectangle :: Rectangle(double h, double w)
{
    this->w = w;
    this->h = h;
}

double Rectangle :: area(void)
{
    return h * w;
}

double Rectangle :: perimeter(void)
{
    return 2*h + 2*w;
}

double Rectangle :: height(void)
{
    return h;
}

double Rectangle :: width(void)
{
    return w;
}

void Rectangle :: rotate(void)
{
    double temp_w = w;
    w = h;
    h = temp_w;
}

Circle::Circle(double r){
    this->r = r;
}

double Circle::area(void)
{
    return M_PI * pow(r, 2);
}

double Circle::perimeter(void)
{
    return 2 * M_PI * r;
}

double Circle::height(void)
{
    return r*2;
}

double Circle::width(void)
{
    return r*2;
}


