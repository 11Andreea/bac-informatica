// Calculeaza minimul si maximul a n numere(unde n>0) citite de la tastatura

#include <iostream>
using namespace std;
int main() {
    int n,x,minn,maxx;
    cin>>n;
    cin>>x, n--;
    //initializam minimul si maximul cu prima valoare citita
    minn=x, maxx=x;
    //parcurgem si citim toate cele n numere
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(x>maxx) maxx=x;
        else if(x<minn) minn=x;
    }
    cout<<minn<<" "<<maxx;
    return 0;
}