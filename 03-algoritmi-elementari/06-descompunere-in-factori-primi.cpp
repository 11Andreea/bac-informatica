#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int d = 2;  // pe rand, fiecare factor prim din descompunere
    int p;      // exponentul lui d in descompunere
    // il  impartim pe n la d in mod repetat, pana cand devine 1
    while(n > 1)
    {
        if(n % d == 0) // d este factor prim al acestuia
        {
            // numaram de cate ori se imparte n la d. acesta va fi exponentul lui d in descompunere
            p = 0;
            while(n % d == 0)
            {
                p++;
                n /= d;
            }
            cout << d << " " << p << endl;
        }
        d++;
        //  daca d * d il depaseste pe n si n nu este 1, decidem ca n este prim, si este factor in descompunerea valorii initiale a lui n
        if(n>1 && d * d > n){
            d = n; // trecem direct la n, urmatorul factor din descompunere
        }
    }
    return 0;
}