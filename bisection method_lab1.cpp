#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

float f(float x)
{
    return x*x*x - x -1;
}

void bisection()
{
    float a,b, c, e;

    cout << "Enter a:";
    cin >> a;

    cout << "Enter b:";
    cin >> b;

    cout << "Enter e:";
    cin >> e;

    if (f(a)* f(b)>0)
    {
        cout << "WRONG GUESS!" << endl;
    }
    else
    {
        do
        {
            c= (a+b)/2;

            if ( f(a)*f(c) <0)
            {
                b=c;
            }
            else
            {
                a=c;
            }
            cout << "root: " << c << ", " << "f(x)= " << f(c) << endl;
        }while(fabs(f(c))>e); // e = -0.001 or 0.001 doesn't matter. fabs does that.
            cout << "Final Root is: " << c << endl;
    }

}

int main()
{
    bisection();
    return 0;
}
