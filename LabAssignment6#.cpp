#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class Arithmetic
{
    private:
        double n1, n2;

    public:
    double set(double n1, double n2)
    {
        this->n1 = n1;
        this->n1 = n1;
    }
    void display()
    {
        cout  << "\n First value is: " << n1;
        cout  << "\n Second value is: " << n2;
    }
    double add(double a, double b)
    {
        return (a + b);
    }

    double sub(double a, double b)
    {
        return (a - b);
    }
    double mult(double a, double b)
    {
        return (a * b);
    }
    double divd(double a, double b)
    {
        if (b == 0)
        b = 1;
        return (a / b);
    }

// friend functions declaration
    friend double avg(Arithmetic ar);
    friend double cmp1(Arithmetic ar);
    friend double cmp2(Arithmetic ar);
};

double avg(Arithmetic ar)
{
    return (ar.n1 + ar.n2)/2;
}

double cmp1(Arithmetic ar)
{
    if(ar.n1 > ar.n2)
        return ar.n1;
    else if(ar.n2 > ar.n1)
        return ar.n2;
    else if(ar.n1 == ar.n2)
        return 0;
}

double cmp2(Arithmetic ar)
{
    if(ar.n1 < ar.n2)
        return ar.n1;
    else if(ar.n2 < ar.n1)
        return ar.n2;
    else if(ar.n1 == ar.n2)
        return 0;
}

int main()
{
    Arithmetic ar_obj;
    char choice = 'Y';
    double x, y;

    while(choice != 'N')
    {
        system("cls");
        cout << "\n Enter first numeric value: ";
        cin >> x;
        cout << "\n Enter second numeric value: ";
        cin >> y;

    ar_obj.set(x, y);
    ar_obj.display();

    cout << endl;
    cout << "\n" << x << " + " << y << " = " << ar_obj.add(x, y)
         << "\n" << x << " - " << y << " = " << ar_obj.sub(x, y)
         << "\n" << x << " * " << y << " = " << ar_obj.mult(x, y)
         << "\n" << x << " / " << y << " = " << ar_obj.divd(x, y)
         << endl;

    cout << "\n Average of " << ar_obj.add(x, y) << " is " << avg(ar_obj)
         << "\n The Larger of " << x << " and " << y << " is " << cmp1(ar_obj)
         << "\n The Smaller of " << x << " and " << y << " is " << cmp2(ar_obj)
         << " " ;

    cout << " \n\n Run this again (Y or N): ";
    cin >> choice;
    choice = tolower(choice);
}

}

