#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

float f(float x)
{
    return x*x*x - x -1;
}

void false_position()
{
    float x0, x1 , x2 , e;

    cout << "Enter x0:";
    cin >> x0;

    cout << "Enter x1:";
    cin >> x1;

    cout << "Enter e:";
    cin >> e;

    if (f(x0)* f(x1)>0)
    {
        cout << "WRONG GUESS!" << endl;
    }
    else
    {
        do
        {
            x2 = x0 - ( f(x0) * ( (x0 - x1)/ (f(x0) - f(x1) ))) ;

            if ( f(x0)*f(x2) <0)
            {
                x1=x2;
            }
            else if ( f(x0)*f(x2) >0 )
            {
                x0 = x2;
            }
            cout << "root: " << x2 << ", " << "f(x)= " << f(x2) << endl;
        }while(fabs(f(x2))>e); // e = -0.001 or 0.001 doesn't matter. fabs does that.
            cout << "Final Root is: " << x2 << endl;
    }

}

int main()
{
    false_position();
    return 0;
}
