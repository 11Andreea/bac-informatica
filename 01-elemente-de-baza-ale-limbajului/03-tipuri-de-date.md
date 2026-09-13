# Tipuri de Date, Limite & Conversii 

## 1. Ce este un tip de dată?

În C++, variabila este un „container” din memorie. Atunci când o declari, primul lucru pe care îl scrii este **tipul de dată**. Acesta îi spune compilatorului trei lucruri esențiale:
1. **Ce fel de valori** poți stoca (numere întregi, numere zecimale, caractere, valori de adevăr).
2. **Cât spațiu ocupă** în memoria RAM (1, 2, 4 sau 8 octeți).
3. **Ce operații** ai voie să faci cu acea variabilă.

> **Regulă de aur:** Alegerea tipului este prima și una dintre cele mai importante decizii. Un tip prea mic duce la **overflow** (depășire de memorie și rezultate eronate), iar un tip prea mare consumă memorie inutil.

C++ împarte tipurile în două mari categorii:
* **Tipuri simple (primitive):** `int`, `float`, `double`, `char`, `bool`, `pointer`, `void`.
* **Tipuri derivate/compuse:** tablouri (vectori, matrice), structuri (`struct`), clase (`class`), enumerări (`enum`).

*În acest ghid ne vom ocupa exclusiv de **tipurile simple** și regulile lor.*

---

## 2. Tipurile de Date Simple și Modificatorii

Mai jos ai tabelul complet cu toate tipurile simple de date utilizate la liceu, dimensiunea lor în memorie, dacă au sau nu semn, precum și intervalul exact de valori.

| Tip de date | Dimensiune | Cu/Fără semn | Interval de valori / Precizie | Descriere și Utilizare la Bac |
| :--- | :---: | :---: | :---: | :--- |
| `short` / `signed short` | 2 octeți | Cu semn | $[-32.768, 32.767]$ | Întregi mici (echivalent cu `short int`) |
| `unsigned short` | 2 octeți | Fără semn | $[0, 65.535]$ | Întregi mici doar pozitivi |
| `int` / `signed int` | 4 octeți | Cu semn | $[-2^{31}, 2^{31}-1]$ ($\approx -2 \cdot 10^9 \dots 2 \cdot 10^9$) | **Standardul** pentru numere întregi ($\approx 2$ miliarde) |
| `unsigned int` | 4 octeți | Fără semn | $[0, 2^{32}-1]$ ($\approx 0 \dots 4 \cdot 10^9$) | Numere naturale (ex: număr de elemente, indici) |
| `long` / `signed long` | 4 octeți | Cu semn | $[-2^{31}, 2^{31}-1]$ | La fel ca `int` pe compilatoarele de liceu (`long int`) |
| `unsigned long` | 4 octeți | Fără semn | $[0, 2^{32}-1]$ | La fel ca `unsigned int` |
| `long long` / `signed long long` | 8 octeți | Cu semn | $[-2^{63}, 2^{63}-1]$ ($\approx -9 \cdot 10^{18} \dots 9 \cdot 10^{18}$) | **OBLIGATORIU** pentru numere ce depășesc 2 miliarde |
| `unsigned long long` | 8 octeți | Fără semn | $[0, 2^{64}-1]$ ($\approx 0 \dots 1.8 \cdot 10^{19}$) | Valori pozitive uriașe |
| `float` | 4 octeți | Real | Precizie $\approx 7$ zecimale | Numere reale în virgulă mobilă |
| `double` | 8 octeți | Real | Precizie $\approx 15$ zecimale | **Recomandat** pentru numere reale la Bac |
| `long double` | 10-16 octeți | Real | Precizie $\approx 18$ zecimale | Numere reale de precizie foarte înaltă |
| `char` / `signed char` | 1 octet | Cu semn | $[-128, 127]$ | Un singur caracter (Coduri ASCII $0 \dots 127$) |
| `unsigned char` | 1 octet | Fără semn | $[0, 255]$ | Caractere / Coduri ASCII extins |
| `bool` | 1 octet | Logic | `true` ($1$) sau `false` ($0$) | Valori logice (Adevărat / Fals) |
| `pointer` | 4 sau 8 octeți | N/A | Adrese de memorie (ex: `0x7ffe...`) | Memorează adresa unei alte variabile |
| `void` | 0 octeți | N/A | Fără valoare | Tip vid (folosit la funcții fără return sau pointeri generici) |

---

## 3. Detalierea Tipurilor de Date Simple

### A. Tipurile Întregi (`int`, `short`, `long long`)
Stochează numere fără parte zecimală (atât pozitive, cât și negative).
* Datorită reprezentării interne (în complement față de 2), un `int` acoperă intervalul $[-2.147.483.648, 2.147.483.647]$.
* **Când folosești `int`?** În 90% din cazuri, dacă datele nu depășesc 2 miliarde.
* **Când folosești `long long`?** Dacă cerința menționează numere mari (ex: mai mari de $2 \cdot 10^9$, produse de numere, numere cu 10-18 cifre).

### B. Tipurile Reale (`float`, `double`)
Stochează numere cu parte zecimală. Punctul `.` este separatorul zecimal.
Pot fi scrise în **format clasic** sau **științific (exponențial)**:
```cpp
float p = 3.14;
double r = 2.5;
double aria = p * r * r;

// Forma științifică (exponențială)
double x = 1.24E+07; // Înseamnă 1.24 * 10^7 = 12400000
```

### C. Tipul Caracter (`char`)
Stochează **un singur caracter** delimitat strict de apostroafe `' '`.

> ⚠️ **ATENȚIE MARE:** Ghilimelele `" "` sunt pentru șiruri de caractere!
> `'A'` $\neq$ `"A"` (`'A'` este caracter de 1 octet, `"A"` este un șir de caractere).

În memorie, `char` stochează de fapt un număr întreg: **codul ASCII** al caracterului respectiv.
```cpp
char c = 'A';
cout << c;        // Afișează: A
cout << (int)c;   // Afișează: 65 (codul ASCII al literei 'A')

c = 65;
cout << c;        // Afișează tot: A (conversie implicită)
```

#### Reguli de citire și afișare pentru `char`:
1. **Citirea de la tastatură (`cin >>`):**
   * Prelucrează primul caracter introdus și sare peste spațiile albe anterioare.
   * Dacă introduci text mai lung (ex: `ABC`), citirile succesive vor lua fiecare caracter în parte:
     ```cpp
     char x, y;
     cin >> x >> y; // Dacă introduci "AB" sau "A B", x devine 'A' și y devine 'B'
     ```
   * Dacă introduci `145` într-o variabilă `char x;`, `x` va primi caracterul `'1'`, nu numărul $145$!

2. **Transformarea între litere mari și mici:**
   În tabelul ASCII, literele mari sunt înaintea celor mici. Diferența dintre codul unei litere mici și al literei mari corespunzătoare este **întotdeauna 32** (`'a' - 'A' = 32`).
   ```cpp
   char literaMica = 'k';
   
   // Trecere de la mică la mare (scădem 32):
   char literaMare = literaMica - ('a' - 'A'); // 'k' - 32 = 'K'
   
   // Trecere de la mare la mică (adăugăm 32):
   char înapoiMica = literaMare + 32;          // 'K' + 32 = 'k'
   ```

### D. Tipul Logic (`bool`)
Are doar două valori posibile: `true` (adevărat, reprezentat prin $1$) sau `false` (fals, reprezentat prin $0$).
```cpp
bool estePrim = false;
int x = 5;

if (x > 0) {
    estePrim = true;
}
```

### E. Tipul Pointer
Stochează adresa de memorie a unei alte variabile. Este folosit în alocarea dinamică a memoriei și în structuri de date avansate (liste, arbori).

### F. Tipul Void (`void`)
Înseamnă „lipsa oricărui tip” sau „fără valoare”.
* **Nu poți declara variabile de tip `void`** (`void x;` va da eroare de compilare!).
* Se folosește la funcții care nu returnează nicio valoare sau la pointeri generici.

---

## 4. Modificatorii de Tip

Modificatorii schimba modul în care compilatorul interpretează memoria unei variabile. Se pot aplica tipurilor `int`, `double` și `char`:

1. `signed` – indică faptul că numărul poate fi și negativ și pozitiv (este setarea implicită).
2. `unsigned` – elimină numerele negative și dublează limita superioară pentru valori pozitive.
3. `short` – reduce dimensiunea memoriei (de obicei la 2 octeți).
4. `long` / `long long` – mărește dimensiunea memoriei (la 4, respectiv 8 octeți).

---

## 5. Conversii de Tip (Type Casting)

Conversia de tip înseamnă transformarea unei valori dintr-un tip de dată în altul. În C++ avem două categorii de conversii: **implicite** și **explicite**.

---

### A. Conversia Implicită (Automată)
Are loc automat de la sine în timpul executării programului, atunci când combini într-o operație operanzi de tipuri diferite sau când atribui o valoare de un tip unei variabile de alt tip.

Compilatorul încearcă să aducă ambele date la același tip pentru a putea efectua calculele.

#### 1. Promovarea (De la tip inferior -> tip superior)
Se face fără pierderi de date. Compilatorul urcă valoarea mai mică la tipul mai mare.
```cpp
int n = 5;
double x;
x = n; // Promovare: n devine 5.0 și este salvat în x
```
La operații mixte, de exemplu `2 + 1.5`, `2` (int) este promovat la `2.0` (double), iar rezultatul va fi `3.5`.

#### 2. Retrogradarea (De la tip superior -> tip inferior)
Apare când forțezi o valoare mai mare într-un tip mai mic. **Atenție: Produce trunchiere și pierdere de date!**
```cpp
double x = 5.75;
int n;
n = x; // Retrogradare: partea zecimală .75 SE PIERDE! n devine 5.
```

#### Reguli speciale ale conversiei implicite:
* **Întregi negativi $\rightarrow$ Tipuri `unsigned`:** Dacă atribui un număr negativ unui tip fără semn (ex: `unsigned int x = -1;`), rezultatul va fi reprezentarea în complement față de 2. `-1` devine cea mai mare valoare posibilă din `unsigned int` ($2^{32}-1 \approx 4.29 \cdot 10^9$).
* **Numere $\rightarrow$ `bool`:** Orice valoare **nenulă** (pozitivă sau negativă) devine `true` ($1$). Valoarea `0` devine `false` ($0$).
* **Reale $\rightarrow$ Întregi:** Se elimină complet partea zecimală (nu se rotunjește, ci se trunchiază).

---

### B. Conversia Explicită (Manuală / Type Casting)
Reprezintă modificarea intenționată a tipului de dată făcută direct de către programator.

#### Sintaxă:
1. `(TIP) expresie` $\rightarrow$ stilul C (cel mai folosit)
2. `TIP(expresie)` $\rightarrow$ stilul C++ (funcționează doar dacă numele tipului are un singur cuvânt, ex: `int(x)`. Formula `unsigned int(x)` este **greșită**!).

```cpp
char c = 'A';
cout << (int)c; // Afișează 65 (codul ASCII)

int n = 97;
cout << (char)n; // Afișează 'a'
```

*(Notă: C++ modern include și operatori avansați precum `static_cast`, `const_cast`, `reinterpret_cast` și `dynamic_cast`, dar la examenul de Bacalaureat se folosește forma clasică `(TIP) expresie`).*

---

## 6. Probleme Clasice & Capcane de Bacalaureat

### Capcana #1: Împărțirea Întreagă și Calculul Mediei Aritmetice
În C++, dacă ambii operanzi dintr-o împărțire sunt întregi, operația `/` va fi o **împărțire întreagă** (va returna doar câtul, pierzând restul/zecimalele).

```cpp
int a = 7, b = 8, c = 8;
int S = a + b + c; // S = 23

// GREȘIT: S / 3 calculează 23 / 3 = 7 (împărțire întreagă)
double mediaGresita = S / 3; // Stochează 7.0 (pierzi zecimalele!)

// CORECT Varianta 1 (promovare implicită folosind un literal real):
double media1 = S / 3.0; // S este promovat la double, rezultatul este 7.66667

// CORECT Varianta 2 (promovare prin înmulțire):
double media2 = 1.0 * S / 3; // 1.0 * S devine double, apoi împărțirea se face real

// CORECT Varianta 3 (conversie explicită):
double media3 = (double)S / 3; // S este convertit explicit la double
```

---

### Capcana #2: Depășirea de Tip (Overflow) și Trucul `1LL`
Când înmulțești două variabile de tip `int`, C++ va efectua înmulțirea tot în `int`. Dacă rezultatul depășește $2 \cdot 10^9$, se produce **overflow** (obții un număr negativ sau complet eronat) *înainte* ca valoarea să poată fi salvată într-un `long long`!

```cpp
int n = 1000000; // 10^6

// GREȘIT: n * n calculează 10^12 în int -> Overflow! (Ex: -727379968)
long long prodGresit = n * n; 

// CORECT Varianta 1 (folosind literalul 1LL):
long long prodCorect1 = 1LL * n * n; // 1LL este valoarea 1 de tip long long.
                                     // Forțează întreaga operație să se execute pe 64 biți!

// CORECT Varianta 2 (conversie explicită):
long long prodCorect2 = (long long)n * n;
```

#### Atenție la Prioritatea Operatorilor!
Ordinea operațiilor contează enorm când faci type-casting:
```cpp
int n = 1000000;

// GREȘIT! n * n se evaluează PRIMUL (înmulțirea are prioritate față de adunare)
// n * n face overflow în int înainte de a fi adunat la 1LL!
long long gresit = 1LL * n + n * n; 

// CORECT: Se forțează ambele înmulțiri să lucreze cu long long
long long corect = 1LL * n + 1LL * n * n;
```

---

## Rezumat
1. Folosește **`int`** pentru numere obișnuite și **`long long`** când calculezi produse sau valori peste $2 \cdot 10^9$.
2. Folosește **`double`** în loc de `float` pentru o precizie zecimală mai bună.
3. Caracterele **`char`** stochează coduri ASCII. Diferența dintre litere mici și mari este `'a' - 'A' = 32`.
4. Ai grijă la împărțirea întregilor: folosește `/ 3.0` sau `(double)` pentru a păstra zecimalele.
5. Evită overflow-ul la înmulțiri mari folosind prefixul **`1LL *`**.