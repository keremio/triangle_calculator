#include <iostream>
#include <math.h>
#define PI 3.141592
using namespace std;

float angle_finder(float c, float a, float b)
{
    float cos = -(pow(c,2) - pow(b,2) - pow(a,2)) / (2*a*b);
    return 45/atan(1) * acos(cos);
}

float coss(float alpha)
{
    return sqrt(1 - pow(sin(alpha),2));
}
float tann(float alpha)
{
    return sin(alpha) / coss(alpha);
}
float cott(float alpha)
{
    return 1/tann(alpha);
}

float area_finder(float alpha, float x, float y)
{
    return sin(alpha*atan(1)/45) * x * y / 2;
}

int main()
{
    float a,b,c;
    cout << "Enter the side a." << "\n";
    cin >> a;
    cout << "Enter the side b." << "\n";
    cin >> b;
    cout << "Enter the side c." << "\n";
    cin >> c;
    if ((a + b > c || a + c > b || b + c > a) && ( abs(a-b) < c && abs(a-c) < b && abs(b-c) < c ))
    {
        if (a == b || a == c || b == c)
        {
            cout << "This triangle is isosceles.\n";
            if (a == b && a == c)
            {
                cout << "This triangle is also an equilateral one.\n";
            }
        }

        cout << "Angle A is: " << angle_finder(a,c,b) << "\n";
        cout << "Angle B is: " << angle_finder(b,c,a) << "\n";
        cout << "Angle C is: " << angle_finder(c,b,a) << "\n";
        float Ad = angle_finder(a,c,b);
        float Bd = angle_finder(b,c,a);
        float Cd = angle_finder(c,b,a);
        if ((floor(Ad) == 90 || ceil(Ad) == 90) || (floor(Bd) == 90 || ceil(Bd) == 90) || (floor(Cd) == 90 || ceil(Cd) == 90))
        {
            cout << "This triangle is a right triangle" << "\n";
        }

        cout << "...." << "For the angle A" << "....\n";
        float A = angle_finder(a,c,b)*atan(1)/45;
        cout << "Sin(A) is: " << sin(A) << "\n";
        cout << "Cos(A) is: " << coss(A) << "\n";
        cout << "Tan(A) is: " << tann(A) << "\n";
        cout << "Cot(A) is: " << cott(A) << "\n";

        cout << "...." << "For the angle B" << "....\n";
        float B = angle_finder(b,c,a)*atan(1)/45;
        cout << "Sin(B) is: " << sin(B) << "\n";
        cout << "Cos(B) is: " << coss(B) << "\n";
        cout << "Tan(B) is: " << tann(B) << "\n";
        cout << "Cot(B) is: " << cott(B) << "\n";

        cout << "...." << "For the angle C" << "....\n";
        float C = angle_finder(c,b,a)*atan(1)/45;
        cout << "Sin(C) is: " << sin(C) << "\n";
        cout << "Cos(C) is: " << coss(C) << "\n";
        cout << "Tan(C) is: " << tann(C) << "\n";
        cout << "Cot(C) is: " << cott(C) << "\n";

        cout << "Area of the triangle is: " << area_finder(angle_finder(a,c,b), b , c);
        }
    else
    {
        cout << "This triangle cannot be drawn.\n";
    }

    return 0;
}
