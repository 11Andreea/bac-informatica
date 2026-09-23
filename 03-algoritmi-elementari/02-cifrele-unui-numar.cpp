// Exemple pentru cifrele unui numar
#include <iostream>
using namespace std;

int suma_cif(int n)
{
    long s=0;
    while(n)
    {
        int c=n%10; //extragem ultima cifra
        s+=c;
        n/=10; //eliminam ultima cifra
    }
    return s;
}


//functie care verifica daca n contine cifra k
bool exista_cif(int n, int k) 
{
    bool existak=0;
    while(n)
    {
        int c=n%10;
        if(c==k) { existak=1; break; }
        n/=10;
    }
    return existak;
}

int main() {
    int n,k;
    cin>>n>>k;
    cout<<suma_cif(n)<<'\n';
    cout<<exista_cif(n,k);
    return 0;
}