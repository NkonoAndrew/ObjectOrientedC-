#include <conio.h>
#include <iomanip>
#include <iostream>
#include<stdlib.h>
#include<fstream>
#include <string.h>
#include <cstring>
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

int readFile(EmployeeInfo employees[])
{
    // Record counter
    int count = 0;
    ifstream inFile("personnel1.dat", ios::in);
      system("cls");

    if (!inFile)
        {
            cout << "\nSorry, the data file \"personnel.dat\" was not found on this drive";
            cout << "\n\nHit Any Key to continue";
            getch();
            system("cls");
        }

         inFile >> employees[count].id >> employees[count].lastname >> employees[count].firstname >> employees[count].hours >> employees[count].payrate
                 >> employees[count].taxrate >> employees[count].grosspay >> employees[count].taxes >> employees[count].netpay;

        while(!inFile.eof())
        {
            count++;
          inFile >> employees[count].id >> employees[count].lastname >> employees[count].firstname >> employees[count].hours >> employees[count].payrate
                 >> employees[count].taxrate >> employees[count].grosspay >> employees[count].taxes >> employees[count].netpay;
        }
        inFile.seekg(0,ios::beg);
        return count;

}

void displayAll(EmployeeInfo employees[], int len)
{
    for(int x = 0; x < len  ; x++)
    {
    // Displays employee info
        cout << "\n\n Employee #" << x + 1
             << "\n Employee ID "<<employees[x].id
             << "\n First Name:" << employees[x].firstname
             << "\n Last Name: " << employees[x].lastname
             << "\n Hours Worked: " << employees[x].hours
             << "\n Employee Pay Rate: $" << employees[x].payrate
             << "\n Employee Tax Rate: "<< employees[x].payrate << "%"
             << "\n Gross Pay \t $ " << employees[x].grosspay
             << "\n Less Tax \t $" << employees[x].taxes
             << "\n Net Pay \t $" << employees[x].netpay;
    }
    cout << "\n\n There are " << len - 1 << " Total Employees: ";
}


int main()
{
    int choice, count = 0;
    char again = 'y';
    const int size = 100;

    EmployeeInfo employees[size];

    int len = readFile(employees);

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
        displayAll(employees, len);
        break;
    case 2:
        break;
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
        cin >> employees[len].id;
        cout << "\n 2 of 6:Enter the Last Name:";
        cin >> employees[len].lastname;
        cout << "\n 3 of 6: Enter the First Name:";
        cin >> employees[len].firstname;
        cout << "\n 4 of 6: Enter the hours worked:";
        cin >> employees[len].hours;
        cout << "\n 5 of 6: Enter the Pay Rate:";
        cin >> employees[len].payrate;
        cout << "\n 6 of 6:Enter the Tax Rate:";
        cin >> employees[len].taxrate;


         for ( int x = 0; x < len; x++)
         {
             employees[len].grosspay = employees[len].hours * employees[len].payrate;
             employees[len].taxes = employees[len].grosspay * employees[len].taxrate;
             employees[len].netpay = employees[len].grosspay - employees[len].taxes;

            outFile << employees[len].id << " " << employees[len].lastname << " " << employees[len].firstname << " " << employees[len].hours << " " << employees[len].payrate << " " << employees[len].taxrate << " " << employees[len].grosspay << " " << employees[len].taxes << " " << employees[len].netpay <<"\n";

         len++;
        outFile.close();
         break;
         }
         cout << "\n There are now " << len - 1 << " employees ";

        break;
        }
    case 4:
        cout << "\n Quitting...";
        exit(0);
        break;
    }
        cout << "\n\n Would you like to run again yes(y) or no(n)...";
        cin >> again;
        again = tolower(again);
        cin.ignore();
        cin.clear();
        count = 0;
        system("cls");
    }
}
