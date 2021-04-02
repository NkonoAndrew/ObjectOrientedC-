// LINKED LIST in C++ (Version III)

#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

struct Node
{  // Pointer Structure
   Node *Previous;
   char Letter;
   Node *Next;
};

int main()
{
   Node *First = NULL;
   Node *Last = NULL;
   Node *Middle = NULL;		// New Node
   Node *TempPrevious;
   Node *TempNext;
   Node *P;
   Node *N; // New node to be inserted between two existing nodes
   int choice, elements = 0;
   char temp, ans = 'y', value[1];
   bool found = false;

   // Create an ENDLESS loop that can only be exited from Option 7
   while (ans == 'y')
   {
	   system("cls");
       cout << "\n1 - INSERT a Letter at the BEGINNING of the LIST";
       cout << "\n2 - INSERT a Letter at the END of the LIST";
       cout << "\n3 - REMOVE a Specific Letter From the LIST";
       cout << "\n4 - TRAVERSE and Display LIST from BEGINNING to END";
       cout << "\n5 - TRAVERSE and Display LIST in REVERSE Order";
	   cout << "\n6 - FIND a Particular Letter in the LIST";
	   cout << "\n7 - INSERT a LETTER in the MIDDLE of the LIST";
       cout << "\n8 - QUIT";
       cout << "\n\nEnter a CHOICE from 1 - 7: ";

       cin >> choice;

	   switch(choice)
       {
	      // Insert Letter at the BEGINNING of the LIST
	      case 1:
	        	P = new Node;
	        	elements = elements + 1;
	        	cout << "\n\nEnter a Letter: ";
				cin >> temp;
		    	P -> Previous = NULL;
		    	P -> Letter = temp;
		    	P -> Next = First;
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

       	  // Insert Letter at the END of the LIST
		  case 2:
	        	P = new Node;
	        	elements = elements + 1;
				// Used this option to insert the "first" element in the linked list
				if (elements == 1)
				   First = NULL;

	        	cout << "\nEnter a Letter: ";
				cin >> temp;
		    	P -> Previous = Last;
		    	P -> Letter = temp;
		    	P -> Next = NULL;
		    	Last = P;

	       		if (First == NULL)
	       		{
            		// We used this option to place the FIRST Node.
		      		First = P;
		      		P -> Previous = NULL;
	       		}
	       		else
	       		{
              		// If we Did NOT use this option to PLACE the
		      		//           FIRST node.
		      		// Adjust Previous Node's "Next" Pointer to the
		      		//   Address of this NEW Last Node
		      		P = P -> Previous;    // Move to the Previous Node
		      		P -> Next = Last;
	       		}
	       		break;
		  // Remove an Element on the Linked List
	 	  case 3:
		 		if(elements > 0)
		 		{
		    		cout << "\n\nEnter a Letter to Find and Delete on the LIST: ";
            		cin >> temp;
		    		P = First;
					// Run an "endless" loop, use the breaks to get out
		 			while(found == false)
					{
		    			if(P -> Letter == temp)
		    			{
		       				cout << "\n\nLetter \"" << P -> Letter << "\" is deleted from List";
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
			   				// Reset Previous Node's "Next" Pointer and
			   				//    Next Node's "Previous" Pointer.

		       				// Determine if Previous was NULL (i.e. we deleted
		       				//    the FIRST node in the LIST.
		      				if(TempPrevious == NULL)
		      				{
               					// Move to adjust NEXT node's pointer
			      				P = TempNext;
			      				P -> Previous = NULL;
			      				First = P;
			      				cout << "\tFirst Element Deleted From List";
								cout << "\n\nHit Any Key to Continue...";
								getch();
								break;
			  				}

		      			    // Determine if Next was NULL (i.e. we deleted
		      			    //    the LAST node in the LIST.
		      			    if(TempNext == NULL)
							{
               				    // Move to adjust PREVIOUS node's pointer
			      			    P = TempPrevious;
			      			    P -> Next = NULL;
			      			    Last = P;
			      			    cout << "\tLast Element Deleted from List";
								cout << "\n\nHit Any Key to Continue...";
								getch();
								break;
							}

		        			// Deleted Node was in the "middle" of the LIST.
		        			// Adjust pointers for the PREVIOUS and NEXT
		        			//    pointers.
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
		      			    // NOT Found, move to the NEXT Node.
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

	  case 4: // Traverse and Display List Elements
	      	if( elements > 0)
	      	{
		      	cout << "\n\nList has " << elements << " elements.\n";
		      	P = First;
		   		while(P -> Next != NULL)
		   		{
			   		cout << P -> Letter << "\t";
			   		P = P -> Next;
		   		}
                cout << P -> Letter;
		      	cout << "  NULL - End of List";
		 	}
		    else
		     	cout << "\nLIST is EMPTY!";

			cout << "\n\nHit Any Key to Continue...";
			getch();
		 	break;

	  case 5: // Traverse and Display List Elements in REVERSE order
		 	if( elements > 0)
	      	{
				cout << "\n\nList has " << elements << " elements.\n";
			  	P = Last;
			  	while(P -> Previous != NULL)
			  	{
			    	cout << P -> Letter << "\t";
			     	P = P -> Previous;
			  	}
		     	cout << P -> Letter;
		     	cout << "  NULL - End of List";
		   	}
		 	else
		    	cout << "\n\nLIST is EMPTY!";

			cout << "\n\nHit Any Key to Continue...";
			getch();
		    break;

	  case 6: // Find a Letter in the LIST

			if(elements > 0)
		 	{
		    		cout << "\n\nEnter a Letter to Find on the LIST: ";
            		cin >> temp;
		    		P = First;

		 			while(found == false)
					{
		    			if(P -> Letter == temp)
		    			{
		       				cout << "\n Letter " << P -> Letter << "\" is IN this List";
							break;
						}
						else
						{
		      				// NOT Found, move to the NEXT Node.
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

	  case 7:	// Insert a NODE in the middle of the LIST
			if(elements > 0)
		 	{
		    		cout << "\n\nEnter a Letter to Find on the LIST: ";
            		cin >> temp;
		    		P = First;

		 			while(found == false)
					{
		    			if(P -> Letter == temp)
		    			{
		       				cout << "\n\nLetter \"" << P -> Letter << "\" is IN this List";
							cout << "\nInserting New Node After this Letter";
							// Record pointers of this Node
			   				TempNext = P -> Next;

							// Create new NODE
							N = new Node;
							elements = elements + 1;
							cout << "\n\nEnter a Letter: ";
							cin >> temp;
							Middle = N;
							N -> Letter = temp;
							// Adjust the Previous Pointer in the New Node
							N -> Previous = P;
							// Adjust Next Pointer in the Previous Node
							P -> Next = N;

							// If the Found Node was the Last Node, This New Node will be the Last Node
							if (TempNext == NULL)
							{
								N -> Next = NULL;
								Last = N;
							}
							else
							{
								// Pick up the Next Node and Adjust it to point to the New Node
								TempPrevious = P -> Previous;
								P -> Previous = Middle;
								N -> Next = TempNext;
							}

							break;
						}
						else
						{
		      				// NOT Found, move to the NEXT Node.
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
				break;
			}

			break;

	  case 8:
			system("cls");
	      	cout << "\nExiting LINKED LIST Program!\n\n";
	      	exit(0);

	  default:
		    system("cls");
	      	cout << "\""<< value << "\" is NOT a Valid value...Enter a Numeric INTEGER!\n\n";
			cout << "\n\nHit Any Key to Continue...";
			getch();
     }
   }

   return 0;
}
