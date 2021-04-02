#include <conio.h>
#include <iomanip>
#include <iostream>
#include<stdlib.h>
#include <time.h>
#include<sstream>
#include <string>
#include<chrono>

using namespace std;
using namespace std::chrono;

int main()
{
    auto start = high_resolution_clock::now();

    char again = 'y';
    string demo;
    string customerid;
    char first, second;
    int third;
    const int idsize = 5;
    stringstream converter;


    while (again == 'y')
    {

    cout << "\n Valid Customer ID Rules: "
         << "\n  1 - A, K, S - Followed by B, C, D, Followed by 101 to 110 "
         << "\n  2 - B, H, N - Followed by A, F, G, H, Followed by 113 to 118 or 213 or 220 or 560 or 890 "
         << "\n  3 - C or T - Followed by K, L, Z, Followed by 134, 138, 145 or 246 "
         << "\n  4 - M, O, Z - Followed by A, D, F, Followed by 177 to 181 or 333 to 335 ";

    cout << "\n\n Enter the customer ID to validate: ";
    getline(cin,customerid);



    if (customerid.length() == idsize)
    {
        system("cls");
        first = customerid[0];
        first = toupper(first);
        second = customerid[1];
        second = toupper(second);

        demo = "";
        for (int n = 2; n < 5; n++)
        {
            demo += customerid.at(n);
        }
        converter.clear();
        converter.str(demo);
        converter >> third;

    switch (first)
    {
        case 'A':
        case 'K':
        case 'S':
            switch (second)
            {
               case 'B':
               case 'C':
               case 'D':
                   switch (third)
                   {
                        case 101:
                        case 102:
                        case 103:
                        case 104:
                        case 105:
                        case 106:
                        case 107:
                        case 108:
                        case 109:
                        case 110:
                            cout << "\n Customer ID " << customerid << " is valid ";
                             break;
                            default:
                            cout << "Customer ID is invalid.";

                   }
                   break;
                        default:
                            cout << "Customer ID is invalid";
            }
        break;

        case 'B':
        case 'H':
        case 'N':
            switch (second)
            {
               case 'A':
               case 'F':
               case 'G':
               case 'H':
                   switch (third)
                   {
                        case 113:
                        case 114:
                        case 115:
                        case 116:
                        case 117:
                        case 118:
                        case 213:
                        case 220:
                        case 560:
                        case 890:
                            cout << "\n Customer id " << customerid << " is valid ";
                              break;
                        default:
                            cout << "Customer ID is invalid";
                   }
                break;
                default:
                    cout << "\n The ID " << customerid << " is not valid ";
            }
            break;

        case 'C':
        case 'T':

            switch (second)
            {
               case 'K':
               case 'L':
               case 'Z':
                   switch (third)
                   {
                        case 134:
                        case 138:
                        case 145:
                        case 246:
                            cout << "\n Customer id " << customerid << " is valid ";
                            break;
                            default:
                            cout << "\n Customer id " << customerid << " invalid ";
                  }
                break;
                default:
            cout << "\n The ID " << customerid << " is not valid ";
            }
        break;

        case 'M':
        case 'O':
        case 'Z':
            switch (second)
            {
               case 'A':
               case 'D':
               case 'F':
                   switch (third)
                   {
                        case 177:
                        case 181:
                        case 333:
                        case 335:
                            cout << "\n Customer ID " << customerid << " is valid ";
                            break;
                            default:
                                cout << "\n The ID " << customerid << " is not invalid ";

                   }
                 break;
                 default:
            cout << "\n The ID " << customerid << " is not invalid ";

            }
            break;
            default:
            cout << "\n The ID " << customerid << " is not invalid ";
        }

      }
        else
        {
        cout << "\n The ID " << customerid << " is not of valid length,"
             << "please enter 2 letters followed by 3 numbers..";
         }

            cout << "\n\n Would you like to run again yes(y) or no(n)...";
            cin >> again;
            again = tolower(again);
            cin.ignore();
            system("cls");
            if(again == 'N' || again == 'n')
            {
                cout << "Hit any key to continue...";
                getch();
                break;
            }
    }
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop-start);

//    cout << "\n" << duration.count;


}
