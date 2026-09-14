# Fișă de Sinteză: Echivalența Structurilor de Control în C++

Acest document prezintă modul în care algoritmii pot fi exprimați prin diferite structuri de control (liniare, alternative și repetitive) și cum se realizează trecerea echivalentă de la o structură la alta.

---

## 1. Echivalența între Structurile Alternative

Orice decizie poate fi exprimată atât prin instrucțiunea `if`, cât și prin instrucțiunea `switch` (când se compară o expresie întreagă cu valori constante) sau prin operatorul ternar (`? :`).

### Exemplu: Clasificarea unei opțiuni

**A. Cu instrucțiunea `switch`:**

```cpp
switch (optiune) {
    case 1: cout << "Adaugare"; break;
    case 2: cout << "Stergere"; break;
    default: cout << "Invalida"; break;
}

```

**B. Echivalent cu `if ... else if ... else`:**

```cpp
if (optiune == 1) {
    cout << "Adaugare";
} else if (optiune == 2) {
    cout << "Stergere";
} else {
    cout << "Invalida";
}

```

**C. Echivalent cu Operatorul Ternar (`? :`):**

```cpp
(optiune == 1) ? cout << "Adaugare" : ((optiune == 2) ? cout << "Stergere" : cout << "Invalida");

```

---

## 2. Echivalența între Structurile Repetitive

Orice problemă rezolvată cu o structură repetitivă poate fi rescrisă folosind oricare dintre celelalte două structuri repetitive.

### Problemă Model: Calculul sumei $S = 1 + 2 + \dots + n$ (pentru $n \ge 1$)

| Instrucțiunea `for` | Instrucțiunea `while` | Instrucțiunea `do...while` |
| --- | --- | --- |
| **Test inițial (compact)** | **Test inițial** | **Test final** |
| `cpp<br>int S = 0;<br>for (int i = 1; i <= n; i++) {<br>    S += i;<br>}<br>` | `cpp<br>int S = 0;<br>int i = 1;<br>while (i <= n) {<br>    S += i;<br>    i++;<br>}<br>` | `cpp<br>int S = 0;<br>int i = 1;<br>do {<br>    S += i;<br>    i++;<br>} while (i <= n);<br>` |

---

## 3. Schema Generală de Transformare a Buclelor

### A. Transformarea `for` $\longleftrightarrow$ `while`

Sintaxa generală `for`:

```cpp
for (E1; E2; E3) {
    Instructiune;
}

```

Este **strict echivalentă** cu structura `while`:

```cpp
E1;
while (E2) {
    Instructiune;
    E3;
}

```

---

### B. Transformarea `while` $\longleftrightarrow$ `do...while`

Deoarece `while` poate să nu execute corpul buclei niciodată (dacă condiția este inițial falsă), iar `do...while` îl execută cel puțin o dată, conversia directă necesită o verificare inițială.

**Transformarea `while` în `do...while`:**

```cpp
// Forma initiala cu while
while (Conditie) {
    Instructiune;
}

```

**Forma echivalentă cu `do...while`:**

```cpp
if (Conditie) {
    do {
        Instructiune;
    } while (Conditie);
}

```

---

## 4. Simularea Structurilor Repetitive prin Structuri Liniare și `goto`

Deși folosirea etichetelor și a instrucțiunii `goto` este nerecomandată în programarea modernă, teoretic orice buclă poate fi construită doar cu salturi condiționate (structură liniară + `if` + `goto`).

### Exemplu: Buclă `while` simulată cu `if` și `goto`

**Cu `while`:**

```cpp
int i = 1;
while (i <= 5) {
    cout << i << " ";
    i++;
}

```

**Echivalent cu `if` și `goto`:**

```cpp
int i = 1;
ETICHETA_TEST:
if (i <= 5) {
    cout << i << " ";
    i++;
    goto ETICHETA_TEST; // Sare inapoi la verificare
}

```

---

## Tabel Recapitulativ de Modificare a Fluxului

| Structură | Condiție de Intrare | Garantat cel puțin 1 executare? | Controlul Pasului |
| --- | --- | --- | --- |
| **`if` / `switch**` | Evaluată o singură dată | Nu (doar dacă e `true`) | Nu se repetă |
| **`while`** | Testată la început | **Nu** | Manual în corp (`i++`) |
| **`do...while`** | Testată la final | **Da** | Manual în corp (`i++`) |
| **`for`** | Testată la început | **Nu** | Automat în antet (`E3`) |