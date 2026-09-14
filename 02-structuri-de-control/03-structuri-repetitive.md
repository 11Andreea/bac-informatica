# Structuri Repetitive în C++

**Structurile repetitive** (sau *bucle / cicluri*) execută un bloc de instrucțiuni de mai multe ori.

---

## Tipuri de Structuri Repetitive

* **Cu număr cunoșcut de pași:** Se știe exact de câte ori se va executa instrucțiunea (implementată prin `for`).
* **Cu număr necunoscut de pași:** Execuția depinde de o condiție logică:
* **Test inițial (`while`):** Verifică condiția **înainte** de a executa corpul buclei. (Execuții posibile: $0, 1, 2, \dots$)
* **Test final (`do...while`):** Execută corpul buclei, apoi verifică condiția. (Execuții posibile: $1, 2, 3, \dots$)

---

## 1. Instrucțiunea `while` (Test Inițial)

Apreciată când **nu se știe numărul exact de iterații**, iar bucla ar putea să nu se execute niciodată dacă condiția este `false` de la început.

### Sintaxă & Mod de Execuție

```cpp
while (Expresie)
    Instrucțiune;

```

1. Se evaluează `Expresie`.
2. Dacă rezultatul este `true`, se execută `Instrucțiune`, apoi se revine la pasul 1.
3. Dacă este `false`, se trece la prima instrucțiune de după buclă.

### Exemplu: Suma numerelor de la $1$ la $n$

```cpp
int n, S = 0, i = 1;
cin >> n;

while (i <= n) {
    S += i;
    i++; // Modificarea variabilei de control este obligatorie!
}
cout << S;

```

---

## 2. Instrucțiunea `do...while` (Test Final)

Garantează că corpul buclei se va executa **cel puțin o dată**, indiferent dacă condiția este inițial adevărată sau falsă.

### Sintaxă & Mod de Execuție

```cpp
do {
    Instrucțiune;
} while (Expresie); // Atenție la caracterul ';' de la final!

```

1. Se execută `Instrucțiune`.
2. Se evaluează `Expresie`.
3. Dacă este `true`, se reluă execuția de la pasul 1.
4. Dacă este `false`, bucla se oprește.

### Exemplu: Suma numerelor (varianta `do...while`)

```cpp
int n, S = 0, i = 1;
cin >> n;

do {
    S += i;
    i++;
} while (i <= n);

cout << S;

```

---

## 3. Instrucțiunea `for`

Utilizată frecvent când **numărul de iterații este cunoscut**. Sintaxa compactă regrupează inițializarea, testarea și incrementarea într-un singur loc.

### Sintaxă

```cpp
for (Expresie_Initializare; Expresie_Testare; Expresie_Continuare)
    Instrucțiune;

```

### Echivalență directă cu `while`:

```cpp
Expresie_Initializare;
while (Expresie_Testare) {
    Instrucțiune;
    Expresie_Continuare;
}

```

### Observații cheie:

* Cele 3 expresii sunt separate prin `;`.
* Oricare dintre ele poate lipsi. Dacă `Expresie_Testare` lipsește, se consideră implicit `true` $\rightarrow$ `for(;;)` creează o **buclă infinită**.
* Variabila declarată în `Expresie_Initializare` este vizibilă doar în interiorul buclei `for`.

### Exemplu: Suma numerelor (varianta `for`)

```cpp
int n, S = 0;
cin >> n;

for (int i = 1; i <= n; i++) {
    S += i;
}
cout << S;

```

---

## 4. Controlul Buclei: `break` și `continue`

| Instrucțiune | Sintaxă | Efect în Buclă |
| --- | --- | --- |
| **`break`** | `break;` | **Oprește imediat** execuția buclei și sare direct după ea. |
| **`continue`** | `continue;` | **Sare peste restul instrucțiunilor** din pasul curent și trece direct la următoarea iterație. |

### Exemplu `break`: Oprire când se atinge $i = 5$

```cpp
int S = 0;
for (int i = 1; i <= 10; i++) {
    S += i;
    if (i == 5) break; // Când i devine 5, iese din for (S va fi 15)
}

```

### Exemplu `continue`: Adunarea numerelor impare

```cpp
int S = 0;
for (int i = 1; i <= 10; i++) {
    if (i % 2 == 0) continue; // Dacă numărul este par, sare peste 'S += i'
    S += i; // Se adună doar numerele impare
}

```

---

## Tabel Comparativ

| Structură | Testare | Nr. Min. Execuții | Utilizare Principală |
| --- | --- | --- | --- |
| **`while`** | Inițială | $0$ | Prelucrări unde condiția poate fi falsă de la început (ex. prelucrare cifre). |
| **`do...while`** | Finală | $1$ | Validări de date de intrare (ex. citire număr până când este pozitiv). |
| **`for`** | Inițială | $0$ | Parcurgeri de vectori, matrice, numărători fixe ($1 \dots n$). |