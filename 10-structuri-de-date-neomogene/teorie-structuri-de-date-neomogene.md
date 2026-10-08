## 1. Ce sunt structurile de date neomogene?

O **structură de date neomogenă** este o structură care poate grupa, sub un singur nume, date de **tipuri diferite**.

În C++, mecanismul folosit pentru acest lucru este `struct`.

Exemplu:

```cpp
struct Elev
{
    char nume[31];
    int varsta;
    float medie;
};
```

Un element de tip `Elev` poate conține simultan:

- un șir de caractere (`nume`);
- un număr întreg (`varsta`);
- un număr real (`medie`).

Aceste componente se numesc **câmpuri** sau **membri** ai structurii.

---

# 2. Declararea unei structuri

Sintaxa generală:

```cpp
struct NumeStructura
{
    tip1 camp1;
    tip2 camp2;
    ...
    tipN campN;
};
```

Exemplu:

```cpp
struct Persoana
{
    char nume[31];
    int varsta;
};
```

Observație importantă:

- după `}` se pune **`;`**.

---

# 3. Declararea variabilelor de tip structură

După definirea structurii:

```cpp
struct Persoana
{
    char nume[31];
    int varsta;
};

Persoana p;
```

În C++ nu este obligatoriu să scriem din nou `struct` la declararea variabilei.

Se poate declara și direct:

```cpp
struct Persoana
{
    char nume[31];
    int varsta;
} p1, p2;
```

Aici `p1` și `p2` sunt variabile de tip `Persoana`.

---

# 4. Accesarea câmpurilor

Pentru accesarea unui câmp se folosește operatorul:

```cpp
.
```

Sintaxa:

```cpp
variabila.camp
```

Exemplu:

```cpp
p.varsta = 17;
p.medie = 9.75;
```

Pentru un câmp de tip șir de caractere:

```cpp
cin >> p.nume;
```

Exemplu complet:

```cpp
struct Elev
{
    char nume[31];
    int varsta;
    float medie;
};

Elev e;

cin >> e.nume;
cin >> e.varsta;
cin >> e.medie;

cout << e.nume << ' ' << e.varsta << ' ' << e.medie;
```

---

# 5. Inițializarea structurilor

O variabilă de tip structură poate fi inițializată la declarare:

```cpp
struct Punct
{
    int x;
    int y;
};

Punct p = {3, 5};
```

Astfel:

```text
p.x = 3
p.y = 5
```

Ordinea valorilor trebuie să corespundă ordinii câmpurilor.

---

# 6. Structuri cu alte tipuri de date

Câmpurile unei structuri pot fi de aproape orice tip de date valid.

Exemplu:

```cpp
struct Produs
{
    int cod;
    char denumire[51];
    float pret;
    int cantitate;
};
```

O structură poate conține:

- `int`
- `float`
- `double`
- `char`
- șiruri de caractere
- tablouri
- alte structuri

---

# 7. Structuri care conțin tablouri

Un câmp al unei structuri poate fi un tablou.

Exemplu:

```cpp
struct Elev
{
    char nume[31];
    int note[10];
};
```

Accesarea unei valori:

```cpp
e.note[0] = 10;
```

sau:

```cpp
cout << e.note[i];
```

Putem combina accesul la câmp și indexarea:

```cpp
e.note[i]
```

---

# 8. Tablouri de structuri

Foarte important pentru BAC.

Putem avea un tablou ale cărui elemente sunt structuri.

Exemplu:

```cpp
struct Elev
{
    char nume[31];
    float medie;
};

Elev v[100];
```

`v` este un tablou cu 100 de elemente de tip `Elev`.

Accesarea unui câmp:

```cpp
v[i].medie
```

Accesarea numelui:

```cpp
v[i].nume
```

---

# 9. Citirea unui tablou de structuri

Exemplu:

```cpp
int n;
cin >> n;

for (int i = 0; i < n; i++)
{
    cin >> v[i].nume;
    cin >> v[i].medie;
}
```

Dacă avem mai multe câmpuri:

```cpp
for (int i = 0; i < n; i++)
{
    cin >> v[i].nume;
    cin >> v[i].varsta;
    cin >> v[i].medie;
}
```

---

# 10. Prelucrarea unui tablou de structuri

Se folosesc aceleași idei ca la tablourile unidimensionale, dar în loc de `v[i]` prelucrăm un anumit câmp:

```cpp
v[i].camp
```

Exemplu — calcularea mediei mediilor:

```cpp
float s = 0;

for (int i = 0; i < n; i++)
    s += v[i].medie;

cout << s / n;
```

---

# 11. Determinarea maximului/minimului

Exemplu: determinarea elevului cu media maximă.

```cpp
int p = 0;

for (int i = 1; i < n; i++)
    if (v[i].medie > v[p].medie)
        p = i;

cout << v[p].nume;
```

Ideea importantă:

- `p` reține **poziția** elementului optim;
- comparația se face între câmpurile dorite;
- la final putem afișa orice câmp al elementului găsit.

---

# 12. Numărarea elementelor care respectă o condiție

Exemplu:

```cpp
int nr = 0;

for (int i = 0; i < n; i++)
    if (v[i].medie >= 9)
        nr++;

cout << nr;
```

---

# 13. Căutarea unui element

Exemplu: căutarea unui elev după nume.

```cpp
char x[31];
cin >> x;

int p = -1;

for (int i = 0; i < n; i++)
    if (strcmp(v[i].nume, x) == 0)
    {
        p = i;
        break;
    }
```

Dacă `p == -1`, elementul nu a fost găsit.

Dacă `p != -1`, elementul se află pe poziția `p`.

Pentru `strcmp`:

```cpp
#include <cstring>
```

---

# 14. Compararea șirurilor din structuri

Șirurile de caractere nu se compară cu `==` în C-style strings.

Greșit:

```cpp
if (v[i].nume == x)
```

Corect:

```cpp
if (strcmp(v[i].nume, x) == 0)
```

Pentru ordine lexicografică:

```cpp
strcmp(v[i].nume, x) < 0
```

înseamnă că `v[i].nume` apare înaintea lui `x`.

```cpp
strcmp(v[i].nume, x) > 0
```

înseamnă că `v[i].nume` apare după `x`.

```cpp
strcmp(v[i].nume, x) == 0
```

înseamnă că sunt egale.

---

# 15. Sortarea unui tablou de structuri

La BAC apare frecvent sortarea după un anumit câmp.

Exemplu: sortare crescătoare după medie.

```cpp
for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
        if (v[i].medie > v[j].medie)
        {
            Elev aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
```

Observația esențială:

```cpp
Elev aux;
```

poate primi **întreaga structură**, nu doar un câmp.

Putem scrie:

```cpp
Elev aux = v[i];
v[i] = v[j];
v[j] = aux;
```

---

# 16. Sortarea după mai multe criterii

Uneori trebuie să sortăm:

1. după un criteriu principal;
2. iar la egalitate după un criteriu secundar.

Exemplu:

- medie descrescător;
- la aceeași medie, nume crescător.

```cpp
for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
        if (v[i].medie < v[j].medie ||
           (v[i].medie == v[j].medie &&
            strcmp(v[i].nume, v[j].nume) > 0))
        {
            Elev aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
```

Modelul general:

```cpp
if (criteriul_principal ||
    (egalitate_criteriu_principal && criteriul_secundar))
```

---

# 17. Structuri transmise parametrilor

O structură poate fi transmisă unei funcții.

Exemplu:

```cpp
struct Punct
{
    int x;
    int y;
};

void afisare(Punct p)
{
    cout << p.x << ' ' << p.y;
}
```

Apel:

```cpp
Punct p = {2, 5};
afisare(p);
```

---

# 18. Funcții care returnează structuri

O funcție poate avea ca rezultat o structură.

Exemplu:

```cpp
Punct mijloc(Punct a, Punct b)
{
    Punct c;

    c.x = (a.x + b.x) / 2;
    c.y = (a.y + b.y) / 2;

    return c;
}
```

Apel:

```cpp
Punct m = mijloc(a, b);
```

---

# 19. Structuri imbricate

O structură poate conține o variabilă de alt tip structură.

Exemplu:

```cpp
struct Data
{
    int zi;
    int luna;
    int an;
};

struct Persoana
{
    char nume[31];
    Data nastere;
};
```

Accesarea câmpurilor:

```cpp
p.nastere.zi
p.nastere.luna
p.nastere.an
```

Observație:

```cpp
p.nastere
```

este o structură de tip `Data`.

---

# 20. Tablouri în structuri + structuri în tablouri

Pot exista combinații.

Exemplu:

```cpp
struct Elev
{
    char nume[31];
    int note[10];
};

Elev v[100];
```

Pentru nota `j` a elevului `i`:

```cpp
v[i].note[j]
```

Aceasta se citește:

> nota `j` din structura `v[i]`.

---

# 21. Pointeri la structuri

Putem avea un pointer către o structură:

```cpp
Elev e;
Elev *p = &e;
```

Accesarea câmpurilor prin pointer se poate face cu operatorul:

```cpp
->
```

Exemplu:

```cpp
p->medie = 9.50;
```

Este echivalent cu:

```cpp
(*p).medie = 9.50;
```

La BAC, trebuie să recunoști diferența:

```cpp
e.medie
```

pentru o variabilă structură;

```cpp
p->medie
```

pentru un pointer la structură.

---

# 22. `.` vs `->`

## Variabilă de tip structură

```cpp
Elev e;

e.medie
```

## Pointer la structură

```cpp
Elev *p = &e;

p->medie
```

Regulă de memorat:

```text
structură       → .
pointer         → ->
```

---

# 23. Transmiterea prin adresă

O structură poate fi transmisă prin adresă:

```cpp
void modifica(Elev *e)
{
    e->medie = 10;
}
```

Apel:

```cpp
modifica(&e);
```

Sau prin referință:

```cpp
void modifica(Elev &e)
{
    e.medie = 10;
}
```

Apel:

```cpp
modifica(e);
```

Pentru nivelul uzual de BAC, este important în primul rând să poți recunoaște și utiliza accesul la câmpuri.

---

# 24. Copierea structurilor

Două variabile de același tip structură pot fi atribuite direct:

```cpp
Elev a, b;

a = b;
```

Se copiază toate câmpurile structurii.

De asemenea:

```cpp
Elev aux = v[i];
```

creează o copie a structurii `v[i]`.

Acest lucru este foarte util la sortare.

---

# 25. Structuri și șiruri de caractere

Exemplu:

```cpp
struct Carte
{
    char titlu[101];
    char autor[51];
    int an;
};
```

Citirea cu `cin`:

```cpp
cin >> c.titlu;
cin >> c.autor;
cin >> c.an;
```

`cin >>` citește până la spațiu.

Dacă textul poate conține spații, se poate folosi:

```cpp
cin.getline(c.titlu, 101);
```

Dar trebuie ținut cont de caracterul `'\n'` rămas în flux după `cin >>`.

---

# 26. `struct` cu câmpuri de tip `char`

Un singur caracter:

```cpp
struct Produs
{
    char categorie;
    int pret;
};
```

Se citește:

```cpp
cin >> p.categorie;
```

Un șir de caractere:

```cpp
struct Produs
{
    char denumire[51];
    int pret;
};
```

Se citește:

```cpp
cin >> p.denumire;
```

Diferența:

```text
char x;          → un caracter
char x[51];      → un șir de caractere
```

---

# 27. Structuri și fișiere

Structurile pot fi folosite pentru organizarea datelor citite din fișiere.

Exemplu:

```cpp
ifstream fin("date.in");

int n;
fin >> n;

for (int i = 0; i < n; i++)
{
    fin >> v[i].nume;
    fin >> v[i].medie;
}
```

Afișarea poate fi făcută în fișier:

```cpp
ofstream fout("date.out");

fout << v[i].nume << ' ' << v[i].medie;
```

---

# 28. Model clasic de problemă

Se citesc `n` elevi, fiecare având nume și medie. Să se afișeze elevul cu media maximă.

```cpp
#include <iostream>
#include <cstring>
using namespace std;

struct Elev
{
    char nume[31];
    float medie;
};

int main()
{
    Elev v[100];
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].nume;
        cin >> v[i].medie;
    }

    int p = 0;

    for (int i = 1; i < n; i++)
        if (v[i].medie > v[p].medie)
            p = i;

    cout << v[p].nume;

    return 0;
}
```

---

# 29. Model: numărare + condiție pe mai multe câmpuri

Exemplu:

> Se numără persoanele cu vârsta de cel puțin 18 ani și media cel puțin 9.

```cpp
int nr = 0;

for (int i = 0; i < n; i++)
    if (v[i].varsta >= 18 && v[i].medie >= 9)
        nr++;
```

Criteriile pot combina orice câmpuri ale structurii.

---

# 30. Model: căutarea tuturor elementelor

Dacă trebuie afișate toate elementele care respectă o condiție:

```cpp
for (int i = 0; i < n; i++)
    if (v[i].medie >= 9)
        cout << v[i].nume << ' ';
```

Nu folosim `break` dacă trebuie afișate **toate** elementele.

---

# 31. Model: eliminarea unui element dintr-un tablou de structuri

Dacă trebuie eliminat elementul de pe poziția `p`:

```cpp
for (int i = p; i < n - 1; i++)
    v[i] = v[i + 1];

n--;
```

Observație:

```cpp
v[i] = v[i + 1];
```

copiază întreaga structură.

---

# 32. Model: inserarea unui element

Pentru inserarea unui element pe poziția `p`:

```cpp
for (int i = n; i > p; i--)
    v[i] = v[i - 1];

v[p] = element;
n++;
```

Trebuie să existe suficient spațiu în tablou.

---

# 33. Criterii de comparare uzuale

Pentru numere:

```cpp
v[i].x < v[j].x
v[i].x > v[j].x
v[i].x == v[j].x
```

Pentru șiruri:

```cpp
strcmp(v[i].nume, v[j].nume) < 0
strcmp(v[i].nume, v[j].nume) > 0
strcmp(v[i].nume, v[j].nume) == 0
```

Pentru combinații:

```cpp
if (v[i].nota > v[j].nota ||
   (v[i].nota == v[j].nota &&
    strcmp(v[i].nume, v[j].nume) < 0))
```

---

# 34. Greșeli frecvente

## 34.1. Uitarea `;` după structură

Greșit:

```cpp
struct Elev
{
    int varsta;
}
```

Corect:

```cpp
struct Elev
{
    int varsta;
};
```

---

## 34.2. Confuzia dintre structură și câmp

Greșit:

```cpp
cout << v[i];
```

Dacă `v[i]` este o structură, nu putem afișa în mod obișnuit structura întreagă cu `cout`.

Trebuie indicat câmpul:

```cpp
cout << v[i].nume;
```

sau:

```cpp
cout << v[i].medie;
```

---

## 34.3. Compararea directă a șirurilor C-style

Greșit:

```cpp
if (v[i].nume == x)
```

Corect:

```cpp
if (strcmp(v[i].nume, x) == 0)
```

---

## 34.4. Folosirea greșită a `.` și `->`

Dacă ai:

```cpp
Elev e;
```

folosești:

```cpp
e.medie
```

Dacă ai:

```cpp
Elev *p;
```

folosești:

```cpp
p->medie
```

---

## 34.5. Sortarea după câmpul greșit

Într-o sortare trebuie verificat exact criteriul cerut.

Exemplu:

```cpp
if (v[i].medie > v[j].medie)
```

nu este același lucru cu:

```cpp
if (v[i].varsta > v[j].varsta)
```

---

## 34.6. Pierderea celorlalte câmpuri la sortare

Greșit:

```cpp
swap(v[i].medie, v[j].medie);
```

Dacă trebuie mutat un elev în întregime, nu trebuie schimbată doar media.

Corect:

```cpp
Elev aux = v[i];
v[i] = v[j];
v[j] = aux;
```

Astfel numele, media, vârsta etc. rămân asociate aceluiași elev.