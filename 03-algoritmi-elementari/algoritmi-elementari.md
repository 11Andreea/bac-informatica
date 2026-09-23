# Algoritmi elementari

---

## Cuprins

1. [Cum abordăm o problemă de algoritmică](#1-cum-abordăm-o-problemă-de-algoritmică)
2. [Maxime și minime](#2-maxime-și-minime)
3. [Cifrele unui număr](#3-cifrele-unui-număr)
4. [Divizibilitate](#4-divizibilitate)
5. [Divizorii unui număr](#5-divizorii-unui-număr)
6. [Algoritmul lui Euclid: CMMDC și CMMMC](#6-algoritmul-lui-euclid-cmmdc-și-cmmmc)
7. [Verificarea primalității](#7-verificarea-primalității)
8. [Descompunerea în factori primi](#8-descompunerea-în-factori-primi)
9. [Șirul lui Fibonacci](#9-șirul-lui-fibonacci)
10. [Baze de numerație](#10-baze-de-numerație)
11. [Eficiența algoritmilor](#11-eficiența-algoritmilor)
12. [Tipare de recunoscut la BAC](#12-tipare-de-recunoscut-la-bac)
13. [Greșeli frecvente](#13-greșeli-frecvente)

---

# 1. Cum abordăm o problemă de algoritmică

Înainte să scrii cod, încearcă să răspunzi la patru întrebări:

1. **Ce date primesc?**
2. **Ce trebuie să determin?**
3. **Ce tipar algoritmic recunosc?**
4. **Care este complexitatea soluției?**

Un flux bun este:

```text
cerință
   ↓
observații matematice
   ↓
algoritm / pseudocod
   ↓
implementare C++
   ↓
testare pe exemple
   ↓
verificarea cazurilor-limită
```

### Tipare importante

| Dacă problema cere... | Gândește-te la... |
|---|---|
| cea mai mare / cea mai mică valoare | maxim / minim |
| proprietăți ale cifrelor | `n % 10`, `n /= 10` |
| dacă un număr îl divide pe altul | `%` |
| toți divizorii | parcurgere până la `sqrt(n)` |
| cel mai mare divizor comun | Euclid |
| dacă un număr este prim | verificarea divizorilor până la `sqrt(n)` |
| forma produsului de numere prime | descompunere în factori primi |
| termeni consecutivi dependenți de cei anteriori | Fibonacci / generare de șir |
| conversie între baze | împărțiri succesive / Horner |
| „merge prea încet?” | analiza complexității |

---

# 2. Maxime și minime

Maximul unei mulțimi este cea mai mare valoare, iar minimul este cea mai mică valoare.

Exemplu:

```text
4 7 3 6
```

are:

```text
maxim = 7
minim = 3
```

## 2.1. Maximul a două valori

```cpp
int maxim = max(a, b);
```

Fără `max`:

```cpp
int maxim;

if (a > b)
    maxim = a;
else
    maxim = b;
```

## 2.2. Maximul pentru un număr oarecare de valori

Dacă citim `n` valori, păstrăm cea mai mare valoare întâlnită până în acel moment.

### Idee

```text
citește prima valoare
aceasta este maximul curent

pentru fiecare valoare următoare:
    dacă valoarea > maxim:
        maxim = valoarea
```

### Implementare

```cpp
int n;
cin >> n;

int x;
cin >> x;

int maxim = x;

for (int i = 2; i <= n; i++) {
    cin >> x;

    if (x > maxim)
        maxim = x;
}

cout << maxim;
```

### De ce este mai bine să pornim de la prima valoare?

Evităm inițializări artificiale precum:

```cpp
int maxim = -1000000000;
```

care pot deveni greșite dacă limitele problemei se schimbă.

## 2.3. Minimul

Exact aceeași idee:

```cpp
int n;
cin >> n;

int x;
cin >> x;

int minim = x;

for (int i = 2; i <= n; i++) {
    cin >> x;

    if (x < minim)
        minim = x;
}

cout << minim;
```

## 2.4. Maxim și minim simultan

```cpp
int n;
cin >> n;

int x;
cin >> x;

int maxim = x;
int minim = x;

for (int i = 2; i <= n; i++) {
    cin >> x;

    if (x > maxim)
        maxim = x;

    if (x < minim)
        minim = x;
}

cout << minim << ' ' << maxim;
```

### Complexitate

Pentru `n` valori:

```text
T(n) = O(n)
```

Fiecare valoare este analizată o singură dată.

### Greșeală frecventă

Nu inițializa maximul cu `0` dacă valorile pot fi negative:

```cpp
int maxim = 0; // poate fi greșit
```

---

# 3. Cifrele unui număr

Pentru un număr natural `n`, putem extrage ultima cifră folosind:

```cpp
n % 10
```

iar ultima cifră poate fi eliminată prin:

```cpp
n /= 10;
```

De exemplu, pentru `274`:

```text
274 % 10 = 4
274 / 10 = 27

27 % 10 = 7
27 / 10 = 2

2 % 10 = 2
2 / 10 = 0
```

## 3.1. Șablonul de bază

```cpp
while (n > 0) {
    int c = n % 10;

    // prelucrăm c

    n /= 10;
}
```

Acesta este unul dintre cele mai importante șabloane de la algoritmii elementari.

## 3.2. Numărul de cifre

```cpp
int n;
cin >> n;

int nr = 0;

while (n > 0) {
    nr++;
    n /= 10;
}

cout << nr;
```

Pentru `n = 0`, numărul are o cifră:

```cpp
if (n == 0)
    nr = 1;
```

## 3.3. Suma cifrelor

```cpp
int n;
cin >> n;

int suma = 0;

while (n > 0) {
    suma += n % 10;
    n /= 10;
}

cout << suma;
```

Pentru `372`:

```text
suma = 3 + 7 + 2 = 12
```

## 3.4. Produsul cifrelor

```cpp
int n;
cin >> n;

int produs = 1;

while (n > 0) {
    produs *= n % 10;
    n /= 10;
}

cout << produs;
```

## 3.5. Cea mai mare cifră

```cpp
int n;
cin >> n;

int maxim = 0;

while (n > 0) {
    int c = n % 10;

    if (c > maxim)
        maxim = c;

    n /= 10;
}

cout << maxim;
```

## 3.6. Cea mai mică cifră

Inițializarea trebuie tratată cu grijă:

```cpp
int n;
cin >> n;

int minim = 9;

while (n > 0) {
    int c = n % 10;

    if (c < minim)
        minim = c;

    n /= 10;
}

cout << minim;
```

## 3.7. Numărul de cifre pare

```cpp
int n;
cin >> n;

int nr = 0;

while (n > 0) {
    int c = n % 10;

    if (c % 2 == 0)
        nr++;

    n /= 10;
}

cout << nr;
```

## 3.8. Construirea numărului oglindit

Pentru a inversa cifrele:

```cpp
int n;
cin >> n;

int ogl = 0;

while (n > 0) {
    int c = n % 10;
    ogl = ogl * 10 + c;
    n /= 10;
}

cout << ogl;
```

Pentru `1234`:

```text
ogl = 4
ogl = 43
ogl = 432
ogl = 4321
```

## 3.9. Verificarea palindromului

Un număr este palindrom dacă este egal cu oglinditul său.

```cpp
int n;
cin >> n;

int copie = n;
int ogl = 0;

while (n > 0) {
    int c = n % 10;
    ogl = ogl * 10 + c;
    n /= 10;
}

if (copie == ogl)
    cout << "DA";
else
    cout << "NU";
```

### Atenție

Dacă prelucrezi `n` direct, acesta se modifică. Păstrează o copie dacă ai nevoie ulterior de valoarea inițială.

---

# 4. Divizibilitate

Spunem că `a` divide `b` dacă există un număr întreg `k` astfel încât:

```text
b = a * k
```

În C++, pentru numere întregi:

```cpp
b % a == 0
```

înseamnă că `b` este divizibil cu `a`.

## 4.1. Verificarea divizibilității

```cpp
if (a != 0 && b % a == 0)
    cout << "DA";
else
    cout << "NU";
```

Nu trebuie să calculăm câtul pentru a verifica divizibilitatea.

## 4.2. Criterii uzuale

### Divizibil cu 2

Ultima cifră este pară:

```cpp
n % 2 == 0
```

### Divizibil cu 5

Ultima cifră este `0` sau `5`:

```cpp
n % 5 == 0
```

### Divizibil cu 10

Ultima cifră este `0`:

```cpp
n % 10 == 0
```

### Divizibil cu 3

Suma cifrelor este divizibilă cu `3`.

### Divizibil cu 9

Suma cifrelor este divizibilă cu `9`.

Exemplu pentru 3:

```cpp
int n;
cin >> n;

int copie = n;
int suma = 0;

while (n > 0) {
    suma += n % 10;
    n /= 10;
}

if (suma % 3 == 0)
    cout << "DA";
else
    cout << "NU";
```

---

# 5. Divizorii unui număr

Un număr `d` este divizor al lui `n` dacă:

```cpp
n % d == 0
```

## 5.1. Varianta simplă

Putem verifica toate valorile de la `1` la `n`:

```cpp
for (int d = 1; d <= n; d++) {
    if (n % d == 0)
        cout << d << ' ';
}
```

Complexitate:

```text
O(n)
```

Pentru valori mari, există o soluție mai bună.

## 5.2. Parcurgerea până la `sqrt(n)`

Dacă `d` este divizor al lui `n`, atunci și:

```text
n / d
```

este divizor.

Divizorii apar în perechi:

```text
36:
1 × 36
2 × 18
3 × 12
4 × 9
6 × 6
```

De aceea este suficient să verificăm:

```text
d * d <= n
```

### Implementare

```cpp
int n;
cin >> n;

for (int d = 1; d * d <= n; d++) {
    if (n % d == 0) {
        cout << d << ' ';

        if (d != n / d)
            cout << n / d << ' ';
    }
}
```

Această variantă are complexitatea:

```text
O(sqrt(n))
```

### Atenție

Condiția:

```cpp
d * d <= n
```

poate produce overflow pentru anumite limite foarte mari. O variantă mai sigură este:

```cpp
d <= n / d
```

---

# 6. Algoritmul lui Euclid: CMMDC și CMMMC

## 6.1. CMMDC

CMMDC(a, b) este cel mai mare număr care divide atât `a`, cât și `b`.

Exemplu:

```text
CMMDC(18, 24) = 6
```

## 6.2. Euclid prin împărțiri

Ideea este:

```text
CMMDC(a, b) = CMMDC(b, a % b)
```

Repetăm până când al doilea număr devine `0`.

### Implementare

```cpp
int a, b;
cin >> a >> b;

while (b != 0) {
    int r = a % b;
    a = b;
    b = r;
}

cout << a;
```

Pentru `48` și `18`:

```text
48 % 18 = 12
18 % 12 = 6
12 % 6 = 0
```

Rezultatul este `6`.

## 6.3. Varianta cu `gcd`

În C++ modern:

```cpp
#include <numeric>

cout << gcd(a, b);
```

Pentru învățarea algoritmului, însă, este important să știi și varianta manuală.

## 6.4. CMMMC

Relația:

```text
CMMMC(a, b) = |a · b| / CMMDC(a, b)
```

Pentru numere naturale pozitive:

```cpp
int cmmdc = gcd(a, b);
int cmmmc = a / cmmdc * b;
```

Este preferabil să împărțim înainte de înmulțire:

```cpp
a / cmmdc * b
```

în loc de:

```cpp
a * b / cmmdc
```

pentru a reduce riscul de overflow.

---

# 7. Verificarea primalității

Un număr natural `p > 1` este prim dacă are exact doi divizori pozitivi:

```text
1 și p
```

Prin urmare:

```text
0 și 1 NU sunt prime.
```

## 7.1. Varianta simplă

Putem căuta un divizor între `2` și `n - 1`:

```cpp
bool prim = true;

if (n < 2)
    prim = false;

for (int d = 2; d < n && prim; d++) {
    if (n % d == 0)
        prim = false;
}
```

Complexitate:

```text
O(n)
```

## 7.2. Varianta eficientă

Dacă `n` este compus, atunci are cel puțin un divizor `d` cu:

```text
d <= sqrt(n)
```

Așadar este suficient să verificăm până la rădăcina pătrată.

```cpp
bool prim = true;

if (n < 2)
    prim = false;

for (int d = 2; d * d <= n && prim; d++) {
    if (n % d == 0)
        prim = false;
}

if (prim)
    cout << "DA";
else
    cout << "NU";
```

Complexitate:

```text
O(sqrt(n))
```

### Variantă cu `d <= n / d`

```cpp
for (int d = 2; d <= n / d && prim; d++) {
    if (n % d == 0)
        prim = false;
}
```

---

# 8. Descompunerea în factori primi

Orice număr natural `n > 1` poate fi scris în mod unic ca produs de puteri ale numerelor prime.

Exemplu:

```text
140 = 2² · 5 · 7
```

## 8.1. Ideea algoritmului

Pornim cu primul posibil factor:

```text
d = 2
```

Cât timp `d` divide numărul:

```text
n % d == 0
```

împărțim `n` la `d` și numărăm de câte ori apare.

### Implementare

```cpp
int n;
cin >> n;

for (int d = 2; d <= n / d; d++) {
    if (n % d == 0) {
        int p = 0;

        while (n % d == 0) {
            n /= d;
            p++;
        }

        cout << d << "^" << p << ' ';
    }
}

if (n > 1)
    cout << n << "^1";
```

Pentru:

```text
140
```

obținem:

```text
2^2 5^1 7^1
```

### De ce testăm până la `sqrt(n)`?

După eliminarea tuturor factorilor mici, dacă `n > 1`, valoarea rămasă este primă și trebuie adăugată ca factor.

### Observație importantă

Versiunea de mai sus modifică `n`. Dacă ai nevoie de valoarea inițială, păstrează o copie.

---

# 9. Șirul lui Fibonacci

Șirul Fibonacci este definit prin faptul că fiecare termen este suma celor doi termeni precedenți.

O variantă uzuală este:

```text
0, 1, 1, 2, 3, 5, 8, 13, ...
```

cu:

```text
F0 = 0
F1 = 1
Fn = F(n-1) + F(n-2)
```

## 9.1. Generarea primilor `n` termeni

Nu avem nevoie de un vector dacă vrem doar să îi afișăm.

```cpp
int n;
cin >> n;

long long a = 0;
long long b = 1;

for (int i = 1; i <= n; i++) {
    cout << a << ' ';

    long long c = a + b;
    a = b;
    b = c;
}
```

Pentru `n = 8`:

```text
0 1 1 2 3 5 8 13
```

## 9.2. Determinarea termenului `n`

```cpp
long long a = 0;
long long b = 1;

for (int i = 0; i < n; i++) {
    long long c = a + b;
    a = b;
    b = c;
}

cout << a;
```

### Atenție la overflow

Fibonacci crește rapid. Tipul `int` se depășește foarte repede, iar `long long` are și el o limită.

---

# 10. Baze de numerație

Un număr poate fi reprezentat în mai multe baze.

În baza `b`, cifrele disponibile sunt:

```text
0, 1, ..., b - 1
```

Exemple:

```text
baza 2  → 0, 1
baza 8  → 0 ... 7
baza 10 → 0 ... 9
baza 16 → 0 ... 9, A, B, C, D, E, F
```

## 10.1. Din baza `b` în baza 10

Dacă avem cifrele:

```text
a_k ... a_2 a_1 a_0
```

valoarea este:

```text
a_k · b^k + ... + a_2 · b² + a_1 · b + a_0
```

O metodă eficientă este schema lui Horner:

```text
valoare = valoare * b + cifra
```

Exemplu: `1011₂`

```text
0
0 * 2 + 1 = 1
1 * 2 + 0 = 2
2 * 2 + 1 = 5
5 * 2 + 1 = 11
```

Rezultatul:

```text
1011₂ = 11₁₀
```

### Implementare

```cpp
int b, n;
cin >> b >> n;

int p10 = 0;

while (n > 0) {
    int cifra = n % 10;
    p10 = p10 * b + cifra;
    n /= 10;
}

cout << p10;
```

Această implementare presupune că reprezentarea poate fi stocată ca număr și că baza este cel mult 10.

## 10.2. Din baza 10 în baza `b`

Se folosesc împărțiri succesive la baza `b`.

Pentru `n`:

```text
cifra = n % b
n = n / b
```

Cifrele sunt obținute de la dreapta la stânga.

Exemplu: `13` în baza `2`:

```text
13 % 2 = 1
13 / 2 = 6

6 % 2 = 0
6 / 2 = 3

3 % 2 = 1
3 / 2 = 1

1 % 2 = 1
1 / 2 = 0
```

Resturile, citite invers:

```text
1101
```

### Implementare pentru baza 2–10

```cpp
int n, b;
cin >> n >> b;

int rezultat = 0;
int p = 1;

while (n > 0) {
    int cifra = n % b;
    rezultat += cifra * p;

    p *= 10;
    n /= b;
}

cout << rezultat;
```

### Atenție

Pentru baze mai mari decât 10, cifrele `10–15` nu pot fi reprezentate ca cifre zecimale. Atunci trebuie să folosim caractere precum:

```text
A B C D E F
```

---

# 11. Eficiența algoritmilor

Un algoritm corect nu este neapărat un algoritm bun.

Trebuie să ținem cont de:

- timpul de execuție;
- memoria folosită;
- dimensiunea datelor de intrare.

În problemele de programare, ne interesează în special **ordinul de creștere** al timpului de execuție.

## 11.1. Notația Big O

Câteva complexități importante:

| Complexitate | Exemplu |
|---|---|
| `O(1)` | acces la o valoare / operație simplă |
| `O(log n)` | căutare binară |
| `O(sqrt(n))` | verificarea primalității prin divizori până la `sqrt(n)` |
| `O(n)` | parcurgerea unei liste / cifrelor |
| `O(n log n)` | mulți algoritmi de sortare eficienți |
| `O(n²)` | două bucle imbricate peste `n` valori |
| `O(2^n)` | unele soluții brute-force recursive |

## 11.2. Exemplu: divizorii

Varianta:

```cpp
for (int d = 1; d <= n; d++)
```

are:

```text
O(n)
```

Varianta:

```cpp
for (int d = 1; d <= n / d; d++)
```

are:

```text
O(sqrt(n))
```

Diferența poate fi foarte mare.

## 11.3. Cum estimezi complexitatea

### O buclă

```cpp
for (int i = 0; i < n; i++)
```

→ `O(n)`

### Două bucle succesive

```cpp
for (...)
    ...

for (...)
    ...
```

→ `O(n) + O(n) = O(n)`

Constanta nu contează în Big O.

### Două bucle imbricate

```cpp
for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        ...
```

→ `O(n²)`

### Buclă care înjumătățește problema

```cpp
while (n > 1)
    n /= 2;
```

→ `O(log n)`

---

# 12. Tipare de recunoscut la BAC

## Dacă vezi „cifrele lui n”

Gândește:

```cpp
while (n > 0) {
    int c = n % 10;
    ...
    n /= 10;
}
```

## Dacă vezi „cea mai mare / cea mai mică dintre n valori”

Gândește:

```cpp
maxim = prima_valoare;
minim = prima_valoare;
```

și apoi parcurgere.

## Dacă vezi „divizor”

Gândește:

```cpp
n % d == 0
```

## Dacă vezi „toți divizorii”

Gândește:

```cpp
d <= sqrt(n)
```

și perechile:

```text
d și n/d
```

## Dacă vezi „CMMDC”

Gândește:

```text
Euclid
```

## Dacă vezi „număr prim”

Gândește:

```text
nu există divizor între 2 și sqrt(n)
```

## Dacă vezi „descompunere în factori primi”

Gândește:

```text
împart repetat la fiecare divizor posibil
```

## Dacă vezi „Fibonacci”

Gândește:

```text
doi termeni anteriori → termen nou
```

## Dacă vezi „schimbarea bazei”

Gândește:

```text
baza b → 10 : Horner
10 → baza b : împărțiri succesive
```

---

# 13. Greșeli frecvente

### 1. Modificarea numărului de care mai ai nevoie

Greșit dacă ulterior ai nevoie de `n`:

```cpp
while (n > 0)
    n /= 10;
```

Folosește:

```cpp
int copie = n;
```

dacă ai nevoie de valoarea originală.

### 2. Inițializarea incorectă a maximului/minimului

Evită:

```cpp
int maxim = 0;
```

dacă valorile pot fi negative.

### 3. Uitarea cazului `n = 0`

Pentru problemele cu cifre, `0` este un caz special.

### 4. Verificarea primalității până la `n`

De cele mai multe ori este inutil. Este suficient până la `sqrt(n)`.

### 5. Overflow

Atenție la:

```cpp
a * b
d * d
```

și la valorile Fibonacci.

### 6. Alegerea unui algoritm prea lent

Dacă `n` poate fi foarte mare, o soluție `O(n)` poate fi imposibilă, în timp ce una `O(sqrt(n))` poate fi acceptabilă.
