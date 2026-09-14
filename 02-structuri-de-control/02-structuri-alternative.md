# Structuri Alternative (de Decizie) în C++

## Ce sunt Structurile Alternative?

**Structurile alternative** (sau *structurile de decizie*) execută anumite instrucțiuni doar dacă sunt îndeplinite specifice condiții. Ele permit ramificarea codului în funcție de valorile variabilelor la momentul executării.

---

## 1. Instrucțiunea `if`

Instrucțiunea `if` este cea mai utilizată structură alternativă.

### A. Sintaxă

* **Varianta completă (cu `else`):**
```cpp
if (Expresie)
    Instrucțiune1
else
    Instrucțiune2

```


* **Varianta scurtă (fără `else`):**
```cpp
if (Expresie)
    Instrucțiune1

```


### B. Mod de Execuție

1. Se evaluează `Expresie` (care este de tip `bool` sau se convertește la `bool`).
* **Nenul** $\rightarrow$ `true`
* **Nul (`0`)** $\rightarrow$ `false`


2. Dacă valoarea este `true`, se execută `Instrucțiune1`.
3. Dacă valoarea este `false`:
* În varianta completă se execută `Instrucțiune2`.
* În varianta scurtă se trece direct la instrucțiunea de după `if`.


### C. Reguli de Conversie și Scriere Scurtă

Pentru că orice valoare diferită de $0$ este interpretată ca `true`, se pot folosi forme scurtate:

| Forma Extinsă | Forma Scurtată | Semnificație |
| --- | --- | --- |
| `if (n != 0)` | `if (n)` | Se execută dacă $n$ este nenul. |
| `if (n == 0)` | `if (!n)` | Se execută dacă $n$ este egal cu zero. |

### D. Erori Frecvente

* **Punctul și virgula după condiție:**
```cpp
if (x > 0); // Greșit! Expresia execută o instrucțiune vidă.
    cout << "Pozitiv"; // Se execută mereu!

```

* **Limbajul fără bloc de cod pentru instrucțiuni multiple:**
Dacă sub `if` sau `else` trebuie executate mai multe instrucțiuni, **trebuie** utilizată o instrucțiune compusă (între acolade `{}`).
* **Confuzia între egalitate (`==`) și atribuire (`=`):**
`if (x = 5)` va atribui valoarea $5$ variabilei `x` și va evalua expresia la `true` (deoarece $5 \neq 0$). Forma corectă este `if (x == 5)`.

### E. Exemple Utile

#### Exemplul 1: Paritate

```cpp
int x;
cin >> x;

if (x % 2 == 0)
    cout << x << " este par";
else
    cout << x << " este impar";

```

#### Exemplul 2: `if`-uri Imbricate (Împărțire la Zero)

```cpp
int n, m;
cin >> n >> m;

if (m == 0)
    cout << "Impartirea la zero nu este permisa!";
else if (n % m == 0)
    cout << m << " divide pe " << n;
else
    cout << m << " nu divide pe " << n;

```

---

## 2. Instrucțiunea `switch`

Instrucțiunea `switch` permite selectarea uneia dintre mai multe ramuri pe baza egalității unei expresii cu o serie de **constante întregi**.

### A. Sintaxă

```cpp
switch (Expresie)
{
    case Constanta_1:
        Grup_Instructiuni_1
        break;
    case Constanta_2:
        Grup_Instructiuni_2
        break;
    ...
    case Constanta_N:
        Grup_Instructiuni_N
        break;
    default:
        Grup_Instructiuni_default
        break;
}

```

### B. Mod de Execuție

1. Se evaluează `Expresie` (care trebuie să returneze un tip întreg: `int`, `char`, `bool` etc.).
2. Valoarea obținută se compară pe rând cu fiecare `Constanta_X`.
3. Când se găsește o potrivire, se execută instrucțiunile asociate acelui `case`.
4. Execuția continuă până la prima instrucțiune `break;` sau până la finalul blocului `switch`.
5. Dacă nicio constantă nu se potrivește, se execută blocul `default` (dacă există).

### C. Importanța Instrucțiunii `break;`

Fără `break;`, programul intră în efectul de **fall-through** (execuția "cade" prin următoarele cazuri fără a mai verifica condițiile):

```cpp
int n = 1;
switch (n) {
    case 1:
        cout << "Unu\n";
    case 2:
        cout << "Doi\n";
        break;
    case 3:
        cout << "Trei\n";
        break;
}
// Rezultat afișat:
// Unu
// Doi

```

### D. Exemplu Relevat

Afișarea zilei din săptămână și gruparea cazurilor (cum sunt zilele de weekend):

```cpp
#include <iostream>
using namespace std;

int main() {
    int zi;
    cin >> zi;

    switch (zi) {
        case 1: cout << "Luni\n"; break;
        case 2: cout << "Marti\n"; break;
        case 3: cout << "Miercuri\n"; break;
        case 4: cout << "Joi\n"; break;
        case 5: cout << "Vineri\n"; break;
        case 6:
        case 7:
            cout << "WEEKEND!\n"; break; // Executat atât pentru 6, cât și pentru 7
        default:
            cout << "Zi invalida!\n"; break;
    }

    return 0;
}

```

---

## Comparație: `if` vs `switch`

| Criteriu | `if` | `switch` |
| --- | --- | --- |
| **Condiții evaluate** | Verifică expresii complexe, intervale (`x > 5 && x < 10`) și tipuri reale (`float`, `double`). | Verifică **exclusiv egalitatea** cu valori constante întregi (`int`, `char`). |
| **Flexibilitate** | Mare (suportă orice combinație de operatori logici). | Limitată la potriviri fixe de valori. |
| **Lizibilitate** | Poate deveni greu de citit dacă sunt multe ramuri imbricate. | Clară și organizată pentru selecții din categorii de opțiuni fixe. |