# Alocarea dinamică a memoriei 

## 1. Ce este alocarea dinamică?

**Alocarea dinamică a memoriei** înseamnă rezervarea memoriei în timpul executării programului, atunci când dimensiunea necesară poate fi stabilită abia la rulare.

Este utilă când:
- nu cunoaștem dinainte numărul de elemente;
- dorim să rezervăm exact memoria necesară;
- avem nevoie de zone de memorie create în timpul execuției.

În C++, operatorii uzuali sunt:
- `new` — alocă memorie pentru un obiect;
- `delete` — eliberează memoria alocată cu `new`;
- `new[]` — alocă un tablou dinamic;
- `delete[]` — eliberează un tablou dinamic.

## 2. Pointeri — noțiuni de bază

Un **pointer** este o variabilă care memorează adresa unei alte variabile sau a unei zone de memorie.

```cpp
int x = 10;
int *p = &x;
```

- `x` are valoarea `10`;
- `&x` reprezintă adresa lui `x`;
- `p` memorează adresa lui `x`;
- `*p` reprezintă valoarea de la adresa memorată în `p`.

```cpp
cout << x;   // 10
cout << *p;  // 10
*p = 25;     // x devine 25
```

Operatori importanți:

| Operator | Semnificație |
|---|---|
| `&x` | adresa variabilei `x` |
| `*p` | valoarea aflată la adresa memorată de `p` |
| `new` | alocare dinamică |
| `delete` | eliberarea unei zone alocate dinamic |

Simbolul `*` este folosit atât în declararea unui pointer (`int *p`), cât și la dereferențiere (`*p`).

## 3. Pointer neinițializat și pointer nul

Un pointer neinițializat nu trebuie dereferențiat:

```cpp
int *p;
```

`p` nu indică în mod garantat o zonă validă de memorie.

Un pointer poate fi inițializat cu `nullptr`:

```cpp
int *p = nullptr;
```

Nu dereferenția un pointer nul:

```cpp
cout << *p; // invalid dacă p este nullptr
```

Pointerul trebuie să indice o zonă validă înainte de a accesa valoarea prin el.

## 4. Alocarea dinamică a unei singure variabile

Sintaxă:

```cpp
tip *p = new tip;
```

Exemplu:

```cpp
int *p = new int;
*p = 7;
cout << *p;

delete p;
p = nullptr;
```

Inițializare directă:

```cpp
int *p = new int(7);
```

După `delete p`, memoria a fost eliberată și nu trebuie accesată prin acel pointer.

## 5. Alocarea unui tablou dinamic

Dacă dimensiunea tabloului este cunoscută numai la rulare, folosim `new[]`:

```cpp
int n;
cin >> n;

int *v = new int[n];
```

Elementele se accesează ca într-un tablou obișnuit:

```cpp
v[0] = 10;
v[1] = 20;
cout << v[0];
```

Pentru `n` elemente, indicii valizi sunt `0, 1, ..., n-1`.

Citire:

```cpp
for (int i = 0; i < n; i++)
    cin >> v[i];
```

Afișare:

```cpp
for (int i = 0; i < n; i++)
    cout << v[i] << ' ';
```

Eliberare:

```cpp
delete[] v;
v = nullptr;
```

**Regulă esențială:** memoria alocată cu `new[]` se eliberează cu `delete[]`, nu cu `delete`.

## 6. `new` versus `new[]`

```cpp
int *p = new int;       // un singur int
delete p;
```

```cpp
int *v = new int[n];    // tablou de n int-uri
delete[] v;
```

| Alocare | Eliberare corectă |
|---|---|
| `new tip` | `delete p` |
| `new tip[n]` | `delete[] p` |

Folosirea perechii greșite produce comportament nedefinit.

## 7. Exemplu complet: tablou dinamic

```cpp
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int *v = new int[n];

    for (int i = 0; i < n; i++)
        cin >> v[i];

    int s = 0;
    for (int i = 0; i < n; i++)
        s += v[i];

    cout << s;

    delete[] v;
    v = nullptr;

    return 0;
}
```

Programul citește numărul de elemente, alocă tabloul, citește valorile, calculează suma și eliberează memoria. Exemplul presupune că `n` este valid și nenegativ.

## 8. Inițializarea elementelor

Poți inițializa elementele în buclă:

```cpp
int *v = new int[n];

for (int i = 0; i < n; i++)
    v[i] = 0;
```

În C++ este posibil și:

```cpp
int *v = new int[n]{};
```

Aceasta inițializează elementele numerice cu zero.

## 9. Pointer și tablou

Accesarea prin index:

```cpp
v[i]
```

este echivalentă cu:

```cpp
*(v + i)
```

Exemplu:

```cpp
v[2] = 15;
```

echivalează cu:

```cpp
*(v + 2) = 15;
```

Forma `v[i]` este de obicei mai clară. Pointerul nu memorează automat dimensiunea tabloului, deci trebuie păstrat separat `n`.

## 10. Transmiterea pointerilor către funcții

Un pointer poate fi parametru al unei funcții:

```cpp
void afisare(const int *v, int n)
{
    for (int i = 0; i < n; i++)
        cout << v[i] << ' ';
}
```

Apel:

```cpp
afisare(v, n);
```

Numărul de elemente se transmite separat, deoarece pointerul nu conține automat lungimea tabloului.

Pentru modificarea elementelor:

```cpp
void dubleaza(int *v, int n)
{
    for (int i = 0; i < n; i++)
        v[i] *= 2;
}
```

Apelul `dubleaza(v, n);` modifică elementele tabloului.

## 11. Funcție care alocă și returnează un tablou

```cpp
int* creeazaVector(int n)
{
    int *v = new int[n];

    for (int i = 0; i < n; i++)
        v[i] = 0;

    return v;
}
```

Utilizare:

```cpp
int *a = creeazaVector(n);

// folosirea lui a

delete[] a;
a = nullptr;
```

Memoria trebuie eliberată numai după terminarea utilizării ei. În C++ modern, proiectele obișnuite folosesc adesea `vector`, dar `new` și `delete` sunt importante pentru înțelegerea pointerilor și pentru exercițiile care le cer explicit.

## 12. Tablouri bidimensionale dinamice

O matrice cu `m` rânduri și `n` coloane poate fi reprezentată ca un tablou de pointeri, fiecare indicând un rând:

```cpp
int **a = new int*[m];

for (int i = 0; i < m; i++)
    a[i] = new int[n];
```

Accesarea elementului de pe rândul `i`, coloana `j`:

```cpp
a[i][j]
```

Citire:

```cpp
for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
        cin >> a[i][j];
```

Afișare:

```cpp
for (int i = 0; i < m; i++)
{
    for (int j = 0; j < n; j++)
        cout << a[i][j] << ' ';
    cout << '\\n';
}
```

Eliberare corectă — întâi fiecare rând, apoi tabloul de pointeri:

```cpp
for (int i = 0; i < m; i++)
    delete[] a[i];

delete[] a;
a = nullptr;
```

Fiecare zonă alocată cu `new[]` trebuie eliberată cu `delete[]`.

## 13. Matrice dinamică — exemplu complet

```cpp
#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    int **a = new int*[m];

    for (int i = 0; i < m; i++)
        a[i] = new int[n];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << ' ';
        cout << '\\n';
    }

    for (int i = 0; i < m; i++)
        delete[] a[i];

    delete[] a;
    a = nullptr;

    return 0;
}
```

Această reprezentare alocă fiecare rând separat; rândurile pot avea și lungimi diferite dacă problema cere o astfel de structură.

## 14. Alocarea dinamică a unei structuri

```cpp
struct Punct
{
    int x;
    int y;
};

Punct *p = new Punct;
p->x = 3;
p->y = 4;

delete p;
p = nullptr;
```

Operatorul `->` este echivalent cu dereferențierea urmată de punct:

```cpp
(*p).x = 3;
```

Tablou dinamic de structuri:

```cpp
Punct *v = new Punct[n];

v[0].x = 1;
v[0].y = 2;

delete[] v;
v = nullptr;
```

- Pentru un pointer la structură: `p->x`.
- Pentru un element dintr-un tablou de structuri: `v[i].x`.

## 15. Alocare dinamică pentru șiruri de caractere

Un șir C are nevoie și de spațiu pentru terminatorul `\\0`.

```cpp
#include <iostream>
using namespace std;

int main()
{
    char *s = new char[101];

    cin.getline(s, 101);
    cout << s;

    delete[] s;
    s = nullptr;

    return 0;
}
```

`cin.getline(s, 101)` poate citi cel mult 100 de caractere utile, apoi adaugă terminatorul șirului.

## 16. Erori frecvente

### 16.1. Pointer neinițializat

Greșit:

```cpp
int *p;
*p = 5;
```

Corect:

```cpp
int *p = new int;
*p = 5;
delete p;
```

### 16.2. Eliberarea greșită

Greșit:

```cpp
int *v = new int[n];
delete v;
```

Corect:

```cpp
delete[] v;
```

### 16.3. Acces în afara tabloului

Greșit:

```cpp
for (int i = 0; i <= n; i++)
    cin >> v[i];
```

Corect:

```cpp
for (int i = 0; i < n; i++)
    cin >> v[i];
```

### 16.4. Folosirea după eliberare

Greșit:

```cpp
delete[] v;
cout << v[0];
```

După eliberare, memoria nu mai poate fi accesată prin pointerul respectiv.

### 16.5. Eliberarea de două ori

Greșit:

```cpp
delete[] v;
delete[] v;
```

O zonă de memorie nu trebuie eliberată de două ori. După eliberare, poți scrie `v = nullptr;`.

### 16.6. Pierderea adresei alocate

```cpp
int *p = new int[10];
p = nullptr;
```

Adresa inițială s-a pierdut, deci zona nu mai poate fi eliberată prin `p`. Aceasta este o **pierdere de memorie** (*memory leak*). Eliberează memoria înainte de a pierde ultimul pointer care o indică.

### 16.7. Eliberarea incorectă a unei matrice

Dacă fiecare rând a fost alocat separat, eliberează fiecare rând înainte de tabloul de pointeri:

```cpp
for (int i = 0; i < m; i++)
    delete[] a[i];

delete[] a;
```

## 17. Alocare automată versus dinamică

| Alocare automată uzuală | Alocare dinamică |
|---|---|
| Exemplu: `int x;`, `int v[100];` | Exemplu: `int *v = new int[n];` |
| Durata de viață a variabilelor locale obișnuite este gestionată automat. | Memoria alocată cu `new` trebuie eliberată cu `delete` sau `delete[]`. |
| Dimensiunea tabloului obișnuit este fixată la declarare. | Dimensiunea poate fi stabilită în timpul execuției. |

În C++ standard, `int v[n];` nu este o declarație standard de tablou obișnuit dacă `n` este o variabilă citită la execuție. Unele compilatoare acceptă această extensie; pentru portabilitate, folosește alocare dinamică sau `vector`.

## 18. Complexitatea operațiilor

Pentru un tablou dinamic cu `n` elemente:
- accesarea lui `v[i]`: \(O(1)\);
- parcurgerea tuturor elementelor: \(O(n)\);
- citirea tuturor elementelor: \(O(n)\);
- calcularea sumei: \(O(n)\).

Pentru o matrice de `m × n` elemente, parcurgerea tuturor elementelor este \(O(mn)\).

## 19. Exemplu: maximul unui tablou dinamic

```cpp
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n <= 0)
        return 0;

    int *v = new int[n];

    for (int i = 0; i < n; i++)
        cin >> v[i];

    int maxim = v[0];

    for (int i = 1; i < n; i++)
        if (v[i] > maxim)
            maxim = v[i];

    cout << maxim;

    delete[] v;
    v = nullptr;

    return 0;
}
```

## 20. Funcție care calculează suma

```cpp
int suma(const int *v, int n)
{
    int s = 0;

    for (int i = 0; i < n; i++)
        s += v[i];

    return s;
}
```

Apel:

```cpp
int *v = new int[n];

// citirea elementelor

cout << suma(v, n);

delete[] v;
```

`const int *v` arată că funcția nu modifică elementele prin pointerul primit.
