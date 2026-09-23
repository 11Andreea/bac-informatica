#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    bool prim = true; // presupunem ca n este prim
    if(n < 2)
        prim = false; // 0 si 1 nu sunt prime
    //parcurgem posibilii divizori
    for(int d=2 ; d * d <= n ; d++)
        if(n % d == 0)
            prim = false;
    if(prim)
        cout << n << "este prim";
    else
        cout << n << "nu este prim";
    return 0;
}