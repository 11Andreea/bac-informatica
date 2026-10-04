## 1. Conceptul și Principiul de Funcționare

**Divide et Impera** este o tehnică de elaborare a algoritmilor care se aplică problemelor ce pot fi descompuse în subprobleme de același tip, dar de dimensiuni mai mici.

Metoda funcționează recursiv în **3 pași principali**:

1. **Divide (Împarte):** Problema inițială de dimensiune $n$ este descompusă în două sau mai multe subprobleme de dimensiuni mai mici, de același tip.
2. **Impera (Stăpânește):** Se rezolvă subproblemele. Dacă dimensiunea subproblemelor este suficient de mică (caz elementar / caz de oprire), rezolvarea se face direct. În caz contrar, se aplică din nou recursiv metoda Divide et Impera.
3. **Combine (Combină):** Se combină soluțiile subproblemelor pentru a obține soluția problemei inițiale.

---

## 2. Structura Generală C++ (Șablon)

```cpp
int divide(int st, int dr) {
    // 1. Caz bază / elementar (oprirea recursivității)
    if (st == dr) {
        return v[st]; // sau altă valoare de bază
    }
    
    // 2. Divide
    int mij = (st + dr) / 2;
    
    // 3. Impera (apeluri recursive)
    int sol_st = divide(st, mij);
    int sol_dr = divide(mij + 1, dr);
    
    // 4. Combine (combinarea rezultatelor)
    return combina(sol_st, sol_dr);
}
```

---

## 3. Algoritmi Clasici

### A. Căutarea Binară (Binary Search)

* **Premisă:** Vectorul / tabloul trebuie să fie **sortat** (crescător/descrescător).
* **Complexitate:** $O(\log n)$

```cpp
// Returnează poziția pe care se află valoarea x, sau -1 dacă nu există
int cautareBinara(int v[], int st, int dr, int x) {
    if (st > dr) {
        return -1; // Cazul în care elementul nu există
    }
    
    int mij = (st + dr) / 2;
    
    if (v[mij] == x) {
        return mij; // Elementul a fost găsit
    }
    if (v[mij] > x) {
        return cautareBinara(v, st, mij - 1, x); // Căutăm în jumătatea stângă
    }
    return cautareBinara(v, mij + 1, dr, x);     // Căutăm în jumătatea dreaptă
}
```

---

### B. Suma / Maximul / Minimul Elementelor unui Vector

#### 1. Suma elementelor
```cpp
int suma(int v[], int st, int dr) {
    if (st == dr) {
        return v[st];
    }
    int mij = (st + dr) / 2;
    return suma(v, st, mij) + suma(v, mij + 1, dr);
}
```

#### 2. Determinarea maximului
```cpp
int maxim(int v[], int st, int dr) {
    if (st == dr) {
        return v[st];
    }
    int mij = (st + dr) / 2;
    int max1 = maxim(v, st, mij);
    int max2 = maxim(v, mij + 1, dr);
    
    if (max1 > max2) {
        return max1;
    }
    return max2;
}
```

---

### C. Algoritmi de Sortare

#### 1. Merge Sort (Sortare prin Interclasare)
* **Principiu:** Împarte vectorul în două jumătăți, le sortează recursiv, apoi interclasează cele două jumătăți sortate.
* **Complexitate:** $O(n \log n)$

```cpp
void interclasare(int v[], int st, int mij, int dr) {
    int i = st, j = mij + 1, k = 0;
    int temp[1001];

    while (i <= mij && j <= dr) {
        if (v[i] <= v[j]) {
            temp[k++] = v[i++];
        } else {
            temp[k++] = v[j++];
        }
    }
    while (i <= mij) temp[k++] = v[i++];
    while (j <= dr)  temp[k++] = v[j++];

    for (i = 0; i < k; i++) {
        v[st + i] = temp[i];
    }
}

void mergeSort(int v[], int st, int dr) {
    if (st < dr) {
        int mij = (st + dr) / 2;
        mergeSort(v, st, mij);
        mergeSort(v, mij + 1, dr);
        interclasare(v, st, mij, dr);
    }
}
```

#### 2. Quick Sort (Sortare Rapidă)
* **Principiu:** Alege un element numit *pivot*, repoziționează elementele astfel încât cele mai mici decât pivotul să fie la stânga, iar cele mai mari la dreapta, apoi sortează recursiv subvectorii.
* **Complexitate:** Medie $O(n \log n)$, Defavorabilă $O(n^2)$

```cpp
int pozitionare(int v[], int st, int dr) {
    int pivot = v[dr];
    int i = st - 1;

    for (int j = st; j < dr; j++) {
        if (v[j] <= pivot) {
            i++;
            int aux = v[i]; v[i] = v[j]; v[j] = aux;
        }
    }
    int aux = v[i + 1]; v[i + 1] = v[dr]; v[dr] = aux;
    return i + 1;
}

void quickSort(int v[], int st, int dr) {
    if (st < dr) {
        int p = pozitionare(v, st, dr);
        quickSort(v, st, p - 1);
        quickSort(v, p + 1, dr);
    }
}
```

---

## 4. Tipuri Frecvente de Subiecte la Bacalaureat

1. **Verificarea unei proprietăți (Ex: Toate elementele sunt pare / există cel puțin un element prim):**
   * Se returnează `1` (Adevărat) sau `0` (Fals) combinând rezultatele cu operatori logici (`&&` sau `||`).

   ```cpp
   // Verifică dacă toate elementele sunt pare
   int toatePare(int v[], int st, int dr) {
       if (st == dr) {
           return v[st] % 2 == 0;
       }
       int mij = (st + dr) / 2;
       return toatePare(v, st, mij) && toatePare(v, mij + 1, dr);
   }
   ```

2. **Căutare / Numărare cu condiții speciale:**
   * Numărarea elementelor care respectă o proprietate (se adună $1$ sau $0$ la cazul de bază sau se însumează rezultatele apelurilor recursive).

---

## 5. Sfaturi și Capcane Frecvente la Examen

* **Calculul mijlocului:** Se scrie `int mij = (st + dr) / 2;`.
* **Cazul de oprire:** Nu uita să tratezi corect cazul `st == dr` (vector cu un singur element) sau `st > dr` (vector vid).
* **Recursivitate infinită:** Asigură-te că domeniul se restrânge la fiecare apel: `[st, mij]` și `[mij + 1, dr]`.