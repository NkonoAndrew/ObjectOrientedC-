//Reger to pointers to structures (in c++ random) and make changes
#include <iomanip>
#include <iostream>
#include<stdlib.h>
#include <time.h>
#include<sstream>
#include <string>
using namespace std;

struct EmployeeInfo
{
    string lastname;
    string firstname;
    float hours;
    float payrate;
    float taxrate;
};

int main()
{
    int choice, searchedIndex;
    char again = 'y';
    bool rerun = true;
    const int elements = 8;
    bool ValueFound;
    EmployeeInfo employees[elements] = {"De Bosse", "Ian D.", 34.5, 45.75, 0.05,
                                        "Smithers III","Weylan K.S.", 40.1, 28.75, 0.04,
                                        "Simpson", "Homer J.", 40, 23.44, 0.023,
                                        "Haddington Smith", "Janet K.B.", 33.9, 35.75, 0.05,
                                        "Jackson", "Sarah L.", 39.45, 17.88, 0.15,
                                        "Kirk", "James Tiberius", 55.6, 89.65, 0.075,
                                        "Griffin", "Peter R.", 25.6, 17.88, 0.04,
                                        "Jones y Enrique", "Alias N.", 28.9, 37.88, 0.045};

    cout.precision(2);
    cout.setf(ios::fixed,ios::showpoint);
    cout.setf(ios::fixed,ios::floatfield);

    while (again == 'y')
    {
    //Load records into structure
    cout << "\n 1 of 4: Display all the records."
         << "\n 2 of 4: Allow the user to find one employee."
         << "\n 3 of 4: Allow the user to change one or more fields."
         << "\n 4 of 4: Quit:"
         << "\n Make a selection:";
    cin  >> choice;
    choice = abs(choice);

    while (choice > 4 )
    {
            cout << "\n Please make choice between 1-4: ";
            cin >> choice;
    }

    switch (choice)
    {
    case 1:

        for (int n = 0; n < elements ; n++)
        {
            float netpay = employees[n].hours * employees[n].payrate;
            float taxes = employees[n].hours * (employees[n].payrate * employees[n].taxrate);
            float grosspay = (employees[n].hours * employees[n].payrate) - employees[n].hours * (employees[n].payrate * employees[n].taxrate);

            cout << "\n\n Employee # " << n + 1
                 << "\n Employee Last Name:" << employees[n].lastname
                 << "\n Employee First Name:" << employees[n].firstname
                 << "\n " << employees[n].hours << " worked @ " << employees[n].payrate << " = " <<  netpay
                 << "\n Tax Rate:(" << employees[n].taxrate * 100 << "%):\t" << taxes
                 << "\n Employee Gross pay:" <<  grosspay;
        }
        break;
    case 2:

        int option;
        cout << "\n Enter the employee to find (by index location) There are 8 employees: ";
        cin >> option;
        option = abs(option);

        while (option > 8 )
        {
            cout << "\n There are only 8 employees, please choose 1-8: ";
            cin >> option;
        }
        switch (option)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 7:
        case 8:
        for (int n = 0; n < elements ; n++)
        {
            if ( n  == option - 1)
            {
            cout << "\n\n Employee #" <<  n + 1
                 << "\n Employee Last Name:" << employees[n].lastname
                 << "\n Employee First Name:" << employees[n].firstname
                 << "\n " << employees[n].hours << " worked @ " << employees[n].payrate << " = " <<  employees[n].hours * employees[n].payrate
                 << "\n Tax Rate:(" << employees[n].taxrate * 100 << "%):\t" << employees[n].hours * (employees[n].payrate * employees[n].taxrate)
                 << "\n Employee Gross pay:" <<  (employees[n].hours * employees[n].payrate) - employees[n].hours * (employees[n].payrate * employees[n].taxrate);
            }
        }
        }
        break;
        case 3:
        int option1;
        cout << "\n Find the Employee whose fields to change(using index):";
        cin >> option1;

         while (option1 > 8 )
        {
            cout << "\n There are only 8 employees, please choose 1-8: ";
            cin >> option1;
        }

        switch (option1)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 7:
        case 8:
        for (int n = 0; n < elements ; n++)
        {
            if ( n == option1 - 1)
            {
            cout << "\n\n Employee #" << n + 1
                 << "\n Employee Last Name:" << employees[n].lastname
                 << "\n Employee First Name:" << employees[n].firstname
                 << "\n " << employees[n].hours << " worked @ " << employees[n].payrate << " = " <<  employees[n].hours * employees[n].payrate
                 << "\n Tax Rate:(" << employees[n].taxrate * 100 << "%):\t" << employees[n].hours * (employees[n].payrate * employees[n].taxrate)
                 << "\n Employee Gross pay:" <<  (employees[n].hours * employees[n].payrate) - employees[n].hours * (employees[n].payrate * employees[n].taxrate);
            }
        }

        string newlastname;
        string newfirstname;
        float newhours;
        float newpayrate;
        float newtaxrate;

        cout << "\n\n\n 1 of 5: Change Last Name:";
        getline(cin, newlastname);
        getline(cin, newlastname);
        cout << "\n 2 of 5: Change the First Name:";
        getline(cin, newfirstname);
      //getline(cin, newfirstname);
        cout << "\n 3 of 5: Change the Pay Rate:";
        cin >> newpayrate;
        cout << "\n 4 of 5: Change the New hours:";
        cin >> newhours;
        cout << "\n 5 of 5: Change the tax rate:";
        cin >> newtaxrate;

        for (int n = 0; n < elements  ; n++)
        {
            if ( n == option1 - 1)
             {
             employees[n].lastname = newlastname;
             employees[n].firstname = newfirstname;
             employees[n].payrate = newpayrate;
             employees[n].hours = newhours;
             employees[n].taxrate = newtaxrate;
             }

         cout << "\n\n Employee# :" << n + 1;
         cout << "\n Last Name: " << employees[n].lastname;
         cout << "\n First Name : " << employees[n].firstname;
         cout << "\n Pay Rate   : " << employees[n].payrate;
         cout << "\n Hours      : " << employees[n].hours;
         cout << "\n Tax Rate   :(" << employees[n].taxrate * 100 << "%):\t" << employees[n].hours * (employees[n].payrate * employees[n].taxrate);
         cout << "\n Employee Gross pay:" <<  (employees[n].hours * employees[n].payrate) - employees[n].hours * (employees[n].payrate * employees[n].taxrate);

        }
        }
        break;

        case 4:
            cout << "\n Quitting.....";
            exit(0);
    }
    cout << "\n\n Would you like to run again yes(y) or no(n)...";
            cin >> again;
            again = tolower(again);
            cin.ignore();
            cin.clear();
            system("cls");
    }
}
