#include <fstream>
#include <conio.h>
#include <iomanip>
#include <iostream>
#include<stdlib.h>
#include <math.h>

using namespace std;

void calculations ( float&, float& , float&, float&, float&);

int main()
{
    float number1, number2, add, subtract, multiply;
    float *pnum1 = &number1, *pnum2 = &number2, *padd = &add, *psubtract = &subtract, *pmultiply = &multiply;
//    float &n1, &n2, &n3, &n4, n5&;
    char again = 'y';

    cout.precision(2);
    cout.setf(ios::fixed, ios::showpoint);
    cout.setf(ios::fixed, ios::floatfield);

    while ( again == 'y')
    {
        cout << "\n1 of 2- Enter the first number: ";
        cin >> *pnum1;
        cout << "\n2 of 2- Enter the second number: ";
        cin >> *pnum2;
        system("cls");

        calculations (*pnum1, *pnum2, *padd, *psubtract, *pmultiply);

        cout << "\n " << *pnum1 << " + " << *pnum2 << " = " << *padd
             << "\n " << *pnum1 << " - " << *pnum2 << " = " << *psubtract
             << "\n " << *pnum1 << " * " << *pnum2 << " = " << *pmultiply;

        cout << "\n\n Would you like to run again Yes(y) or No(N): ";
        cin >> again;
        again = tolower(again);
        system("cls");
    }
}

void calculations (float &num1, float &num2, float &add, float &subtract, float &multiply)
{
    add = num1 + num2;
    subtract = num1 - num2;
    multiply = num1 * num2;
}
