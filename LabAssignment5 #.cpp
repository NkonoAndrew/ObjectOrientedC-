#include <iomanip>
#include <iostream>
#include<stdlib.h>
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
        void setid (string id)
        {
            this->id = id;
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
        void display();

        void setAll(string id, string firstname, string lastname, float gpa, int classes)
        {
            setid(id);
            setfirstname(firstname);
            setlastname(lastname);
            setgpa(gpa);
            setclasses(classes);
        }

        string getid()
        {
            return id;
        }

        string getlastname()
        {
            return lastname;
        }

        string getfirstname()
        {
            return firstname;
        }

        float getgpa()
        {
            return gpa;
        }

        float getclass()
        {
            return classes;
        }
         StudentInfo()
        {

        }

        StudentInfo( string id3, string lastname3, string firstname3, float gpa3, int classes3)
        {
            id = id3;
            lastname = lastname3;
            firstname = firstname3;
            gpa = gpa3;
            classes = classes3;
        }

};

void StudentInfo::display()
{
        cout << "\n\n Student ID:" << id
             << "\n First Name: " << firstname
             << "\n Last Name:" << lastname
             << "\n GPA:" << gpa
             << "\n Classes taken " << classes;
}
void displayall ( StudentInfo students[], int size)
{
               for(int i = 0; i < size; i++)
               {
                    students[i].display();
                    cout << "\n";
               }
}

void addStudent( StudentInfo students[], int &size)
{
        string id, lastname, firstname;
        float gpa;
        int classes;

        cout << "\n\n Student ID:";
        cin >> id;
        students[size].setid(id);

        cout << "\n First Name: ";
        cin >> firstname;
        students[size].setfirstname(firstname);

        cout << "\n Last Name:";
        cin >> lastname;
        students[size].setlastname(lastname);

        cout << "\n GPA:";
        cin >> gpa;
        students[size].setgpa(gpa);

        cout << "\n Classes taken ";
        cin >> classes;
        students[size].setclasses(classes);

        size++;

        displayall(students,size);
}

int main()
{
    int count, choice;
    const int size = 10;
    int currentsize = 4;
    char again = 'y';
    string id,firstname,lastname;
    float gpa, classes;


   StudentInfo students[size];
    students[0] = StudentInfo ("AS123", "Peter", "Pan", 4.0, 45);
    students[1] = StudentInfo ("AS124", "John", "Meyers", 4.0, 45);
    students[2] = StudentInfo ("AS125", "Timothy", "Doe", 4.0, 45);
    students[3] = StudentInfo ("AS126", "Sarah", "Mary", 4.0, 45);


    while (again == 'y')
    {

         cout << "\n 1 of 3:Display all the members"
              << "\n 2 of 3: Allow user to enter a NEW class member, student5 or student6)"
              << "\n 3 of 3: Quit"
              << "\n Make a choice:";


         cin >>  choice;
         choice = abs(choice);

            while ( choice > 3)
            {
                cout << "\n You entered " << choice << " please make a selection between 1-3:";
                cin >>  choice;
                choice = abs(choice);

            }

            switch (choice)
            {
            case 1:
                cout << "\n Displaying the students data:";
                displayall(students, currentsize);
                break;
            case 2:
                addStudent(students, currentsize);
                break;
            case 3:
                cout << "\n Quitting....";
                exit(0);

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
