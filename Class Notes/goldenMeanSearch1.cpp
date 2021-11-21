#include <iostream>
#include <cmath>
using namespace std;

constexpr double phi = (1 + sqrt(5)) / 2;
typedef double (*FuncOneVar)(double);

double goldenMeanSearch(FuncOneVar f, double L, double R, double epsilon)
{
    double S = (R - L) / phi;
    double a = R - S;
    double b = L + S;

    double y_of_a = f(a);
    double y_of_b = f(b);

    while (R-L > epsilon)
    {
        if (y_of_a >= y_of_b)
        {
            R = b;
            b = a;
            S = (R - L) / phi;
            a = R - S;
            y_of_a = f(a);
        }
        else
            R = a;
            a = b;
            S = (R - L) / phi;
            b = L + S;
            y_of_b = f(b);
    }
    return y_of_a > y_of_b ? a : b;
}

double f(double x)  // THIS IS A RANDOM FUNCTION THAT WE ARE ANALYZING! SORTA DISREGARD
{
    return 9 - x*x;
}

int main()
{
    cout << goldenMeanSearch(f, -5, 3, .00001) << '\n';
}