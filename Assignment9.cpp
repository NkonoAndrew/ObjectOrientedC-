#include <conio.h>
#include <iomanip>
#include <iostream>
#include<stdlib.h>
#include<fstream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct EmployeeInfo
{
    string id;
    string lastname;
    string firstname;
    float hours;
    float payrate;
    float taxes;
    int dependants;
};

bool compare( const EmployeeInfo &id1, const EmployeeInfo &id2)
{
    string temp1, temp2;
    temp1 = id1.lastname;
    temp2 = id2.lastname;
    return (temp1 < temp2);
}

int main()
{
    vector <EmployeeInfo> employees;
    EmployeeInfo emp;
    int choice, option;
    char again = 'y';
    int size;
    string ID;
    int index;
    string id, lastname, firstname;
    float hours, payrate, taxes;
    int dependants, count = employees.size();
    bool rerun = true;
    int len = 0;


    ifstream inFile("personnel5.txt",ios::in);
    system("cls");

    if(!inFile)
    {
        cout << "\nSorry, the data file \"personnel5.dat\" was not found on this drive";
        cout << "\n\nHit Any Key to continue";
        getch();
        system("cls");
    }

       employees.push_back(EmployeeInfo());
       inFile >> employees[0].id >> employees[0].lastname >> employees[0].firstname >> employees[0].hours >>
       employees[0].payrate >> employees[0].taxes >> employees[0].dependants;

    while (!inFile.eof())
    {
        len++;
        employees.push_back(EmployeeInfo());
        inFile >> employees[len].id >> employees[len].lastname >> employees[len].firstname >> employees[len].hours >>
        employees[len].payrate >> employees[len].taxes >> employees[len].dependants;
    }
    inFile.close();

    employees.pop_back();
    len--;

    while (again  == 'y')
    {
    system("cls");
    cout << "\n There are " << employees.size(
                                              ) << " employees";
    cout << "\n\n 1 of 7:Display the contents of the Vector"
         << "\n 2 of 7:Find a record based in Employee ID"
         << "\n 3 of 7:Sort the records based on Last Name"
         << "\n 4 of 7:Delete a record based on Employee ID"
         << "\n 5 of 7:Change one or more of the fields, search for the target record based on Employee ID"
         << "\n 6 of 7:Add a new record to the vector"
         << "\n 7 of 7:Quit"
         << "\n Make choice:";

        cin >> choice;

        switch (choice)
        {
            case 1:

            for (int n = 0; n < employees.size() ; n++)
            {
                cout << "\n\n\n Employee # " << n
                     << "\n Employee ID: " <<  employees[n].id
                     << "\n Last Name: " << employees[n].lastname
                     << "\n First Name: " << employees[n].firstname
                     << "\n Number of hours worked: " << employees[n].hours
                     << "\n Pay Rate: " << employees[n].payrate
                     << "\n Tax Rate: " << employees[n].taxes
                     << "\n Dependants: " << employees[n].dependants;
            }
            break;

            case 2:
            {
                cout << "\n Enter the employee ID to find:";
                cin >> ID;

                bool close = false;
                vector <string> temp;

                for (int n = 0; n < employees.size(); n++)
                {
                    temp.push_back(string());
                    temp[n] = employees[n].id;
                }
                vector <string>::iterator item = temp.begin();
                item = find(temp.begin(),temp.end(),ID);

                if (item != temp.end())
                {
                    index  = distance(temp.begin(),item);
                    close = true;
                    cout << "\n" << employees[index].id << " found at index#" << index;
                }
                else
                {
                    cout << "\n Not found";
                }

                break;
            }

            case 3:
                cin.clear();
                sort(employees.begin(), employees.end(),compare);

                 for (int n = 0; n < employees.size(); n++)
                {
                cout << "\n\n\n Employee # " << n
                     << "\n Employee ID: " <<  employees[n].id
                     << "\n Last Name: " << employees[n].lastname
                     << "\n First Name: " << employees[n].firstname
                     << "\n Number of hours worked: " << employees[n].hours
                     << "\n Pay Rate: " << employees[n].payrate
                     << "\n Tax Rate: " << employees[n].taxes
                     << "\n Dependants: " << employees[n].dependants;
                }
                break;

            case 6:
            {
                count = employees.size();
                employees.push_back(EmployeeInfo());

                cout << "\n Adding to the vector....";

                cout << "\n 1 of 7: Enter the ID:";
                cin >> employees[count].id;

                cout << "\n 2 of 7:Enter the Last Name:";
                cin >> employees[count].lastname;

                cout << "\n 3 of 7: Enter the First Name:";
                cin >> employees[count].firstname;

                cout << "\n 4 of 7: Enter the hours worked:";
                cin >> employees[count].hours;
                hours = fabs(hours);

                cout << "\n 5 of 7: Enter the Pay Rate:";
                cin >> employees[count].payrate;
                payrate = fabs(payrate);

                cout << "\n 6 of 7:Enter the Tax Rate:";
                cin >> employees[count].taxes;
                taxes = fabs(taxes);

                cout << "\n 7 of 7: Enter the dependents:";
                cin >> employees[count].dependants;
                dependants = fabs(dependants);

                 ofstream outFile;
                 outFile.open("personnel5.txt", ios::out);
                for ( int n = 0; n < employees.size(); n++)
                {
                    outFile << employees[n].id << " " << employees[n].lastname << " " << employees[n].firstname << " " << employees[n].hours
                        << " " << employees[n].payrate  << " " << employees[n].taxes  << " " << employees[n].dependants << "\n";

                }
                outFile.close();
                break;

            }

            case 4:
            {
                    cout << "\n Enter the employee ID to find:";
                cin >> ID;

                bool close = false;
                vector <string> temp;

                for (int n = 0; n < employees.size(); n++)
                {
                    temp.push_back(string());
                    temp[n] = employees[n].id;
                }
                    vector <string>::iterator item = temp.begin();
                    item = find(temp.begin(),temp.end(),ID);

                if (item != temp.end())
                {
                    index  = distance(temp.begin(),item);
                    close = true;
                    cout << "\n" << employees[index].id << " found at index# " << index <<  " will deleted ";
                    employees.erase(employees.begin() + index);

                     ofstream outFile;
                    outFile.open("personnel5.txt", ios::out);
                    for ( int n = 0; n < employees.size(); n++)
                    {
                        outFile << employees[n].id << " " << employees[n].lastname << " " << employees[n].firstname << " " << employees[n].hours
                        << " " << employees[n].payrate  << " " << employees[n].taxes  << " " << employees[n].dependants << "\n";

                    }
                    outFile.close();

                }
                else
                {
                    cout << "\n Not found";
                }
                break;
             }

            case 5:

            {
                cout << "\n Enter the employee ID to find:";
                cin >> ID;
                while (rerun)
                {

                bool close = false;
                vector <string> temp;

                for (int n = 0; n < employees.size(); n++)
                {
                    temp.push_back(string());
                    temp[n] = employees[n].id;
                }
                vector <string>::iterator item = temp.begin();
                item = find(temp.begin(),temp.end(),ID);

                if (item != temp.end())
                {
                    EmployeeInfo data;
                    index  = distance(temp.begin(),item);
                    close = true;
                    cout << "\n" << employees[index].id << " found at index#" << index;

                    cout << "\n\n Making changes to vector...";

                    cout << "\n\n 1 of 8: Employee ID:" << employees[index].id;
                    cout << "\n 2 of 8: Last Name:" << employees[index].lastname;
                    cout << "\n 3 of 8: First Name:" << employees[index].firstname;
                    cout << "\n 4 of 8: Hours worked:" << employees[index].hours;
                    cout << "\n 5 of 8: Pay Rate:" << employees[index].payrate;
                    cout << "\n 6 of 8: Tax Rate:" << employees[index].taxes;
                    cout << "\n 7 of 8: Dependents:" << employees[index].dependants;
                    cout << "\n 8 of 8:  Quit:";

                    cout << "\n Make a choice:";
                    cin >> option;

                    switch (option)
                    {
                    case 1:
                        cout << "\n Enter the new ID:";
                        cin >> employees[index].id;
                        //out << "\n" << index;
                        break;

                    case 2:
                        cout << "\n Enter the new Last Name:";
                        cin >> employees[index].lastname;
                        break;

                    case 3:
                        cout << "\n Enter the new First Name:";
                        cin >> employees[index].firstname;
                        break;

                    case 4:
                        cout << "\n Enter the Hours:";
                        cin >> employees[index].hours;
                        break;

                    case 5:
                        cout << "\n Enter the Pay rate:";
                        cin >> employees[index].payrate;
                        break;

                    case 6:
                        cout << "\n Enter the new Tax Rate:";
                        cin >> employees[index].taxes;
                        break;

                    case 7:
                        cout << "\n Enter the new Dependants:";
                        cin >> employees[index].dependants;
                        break;

                         ofstream outFile;
                         outFile.open("personnel5.txt", ios::out);
                        for ( int n = 0; n < employees.size(); n++)
                        {
                            outFile << employees[n].id << " " << employees[n].lastname << " " << employees[n].firstname << " " << employees[n].hours
                            << " " << employees[n].payrate  << " " << employees[n].taxes  << " " << employees[n].dependants << "\n";

                        }
                        outFile.close();
                    }


                }

                else
                {
                    cout << "\n Not found";
                }
                cout << "\n Would you like to run again (1) to continue and (0) to return to main menu:";
                cin >> rerun;
                rerun = abs(rerun);
                system("cls");
                }
                break;
            }

            case 7:
                cout << "\n Quitting....";
                exit(0);

        }
        cout << "\n\n Would you like to return to main menu (Y)-YES-----(N)-NO:";
        cin >> again;
        again = tolower(again);
        system("cls");

    }
        ofstream outFile;
        outFile.open("personnel5.txt", ios::out);
        for ( int n = 0; n < employees.size(); n++)
        {
            outFile << employees[n].id << " " << employees[n].lastname << " " << employees[n].firstname << " " << employees[n].hours
            << " " << employees[n].payrate  << " " << employees[n].taxes  << " " << employees[n].dependants << "\n";

        }
        outFile.close();

}

