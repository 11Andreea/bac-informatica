# Operatorii în C++

## 1. Operatori Aritmetici în C++

Operatorii aritmetici efectuează calcule matematice asupra operanzilor (constante, variabile sau expresii).

### A. Împărțirea Întreagă vs. Împărțirea Zecimală (`/`)

Comportamentul operatorului `/` depinde exclusiv de tipul operanzilor:

* **Împărțire întreagă:** Se aplică dacă **ambii** operanzi sunt de tip întreg (`int`, `short`, `long long`). Rezultatul este câtul întreg, iar partea zecimală se taie (se trunchiază).
* **Împărțire zecimală:** Se aplică dacă **cel puțin un** operand este de tip real (`float`, `double`). Dacă un operand este întreg și celălalt este real, C++ convertește implicit operandul întreg la tip real înainte de a efectua împărțirea.

```cpp
int a = 11, b = 4;
double x = 11.0, y = 4.0;

cout << a / b;     // Afișează 2 (împărțire întreagă)
cout << x / y;     // Afișează 2.75 (împărțire reală)
cout << a / 4.0;   // Afișează 2.75 (a este convertit implicit la double)

```

### B. Operatorul Modulo (`%`)

Operatorul `%` calculează restul împărțirii întregi a două numere.

* **Restricție strictă:** Ambii operanzi **trebuie** să fie de tip întreg. Folosirea `%` pe numere de tip `double` sau `float` generează eroare de compilare.

**Aplicații frecvente la Bacalaureat:**

* Extragerea ultimei cifre a unui număr: `n % 10`
* Verificarea parității: `n % 2 == 0` (adevărat dacă $n$ este par)
* Testarea divizibilității: `a % b == 0` (adevărat dacă $a$ se divide cu $b$)

---

## 2. Operatori Logici și Legile lui De Morgan

Lucrează cu valori de adevărat (`1` / `true`) și fals (`0` / `false`). În C++, orice valoare numerică nenulă este interpretată ca `true`, iar `0` este interpretat ca `false`.

### A. Tabela de Adevăr pentru Operatori Logici

| `p` | `q` | `!p` (Negare) | `p && q` (Conjuncție - ȘI) | `p || q` (Disjuncție - SAU) |
| --- | --- | --- | --- | --- |
| `0` (Fals) | `0` (Fals) | `1` | `0` | `0` |
| `0` (Fals) | `1` (Adevărat) | `1` | `0` | `1` |
| `1` (Adevărat) | `0` (Fals) | `0` | `0` | `1` |
| `1` (Adevărat) | `1` (Adevărat) | `0` | `1` | `1` |

> **Evaluarea de scurtcircuit (Short-Circuit Evaluation):**
> * La `p && q`, dacă `p` este `0` (fals), C++ **nu mai evaluează** `q`, deoarece întregul rezultat va fi garantat `0`.
> * La `p || q`, dacă `p` este `1` (adevărat), C++ **nu mai evaluează** `q`, deoarece întregul rezultat va fi garantat `1`.
> 
> 

### B. Legile lui De Morgan

Permit simplificarea sau transformarea negării unor expresii logice compuse:

1. `!(p && q)` este echivalent cu `!p || !q`
2. `!(p || q)` este echivalent cu `!p && !q`

**Exemplu din variantele de examen:**
Cerință: Determinați negarea condiției ca un număr $x$ să aparțină intervalului deschis $(5, 8]$.

* Condiția de apartenență: `(x > 5 && x <= 8)`
* Negarea expresiei folosind De Morgan:

$$\mathbf{!}\mathbf{(x > 5 \ \ \mathbf{\&\&} \ \ x <= 8)} \ \longrightarrow \ \mathbf{!(x > 5) \ \ \mathbf{\Vert{}\Vert{}} \ \ !(x <= 8)} \ \longrightarrow \ \mathbf{(x <= 5 \ \ \mathbf{\Vert{}\Vert{}} \ \ x > 8)}$$



---

## 3. Incrementare și Decrementare: Pre vs. Post

Operatorii `++` și `--` pot fi plasați înainte (prefixat) sau după operand (postfixat).

| Expresie | Denumire | Mecanism de funcționare | Valoare returnată |
| --- | --- | --- | --- |
| `++x` | Preincrementare | Mărește pe `x` cu `1`, **apoi** returnează noua valoare | Noua valoare a lui `x` |
| `x++` | Postincrementare | Salvează valoarea curentă a lui `x`, mărește pe `x` cu `1`, **apoi** returnează valoarea veche | Valoarea inițială a lui `x` |
| `--x` | Predecrementare | Micșorează pe `x` cu `1`, **apoi** returnează noua valoare | Noua valoare a lui `x` |
| `x--` | Postdecrementare | Salvează valoarea curentă, micșorează pe `x` cu `1`, **apoi** returnează valoarea veche | Valoarea inițială a lui `x` |

```cpp
int x = 5, y, z;

y = x++; // y primește 5 (valoarea veche), iar x devine 6
z = ++x; // x devine 7, iar z primește 7 (noua valoare)

cout << x << " " << y << " " << z; // Afișează: 7 5 7

```

> **Regulă Lvalue:** Preincrementarea (`++x`) returnează o referință către variabilă (lvalue), deci i se pot aplica alți operatori în lanț: `++ ++x;`. Postincrementarea (`x++`) returnează o valoare temporară (rvalue), astfel că expresia `(x++)++;` este **eroare de compilare**.

---

## 4. Operatorul Condițional Ternar (`? :`)

Este singurul operator din C++ care primește 3 operanzi. Se folosește ca o alternativă compactă pentru structura decizională `if - else`.

$$\text{Condiție} \ \mathbf{?} \ \text{Expresie\_Adevărat} \ \mathbf{:} \ \text{Expresie\_Fals}$$

### Mecanism de evaluare:

1. Se evaluează `Condiție`.
2. Dacă este adevărată (`true`), se evaluează **exclusiv** `Expresie_Adevărat` și valoarea ei devine rezultatul întregii operații.
3. Dacă este falsă (`false`), se evaluează **exclusiv** `Expresie_Fals` și valoarea ei devine rezultatul.

```cpp
int a = 10, b = 25;

// Determinarea maximului
int max_val = (a > b) ? a : b; // max_val va fi 25

// Afișarea parității direct în cout
cout << (a % 2 == 0 ? "Par" : "Impar");

// Operatori condiționali imbricați (verificare semn)
cout << (a > 0 ? "Pozitiv" : (a == 0 ? "Nul" : "Negativ"));

```

---

## 5. Operații pe Biți (Bitwise Operations)

Lucrează direct pe reprezentarea în memorie a numerelor întregi în baza 2 (complement față de 2 pentru numere negative).

### A. Reprezentarea în Memorie (Exemplu pe 16 biți - `short`)

* Numărul `13` în baza 2: `0000000000001101`
* Numărul `151` în baza 2: `0000000010010111`

### B. Operatorii Logici pe Biți

```
  0000000000001101  (13)             0000000000001101  (13)             0000000000001101  (13)
& 0000000010010111 (151)           | 0000000010010111 (151)           ^ 0000000010010111 (151)
------------------                 ------------------                 ------------------
  0000000000000101   = 5             0000000010011111   = 159           0000000010011010   = 154

```

* **`&` (AND pe biți):** Bitul rezultat este `1` dacă **ambii** biți de pe aceeași poziție sunt `1`.
* **`|` (OR pe biți):** Bitul rezultat este `1` dacă **cel puțin un** bit de pe aceeași poziție este `1`.
* **`^` (XOR / SAU Exclusiv pe biți):** Bitul rezultat este `1` dacă biții comparați sunt **diferiți**.
* **`~` (NOT / Negație pe biți):** Invertește fiecare bit (`0` devine `1`, `1` devine `0`). Pentru un număr întreg $x$, `~x` este egal matematic cu $-(x + 1)$.

### C. Deplasarea pe Biți (Shift Operators)

* **Deplasare stânga (`<<`):** Deplasează toți biții spre stânga cu $k$ poziții, completând la dreapta cu `0`.

$$\text{Fórmula generală: } n \ll k = n \cdot 2^k$$



*Exemplu:* `13 << 3` devine $13 \cdot 2^3 = 13 \cdot 8 = 104$.
* **Deplasare dreapta (`>>`):** Deplasează toți biții spre dreapta cu $k$ poziții, eliminând biții din capătul drept.

$$\text{Formulă generală: } n \gg k = \left\lfloor \frac{n}{2^k} \right\rfloor$$



*Exemplu:* `133 >> 3` devine $\lfloor 133 / 8 \rfloor = 16$.

---

## 6. Atribuirea și Interschimbarea (Regula Paharelor)

Atribuirea simplă (`=`) copiază valoarea din dreapta în variabila din stânga.

### A. Atribuiri Compuse

Abreviază operațiile în care o variabilă este actualizată pe baza propriei valori:

* `x += y` $\equiv$ `x = x + y`
* `x *= y` $\equiv$ `x = x * y`
* `x >>= 1` $\equiv$ `x = x >> 1` (echivalent cu `x = x / 2`)

### B. Interschimbarea a Două Variabile

**Metoda 1: Cu variabilă auxiliară (Standard / Regula Paharelor)**

```cpp
int a = 5, b = 7;
int aux = a; // Pasul 1: Salvăm valoarea lui 'a' în paharul 'aux'
a = b;       // Pasul 2: Punem valoarea lui 'b' în 'a'
b = aux;     // Pasul 3: Punem valoarea salvată în 'b'

```

**Metoda 2: Fără variabilă auxiliară (Aritmetică)**

```cpp
int a = 5, b = 7;
a = a + b; // a devine 12
b = a - b; // b devine (12 - 7) = 5 (valoarea inițială a lui a)
a = a - b; // a devine (12 - 5) = 7 (valoarea inițială a lui b)

```

**Metoda 3: Fără variabilă auxiliară (Folosind XOR pe biți)**

```cpp
int a = 5, b = 7;
a = a ^ b;
b = a ^ b;
a = a ^ b;

```

---

## 7. Prioritatea și Asociativitatea Operatorilor

Prioritatea determină ordinea în care se evaluează operatorii dintr-o expresie complexă în absența parantezelor.

| Nivel Prioritate | Operatori | Descriere | Asociativitate |
| --- | --- | --- | --- |
| **1 (Maximă)** | `()` `[]` `.` | Paranteze, acces elemente | De la stânga la dreapta |
| **2** | `!` `~` `++` `--` `-` (unar) | Operatori unari, negații, incrementări | **De la dreapta la stânga** |
| **3** | `*` `/` `%` | Înmulțire, împărțire, rest | De la stânga la dreapta |
| **4** | `+` `-` | Adunare, scădere | De la stânga la dreapta |
| **5** | `<<` `>>` | Deplasări pe biți | De la stânga la dreapta |
| **6** | `<` `<=` `>` `>=` | Comparații de mărime | De la stânga la dreapta |
| **7** | `==` `!=` | Comparații de egalitate | De la stânga la dreapta |
| **8** | `&` | AND pe biți | De la stânga la dreapta |
| **9** | `^` | XOR pe biți | De la stânga la dreapta |
| **10** | `|` | OR pe biți | De la stânga la dreapta |
| **11** | `&&` | AND logic | De la stânga la dreapta |
| **12** | `||` | OR logic | De la stânga la dreapta |
| **13** | `? :` | Operatorul condițional | **De la dreapta la stânga** |
| **14 (Minimă)** | `=` `+=` `-=` `*=` `/=` | Atribuiri | **De la dreapta la stânga** |