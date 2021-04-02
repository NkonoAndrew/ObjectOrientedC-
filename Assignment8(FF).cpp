//Loading linked list in data file
#include <conio.h>
#include <iomanip>
#include <iostream>
#include<stdlib.h>
#include<fstream>
#include <string>
using namespace std;

struct Node
{
   string name;
   int value;
   Node *Previous;
   Node *Next;
};

int main()
{
    char again = 'y';
    bool found = false;
    bool rerun = true;
    int choice;
    int elements = 0, index = 0;
    int option;
    int count = 1;
    Node *First = NULL;
    Node *Middle = NULL;
    Node *Last = NULL;
    Node *TempPrevious;
    Node *TempNext;
    Node *P;
    Node *N;
    Node states;
    string tempstr;
    int tempvalue;


        ifstream inFile("States2.dat",ios::in);
        if (!inFile)
        {
            cout << "\nSorry, the data file \"States2.dat\" was not found on this drive";
            cout << "\n\nHit Any Key to continue";
        }
        inFile >> tempstr >> tempvalue;

        while(!inFile.eof())
        {
                P = new Node;
		    	P-> Previous = Last;
		    	P->name = tempstr;
		    	P->value = tempvalue;
                P-> Next = NULL;
		    	Last = P;

	       		if (First == NULL)
	       		{
		      		First = P;
		      		P -> Previous = NULL;
	       		}
	       		else
	       		{
                    P = P -> Previous;
		      		P -> Next = Last;
	       		}
                elements = elements + 1;
                inFile >> tempstr >> tempvalue;

            }
             inFile.close();

    while ( again == 'y')
    {
            system("cls");
           cout << "\n 1 of 9:Add a Node to the front of the list"
                << "\n 2 of 9:Add a Node to the rear of the list"
                << "\n 3 of 9:Add a Node in the middle of the list "
                << "\n 4 of 9:Display all Nodes from front to the last node"
                << "\n 5 of 9:Display all Nodes from the last node to the first"
                << "\n 6 of 9:Search for one Node based on State Name"
                << "\n 7 of 9:Search for one Node and change any ONE of the fields"
                << "\n 8 of 9:Delete a node based on State Name"
                << "\n 9 of 9:Quit"
                << "\n Make a choice:";
            cin >>  choice;

            switch (choice)
            {
            case 1:
                {
                    P = new Node;
                    cout << "\n\n Node created at " << P;
                    elements = elements + 1;

                    cout << "\n\n 1 of 2: Enter a state name:";
                    cin >> tempstr;

                    cout << "\n 2 of 2: Enter a value:";
                    cin >> tempvalue;

                    P->Previous = NULL;
                    P->name = tempstr;
                    P->value = tempvalue;
                    P->Next = First;
                    First = P;

                    if (elements == 1)
                    {
                        Last = P;
                    }
                    else
                    {
                        P = P->Next;
                        P->Previous = First;
                    }

                break;
            }
            case 2:
                {
                P = new Node;
                cout << "\n Node created at " << P;
                elements = elements + 1;
                if (elements == 1)
                {
                    First = NULL;
                }

	        	cout << "\n\n 1 of 2: Enter a state name:";
                cin >> tempstr;

                cout << "\n 2 of 2: Enter a value:";
                cin >> tempvalue;

		    	P->Previous = Last;
		    	P->name = tempstr;
		    	P->value = tempvalue;
		    	P->Next = NULL;
		    	Last = P;

	       		if (First == NULL)
	       		{
		      		First = P;
		      		P -> Previous = NULL;
	       		}
	       		else
	       		{
                    P = P->Previous;
		      		P->Next = Last;
                }
                break;
            }
            case 3:
                //Insert in the middle of the list
            if(elements > 0)
		 	{
                cout << "\n\n Inserting Node...Enter state name to insert node after:";
                getline(cin, tempstr);
                getline(cin, tempstr);
                P = First;

                while(found == false)
                {
                    if(P->name == tempstr)
                    {
                        cout << "\n\n \"" << P->name << "\" is IN this List";
                        cout << "\n\nInserting New Node After this " << P->name;
                        TempNext = P->Next;

                        // Create new NODE to be inserted
                        N = new Node;
                        elements++;

                        cout << "\n Enter a state name: ";
                        getline(cin, tempstr);

                        cout << "\n Enter a value:";
                        cin >> tempvalue;

                        Middle = N;
                        N->name = tempstr;
                        N->value = tempvalue;
                        N->Previous = P;
                        P -> Next = N;

                        if (TempNext == NULL)
                        {
                            N->Next = NULL;
                            Last = N;
                        }
                        else
                        {
                            TempPrevious = P->Previous;
                            P->Previous = Middle;
                            N->Next = TempNext;
                        }
							break;
						}
						else
						{
		      				P = P->Next;
			  				if ((P->Next == NULL) && (P->name != tempstr))
			  				{
			   					cout << "\n\n\"" << tempstr << "\" is NOT in the LIST!";
			   					break;
			  				}
						}
					}
       		}
	       	else

		    	cout << "\n\nLIST is EMPTY!";
				break;

            case 4:
            {
            cout << "\n\nList has " << elements << " elements \n";
            P = First;

            while(P!= NULL)
            {
                cout <<"\nIndex#"<< index << setw(12) << P->name << setw(5)<< P->value << setw(5)<< " at " << setw(7)<< P << " pointing to " << setw(7)<< P->Next;
                P = P->Next;
                index++;
            }
            break;
            }

            case 5:
            {
               cout << "\n The list has " << elements << " elements \n";
                index = elements - 1;
               P = Last;
               while (P!= NULL)
               {
                    cout <<"\nIndex#" << index << setw(12) << P->name << setw(5)<< P->value << setw(5)<< " at " << setw(7)<< P << " pointing to " << setw(7)<< P->Next;
                    P = P->Previous;

                    index--;
               }
               break;
            }
			case 6:
            if(elements > 0)
		 	{
		    		cout << "\n Enter a State to Find in the LIST: ";
            		getline(cin, tempstr);
            		getline(cin, tempstr);
		    		P = First;

		 			while(found == false)
					{
		    			if(P->name == tempstr)
		    			{
		       				cout << "\n State \"" << P->name << "\" is IN this List";
                            break;
						}
						else
						{
		      				P = P->Next;
			  				if ((P->Next == NULL) && (P->name != tempstr))
			  				{
			   					cout << "\n\n\"" << tempstr << "\" is NOT in the LIST!";
			   					break;
			  				}
						}
					}

                }
	       	else
		    	cout << "\n\nLIST is EMPTY!";

        break;

            case 7:
                if(elements > 0)
                {
		    		cout << "\n Enter an State to Find in the LIST: ";
            		getline(cin,tempstr);
            		getline(cin,tempstr);
		    		P = First;

		 			while(found == false)
					{
                        if(P->name == tempstr)
                        {

                            cout << "\n State \"" << P->name << "\" is IN this List";

		       				cout << "\n 1 of 2: Change the state name:"
                                 << "\n 2 of 2: Change the value:"
                                 << "\n Make a choice:";
                            cin >> option;

                                 switch (option)
                                 {
                                 case 1:
                                     cout << "\n Enter the new state name:";
                                     cin.ignore();
                                    //getline(cin, tempstr);
                                    getline(cin, tempstr);

                                     P->name = tempstr;
                                    break;
                                 case 2:
                                     cout << "\n Enter the new value:";
                                     cin >> tempvalue;
                                     P->name = tempvalue;
                                    break;
                                }
                                break;
						}
						else
						{
		      				P = P->Next;
			  				if ((P->Next == NULL) && (P->name != tempstr))
			  				{
			   					cout << "\n\n\"" << tempstr << "\" is NOT in the LIST!";
			   					break;
			  				}
						}
					}

       		}
	       	else
		    	cout << "\n\nLIST is EMPTY!";
		    	break;
            case 8:
                if(elements > 0)
		 		{
		    		cout << "\n\nEnter a State to Find and Delete on the LIST: ";
            		getline(cin, tempstr);
            		getline(cin, tempstr);
		    		P = First;
		 			while(found == false)
					{
		    			if(P->name == tempstr)
		    			{
		       				cout << "\n \"" << P->name << "\" will be deleted from List";
			   				elements = elements - 1;

			   				TempPrevious = P -> Previous;
			   				TempNext = P -> Next;
			   				delete P;

		      				if(TempPrevious == NULL)
		      				{
			      				P = TempNext;
			      				P -> Previous = NULL;
			      				First = P;
			      				cout << "\t(First Element Deleted From List)";
								break;
			  				}

		      			    if(TempNext == NULL)
							{
			      			    P = TempPrevious;
			      			    P -> Next = NULL;
			      			    Last = P;
			      			    cout << "\t(Last Element Deleted from List)";
								break;
							}

		      			    if((TempPrevious != NULL) && (TempNext != NULL))
							{
			     			    P = TempPrevious;
			     			    P -> Next = TempNext;
			     			    P = TempNext;
			     			    P -> Previous = TempPrevious;
								cout << "\n\nHit Any Key to Continue...";

								break;
							}
						}
		    			else
						{
		      				P = P->Next;
			  				if ((P->Next == NULL) && (P->name != tempstr))
			  				{
			   					cout << "\n\n\"" << tempstr << "\" is NOT in the LIST!";
			   					break;
			  				}
						}
					}
       		}
	       	else
			{
		    	cout << "\n\nLIST is EMPTY!";
			}
		  	break;

		  	case 9:
                cout << "\n Quitting....";
                exit(0);

            }


        cout << "\n\n Would you like to run again yes(y) or no(n)...";
        cin >> again;
        again = tolower(again);
        system("cls");
        index = 0;
        cin.ignore();
        cin.clear();
    }

        fstream outFile("States2.dat", ios::out);
        P = First;
        while(P!= NULL)
        {
            if ( P->Next != NULL)
            {
                outFile << P->name << " " << P->value << "\n";
            }
            else
            {
                outFile << P->name << " " << P->value << "\n";
            }
            P = P->Next;
        }
        outFile.close();

        P = Last;
        while(P!= NULL)
        {
            if ( P->Next != NULL)
            {
                outFile << P->name << " " << P->value << "\n";
            }
            else
            {
                outFile << P->name << " " << P->value << "\n";
            }
            P = P->Previous;
        }
        outFile.close();



}

