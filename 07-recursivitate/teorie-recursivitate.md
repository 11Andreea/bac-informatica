# Recursivitate 
## 1. Ce este recursivitatea?

**Recursivitatea** este tehnica prin care o funcție se apelează pe ea
însăși pentru a rezolva o problemă.

Ideea de bază este:

1.  rezolvăm direct cazurile simple;
2.  pentru un caz mai mare, reducem problema la una sau mai multe
    probleme mai mici de același tip;
3.  apelurile recursive se opresc atunci când este atinsă o **condiție
    de oprire**.

O funcție recursivă are, în general, două componente esențiale:

-   **cazul de bază** --- situația în care nu mai este necesar un apel
    recursiv;
-   **pasul recursiv** --- apelul funcției pentru o problemă mai mică
    sau pentru o stare mai apropiată de cazul de bază.

### Exemplu conceptual

Pentru calculul factorialului:

\[ n! = n `\cdot `{=tex}(n-1)! \]

iar:

\[ 0! = 1 \]

Funcția poate fi scrisă:

``` cpp
long long factorial(int n)
{
    if (n == 0)
        return 1;

    return n * factorial(n - 1);
}
```

Pentru `factorial(4)` se obține:

``` text
factorial(4)
→ 4 * factorial(3)
→ 4 * 3 * factorial(2)
→ 4 * 3 * 2 * factorial(1)
→ 4 * 3 * 2 * 1 * factorial(0)
→ 4 * 3 * 2 * 1 * 1
→ 24
```

------------------------------------------------------------------------

# 2. Structura generală a unei funcții recursive

Forma cea mai simplă este:

``` cpp
tip functie(parametri)
{
    if (conditie_de_oprire)
        return valoare;

    return ... functie(parametri_modificati) ...;
}
```

Exemplu:

``` cpp
int suma(int n)
{
    if (n == 0)
        return 0;

    return n + suma(n - 1);
}
```

Pentru `suma(4)`:

``` text
suma(4)
= 4 + suma(3)
= 4 + 3 + suma(2)
= 4 + 3 + 2 + suma(1)
= 4 + 3 + 2 + 1 + suma(0)
= 10
```

------------------------------------------------------------------------

# 3. Cele două elemente obligatorii

## 3.1. Cazul de bază

Cazul de bază este condiția care oprește recursivitatea.

Exemplu:

``` cpp
if (n == 0)
    return 1;
```

Fără un caz de bază corect, funcția poate continua să se apeleze la
nesfârșit până la epuizarea memoriei pentru stiva de apeluri.

------------------------------------------------------------------------

## 3.2. Pasul recursiv

Pasul recursiv trebuie să apropie argumentele de cazul de bază.

Exemplu corect:

``` cpp
factorial(n - 1)
```

Dacă baza este `n == 0`, atunci:

``` text
n → n-1 → n-2 → ... → 0
```

Exemplu problematic:

``` cpp
factorial(n + 1)
```

Dacă pornim de la un `n > 0`, ne îndepărtăm de cazul `n == 0`.

------------------------------------------------------------------------

# 4. Recursivitate directă

O funcție are **recursivitate directă** atunci când se apelează pe ea
însăși.

``` cpp
int f(int n)
{
    if (n == 0)
        return 0;

    return f(n - 1) + 1;
}
```

Aici `f` se apelează direct pe `f`.

------------------------------------------------------------------------

# 5. Recursivitate indirectă

Recursivitatea poate apărea și prin mai multe funcții.

De exemplu:

``` cpp
void f(int n)
{
    if (n > 0)
        g(n - 1);
}

void g(int n)
{
    if (n > 0)
        f(n - 1);
}
```

Avem:

``` text
f → g → f → g → ...
```

La Bac este întâlnită mai rar decât recursivitatea directă.

------------------------------------------------------------------------

# 6. Recursivitate liniară

O funcție are recursivitate liniară atunci când fiecare apel generează
**un singur apel recursiv**.

Exemplu:

``` cpp
int suma(int n)
{
    if (n == 0)
        return 0;

    return n + suma(n - 1);
}
```

Schema este:

``` text
f(n)
 |
 f(n-1)
 |
 f(n-2)
 |
 ...
 |
 f(0)
```

Numărul apelurilor este, de regulă, proporțional cu `n`.

------------------------------------------------------------------------

# 7. Recursivitate cu mai multe apeluri

Uneori, un apel al funcției generează două sau mai multe apeluri
recursive.

Exemplu:

``` cpp
int fib(int n)
{
    if (n <= 1)
        return n;

    return fib(n - 1) + fib(n - 2);
}
```

Pentru `fib(4)`:

``` text
                 fib(4)
                /      \
           fib(3)      fib(2)
           /   \       /   \
       fib(2) fib(1) fib(1) fib(0)
       /   \
   fib(1) fib(0)
```

Acest tip de recursivitate poate genera foarte multe apeluri.

------------------------------------------------------------------------

# 8. Recursivitate în coadă (tail recursion)

O funcție este recursivă în coadă atunci când apelul recursiv este
ultima operație importantă efectuată de funcție.

Exemplu:

``` cpp
void afisare(int n)
{
    if (n == 0)
        return;

    cout << n << ' ';
    afisare(n - 1);
}
```

Apelul:

``` cpp
afisare(5);
```

afișează:

``` text
5 4 3 2 1
```

------------------------------------------------------------------------

# 9. Ordinea operațiilor: înainte sau după apelul recursiv

Aceasta este una dintre cele mai importante idei pentru exercițiile de
Bac.

## 9.1. Prelucrare înainte de apel

``` cpp
void f(int n)
{
    if (n == 0)
        return;

    cout << n << ' ';
    f(n - 1);
}
```

Pentru:

``` cpp
f(4);
```

rezultatul este:

``` text
4 3 2 1
```

------------------------------------------------------------------------

## 9.2. Prelucrare după apel

``` cpp
void f(int n)
{
    if (n == 0)
        return;

    f(n - 1);
    cout << n << ' ';
}
```

Pentru:

``` cpp
f(4);
```

rezultatul este:

``` text
1 2 3 4
```

### De ce?

Apelurile sunt mai întâi construite:

``` text
f(4)
f(3)
f(2)
f(1)
f(0)
```

Apoi, după ce `f(0)` se termină, execuția revine:

``` text
f(1) → afișează 1
f(2) → afișează 2
f(3) → afișează 3
f(4) → afișează 4
```

Această revenire se numește **backtracking al apelurilor** / revenire
din recursie, dar nu trebuie confundată cu metoda de căutare numită
backtracking.

------------------------------------------------------------------------

# 10. Stiva de apeluri

La fiecare apel de funcție, informațiile necesare apelului sunt păstrate
în **stiva de execuție**.

Pentru:

``` cpp
int f(int n)
{
    if (n == 0)
        return 0;

    return n + f(n - 1);
}
```

apelul:

``` cpp
f(3);
```

construiește aproximativ:

``` text
f(3)
f(2)
f(1)
f(0)
```

Apoi apelurile se închid în ordine inversă:

``` text
f(0)
f(1)
f(2)
f(3)
```

Această structură explică de ce instrucțiunile de după apelul recursiv
sunt executate în ordine inversă.

------------------------------------------------------------------------

# 11. Cum urmărești o funcție recursivă la Bac

Pentru o funcție recursivă, urmărește mereu:

1.  care este cazul de bază;
2.  cu ce valori este apelată funcția;
3.  cum se modifică parametrii;
4.  ce se execută înainte de apel;
5.  ce se execută după apel;
6.  câte apeluri recursive se generează;
7.  în ce moment se produce `return`.

### Exemplu

``` cpp
void f(int n)
{
    if (n == 0)
        return;

    cout << n << ' ';
    f(n - 1);
    cout << n << ' ';
}
```

Pentru:

``` cpp
f(3);
```

Prima coborâre:

``` text
3
2
1
```

Apoi revenirea:

``` text
1
2
3
```

Rezultatul:

``` text
3 2 1 1 2 3
```

------------------------------------------------------------------------

# 12. Funcții recursive care returnează valori

O funcție recursivă poate returna o valoare.

## Factorial

``` cpp
long long factorial(int n)
{
    if (n == 0)
        return 1;

    return n * factorial(n - 1);
}
```

## Suma numerelor de la 1 la n

``` cpp
int suma(int n)
{
    if (n == 0)
        return 0;

    return n + suma(n - 1);
}
```

## Puterea

``` cpp
long long putere(int x, int n)
{
    if (n == 0)
        return 1;

    return x * putere(x, n - 1);
}
```

------------------------------------------------------------------------

# 13. Recursivitate pentru numere naturale

Recursivitatea este foarte utilă pentru prelucrarea cifrelor unui număr.

Operațiile de bază sunt:

``` cpp
n % 10
```

pentru ultima cifră și:

``` cpp
n / 10
```

pentru eliminarea ultimei cifre.

Exemplu:

``` text
n = 5728

n % 10 → 8
n / 10 → 572
```

Apoi:

``` text
572 % 10 → 2
57 % 10 → 7
5 % 10 → 5
```

------------------------------------------------------------------------

# 14. Numărul de cifre

``` cpp
int nrCifre(int n)
{
    if (n < 10)
        return 1;

    return 1 + nrCifre(n / 10);
}
```

Pentru `5728`:

``` text
nrCifre(5728)
= 1 + nrCifre(572)
= 1 + 1 + nrCifre(57)
= 1 + 1 + 1 + nrCifre(5)
= 4
```

------------------------------------------------------------------------

# 15. Suma cifrelor

``` cpp
int sumaCifre(int n)
{
    if (n < 10)
        return n;

    return n % 10 + sumaCifre(n / 10);
}
```

Exemplu:

``` text
sumaCifre(5728)
= 8 + sumaCifre(572)
= 8 + 2 + sumaCifre(57)
= 8 + 2 + 7 + sumaCifre(5)
= 22
```

------------------------------------------------------------------------

# 16. Numărul de apariții ale unei cifre

Pentru numărul de apariții ale cifrei `c`:

``` cpp
int aparitii(int n, int c)
{
    if (n < 10)
        return n == c;

    return (n % 10 == c) + aparitii(n / 10, c);
}
```

Exemplu:

``` cpp
aparitii(122321, 2)
```

rezultatul este `3`.

------------------------------------------------------------------------

# 17. Verificarea existenței unei cifre

``` cpp
bool existaCifra(int n, int c)
{
    if (n < 10)
        return n == c;

    return n % 10 == c || existaCifra(n / 10, c);
}
```

Exemplu:

``` cpp
existaCifra(5728, 7)
```

returnează `true`.

------------------------------------------------------------------------

# 18. Cea mai mare cifră

``` cpp
int cifraMaxima(int n)
{
    if (n < 10)
        return n;

    return max(n % 10, cifraMaxima(n / 10));
}
```

Exemplu:

``` text
cifraMaxima(5728)
= max(8, cifraMaxima(572))
= max(8, 7)
= 8
```

------------------------------------------------------------------------

# 19. Cea mai mică cifră

``` cpp
int cifraMinima(int n)
{
    if (n < 10)
        return n;

    return min(n % 10, cifraMinima(n / 10));
}
```

------------------------------------------------------------------------

# 20. Afișarea cifrelor în ordine normală

Dacă vrem să afișăm cifrele de la prima la ultima, putem folosi apelul
recursiv înaintea afișării.

``` cpp
void cifre(int n)
{
    if (n < 10)
    {
        cout << n << ' ';
        return;
    }

    cifre(n / 10);
    cout << n % 10 << ' ';
}
```

Pentru:

``` cpp
cifre(5728);
```

rezultatul:

``` text
5 7 2 8
```

------------------------------------------------------------------------

# 21. Afișarea cifrelor în ordine inversă

``` cpp
void cifreInverse(int n)
{
    cout << n % 10 << ' ';

    if (n >= 10)
        cifreInverse(n / 10);
}
```

Pentru `5728`:

``` text
8 2 7 5
```

O variantă echivalentă:

``` cpp
void cifreInverse(int n)
{
    if (n == 0)
        return;

    cout << n % 10 << ' ';
    cifreInverse(n / 10);
}
```

Atenție: pentru `n = 0`, tratarea specială poate fi necesară dacă
problema consideră numărul `0` ca având o cifră.

------------------------------------------------------------------------

# 22. Inversul unui număr

O variantă elegantă folosește un parametru suplimentar:

``` cpp
int invers(int n, int r = 0)
{
    if (n == 0)
        return r;

    return invers(n / 10, r * 10 + n % 10);
}
```

Exemplu:

``` cpp
invers(5728)
```

→ `8275`.

Parametrul `r` reține rezultatul construit până în acel moment.

------------------------------------------------------------------------

# 23. Palindrom

Un număr este palindrom dacă este egal cu inversul său.

Putem folosi funcția de inversare:

``` cpp
bool palindrom(int n)
{
    int x = n;

    // Se poate apela invers(x) dacă funcția a fost definită.
    return n == invers(x);
}
```

La exercițiile de Bac, se poate cere și construirea unei funcții
recursive care verifică direct proprietatea, dar metoda exactă depinde
de cerință.

------------------------------------------------------------------------

# 24. Divizibilitate și CMMDC

## CMMDC prin recursivitate

Algoritmul lui Euclid este în mod natural recursiv:

``` cpp
int cmmdc(int a, int b)
{
    if (b == 0)
        return a;

    return cmmdc(b, a % b);
}
```

Exemplu:

``` text
cmmdc(48, 18)
→ cmmdc(18, 12)
→ cmmdc(12, 6)
→ cmmdc(6, 0)
→ 6
```

------------------------------------------------------------------------

# 25. CMMMC

Folosind CMMDC:

``` cpp
int cmmmc(int a, int b)
{
    return a / cmmdc(a, b) * b;
}
```

Este recomandabil să împărțim înainte de înmulțire pentru a reduce
riscul de depășire a tipului de date.

------------------------------------------------------------------------

# 26. Șiruri și recursivitate

Recursivitatea poate fi folosită și pentru prelucrarea caracterelor unui
șir.

Exemplu: afișarea caracterelor unui șir.

``` cpp
void afisare(const string& s, int p)
{
    if (p == s.size())
        return;

    cout << s[p] << ' ';
    afisare(s, p + 1);
}
```

------------------------------------------------------------------------

# 27. Numărarea unui caracter într-un șir

``` cpp
int aparitii(const string& s, int p, char c)
{
    if (p == s.size())
        return 0;

    return (s[p] == c) + aparitii(s, p + 1, c);
}
```

Exemplu:

``` cpp
aparitii("banana", 0, 'a')
```

→ `3`.

------------------------------------------------------------------------

# 28. Verificarea unui șir dacă este palindrom

Putem compara caracterele de la extremități.

``` cpp
bool palindrom(const string& s, int st, int dr)
{
    if (st >= dr)
        return true;

    if (s[st] != s[dr])
        return false;

    return palindrom(s, st + 1, dr - 1);
}
```

Apel:

``` cpp
palindrom(s, 0, s.size() - 1);
```

Ideea:

``` text
s[st] == s[dr]
s[st+1] == s[dr-1]
...
```

------------------------------------------------------------------------

# 29. Recursivitate pe tablouri

Un tablou poate fi parcurs recursiv folosind poziția curentă.

``` cpp
void afisare(int a[], int n, int p)
{
    if (p == n)
        return;

    cout << a[p] << ' ';
    afisare(a, n, p + 1);
}
```

Apel:

``` cpp
afisare(a, n, 0);
```

------------------------------------------------------------------------

# 30. Suma elementelor unui tablou

``` cpp
int suma(int a[], int n, int p)
{
    if (p == n)
        return 0;

    return a[p] + suma(a, n, p + 1);
}
```

------------------------------------------------------------------------

# 31. Maximul dintr-un tablou

``` cpp
int maxim(int a[], int n, int p)
{
    if (p == n - 1)
        return a[p];

    return max(a[p], maxim(a, n, p + 1));
}
```

Apel:

``` cpp
maxim(a, n, 0);
```

------------------------------------------------------------------------

# 32. Numărul de elemente pare

``` cpp
int nrPare(int a[], int n, int p)
{
    if (p == n)
        return 0;

    return (a[p] % 2 == 0) + nrPare(a, n, p + 1);
}
```

------------------------------------------------------------------------

# 33. Verificarea dacă toate elementele respectă o condiție

Exemplu: toate elementele sunt pozitive.

``` cpp
bool toatePozitive(int a[], int n, int p)
{
    if (p == n)
        return true;

    return a[p] > 0 && toatePozitive(a, n, p + 1);
}
```

------------------------------------------------------------------------

# 34. Căutarea unui element într-un tablou

``` cpp
bool exista(int a[], int n, int p, int x)
{
    if (p == n)
        return false;

    return a[p] == x || exista(a, n, p + 1, x);
}
```

------------------------------------------------------------------------

# 35. Recursivitate și descompunerea unei probleme

O metodă bună de a construi o funcție recursivă este să întrebi:

> „Dacă știu să rezolv problema pentru partea mai mică, cum folosesc
> acel rezultat pentru problema actuală?"

Exemplu:

``` cpp
suma(n) = n + suma(n - 1)
```

Problema pentru `n` se reduce la problema pentru `n - 1`.

------------------------------------------------------------------------

# 36. Cum găsești cazul de bază

Cazul de bază trebuie să fie cea mai simplă versiune a problemei.

### Factorial

Problema:

``` text
factorial(n)
```

Caz simplu:

``` text
factorial(0) = 1
```

### Suma numerelor

``` text
suma(0) = 0
```

### Cifrele unui număr

Când:

``` text
n < 10
```

avem o singură cifră.

### Tablou

Când:

``` text
p == n
```

nu mai avem elemente de prelucrat.

------------------------------------------------------------------------

# 37. Parametrul care se modifică

Într-o funcție recursivă trebuie să existe, în mod normal, o evoluție
clară spre cazul de bază.

Exemple:

``` cpp
n - 1
```

``` cpp
n / 10
```

``` cpp
p + 1
```

``` cpp
st + 1, dr - 1
```

### Exemple

Pentru cifre:

``` cpp
n / 10
```

Pentru tablou:

``` cpp
p + 1
```

Pentru interval:

``` cpp
st + 1
dr - 1
```

------------------------------------------------------------------------

# 38. Recursivitate cu doi parametri

Unele probleme necesită mai mult de un parametru.

Exemplu:

``` cpp
int putere(int x, int n)
{
    if (n == 0)
        return 1;

    return x * putere(x, n - 1);
}
```

Aici:

-   `x` rămâne constant;
-   `n` se apropie de `0`.

------------------------------------------------------------------------

# 39. Parametru acumulator

Un parametru poate păstra rezultatul construit în timpul recursiei.

Exemplu:

``` cpp
int suma(int n, int s = 0)
{
    if (n == 0)
        return s;

    return suma(n - 1, s + n);
}
```

Pentru `suma(4)`:

``` text
suma(4, 0)
→ suma(3, 4)
→ suma(2, 7)
→ suma(1, 9)
→ suma(0, 10)
→ 10
```

------------------------------------------------------------------------

# 40. Recursivitate și afișare

Trebuie să fii foarte atentă la poziția instrucțiunii `cout`.

## Înainte

``` cpp
cout << n;
f(n - 1);
```

Produce o ordine descrescătoare dacă `n` scade.

## După

``` cpp
f(n - 1);
cout << n;
```

Produce o ordine crescătoare.

## Și înainte, și după

``` cpp
cout << n;
f(n - 1);
cout << n;
```

Produce:

``` text
n n-1 ... 1 1 ... n-1 n
```

Acest tipar apare foarte des în exercițiile de urmărire.

------------------------------------------------------------------------

# 41. Exemplu complet de urmărire

Considerăm:

``` cpp
void f(int n)
{
    if (n == 0)
        return;

    cout << n << ' ';
    f(n - 1);
    cout << n << ' ';
}
```

Apel:

``` cpp
f(3);
```

### Coborârea

``` text
f(3) → afișează 3
f(2) → afișează 2
f(1) → afișează 1
f(0) → se oprește
```

### Revenirea

``` text
f(1) → afișează 1
f(2) → afișează 2
f(3) → afișează 3
```

Rezultat:

``` text
3 2 1 1 2 3
```

------------------------------------------------------------------------

# 42. Recursivitate pentru puteri

Varianta simplă:

``` cpp
long long putere(int x, int n)
{
    if (n == 0)
        return 1;

    return x * putere(x, n - 1);
}
```

Există și o variantă mai eficientă, prin **exponentiere rapidă**:

``` cpp
long long putere(int x, int n)
{
    if (n == 0)
        return 1;

    if (n % 2 == 0)
    {
        long long p = putere(x, n / 2);
        return p * p;
    }

    return x * putere(x, n - 1);
}
```

Ideea este că pentru exponent par:

\[ x\^n = (x^{n/2})^2 \]

------------------------------------------------------------------------

# 43. Fibonacci

Definiția recursivă clasică:

``` cpp
int fib(int n)
{
    if (n <= 1)
        return n;

    return fib(n - 1) + fib(n - 2);
}
```

Șirul este:

``` text
0 1 1 2 3 5 8 13 ...
```

### Atenție

Această implementare generează multe apeluri repetate și este
ineficientă pentru valori mari ale lui `n`.

La Bac, interesul este de obicei înțelegerea recursivității și urmărirea
apelurilor, nu calculul unor valori foarte mari cu această implementare.

------------------------------------------------------------------------

# 44. Recursivitate vs. iterativitate

Multe probleme care pot fi rezolvate recursiv pot fi rezolvate și cu
bucle.

### Iterativ

``` cpp
int suma(int n)
{
    int s = 0;

    for (int i = 1; i <= n; i++)
        s += i;

    return s;
}
```

### Recursiv

``` cpp
int suma(int n)
{
    if (n == 0)
        return 0;

    return n + suma(n - 1);
}
```

Ambele pot produce același rezultat.

Recursivitatea este însă utilă în special atunci când structura
problemei este în mod natural recursivă.

------------------------------------------------------------------------

# 45. Avantaje și dezavantaje

## Avantaje

-   poate face codul mai simplu;
-   exprimă natural problemele definite recursiv;
-   este foarte utilă pentru arbori, divide et impera și backtracking;
-   poate reduce codul necesar pentru unele probleme.

## Dezavantaje

-   folosește memoria stivei;
-   prea multe apeluri pot produce depășirea stivei;
-   unele variante recursive sunt mult mai lente decât variantele
    iterative;
-   urmărirea poate fi mai dificilă.

------------------------------------------------------------------------

# 46. Complexitatea recursiei

Pentru o recursivitate liniară de forma:

``` cpp
f(n)
{
    ...
    f(n - 1);
}
```

numărul de apeluri este aproximativ proporțional cu `n`.

Complexitatea este, în general:

``` text
O(n)
```

Pentru o recursivitate de forma:

``` cpp
f(n)
{
    f(n - 1);
    f(n - 2);
}
```

numărul de apeluri poate crește exponențial.

Exemplul Fibonacci naiv are o complexitate aproximativă exponențială.

------------------------------------------------------------------------

# 47. Recursivitate și divide et impera

**Divide et impera** este o tehnică în care problema este împărțită în
probleme mai mici, acestea sunt rezolvate, apoi rezultatele sunt
combinate.

Multe implementări de divide et impera sunt recursive.

Schema generală:

``` cpp
rezolva(problema)
{
    if (problema este suficient de mică)
        rezolvă direct;

    împarte problema;
    rezolvă recursiv subproblemele;
    combină rezultatele;
}
```

Exemple clasice:

-   căutare binară;
-   Merge Sort;
-   Quick Sort.

Pentru Bac este important să recunoști ideea de bază și structura
recursivă.

------------------------------------------------------------------------

# 48. Căutarea binară recursivă

Pentru un vector sortat:

``` cpp
int cautareBinara(int a[], int st, int dr, int x)
{
    if (st > dr)
        return -1;

    int m = (st + dr) / 2;

    if (a[m] == x)
        return m;

    if (x < a[m])
        return cautareBinara(a, st, m - 1, x);

    return cautareBinara(a, m + 1, dr, x);
}
```

Ideea:

-   verificăm elementul din mijloc;
-   dacă `x` este mai mic, căutăm în jumătatea stângă;
-   dacă `x` este mai mare, căutăm în jumătatea dreaptă.

Complexitatea este:

``` text
O(log n)
```

------------------------------------------------------------------------

# 49. Backtracking și recursivitate

**Backtracking-ul** folosește în mod obișnuit recursivitatea pentru a
construi soluții pas cu pas.

Schema generală:

``` cpp
void back(int k)
{
    if (soluția este completă)
    {
        afișează soluția;
        return;
    }

    for (fiecare alegere posibilă)
    {
        dacă alegerea este validă
        {
            alegerea este făcută;
            back(k + 1);
            alegerea este anulată;
        }
    }
}
```

Recursivitatea este mecanismul prin care se trece la următorul nivel al
construirii soluției.

------------------------------------------------------------------------

# 50. Recursivitate cu generare de variante

Un exemplu simplificat:

``` cpp
void gen(int k)
{
    if (k > n)
    {
        // am construit o soluție
        return;
    }

    for (int x = 1; x <= n; x++)
    {
        // alegem x
        gen(k + 1);
        // anulăm alegerea
    }
}
```

Numărul de apeluri poate deveni foarte mare, deoarece fiecare nivel
poate genera mai multe ramuri.

------------------------------------------------------------------------

# 51. Recursivitate mutuală

Două funcții se pot apela reciproc.

``` cpp
bool par(int n);

bool impar(int n)
{
    if (n == 0)
        return false;

    return par(n - 1);
}

bool par(int n)
{
    if (n == 0)
        return true;

    return impar(n - 1);
}
```

Pentru:

``` cpp
par(4)
```

se ajunge la:

``` text
par(4)
→ impar(3)
→ par(2)
→ impar(1)
→ par(0)
→ true
```

Este un exemplu de recursivitate indirectă.

------------------------------------------------------------------------

# 52. Greșeli frecvente la Bac

## 52.1. Lipsa cazului de bază

Greșit:

``` cpp
int f(int n)
{
    return n + f(n - 1);
}
```

Nu există o condiție de oprire.

------------------------------------------------------------------------

## 52.2. Cazul de bază nu este atins

Greșit:

``` cpp
int f(int n)
{
    if (n == 0)
        return 0;

    return f(n + 1);
}
```

Pentru un `n > 0`, `n` nu ajunge la `0`.

------------------------------------------------------------------------

## 52.3. Confuzia dintre `/` și `%`

Pentru cifre:

``` cpp
n % 10
```

= ultima cifră.

``` cpp
n / 10
```

= elimină ultima cifră.

------------------------------------------------------------------------

## 52.4. Confuzia dintre prelucrarea înainte și după apel

``` cpp
cout << n;
f(n - 1);
```

nu are același rezultat ca:

``` cpp
f(n - 1);
cout << n;
```

------------------------------------------------------------------------

## 52.5. Uitarea valorii returnate

Greșit:

``` cpp
int suma(int n)
{
    if (n == 0)
        return 0;

    suma(n - 1);
}
```

Dacă funcția trebuie să returneze suma, rezultatul apelului recursiv
trebuie folosit:

``` cpp
return n + suma(n - 1);
```

------------------------------------------------------------------------

# 53. Cum rezolvi rapid un exercițiu de urmărire

Când vezi o funcție recursivă, poți folosi următorul algoritm:

### Pasul 1

Scrie apelul inițial.

### Pasul 2

Urmărește primul apel recursiv.

### Pasul 3

Continuă până la cazul de bază.

### Pasul 4

Marchează separat instrucțiunile executate înainte de apel.

### Pasul 5

La revenire, execută instrucțiunile de după apel.

### Pasul 6

Pentru mai multe apeluri recursive, desenează arborele apelurilor.

------------------------------------------------------------------------

# 54. Exemplu de analiză

``` cpp
int f(int n)
{
    if (n == 1)
        return 1;

    return n + f(n - 1);
}
```

Pentru:

``` cpp
f(4)
```

scriem:

``` text
f(4)
= 4 + f(3)
= 4 + 3 + f(2)
= 4 + 3 + 2 + f(1)
= 4 + 3 + 2 + 1
= 10
```

------------------------------------------------------------------------

# 55. Exemplu cu două apeluri

``` cpp
int f(int n)
{
    if (n <= 1)
        return 1;

    return f(n - 1) + f(n - 2);
}
```

Pentru `f(4)`:

``` text
f(4)
├── f(3)
│   ├── f(2)
│   │   ├── f(1)
│   │   └── f(0)
│   └── f(1)
└── f(2)
    ├── f(1)
    └── f(0)
```

La exercițiile de acest tip, un desen al arborelui este adesea cea mai
sigură metodă.

------------------------------------------------------------------------

# 56. Tipare de memorat pentru Bac

## Suma 1...n

``` cpp
int suma(int n)
{
    if (n == 0)
        return 0;

    return n + suma(n - 1);
}
```

## Factorial

``` cpp
long long factorial(int n)
{
    if (n == 0)
        return 1;

    return n * factorial(n - 1);
}
```

## Putere

``` cpp
long long putere(int x, int n)
{
    if (n == 0)
        return 1;

    return x * putere(x, n - 1);
}
```

## CMMDC

``` cpp
int cmmdc(int a, int b)
{
    if (b == 0)
        return a;

    return cmmdc(b, a % b);
}
```

## Număr de cifre

``` cpp
int nrCifre(int n)
{
    if (n < 10)
        return 1;

    return 1 + nrCifre(n / 10);
}
```

## Suma cifrelor

``` cpp
int sumaCifre(int n)
{
    if (n < 10)
        return n;

    return n % 10 + sumaCifre(n / 10);
}
```

## Maximul cifrelor

``` cpp
int cifraMaxima(int n)
{
    if (n < 10)
        return n;

    return max(n % 10, cifraMaxima(n / 10));
}
```

## Afișare crescătoare a cifrelor

``` cpp
void cifre(int n)
{
    if (n < 10)
    {
        cout << n << ' ';
        return;
    }

    cifre(n / 10);
    cout << n % 10 << ' ';
}
```

## Afișare descrescătoare a cifrelor

``` cpp
void cifre(int n)
{
    cout << n % 10 << ' ';

    if (n >= 10)
        cifre(n / 10);
}
```

## Parcurgere tablou

``` cpp
void parcurgere(int a[], int n, int p)
{
    if (p == n)
        return;

    // prelucrarea lui a[p]
    parcurgere(a, n, p + 1);
}
```

------------------------------------------------------------------------

# 57. Recursivitate pe interval

Uneori problema este formulată pentru un interval `[st, dr]`.

Schema:

``` cpp
void f(int st, int dr)
{
    if (st > dr)
        return;

    // prelucrare

    f(st + 1, dr);
}
```

Pentru reducerea intervalului din ambele capete:

``` cpp
void f(int st, int dr)
{
    if (st >= dr)
        return;

    // prelucrare

    f(st + 1, dr - 1);
}
```

Această idee apare frecvent la verificarea palindromurilor.

------------------------------------------------------------------------

# 58. Recursivitate pentru secvențe

O secvență poate fi prelucrată element cu element.

``` cpp
int suma(int a[], int p, int n)
{
    if (p == n)
        return 0;

    return a[p] + suma(a, p + 1, n);
}
```

Este important să identifici:

-   poziția curentă;
-   poziția de oprire;
-   modul în care poziția avansează.

------------------------------------------------------------------------

# 59. Recursivitate și valori globale

O funcție recursivă poate modifica și variabile globale, de exemplu
pentru numărare:

``` cpp
int cnt = 0;

void f(int n)
{
    if (n == 0)
        return;

    if (n % 2 == 0)
        cnt++;

    f(n - 1);
}
```

Deși funcționează, pentru funcții reutilizabile este adesea mai clar să
returnăm rezultatul sau să folosim parametri.

------------------------------------------------------------------------

# 60. Funcție `void` vs. funcție cu `return`

## `void`

Este potrivită când vrem să efectuăm o acțiune, de exemplu să afișăm:

``` cpp
void f(int n)
{
    if (n == 0)
        return;

    cout << n << ' ';
    f(n - 1);
}
```

## Funcție care returnează

Este potrivită când vrem să calculăm o valoare:

``` cpp
int f(int n)
{
    if (n == 0)
        return 0;

    return n + f(n - 1);
}
```

------------------------------------------------------------------------

# 61. Recursivitatea și memoria

Fiecare apel recursiv ocupă spațiu în stiva programului.

Pentru:

``` cpp
f(n)
→ f(n-1)
→ f(n-2)
→ ...
```

există simultan mai multe apeluri active.

Dacă adâncimea recursiei este foarte mare, poate apărea:

``` text
stack overflow
```

La Bac, este suficient să reții că recursivitatea consumă memorie pentru
apelurile active.

------------------------------------------------------------------------

# 62. Cum verifici dacă o recursie se termină

Întreabă:

> Există o mărime care se apropie mereu de cazul de bază?

Exemple:

``` cpp
n → n - 1
```

și baza:

``` cpp
n == 0
```

este corect.

``` cpp
n → n / 10
```

și baza:

``` cpp
n < 10
```

este corect.

``` cpp
p → p + 1
```

și baza:

``` cpp
p == n
```

este corect.

------------------------------------------------------------------------

# 63. Recursivitate cu condiții

Pasul recursiv poate depinde de o condiție.

Exemplu:

``` cpp
int f(int n)
{
    if (n < 10)
        return n;

    if (n % 2 == 0)
        return f(n / 10);

    return n % 10 + f(n / 10);
}
```

Pentru astfel de exerciții, trebuie urmărită ramura aleasă la fiecare
apel.

------------------------------------------------------------------------

# 64. Recursivitate și `return` condiționat

Exemplu:

``` cpp
int f(int n)
{
    if (n == 0)
        return 0;

    if (n % 2 == 0)
        return f(n / 2);

    return n + f(n - 1);
}
```

La fiecare nivel trebuie verificată condiția înainte de a continua.

------------------------------------------------------------------------

# 65. Recursivitate și operatorii logici

Poți întâlni expresii precum:

``` cpp
return conditie || f(...);
```

sau:

``` cpp
return conditie && f(...);
```

Acestea sunt utile pentru că:

-   `||` caută existența unei situații adevărate;
-   `&&` verifică dacă toate situațiile sunt adevărate.

Exemplu:

``` cpp
bool exista(int a[], int n, int p, int x)
{
    if (p == n)
        return false;

    return a[p] == x || exista(a, n, p + 1, x);
}
```

------------------------------------------------------------------------

# 66. Recursivitate și conversia în baze

Conversia unui număr în baza `b` poate fi făcută recursiv.

Pentru afișarea cifrelor în ordinea corectă:

``` cpp
void conversie(int n, int b)
{
    if (n < b)
    {
        cout << n;
        return;
    }

    conversie(n / b, b);
    cout << n % b;
}
```

Exemplu:

``` cpp
conversie(13, 2);
```

afișează:

``` text
1101
```