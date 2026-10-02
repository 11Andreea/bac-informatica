## 1. Ce este un subprogram?

Un **subprogram** este o secvență de instrucțiuni care realizează o operație bine definită și care poate fi apelată de mai multe ori din program.

Folosirea subprogramelor permite:

- împărțirea unei probleme complexe în probleme mai mici;
- reutilizarea codului;
- evitarea repetării acelorași instrucțiuni;
- organizarea și lizibilitatea programului;
- testarea mai ușoară a unor componente ale programului.

În C++, subprogramele sunt implementate prin **funcții**.

Un program poate conține mai multe funcții, fiecare având o responsabilitate clară.

---

# 2. Structura generală a unei funcții

Forma generală este:

```cpp
tip nume(parametri)
{
    // instrucțiuni
}
```

Exemplu:

```cpp
int suma(int a, int b)
{
    return a + b;
}
```

Componentele sunt:

- `int` — tipul valorii returnate;
- `suma` — numele funcției;
- `(int a, int b)` — lista parametrilor;
- `{ ... }` — corpul funcției;
- `return a + b;` — valoarea returnată.

---

# 3. Funcții cu și fără valoare returnată

## 3.1. Funcția care returnează o valoare

O funcție poate calcula o valoare și o poate transmite programului apelant folosind `return`.

Exemplu:

```cpp
int patrat(int x)
{
    return x * x;
}
```

Apel:

```cpp
int x = patrat(5);
```

După apel, `x` va avea valoarea `25`.

O funcție care returnează o valoare trebuie să aibă un tip de rezultat corespunzător:

```cpp
int
long long
float
double
char
bool
```

etc.

---

## 3.2. Funcția fără valoare returnată

Pentru o funcție care doar execută anumite instrucțiuni și nu transmite o valoare se folosește tipul `void`.

Exemplu:

```cpp
void afisare()
{
    cout << "Salut!";
}
```

Apel:

```cpp
afisare();
```

O funcție `void` poate conține `return;`, dar acesta nu returnează o valoare:

```cpp
void f(int x)
{
    if (x < 0)
        return;

    cout << x;
}
```

---

# 4. Instrucțiunea `return`

Instrucțiunea `return` încheie execuția funcției și, dacă este cazul, transmite o valoare către apelant.

Exemplu:

```cpp
int maxim(int a, int b)
{
    if (a > b)
        return a;
    return b;
}
```

La întâlnirea unui `return`, funcția se oprește imediat.

De exemplu:

```cpp
int f(int x)
{
    return x * 2;
    cout << "Salut";
}
```

Instrucțiunea `cout` nu va fi executată.

---

# 5. Apelul unei funcții

O funcție este executată atunci când este **apelată**.

Dacă avem:

```cpp
int suma(int a, int b)
{
    return a + b;
}
```

o putem apela astfel:

```cpp
suma(3, 7);
```

Dacă rezultatul este necesar:

```cpp
int s = suma(3, 7);
```

sau:

```cpp
cout << suma(3, 7);
```

sau:

```cpp
if (suma(a, b) > 10)
    cout << "DA";
```

---

# 6. Parametrii unei funcții

Parametrii reprezintă datele pe care funcția le primește.

Exemplu:

```cpp
int produs(int a, int b)
{
    return a * b;
}
```

`a` și `b` sunt **parametri formali**.

La apel:

```cpp
produs(4, 5);
```

valorile `4` și `5` sunt **parametri efectivi** (argumente).

---

# 7. Parametri formali și parametri efectivi

## Parametri formali

Sunt variabilele declarate în antetul funcției:

```cpp
int suma(int a, int b)
```

Aici `a` și `b` sunt parametri formali.

## Parametri efectivi

Sunt valorile sau expresiile transmise în momentul apelului:

```cpp
suma(10, 20);
```

Aici `10` și `20` sunt parametri efectivi.

Pot fi și variabile:

```cpp
int x = 10, y = 20;
suma(x, y);
```

sau expresii:

```cpp
suma(x + 1, y * 2);
```

---

# 8. Transmiterea parametrilor prin valoare

În transmiterea **prin valoare**, funcția primește o copie a valorii parametrului.

Exemplu:

```cpp
void f(int x)
{
    x = 100;
}

int main()
{
    int a = 5;
    f(a);
    cout << a;
}
```

Se afișează:

```text
5
```

De ce?

`x` este o copie a lui `a`. Modificarea lui `x` nu modifică variabila `a`.

Aceasta este forma uzuală:

```cpp
void f(int x)
```

---

# 9. Transmiterea parametrilor prin referință

În transmiterea prin **referință**, parametrul reprezintă aceeași variabilă cu argumentul transmis.

În C++ se folosește `&`.

Exemplu:

```cpp
void f(int &x)
{
    x = 100;
}

int main()
{
    int a = 5;
    f(a);
    cout << a;
}
```

Se afișează:

```text
100
```

Modificarea lui `x` modifică direct `a`.

---

# 10. Diferența dintre valoare și referință

## Prin valoare

```cpp
void f(int x)
{
    x++;
}
```

```cpp
int a = 5;
f(a);
```

`a` rămâne `5`.

## Prin referință

```cpp
void f(int &x)
{
    x++;
}
```

```cpp
int a = 5;
f(a);
```

`a` devine `6`.

### Regula importantă

```cpp
int x
```

→ parametrul este transmis prin valoare.

```cpp
int &x
```

→ parametrul este transmis prin referință.

---

# 11. De ce sunt utile parametrii prin referință?

Sunt utili atunci când funcția trebuie să modifice variabila primită.

De exemplu, pentru a calcula simultan câtul și restul unei împărțiri:

```cpp
void impartire(int a, int b, int &q, int &r)
{
    q = a / b;
    r = a % b;
}
```

Apel:

```cpp
int q, r;

impartire(17, 5, q, r);
```

După apel:

```text
q = 3
r = 2
```

---

# 12. Funcțiile pot avea mai mulți parametri

Exemplu:

```cpp
int maxim3(int a, int b, int c)
{
    int m = a;

    if (b > m)
        m = b;

    if (c > m)
        m = c;

    return m;
}
```

Apel:

```cpp
cout << maxim3(4, 9, 2);
```

Rezultat:

```text
9
```

---

# 13. Funcțiile pot să nu aibă parametri

O funcție poate fi definită fără parametri:

```cpp
void mesaj()
{
    cout << "Salut!";
}
```

Apel:

```cpp
mesaj();
```

O funcție fără parametri poate returna totuși o valoare:

```cpp
int citeste()
{
    int x;
    cin >> x;
    return x;
}
```

---

# 14. Funcțiile pot returna diferite tipuri de date

Exemple:

## `int`

```cpp
int suma(int a, int b)
{
    return a + b;
}
```

## `long long`

```cpp
long long produs(long long a, long long b)
{
    return a * b;
}
```

## `double`

```cpp
double medie(double a, double b)
{
    return (a + b) / 2;
}
```

## `char`

```cpp
char primaLitera()
{
    return 'A';
}
```

## `bool`

```cpp
bool par(int x)
{
    return x % 2 == 0;
}
```

## `void`

```cpp
void afisare(int x)
{
    cout << x;
}
```

---

# 15. Funcții booleene

Foarte multe probleme de Bac pot fi simplificate folosind funcții care întorc `true` sau `false`.

Exemplu:

```cpp
bool par(int x)
{
    return x % 2 == 0;
}
```

Apel:

```cpp
if (par(x))
    cout << "PAR";
else
    cout << "IMPAR";
```

Alt exemplu:

```cpp
bool prim(int n)
{
    if (n < 2)
        return false;

    for (int d = 2; d * d <= n; d++)
        if (n % d == 0)
            return false;

    return true;
}
```

---

# 16. Prototipul unei funcții

Un **prototip** anunță compilatorului existența unei funcții înainte ca aceasta să fie definită.

Exemplu:

```cpp
int suma(int, int);
```

sau:

```cpp
int suma(int a, int b);
```

Definiția poate apărea ulterior:

```cpp
int suma(int a, int b)
{
    return a + b;
}
```

---

# 17. Ordinea funcțiilor

Dacă o funcție este definită înainte de `main()`, poate fi apelată direct:

```cpp
int suma(int a, int b)
{
    return a + b;
}

int main()
{
    cout << suma(2, 3);
}
```

Dacă este definită după `main()`, este necesar un prototip înainte de `main()`:

```cpp
int suma(int, int);

int main()
{
    cout << suma(2, 3);
}

int suma(int a, int b)
{
    return a + b;
}
```

---

# 18. Funcția `main`

`main` este funcția de la care începe execuția programului.

Forma uzuală:

```cpp
int main()
{
    // instrucțiuni
    return 0;
}
```

În problemele de Bac se întâlnește frecvent:

```cpp
int main()
{
    ...
}
```

`main` este și ea o funcție, dar este funcția principală a programului.

---

# 19. Domeniul de vizibilitate al variabilelor

O variabilă locală este vizibilă numai în blocul în care a fost declarată.

Exemplu:

```cpp
void f()
{
    int x = 10;
    cout << x;
}
```

`x` nu poate fi folosit în `main()`:

```cpp
int main()
{
    cout << x; // greșit
}
```

---

# 20. Variabile locale

Variabilele declarate în interiorul unei funcții sunt locale acelei funcții.

```cpp
int suma(int a, int b)
{
    int s = a + b;
    return s;
}
```

`a`, `b` și `s` sunt accesibile în corpul funcției.

După terminarea funcției, aceste variabile locale nu mai pot fi accesate din exterior.

---

# 21. Variabile globale

O variabilă declarată în afara funcțiilor este globală.

Exemplu:

```cpp
int x;

void f()
{
    x++;
}

int main()
{
    x = 10;
    f();
    cout << x;
}
```

Rezultatul este:

```text
11
```

La Bac este recomandat să folosești variabile locale și parametri atunci când este suficient. Variabilele globale pot face programul mai greu de urmărit.

---

# 22. Subprograme care prelucrează cifrele unui număr

Subprogramele sunt foarte utile pentru algoritmii clasici de prelucrare a numerelor.

## Numărul de cifre

```cpp
int nrCifre(int n)
{
    int cnt = 0;

    if (n == 0)
        return 1;

    while (n != 0)
    {
        cnt++;
        n /= 10;
    }

    return cnt;
}
```

---

## Suma cifrelor

```cpp
int sumaCifre(int n)
{
    int s = 0;

    while (n != 0)
    {
        s += n % 10;
        n /= 10;
    }

    return s;
}
```

---

## Cea mai mare cifră

```cpp
int cifraMax(int n)
{
    int mx = 0;

    while (n != 0)
    {
        int c = n % 10;

        if (c > mx)
            mx = c;

        n /= 10;
    }

    return mx;
}
```

---

## Cea mai mică cifră

Pentru numere nenule:

```cpp
int cifraMin(int n)
{
    int mn = 9;

    while (n != 0)
    {
        int c = n % 10;

        if (c < mn)
            mn = c;

        n /= 10;
    }

    return mn;
}
```

---

# 23. Subprogram pentru verificarea parității

```cpp
bool par(int n)
{
    return n % 2 == 0;
}
```

Apel:

```cpp
if (par(x))
    cout << "DA";
```

---

# 24. Subprogram pentru divizibilitate

Pentru a verifica dacă `a` îl divide pe `b`:

```cpp
bool divide(int a, int b)
{
    return b % a == 0;
}
```

De exemplu:

```cpp
if (divide(5, 20))
    cout << "DA";
```

---

# 25. Subprogram pentru numărul de divizori

```cpp
int nrDivizori(int n)
{
    int cnt = 0;

    for (int d = 1; d <= n; d++)
        if (n % d == 0)
            cnt++;

    return cnt;
}
```

Variantă mai eficientă:

```cpp
int nrDivizori(int n)
{
    int cnt = 0;

    for (int d = 1; d * d <= n; d++)
    {
        if (n % d == 0)
        {
            cnt++;

            if (d * d != n)
                cnt++;
        }
    }

    return cnt;
}
```

---

# 26. Subprogram pentru verificarea numerelor prime

```cpp
bool prim(int n)
{
    if (n < 2)
        return false;

    for (int d = 2; d * d <= n; d++)
        if (n % d == 0)
            return false;

    return true;
}
```

Ideea:

- numerele mai mici decât `2` nu sunt prime;
- este suficient să verificăm divizorii până la `sqrt(n)`;
- dacă găsim un divizor, numărul nu este prim;
- dacă nu găsim niciunul, numărul este prim.

---

# 27. Subprogram pentru cmmdc

Algoritmul lui Euclid:

```cpp
int cmmdc(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}
```

Exemplu:

```cpp
cout << cmmdc(24, 18);
```

Rezultat:

```text
6
```

---

# 28. Subprogram pentru cmmmc

Folosind relația:

```text
cmmmc(a,b) = a / cmmdc(a,b) * b
```

Subprogram:

```cpp
int cmmmc(int a, int b)
{
    return a / cmmdc(a, b) * b;
}
```

Este preferabil să faci împărțirea înaintea înmulțirii pentru a reduce riscul de depășire a domeniului.

---

# 29. Subprograme pentru șiruri de caractere

Un subprogram poate primi un șir de caractere.

Exemplu:

```cpp
int lungime(char s[])
{
    int i = 0;

    while (s[i] != '\0')
        i++;

    return i;
}
```

Apel:

```cpp
char s[101];

cin.getline(s, 101);

cout << lungime(s);
```

---

# 30. Transmiterea unui tablou unidimensional către un subprogram

Un tablou poate fi transmis unei funcții.

Exemplu:

```cpp
void citire(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cin >> a[i];
}
```

Apel:

```cpp
int a[100];

citire(a, n);
```

Este necesar să transmitem și numărul de elemente `n`, deoarece funcția nu poate determina automat dimensiunea tabloului primit în acest mod.

---

# 31. Prelucrarea unui tablou într-o funcție

Exemplu — suma elementelor:

```cpp
int suma(int a[], int n)
{
    int s = 0;

    for (int i = 0; i < n; i++)
        s += a[i];

    return s;
}
```

Apel:

```cpp
cout << suma(a, n);
```

---

# 32. Căutarea maximului într-un tablou

```cpp
int maxim(int a[], int n)
{
    int mx = a[0];

    for (int i = 1; i < n; i++)
        if (a[i] > mx)
            mx = a[i];

    return mx;
}
```

---

# 33. Căutarea minimului într-un tablou

```cpp
int minim(int a[], int n)
{
    int mn = a[0];

    for (int i = 1; i < n; i++)
        if (a[i] < mn)
            mn = a[i];

    return mn;
}
```

---

# 34. Numărarea elementelor care respectă o proprietate

Exemplu — numărul elementelor pare:

```cpp
int nrPare(int a[], int n)
{
    int cnt = 0;

    for (int i = 0; i < n; i++)
        if (a[i] % 2 == 0)
            cnt++;

    return cnt;
}
```

---

# 35. Modificarea unui tablou într-o funcție

Elementele tabloului pot fi modificate în funcție.

```cpp
void dublare(int a[], int n)
{
    for (int i = 0; i < n; i++)
        a[i] *= 2;
}
```

Apel:

```cpp
dublare(a, n);
```

După apel, elementele tabloului sunt efectiv modificate.

---

# 36. Transmiterea unui tablou bidimensional

Pentru un tablou bidimensional, dimensiunea coloanelor trebuie specificată în antetul funcției.

Exemplu:

```cpp
void afisare(int a[][100], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << ' ';

        cout << '\n';
    }
}
```

Apel:

```cpp
afisare(a, m, n);
```

---

# 37. Funcții care întorc rezultate multiple

O funcție poate returna o singură valoare prin `return`, dar poate transmite mai multe rezultate prin parametri transmiși prin referință.

Exemplu:

```cpp
void minMax(int a[], int n, int &mn, int &mx)
{
    mn = a[0];
    mx = a[0];

    for (int i = 1; i < n; i++)
    {
        if (a[i] < mn)
            mn = a[i];

        if (a[i] > mx)
            mx = a[i];
    }
}
```

Apel:

```cpp
int mn, mx;

minMax(a, n, mn, mx);
```

După apel, `mn` și `mx` conțin cele două rezultate.

---

# 38. Apeluri de funcții în expresii

Rezultatul unei funcții poate fi folosit în expresii.

```cpp
int f(int x)
{
    return x * 2;
}
```

Putem scrie:

```cpp
int y = f(5) + 3;
```

sau:

```cpp
if (f(x) > 10)
    cout << "DA";
```

sau:

```cpp
cout << f(x) * 2;
```

---

# 39. Funcții care apelează alte funcții

O funcție poate apela o altă funcție.

```cpp
int patrat(int x)
{
    return x * x;
}

int sumaPatrate(int a, int b)
{
    return patrat(a) + patrat(b);
}
```

Apel:

```cpp
cout << sumaPatrate(3, 4);
```

Rezultat:

```text
25
```

---

# 40. Apeluri imbricate

O funcție poate fi folosită ca argument pentru o altă funcție.

Exemplu:

```cpp
int suma(int a, int b)
{
    return a + b;
}

int dublu(int x)
{
    return 2 * x;
}
```

Putem scrie:

```cpp
cout << dublu(suma(3, 4));
```

Ordinea conceptuală este:

```text
suma(3,4) → 7
dublu(7) → 14
```

---

# 41. Recursivitatea

Un subprogram este **recursiv** dacă se apelează pe el însuși.

Exemplu — factorial:

```cpp
long long factorial(int n)
{
    if (n == 0)
        return 1;

    return n * factorial(n - 1);
}
```

Apel:

```cpp
cout << factorial(5);
```

Rezultat:

```text
120
```

---

# 42. Structura unei funcții recursive

O funcție recursivă trebuie să aibă:

1. **caz de bază** — oprește recursia;
2. **apel recursiv** — problema este redusă către cazul de bază.

Schema:

```cpp
tip f(parametri)
{
    if (caz_de_baza)
        return rezultat;

    return ... f(parametri_modificati) ...;
}
```

Fără caz de bază, funcția poate apela la nesfârșit și programul va produce o eroare de execuție.

---

# 43. Factorialul recursiv

Definiția matematică:

```text
0! = 1
n! = n × (n-1)!
```

Implementare:

```cpp
long long factorial(int n)
{
    if (n == 0)
        return 1;

    return n * factorial(n - 1);
}
```

Pentru `5!`:

```text
5 × 4 × 3 × 2 × 1 × 1
```

---

# 44. Fibonacci recursiv

Definiția:

```text
F(0) = 0
F(1) = 1
F(n) = F(n-1) + F(n-2)
```

Implementare:

```cpp
int fib(int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return fib(n - 1) + fib(n - 2);
}
```

Această variantă este simplă pentru înțelegerea recursivității, dar este ineficientă pentru valori mari ale lui `n`.

---

# 45. Recursivitatea pentru prelucrarea cifrelor

Exemplu — suma cifrelor:

```cpp
int sumaCifre(int n)
{
    if (n == 0)
        return 0;

    return n % 10 + sumaCifre(n / 10);
}
```

Pentru `1234`:

```text
4 + sumaCifre(123)
4 + 3 + sumaCifre(12)
4 + 3 + 2 + sumaCifre(1)
4 + 3 + 2 + 1 + sumaCifre(0)
= 10
```

---

# 46. Recursivitate și afișare

Ordinea în care apare `cout` față de apelul recursiv este foarte importantă.

## Afișare înainte de apel

```cpp
void f(int n)
{
    if (n == 0)
        return;

    cout << n << ' ';
    f(n - 1);
}
```

Pentru `f(3)`:

```text
3 2 1
```

## Afișare după apel

```cpp
void f(int n)
{
    if (n == 0)
        return;

    f(n - 1);
    cout << n << ' ';
}
```

Pentru `f(3)`:

```text
1 2 3
```

---

# 47. Recursivitate cu două apeluri

Exemplu:

```cpp
void f(int n)
{
    if (n == 0)
        return;

    f(n - 1);
    cout << n << ' ';
    f(n - 1);
}
```

Pentru astfel de exerciții este util să construiești arborele apelurilor și să urmărești exact ordinea revenirilor din apelurile recursive.

---

# 48. Subprograme și tablouri — idee importantă pentru Bac

Când transmiți un tablou unei funcții:

```cpp
int a[100];
```

și apelezi:

```cpp
f(a, n);
```

funcția poate lucra cu elementele tabloului.

Exemplu:

```cpp
void modifica(int a[], int n)
{
    for (int i = 0; i < n; i++)
        a[i]++;
}
```

După:

```cpp
modifica(a, n);
```

valorile din `a` au fost modificate.

---

# 49. Funcție care verifică o proprietate a unui tablou

Exemplu — verifică dacă toate elementele sunt pozitive:

```cpp
bool toatePozitive(int a[], int n)
{
    for (int i = 0; i < n; i++)
        if (a[i] <= 0)
            return false;

    return true;
}
```

Această tehnică este foarte utilă:

- presupui că proprietatea este adevărată;
- cauți o excepție;
- dacă găsești o excepție, returnezi `false`;
- dacă termini parcurgerea, returnezi `true`.

---

# 50. Funcție care verifică existența unei valori

```cpp
bool exista(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
        if (a[i] == x)
            return true;

    return false;
}
```

Apel:

```cpp
if (exista(a, n, x))
    cout << "DA";
else
    cout << "NU";
```

---

# 51. Funcție care returnează poziția unui element

```cpp
int pozitie(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
        if (a[i] == x)
            return i;

    return -1;
}
```

`-1` poate indica faptul că elementul nu a fost găsit.

Dacă se dorește poziția începând de la `1`:

```cpp
return i + 1;
```

Este important să fii atent la convenția cerută în enunț.

---

# 52. Funcții și vectori — idee de reținut

Pentru un tablou:

```cpp
int a[100];
```

antetul poate fi:

```cpp
int f(int a[], int n)
```

sau, echivalent în acest context:

```cpp
int f(int a[100], int n)
```

Dimensiunea reală a tabloului este transmisă separat prin `n`.

---

# 53. Parametri `const` — noțiune utilă

În C++ se poate folosi `const` pentru a preciza că parametrul nu trebuie modificat.

Exemplu:

```cpp
void afisare(const int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
}
```

Pentru nivelul uzual de Bac, această formă nu este esențială, dar este corectă și poate fi întâlnită în cod C++.

---

# 54. Greșeli frecvente la subprograme

## 54.1. Uitarea lui `return`

Greșit:

```cpp
int suma(int a, int b)
{
    a + b;
}
```

Corect:

```cpp
int suma(int a, int b)
{
    return a + b;
}
```

---

## 54.2. Returnarea unei valori dintr-o funcție `void`

Greșit:

```cpp
void f()
{
    return 5;
}
```

Corect:

```cpp
int f()
{
    return 5;
}
```

---

## 54.3. Confuzia dintre `=` și `==`

```cpp
if (x == 5)
```

înseamnă comparare.

```cpp
x = 5;
```

înseamnă atribuire.

---

## 54.4. Confuzia dintre valoare și referință

```cpp
void f(int x)
```

nu modifică variabila originală prin atribuiri asupra lui `x`.

```cpp
void f(int &x)
```

poate modifica variabila originală.

---

## 54.5. Parametri incompatibili

Dacă funcția cere:

```cpp
int f(int a, int b)
```

apelul trebuie să îi furnizeze doi parametri compatibili:

```cpp
f(x, y);
```

Nu:

```cpp
f(x);
```

---

## 54.6. Uitarea dimensiunii la tablouri

```cpp
int suma(int a[], int n)
```

este forma corectă pentru a ști câte elemente trebuie parcurse.

---

## 54.7. Accesarea lui `a[0]` când tabloul este gol

Codul:

```cpp
int mx = a[0];
```

presupune că există cel puțin un element.

Dacă `n` poate fi `0`, trebuie tratat separat.

---

## 54.8. Caz de bază lipsă în recursivitate

Greșit:

```cpp
int f(int n)
{
    return f(n - 1);
}
```

Nu există o condiție de oprire.

---

# 55. Cum alegi între `return` și parametru prin referință?

Dacă ai nevoie de **un singur rezultat**, `return` este de obicei cea mai simplă soluție:

```cpp
int maxim(int a, int b)
{
    return a > b ? a : b;
}
```

Dacă ai nevoie de **mai multe rezultate**, poți folosi parametri prin referință:

```cpp
void minMax(int a, int b, int &mn, int &mx)
{
    mn = min(a, b);
    mx = max(a, b);
}
```

---

# 56. Subprogram pentru interschimbarea a două valori

Un exemplu clasic de transmitere prin referință:

```cpp
void swapValues(int &a, int &b)
{
    int aux = a;
    a = b;
    b = aux;
}
```

Apel:

```cpp
swapValues(x, y);
```

După apel, valorile lui `x` și `y` sunt inversate.

---

# 57. Funcții cu parametri de tip caracter

Exemplu:

```cpp
bool vocala(char c)
{
    return c == 'a' || c == 'e' || c == 'i' ||
           c == 'o' || c == 'u';
}
```

Apel:

```cpp
if (vocala(c))
    cout << "DA";
```

---

# 58. Funcții pentru șiruri

Exemplu — numărul de vocale:

```cpp
int nrVocale(char s[])
{
    int cnt = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == 'a' || s[i] == 'e' ||
            s[i] == 'i' || s[i] == 'o' ||
            s[i] == 'u')
        {
            cnt++;
        }
    }

    return cnt;
}
```

---

# 59. Funcții și caracterul `'\0'`

Un șir C-style se termină cu caracterul nul:

```cpp
'\0'
```

De aceea, parcurgerea unui șir poate fi făcută astfel:

```cpp
for (int i = 0; s[i] != '\0'; i++)
```

sau:

```cpp
int i = 0;

while (s[i] != '\0')
{
    ...
    i++;
}
```

---

# 60. Funcții pentru matrice

Un subprogram poate prelucra o matrice.

Exemplu — suma elementelor:

```cpp
int suma(int a[][100], int m, int n)
{
    int s = 0;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            s += a[i][j];

    return s;
}
```

Apel:

```cpp
cout << suma(a, m, n);
```

---

# 61. Funcție pentru suma unei linii

```cpp
int sumaLinie(int a[][100], int n, int linie)
{
    int s = 0;

    for (int j = 0; j < n; j++)
        s += a[linie][j];

    return s;
}
```

Atenție la convenția de indexare:

- în C++, prima linie are indicele `0`;
- a doua are indicele `1`;
- etc.

---

# 62. Funcție pentru suma unei coloane

```cpp
int sumaColoana(int a[][100], int m, int coloana)
{
    int s = 0;

    for (int i = 0; i < m; i++)
        s += a[i][coloana];

    return s;
}
```

---

# 63. Funcții pentru diagonalele unei matrice pătratice

Pentru o matrice `n x n`:

## Diagonala principală

Elementele sunt:

```text
a[0][0]
a[1][1]
a[2][2]
...
a[n-1][n-1]
```

Funcție:

```cpp
int sumaDiagPrincipala(int a[][100], int n)
{
    int s = 0;

    for (int i = 0; i < n; i++)
        s += a[i][i];

    return s;
}
```

## Diagonala secundară

Elementele sunt:

```text
a[0][n-1]
a[1][n-2]
...
a[n-1][0]
```

Funcție:

```cpp
int sumaDiagSecundara(int a[][100], int n)
{
    int s = 0;

    for (int i = 0; i < n; i++)
        s += a[i][n - 1 - i];

    return s;
}
```

---

# 64. Subprograme pentru sortare

Un subprogram poate implementa un algoritm de sortare.

Exemplu — sortare crescătoare prin selecție:

```cpp
void sortare(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int p = i;

        for (int j = i + 1; j < n; j++)
            if (a[j] < a[p])
                p = j;

        swap(a[i], a[p]);
    }
}
```

Apel:

```cpp
sortare(a, n);
```

---

# 65. Subprograme și algoritmi — avantaj important

Dacă ai nevoie să verifici dacă mai multe valori sunt prime, este mai bine să scrii o singură funcție:

```cpp
bool prim(int n)
{
    ...
}
```

și să o reutilizezi:

```cpp
for (int i = 0; i < n; i++)
    if (prim(a[i]))
        cout << a[i] << ' ';
```

În loc să repeți algoritmul de verificare a primalității de fiecare dată.

---

# 66. Cum identifici un subprogram într-un exercițiu de Bac

Când enunțul spune:

> „Scrieți un subprogram care...”

trebuie să:

1. identifici datele de intrare;
2. identifici rezultatul cerut;
3. alegi tipul rezultatului;
4. stabilești parametrii;
5. scrii corpul funcției;
6. returnezi rezultatul, dacă este cazul.

Exemplu:

> „Scrieți un subprogram care primește un număr natural `n` și returnează numărul cifrelor sale.”

Date:

```text
n — parametru
```

Rezultat:

```text
numărul de cifre — int
```

Soluție:

```cpp
int nrCifre(int n)
{
    int cnt = 0;

    if (n == 0)
        return 1;

    while (n != 0)
    {
        cnt++;
        n /= 10;
    }

    return cnt;
}
```

---

# 67. Cum alegi tipul funcției

Întreabă-te:

### Funcția trebuie să returneze un număr întreg?

```cpp
int
```

### Poate rezultatul depăși domeniul lui `int`?

```cpp
long long
```

### Rezultatul este adevărat/fals?

```cpp
bool
```

### Rezultatul este un caracter?

```cpp
char
```

### Funcția doar efectuează o acțiune?

```cpp
void
```

---

# 68. Cum rezolvi rapid un subprogram la Bac

O metodă sigură:

### Pasul 1 — identifică intrarea

Ce primește funcția?

Exemplu:

```text
n
```

sau:

```text
a, n
```

### Pasul 2 — identifică ieșirea

Ce trebuie să obțină?

Exemplu:

```text
numărul de elemente pare
```

### Pasul 3 — alege tipul

Dacă este un număr:

```cpp
int
```

### Pasul 4 — scrie scheletul

```cpp
int f(int n)
{
    ...
}
```

### Pasul 5 — implementează algoritmul

### Pasul 6 — verifică limitele și cazurile speciale

### Pasul 7 — verifică `return`

---

# 69. Exemplu complet de subprogram

Cerință:

> Scrieți funcția `nrPrime` care primește un tablou cu `n` numere naturale și returnează câte dintre acestea sunt prime.

Soluție:

```cpp
bool prim(int x)
{
    if (x < 2)
        return false;

    for (int d = 2; d * d <= x; d++)
        if (x % d == 0)
            return false;

    return true;
}

int nrPrime(int a[], int n)
{
    int cnt = 0;

    for (int i = 0; i < n; i++)
        if (prim(a[i]))
            cnt++;

    return cnt;
}
```

Observație:

Funcția `nrPrime` folosește subprogramul `prim`.

---

# 70. Subprograme în lanț

Un program poate avea o structură de tipul:

```text
main()
   |
   +-- nrPrime()
          |
          +-- prim()
```

Adică `main` apelează `nrPrime`, iar `nrPrime` apelează `prim`.

Această organizare este foarte utilă pentru probleme mai complexe.

---

# 71. Funcții care nu modifică parametrii

Exemplu:

```cpp
int suma(int a, int b)
{
    return a + b;
}
```

Parametrii sunt primiți prin valoare, deci modificările lor interne nu afectează variabilele din apelant.

---

# 72. Funcții care modifică parametrii

Exemplu:

```cpp
void ordoneaza(int &a, int &b)
{
    if (a > b)
        swap(a, b);
}
```

Apel:

```cpp
ordoneaza(x, y);
```

Dacă `x > y`, valorile lor vor fi schimbate.

---

# 73. Diferența dintre funcție și procedură

În terminologia folosită în alte limbaje:

- **funcție** — returnează o valoare;
- **procedură** — efectuează o acțiune fără să returneze o valoare.

În C++, ambele sunt implementate prin **funcții**:

```cpp
int suma(...)
```

și:

```cpp
void afisare(...)
```

---

# 74. Formule și șabloane utile de memorat

## Funcție numerică simplă

```cpp
int f(int x)
{
    ...
    return rezultat;
}
```

## Funcție booleană

```cpp
bool f(int x)
{
    if (...)
        return false;

    ...

    return true;
}
```

## Funcție `void`

```cpp
void f(int x)
{
    ...
}
```

## Tablou unidimensional

```cpp
int f(int a[], int n)
{
    ...
}
```

## Modificarea unui parametru

```cpp
void f(int &x)
{
    ...
}
```

## Mai multe rezultate

```cpp
void f(int x, int &r1, int &r2)
{
    ...
}
```

## Matrice

```cpp
int f(int a[][100], int m, int n)
{
    ...
}
```

## Recursivitate

```cpp
int f(int n)
{
    if (conditie_de_baza)
        return rezultat;

    return ... f(...);
}
```

---

# 76. Ideile esențiale de reținut

Pentru Bac, cele mai importante idei sunt:

1. Un subprogram este o secvență de instrucțiuni reutilizabilă.
2. În C++, subprogramele sunt funcții.
3. O funcție poate returna o valoare sau poate fi `void`.
4. `return` încheie funcția și poate transmite rezultatul.
5. Parametrii pot fi transmiși prin valoare sau prin referință.
6. `int &x` permite modificarea variabilei originale.
7. Tablourile pot fi transmise funcțiilor.
8. Pentru tablouri este necesar de obicei să transmiți numărul de elemente.
9. O funcție poate apela alte funcții.
10. O funcție se poate apela pe ea însăși — recursivitate.
11. Recursivitatea trebuie să aibă un caz de bază.
12. Funcțiile booleene sunt foarte utile pentru verificarea proprietăților.
13. Parametrii prin referință sunt utili pentru transmiterea mai multor rezultate sau pentru modificarea datelor.
14. Trebuie acordată atenție cazurilor speciale și limitelor tablourilor.
15. La subiectele de Bac, antetul funcției trebuie respectat exact când este precizat în cerință.
