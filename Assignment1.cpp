#include <fstream>
#include <conio.h>
#include <iomanip>
#include <iostream>
#include<stdlib.h>
#include <math.h>

using namespace std;

int main()
{
    char lastname[30], firstname[30];
    string id;
    float hours, payrate, fedtax, state, fedrate,staterate, grosspay, net, time;
    int choice, count = 0;
    char again = 'y';

    cout.precision(2);
    cout.setf(ios::fixed, ios::showpoint);
    cout.setf(ios::fixed, ios::floatfield);

    do
    {
        system("cls");
        cout << "\n 1. Write new records to the file. "
             << "\n 2. Display records from the data file to the screen. "
             << "\n 3. Find all employees who work less than 'N' hours "
             << "\n 4. Quit"
             << "\n Please make a choice:";
        cin >> choice;
        choice= abs(choice);

    while ((choice <= 0) || (choice > 4))
    {
        system("cls");
        cout << "You entered " << choice << "\n Please Enter 1, 2,3 or 4: ";
        cin >> choice;
        choice = abs(choice);
    }

    switch (choice)
    {
    case 1:
    {
            //Writing to the file
            ofstream outFile("personnel2.dat", ios::out | ios::app);
            if(!outFile)
            {
                cerr << "\n File CANNOT be opened for data output! \n";
                exit(-1);
            }
            //Allowing user to enter data
            cout << "\n 1 of 7-Enter the first name:";
            cin >> firstname;
            system("cls");
            cout << "\n 2 of 7-Enter the last name:";
            cin >> lastname;
            system("cls");
            cout << "\n 3 of 7-Enter the ID:";
            cin >> id;
            system("cls");
            cout << "\n 4 of 7-Enter the hours worked:";
            cin >> hours;
            hours = fabs(hours);
            system("cls");
            cout << setprecision(2) << "\n 5 of 7-Enter  Pay rate:$";
            cin >> payrate;
            payrate = fabs(payrate);
            system("cls");

             cout << "\n 6 of 7- Enter the State Tax Rate (No more than 11)%:";
             cin >> staterate;
             staterate = fabs(staterate);
              while (staterate > 11)
              {
                  cout << "\n Please enter a tax rate less than 11%";
                  cin >> staterate;
                  staterate=fabs(staterate);
              }
             system("cls");

             cout << "\n 7 of 7- Enter the Federal State Rate (No more than 41%):";
             cin >> fedrate;
             fedrate = fabs(fedrate);
             while (fedrate > 41)
             {
                 cout << "\n Please enter a rate less than 41%:";
                 cin >> fedrate;
                 fedrate = fabs(fedrate);

             }
            system("cls");

             grosspay = hours * payrate;
             fedtax = grosspay * (fedrate/100);
             state = grosspay * (staterate/100);
             net = grosspay - (fedtax + state);

            outFile << id << " " << lastname << " " << firstname << " " << hours << " " << payrate << " " << fedrate << " " << staterate << " " << grosspay
            << " " << fedtax << " " << state << " " << net << "\n" ;

            outFile.close();
            break;
        }
    case 2:
        {
         ifstream inFile("personnel2.dat", ios::in);
         system("cls");

         if(!inFile)
         {
             cout << "\n Data file was not found on the drive ";
             getch();
             system("cls");
             break;
         }
         inFile >> id >> lastname >> firstname >> hours >> payrate >> fedrate >> staterate >> grosspay >> fedtax >> state >> net;

        while (!inFile.eof())
         {
             count++;
             cout << "\n Employee #" << count
                  << "\n Employee ID: " <<  id
                  << "\n Lastname: " << lastname
                  << "\n Firstname: " << firstname
                  << "\n Number of hours worked: " << hours
                  << "\n Payrate: " << payrate
                  << "\n Federal Tax Rate: " << fedrate
                  << "\n State Tax Rate: " << staterate
                  << "\n Gross Pay:$" << grosspay
                  << "\n Federal Taxes withhled:$" << fedtax
                  << "\n State taxes withheld:$" << state
                  << "\n Net Pay:$" << net << "\n\t";

        inFile >> id >> lastname >> firstname >> hours >> payrate >> fedrate >> staterate >> grosspay >> fedtax >> state >> net;

         }
          // Close the file stream

            inFile.close();
            // Reset the counter
            count = 0;
            break;
        }

    case 3:
    cout << "\n Find all Employees less than n hours...Enter number of hours: ";
    cin >> time;

    //Load data into array or vector


    case 4:
        {
            //Quitting the application
            system("cls");
            cout << "\n Quitting...."
                 << "\n Hit Any Key To Continue...";
                 getch();
                 exit(0);
        }

    }
    cout << "\n Would you like to run again Yes(Y) or No(N)...";
    cin >> again;
    again = tolower(again);
    system("cls");

    }while (again == 'y');
}
