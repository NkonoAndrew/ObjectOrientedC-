#include <iomanip>

#include <iostream>

#include<stdlib.h>

#include <time.h>

#include<sstream>

#include <string>

using namespace std;

int check1(char first) {

if(first == 'A' || first == 'K' || first == 'S') {

return 1;

} else if(first == 'B' || first == 'H' || first == 'N') {

return 2;

} else if(first == 'C' || first == 'T' ) {

return 3;

} else if(first == 'M' || first == 'O' || first == 'Z') {

return 4;

} else {

return 5;

}

}

int check2(char second, int firstCheck) {

if(firstCheck == 1 && (second == 'B' || second == 'C' || second == 'D')) {

return 1;

} else if(firstCheck == 2 && (second == 'A' || second == 'F' || second == 'G' || second || 'H')) {

return 2;

} else if(firstCheck == 3 && (second == 'K' || second == 'L' || second == 'Z' )) {

return 3;

} else if(firstCheck == 4 && (second == 'A' || second == 'D' || second == 'F')) {

return 4;

} else {

return 5;

}

}

int check3(int third, int firstCheck) {

if(firstCheck == 1 && (third >= 101 && third <= 110)) {

return 1;

} else if(firstCheck == 2 && ((third >= 101 && third <= 110) || third == 213 || third == 220 || third == 560)) {

return 2;

} else if(firstCheck == 3 && (third == 134 || third == 138 || third == 145 || third == 246)) {

return 3;

} else if(firstCheck == 4 && ((third >= 117 && third <= 181) || (third >= 333 && third <= 335) )) {

return 4;

} else {

return 5;

}

}

int main()

{

char again = 'y';

string demo;

string customerid;

char first, second;

int third;

const int idsize = 5;

stringstream converter;

while (again == 'y')

{

cout << "\n Enter the customer ID to validate: ";

getline(cin, customerid);

cout << customerid << endl;

if (customerid.length() == idsize)

{

first = customerid[0];

first = toupper(first);

second = customerid[1];

second = toupper(second);

demo = "";

for (int n = 0; n < 3; n++)

{

demo += customerid.at(n+2);

}

converter.clear();

converter.str(demo);

converter >> third;

int firstCheck = check1(first);

int secondCheck = check2(second, firstCheck);

int thirdCheck = check3(third, firstCheck);

// cout << firstCheck << " " << secondCheck << " " << thirdCheck << endl;

if(firstCheck == secondCheck && secondCheck == thirdCheck) {

cout << "Customer ID is VALID" << endl;

} else {

cout << "Customer ID is INVALID" << endl;

}

}

else

{

cout << "\n The id " << customerid << " is not of valid length ";

}

cout << "\n Run again yes(y)or no(n)...";

cin >> again;

again = tolower(again);

cin.ignore();

}

}
