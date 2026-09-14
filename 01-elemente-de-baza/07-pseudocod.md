# Ghidul Limbajului Pseudocod (Format Examen Bacalaureat)

Limbajul **pseudocod** este un instrument informal utilizat pentru proiectarea și descrierea algoritmilor într-o formă citibilă pentru oameni, fără restricțiile rigide de sintaxă ale unui limbaj de programare compilabil.

---

## 1. Concepte de Bază: Variabile, Constante și Operații

### A. Variabile și Constante

* **Fără declarare:** Variabilele nu necesită specificarea tipului în prealabil (`int`, `float` etc.). Ele își iau tipul din valoarea stocată.
* **Nume valide:** Doar litere, cifre și caracterul `_` (fără a începe cu o cifră).
* **Constante:** Numere întregi/reale (`10`, `3.14`), caractere delimitat de apostroafe (`'a'`) sau șiruri delimitat de ghilimele (`"bac"`).

### B. Operatorii Aritmetici, Relaționali și Logici

| Categorie | Operator Pseudocod | Descriere / Echivalent C++ | Exemple / Observații |
| --- | --- | --- | --- |
| **Aritmetici** | `+`, `-`, `*` | Adunare, scădere, înmulțire | `a + b`, `x * 2` |
|  | `/` | Împărțire reală | `7 / 2 = 3.5` |
|  | `[a / b]` | Câtul împărțirii întregi | `[7 / 2] = 3` (echivalent `a / b` în C++ pe `int`) |
|  | `%` | Restul împărțirii (Modulo) | `7 % 2 = 1` |
| **Relaționali** | `=`, `≠` | Egalitate, neegalitate | C++: `==`, `!=` |
|  | `<`, `≤`, `>`, `≥` | Comparații | C++: `<`, `<=`, `>`, `>=` |
| **Logici** | `NOT`, `ȘI`, `SAU` | Negare, Conjuncție, Disjuncție | C++: `!`, `&&`, ` |

---

## 2. Instrucțiuni de Bază (Citire, Afișare, Atribuire)

### Citirea

Preia valori de la tastatură și le stochează în una sau mai multe variabile.

* **Sintaxă:** `citeste <lista_variabile>`
* **Exemplu:** `citeste a, b, c`

### Afișarea

Evaluază și afișează mesaje, valori sau rezultate pe ecran.

* **Sintaxă:** `scrie <lista_expresii>`
* **Exemplu:** `scrie 'Suma este: ', a + b`

### Atribuirea

Evaluează expresia din dreapta și o stochează în variabila din stânga.

* **Sintaxă:** `<variabila> ← <expresie>`
* **Exemplu:** `S ← a + b` sau `i ← i + 1`

---

## 3. Structura Alternativă (`daca`)

Permite ramificarea fluxului algoritmului pe baza unei condiții logice.

```text
┌ daca <conditie> atunci
│    <instructiuni1>
│ altfel
│    <instructiuni2>
└■

```

* **Varianta fără `altfel`:**

```text
┌ daca <conditie> atunci
│    <instructiuni1>
└■

```

---

## 4. Structuri Repetitive

### A. Cu număr cunoscut de pași: `pentru`

Specifică în mod direct numărul de iterații prin intermediul unui contor.

```text
┌ pentru <var> ← <exp_init>, <exp_fin> [, pas] executa
│    <instructiuni>
└■

```

* Dacă pasul lipseste, se consideră că este `1`.
* Dacă pasul este `-1`, contorul decrementează de la `exp_init` la `exp_fin`.

---

### B. Cu număr necunoscut de pași și test inițial: `cat timp`

Execută instrucțiunile **atât timp cât condiția este adevărată**. Dacă condiția este falsă de la început, corpul nu se execută niciodată.

```text
┌ cat timp <conditie> executa
│    <instructiuni>
└■

```

---

### C. Cu număr necunoscut de pași și test final

| Structură | Sintaxă | Condiție de continuare | Execuții minime |
| --- | --- | --- | --- |
| **`executa ... cat timp`** | `┌ executa`<br>

<br>`│    <instructiuni>`<br>

<br>`└ cat timp <conditie>` | Se repetă cât timp condiția este **ADEVĂRATĂ**. | **1** |
| **`repeta ... pana cand`** | `┌ repeta`<br>

<br>`│    <instructiuni>`<br>

<br>`└ pana cand <conditie>` | Se repetă cât timp condiția este **FALSĂ** (se oprește când devine adevărată). | **1** |

---

## 5. Ghid de Echivalență între Structurile Repetitive

La examenul de Bacalaureat, cerința de transformare a unei bucle în alt tip de buclă echivalentă este foarte frecventă.

### A. Evaluarea `cattimp` în `executa...cattimp` sau `repeta...panacand`

Deoarece `cattimp` efectuează testul la început, conversia într-o buclă cu test final necesită **o verificare prealabilă cu `daca**` pentru a preveni executarea accidentală când condiția inițială este falsă.

```text
// Original:
┌ cattimp <conditie> executa
│     <instructiuni>
└■

// Echivalent cu 'executa ... cattimp':
┌ daca <conditie> atunci
│┌ executa
││     <instructiuni>
│└ cattimp <conditie>
└■

// Echivalent cu 'repeta ... panacand':
┌ daca <conditie> atunci
│┌ repeta
││     <instructiuni>
│└ panacand NOT (<conditie>)
└■

```

---

### B. Conversionarea `repeta...panacand` în `cattimp`

Se execută primul pas în mod direct (necondiționat), iar restul iterațiilor sunt introduse în bucla `cattimp` cu condiția negată:

```text
// Original:
┌ repeta
│     <instructiuni>
└ panacand <conditie>

// Echivalent cu 'cattimp':
<instructiuni>
┌ cattimp NOT (<conditie>) executa
│     <instructiuni>
└■

```

---

## 6. Traducere Pseudocod $\rightarrow$ C++

| Pseudocod | C++ |
| --- | --- |
| `citeste a, b` | `cin >> a >> b;` |
| `scrie a, ' ', b` | `cout << a << " " << b;` |
| `a ← b + 1` | `a = b + 1;` |
| `[a / b]` | `a / b` *(dacă a și b sunt de tip `int`)* |
| `a % b` | `a % b;` |
| `daca c atunci ... altfel ...` | `if (c) { ... } else { ... }` |
| `pentru i ← a, b executa` | `for (int i = a; i <= b; i++)` |
| `cat timp c executa` | `while (c)` |
| `executa ... cat timp c` | `do { ... } while (c);` |
| `repeta ... pana cand c` | `do { ... } while (!c);` |