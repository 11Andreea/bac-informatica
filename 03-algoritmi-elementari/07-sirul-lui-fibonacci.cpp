#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Introdu numarul de termeni n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Numarul trebuie sa fie pozitiv.";
        return 0;
    }

    long long a = 1, b = 1, c; // Folosim long long pentru a evita depasirea la n mare

    for (int i = 1; i <= n; ++i) {
        if (i == 1 || i == 2) {
            cout << 1 << " ";
        } else {
            c = a + b;
            a = b;
            b = c;
            cout << c << " ";
        }
    }
    return 0;
}