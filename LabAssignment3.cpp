#include <conio.h>
#include <iomanip>
#include <iostream>
#include<stdlib.h>
#include<math.h>


using namespace std;

int main()
{
    string stringvalue;
    char again = 'y', text, blank = ' ';

    while (again == 'y')
    {
     int a_count = 0, e_count = 0, o_count = 0, i_count = 0, u_count = 0;
     int length;
     int nonvowel = 0;
     blank = ' ';

        cout << "\n Enter a string (including blanks): ";
        getline(cin, stringvalue);
        getline(cin, stringvalue);


        length = stringvalue.length();
        for (int n = 0; n < length; n++)
       {
           text = (char)stringvalue[n];

           if ( text != blank) // Does not count the blanks
           {
               text = toupper(text);
               char upper = toupper(text);

               switch (upper)
               {
               case 'A':
                    a_count++;
                    break;
               case 'E':
                    e_count++;
                    break;
               case 'I':
                    i_count++;
                    break;
               case 'O':
                    o_count++;
                    break;
               case 'U':
                    u_count++;
                    break;
               default:
                    nonvowel++;
                    break;
               }
           }
       }
       cout << "\n There are...."
                    << "\n " << a_count << " A's"
                    << "\n " << e_count << " E's"
                    << "\n " << i_count << " I's"
                    << "\n " << o_count << " O's"
                    << "\n " << u_count << " U's"
                    << "\n " << nonvowel << " non vowels " << " (does not count blanks) ";


       cout << "\n Run again yes(y) or no(n)...";
       cin >> again;
       again = tolower(again);
      // cin.ignore();
       system("cls");
  }
}
