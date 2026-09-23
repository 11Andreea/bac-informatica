#include <iostream>
using namespace std;

int alg_euclid_scaderi(int n,int m) {
    while(n != m)
        if(n > m)
            n -= m;
        else
            m -= n;
    return n;
}

int alg_euclid_impartiri(int n,int m) {
   while(m != 0)
    {
        int r = n % m;
        n = m;
        m = r;
    }
   return n;
}

//
int main()
{
    int n,m;
    cin>>n>>m;
    int cmmdc=alg_euclid_impartiri(n,m);
    int cmmmc=(n*m)/cmmdc;
    cout<<cmmdc<<" "<<cmmmc;
    return 0;
}