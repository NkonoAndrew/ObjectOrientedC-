#include <math.h>
#include <conio.h>
#include <iomanip>
#include <iostream>
#include<stdlib.h>
using namespace std;

class Vehicles
{
    protected:
        string vehiclename;
        int passengers;
        int wheels;
        float speed;

    public:
        Vehicles()
        {
            vehiclename = " Motorcycle ";
            passengers = 2;
            wheels = 2;
            speed = 100;
        }

        string getvehiclename()
        {
            return vehiclename;
        }

        int getpassengers()
        {
             return passengers;
        }

        int getwheels()
        {
            return wheels;
        }

        float getspeed()
        {
            return speed;
        }

        Vehicles(string vehiclename1, int passengers1, int wheels1, float speed1)
        {
            vehiclename = vehiclename1;
            passengers = passengers1;
            wheels = wheels1;
            speed = speed1;
        }

        void setvehiclename(string vehiclename)
        {
            this->vehiclename  = vehiclename;
        }
        void setpassengers(int passengers)
        {
            this->passengers = passengers;
        }
        void setwheels(int wheels)
        {
            this->wheels = wheels;
        }
        void setspeed(float speed)
        {
            this->speed = speed;
        }

        void setall(string vehiclename, int passengers, int wheels, float speed)
        {
            setvehiclename(vehiclename);
            setpassengers(passengers);
            setwheels(wheels);
            setspeed(speed);
        }
        void display()
        {
            cout << "\n\n " << vehiclename << " carries " << passengers << "(including the driver)"
                 << "\n " << vehiclename << " has " << wheels << " wheels and can travel " << speed << "mph";
        }

};

class Truck:public Vehicles
{
    private:
        float load;
        float weight;
    public:

        float getload()
        {
            return load;
        }
        float getweight()
        {
            return weight;
        }

        void setload(int load)
        {
            this->load = load;
        }

        void setweight(int weight)
        {
            this->weight = weight;
        }

        Truck()
        {
            load = 0;
            weight = 2000;
        }

        Truck(string vehiclename1, int passengers1, int wheels1, float speed1)
        {
            vehiclename = vehiclename1;
            passengers = passengers1;
            wheels = wheels1;
            speed = speed1;
        }

        void displaytrucks()
        {
            cout << "\n\n " << vehiclename << " carries " << passengers << "(including the driver)"
                 << "\n " << vehiclename << " has " << wheels << " wheels and can travel " << speed << "mph";
        }

};

void displayall( Vehicles vehicle[], int size)
{
               for(int i = 0; i < size - 1; i++)
               {
                    vehicle[i].display();
                    cout << "\n";
               }
}
void addvehicle(Vehicles vehicle[], int &max)
{
        string vehiclename;
        int passengers;
        int wheels;
        float speed;

        cout << "\n There are " << max - 1 << " vehicles ";

        cout << "\n\n Vehicle Type:";
        cin >> vehiclename;

        cout << "\n Passengers: ";
        cin >> passengers;

        cout << "\n Number of wheels:";
        cin >> wheels;

        cout << "\n Miles per hour:";
        cin >> speed;

        vehicle[max-1].setall(vehiclename,passengers,wheels,speed);

        max++;
        cout << "\n There are now " << max - 1;

}


void addtruck(Truck truck[], int &current2)
{
        string vehiclename;
        int passengers;
        int wheels;
        float speed;

        cout << "\n There are " << current2 - 1 << " trucks ";

        cout << "\n\n Truck Type:";
        cin >> vehiclename;

        cout << "\n Passengers: ";
        cin >> passengers;

        cout << "\n Number of wheels:";
        cin >> wheels;

        cout << "\n Miles per hour:";
        cin >> speed;

        truck[current2-1].setall(vehiclename,passengers,wheels,speed);

        current2++;

        cout << "\n There are now " << current2 - 1 << " trucks";

}

void change( Vehicles vehicle[], int &index, int current)
{
     int option;
     bool rerun2 = true;
     bool rerun1 = true;
     string vehiclename;
     int passengers;
     int wheels;
     float speed;

     do
    {
    system("cls");
    cout << "\n\n Enter a vehicle class members values to change based on its array index location: ";
    cin >> index;

    cout << "\n There are currently " << current << " Vehicles ";

    cout << "\n\n Vehicle:" << vehicle[index-1].getvehiclename()
         << "\n Passengers: " << vehicle[index-1].getpassengers()
         << "\n Number of wheels:" << vehicle[index-1].getwheels()
         << "\n Speed:" << vehicle[index-1].getspeed();

         do
               {
               cout << "\n\n 1 of 4: Vehicle name "
                    << "\n 2 of 4: Change number of passengers "
                    << "\n 3 of 4: Change number of wheels "
                    << "\n 4 of 4: Change speed "
                    << "\n Make a choice:";
               cin >> option;

               while(option < 1 || option > 4)
               {
                    cout << "\n Invalid selection. Make a selection : ";
                    cin >> option;
               }

               switch(option)
               {
                    case 1:
                        cout << "\n Enter New Vehicle Name:" << vehicle[index-1].getvehiclename() << ":";
                        cin >> vehiclename;
                        vehicle[index-1].setvehiclename(vehiclename);
                        break;

                    case 2:
                        cout << "\n Enter New Number of passengers: "
                             << vehicle[index-1].getpassengers() << ":";
                        cin >> passengers;
                        vehicle[index-1].setpassengers(passengers);
                        break;

                    case 3:
                        cout << "\n Enter New Number of Wheels "
                             << vehicle[index-1].getwheels() << ":";
                        cin >> wheels;
                        vehicle[index-1].setwheels(wheels);
                        break;

                    case 4:
                        cout << "\n Enter New speed: "
                             << vehicle[index-1].getspeed() << ":";
                        cin >> speed;
                        vehicle[index-1].setspeed(speed);
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
}

void settruck( Truck truck[],int &index2, int current2)
{
    int option;
     bool rerun2 = true;
     bool rerun1 = true;
     string vehiclename;
     int passengers;
     int wheels;
     float speed;

     do
    {
   // system("cls");
    cout << "\n\n Enter a vehicle class members values to change based on its array index location: ";
    cin >> index2;

    cout << "\n There are currently " << current2 << " Vehicles ";

    cout << "\n\n Vehicle:" << truck[index2-1].getvehiclename()
         << "\n Passengers: " << truck[index2-1].getpassengers()
         << "\n Number of wheels:" << truck[index2-1].getwheels()
         << "\n Speed:" << truck[index2-1].getspeed();

         do
               {
               cout << "\n\n 1 of 4: Truck name "
                    << "\n 2 of 4: Change number of passengers "
                    << "\n 3 of 4: Change number of wheels "
                    << "\n 4 of 4: Change speed: ";

               cin >> option;

               while(option < 1 || option > 4)
               {
                    cout << "\n Invalid selection. Make a selection : ";
                    cin >> option;
               }

               switch(option)
               {
                    case 1:
                        cout << "\n Enter New Vehicle Name:" << truck[index2-1].getvehiclename() << ":";
                        cin >> vehiclename;
                        truck[index2-1].setvehiclename(vehiclename);
                        break;

                    case 2:
                        cout << "\n Enter New Number of passengers: "
                             << truck[index2-1].getpassengers() << ":";
                        cin >> passengers;
                        truck[index2-1].setpassengers(passengers);
                        break;

                    case 3:
                        cout << "\n Enter New Number of Wheels "
                             << truck[index2-1].getwheels() << ":";
                        cin >> wheels;
                        truck[index2-1].setwheels(wheels);
                        break;

                    case 4:
                        cout << "\n Enter New speed: "
                             << truck[index2-1].getspeed() << ":";
                        cin >> speed;
                        truck[index2-1].setspeed(speed);
                        break;

                    index2++;
               }
                    cout << "\n One(1) to make another change, Zero (0) to exit:";
               cin >> rerun1;
               rerun1 = abs(rerun1);

                } while(rerun1);

               cout << "\n One(1) to make make changes for another student, Zero (0) to exit:";
               cin >> rerun2;
               rerun2 = abs(rerun2);

            } while(rerun2);

}
int main()
{
    bool again = true;
    int max = 5;
    int option;
    int current2 = 4;
    int index;
    string vehiclename;
    int passengers;
    int index2;

    Vehicles vehicle[max];
    Truck truck[current2];

    vehicle[0] = Vehicles("Sedan", 5, 4, 80);
    vehicle[1] = Vehicles("Bicycle", 1, 2, 30);
    vehicle[2] = Vehicles("Unicycle", 1, 1, 15);
    vehicle[3] = Vehicles("Row Boat", 3, 0, 10);

    truck[0] = Truck("Pickup", 2, 4, 65);
    truck[1] = Truck("Van", 2, 6, 10);


    while (again)
    {
        system("cls");
        cout << "\n 1 of 7: Display all vehicles class member\'s values"
             << "\n 2 of 7: Change a Vehicle class member\'s values based on its array index location"
             << "\n 3 of 7: Find a Vehicle class member based on its array index location"
             << "\n 4 of 7: Add a new Vehicle or Truck "
             << "\n 5 of 7: Display the Truck class member values"
             << "\n 6 of 7: Set the Truck member values of Load and Weight"
             << "\n 7 of 7: Quit this application"
             << "\n\n Make a choice:";

        cin >> option;
        option = abs(option);

        switch (option)
        {
            case 1:
                cout << "\n There are " << max - 1 << " vehicles now ";
                displayall(vehicle, max);
                break;
            case 2:
                cout << "\n There are " << max - 1 << " vehicles ";
                change(vehicle, index, max);
                break;
            case 3:
                int choice;
                cout << "\n Enter the employee to find (by index location) There are " << max - 1 << " employees:";
                cin >> choice;
                choice = abs(choice);

                if (choice < 0 || choice > max)
                cout << "\n" << choice << " is not a valid index location. Choose:";

                else
                vehicle[choice - 1].display();

                break;
            case 4:
                int opinion;
                cout << "\n Would you like to add:"
                     << "\n 1 of 2: Vehicle "
                     << "\n 2 of 2: Truck "
                     << "\n Make a choice: ";

                cin >> opinion;

                switch (opinion)
                {
                case 1:

                    addvehicle(vehicle, max);

                    break;
                case 2:
                    addtruck(truck, current2);
                    break;
                }

                break;
            case 5:
                for(int count = 0 ; count < current2; count++)
                {
                truck[count].displaytrucks();

                }


                break;
            case 6:
                settruck(truck,index2, current2);
                break;

            case 7:
                cout << "\n Quitting.....";
                exit(0);
                break;
        }
         cout << "\n\n One(1) to return to main menu, Zero (0) to exit:";
         cin >> again;
         again = abs(again);
    }while (again);
}
