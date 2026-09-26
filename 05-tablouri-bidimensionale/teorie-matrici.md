# Tablouri bidimensionale

Tablourile bidimensionale (matricele) sunt structuri de date care organizează elementele pe **linii și coloane**.

Un tablou bidimensional poate fi privit ca un tabel:

```text
        coloane
       0   1   2   3
     ┌───┬───┬───┬───┐
  0  │ 2 │ 5 │ 7 │ 1 │
     ├───┼───┼───┼───┤
  1  │ 4 │ 3 │ 8 │ 6 │
     ├───┼───┼───┼───┤
  2  │ 9 │ 0 │ 2 │ 5 │
     └───┴───┴───┴───┘
        ↑
      linii
````

În C++, fiecare element este identificat prin două indici:

```cpp
a[i][j]
```

unde:

* `i` = indicele liniei;
* `j` = indicele coloanei.

---

## 1. Declararea unui tablou bidimensional

Sintaxa generală:

```cpp
tip nume[NUMAR_LINII][NUMAR_COLOANE];
```

Exemplu:

```cpp
int a[100][100];
```

Matricea poate avea maximum 100 de linii și 100 de coloane.

Putem declara și tablouri cu dimensiuni diferite:

```cpp
int a[50][100];
```

Aceasta are:

* 50 de linii;
* 100 de coloane.

---

## 2. Indicii

În C++, indicii încep de la `0`.

Pentru:

```cpp
int a[3][4];
```

elementele sunt:

```text
a[0][0] a[0][1] a[0][2] a[0][3]
a[1][0] a[1][1] a[1][2] a[1][3]
a[2][0] a[2][1] a[2][2] a[2][3]
```

Dacă folosim `n` linii și `m` coloane:

```text
i ∈ [0, n-1]
j ∈ [0, m-1]
```

La BAC este foarte frecvent să se folosească indici de la `1`, pentru a corespunde mai ușor enunțului:

```cpp
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        cin >> a[i][j];
```

În acest caz trebuie să declarăm suficient spațiu:

```cpp
int a[101][101];
```

pentru maximum 100 de linii și 100 de coloane.

---

# 3. Citirea unei matrice

Pentru o matrice cu `n` linii și `m` coloane:

```cpp
for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        cin >> a[i][j];
```

Ordinea obișnuită este:

1. alegem linia;
2. parcurgem toate coloanele acelei linii;
3. trecem la următoarea linie.

Exemplu:

```cpp
int n, m;
cin >> n >> m;

for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        cin >> a[i][j];
```

---

# 4. Afișarea unei matrice

```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
        cout << a[i][j] << ' ';
    cout << '\n';
}
```

Rezultatul este afișat sub formă de tabel.

---

# 5. Parcurgerea unei matrice

Schema fundamentală:

```cpp
for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
        // prelucrarea lui a[i][j]
    }
```

Aceasta este una dintre cele mai importante scheme pentru problemele cu matrice.

## Ordinea parcurgerii

Elementele sunt vizitate astfel:

```text
a[0][0] → a[0][1] → a[0][2] → ...
    ↓
a[1][0] → a[1][1] → a[1][2] → ...
    ↓
a[2][0] → a[2][1] → a[2][2] → ...
```

---

# 6. Numărul total de elemente

O matrice cu `n` linii și `m` coloane are:

```text
n * m
```

elemente.

Exemplu:

```text
5 linii × 7 coloane = 35 elemente
```

---

# 7. Suma tuturor elementelor

```cpp
int s = 0;

for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        s += a[i][j];
```

---

# 8. Numărul elementelor care respectă o condiție

Exemplu: numărul elementelor pare.

```cpp
int cnt = 0;

for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        if (a[i][j] % 2 == 0)
            cnt++;
```

Schema generală:

```cpp
int cnt = 0;

for (...)
    for (...)
        if (conditie)
            cnt++;
```

---

# 9. Suma elementelor care respectă o condiție

Exemplu: suma elementelor pozitive.

```cpp
int s = 0;

for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        if (a[i][j] > 0)
            s += a[i][j];
```

---

# 10. Maximul și minimul

## Maximul din matrice

```cpp
int mx = a[0][0];

for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        if (a[i][j] > mx)
            mx = a[i][j];
```

## Minimul din matrice

```cpp
int mn = a[0][0];

for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        if (a[i][j] < mn)
            mn = a[i][j];
```

---

# 11. Poziția maximului/minimului

Dacă trebuie să determinăm și poziția unui element:

```cpp
int mx = a[0][0];
int linie = 0, coloana = 0;

for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        if (a[i][j] > mx) {
            mx = a[i][j];
            linie = i;
            coloana = j;
        }
```

La final:

```cpp
cout << mx << ' ' << linie << ' ' << coloana;
```

Dacă există mai multe valori maxime, acest algoritm reține **prima** întâlnită.

Pentru ultima poziție, putem folosi:

```cpp
if (a[i][j] >= mx)
```

---

# 12. Prelucrarea unei linii

Pentru a parcurge doar linia `k`:

```cpp
for (int j = 0; j < m; j++)
    // a[k][j]
```

Exemplu: suma elementelor de pe linia `k`:

```cpp
int s = 0;

for (int j = 0; j < m; j++)
    s += a[k][j];
```

---

# 13. Prelucrarea unei coloane

Pentru a parcurge doar coloana `k`:

```cpp
for (int i = 0; i < n; i++)
    // a[i][k]
```

Exemplu: suma elementelor de pe coloana `k`:

```cpp
int s = 0;

for (int i = 0; i < n; i++)
    s += a[i][k];
```

---

# 14. Suma fiecărei linii

```cpp
for (int i = 0; i < n; i++) {
    int s = 0;

    for (int j = 0; j < m; j++)
        s += a[i][j];

    cout << s << '\n';
}
```

---

# 15. Suma fiecărei coloane

```cpp
for (int j = 0; j < m; j++) {
    int s = 0;

    for (int i = 0; i < n; i++)
        s += a[i][j];

    cout << s << '\n';
}
```

---

# 16. Maximul de pe fiecare linie

```cpp
for (int i = 0; i < n; i++) {
    int mx = a[i][0];

    for (int j = 1; j < m; j++)
        if (a[i][j] > mx)
            mx = a[i][j];

    cout << mx << '\n';
}
```

---

# 17. Minimul de pe fiecare coloană

```cpp
for (int j = 0; j < m; j++) {
    int mn = a[0][j];

    for (int i = 1; i < n; i++)
        if (a[i][j] < mn)
            mn = a[i][j];

    cout << mn << '\n';
}
```

---

# 18. Diagonala principală

Diagonala principală există în cazul unei matrice pătratice.

Exemplu:

```text
x  2  3  4
5  x  7  8
9  1  x  6
2  3  4  x
```

Elementele de pe diagonala principală sunt:

```text
a[0][0]
a[1][1]
a[2][2]
a[3][3]
```

Condiția este:

```cpp
i == j
```

Parcurgere:

```cpp
for (int i = 0; i < n; i++)
    cout << a[i][i];
```

Dacă matricea este `n × n`.

---

# 19. Diagonala secundară

Pentru o matrice `n × n`, diagonala secundară este:

```text
1  2  3  x
4  5  x  7
8  x 10 11
x 13 14 15
```

Condiția este:

```text
i + j == n - 1
```

Elementele sunt:

```cpp
a[0][n-1]
a[1][n-2]
a[2][n-3]
...
a[n-1][0]
```

Parcurgere:

```cpp
for (int i = 0; i < n; i++)
    cout << a[i][n - 1 - i];
```

---

# 20. Suma diagonalei principale

```cpp
int s = 0;

for (int i = 0; i < n; i++)
    s += a[i][i];
```

---

# 21. Suma diagonalei secundare

```cpp
int s = 0;

for (int i = 0; i < n; i++)
    s += a[i][n - 1 - i];
```

---

# 22. Deasupra diagonalei principale

Pentru elementele strict deasupra diagonalei principale:

```text
-  x  x  x
-  -  x  x
-  -  -  x
-  -  -  -
```

Condiția:

```cpp
j > i
```

Parcurgere:

```cpp
for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
        // a[i][j]
```

---

# 23. Sub diagonala principală

Condiția:

```cpp
i > j
```

Parcurgere:

```cpp
for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++)
        // a[i][j]
```

---

# 24. Deasupra sau pe diagonala principală

Condiția:

```cpp
j >= i
```

Parcurgere:

```cpp
for (int i = 0; i < n; i++)
    for (int j = i; j < n; j++)
        // a[i][j]
```

---

# 25. Sub sau pe diagonala principală

Condiția:

```cpp
i >= j
```

Parcurgere:

```cpp
for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++)
        // a[i][j]
```

---

# 26. Regiunile determinate de diagonala secundară

Pentru diagonala secundară:

```text
i + j == n - 1
```

## Deasupra diagonalei secundare

```text
i + j < n - 1
```

## Sub diagonala secundară

```text
i + j > n - 1
```

---

# 27. Triunghiurile unei matrice

Pentru o matrice pătratică putem avea:

* triunghi superior principal;
* triunghi inferior principal;
* triunghi superior secundar;
* triunghi inferior secundar.

Este foarte important să transformăm cerința în **condiție asupra indicilor**.

Exemplu:

```cpp
if (i < j)
```

înseamnă element strict deasupra diagonalei principale.

---

# 28. Elementele de pe marginea matricei

Pentru o matrice cu `n` linii și `m` coloane, un element se află pe margine dacă:

```cpp
i == 0 || i == n - 1 || j == 0 || j == m - 1
```

Parcurgere:

```cpp
for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
            // a[i][j]
```

---

# 29. Interiorul matricei

Un element este strict în interior dacă nu se află pe margine:

```cpp
i > 0 && i < n - 1 &&
j > 0 && j < m - 1
```

---

# 30. Cele patru colțuri

Pentru matricea `n × m`, colțurile sunt:

```cpp
a[0][0]
a[0][m - 1]
a[n - 1][0]
a[n - 1][m - 1]
```

---

# 31. Schimbarea a două elemente

Pentru a interschimba două elemente:

```cpp
swap(a[i][j], a[x][y]);
```

sau:

```cpp
int aux = a[i][j];
a[i][j] = a[x][y];
a[x][y] = aux;
```

---

# 32. Schimbarea a două linii

Pentru liniile `x` și `y`:

```cpp
for (int j = 0; j < m; j++)
    swap(a[x][j], a[y][j]);
```

---

# 33. Schimbarea a două coloane

Pentru coloanele `x` și `y`:

```cpp
for (int i = 0; i < n; i++)
    swap(a[i][x], a[i][y]);
```

---

# 34. Transpusă

Transpunerea unei matrice schimbă liniile cu coloanele.

Dacă:

```text
1 2 3
4 5 6
```

transpusa este:

```text
1 4
2 5
3 6
```

Matematic:

```text
b[j][i] = a[i][j]
```

Pentru o matrice generală:

```cpp
for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        b[j][i] = a[i][j];
```

Matricea `b` va avea `m` linii și `n` coloane.

---

# 35. Transpunerea unei matrice pătratice

Pentru o matrice `n × n`, putem face transpunerea direct în aceeași matrice:

```cpp
for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
        swap(a[i][j], a[j][i]);
```

Nu trebuie să schimbăm elementele de pe diagonala principală.

---

# 36. Simetria față de diagonala principală

O matrice pătratică este simetrică față de diagonala principală dacă:

```text
a[i][j] == a[j][i]
```

pentru toate valorile `i` și `j`.

Putem verifica:

```cpp
bool ok = true;

for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
        if (a[i][j] != a[j][i])
            ok = false;
```

Este suficient să verificăm o singură parte a matricei.

---

# 37. Rotirea unei matrice cu 90°

Pentru o matrice pătratică, rotirea cu 90° în sensul acelor de ceasornic se poate face prin:

1. transpunere;
2. inversarea fiecărei linii.

Transpunere:

```cpp
for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
        swap(a[i][j], a[j][i]);
```

Inversarea fiecărei linii:

```cpp
for (int i = 0; i < n; i++)
    for (int j = 0; j < n / 2; j++)
        swap(a[i][j], a[i][n - 1 - j]);
```

---

# 38. Eliminarea unei linii

Dacă vrem să eliminăm linia `k`, putem deplasa liniile următoare în sus:

```cpp
for (int i = k; i < n - 1; i++)
    for (int j = 0; j < m; j++)
        a[i][j] = a[i + 1][j];

n--;
```

---

# 39. Eliminarea unei coloane

Pentru eliminarea coloanei `k`:

```cpp
for (int j = k; j < m - 1; j++)
    for (int i = 0; i < n; i++)
        a[i][j] = a[i][j + 1];

m--;
```

---

# 40. Adăugarea unei linii

Pentru inserarea unei linii înainte de poziția `k`, deplasăm liniile în jos:

```cpp
for (int i = n; i > k; i--)
    for (int j = 0; j < m; j++)
        a[i][j] = a[i - 1][j];
```

Apoi completăm noua linie:

```cpp
for (int j = 0; j < m; j++)
    cin >> a[k][j];

n++;
```

---

# 41. Adăugarea unei coloane

Deplasăm coloanele spre dreapta:

```cpp
for (int j = m; j > k; j--)
    for (int i = 0; i < n; i++)
        a[i][j] = a[i][j - 1];
```

Apoi completăm noua coloană:

```cpp
for (int i = 0; i < n; i++)
    cin >> a[i][k];

m++;
```

---

# 42. Prelucrarea doar a elementelor distincte

Dacă cerința este să afișăm valorile distincte, trebuie să verificăm dacă o valoare a mai apărut.

O metodă simplă:

```cpp
for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
        bool gasit = false;

        for (int x = 0; x < i; x++)
            for (int y = 0; y < m; y++)
                if (a[x][y] == a[i][j])
                    gasit = true;

        for (int y = 0; y < j; y++)
            if (a[i][y] == a[i][j])
                gasit = true;

        if (!gasit)
            cout << a[i][j] << ' ';
    }
```

Pentru valori naturale cu domeniu mic, o frecvență este de obicei mai eficientă.

---

# 43. Frecvența valorilor

Dacă valorile sunt într-un interval mic, putem folosi un vector de frecvență.

Exemplu pentru valori între `0` și `100`:

```cpp
int f[101] = {};

for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        f[a[i][j]]++;
```

Apoi:

```cpp
for (int x = 0; x <= 100; x++)
    if (f[x] > 0)
        cout << x << ' ' << f[x] << '\n';
```

---

# 44. Numărul de apariții ale unei valori

Pentru valoarea `x`:

```cpp
int cnt = 0;

for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        if (a[i][j] == x)
            cnt++;
```

---

# 45. Verificarea unei proprietăți a tuturor elementelor

Exemplu: verificăm dacă toate elementele sunt pozitive.

```cpp
bool ok = true;

for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        if (a[i][j] <= 0)
            ok = false;
```

Schema generală:

```cpp
bool ok = true;

for (...)
    for (...)
        if (!(conditia))
            ok = false;
```

---

# 46. Verificarea existenței unui element

Exemplu: există cel puțin un element negativ?

```cpp
bool ok = false;

for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        if (a[i][j] < 0)
            ok = true;
```

Schema generală:

```cpp
bool gasit = false;

for (...)
    for (...)
        if (conditie)
            gasit = true;
```

---

# 47. Oprirea la găsirea unui element

Dacă vrem să oprim căutarea imediat:

```cpp
bool gasit = false;

for (int i = 0; i < n && !gasit; i++)
    for (int j = 0; j < m; j++)
        if (a[i][j] == x) {
            gasit = true;
            break;
        }
```

---

# 48. Elemente deasupra/sub diagonalei secundare

Pentru diagonala secundară:

```text
i + j = n - 1
```

### Strict deasupra

```cpp
i + j < n - 1
```

### Strict sub

```cpp
i + j > n - 1
```

### Pe sau deasupra

```cpp
i + j <= n - 1
```

### Pe sau sub

```cpp
i + j >= n - 1
```

---

# 49. Elementele dintre cele două diagonale

Într-o matrice pătratică, condițiile depind de regiunea cerută.

De exemplu, pentru regiunea aflată între diagonalele principale, putem folosi:

```cpp
abs(i - j)
```

sau condiții echivalente bazate pe:

```text
i < j
i + j < n - 1
```

Înainte de a scrie codul, este recomandat să desenezi matricea și să marchezi elementele dorite.

---

# 50. Matrice triunghiulară

O matrice pătratică este triunghiulară superior dacă toate elementele de sub diagonala principală sunt `0`:

```text
1 2 3
0 4 5
0 0 6
```

Condiția:

```cpp
i > j
```

Trebuie verificat:

```cpp
bool ok = true;

for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++)
        if (a[i][j] != 0)
            ok = false;
```

---

# 51. Matrice triunghiulară inferior

Exemplu:

```text
1 0 0
2 3 0
4 5 6
```

Trebuie ca toate elementele de deasupra diagonalei principale să fie `0`.

Condiția:

```cpp
j > i
```

Verificare:

```cpp
bool ok = true;

for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
        if (a[i][j] != 0)
            ok = false;
```

---

# 52. Matrice diagonală

O matrice este diagonală dacă toate elementele din afara diagonalei principale sunt `0`.

```text
1 0 0
0 5 0
0 0 8
```

Verificare:

```cpp
bool ok = true;

for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        if (i != j && a[i][j] != 0)
            ok = false;
```

---

# 53. Matrice scalară

O matrice scalară are:

* toate elementele din afara diagonalei principale egale cu `0`;
* toate elementele de pe diagonala principală egale între ele.

Exemplu:

```text
5 0 0
0 5 0
0 0 5
```

---

# 54. Matrice identitate

Matricea identitate are:

* `1` pe diagonala principală;
* `0` în rest.

Exemplu:

```text
1 0 0
0 1 0
0 0 1
```

Putem verifica:

```cpp
bool ok = true;

for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        if ((i == j && a[i][j] != 1) ||
            (i != j && a[i][j] != 0))
            ok = false;
```

---

# 55. Matrice simetrică

O matrice este simetrică dacă:

```cpp
a[i][j] == a[j][i]
```

pentru toate perechile de indici.

Exemplu:

```text
1 2 3
2 4 5
3 5 6
```

---

# 56. Matrice antisimetrică

O matrice este antisimetrică dacă:

```text
a[i][j] = -a[j][i]
```

Pentru diagonala principală rezultă:

```text
a[i][i] = 0
```

deoarece:

```text
a[i][i] = -a[i][i]
```

---

# 57. Operații între două matrice

Pentru două matrice de aceeași dimensiune putem efectua operații element cu element.

## Adunarea

```cpp
for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        c[i][j] = a[i][j] + b[i][j];
```

## Scăderea

```cpp
for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        c[i][j] = a[i][j] - b[i][j];
```

---

# 58. Înmulțirea unei matrice cu un scalar

Pentru scalarul `k`:

```cpp
for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        a[i][j] *= k;
```

---

# 59. Înmulțirea a două matrice

Dacă:

```text
A = n × m
B = m × p
```

atunci:

```text
C = n × p
```

Formula:

```text
C[i][j] = Σ A[i][k] * B[k][j]
```

Implementare:

```cpp
for (int i = 0; i < n; i++)
    for (int j = 0; j < p; j++) {
        c[i][j] = 0;

        for (int k = 0; k < m; k++)
            c[i][j] += a[i][k] * b[k][j];
    }
```

Observație: această operație este diferită de înmulțirea element cu element.

---

# 60. Vectorul unei linii / coloane

O linie a matricei poate fi privită ca un vector:

```cpp
a[i][0], a[i][1], ..., a[i][m-1]
```

O coloană:

```cpp
a[0][j], a[1][j], ..., a[n-1][j]
```

Acest lucru este util când o problemă cere:

* sortarea unei linii;
* sortarea unei coloane;
* suma unei linii;
* maximul unei coloane;
* interschimbarea a două linii/coloane.

---

# 61. Sortarea unei linii

Putem folosi `sort`:

```cpp
sort(a[i], a[i] + m);
```

Pentru sortare descrescătoare:

```cpp
sort(a[i], a[i] + m, greater<int>());
```

---

# 62. Sortarea tuturor liniilor

```cpp
for (int i = 0; i < n; i++)
    sort(a[i], a[i] + m);
```

---

# 63. Sortarea unei coloane

O coloană nu este stocată ca un vector continuu, deci nu putem folosi direct `sort(a[0], ...)`.

Putem folosi un vector auxiliar:

```cpp
vector<int> v(n);

for (int i = 0; i < n; i++)
    v[i] = a[i][j];

sort(v.begin(), v.end());

for (int i = 0; i < n; i++)
    a[i][j] = v[i];
```

---

# 64. Probleme cu linii/coloane care respectă o condiție

Exemplu: determinarea numărului de linii care conțin cel puțin un element negativ.

```cpp
int cnt = 0;

for (int i = 0; i < n; i++) {
    bool gasit = false;

    for (int j = 0; j < m; j++)
        if (a[i][j] < 0)
            gasit = true;

    if (gasit)
        cnt++;
}
```

Ideea importantă este că `gasit` se resetează pentru fiecare linie.

---

# 65. Linii identice

Două linii `x` și `y` sunt identice dacă:

```cpp
bool ok = true;

for (int j = 0; j < m; j++)
    if (a[x][j] != a[y][j])
        ok = false;
```

---

# 66. Coloane identice

Două coloane `x` și `y` sunt identice dacă:

```cpp
bool ok = true;

for (int i = 0; i < n; i++)
    if (a[i][x] != a[i][y])
        ok = false;
```

---

# 67. Numărul de linii distincte

Pentru fiecare linie trebuie să verificăm dacă există o linie anterioară identică.

Schema este:

```cpp
int cnt = 0;

for (int i = 0; i < n; i++) {
    bool distincta = true;

    for (int k = 0; k < i; k++) {
        bool egale = true;

        for (int j = 0; j < m; j++)
            if (a[i][j] != a[k][j])
                egale = false;

        if (egale)
            distincta = false;
    }

    if (distincta)
        cnt++;
}
```

---

# 68. Elemente vecine

Pentru un element `a[i][j]`, vecinii direcți pot fi:

```text
        sus
         |
stânga - x - dreapta
         |
       jos
```

Adică:

```cpp
a[i-1][j]
a[i+1][j]
a[i][j-1]
a[i][j+1]
```

Trebuie să verificăm limitele înainte de accesare.

Exemplu:

```cpp
if (i > 0)
    // a[i-1][j]

if (i < n - 1)
    // a[i+1][j]

if (j > 0)
    // a[i][j-1]

if (j < m - 1)
    // a[i][j+1]
```

---

# 69. Cei 8 vecini

Pentru un element interior, putem considera și diagonalele:

```text
↖  ↑  ↗
←  x  →
↙  ↓  ↘
```

Coordonatele modificărilor sunt:

```text
(-1,-1)  (-1,0)  (-1,+1)
( 0,-1)           ( 0,+1)
(+1,-1)  (+1,0)  (+1,+1)
```

O metodă elegantă este folosirea vectorilor de direcție:

```cpp
int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};
```

Apoi:

```cpp
for (int d = 0; d < 8; d++) {
    int ni = i + di[d];
    int nj = j + dj[d];

    if (ni >= 0 && ni < n && nj >= 0 && nj < m)
        // a[ni][nj]
}
```

---

# 70. Suma vecinilor

Exemplu pentru cei 4 vecini:

```cpp
int s = 0;

if (i > 0)
    s += a[i - 1][j];

if (i < n - 1)
    s += a[i + 1][j];

if (j > 0)
    s += a[i][j - 1];

if (j < m - 1)
    s += a[i][j + 1];
```

---

# 71. Căutarea unui element într-o matrice

Căutare liniară:

```cpp
bool gasit = false;

for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        if (a[i][j] == x)
            gasit = true;
```

Complexitate:

```text
O(n · m)
```

---

# 72. Complexitatea parcurgerii unei matrice

Dacă avem `n` linii și `m` coloane:

```cpp
for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
```

atunci fiecare element este vizitat o singură dată.

Complexitatea este:

```text
O(n · m)
```

Pentru o matrice pătratică `n × n`:

```text
O(n²)
```

---

# 73. Atenție la matricele pătratice

O matrice este pătratică dacă:

```text
n = m
```

Doar în acest caz avem:

* aceeași cantitate de linii și coloane;
* diagonala principală;
* diagonala secundară;
* triunghiuri față de diagonale.

Dacă matricea este `n × m` și `n != m`, nu trebuie să aplicăm automat formulele pentru diagonale de matrice pătratică.

---

# 74. Indici de la 0 vs. indici de la 1

În C++:

```cpp
int a[100][100];
```

permite în mod normal indicii:

```text
0 ... 99
```

Dacă vrem să lucrăm cu:

```text
1 ... n
1 ... m
```

declarăm suficient spațiu:

```cpp
int a[101][101];
```

Exemplu:

```cpp
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        cin >> a[i][j];
```

Pentru BAC, ambele variante sunt corecte. Important este să nu le amestecăm.

---

# 75. Inițializarea unei matrice

Putem inițializa toate elementele cu `0`:

```cpp
int a[100][100] = {};
```

sau:

```cpp
int a[100][100] = {0};
```

Pentru o matrice mică putem specifica valorile:

```cpp
int a[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

---

# 76. Copierea unei matrice

```cpp
for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        b[i][j] = a[i][j];
```

---

# 77. Compararea a două matrice

Două matrice de aceeași dimensiune sunt egale dacă toate elementele corespunzătoare sunt egale.

```cpp
bool egale = true;

for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        if (a[i][j] != b[i][j])
            egale = false;
```

---

# 78. Matrice cu valori booleene

Uneori o matrice poate reprezenta o hartă sau o relație:

```text
0 1 0
1 0 1
0 1 0
```

Putem folosi:

```cpp
bool a[100][100];
```

sau, pentru eficiență:

```cpp
int a[100][100];
```

în funcție de cerință.

---

# 79. Matricea de adiacență

În teoria grafurilor, un graf cu `n` vârfuri poate fi reprezentat printr-o matrice de adiacență:

```cpp
int a[100][100];
```

Pentru un graf neorientat:

```text
a[i][j] = 1
```

înseamnă că există muchie între `i` și `j`.

Într-un graf neorientat:

```text
a[i][j] == a[j][i]
```

deci matricea este simetrică.

---

# 80. Greșeli frecvente

## Greșeala 1 — Inversarea indicilor

```cpp
a[i][j]
```

înseamnă:

```text
linia i, coloana j
```

nu invers.

---

## Greșeala 2 — Depășirea limitelor

Nu putem accesa:

```cpp
a[-1][j]
a[n][j]
a[i][-1]
a[i][m]
```

---

## Greșeala 3 — Confuzia dintre diagonale

Diagonala principală:

```cpp
i == j
```

Diagonala secundară:

```cpp
i + j == n - 1
```

---

## Greșeala 4 — Folosirea `n` în loc de `m`

Pentru o matrice `n × m`:

```cpp
i < n
j < m
```

Nu:

```cpp
j < n
```

decât dacă matricea este pătratică.

---

## Greșeala 5 — Inițializarea greșită a maximului/minimului

Este mai sigur:

```cpp
int mx = a[0][0];
```

decât:

```cpp
int mx = 0;
```

deoarece matricea poate conține doar valori negative.

---

## Greșeala 6 — Resetarea greșită a variabilelor

Dacă determinăm suma fiecărei linii:

```cpp
for (int i = 0; i < n; i++) {
    int s = 0;

    for (int j = 0; j < m; j++)
        s += a[i][j];

    cout << s;
}
```

`s` trebuie resetat pentru fiecare linie.

---

# 81. Cheat sheet — condiții importante

| Element / zonă               | Condiție                               |   |          |   |        |   |           |
| ---------------------------- | -------------------------------------- | - | -------- | - | ------ | - | --------- |
| Diagonala principală         | `i == j`                               |   |          |   |        |   |           |
| Diagonala secundară          | `i + j == n - 1`                       |   |          |   |        |   |           |
| Deasupra diag. principale    | `i < j`                                |   |          |   |        |   |           |
| Sub diag. principale         | `i > j`                                |   |          |   |        |   |           |
| Pe/deasupra diag. principale | `i <= j`                               |   |          |   |        |   |           |
| Pe/sub diag. principale      | `i >= j`                               |   |          |   |        |   |           |
| Deasupra diag. secundare     | `i + j < n - 1`                        |   |          |   |        |   |           |
| Sub diag. secundare          | `i + j > n - 1`                        |   |          |   |        |   |           |
| Pe/deasupra diag. secundare  | `i + j <= n - 1`                       |   |          |   |        |   |           |
| Pe/sub diag. secundare       | `i + j >= n - 1`                       |   |          |   |        |   |           |
| Margine                      | `i == 0                                |   | i == n-1 |   | j == 0 |   | j == m-1` |
| Interior                     | `i > 0 && i < n-1 && j > 0 && j < m-1` |   |          |   |        |   |           |
| Colț stânga-sus              | `i == 0 && j == 0`                     |   |          |   |        |   |           |
| Colț dreapta-sus             | `i == 0 && j == m-1`                   |   |          |   |        |   |           |
| Colț stânga-jos              | `i == n-1 && j == 0`                   |   |          |   |        |   |           |
| Colț dreapta-jos             | `i == n-1 && j == m-1`                 |   |          |   |        |   |           |