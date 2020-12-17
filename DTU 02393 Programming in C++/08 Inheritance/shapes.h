#ifndef shapes_h
#define shapes_h

class Shape
{
public:
    Shape(void){;}; 
    virtual double area(void){return 0;};
    virtual double perimeter(void){return 0;};
    virtual double height(void){return 0;};
    virtual double width(void){return 0;};
    virtual void rotate(void){;};
};


class Rectangle : public Shape
{
public:
    Rectangle(double w, double h);
    double area(void);
    double perimeter(void);
    double height(void);
    double width(void);
    void rotate(void);
protected:
    double h;
    double w;
};

class Square : public Rectangle
{
public:
    Square(double l) : Rectangle(l, l){;};
protected:
};

class Circle : public Shape
{
public:
    Circle(double r);
    double area(void);
    double perimeter(void);
    double height(void);
    double width(void);
    void rotate(void){;}; // rotation has no effect on circle
protected:
    double r;
};

#endif