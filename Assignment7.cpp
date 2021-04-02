#include <conio.h>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

class Employees
{
    protected:
        string id;
        float hours;
        float overtime;
        float incometax;
        float perhour;
        string empstatus;

    public:
        string getid()
        {
            return id;
        }
        float gethours()
        {
            return hours;
        }
        float getperhour()
        {
            return perhour;
        }
        float getincometax()
        {
            return incometax;
        }
        string getempstatus()
        {
            return empstatus;
        }
        void setid(string id)
        {
            this->id = id;
        }
        void sethours(float hours)
        {
            this->hours = hours;
        }
        void setperhour(float perhour)
        {
            this->perhour = perhour;
        }
        void setincometax(float incometax)
        {
            this->incometax = incometax;
        }
        void setempstatus(string empstatus)
        {
            this->empstatus = empstatus;
        }

        virtual void calculatepay() = 0;

        virtual void setovertime()
        {
            overtime = 0;
        }

        virtual void Terminate()
        {
            cout << "\n Terminated (base class)";
        }


        void initialize(string id, float perhour, float incometax, string empstatus)
        {
            setid(id);
            setperhour(perhour);
            setincometax(incometax);
            setempstatus(empstatus);
        }
        Employees()
        {
            id = "nein";
            hours = 0;
            perhour = 0;
            incometax = 0;
            overtime = 0;
            empstatus = "nein";
        }
};

class Hourly:public Employees
{
    public:
        Hourly()
        {
            id = "N/A";
            hours = 0;
            perhour = 0;
            incometax = 0;
            overtime = 0;
            empstatus = "Hourly";
        }
        void Terminate()
        {
            id = "Nein";
            hours = 0;
            perhour = 0;
            incometax = 0;
            overtime = 0;
            empstatus = "Hourly Terminated";
        }

        void setovertime()
        {
            if (hours <= 40)
            {
                overtime = 0;
                hours = 40;
            }
            else
            {
                overtime = hours - 40;
                hours = 40;
            }
        }

        void calculatepay()
        {
            cout.precision(2);
            cout.setf(ios::fixed,ios::showpoint);
            cout.setf(ios::fixed,ios::floatfield);

            float regularpay, overtimepay, grosspay, taxes, netpay, otrate = 1.5;
            regularpay = hours * perhour;
            overtimepay = overtime * perhour * otrate;
            grosspay = regularpay + overtimepay;
            taxes = grosspay * incometax;
            netpay = grosspay - taxes;

            cout << "\n\n Employee ID:" << id << "\n" << hours << " @ " << perhour << " (payrate)";
            if (overtime > 0)
                {
                    cout << "\n The overtime pay is " << overtimepay;
                }
            if (overtimepay > 0)
                {
                    cout << "\n " << overtime << " overtime hours @" << otrate * perhour;
                }

            cout << "\n GrossPay:" << grosspay
                 << "\n Taxes:" << taxes
                 << "\n Net Pay:" << netpay
                 << "\n Employee Status:" << empstatus;
        }

        void initialize(string ID, float hours, float Perhour, float Incometax)
        {
            setid(ID);
            setincometax(Incometax);
            setperhour(Perhour);
            sethours(hours);
            if (hours <= 40)
            {
                overtime = 0;
                hours = 0;
            }
            else
            {
                overtime = hours - 40;
                hours = 40;
            }
            empstatus = "Hourly";

        }
};

class Salaried: public Employees
{
   public:
    Salaried()
    {
        perhour = 0;
        id = "N/A";
        incometax = 0;
        empstatus = "Salaried";
    }
    void Terminate()
    {
        id = "nein";
        perhour = 0;
        incometax = 0;
        empstatus = "Salaried Terminated";
    }
    void initialize(string id, float perhour, float incometax)
    {
        setid(id);
        setperhour(perhour);
        setincometax(incometax);
        setempstatus("Salaried");
        sethours(40);
    }
    void calculatepay()
    {
        cout.precision(2);
        cout.setf(ios::fixed,ios::showpoint);
        cout.setf(ios::fixed,ios::floatfield);

      float grosspay, taxes, netpay;
            grosspay = perhour;
            taxes = grosspay * incometax;
            netpay = grosspay - taxes;

     cout << "\n Employee ID:" << id
          << "\n GrossPay:" << grosspay
          << "\n Taxes:" << taxes
          << "\n Net Pay:" << netpay
          << "\n Employee Status:" << empstatus;

    }
};

class Contractor:public Employees
{
    public:
        Contractor()
        {
            id = "N/A";
            perhour = 0;
            incometax = 0;
            empstatus = "Salaried";
        }
        void Terminate()
        {
            id = "nein";
            perhour = 0;
            empstatus = "Contract Ended";
        }
        void initialize(string id, float perhour)
        {
            setid(id);
            setperhour(perhour);
            hours = 0;
            incometax = 0;
            setempstatus("Salaried");
        }
        void calculatepay()
        {
           float grosspay3;

           grosspay3 = perhour;

           cout << "\n Employee ID: " << id
                << "\n Contractor Fee fee: " << perhour
                << "\n Employee Status:" << empstatus;

        }
};

int main()
{
        int numHourly = 3;
        int numSalaried = 3;
        int numContractor = 3;
        int option,index;
        const int size = 10;

        Hourly hours[size];
        Salaried salary[size];
        Contractor contract[size];

        Employees *employees = &hours[3];
        Employees *salaried = &salary[3];
        Employees *contracted = &contract[3];


        hours[0].initialize("AS101",32.34,28.50,0.055);
        hours[1].initialize("GH199",44.5,39.22,0.04);
        hours[2].initialize("UY189",47.22,45.60,0.016);

        salary[0].initialize("VE320",45750.34,0.07);
        salary[1].initialize("BR003",65740.88,0.065);
        salary[2].initialize("AA891",50900.71,0.12);

        contract[0].initialize("BV111",55473.56);
        contract[1].initialize("NB290",65540.87);
        contract[2].initialize("VC100",45679.25);

    string employeeid;
    float whours, payrate, taxrate, othours;
    int choice, count = 0;
    char again = 'y';

    while (again)
    {
        system("cls");

    cout << "\n 1 of 8: Enter data for the Hourly"
         << "\n 2 of 8: Enter data for the Salaried"
         << "\n 3 of 8: Enter data for Contractor"
         << "\n 4 of 8: Display the ID, Pay, Hours Tax, Net if any for Hourly"
         << "\n 5 of 8: Display the ID, Annual Salary, Tax, Net for the Salaried"
         << "\n 6 of 8: Display the ID, Contractor Fee for the Contractor"
         << "\n 7 of 8: Terminate a derived class member Employee (Hourly, Salaried, Contractor)"
         << "\n 8 of 8: Quit "
         << "\n\n Make a choice:";

    cin >> choice;
    choice = abs(choice);

    switch (choice)
    {
    case 1:
       {
           string id;
        float hours, rate, incomerate;

        if ( numHourly < size)
        {
            cout << " Adding Hourly Employees...";
        cout << "\n\n Hourly Employee.." << numHourly + 1 << " of " << size;
        cout << "\n\n\n 1 of 4: Enter the Employee\'s ID:";
        cin >> id;
        employees->setid(id);

        cout << "\n 2 of 4: Enter the number of hours worked:";
        cin >> hours;
        hours = fabs(hours);
        employees->sethours(hours);

        cout << "\n 3 of 4: Enter the pay rate: ";
        cin >> rate;
        rate = fabs(rate);
        employees->setperhour(rate);

        cout << "\n 4 of 4: Enter the income tax rate: ";
        cin >> incomerate;
        incomerate = fabs(incomerate);
        employees->setincometax(incomerate);

        employees++;
        numHourly++;
        }
        else
        {
        cout << "\n The array cannot hold any more employees...";
        exit(0);
        }

       }
       break;

    case 2:
        {
        string id2;
        float incomerate2, rate2;

        if ( numSalaried < size)
        {
            cout << "\n Adding Salaried Employees.."
                 << "\n\n Salaried Employee " << numSalaried + 1 << " of " << size
                 << "\n\n\n 1 of 3: Enter the Employee\'s ID:";
        cin >> id2;
        salaried->setid(id2);

        cout << "\n 2 of 3: Enter the salary: ";
        cin >> rate2;
        rate2 = fabs(rate2);
        salaried->setperhour(rate2);

        cout << "\n 3 of 3: Enter the income tax rate: ";
        cin >> incomerate2;
        incomerate2 = fabs(incomerate2);
        salaried->setincometax(incomerate2);

        salaried++;
        numSalaried++;
        }
        else
            cout << "\n The array cannot hold any more employees";

        }
        break;
    case 3:
        {
        string id3;
        float rate3;

        if (numContractor < size)
        {
            cout << "\n Adding Contractors.."
                 << "\n Contractor " << numContractor + 1 << " of " << size
                 << "\n\n\n 1 of 2: Enter the Employee\'s ID:";
        cin >> id3;
        contracted->setid(id3);

        cout << "\n 1 of 2:: Enter the contract fee: ";
        cin >> rate3;
        rate3 = fabs(rate3);
        contracted->setperhour(rate3);

        contracted++;
        numContractor++;
        }
        else
             cout << "\n The array cannot hold any more employees";
        }
        break;

    case 4:

        cout << "\n Display Data for Hourly Employees";
        cout << "\n There are " << numHourly << " in hourly class";
        cout << "\n";
        for (int n = 0; n < numHourly; n++)
        {
            hours[n].calculatepay();
        }
        break;

    case 5:
        cout << "\n Display Data for Salaried Employees";
        cout << "\n There are " << numSalaried << " in salaried class";


        for ( int n = 0; n < numSalaried; n++)
        {
            cout << "\n" ;
            salary[n].calculatepay();
        }

        break;

    case 6:
        cout << "\n Display Data for Contracted Employees";
        cout << "\n There are " << numContractor << " in salaried class";

        cout << "\n";
        for ( int n = 0; n < numContractor; n++)
        {
            cout << "\n";
            contract[n].calculatepay();
        }

        break;

    case 7:
        cout << "\n Terminating one of the employees..."
             << "\n 1 of 3: Terminate Hourly Employee"
             << "\n 2 of 3: Terminate Salaried Employee"
             << "\n 3 of 3: Terminate Contractor"
             << "\n Make a choice:";
        cin >> option;
        option = abs(option);

                switch (option)
                {
                    case 1:

                        cout << "\n Enter the Employee to Terminate(by index):";
                        cin >> index;

                        for (int n = 0; n < numHourly; n++)
                        {
                            if (n == index - 1)
                            {
                                cout << "\n";
                                hours[n].Terminate();
                            }
                        }

                        break;
                    case 2:
                        cout << "\n Enter Employee to Terminate(by index):";
                        cin >> index;
                        for (int n = 0; n < numSalaried; n++)
                        {
                            if (n == index - 1)
                            {
                                cout << "\n";
                                salary[n].Terminate();
                            }
                        }
                        break;
                    case 3:
                        cout << "\n Enter the Employee to Terminate(by index):";
                        cin >> index;
                        for (int n = 0; n < numContractor; n++)
                        {
                            if (n == index - 1)
                            {
                                cout << "\n";
                                contract[n].Terminate();
                            }
                        }
                        break;
                }
                break;

    case 8:
            cout << "\n Quitting.....";
            exit(0);

    }
        cout << "\n\n Would you like to run again yes(y) or no(n)...";
        cin >> again;
        again = tolower(again);
        system("cls");
    }
}

