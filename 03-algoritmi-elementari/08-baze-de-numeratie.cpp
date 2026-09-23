#include <iostream>
using namespace std;

// determină cea mai mare cifră a reprezentării în baza b a numărului n.
void max_cif(int n, int b) {
    cmax = 0;
    while(n)
    {
        int cif= n % b;
        if(cif > cmax)
            cmax = cif;
        n /= b;
    }
    cout << cmax;
}

//Transformarea din baza b în baza 10
void trans_b10(int n,int b) 
{
    int rez = 0;
    for(int i =1 ; i <= n ; i ++)
    {
        int x;
        cin >> x;
        rez = rez * b + x;
    }
    cout << rez;
}
int main()
{

    return 0;
}