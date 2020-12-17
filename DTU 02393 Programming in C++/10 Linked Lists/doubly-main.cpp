# include "doubly-linked.h"

using namespace std;

int main()
{
    List a;

    int i = 1;
    while(i<10){
            a.insert(i);
            i++;
    }
    a.print();
    a.reverse();
    a.print();

    a.~List();

    return 0;
}