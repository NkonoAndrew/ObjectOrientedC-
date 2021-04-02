#include <iostream>
#include <fstream>
#include <cstdlib>
#define MAX 100 // Constant for maximum number of employees
using namespace std;
// Defines a structure Employee
struct Employee
{
// Data member to store employee data
string id;
string firstName;
string lastName;
float hour;
float payRatePerHour;
float taxRate;
float gross;
float tax;
float net;
};// End of structure
// Function to write employee records to file
void writeData(Employee emp[], int len)
{
// ofstream object declared
ofstream fWrite;
// Opens the file for writing
fWrite.open("personnel1.txt");
// Checks if the file unable to open for writing display's error message with file name
if(!fWrite)
{
cout<<"\n ERROR: Unable to open the file for writing.";
exit(0);
}// End of if condition
// Loops till number of records
for(int x = 0; x < len; x++)
{
// Checks if loop value is equals to number of records -1 (last record)
if(x == len - 1)
// Writes current employee information with out new line character
fWrite<<emp[x].id<<" "<<emp[x].firstName<<" "<<emp[x].lastName<<" "<<emp[x].hour<<" "<<emp[x].payRatePerHour<<" "<<emp[x].taxRate;
// Otherwise not last record
// Writes current employee information with out new line character
else
fWrite<<emp[x].id<<" "<<emp[x].firstName<<" "<<emp[x].lastName<<" "<<emp[x].hour<<" "<<emp[x].payRatePerHour<<" "<<emp[x].taxRate<<endl;
}// End of for loop
}// End of function
// Function to read employee information and stores it in emp array of objects
int readFile(Employee emp[])
{
// Record counter
int recordCounter = 0;
// ifstream object declared
ifstream fRead;
// Opens the file for reading
fRead.open("personnel1.txt");
// Checks if the file unable to open for reading display's error message with file name
if(!fRead)
{
cout<<"\n ERROR: Unable to open the file for reading.";
exit(0);
}// End of if condition
// Loops till end of the file
while(!fRead.eof())
{
// Extracts id from the file and stores at recordCounter index position of emp array
fRead>>emp[recordCounter].id;
// Extracts first name from the file and stores at recordCounter index position of emp array
fRead>>emp[recordCounter].firstName;
// Extracts last name from the file and stores at recordCounter index position of emp array
fRead>>emp[recordCounter].lastName;
// Extracts hours worked from the file and stores at recordCounter index position of emp array
fRead>>emp[recordCounter].hour;
// Extracts pay rate from the file and stores at recordCounter index position of emp array
fRead>>emp[recordCounter].payRatePerHour;
// Extracts tax rate from the file and stores at recordCounter index position of emp array
fRead>>emp[recordCounter].taxRate;
// Calculates gross pay
emp[recordCounter].gross = (emp[recordCounter].hour * emp[recordCounter].payRatePerHour);
// Calculates tax
emp[recordCounter].tax = (emp[recordCounter].gross * emp[recordCounter].taxRate / 100.0);
// Calculate net pay
emp[recordCounter].net = (emp[recordCounter].gross - emp[recordCounter].tax);
// Increase the student counter by one
recordCounter++;
}// End of while loop
// Closes the file
fRead.close();
// Returns number of records
return recordCounter;
}// End of function
// Function to display menu, accepts user choice, return user choice
int menu()
{
// To store choice
int ch;
// Displays menu
cout<<"\n ******************* MENU *************************** ";
cout<<"\n 1 - Display All Employees";
cout<<"\n 2 - Find One Particular Employee";
cout<<"\n 3 - Add a New Employee";
cout<<"\n 4 - Quit";
cout<<"\n ********************************************** ";
// Accepts user choice
cout<<"\n Enter an Option (1 - 4): ";
cin>>ch;
// Returns user choice
return ch;
}// End of function
// Function to display all employees information
void displayAll(Employee emp[], int len)
{
// Displays total number of employees
cout<<endl<<" "<<len<<" Total Employees: ";
// Loops till number of employees
for(int x = 0; x < len; x++)
{
// Displays each employee information
cout<<"\n\n Employee #"<<(x + 1)<<"\t Employee ID "<<emp[x].id;
cout<<endl<<" "<<emp[x].firstName<<", "<<emp[x].lastName;
cout<<"\n Hours Worked: "<<emp[x].hour;
cout<<"\n Employee Pay Rate: $"<<emp[x].payRatePerHour;
cout<<"\n Employee Tax Rate: "<<emp[x].taxRate<<"%";
cout<<"\n Gross Pay \t $"<<emp[x].gross;
cout<<"\n Less Tax \t $"<<emp[x].tax;
cout<<"\n Net Pay \t $"<<emp[x].net;
}// End of for loop
}// End of function
// Function to add a employee record
void addEmployee(Employee emp[], int &len)
{
// Displays number of records out of maximum capacity
cout<<"\n Record #"<<len<<" of "<<MAX;
// Checks if current record length is equals to maximum then display error message
if(len == MAX)
cout<<"\n Insufficient Memory.";
// Otherwise add the record
else
{
// Accepts employee data and adds it to len index position of emp array
cout<<"\n Enter Employee ID: ";
cin>>emp[len].id;
cout<<"\n Enter Employee First Name: ";
cin>>emp[len].firstName;
cout<<"\n Enter Employee Last Name: ";
cin>>emp[len].lastName;
cout<<"\n Enter Hours Worked: ";
cin>>emp[len].hour;
cout<<"\n Enter Pay Rate Per Hour: ";
cin>>emp[len].payRatePerHour;
cout<<"\n Enter Tax Rate: ";
cin>>emp[len].taxRate;
// Calculates gross pay
emp[len].gross = (emp[len].hour * emp[len].payRatePerHour);
// Calculates tax
emp[len].tax = (emp[len].gross * emp[len].taxRate / 100.0);
// Calculates net pay
emp[len].net = (emp[len].gross - emp[len].tax);
// Increase the record counter by one
len++;
// Displays current record status out of maximum capacity
cout<<"\n Record Added Successfully. \n Records "<<len<<" of "<<MAX;
}// End of else
}// End of function
// Function to display a particular employee information
void findEmployee(Employee emp[], int len)
{
int position;
// Accepts index position
cout<<"\n Find an Employee By Its Index in the Array: ";
cout<<"\n Find an Employee By Its Index (0 to "<<(len - 1)<<"): ";
cin>>position;
// Displays employee information at entered index position
cout<<"\n\n Index Location "<<position<<" of "<<(len - 1);
cout<<"\n Employee ID: "<<emp[position].id;
cout<<endl<<" "<<emp[position].firstName<<", "<<emp[position].lastName;
cout<<"\n Hours Worked: "<<emp[position].hour<<" @$"<<emp[position].payRatePerHour;
cout<<"\n Employee Tax Rate @"<<emp[position].taxRate<<"%";
cout<<"\n Gross Pay \t $"<<emp[position].gross;
cout<<"\n Less Tax \t $"<<emp[position].tax;
cout<<"\n Net Pay \t $"<<emp[position].net;
}// End of function
// main function definition
int main()
{
// Creates an array of object of structure Employees of size MAX
Employee employee[MAX];
// Calls the function to read file and stores data in employee array of object
// Stores the return value as number of records
int len = readFile(employee);
// Loops till user choice is not 4
do
{
// Calls the function menu() to accept user choice
// Based on the return value of the user choice calls the appropriate function
switch(menu())
{
case 1:
// Calls the function to display all employee information
displayAll(employee, len);
break;
case 2:
// Calls the function to display a employee information
findEmployee(employee, len);
break;
case 3:
// Calls the function to add an employee
addEmployee(employee, len);
break;
case 4:
// Calls the function to write data to file
writeData(employee, len);
exit(0);
break;
default:
cout<<"\n Invalid choice! Try again.";
}// End of switch - case
}while(1); // End of do - while loop
}// End of main function
// Increase the student counter by one
recordCounter++;
}// End of while loop
// Closes the file
fRead.close();
// Returns number of records
return recordCounter;
}// End of function
// Function to display menu, accepts user choice, return user choice
int menu()
{
// To store choice
int ch;
// Displays menu
cout<<"\n ******************* MENU *************************** ";
cout<<"\n 1 - Display All Employees";
cout<<"\n 2 - Find One Particular Employee";
cout<<"\n 3 - Add a New Employee";
cout<<"\n 4 - Quit";
cout<<"\n ********************************************** ";
// Accepts user choice
cout<<"\n Enter an Option (1 - 4): ";
cin>>ch;
// Returns user choice
return ch;
}// End of function
// Function to display all employees information
void displayAll(Employee emp[], int len)
{
// Displays total number of employees
cout<<endl<<" "<<len<<" Total Employees: ";
// Loops till number of employees
for(int x = 0; x < len; x++)
{
// Displays each employee information
cout<<"\n\n Employee #"<<(x + 1)<<"\t Employee ID "<<emp[x].id;
cout<<endl<<" "<<emp[x].firstName<<", "<<emp[x].lastName;
cout<<"\n Hours Worked: "<<emp[x].hour;
cout<<"\n Employee Pay Rate: $"<<emp[x].payRatePerHour;
cout<<"\n Employee Tax Rate: "<<emp[x].taxRate<<"%";
cout<<"\n Gross Pay \t $"<<emp[x].gross;
cout<<"\n Less Tax \t $"<<emp[x].tax;
cout<<"\n Net Pay \t $"<<emp[x].net;
}// End of for loop
}// End of function
// Function to add a employee record
void addEmployee(Employee emp[], int &len)
{
// Displays number of records out of maximum capacity
cout<<"\n Record #"<<len<<" of "<<MAX;
// Checks if current record length is equals to maximum then display error message
if(len == MAX)
cout<<"\n Insufficient Memory.";
// Otherwise add the record
else
{
// Accepts employee data and adds it to len index position of emp array
cout<<"\n Enter Employee ID: ";
cin>>emp[len].id;
cout<<"\n Enter Employee First Name: ";
cin>>emp[len].firstName;
cout<<"\n Enter Employee Last Name: ";
cin>>emp[len].lastName;
cout<<"\n Enter Hours Worked: ";
cin>>emp[len].hour;
cout<<"\n Enter Pay Rate Per Hour: ";
cin>>emp[len].payRatePerHour;
cout<<"\n Enter Tax Rate: ";
cin>>emp[len].taxRate;
// Calculates gross pay
emp[len].gross = (emp[len].hour * emp[len].payRatePerHour);
// Calculates tax
emp[len].tax = (emp[len].gross * emp[len].taxRate / 100.0);
// Calculates net pay
emp[len].net = (emp[len].gross - emp[len].tax);
// Increase the record counter by one
len++;
// Displays current record status out of maximum capacity
cout<<"\n Record Added Successfully. \n Records "<<len<<" of "<<MAX;
}// End of else
}// End of function
// Function to display a particular employee information
void findEmployee(Employee emp[], int len)
{
int position;
// Accepts index position
cout<<"\n Find an Employee By Its Index in the Array: ";
cout<<"\n Find an Employee By Its Index (0 to "<<(len - 1)<<"): ";
cin>>position;
// Displays employee information at entered index position
cout<<"\n\n Index Location "<<position<<" of "<<(len - 1);
cout<<"\n Employee ID: "<<emp[position].id;
cout<<endl<<" "<<emp[position].firstName<<", "<<emp[position].lastName;
cout<<"\n Hours Worked: "<<emp[position].hour<<" @$"<<emp[position].payRatePerHour;
cout<<"\n Employee Tax Rate @"<<emp[position].taxRate<<"%";
cout<<"\n Gross Pay \t $"<<emp[position].gross;
cout<<"\n Less Tax \t $"<<emp[position].tax;
cout<<"\n Net Pay \t $"<<emp[position].net;
}// End of function
// main function definition
int main()
{
// Creates an array of object of structure Employees of size MAX
Employee employee[MAX];
// Calls the function to read file and stores data in employee array of object
// Stores the return value as number of records
int len = readFile(employee);
// Loops till user choice is not 4
do
{
// Calls the function menu() to accept user choice
// Based on the return value of the user choice calls the appropriate function
switch(menu())
{
case 1:
// Calls the function to display all employee information
displayAll(employee, len);
break;
case 2:
// Calls the function to display a employee information
findEmployee(employee, len);
break;
case 3:
// Calls the function to add an employee
addEmployee(employee, len);
break;
case 4:
// Calls the function to write data to file
writeData(employee, len);
exit(0);
break;
default:
cout<<"\n Invalid choice! Try again.";
}// End of switch - case
}while(1); // End of do - while loop
}// End of main function
