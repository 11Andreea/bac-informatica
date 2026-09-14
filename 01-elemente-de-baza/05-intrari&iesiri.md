# Citirea, Afișarea și Lucrul cu Fișiere în C++

## 1. Citirea și Afișarea de la Tastatură / Ecran

În C++, comunicarea cu utilizatorul se face prin intermediul fluxurilor de date (**streams**). Acestea sunt gestionate prin biblioteca `<iostream>`.

* **`cin`** (*console input*): Citește date introduse de la tastatură (operatorul de extracție `>>`).
* **`cout`** (*console output*): Afișează date pe ecran (operatorul de inserție `<<`).

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b;
    
    // Afisare mesaj
    cout << "Introdu doua numere: ";
    
    // Citire valori de la tastatura (separate prin spatiu sau Enter)
    cin >> a >> b;
    
    // Afisare rezultat si trecere pe linie noua (endl sau '\n')
    cout << "Suma este: " << a + b << endl;
    
    return 0;
}

```

> **Atenție la delimitatori:**
> * `"A"` este un **șir de caractere** (delimitate prin ghilimele).
> * `'A'` este un **singur caracter** (delimitat prin apostroafe).


---

## 2. Lucrul cu Fișiere Text

Când numărul datelor de intrare sau ieșire este mare, folosim **fișiere text**.
Pentru aceasta, includem biblioteca **`<fstream>`**.

### Etapele lucrului cu fișiere

| Etapă | Tip flux / Funcție | Explicație |
| --- | --- | --- |
| **1. Declarare & Deschidere** | `ifstream fin("fisier.in");`<br>

<br>`ofstream fout("fisier.out");` | Creează legătura între program și fișier. |
| **2. Citire / Scriere** | `fin >> x;`<br>

<br>`fout << x;` | Se folosesc exact ca `cin` și `cout`. |
| **3. Închidere** | `fin.close();`<br>

<br>`fout.close();` | Eliberează resursele și salvează datele. |

---

### Exemplu complet

```cpp
#include <fstream> // Biblioteca pentru fisiere

using namespace std;

// Declararea fluxurilor ca variabile globale (se deschid automat)
ifstream fin("sum.in");   // Fișier din care citim
ofstream fout("sum.out"); // Fișier în care scriem

int main() {
    int a, b, s;
    
    // Citim din fisier
    fin >> a >> b;
    fin.close(); // Inchidem fisierul de citire
    
    s = a + b;
    
    // Scriem in fisier
    fout << s;
    fout.close(); // Inchidem fisierul de scriere
    
    return 0;
}

```

> **Reguli importante la fișiere:**
> * **Fișierul de intrare (`.in`) MUST exist!** Dacă fișierul nu există pe disc, citirea eșuează iar variabilele vor rămâne neinițializate (comportament impredictibil).
> * **Fișierul de ieșire (`.out`) se creează automat** dacă nu există. Dacă există deja, conținutul vechi va fi șters (suprascris).
> 
> 

---

# EXTRA

## 3. Formatarea Afișării și Citirii (Manipulatori)

Pentru a personaliza modul în care se afișează sau se citesc datele (ex: numărul de zecimale, alinierea pe coloane, baze de numerație), folosim **manipulatori**.

O parte se găsesc în `<iostream>`, iar cei cu parametri se află în biblioteca **`<iomanip>`**.

### A. Formatarea Lungimii și Alinierea (`<iomanip>`)

| Manipulator | Rol | Exemplu |
| --- | --- | --- |
| `setw(int n)` | Setează afișarea pe un spațiu de minim `n` caractere | `cout << setw(10) << 2019;` |
| `left` | Aliniază textul la stânga în zona `setw` | `cout << left << setw(10) << 2019;` |
| `right` | Aliniază textul la dreapta *(implicit)* | `cout << right << setw(10) << 2019;` |
| `internal` | Semnul la stânga, cifra la dreapta | `cout << internal << setw(10) << -2019;` |
| `setfill(char c)` | Umple spațiile goale dintr-un `setw` cu caracterul `c` | `cout << setfill('#') << setw(5) << 7; // ####7` |

---

### B. Formatarea Numărului de Zecimale (Numere Reale)

Pentru afișarea numerelor `float` sau `double` se folosesc combinații între `fixed`, `scientific` și `setprecision(n)`.

```cpp
#include <iostream>
#include <iomanip> // Necesar pentru setprecision
using namespace std;

int main() {
    double pi = 3.14159265;

    // 1. Format implicit: afișează un număr total de 6 cifre semnificative
    cout << pi << "\n"; // 3.14159

    // 2. Format FIX (fixed): setprecision(n) fixează exact N ZECIMALE după punct
    cout << fixed << setprecision(2) << pi << "\n"; // 3.14
    cout << fixed << setprecision(4) << pi << "\n"; // 3.1416 (cu rotunjire)

    // 3. Format ȘTIINȚIFIC (exponențial)
    cout << scientific << setprecision(2) << pi << "\n"; // 3.14e+00

    return 0;
}

```

---

### C. Baze de Numerație și Afișare Booleană

| Manipulator | Descriere | Exemplu Output |
| --- | --- | --- |
| `dec` | Baza 10 *(implicit)* | `2019` |
| `oct` | Baza 8 | `3743` |
| `hex` | Baza 16 (hexazecimal) | `7e3` |
| `showbase` / `noshowbase` | Afișează prefixul bazei (`0` pt octal, `0x` pt hex) | `0x7e3` |
| `uppercase` | Scrie literele din hexazecimal cu litere mari | `0X7E3` |
| `boolalpha` | Afișează `true`/`false` în loc de `1`/`0` | `true` |

```cpp
int n = 255;
cout << hex << showbase << uppercase << n; // Afișează 0xFF

bool ok = true;
cout << boolalpha << ok; // Afișează true

```

---

### D. Ignorarea sau Păstrarea Spațiilor la Citire

* **`skipws`** *(implicit)*: `cin` sare automat peste spații, Tab-uri și Enter-uri înainte să citească o valoare.
* **`noskipws`**: Forțează `cin` să citească exact caracterul următor, chiar dacă acesta este spațiu sau `\n`.

```cpp
char a, b;
cin >> noskipws >> a >> b; 
// Dacă introduci "A B", a va fi 'A', iar b va fi spațiul ' '!

```