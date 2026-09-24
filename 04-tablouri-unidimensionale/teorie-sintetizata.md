\# Tablouri unidimensionale



Un \*\*tablou unidimensional\*\* este o structură de date formată dintr-un număr finit de elemente de același tip, memorate în ordine și accesibile prin intermediul unui indice.



În problemele de Bacalaureat, tablourile sunt folosite pentru memorarea și prelucrarea unor șiruri de valori.



\---



\## 1. Declararea unui tablou



În C/C++, un tablou se declară astfel:



```cpp

tip nume\[dimensiune];

````



Exemplu:



```cpp

int a\[100];

```



Declararea de mai sus rezervă spațiu pentru 100 de numere întregi.



În problemele de BAC, este recomandat ca dimensiunea maximă să fie declarată printr-o constantă:



```cpp

const int NMAX = 1000;

int a\[NMAX];

```



\---



\## 2. Indicii tabloului



În C/C++, indicii unui tablou încep de la `0`.



Pentru:



```cpp

int a\[5];

```



elementele sunt:



```text

indice:   0   1   2   3   4

&#x20;         ↓   ↓   ↓   ↓   ↓

element: a\[0] a\[1] a\[2] a\[3] a\[4]

```



Prin urmare, dacă tabloul are `n` elemente, ultimul element este:



```cpp

a\[n - 1]

```



\### Exemplu



```cpp

a\[0] = 10;

a\[1] = 20;

a\[2] = 30;

```



\---



\# 3. Citirea unui tablou



De obicei se citește mai întâi numărul de elemente `n`, apoi cele `n` elemente.



```cpp

int n, a\[100];



cin >> n;



for (int i = 0; i < n; i++)

&#x20;   cin >> a\[i];

```



Este important ca bucla să parcurgă exact elementele existente:



```cpp

i = 0, 1, ..., n - 1

```



\---



\# 4. Afișarea unui tablou



Pentru afișarea tuturor elementelor:



```cpp

for (int i = 0; i < n; i++)

&#x20;   cout << a\[i] << " ";

```



Dacă se dorește afișarea pe linii separate:



```cpp

for (int i = 0; i < n; i++)

&#x20;   cout << a\[i] << '\\n';

```



\---



\# 5. Parcurgerea unui tablou



Cea mai importantă operație asupra unui tablou este \*\*parcurgerea\*\*.



Forma generală:



```cpp

for (int i = 0; i < n; i++)

{

&#x20;   // prelucrarea lui a\[i]

}

```



În funcție de problemă, putem parcurge tabloul:



\* de la stânga la dreapta;

\* de la dreapta la stânga;

\* doar anumite poziții;

\* doar elementele care îndeplinesc o condiție.



\---



\## 5.1. Parcurgere de la stânga la dreapta



```cpp

for (int i = 0; i < n; i++)

&#x20;   cout << a\[i] << " ";

```



\---



\## 5.2. Parcurgere de la dreapta la stânga



```cpp

for (int i = n - 1; i >= 0; i--)

&#x20;   cout << a\[i] << " ";

```



\---



\## 5.3. Parcurgerea pozițiilor pare



Dacă pozițiile sunt considerate începând de la `0`:



```cpp

for (int i = 0; i < n; i += 2)

&#x20;   cout << a\[i] << " ";

```



\---



\## 5.4. Parcurgerea pozițiilor impare



```cpp

for (int i = 1; i < n; i += 2)

&#x20;   cout << a\[i] << " ";

```



\---



\# 6. Citirea și prelucrarea simultană



Nu este întotdeauna necesar să memorăm toate elementele.



De exemplu, pentru calcularea sumei:



```cpp

int n, x, s = 0;



cin >> n;



for (int i = 0; i < n; i++)

{

&#x20;   cin >> x;

&#x20;   s += x;

}

```



În acest caz nu avem nevoie de un tablou.



\### Principiu important



Dacă problema cere doar o informație care poate fi calculată pe măsură ce citim valorile, \*\*nu este obligatoriu să memorăm tabloul\*\*.



\---



\# 7. Accesarea unui element



Un element este accesat folosind indicele său:



```cpp

a\[i]

```



Exemple:



```cpp

cout << a\[0];       // primul element

cout << a\[n - 1];   // ultimul element

```



Putem modifica un element:



```cpp

a\[3] = 100;

```



\---



\# 8. Calcularea sumei elementelor



```cpp

int s = 0;



for (int i = 0; i < n; i++)

&#x20;   s += a\[i];

```



La final:



```cpp

s

```



conține suma tuturor elementelor.



\---



\# 9. Calcularea produsului elementelor



```cpp

long long p = 1;



for (int i = 0; i < n; i++)

&#x20;   p \*= a\[i];

```



Este recomandat să folosim `long long` dacă produsul poate deveni mare.



\---



\# 10. Numărarea elementelor care respectă o condiție



Model general:



```cpp

int cnt = 0;



for (int i = 0; i < n; i++)

{

&#x20;   if (conditie)

&#x20;       cnt++;

}

```



\### Exemplu



Numărul elementelor pare:



```cpp

int cnt = 0;



for (int i = 0; i < n; i++)

{

&#x20;   if (a\[i] % 2 == 0)

&#x20;       cnt++;

}

```



\---



\# 11. Suma elementelor care respectă o condiție



```cpp

int s = 0;



for (int i = 0; i < n; i++)

{

&#x20;   if (conditie)

&#x20;       s += a\[i];

}

```



\### Exemplu



Suma elementelor pozitive:



```cpp

int s = 0;



for (int i = 0; i < n; i++)

{

&#x20;   if (a\[i] > 0)

&#x20;       s += a\[i];

}

```



\---



\# 12. Numărarea elementelor pare și impare



```cpp

int pare = 0, impare = 0;



for (int i = 0; i < n; i++)

{

&#x20;   if (a\[i] % 2 == 0)

&#x20;       pare++;

&#x20;   else

&#x20;       impare++;

}

```



\---



\# 13. Numărarea elementelor pozitive, negative și nule



```cpp

int poz = 0, neg = 0, zero = 0;



for (int i = 0; i < n; i++)

{

&#x20;   if (a\[i] > 0)

&#x20;       poz++;

&#x20;   else if (a\[i] < 0)

&#x20;       neg++;

&#x20;   else

&#x20;       zero++;

}

```



\---



\# 14. Determinarea maximului



Se pornește de la primul element:



```cpp

int maxim = a\[0];



for (int i = 1; i < n; i++)

{

&#x20;   if (a\[i] > maxim)

&#x20;       maxim = a\[i];

}

```



La final:



```cpp

maxim

```



este valoarea maximă din tablou.



\---



\# 15. Determinarea minimului



```cpp

int minim = a\[0];



for (int i = 1; i < n; i++)

{

&#x20;   if (a\[i] < minim)

&#x20;       minim = a\[i];

}

```



\---



\## De ce nu este recomandat să pornim cu `maxim = 0`?



Greșit:



```cpp

int maxim = 0;

```



Dacă toate valorile sunt negative, rezultatul va fi incorect.



Corect:



```cpp

int maxim = a\[0];

```



Aceeași idee este valabilă pentru minim.



\---



\# 16. Poziția maximului



Dacă trebuie determinată și poziția maximului:



```cpp

int poz = 0;



for (int i = 1; i < n; i++)

{

&#x20;   if (a\[i] > a\[poz])

&#x20;       poz = i;

}

```



Valoarea maximă:



```cpp

a\[poz]

```



Poziția:



```cpp

poz

```



\---



\# 17. Poziția minimului



```cpp

int poz = 0;



for (int i = 1; i < n; i++)

{

&#x20;   if (a\[i] < a\[poz])

&#x20;       poz = i;

}

```



\---



\# 18. Primul element care respectă o condiție



Exemplu: primul element par.



```cpp

int poz = -1;



for (int i = 0; i < n; i++)

{

&#x20;   if (a\[i] % 2 == 0)

&#x20;   {

&#x20;       poz = i;

&#x20;       break;

&#x20;   }

}

```



Dacă `poz == -1`, nu există niciun element par.



\---



\# 19. Ultimul element care respectă o condiție



```cpp

int poz = -1;



for (int i = 0; i < n; i++)

{

&#x20;   if (conditie)

&#x20;       poz = i;

}

```



Nu folosim `break`, deoarece vrem să continuăm până la sfârșit.



\---



\# 20. Verificarea existenței unui element



Exemplu: verificăm dacă există cel puțin un element egal cu `x`.



```cpp

bool exista = false;



for (int i = 0; i < n; i++)

{

&#x20;   if (a\[i] == x)

&#x20;   {

&#x20;       exista = true;

&#x20;       break;

&#x20;   }

}

```



Alternativ:



```cpp

int poz = -1;



for (int i = 0; i < n; i++)

{

&#x20;   if (a\[i] == x)

&#x20;   {

&#x20;       poz = i;

&#x20;       break;

&#x20;   }

}

```



\---



\# 21. Verificarea unei proprietăți pentru toate elementele



Exemplu: verificăm dacă toate elementele sunt pozitive.



```cpp

bool toate = true;



for (int i = 0; i < n; i++)

{

&#x20;   if (a\[i] <= 0)

&#x20;   {

&#x20;       toate = false;

&#x20;       break;

&#x20;   }

}

```



Ideea generală:



```text

presupunem că proprietatea este adevărată

&#x20;       ↓

căutăm o excepție

&#x20;       ↓

dacă găsim o excepție → proprietatea este falsă

```



\---



\# 22. Verificarea dacă tabloul este ordonat



\## Crescător



Pentru ordine crescătoare:



```cpp

bool crescator = true;



for (int i = 0; i < n - 1; i++)

{

&#x20;   if (a\[i] > a\[i + 1])

&#x20;   {

&#x20;       crescator = false;

&#x20;       break;

&#x20;   }

}

```



Este permisă egalitatea:



```text

1 2 2 5 8

```



este crescător.



\---



\## Strict crescător



```cpp

bool strict = true;



for (int i = 0; i < n - 1; i++)

{

&#x20;   if (a\[i] >= a\[i + 1])

&#x20;   {

&#x20;       strict = false;

&#x20;       break;

&#x20;   }

}

```



Exemplu:



```text

1 2 4 7

```



este strict crescător.



\---



\## Descrescător



```cpp

bool descrescator = true;



for (int i = 0; i < n - 1; i++)

{

&#x20;   if (a\[i] < a\[i + 1])

&#x20;   {

&#x20;       descrescator = false;

&#x20;       break;

&#x20;   }

}

```



\---



\## Strict descrescător



```cpp

bool strict = true;



for (int i = 0; i < n - 1; i++)

{

&#x20;   if (a\[i] <= a\[i + 1])

&#x20;   {

&#x20;       strict = false;

&#x20;       break;

&#x20;   }

}

```



\---



\# 23. Calcularea mediei aritmetice



```cpp

int s = 0;



for (int i = 0; i < n; i++)

&#x20;   s += a\[i];



double media = (double)s / n;

```



Conversia la `double` este importantă pentru a evita împărțirea întreagă.



\---



\# 24. Numărarea aparițiilor unei valori



```cpp

int cnt = 0;



for (int i = 0; i < n; i++)

{

&#x20;   if (a\[i] == x)

&#x20;       cnt++;

}

```



\---



\# 25. Frecvența valorilor



Dacă valorile se află într-un interval mic, putem folosi un tablou de frecvență.



Exemplu: valorile sunt între `0` și `100`.



```cpp

int f\[101] = {0};



for (int i = 0; i < n; i++)

{

&#x20;   f\[a\[i]]++;

}

```



După parcurgere:



```cpp

f\[x]

```



reprezintă numărul de apariții ale valorii `x`.



\---



\## Exemplu



Pentru:



```text

2 5 2 3 5 2

```



obținem:



```text

f\[2] = 3

f\[3] = 1

f\[5] = 2

```



\---



\# 26. Afișarea valorilor distincte



O metodă simplă este să verificăm dacă valoarea a mai apărut înainte.



```cpp

for (int i = 0; i < n; i++)

{

&#x20;   bool apareAnterior = false;



&#x20;   for (int j = 0; j < i; j++)

&#x20;   {

&#x20;       if (a\[i] == a\[j])

&#x20;       {

&#x20;           apareAnterior = true;

&#x20;           break;

&#x20;       }

&#x20;   }



&#x20;   if (!apareAnterior)

&#x20;       cout << a\[i] << " ";

}

```



Această metodă are complexitate `O(n²)`.



Dacă valorile sunt într-un interval mic, este mai eficient un tablou de frecvență.



\---



\# 27. Eliminarea elementelor dintr-un tablou



Eliminarea unui element presupune deplasarea elementelor din dreapta spre stânga.



Dacă vrem să eliminăm elementul de pe poziția `p`:



```cpp

for (int i = p; i < n - 1; i++)

&#x20;   a\[i] = a\[i + 1];



n--;

```



\### Exemplu



Inițial:



```text

10 20 30 40 50

```



Eliminăm `30`.



Rezultat:



```text

10 20 40 50

```



\---



\# 28. Inserarea unui element



Pentru inserarea valorii `x` pe poziția `p`, deplasăm elementele spre dreapta:



```cpp

for (int i = n; i > p; i--)

&#x20;   a\[i] = a\[i - 1];



a\[p] = x;

n++;

```



Este necesar să existe spațiu suficient în tabloul declarat.



\---



\# 29. Inversarea unui tablou



Putem inversa tabloul folosind doi indici:



```cpp

int st = 0;

int dr = n - 1;



while (st < dr)

{

&#x20;   swap(a\[st], a\[dr]);



&#x20;   st++;

&#x20;   dr--;

}

```



Exemplu:



```text

1 2 3 4 5

```



devine:



```text

5 4 3 2 1

```



\---



\# 30. Copierea unui tablou



```cpp

for (int i = 0; i < n; i++)

&#x20;   b\[i] = a\[i];

```



După executare, `b` conține aceleași valori ca `a`.



\---



\# 31. Compararea a două tablouri



Pentru două tablouri cu același număr de elemente:



```cpp

bool egale = true;



for (int i = 0; i < n; i++)

{

&#x20;   if (a\[i] != b\[i])

&#x20;   {

&#x20;       egale = false;

&#x20;       break;

&#x20;   }

}

```



\---



\# 32. Interclasarea a două tablouri ordonate



Dacă avem două tablouri sortate crescător:



```text

a: 1 4 7 10

b: 2 3 8 12

```



putem construi un al treilea tablou sortat.



```cpp

int i = 0, j = 0, k = 0;



while (i < n \&\& j < m)

{

&#x20;   if (a\[i] < b\[j])

&#x20;       c\[k++] = a\[i++];

&#x20;   else

&#x20;       c\[k++] = b\[j++];

}



while (i < n)

&#x20;   c\[k++] = a\[i++];



while (j < m)

&#x20;   c\[k++] = b\[j++];

```



Rezultatul:



```text

1 2 3 4 7 8 10 12

```



\---



\# 33. Căutarea liniară



Căutarea liniară verifică elementele unul câte unul.



```cpp

int poz = -1;



for (int i = 0; i < n; i++)

{

&#x20;   if (a\[i] == x)

&#x20;   {

&#x20;       poz = i;

&#x20;       break;

&#x20;   }

}

```



Complexitatea este:



```text

O(n)

```



\---



\# 34. Căutarea binară



Căutarea binară poate fi folosită atunci când tabloul este \*\*ordonat\*\*.



Ideea:



1\. se verifică elementul din mijloc;

2\. dacă este valoarea căutată, ne oprim;

3\. dacă este prea mic, căutăm în jumătatea dreaptă;

4\. dacă este prea mare, căutăm în jumătatea stângă.



```cpp

int st = 0, dr = n - 1;

bool gasit = false;



while (st <= dr)

{

&#x20;   int mij = (st + dr) / 2;



&#x20;   if (a\[mij] == x)

&#x20;   {

&#x20;       gasit = true;

&#x20;       break;

&#x20;   }

&#x20;   else if (a\[mij] < x)

&#x20;       st = mij + 1;

&#x20;   else

&#x20;       dr = mij - 1;

}

```



Complexitatea este:



```text

O(log n)

```



\---



\# 35. Sortarea unui tablou



Sortarea înseamnă așezarea elementelor într-o anumită ordine.



Exemplu crescător:



```text

5 2 8 1 4

```



devine:



```text

1 2 4 5 8

```



\---



\## 35.1. Sortare prin selecție



```cpp

for (int i = 0; i < n - 1; i++)

{

&#x20;   int pozMin = i;



&#x20;   for (int j = i + 1; j < n; j++)

&#x20;   {

&#x20;       if (a\[j] < a\[pozMin])

&#x20;           pozMin = j;

&#x20;   }



&#x20;   swap(a\[i], a\[pozMin]);

}

```



Complexitate:



```text

O(n²)

```



\---



\## 35.2. Sortare prin interschimbare



```cpp

for (int i = 0; i < n - 1; i++)

{

&#x20;   for (int j = i + 1; j < n; j++)

&#x20;   {

&#x20;       if (a\[i] > a\[j])

&#x20;           swap(a\[i], a\[j]);

&#x20;   }

}

```



Complexitate:



```text

O(n²)

```



\---



\## 35.3. Bubble Sort



```cpp

for (int i = 0; i < n - 1; i++)

{

&#x20;   for (int j = 0; j < n - i - 1; j++)

&#x20;   {

&#x20;       if (a\[j] > a\[j + 1])

&#x20;           swap(a\[j], a\[j + 1]);

&#x20;   }

}

```



Complexitate în cazul general:



```text

O(n²)

```



\---



\# 36. `sort()` în C++



În C++ putem folosi funcția standard:



```cpp

\#include <algorithm>



sort(a, a + n);

```



pentru sortare crescătoare.



Pentru sortare descrescătoare:



```cpp

sort(a, a + n, greater<int>());

```



Este important să includem:



```cpp

\#include <algorithm>

```



\---



\# 37. Numărul de elemente distincte



Dacă tabloul este sortat, putem număra valorile distincte eficient.



```cpp

sort(a, a + n);



int cnt = 0;



for (int i = 0; i < n; i++)

{

&#x20;   if (i == 0 || a\[i] != a\[i - 1])

&#x20;       cnt++;

}

```



\---



\# 38. Eliminarea valorilor duplicate



Dacă tabloul este sortat, duplicatele pot fi eliminate prin deplasare.



O variantă simplă:



```cpp

sort(a, a + n);



int m = 0;



for (int i = 0; i < n; i++)

{

&#x20;   if (i == 0 || a\[i] != a\[i - 1])

&#x20;       a\[m++] = a\[i];

}



n = m;

```



\---



\# 39. Secvențe de elemente



O \*\*secvență\*\* este o porțiune consecutivă a tabloului.



Exemplu:



```text

2 4 6 1 3 5 7 8

&#x20;   └─────────┘

```



Elementele:



```text

6 1 3 5

```



formează o secvență.



Elementele unei secvențe sunt consecutive în tablou.



\---



\# 40. Lungimea unei secvențe



Dacă o secvență începe la poziția `st` și se termină la poziția `dr`, lungimea ei este:



```text

dr - st + 1

```



Exemplu:



```text

poziții:  2  3  4  5

&#x20;         ↓  ↓  ↓  ↓

&#x20;         7  8  9 10

```



Lungimea este:



```text

5 - 2 + 1 = 4

```



\---



\# 41. Cea mai lungă secvență de elemente egale



Exemplu:



```text

1 1 1 2 2 3 3 3 3 1

```



Cea mai lungă secvență este:



```text

3 3 3 3

```



Algoritmul:



```cpp

int lung = 1;

int maxim = 1;



for (int i = 1; i < n; i++)

{

&#x20;   if (a\[i] == a\[i - 1])

&#x20;       lung++;

&#x20;   else

&#x20;       lung = 1;



&#x20;   if (lung > maxim)

&#x20;       maxim = lung;

}

```



\---



\# 42. Cea mai lungă secvență crescătoare



Pentru secvențe strict crescătoare:



```cpp

int lung = 1;

int maxim = 1;



for (int i = 1; i < n; i++)

{

&#x20;   if (a\[i] > a\[i - 1])

&#x20;       lung++;

&#x20;   else

&#x20;       lung = 1;



&#x20;   if (lung > maxim)

&#x20;       maxim = lung;

}

```



\---



\# 43. Cea mai lungă secvență descrescătoare



```cpp

int lung = 1;

int maxim = 1;



for (int i = 1; i < n; i++)

{

&#x20;   if (a\[i] < a\[i - 1])

&#x20;       lung++;

&#x20;   else

&#x20;       lung = 1;



&#x20;   if (lung > maxim)

&#x20;       maxim = lung;

}

```



\---



\# 44. Secvențe de elemente pare



Pentru cea mai lungă secvență de numere pare:



```cpp

int lung = 0;

int maxim = 0;



for (int i = 0; i < n; i++)

{

&#x20;   if (a\[i] % 2 == 0)

&#x20;   {

&#x20;       lung++;



&#x20;       if (lung > maxim)

&#x20;           maxim = lung;

&#x20;   }

&#x20;   else

&#x20;   {

&#x20;       lung = 0;

&#x20;   }

}

```



\---



\# 45. Determinarea începutului unei secvențe maxime



Dacă vrem și poziția de început:



```cpp

int lung = 1;

int maxim = 1;

int inceput = 0;

int inceputMax = 0;



for (int i = 1; i < n; i++)

{

&#x20;   if (a\[i] == a\[i - 1])

&#x20;   {

&#x20;       lung++;

&#x20;   }

&#x20;   else

&#x20;   {

&#x20;       lung = 1;

&#x20;       inceput = i;

&#x20;   }



&#x20;   if (lung > maxim)

&#x20;   {

&#x20;       maxim = lung;

&#x20;       inceputMax = inceput;

&#x20;   }

}

```



\---



\# 46. Ștergerea tuturor aparițiilor unei valori



Dacă dorim să eliminăm toate elementele egale cu `x`:



```cpp

int m = 0;



for (int i = 0; i < n; i++)

{

&#x20;   if (a\[i] != x)

&#x20;       a\[m++] = a\[i];

}



n = m;

```



Exemplu:



```text

2 5 3 5 7 5

```



pentru `x = 5` devine:



```text

2 3 7

```



\---



\# 47. Mutarea elementelor



\## Mutarea tuturor elementelor cu o poziție la dreapta



```cpp

for (int i = n; i > 0; i--)

&#x20;   a\[i] = a\[i - 1];

```



Înainte:



```text

1 2 3 4

```



După:



```text

\_ 1 2 3 4

```



\---



\## Mutarea tuturor elementelor cu o poziție la stânga



```cpp

for (int i = 0; i < n - 1; i++)

&#x20;   a\[i] = a\[i + 1];



n--;

```



\---



\# 48. Rotirea unui tablou



\## Rotire la stânga cu o poziție



```cpp

int x = a\[0];



for (int i = 0; i < n - 1; i++)

&#x20;   a\[i] = a\[i + 1];



a\[n - 1] = x;

```



Exemplu:



```text

1 2 3 4 5

```



devine:



```text

2 3 4 5 1

```



\---



\## Rotire la dreapta cu o poziție



```cpp

int x = a\[n - 1];



for (int i = n - 1; i > 0; i--)

&#x20;   a\[i] = a\[i - 1];



a\[0] = x;

```



Rezultat:



```text

5 1 2 3 4

```



\---



\# 49. Verificarea palindromului



Un tablou este palindrom dacă este identic citit de la stânga la dreapta și de la dreapta la stânga.



Exemplu:



```text

1 2 3 2 1

```



Algoritm:



```cpp

bool palindrom = true;



for (int i = 0; i < n / 2; i++)

{

&#x20;   if (a\[i] != a\[n - 1 - i])

&#x20;   {

&#x20;       palindrom = false;

&#x20;       break;

&#x20;   }

}

```



Nu este necesară verificarea tuturor elementelor: este suficient să comparăm elementele simetrice față de centru.



\---



\# 50. Intersectarea a două tablouri



Dacă trebuie determinate valorile care apar în ambele tablouri, putem verifica fiecare element din primul tablou în al doilea.



```cpp

for (int i = 0; i < n; i++)

{

&#x20;   bool gasit = false;



&#x20;   for (int j = 0; j < m; j++)

&#x20;   {

&#x20;       if (a\[i] == b\[j])

&#x20;       {

&#x20;           gasit = true;

&#x20;           break;

&#x20;       }

&#x20;   }



&#x20;   if (gasit)

&#x20;       cout << a\[i] << " ";

}

```



Dacă trebuie afișate valorile distincte, trebuie tratate și duplicatele.



\---



\# 51. Reuniunea a două tablouri



Reuniunea conține valorile care apar în cel puțin unul dintre cele două tablouri.



O soluție simplă este:



1\. afișăm valorile distincte din primul tablou;

2\. pentru fiecare element din al doilea tablou verificăm dacă nu a apărut deja;

3\. îl adăugăm dacă este nou.



\---



\# 52. Diferența dintre două tablouri



Diferența `A - B` conține elementele din `A` care nu apar în `B`.



Pentru fiecare element din `A`, verificăm dacă apare în `B`.



```cpp

for (int i = 0; i < n; i++)

{

&#x20;   bool gasit = false;



&#x20;   for (int j = 0; j < m; j++)

&#x20;   {

&#x20;       if (a\[i] == b\[j])

&#x20;       {

&#x20;           gasit = true;

&#x20;           break;

&#x20;       }

&#x20;   }



&#x20;   if (!gasit)

&#x20;       cout << a\[i] << " ";

}

```



\---



\# 53. Tablouri de caractere



Un șir de caractere poate fi reprezentat și printr-un tablou de caractere:



```cpp

char s\[101];

```



Citirea unui cuvânt:



```cpp

cin >> s;

```



Pentru lucrul cu șiruri de caractere există însă funcții și concepte specifice, care sunt tratate separat în capitolul \*\*Șiruri de caractere\*\*.



\---



\# 54. Tablouri cu indici de la 1



În unele probleme este mai convenabil să folosim indicii:



```text

1, 2, ..., n

```



Putem declara:



```cpp

int a\[101];

```



și să folosim:



```cpp

for (int i = 1; i <= n; i++)

&#x20;   cin >> a\[i];

```



Este important ca tabloul să aibă suficient spațiu pentru indicele `n`.



\### Atenție



În C/C++, indexarea începe în mod normal de la `0`.



Folosirea indicilor de la `1` este doar o convenție aleasă de programator.



\---



\# 55. Greșeli frecvente



\## 55.1. Depășirea limitelor tabloului



Greșit:



```cpp

int a\[100];



for (int i = 0; i <= 100; i++)

&#x20;   cin >> a\[i];

```



`a\[100]` nu există.



Indicii valizi sunt:



```text

0 ... 99

```



Corect:



```cpp

for (int i = 0; i < 100; i++)

&#x20;   cin >> a\[i];

```



\---



\## 55.2. Confuzia dintre `n` și ultimul indice



Dacă avem `n` elemente:



```text

primul indice = 0

ultimul indice = n - 1

```



\---



\## 55.3. Inițializarea greșită a maximului/minimului



Greșit:



```cpp

int maxim = 0;

```



Corect:



```cpp

int maxim = a\[0];

```



\---



\## 55.4. Uitarea actualizării lui `n`



După ștergerea unui element:



```cpp

n--;

```



După inserare:



```cpp

n++;

```



\---



\## 55.5. Deplasarea în direcția greșită



La \*\*inserare\*\*, elementele trebuie deplasate spre dreapta:



```cpp

for (int i = n; i > p; i--)

&#x20;   a\[i] = a\[i - 1];

```



La \*\*ștergere\*\*, elementele sunt deplasate spre stânga:



```cpp

for (int i = p; i < n - 1; i++)

&#x20;   a\[i] = a\[i + 1];

```



\---



\# 56. Complexitatea algoritmilor



Pentru BAC este util să putem identifica aproximativ eficiența unei soluții.



\### O singură parcurgere



```cpp

for (int i = 0; i < n; i++)

```



Complexitate:



```text

O(n)

```



\---



\### Două bucle imbricate



```cpp

for (int i = 0; i < n; i++)

&#x20;   for (int j = 0; j < n; j++)

```



Complexitate:



```text

O(n²)

```



\---



\### Căutare binară



```text

O(log n)

```



\---



\### Sortări elementare



De regulă:



```text

O(n²)

```



\---



\### Sortarea cu `std::sort`



În mod uzual:



```text

O(n log n)

```



\---



\# 57. Alegerea algoritmului potrivit



Într-o problemă cu tablouri, trebuie să identificăm mai întâi operația cerută.



| Cerință                                      | Tehnică                         |

| -------------------------------------------- | ------------------------------- |

| suma elementelor                             | acumulare                       |

| produsul elementelor                         | acumulare                       |

| numărul elementelor care respectă o condiție | contor                          |

| maxim/minim                                  | variabilă de extrem             |

| poziția maximului/minimului                  | indice                          |

| existența unei valori                        | căutare                         |

| prima apariție                               | căutare + `break`               |

| ultima apariție                              | parcurgere completă             |

| toate elementele respectă o condiție         | căutarea unei excepții          |

| frecvența valorilor                          | tablou de frecvență             |

| eliminarea unui element                      | deplasare la stânga             |

| inserarea unui element                       | deplasare la dreapta            |

| inversare                                    | doi indici                      |

| rotire                                       | memorarea elementului mutat     |

| secvență maximă                              | contorizarea lungimii curente   |

| valori distincte                             | verificare apariții / frecvențe |

| căutare într-un tablou nesortat              | căutare liniară                 |

| căutare într-un tablou sortat                | căutare binară                  |

| sortare                                      | algoritm de sortare             |

| combinarea a două tablouri sortate           | interclasare                    |



\---



\# 58. Tipare esențiale de memorat



\## Contor



```cpp

int cnt = 0;



for (int i = 0; i < n; i++)

&#x20;   if (conditie)

&#x20;       cnt++;

```



\---



\## Sumă condiționată



```cpp

int s = 0;



for (int i = 0; i < n; i++)

&#x20;   if (conditie)

&#x20;       s += a\[i];

```



\---



\## Maxim



```cpp

int maxim = a\[0];



for (int i = 1; i < n; i++)

&#x20;   if (a\[i] > maxim)

&#x20;       maxim = a\[i];

```



\---



\## Minim



```cpp

int minim = a\[0];



for (int i = 1; i < n; i++)

&#x20;   if (a\[i] < minim)

&#x20;       minim = a\[i];

```



\---



\## Căutare



```cpp

int poz = -1;



for (int i = 0; i < n; i++)

{

&#x20;   if (a\[i] == x)

&#x20;   {

&#x20;       poz = i;

&#x20;       break;

&#x20;   }

}

```



\---



\## Secvență



```cpp

int lung = 1;

int maxim = 1;



for (int i = 1; i < n; i++)

{

&#x20;   if (conditie)

&#x20;       lung++;

&#x20;   else

&#x20;       lung = 1;



&#x20;   if (lung > maxim)

&#x20;       maxim = lung;

}

```



\---



\## Ștergere



```cpp

for (int i = p; i < n - 1; i++)

&#x20;   a\[i] = a\[i + 1];



n--;

```



\---



\## Inserare



```cpp

for (int i = n; i > p; i--)

&#x20;   a\[i] = a\[i - 1];



a\[p] = x;

n++;

```



\---



\## Inversare



```cpp

for (int i = 0; i < n / 2; i++)

&#x20;   swap(a\[i], a\[n - 1 - i]);

```



\---



\# 59. Cum abordezi o problemă cu tablouri



Când primești o problemă, încearcă să răspunzi în ordine la următoarele întrebări:



\### 1. Trebuie să memorez tabloul?



Dacă prelucrarea poate fi făcută în timpul citirii, poate să nu fie necesară memorarea.



\### 2. Ce se cere?



Identifică dacă trebuie:



\* sumă;

\* produs;

\* număr de elemente;

\* maxim/minim;

\* poziție;

\* verificare;

\* căutare;

\* sortare;

\* eliminare;

\* inserare;

\* secvență;

\* frecvență;

\* interclasare.



\### 3. Este suficientă o singură parcurgere?



Încearcă mai întâi să găsești o soluție `O(n)`.



\### 4. Pot folosi un tablou de frecvență?



Dacă valorile sunt într-un interval mic, frecvențele pot simplifica foarte mult problema.



\### 5. Este necesară sortarea?



Sortarea poate simplifica problemele cu:



\* valori distincte;

\* frecvențe;

\* căutări;

\* interclasare;

\* determinarea anumitor proprietăți.



\### 6. Trebuie păstrată ordinea inițială?



Acest lucru este foarte important înainte de a sorta sau elimina elemente.



\---



\# 60. Cazuri-limită importante



La problemele cu tablouri trebuie testate în special:



\### Un singur element



```text

n = 1

```



\### Toate elementele sunt egale



```text

5 5 5 5 5

```



\### Toate elementele sunt diferite



```text

1 4 7 9 12

```



\### Toate valorile sunt negative



```text

\-5 -2 -10 -1

```



\### Tablou deja sortat



```text

1 2 3 4 5

```



\### Tablou sortat invers



```text

5 4 3 2 1

```



\### Valoarea căutată nu există



Trebuie să avem un mod de a reprezenta acest caz, de exemplu:



```cpp

poz = -1;

```





