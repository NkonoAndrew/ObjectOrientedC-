#include <conio.h>
#include <iomanip>
#include <iostream>
#include<stdlib.h>
#include<fstream>
#include <string.h>
using namespace std;

struct EmployeeInfo
{
    string id;
    string lastname;
    string firstname;
    float hours;
    float payrate;
    float taxrate;
    float grosspay;
    float taxes;
    float netpay;
};

int main()
{
    int choice, count = 0;
    char again = 'y';
    const int size = 100;

    EmployeeInfo employees[size];

    //int n = sizeof(employees)/sizeof(employees[0]);

    cout.precision(2);
    cout.setf(ios::fixed,ios::showpoint);
    cout.setf(ios::fixed,ios::floatfield);

    while (again == 'y')
    {
    //Load records into structure
    cout << "\n 1 of 4: Display all the records."
         << "\n 2 of 4: Allow the user to find one employee."
         << "\n 3 of 4: Allow the user to add employees."
         << "\n 4 of 4: Quit."
         << "\n Make a selection:";
    cin  >> choice;
    choice = abs(choice);
    system("cls");

    while (choice >= 5 )
    {
             cout << "\n Please make choice between 1-4...";
             cout << "\n 1 of 4: Display all the records."
                  << "\n 2 of 4: Allow the user to find one employee."
                  << "\n 3 of 4: Allow the user to add employees."
                  << "\n 4 of 4: Quit."
                  << "\n Make a selection:";
             cin  >> choice;
            choice = abs(choice);
            system("cls");
    }

    switch (choice)
    {
    case 1:
        {

        ifstream inFile("personnel1.dat", ios::in);
        system("cls");

        if (!inFile)
        {
            cout << "\nSorry, the data file \"personnel.dat\" was not found on this drive";
            cout << "\n\nHit Any Key to continue";
            getch();
            system("cls");
            break;
        }

        //Read the first record
        for (int n = 1; n <= size ; n++)
        {
           inFile >> employees[n].id >> employees[n].lastname >> employees[n].firstname >> employees[n].hours >> employees[n].payrate >> employees[n].taxrate >> employees[n].grosspay >> employees[n].taxes >> employees[n].netpay;

                while(!inFile.eof())
                {
                    cout << "\n\n\n Employee # " << n++
                         << "\n Employee ID: " <<  employees[n].id
                         << "\n Last Name: " << employees[n].lastname
                         << "\n First Name: " << employees[n].firstname
                         << "\n Number of hours worked: " << employees[n].hours
                         << "\n Pay Rate: " << employees[n].payrate
                         << "\n Tax Rate: " << employees[n].taxrate
                         << "\n Gross Pay: " << employees[n].grosspay
                         << "\n Taxes With held: " << employees[n].taxes
                         << "\n Net pay: " << employees[n].netpay;

          inFile >> employees[n].id >> employees[n].lastname >> employees[n].firstname >> employees[n].hours >> employees[n].payrate >> employees[n].taxrate >> employees[n].grosspay >> employees[n].taxes >> employees[n].netpay;
                }
        //Close the file stream
        inFile.close();

        }
        break;
        }

    case 2:
    {
        string option;
        cout << "\n Enter the employee to find (by id):";
        getline(cin, option, '\n');
        getline(cin, option, '\n');


        break;
    }

    case 3:
    //Writing to file
    {
        string id, lastname, firstname;
        float hours, payrate, taxrate, gross, taxes, netpay, grosspay;


        //Add a new employee
        ofstream outFile("personnel1.dat",ios::out|ios::app);
        if (!outFile)
        {
            cerr << "File CANNOT be opened for data output!!\n";
            exit( -1 );
        }

        cout << "\n 1 of 6: Enter the ID:";
        getline(cin,id);
        getline(cin,id);
        cout << "\n 2 of 6:Enter the Last Name:";
        getline(cin,lastname);
        cout << "\n 3 of 6: Enter the First Name:";
        getline(cin,firstname);
        cout << "\n 4 of 6: Enter the hours worked:";
        cin >> hours;
        cout << "\n 5 of 6: Enter the Pay Rate:";
        cin >> payrate;
        cout << "\n 6 of 6:Enter the Tax Rate:";
        cin >> taxrate;


        for (int n = 0; n < size ; n++)
        {
         employees[n].grosspay = employees[n].hours * employees[n].payrate;
         employees[n].taxes = employees[n].grosspay * employees[n].taxrate;
         employees[n].netpay = employees[n].grosspay - employees[n].taxes;

             employees[n].lastname = lastname;
             employees[n].firstname = firstname;
             employees[n].payrate = payrate;
             employees[n].hours = hours;
             employees[n].taxrate = taxrate;

        outFile << employees[n].id << " " << employees[n].lastname << " " << employees[n].firstname << " " << employees[n].hours << " " << employees[n].payrate << " " << employees[n].taxrate << " " << employees[n].grosspay << " " << employees[n].taxes << " " << employees[n].netpay << "\n";

        }
        outFile.close();
        break;

        }
    case 4:
            cout << "\n Quitting...";
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
