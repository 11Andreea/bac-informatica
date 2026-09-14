# Structura Liniară în C++

## Ce este Structura Liniară?

**Structura liniară** (numită și *structură secvențială*) este cel mai simplu mod de organizare a unui algoritm. În cadrul acestei structuri, instrucțiunile se execută **în ordine, una după alta**, de la sus în jos, exact în secvența în care au fost scrise.

O caracteristică fundamentală este faptul că instrucțiunile se execută **la fel la fiecare rulare a programului**, indiferent de valorile datelor de intrare (fără ramificări, decizii sau repetări).

---

## 1. Instrucțiunea Expresie

În C++, o expresie devine instrucțiune atunci când este urmată de caracterul punct și virgulă (`;`).

### Sintaxă:

$$\text{Expresie};$$

### Mod de funcționare:

Se evaluează expresia, iar valoarea obținută este de obicei salvată într-o variabilă (prin atribuire) sau transmisă către un flux de ieșire.

### Exemple:

```cpp
x = 2;       // Instrucțiune de atribuire (expresia x = 2 urmată de ;)
x++;         // Instrucțiune de incrementare (expresia x++ urmată de ;)
cout << x;   // Instrucțiune de afișare

```

> **Notă privind citirea și afișarea:**
> În C++, operațiile I/O cu stream-uri (`cin >> ...`, `cout << ...`) sunt din punct de vedere sintactic tot **expresii**.
> * În secvența `cout << x;`, `cout` și `x` sunt operanzii, iar `<<` este operatorul de inserție.
> * Rezultatul acestei operații este o referință către stream-ul `cout`, permițând înlănțuirea: `cout << x << " " << y;`.

---

## 2. Instrucțiunea Declarativă

Instrucțiunea declarativă este folosită pentru a introduce noi identificatori (variabile, constante, structuri sau funcții) și pentru a le specifica tipul de date.

### Sintaxă:

$$\text{Tip\_de\_date} \ \ \text{Lista\_identificatori};$$

* **`Tip_de_date`**: Poate fi un tip primitiv (`int`, `float`, `double`, `char`, `bool`) sau un tip definit de utilizator (`struct`).
* **`Lista_identificatori`**: Conține unul sau mai mulți identificatori separați prin virgulă. Opțional, variabilele pot fi inițializate chiar la declarare.

### Exemple:

```cpp
int x, y, z;          // Declararea a 3 variabile de tip întreg
double a = 3.14;      // Declarare cu inițializare
char c1 = 'A', c2;    // Declararea a două caractere, unul fiind inițializat

```

---

## 3. Instrucțiunea Compusă (Blocul de Cod)

Instrucțiunea compusă (sau blocul) reprezintă o grupare de mai multe declarații și instrucțiuni delimitate de acolade `{}`.

### Sintaxă:

```cpp
{
    // Declarații și instrucțiuni
}

```

### Scop și reguli principale:

1. **Echivalență sintactică:** Permite tratarea unui grup de instrucțiuni ca și cum ar fi o **singură instrucțiune** (foarte util la structurile alternative `if` sau repetitive `while`, `for`).
2. **Fără punct și virgulă:** După acolada de închidere `}` **nu** se pune punct și virgulă `;` (cu excepția declarării de structuri/clase).
3. **Domeniu de vizibilitate (Scope):** Variabilele declarate în interiorul unui bloc sunt **locale** acelui bloc și sunt distruse automat din memorie la ieșirea din bloc.

### Exemplu de vizibilitate (Domeniu de definire):

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 5; // Variabila x din blocul principal (main)
    
    {
        int x = 7; // O nouă variabilă x, locală blocului interior (maschează x-ul exterior)
        cout << x << endl; // Va afișa: 7
    } // Aici x cu valoarea 7 este distrus din memorie
    
    cout << x << endl; // Va afișa: 5 (variabila x din main)
    return 0;
}

```

---

## 4. Instrucțiunea `return`

Instrucțiunea `return` oprește imediat execuția funcției curente și transferă controlul înapoi către funcția apelantă (de exemplu, către sistemul de operare dacă este apelată în `main`).

### Sintaxă:

* `return;` — folosită în funcții care nu returnează nicio valoare (funcții de tip `void`).
* `return expresie;` — folosită în funcții care calculează și returnează o valoare de tipul specificat la antetul funcției.

### Exemplu:

```cpp
int main() {
    int a = 10, b = 20;
    cout << a + b;
    
    return 0; // Oprește executarea funcției main și returnează codul 0 (execuție cu succes)
    
    cout << "Acest text nu se va afisa niciodata!"; // Instrucțiune inaccesibilă
}

```

---

## 5. Instrucțiunea Vidă

Instrucțiunea vidă constă doar dintr-un singur caracter punct și virgulă (`;`). La întâlnirea ei, calculatorul nu execută nicio acțiune.

### Sintaxă:

`;`

### Utilizare:

Se folosește atunci când sintaxa C++ cere prezența unei instrucțiuni într-un anumit punct al codului, însă logica algoritmului nu necesită nicio procesare.

### Exemple și Capcane:

* **Eroare frecventă (Punct și virgulă greșit la `if` sau bucle):**

```cpp
int x = 5;
if (x > 10); // Punctul și virgula reprezintă o instrucțiune vidă executată pe ramura true!
{
    cout << "x este mai mare decat 10"; // Se va afișa MEREU, fiind un bloc separat!
}

```

* **Exemplu legitim (buclă cu corp vid):**

```cpp
// Parcurgerea unui șir până la primul caracter spațiu
while (s[i] != ' ' && s[i] != '\0')
    i++; // Sau direct: while (s[i++] != ' '); (unde corpul buclei este instrucțiunea vidă)

```

---

## Rezumatul Structurii Liniare

| Tip Instrucțiune | Sintaxă | Exemplu | Semnificație |
| --- | --- | --- | --- |
| **Expresie** | `Expresie;` | `a = b + 5;` | Evaluează o expresie / atribuire |
| **Declarativă** | `Tip Nume;` | `int n, m;` | Rezervă spațiu în memorie |
| **Compusă** | `{ ... }` | `{ int x=1; cout<<x; }` | Grupează instrucțiuni într-un bloc |
| **Return** | `return v;` | `return 0;` | Întrerupe funcția și trimite valoarea |
| **Vidă** | `;` | `;` | Nu execută nicio operație |