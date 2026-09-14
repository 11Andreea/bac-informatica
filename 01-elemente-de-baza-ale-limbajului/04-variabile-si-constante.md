
# Variabile, Constante și Cuvinte Rezervate în C++

Un program funcționează simplu: preia date, le prelucrează în **memoria RAM** și afișează rezultatul. În RAM, datele sunt stocate în locații specifice (fiecare octet are o adresă unică în hexazecimal, începând de la `0`).

---

## 1. Variabilele

O **variabilă** este o zonă din memoria RAM care conține o valoare ce se poate modifica pe parcursul execuției programului.

### Caracteristicile unei variabile
* **Adresa de memorie:** Numărul de ordine al octetului din RAM unde este salvată variabila.
* **Identificatorul (numele):** Numele pe care i-l dai variabilei pentru a o folosi în cod.
* **Tipul de dată:** Stabilește ce fel de valori poate reține (întregi, reale, caractere etc.) și cât spațiu ocupă.
* **Domeniul de vizibilitate:** Zona din cod în care variabila există și poate fi utilizată.

---

### Regulile pentru numirea variabilelor (Identificatori)

Pentru ca un nume de variabilă să fie valid la compilare, trebuie să respecte aceste reguli stricte:

* **Caractere permise:** Doar litere din alfabetul englez (`a-z`, `A-Z`), cifre (`0-9`) și caracterul underline (`_`).
* **Fără cifră la început:** Primul caracter **trebuie** să fie o literă sau `_` (de exemplu, `2a` este ILEGAL).
* **Case-sensitive:** C++ face diferența între litere mari și mici (`suma`, `Suma` și `SUMA` sunt trei variabile complet diferite).
* **Fără spații sau caractere speciale:** Nu sunt permise spații, cratime (`-`) sau diacritice (`ă`, `î`, `ș`, `ț`, `â`).
* **Fără cuvinte rezervate:** Nu poți folosi cuvinte cheie din limbaj (ex: `int`, `return`, `for`).

#### Exemple de identificatori:
| Corecți | Incorecți (Greșiți) | Motivația greșelii |
| :--- | :--- | :--- |
| `a`, `numar`, `Numar` | `2a` | Începe cu o cifră |
| `alt_numar`, `a2b` | `alt numar` | Conține spațiu |
| `un_nume_lung` | `un-numar` | Conține minus (`-`) |
| `_suma` *(neindicat)* | `număr` | Conține diacritice (`ă`) |

---

### Declararea și inițializarea variabilelor

Sintaxa generală este:
```cpp
Tip_de_date nume_variabila;

```

#### Exemple de declarări:

```cpp
int a, b;                   // Două variabile de tip întreg, neinițializate
int x = 10;                 // Declarare și inițializare cu valoarea 10
double media = 9.50;        // Număr real
char c = 'A';               // Caracter
bool ok = true;             // Valoare logică

```

---

## 2. Variabile Globale vs. Variabile Locale

Locul în care declari o variabilă îi determină **durata de viață** și **zona din program** de unde poate fi accesată.

```cpp
#include <iostream>
using namespace std;

int g; // VARIABILĂ GLOBALĂ (în afara oricărei funcții)

void functie() {
    int x = 5; // VARIABILĂ LOCALĂ (există doar în interiorul acestei funcții)
}

int main() {
    int n; // VARIABILĂ LOCALĂ (există doar în main)
    return 0;
}

```

### Comparație

| Criteriu | Variabile Globale | Variabile Locale |
| --- | --- | --- |
| **Unde se declară** | În afara oricărei funcții (la începutul fișierului) | În interiorul unui bloc de cod `{ ... }` |
| **Unde sunt vizibile** | În tot fișierul, din locul declarării până la final | Doar în blocul `{ ... }` în care au fost declarate |
| **Valoare inițială** | Se inițializează **automat cu 0** | Conțin **valori reziduale (gunoi/reziduuri)** |
| **Durată de viață** | Pe toată durata rulării programului | Sunt create la intrarea în bloc și șterse la ieșire |

> **Atenție la examen:** Dacă o variabilă locală are același nume cu una globală, variabila locală are prioritate în blocul ei (o „ascunde” pe cea globală). Folosirea unei variabile locale neinițializate duce la comportament imprevizibil!

---

## 3. Constantele

Constantele sunt date care **NU își pot modifica valoarea** în timpul execuției programului.

### A. Constante simbolice (cu nume)

Se pot defini în două moduri:

1. **Cu modificatorul `const` (Recomandat în C++):**
```cpp
const int NMAX = 100;
const double PI = 3.14159;

```


*Notă:* La declararea cu `const`, inițializarea este **obligatorie**. Încercarea de a modifica valoarea ulterior (`NMAX = 200;`) va genera eroare de compilare.
2. **Cu directiva `#define` (Preluată din C):**
```cpp
#define NMAX 100

```


*Notă:* Nu se pune punct și virgulă `;` la final și nu se precizează tipul de dată. Preprocesorul înlocuiește direct textul `NMAX` cu `100` înainte de compilare.

---

### B. Constante literale (Literali)

Sunt valori scrise direct în codul sursă.

#### 1. Literali întregi (Baze de numerație)

* **Zecimal (baza 10):** Scrise obișnuit. Exemple: `176`, `-54`, `0`.
* **Octal (baza 8):** Încep obligatoriu cu cifra `0`. Conțin cifre de la `0` la `7`.
* Exemple: `015` (care înseamnă 13 în baza 10), `062`.
* *Capcană:* `0295` este **greșit** și dă eroare de compilare (cifra 9 nu există în baza 8).


* **Hexazecimal (baza 16):** Încep cu `0x` sau `0X`. Conțin cifre `0-9` și litere `A-F`.
* Exemple: `0x15`, `0x6F`, `0xFF`.



#### 2. Literali reali

* **Forma fixă (standard):** `3.14`, `-1.5`.
* **Forma științifică (exponențială):** `-0.567E+2` reprezintă $-0.567 \times 10^2 = -56.7$.

#### 3. Literali caracter (`char`)

Un singur caracter delimitat de **apostroafe** (`' '`).

* Exemple: `'a'`, `'B'`, `'?'`.

**Secvențe ESCAPE:** Sunt caractere speciale reprezentate prin două simboluri, primul fiind backslash `\`. Deși conțin două caractere scrise, din punct de vedere sintactic reprezintă **un singur caracter**.

| Secvență Escape | Semnificație |
| --- | --- |
| `'\n'` | Linie nouă (Enter / Newline) |
| `'\t'` | Tab orizontal |
| `'\\'` | Caracterul Backslash (`\`) |
| `'\''` | Apostrof (`'`) |
| `'\"'` | Ghilimele (`"`) |
| `'\0'` | Caracterul nul (marchează sfârșitul unui șir de caractere) |

#### 4. Literali șir de caractere (`string`)

Secvențe de caractere delimitate de **ghilimele** (`" "`).

* Exemple: `"Informatica"`, `"n = "`, `"Rezultat: \n"`.

> **Diferență critică pentru Bacalaureat:**
> `'A'` $\neq$ `"A"`
> * `'A'` este un **caracter simplu** (tip `char`, ocupă 1 octet).
> * `"A"` este un **șir de caractere** (tablou de `char` terminat cu `'\0'`, ocupă 2 octeți).
> 
> 

---

## 4. Cuvinte Rezervate (Keywords) în C++

Cuvintele rezervate sunt cuvinte cheie care au un înțeles special pentru compilator și **nu pot fi folosite ca nume de variabile sau funcții**.

### Lista cuvintelor rezervate din C++:

`alignas` | `alignof` | `and` | `and_eq` | `asm` | `auto` | `bitand` | `bitor` | `bool` | `break` | `case` | `catch` | `char` | `char16_t` | `char32_t` | `class` | `compl` | `concept` | `const` | `constexpr` | `const_cast` | `continue` | `decltype` | `default` | `delete` | `do` | `double` | `dynamic_cast` | `else` | `enum` | `explicit` | `export` | `extern` | `false` | `float` | `for` | `friend` | `goto` | `if` | `inline` | `int` | `long` | `mutable` | `namespace` | `new` | `noexcept` | `not` | `not_eq` | `nullptr` | `operator` | `or` | `or_eq` | `private` | `protected` | `public` | `register` | `reinterpret_cast` | `requires` | `return` | `short` | `signed` | `sizeof` | `static` | `static_assert` | `static_cast` | `struct` | `switch` | `template` | `this` | `thread_local` | `throw` | `true` | `try` | `typedef` | `typeid` | `typename` | `union` | `unsigned` | `using` | `virtual` | `void` | `volatile` | `wchar_t` | `while` | `xor` | `xor_eq`
