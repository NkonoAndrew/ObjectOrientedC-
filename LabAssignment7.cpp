#include<iostream>
#include<stdlib.h>
using namespace std;

void help();

class Shapes
{
    protected:
        double width;
        double height;
        double width2;

    public:
        void setwidth( double width)
        {
            this->width = width;
        }
        void setheight( double height)
        {
            this->height = height;
        }
         void setwidth2( double width2)
        {
            this->width2 = width2;
        }

        double getwidth2()
        {
            return width2;
        }

        double getwidth()
        {
            return width;
        }
        double getheight()
        {
            return height;
        }
         virtual double getarea()
         {
            double area = 0;
            return area;
         }

};

class Rectangle:public Shapes
{
    public:
        double getarea()
        {
            double area = getwidth() * getheight();
            return area;
        }
};

class Triangle:public Shapes
{
    public:
        double getarea()
        {
            double area = 0.5 * (getwidth() * getheight());
            return area;
        }

};

class Cylinder: public Shapes
{
    public:
        double getarea()
        {
            // 2πrh+2πr2
            double area = ((2 * 3.14159F * getheight() * getwidth()) +
                           (2 * 3.14159F * getwidth() * getwidth()));
           return area;
        }
};

class Trapezoid:public Shapes
{
    public:

        double getarea()
         {
             double area = ((getwidth() + getwidth2()) / 2.0F) * getheight();
            return area;
         }
};

class Circle:public Shapes
{
    public:
        double getarea()
        {
        double area = (3.14159F * getwidth()* getwidth());
        return area;
        }
};

int main()
{
    int option;
    Rectangle rectangle;
    Triangle triangle;
    Cylinder cylinder;
    Circle circle;
    Trapezoid trapezoid;

    Shapes *s1 = &rectangle,*s2 = s2 = &triangle,*s3 = s3 = &cylinder,*s4 = s4 = &circle,*s5 = s5 = &trapezoid;

   // s1 = &rectangle;
    ;
    ;
    ;
    ;

    char again;
    cout.precision(2);
    cout.setf(ios::fixed,ios::showpoint);
    cout.setf(ios::fixed,ios::floatfield);

    while (again)
    {
        cout << "\n Determine the area of objects:"
         << "\n 1 of 6: Rectangle"
         << "\n 2 of 6: Triangle"
         << "\n 3 of 6: Cylinder"
         << "\n 4 of 6: Trapezoid"
         << "\n 5 of 6: Circle"
         << "\n 6 of 6: Quit"
         << "\n\n Choose an option:";
    cin >> option;

    switch (option)
    {
    case 1:
        float height, width;
        cout << "\n Enter the width of the rectangle:";
        cin >> width;
        (*s1).setwidth(width);

        cout << "\n Enter the height of the rectangle:";
        cin >> height;
        (*s1).setheight(height);

        cout << "\n The area is " << s1->getarea();
        break;

    case 2:
        double width2, height2;
        cout << "\n Enter the base of the triangle:";
        cin >> width2;
        s2->setwidth(width2);

        cout << "\n Enter the height of the triangle:";
        cin >> height2;
        s2->setheight(height2);

        cout << "\n\n The area of the triangle is " << s2->getarea();
        break;

    case 3:
        double radius, height3;
        cout << "\n Enter the radius of the cylinder:";
        cin >> radius;
        s3->setwidth(radius);

        cout << "\n Enter the height of the cylinder:";
        cin >> height3;
        s3->setheight(height3);

        cout << "\n\n The area of the cylinder is " << s3->getarea();
        break;

    case 4:
        double side1, side2, height4;
        cout << "\n Enter side a:";
        cin >> side1;
        s5->setwidth(side1);

        cout << "\n Enter side b:";
        cin >> side2;
        s5->setwidth2(side2);

        cout << "\n Enter the height:";
        cin >> height4;
        s5->setheight(height4);

        cout << "\n\n The area of the trapezoid is " << s5->getarea();
        break;


    case 5:
        double radius2;
        cout << "\n Enter the radius:";
        cin >> radius2;
        s4->setwidth(radius2);

        cout << "\n The area of the circle is " << s4->getarea();
        break;

     case 6:
        cout << "\n Quiting....";
        exit(0);
        break;


    }
      cout << "\n\n Would you like to run again yes(y) or no(n)...";
        cin >> again;
        again = tolower(again);
        system("cls");
    }
}
