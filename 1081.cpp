#include <stdio.h>
#include <vector>
#include <stdlib.h>

using namespace std;
long gcd(long a, long b)
{
    long c;
    while (b != 0) 
    {
        c = a % b; 
        a = b;  
        b = c;
    }
    return a;
}


struct Rational 
{
    long numerator;
    long denominator;
    long integer;
    Rational()
    {
        integer = 0;
    }
    void normalize()
    {
        if (labs(numerator) >= denominator)
        {
            integer += numerator / denominator;
            numerator = numerator % denominator;            
        }
        if (numerator == 0) return;
        long g = labs(gcd(numerator, denominator));
        if (g != 1)
        {
            numerator /= g;
            denominator /= g;
        }

    }
    void print()
    {
        const char* place_holder = "";
        if (integer != 0)
        {
            printf("%ld", integer);
            place_holder = " ";
        }
        if (numerator != 0)
        {
            printf("%s%ld/%ld", place_holder, numerator, denominator);
        }
        else
        {
            if (integer == 0)
            {
                printf("0");
            }
        }
    }
};

int main()
{
    int N;
    scanf("%d", &N);
    Rational r;
    long n, d;
    for (int i = 0; i < N; i ++)
    {
        scanf("%ld/%ld", &n, &d);
        if (i == 0)
        {
            r.numerator = n;
            r.denominator = d;
        }
        else
        {
            r.numerator = (n * r.denominator + r.numerator * d);
            r.denominator = d * r.denominator;
        }
        r.normalize();
    }

    r.print();
}
