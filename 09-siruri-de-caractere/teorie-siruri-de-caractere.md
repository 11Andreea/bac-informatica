# Șiruri de caractere

## 1. Ce este un șir de caractere?

Un **șir de caractere** este o succesiune de caractere.

În C++, șirurile de caractere pot fi reprezentate prin tablouri de caractere:

```cpp
char s[101];
```

Dacă șirul este `Ana`, în memorie avem:

```text
A n a \0
```

Caracterul `'\0'` este **terminatorul de șir** și marchează sfârșitul șirului.

### Lungimea șirului

Lungimea nu include caracterul `'\0'`.

Pentru `Ana`:

```text
lungime = 3
```

---

## 2. Declararea șirurilor

```cpp
char s[101];
```

Poate memora cel mult **100 de caractere**, deoarece o poziție este necesară pentru `'\0'`.

### Inițializare

```cpp
char s[] = "Ana";
```

sau:

```cpp
char s[4] = "Ana";
```

Este echivalent cu:

```text
A n a \0
```

### Atenție

```cpp
char s[3] = "Ana";
```

este greșit pentru un șir C valid, deoarece nu mai există loc pentru `'\0'`.

---

# 3. Citirea șirurilor

## 3.1. `cin >> s`

```cpp
cin >> s;
```

Citește un șir până la primul caracter alb:

- spațiu
- tab
- Enter

De exemplu, pentru:

```text
Ana Maria
```

se citește doar:

```text
Ana
```

---

## 3.2. `cin.getline(s, n)`

```cpp
cin.getline(s, n);
```

Citește o linie întreagă, inclusiv spațiile, până la Enter.

`n` reprezintă dimensiunea tabloului.

Exemplu:

```cpp
char s[101];
cin.getline(s, 101);
```

Poate citi cel mult 100 de caractere, deoarece unul este rezervat pentru `'\0'`.

### După `cin >>`

Dacă înainte ai folosit:

```cpp
cin >> x;
```

și apoi:

```cpp
cin.getline(s, 101);
```

poate fi necesar:

```cpp
cin.get();
```

pentru a elimina Enter-ul rămas în flux.

---

# 4. Accesarea caracterelor

Caracterele sunt indexate de la `0`.

Pentru:

```cpp
char s[] = "informatica";
```

avem:

```text
s[0] = 'i'
s[1] = 'n'
s[2] = 'f'
...
```

Ultimul caracter propriu-zis se află la:

```cpp
s[strlen(s)-1]
```

---

# 5. Parcurgerea unui șir

## Cu lungimea cunoscută

```cpp
for(int i = 0; i < strlen(s); i++)
    cout << s[i];
```

## Până la terminator

Aceasta este forma foarte importantă la BAC:

```cpp
for(int i = 0; s[i] != '\0'; i++)
    cout << s[i];
```

sau:

```cpp
int i = 0;
while(s[i] != '\0')
{
    // prelucrare
    i++;
}
```

---

# 6. `strlen`

Pentru folosirea funcției:

```cpp
strlen(s)
```

se include:

```cpp
#include <cstring>
```

`strlen(s)` returnează numărul de caractere din șir, fără `'\0'`.

Exemplu:

```cpp
char s[] = "abcde";
cout << strlen(s);
```

Rezultat:

```text
5
```

### Important

`strlen` nu modifică șirul.

---

# 7. Caractere și coduri ASCII

Caracterele au coduri numerice.

Cele mai importante relații:

```text
'A' ... 'Z'
'a' ... 'z'
'0' ... '9'
```

Pentru literele alfabetului englez:

```text
'A' < 'B' < ... < 'Z'
'a' < 'b' < ... < 'z'
```

În ASCII:

```text
'A' = 65
'a' = 97
'0' = 48
```

Diferența dintre o literă mare și litera mică corespunzătoare este:

```text
32
```

---

# 8. Testarea tipului unui caracter

Funcțiile uzuale se află în:

```cpp
#include <cctype>
```

## `isdigit(c)`

Verifică dacă `c` este cifră.

```cpp
if(isdigit(s[i]))
```

---

## `isalpha(c)`

Verifică dacă este literă.

```cpp
if(isalpha(s[i]))
```

---

## `islower(c)`

Verifică dacă este literă mică.

```cpp
if(islower(s[i]))
```

---

## `isupper(c)`

Verifică dacă este literă mare.

```cpp
if(isupper(s[i]))
```

---

## `isspace(c)`

Verifică dacă este caracter alb.

```cpp
if(isspace(s[i]))
```

Poate identifica spații și alte caractere albe.

---

# 9. Transformarea literelor

## `tolower`

Transformă o literă în literă mică:

```cpp
c = tolower(c);
```

## `toupper`

Transformă o literă în literă mare:

```cpp
c = toupper(c);
```

Exemplu:

```cpp
char c = 'a';
c = toupper(c);
```

Acum:

```text
c = 'A'
```

---

# 10. Compararea caracterelor

Caracterele pot fi comparate direct:

```cpp
if(s[i] == 'a')
```

```cpp
if(s[i] >= 'a' && s[i] <= 'z')
```

```cpp
if(s[i] >= '0' && s[i] <= '9')
```

### Exemplu: numărarea literelor `a`

```cpp
int nr = 0;

for(int i = 0; s[i] != '\0'; i++)
    if(s[i] == 'a')
        nr++;
```

---

# 11. Compararea șirurilor

## `strcmp`

Pentru compararea lexicografică a două șiruri:

```cpp
strcmp(s1, s2)
```

Necesită:

```cpp
#include <cstring>
```

Rezultatul:

```text
strcmp(s1, s2) == 0    → șirurile sunt egale
strcmp(s1, s2) < 0     → s1 este înaintea lui s2
strcmp(s1, s2) > 0     → s1 este după s2
```

Exemplu:

```cpp
if(strcmp(s1, s2) == 0)
    cout << "egale";
```

### Foarte important

Nu compara șirurile cu:

```cpp
if(s1 == s2)
```

pentru a verifica egalitatea conținutului unui șir C.

Folosește:

```cpp
strcmp(s1, s2) == 0
```

---

# 12. Copierea șirurilor — `strcpy`

```cpp
strcpy(destinatie, sursa);
```

Exemplu:

```cpp
char s1[101], s2[101];

cin >> s1;
strcpy(s2, s1);
```

Acum `s2` conține o copie a lui `s1`.

Necesită:

```cpp
#include <cstring>
```

### Atenție

Destinația trebuie să aibă suficient spațiu pentru șir și `'\0'`.

---

# 13. Concatenarea — `strcat`

Concatenează al doilea șir la primul:

```cpp
strcat(s1, s2);
```

Dacă:

```text
s1 = "Ana"
s2 = "Maria"
```

după:

```cpp
strcat(s1, s2);
```

obținem:

```text
s1 = "AnaMaria"
```

Pentru spațiu:

```cpp
strcat(s1, " ");
strcat(s1, s2);
```

Rezultatul:

```text
Ana Maria
```

Destinația trebuie să aibă suficient spațiu.

---

# 14. Căutarea unui caracter — `strchr`

```cpp
strchr(s, c)
```

caută prima apariție a caracterului `c` în șirul `s`.

Exemplu:

```cpp
char *p = strchr(s, 'a');
```

Dacă nu există caracterul, rezultatul este `nullptr`.

La nivel de BAC, de cele mai multe ori este mai simplu și mai sigur să cauți manual:

```cpp
int poz = -1;

for(int i = 0; s[i] != '\0'; i++)
    if(s[i] == 'a')
    {
        poz = i;
        break;
    }
```

---

# 15. Căutarea unui subșir — `strstr`

```cpp
strstr(s, sub)
```

caută prima apariție a șirului `sub` în `s`.

Exemplu:

```cpp
if(strstr(s, "ana") != nullptr)
    cout << "gasit";
```

---

# 16. Ștergerea unui caracter

Nu există o funcție standard simplă pe care să te bazezi la BAC pentru ștergerea unui caracter dintr-un tablou de caractere.

Metoda clasică:

Dacă vrem să ștergem caracterul de pe poziția `p`:

```cpp
for(int i = p; i < strlen(s); i++)
    s[i] = s[i+1];
```

Exemplu:

```text
s = "abcdef"
p = 2
```

După ștergere:

```text
"abdef"
```

### Variantă mai eficientă

Calculăm lungimea o singură dată:

```cpp
int n = strlen(s);

for(int i = p; i < n; i++)
    s[i] = s[i+1];
```

---

# 17. Inserarea unui caracter

Pentru a insera caracterul `c` pe poziția `p`:

```cpp
int n = strlen(s);

for(int i = n; i >= p; i--)
    s[i+1] = s[i];

s[p] = c;
```

Observă că deplasarea se face **de la dreapta la stânga**, pentru a nu pierde caracterele.

---

# 18. Înlocuirea unui caracter

Pentru a înlocui toate aparițiile lui `a` cu `b`:

```cpp
for(int i = 0; s[i] != '\0'; i++)
    if(s[i] == 'a')
        s[i] = 'b';
```

Pentru prima apariție:

```cpp
for(int i = 0; s[i] != '\0'; i++)
    if(s[i] == 'a')
    {
        s[i] = 'b';
        break;
    }
```

---

# 19. Numărarea caracterelor

## Numărul de litere

```cpp
int nr = 0;

for(int i = 0; s[i] != '\0'; i++)
    if(isalpha(s[i]))
        nr++;
```

## Numărul de cifre

```cpp
int nr = 0;

for(int i = 0; s[i] != '\0'; i++)
    if(isdigit(s[i]))
        nr++;
```

## Numărul de vocale

```cpp
int nr = 0;

for(int i = 0; s[i] != '\0'; i++)
{
    char c = tolower(s[i]);

    if(c == 'a' || c == 'e' || c == 'i' ||
       c == 'o' || c == 'u')
        nr++;
}
```

---

# 20. Prima și ultima apariție a unui caracter

## Prima apariție

```cpp
int poz = -1;

for(int i = 0; s[i] != '\0'; i++)
    if(s[i] == 'a')
    {
        poz = i;
        break;
    }
```

## Ultima apariție

```cpp
int poz = -1;

for(int i = 0; s[i] != '\0'; i++)
    if(s[i] == 'a')
        poz = i;
```

Dacă `poz == -1`, caracterul nu apare.

---

# 21. Inversarea unui șir

Se folosesc doi indici:

```cpp
int i = 0;
int j = strlen(s) - 1;

while(i < j)
{
    swap(s[i], s[j]);
    i++;
    j--;
}
```

Pentru:

```text
abcde
```

obținem:

```text
edcba
```

---

# 22. Verificarea dacă un șir este palindrom

Un palindrom se citește la fel de la stânga la dreapta și de la dreapta la stânga.

Exemple:

```text
radar
ana
abba
```

Algoritm:

```cpp
int i = 0;
int j = strlen(s) - 1;
bool ok = true;

while(i < j)
{
    if(s[i] != s[j])
    {
        ok = false;
        break;
    }

    i++;
    j--;
}
```

---

# 23. Numărul de cuvinte dintr-un text

Considerăm cuvintele separate printr-un singur spațiu și fără spații la început/sfârșit.

O metodă simplă:

```cpp
int nr = 0;

for(int i = 0; s[i] != '\0'; i++)
    if(s[i] != ' ' && (i == 0 || s[i-1] == ' '))
        nr++;
```

Ideea:

Un cuvânt începe:
- la poziția `0`, sau
- imediat după un spațiu.

---

# 24. Prelucrarea cuvintelor

Foarte multe exerciții de BAC cer prelucrarea unui text **cuvânt cu cuvânt**.

Tiparul de bază:

```cpp
int i = 0;

while(s[i] != '\0')
{
    while(s[i] == ' ')
        i++;

    int start = i;

    while(s[i] != ' ' && s[i] != '\0')
        i++;

    int stop = i - 1;

    // cuvantul este intre start si stop
}
```

Acest tipar permite:
- numărarea cuvintelor;
- găsirea celui mai lung cuvânt;
- găsirea celui mai scurt cuvânt;
- verificarea unor proprietăți ale fiecărui cuvânt;
- numărarea cuvintelor care respectă o condiție.

---

# 25. Cel mai lung cuvânt

```cpp
int i = 0;
int maxim = 0;

while(s[i] != '\0')
{
    while(s[i] == ' ')
        i++;

    int start = i;

    while(s[i] != ' ' && s[i] != '\0')
        i++;

    int lungime = i - start;

    if(lungime > maxim)
        maxim = lungime;
}
```

Dacă trebuie reținut și cuvântul, se memorează poziția de început și lungimea.

---

# 26. Cel mai scurt cuvânt

Ideea este identică, dar căutăm minimul:

```cpp
int minim = 1000000;

int i = 0;

while(s[i] != '\0')
{
    while(s[i] == ' ')
        i++;

    int start = i;

    while(s[i] != ' ' && s[i] != '\0')
        i++;

    int lungime = i - start;

    if(lungime < minim)
        minim = lungime;
}
```

---

# 27. Extragererea unui cuvânt

Dacă avem:

```text
"ana maria"
```

și vrem să extragem `ana` într-un alt șir:

```cpp
char cuv[101];

int i = 0;

while(s[i] != ' ' && s[i] != '\0')
{
    cuv[i] = s[i];
    i++;
}

cuv[i] = '\0';
```

### Foarte important

După copiere trebuie pus:

```cpp
cuv[i] = '\0';
```

Altfel, `cuv` nu este un șir C valid.

---

# 28. Numărarea aparițiilor unui subșir

Dacă vrem să numărăm de câte ori apare un subșir:

```cpp
int nr = 0;

for(int i = 0; s[i] != '\0'; i++)
{
    int j = 0;

    while(sub[j] != '\0' && s[i+j] == sub[j])
        j++;

    if(sub[j] == '\0')
        nr++;
}
```

Aici aparițiile se pot suprapune.

Exemplu conceptual:

```text
aaaa
```

și subșirul:

```text
aa
```

are apariții la pozițiile `0`, `1`, `2`.

---

# 29. Verificarea dacă două șiruri sunt anagrame

Două șiruri sunt anagrame dacă au aceleași caractere, cu aceleași frecvențe.

Exemplu:

```text
"listen"
"silent"
```

Metodă cu frecvențe:

```cpp
int f[256] = {0};

for(int i = 0; s1[i] != '\0'; i++)
    f[(unsigned char)s1[i]]++;

for(int i = 0; s2[i] != '\0'; i++)
    f[(unsigned char)s2[i]]--;

bool ok = true;

for(int i = 0; i < 256; i++)
    if(f[i] != 0)
        ok = false;
```

---

# 30. Frecvența caracterelor

Putem număra de câte ori apare fiecare caracter folosind un vector de frecvență.

Pentru litere mici:

```cpp
int f[26] = {0};

for(int i = 0; s[i] != '\0'; i++)
    if(s[i] >= 'a' && s[i] <= 'z')
        f[s[i] - 'a']++;
```

Interpretare:

```text
f[0] → numărul de 'a'
f[1] → numărul de 'b'
...
f[25] → numărul de 'z'
```

---

# 31. Transformarea unei cifre în valoare numerică

Pentru un caracter cifră:

```cpp
char c = '7';
```

valoarea numerică este:

```cpp
int x = c - '0';
```

Rezultă:

```text
x = 7
```

### Transformarea unei valori numerice în caracter

Pentru o cifră `x` între `0` și `9`:

```cpp
char c = x + '0';
```

---

# 32. Număr format din cifrele unui șir

Dacă șirul conține numai cifre:

```cpp
int x = 0;

for(int i = 0; s[i] != '\0'; i++)
    x = x * 10 + (s[i] - '0');
```

Pentru:

```text
"1234"
```

se obține:

```text
1234
```

---

# 33. Verificarea dacă un șir conține numai cifre

```cpp
bool ok = true;

for(int i = 0; s[i] != '\0'; i++)
    if(!isdigit(s[i]))
        ok = false;
```

---

# 34. Eliminarea spațiilor

Pentru eliminarea tuturor spațiilor:

```cpp
int j = 0;

for(int i = 0; s[i] != '\0'; i++)
    if(s[i] != ' ')
    {
        s[j] = s[i];
        j++;
    }

s[j] = '\0';
```

Exemplu:

```text
"ana are mere"
```

devine:

```text
"anaaremere"
```

---

# 35. Eliminarea caracterelor duplicate consecutive

Exemplu:

```text
"aaabbbcc"
```

devine:

```text
"abc"
```

Algoritm:

```cpp
int j = 0;

for(int i = 0; s[i] != '\0'; i++)
{
    if(i == 0 || s[i] != s[i-1])
    {
        s[j] = s[i];
        j++;
    }
}

s[j] = '\0';
```

---

# 36. Separarea cuvintelor prin delimitatori

Uneori cuvintele nu sunt separate doar prin spații, ci prin:

```text
' ', ',', '.', ';', ':', '!', '?'
```

Putem considera un caracter delimitator dacă:

```cpp
s[i] == ' ' || s[i] == ',' || s[i] == '.' 
```

etc.

Pentru delimitatori mai complecși se poate folosi:

```cpp
ispunct(s[i])
```

---

# 37. `strtok` — împărțirea în cuvinte

Funcția:

```cpp
strtok(s, delimitatori)
```

poate împărți un șir în token-uri.

Exemplu:

```cpp
char s[] = "Ana Maria Ion";

char *p = strtok(s, " ");

while(p != nullptr)
{
    cout << p << '\n';
    p = strtok(nullptr, " ");
}
```

Rezultă:

```text
Ana
Maria
Ion
```

### Pentru BAC

De regulă, este mai bine să stăpânești **prelucrarea manuală a cuvintelor**, deoarece este mai transparentă și apare frecvent în rezolvări.

---

# 38. Funcții de conversie numerică

## `atoi`

Transformă un șir care reprezintă un număr întreg într-un `int`:

```cpp
int x = atoi(s);
```

Necesită:

```cpp
#include <cstdlib>
```

Exemplu:

```cpp
char s[] = "123";
int x = atoi(s);
```

---

# 39. Șiruri constante și `const char*`

Un literal precum:

```cpp
"abc"
```

este un șir constant.

Poate fi folosit direct în funcții:

```cpp
strcpy(s, "abc");
strcat(s, "xyz");
strcmp(s, "abc");
```

Nu încerca să modifici literalul:

```cpp
"abc"[0] = 'A'; // greșit
```

---

# 40. Șir de caractere vs. caracter

Este esențial să faci diferența între:

```cpp
'a'
```

și:

```cpp
"a"
```

Primul este **caracter**.

Al doilea este **șir de caractere**.

Corect:

```cpp
if(s[i] == 'a')
```

Nu:

```cpp
if(s[i] == "a")
```

---

# 41. Șir de caractere vs. vector de caractere

În problemele de BAC:

```cpp
char s[101];
```

este un tablou de caractere folosit ca șir.

Un șir valid trebuie să se termine cu:

```cpp
'\0'
```

De aceea:

```cpp
strlen(s)
```

se oprește la primul `'\0'`.

---

# 42. Greșeli frecvente la BAC

## 42.1. Confundarea lui `'a'` cu `"a"`

Greșit:

```cpp
if(s[i] == "a")
```

Corect:

```cpp
if(s[i] == 'a')
```

---

## 42.2. Uitarea lui `'\0'`

La construirea manuală a unui șir:

```cpp
s[j] = '\0';
```

este obligatoriu.

---

## 42.3. Depășirea dimensiunii tabloului

Dacă:

```cpp
char s[101];
```

pot exista cel mult 100 de caractere utile.

---

## 42.4. Folosirea greșită a `strlen`

`strlen(s)` este lungimea șirului, nu poziția ultimului caracter.

Ultima poziție este:

```cpp
strlen(s) - 1
```

---

## 42.5. Compararea șirurilor cu `==`

Pentru șiruri C:

```cpp
strcmp(s1, s2) == 0
```

este forma standard pentru compararea conținutului.

---

## 42.6. Deplasarea în direcția greșită la inserare

La inserare, caracterele trebuie deplasate:

```text
de la dreapta la stânga
```

pentru a nu le suprascrie.

---

## 42.7. Apelarea repetată inutilă a `strlen`

Mai eficient:

```cpp
int n = strlen(s);

for(int i = 0; i < n; i++)
```

decât:

```cpp
for(int i = 0; i < strlen(s); i++)
```

în algoritmi unde lungimea este folosită de multe ori.

---

# 43. Tipare de algoritmi de memorat

## 43.1. Parcurgere

```cpp
for(int i = 0; s[i] != '\0'; i++)
{
    // prelucrare
}
```

---

## 43.2. Numărare

```cpp
int nr = 0;

for(int i = 0; s[i] != '\0'; i++)
    if(conditie)
        nr++;
```

---

## 43.3. Verificare existență

```cpp
bool gasit = false;

for(int i = 0; s[i] != '\0'; i++)
    if(conditie)
    {
        gasit = true;
        break;
    }
```

---

## 43.4. Verificare proprietate pentru toate caracterele

```cpp
bool ok = true;

for(int i = 0; s[i] != '\0'; i++)
    if(!conditie)
    {
        ok = false;
        break;
    }
```

---

## 43.5. Construirea unui șir nou

```cpp
int j = 0;

for(int i = 0; s[i] != '\0'; i++)
    if(conditie)
    {
        t[j] = s[i];
        j++;
    }

t[j] = '\0';
```

---

## 43.6. Ștergerea caracterelor care respectă o condiție

```cpp
int j = 0;

for(int i = 0; s[i] != '\0'; i++)
    if(!conditie)
    {
        s[j] = s[i];
        j++;
    }

s[j] = '\0';
```

---

## 43.7. Înlocuirea caracterelor

```cpp
for(int i = 0; s[i] != '\0'; i++)
    if(conditie)
        s[i] = caracter_nou;
```

---

## 43.8. Prelucrarea cuvintelor

```cpp
int i = 0;

while(s[i] != '\0')
{
    while(s[i] == ' ')
        i++;

    int start = i;

    while(s[i] != ' ' && s[i] != '\0')
        i++;

    int stop = i - 1;

    // prelucrăm [start, stop]
}
```

---

# 44. Complexitatea operațiilor uzuale

Pentru un șir cu `n` caractere:

| Operație | Complexitate aproximativă |
|---|---:|
| Parcurgere | `O(n)` |
| Numărare caractere | `O(n)` |
| Căutare caracter | `O(n)` |
| Verificare palindrom | `O(n)` |
| Inversare | `O(n)` |
| Copiere | `O(n)` |
| Concatenare | `O(n + m)` |
| Comparare | `O(min(n,m))` |
| Căutare naivă subșir | `O(n*m)` |

La nivel de BAC este important mai ales să recunoști algoritmii de **parcurgere liniară**.

---

# 45. Șablon rapid pentru probleme

Când vezi o problemă cu șiruri de caractere:

### Pasul 1 — identifică ce reprezintă șirul

Întreabă-te:

- este un cuvânt?
- este o propoziție?
- conține spații?
- are cifre?
- are delimitatori?

### Pasul 2 — alege citirea

Fără spații:

```cpp
cin >> s;
```

Cu spații:

```cpp
cin.getline(s, 101);
```

### Pasul 3 — identifică unitatea de prelucrare

Poate fi:

- caracter;
- secvență de caractere;
- cuvânt;
- subșir;
- frecvență.

### Pasul 4 — alege tiparul

Pentru caractere:

```cpp
for(int i = 0; s[i] != '\0'; i++)
```

Pentru cuvinte:

```cpp
while(s[i] != '\0')
```

cu delimitarea începutului și sfârșitului cuvântului.

---

# 46. Bibliotecile importante

Pentru șiruri C:

```cpp
#include <cstring>
```

Funcții importante:

```text
strlen
strcpy
strcat
strcmp
strchr
strstr
strtok
```

Pentru clasificarea caracterelor:

```cpp
#include <cctype>
```

Funcții importante:

```text
isdigit
isalpha
islower
isupper
isspace
tolower
toupper
```

Pentru conversii:

```cpp
#include <cstdlib>
```

Funcție utilă:

```text
atoi
```

---

# 47. Fișă de memorare

```cpp
// Lungime
int n = strlen(s);

// Parcurgere
for(int i = 0; s[i] != '\0'; i++)

// Egalitate
strcmp(s1, s2) == 0

// Copiere
strcpy(s1, s2)

// Concatenare
strcat(s1, s2)

// Căutare caracter
strchr(s, 'a')

// Căutare subșir
strstr(s, "abc")

// Literă
isalpha(c)

// Cifră
isdigit(c)

// Literă mică
islower(c)

// Literă mare
isupper(c)

// Caracter alb
isspace(c)

// Micșorare
tolower(c)

// Majusculă
toupper(c)

// Cifră caracter → număr
c - '0'

// Număr → caracter cifră
x + '0'

// Terminator
'\0'
```
