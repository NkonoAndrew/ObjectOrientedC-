#include <conio.h>
#include <iomanip>
#include <iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;
void addition(float, float);
void subtraction (float, float);
void multiplication (float, float);
void division ( float, float);
void combination (float, float);


int main()
{
    float number1, number2;
    //float add, subtract, multiply, divide;
   // bool again = true;
    bool rerun = true;
    int choice;
    char again = 'y';

    cout.precision(2);
    cout.setf(ios::fixed,ios::showpoint);
    cout.setf(ios::fixed,ios::floatfield);



   while(again == 'y')
    {
         cout << " Enter the first number: ";
         cin  >> number1;
         cout << "Enter the second number: ";
         cin  >> number2;
          while (number2 == 0)
          {
              cout << "\n Please enter a number other than 0 because a number divided by zero is undefined : ";
              cin >> number2;
              system("cls");
          }

         // Second number cannot be zero

       while(again)
        {
            cout << "\n 1 of 7: Add " << number1 << " + " << number2
                 << "\n 2 of 7: Subtract " << number1 << " - " << number2
                 << "\n 3 of 7: Multiply " << number1 << " * " << number2
                 << "\n 4 of 7: Divide " << number1 << " / " << number2
                 << "\n 5 of 7: Show all calculations "
                 << "\n 6 of 7: Make changes "
                 << "\n 7 of 7: Quit";

            cout << "\n\n Make a selection to display:";
            cin >> choice;
            choice = abs(choice);

            switch (choice)
            {
               case 1:
                    addition(number1, number2);
                    break;
               case 2:
                    subtraction(number1, number2);
                    break;
               case 3:
                    multiplication(number1, number2);
                    break;
               case 4:
                    division(number1, number2);
                    break;
               case 5:
                   combination(number1, number2);
                   break;
               case 6:
                  again = false;
                  break;
               case 7:
                   system("cls");
                   exit(0);

               default:
                    cout << "\n\n\t" << choice << " is not a valid entry, select a number between 1 and 7: ";
                    cin >> choice;
                    choice = abs(choice);

            }
            cout << "\n\n Hit any key to continue...";
            getch();
            system("cls");

        }

    system("cls");
    }
}
void addition(float n1, float n2)
{
    cout << "\n " << n1 << " + " << n2 << " = " << (n1+n2);
}
void subtraction(float n1, float n2)
{
    cout << "\n " << n1 << " - " << n2 << " = " << n1-n2;
}
void multiplication(float n1, float n2)
{
    cout << "\n" << n1 << " * " << n2 << " = " << n1*n2;
}
void division(float n1, float n2)
{
    cout << "\n" << n1 << " / " << n2 << " = " << n1/n2;

}
void combination(float n1, float n2)
{
    addition(n1,n2);
    subtraction(n1,n2);
    multiplication(n1,n2);
    division(n1,n2);
}


