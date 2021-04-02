#include <conio.h>
#include <iomanip>
#include <iostream>
#include<stdlib.h>
#include <math.h>
#include <time.h>

using namespace std;

// Sort prototypes
void sort1(int *[], int n);
void sort2(int *[], int n);

int main()
{
    const int members = 15;
    int numbers[members] = {0};
    char again = 'y';

    //Random numbers

    srand((unsigned) time (NULL));

    //Two arrays of pointers
    int *pArray1[members];
    int *pArray2[members];

    while ( again == 'y')
    {
    // Loading Array and displaying elements
    cout << "\n\n The contents of the array are..";
    for ( int i = 0; i < members; i++)
    {
        numbers[i] = rand()% 100 + 1;
        cout << "\n Location # " << i << " \t" << numbers[i];
    }

    for ( int i = 0; i < members; i++)
    {
        pArray1[i] = &numbers[i];
        pArray2[i] = &numbers[i];
    }

    // Contents via shadow pointers
    cout << "\n\n\n  The elements of the array via shadow pointers are...";
     for ( int i = 0; i < members; i++)
     {
         cout << "\n Location # " << i << " \t" << * pArray1[i];
     }

     //Calling the first sorting function
     sort1(pArray1, members);
     cout << "\n\n\n Sorting using the shadow array (Ascending Order)...";

     for ( int i = 0; i < members; i++)
     {
         cout << "\n Location # " << i << " \t" << *pArray1[i] << " at memory location " << pArray1[i];
     }

     //Calling the second sorting function
     sort2(pArray2, members);
     cout << "\n\n\n Sorting using the shadow array (Descending Order)...";

     for ( int i = 0; i < members; i++)
     {
         cout << "\n Location # " << i << " \t" << *pArray2[i] << " at memory location " << pArray2[i];
     }



        cout << "\n\n Would you like to run again...Yes(y) or No(n)...";
        cin >> again;
        again = tolower(again);
        system("cls");
    }
}
void sort1(int *line [], int num)
{
    int *hold;

    for (int k = 1; k <= num - 1; k++)
    {
        for ( int q = 0; q <= num - 2; q++)
        {
            if (*line[q] >= *line[q+1])
            {
                hold = line[q];
                line[q] = line[q+1];
                line[q+1] = hold;
            }
        }
    }
}
void sort2( int *line2 [], int numb)
{
    int *hold2;

    for (int w = 1; w <= numb - 1; w++)
    {
        for ( int g = 0; g <= numb - 2; g++)
        {
            if (*line2[g] <= *line2[g+1])
            {
                hold2 = line2[g];
                line2[g] = line2[g+1];
                line2[g+1] = hold2;
            }
        }
    }
}
