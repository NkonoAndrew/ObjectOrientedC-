#include<iostream>
#include<conio.h>
#include <stdlib.h>
using namespace std;

struct Node
{
    Node *Previous;
    int Letter;
    Node *Next;
};

int main()
{
    Node *First = NULL;
    Node *Last = NULL;
    Node *TempPrevious;
    Node *TempNext;
    Node *P;
    //Node *N;
    int choice, elements = 0, count = 0;;
    char again = 'y';
    int temp;
    bool found = false;

    while ( again == 'y')
    {
        system("cls");
       cout << "\n 1 of 9: Insert an Integer at the BEGINNING of the LIST";
       cout << "\n 2 of 9: Insert an Integer at the END of the LIST";
       cout << "\n 3 of 9: Remove and Integer From the LIST";
       cout << "\n 4 of 9: Traverse and Display LIST from BEGINNING to END";
       cout << "\n 5 of 9: Traverse and Display LIST in REVERSE Order";
	   cout << "\n 6 of 9: Find a Particular Integer in the LIST";
	   cout << "\n 7 of 9: Find and replace an integer in the LIST";
	   cout << "\n 8 of 8: Display the Last and First";
       cout << "\n 9 of 9: QUIT";

       cout << "\n\nEnter a choice from 1 - 7: ";
       cin >> choice;

       switch (choice)
       {
       case 1:
            P = new Node;
            cout << "\n\n Node created at " << P;
            elements++;
            cout << "\n\n Enter an integer:";
            cin >> temp;

            P->Previous = NULL;
            P->Letter = temp;
            P->Next = First;
            First = P;

            if (elements == 1)
            {  // This is the First Node in the List
                Last = P;
            }
            if (elements > 1)
            {  // Set the Last Node's "Previous" Pointer
                P = P -> Next;
                P -> Previous = First;
            }

           break;
       case 2:
           P = new Node;
	        	elements++;
				if (elements == 1)
				   First = NULL;

	        	cout << "\nEnter an Integer: ";
				cin >> temp;
		    	P -> Previous = Last;
		    	P -> Letter = temp;
		    	P -> Next = NULL;
		    	Last = P;

	       		if (First == NULL)
	       		{
		      		First = P;
		      		P -> Previous = NULL;
	       		}
	       		else
	       		{
                    P -> Previous = P;
		      		Last = P -> Next;
	       		}
	       		break;
       case 3:

           if(elements > 0)
		 		{
		    		cout << "\n\nEnter a Letter to Find and Delete on the LIST: ";
            		cin >> temp;
		    		P = First;
		 			while(found == false)
					{
		    			if(P -> Letter == temp)
		    			{
		       				cout << "\n\n Number \"" << P -> Letter << "\" will be deleted from List";
			   				elements = elements - 1;
							if (elements == 0)
							{
								delete P;
								First = NULL;
								Last = NULL;
								cout << "\n\nHit Any Key to Continue...";
								getch();
								break;
							}
			   				TempPrevious = P -> Previous;
			   				TempNext = P -> Next;
			   				delete P;

		      				if(TempPrevious == NULL)
		      				{
			      				P = TempNext;
			      				P -> Previous = NULL;
			      				First = P;
			      				cout << "\tFirst Element Deleted From List";
								cout << "\n\nHit Any Key to Continue...";
								getch();
								break;
			  				}

		      			    if(TempNext == NULL)
							{
			      			    P = TempPrevious;
			      			    P -> Next = NULL;
			      			    Last = P;
			      			    cout << "\tLast Element Deleted from List";
								cout << "\n\nHit Any Key to Continue...";
								getch();
								break;
							}

		      			    if((TempPrevious != NULL) && (TempNext != NULL))
							{
			     			    P = TempPrevious;
			     			    P -> Next = TempNext;
			     			    P = TempNext;
			     			    P -> Previous = TempPrevious;
								cout << "\n\nHit Any Key to Continue...";
								getch();
								break;
							}

						}
		    			else
						{

		      				P = P -> Next;
			  				if ((P -> Next == NULL) && (P -> Letter != temp))
			  				{
			   					cout << "\n\n\"" << temp << "\" is NOT in the LIST!";
								cout << "\n\nHit Any Key to Continue...";
								getch();
			   					break;
			  				}
						}
					}
       		}
	       	else
			{
		    	cout << "\n\nLIST is EMPTY!";
				cout << "\n\nHit Any Key to Continue...";
				getch();
			}
		  	break;

       case 4:
           if( elements > 0)
	      	{
		      	cout << "\n\nList has " << elements << " elements \n";
		      	P = First;

		      	while(P!= NULL)
		   		{
		   		    if ( P->Next != NULL)
			   		{
			   		    cout << P -> Letter << " at Memory Address " << P << " Pointing to " << P->Next << "\n";
                    }

			   		else
			   		{
			   		    cout << P -> Letter << " at Memory Address " << P << " Pointing to " << "Null "<< "\n";
                    }
                    P = P -> Next;
		   		}
		 	}
		    else
		     	cout << "\nLIST is EMPTY!";

			cout << "\n\nHit Any Key to Continue...";
			getch();
           break;

       case 5:
           if (elements > 0)
           {
               cout << "\n The list has " << elements << " elements \n";
               P = Last;
               while (P!= NULL)
               {
                    if (P-> Next != NULL)
                    {
                        cout << P -> Letter << " at Memory Address " << P << " Pointing to " << P->Next << "\n";
                    }
                    else
                    {
                        cout << P -> Letter << " at Memory Address " << P << " Pointing to " << "Null \n";
                    }
                    P = P -> Previous;
               }
           }
           else
            cout << "\n LIST is Empty!";
			cout << "\n\nHit Any Key to Continue...";
			getch();
			break;

       case 6:
           if(elements > 0)
		 	{
		    		cout << "\n Enter an Integer to Find in the LIST: ";
            		cin >> temp;
		    		P = First;

		 			while(found == false)
					{
		    			if(P -> Letter == temp)
		    			{
		       				cout << "\n Number \"" << P -> Letter << "\" is IN this List";
							break;
						}
						else
						{
		      				P = P -> Next;
			  				if ((P -> Next == NULL) && (P -> Letter != temp))
			  				{
			   					cout << "\n\n\"" << temp << "\" is NOT in the LIST!";
			   					break;
			  				}
						}
					}

       		}
	       	else
		    	cout << "\n\nLIST is EMPTY!";

			cout << "\n\nHit Any Key to Continue...";
			getch();
        break;

       case 7:
           if(elements > 0)
		 	{
		    		cout << "\n Enter an Integer to Find in the LIST: ";
            		cin >> temp;
            		temp = toupper(temp);
		    		P = First;

		 			while(found == false)
					{
		    			if(P -> Letter == temp)
		    			{
		       				cout << "\n Number \"" << P -> Letter << "\" is IN this List";
		       				cout << "\n Enter a new Letter:";
		       				cin >> temp;
		       				P->Letter = temp;
							break;
						}
						else
						{
		      				P = P -> Next;
			  				if ((P -> Next == NULL) && (P -> Letter != temp))
			  				{
			   					cout << "\n\n\"" << temp << "\" is NOT in the LIST!";
			   					break;
			  				}
						}
					}

       		}
	       	else
		    	cout << "\n\nLIST is EMPTY!";
		    	break;

       case 8:
        if ( elements > 0)
        {
            P = First;
        cout << "\n First Element is " << P->Letter << " at Memory Location " << P;
            P = Last;
        cout << "\n Last Element is " << P->Letter << " at Memory Location " << P;
        }
        else
            cout << "\n LIST is Empty";
        break;

       case 9:
           cout << "\n Quitting....";
           exit(0);


       }
        cout << "\n\n Would you like to run again yes(y) or no(n)...";
        cin >> again;
        again = tolower(again);
        system("cls");

    }
}
