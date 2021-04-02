#include <conio.h>
#include <iomanip>
#include <iostream>
#include<stdlib.h>
#include<fstream>
#include <string.h>
#include <cstring>
#include<limits>
using namespace std;

class StudentInfo
{
    private:
        string id;
        string lastname;
        string firstname;
        float gpa;
        int classes;
    public:

        void display();
        void all(string, string, string, float, float);

        //Get values
        string getid() const
        {
            return id;
        }

        string getlastname() const
        {
            return lastname;
        }

        string getfirstname() const
        {
            return firstname;
        }

        float getgpa() const
        {
            return gpa;
        }

        float getclass() const
        {
            return classes;
        }

       void setid (string id)
        {
            this->id  = id;
        }
        void setlastname (string lastname)
        {
            this->lastname = lastname;
        }
        void setfirstname (string firstname)
        {
            this->firstname = firstname;
        }
        void setgpa (float gpa)
        {
            this-> gpa = gpa;
        }
        void setclasses (int classes)
        {
            this->classes = classes;
        }

        void setAll(string id, string firstname, string lastname, float gpa, int classes)
        {
            setid(id);
            setfirstname(firstname);
            setlastname(lastname);
            setgpa(gpa);
            setclasses(classes);
        }
};


//void StudentInfo::all(string, string, string, float, float)
void StudentInfo::display()
{
        cout << "\n Student ID:" << id
             << "\n First Name: " << firstname
             << "\n Last Name:" << lastname
             << "\n GPA:" << gpa
             << "\n Classes taken:" << classes;

}

void displayall ( StudentInfo students[], int len)
{
    int count = 1;
    cout << "\n Student details : ";
               for(int i = 0; i < len; i++)
               {
                   cout << " \n\n Student #" << count ++;
                    students[i].display();
                    cout << "\n";
               }
}
//students.push_back(StudentInfo(id, firstname, lastname, gpa, classes)
int readFile(StudentInfo students[])
{
        string id2;
        string lastname2;
        string firstname2;
        float gpa2;
        int classes2;

        // Record counter
    int count = 0;
    ifstream inFile("Students1.dat", ios::in|ios::binary);
      system("cls");

    if (!inFile)
        {
            cout << "\nSorry, the data file \"Student1.dat\" was not found on this drive";
            cout << "\n\nHit Any Key to continue";
            getch();
            system("cls");
        }

        inFile >> id2 >> firstname2 >> lastname2 >> gpa2 >> classes2;

        while(!inFile.eof())
        {
            students[count].setAll(id2,firstname2,lastname2,gpa2,classes2);

            count++;
        inFile >> id2 >> firstname2 >> lastname2 >> gpa2 >> classes2;

        }

        inFile.close();
        return count;
}

void addStudent(StudentInfo students[], int &size)
{

               string id,firstname,lastname;
               float gpa;
               int classes;

                    cout << "\n Enter ID :";
                    cin >> id;

                    cout << "\n Enter Firstname :";
                    cin >> firstname;

                    cout << "\n Enter Lastname : ";
                    cin >> lastname;

                    cout << "\n Enter GPA: ";
                    cin >> gpa;

                    cout << "\n Enter number of classes : ";
                    cin >> classes;

                    students[size].setAll(id,firstname,lastname,gpa,classes);
                    size++;

}

// function to write the updated information back to the input file

void writefile(StudentInfo students[], int size)
{
               fstream outFile("Students1.dat", ios::out); //overwrite the existing file

               for(int i = 0; i < size; i++)

                {
                    outFile << students[i].getid() << " " << students[i].getfirstname() << " " << students[i].getlastname()
                            << " " << students[i].getgpa() << " " << students[i].getclass() << "\n";

               }
               outFile.close();
}
void changefield(StudentInfo students[], int &index, int len)
{

               int option;
               string id,firstname,lastname;
               float gpa;
               int classes;
               bool rerun2 = true;
               bool rerun1 = true;

            do
            {
                system("cls");
            cout << "\n Enter the student who's details you'd like to change(by index location):";
            cin >> index;

        cout << "\n There are " << len << " students";

        cout << "\n\n Student ID:" << students[index-1].getid()
             << "\n First Name: " << students[index-1].getfirstname()
             << "\n Last Name:" << students[index-1].getlastname()
             << "\n GPA:" << students[index-1].getgpa()
             << "\n Classes taken " << students[index-1].getclass();

              do
               {
               cout << "\n\n 1 of 5: Change ID "
                    << "\n 2 of 5: Change First Name "
                    << "\n 3 of 5: Change Last Name "
                    << "\n 4 of 5: Change GPA "
                    << "\n 5 of 5: Change classes "
                    << "\n\n Make a selection:";

               cin >> option;

               while(option < 1 || option > 5)
               {
                    cout << "\n Invalid selection. Make a selection : ";
                    cin >> option;
               }

               switch(option)
               {
                    case 1:
                        cout << "\n Enter New ID for " << students[index-1].getid() << ":";
                        cin >> id;
                        students[index-1].setid(id);
                        break;

                    case 2:
                        cout << "\n Enter New First Name for "
                             << students[index-1].getfirstname() << ":";
                        cin >> firstname;
                        students[index-1].setfirstname(firstname);
                        break;

                    case 3:
                        cout << "\n Enter New Lastname for "
                             << students[index-1].getlastname() << ":";
                        cin >> lastname;
                        students[index-1].setlastname(lastname);
                        break;

                    case 4:
                        cout << "\n Enter New GPA for "
                             << students[index-1].getgpa() << ":";
                        cin >> gpa;
                        students[index-1].setgpa(gpa);
                        break;

                    case 5:
                        cout << "\n Enter number of classes "
                             << students[index-1].getclass() << ":";
                        cin >> classes;
                        students[index-1].setclasses(classes);
                        break;

                    index++;
               }
                    cout << "\n One(1) to make another change, Zero (0) to exit:";
               cin >> rerun1;
               rerun1 = abs(rerun1);

                } while(rerun1);

               cout << "\n One(1) to make make changes for another student, Zero (0) to exit:";
               cin >> rerun2;
               rerun2 = abs(rerun2);

            } while(rerun2);

            writefile(students, len);
}

int main()
{
    char again = 'y';
    int count, choice, option, counter = 0;
    const int size = 20;
    int index;
    bool rerun = true;

    StudentInfo students[size];

    int len = readFile(students);


    cout.precision(2);
    cout.setf(ios::fixed,ios::showpoint);
    cout.setf(ios::fixed,ios::floatfield);

    while (again == 'y')
    {
        system("cls");
        cout << "\n There are " << len << " students "
             << "\n 1 of 5: Display each member's characteristics "
             << "\n 2 of 5: Find a student by index location"
             << "\n 3 of 5: Change any of the fields for a student"
             << "\n 4 of 5: Add a new student record "
             << "\n 5 of 5: Quit "
             << "\n\n Make a selection: ";
        cin >> choice;
        choice = abs(choice);

        system("cls");

    while (choice > 5 )
    {
        cout << "\n 1 of 5: Display each member's characteristics "
             << "\n 2 of 5: Find a student by index location"
             << "\n 3 of 5: Change any of the fields for a student"
             << "\n 4 of 5: Add a new student record "
             << "\n 5 of 5: Quit "
             << "\n\n Make a selection: ";
        cin >> choice;
        choice = abs(choice);
    }

    switch (choice)
    {
    case 1:
        displayall(students, len);
        break;

    case 2:
        int option;
        cout << "\n Enter the employee to find (by index location) There are " << len << " employees:";
        cin >> option;
        option = abs(option);

        if (option < 0 || option > len)
            cout << "\n" << option << " is not a valid index location. Choose:";

        else
            students[option - 1].display();

        break;
    case 3:
        cout << "\n There are " << len << " students ";
        changefield(students, index, len);
        break;

    case 4:
        addStudent(students, len);
        break;

    case 5:
        cout << "\n Quitting....";
        writefile(students,len);
        exit(0);

    }
        cout << "\n\n Would you return to main menu; yes(y) or no(n)...";
        cin >> again;
        again = tolower(again);
        cin.ignore();
        cin.clear();
        count = 0;
        system("cls");
    }
    writefile(students,len);
}

