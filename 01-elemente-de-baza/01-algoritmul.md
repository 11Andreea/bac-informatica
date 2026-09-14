# Ghidul tău de orientare: Ce este un algoritm și cum funcționează? 

Un **algoritm** este, în esență, o rețetă super precisă. Mai tehnic spus, este o serie de pași (sau instrucțiuni) clari care se execută într-o ordine fixă. Dacă urmezi acești pași, vei rezolva o anumită problemă într-un timp limitat, pornind de la niște date pe care le ai deja și ajungând la rezultatul dorit.

---

## 1. Cum funcționează un algoritm? (Schema simplă)

Mecanismul din spatele oricărui algoritm arată cam așa:

```text
[ Date de Intrare ]  --->  [ ALGORITM (Mecanismul de procesare) ]  --->  [ Date de Ieșire ]
```

* **Date de intrare (Input):** Ingredientele cu care pornești la drum (de exemplu, două numere, $a$ și $b$).
* **Date de ieșire (Output):** Rezultatul final (de exemplu, suma lor, $S = a + b$).
* **Date auxiliare:** Niște foi de ciornă sau variabile pe care le folosești doar pe moment, ca să îți iasă calculele.

---

## 2. Exemplu: Suma a două numere 

### Cerința
Primești două numere întregi, $a$ și $b$. Trebuie să le afli suma.

### Algoritmul:
1. Întreabă utilizatorul cât este $a$ și ține minte valoarea.
2. Întreabă utilizatorul cât este $b$ și ține minte valoarea.
3. Adună-le și pune rezultatul în cutia numită $S$ ($S \leftarrow a + b$).
4. Arată-i utilizatorului ce se află în cutia $S$.
5. Gata! Oprește programul.

---

# Cele 5 reguli de aur

Ca o listă de instrucțiuni să poată fi numită cu adevărat un **algoritm**, ea trebuie să respecte cu strictețe 5 caracteristici obligatorii.

---

## 1. Generalitatea (Să fie universal)
Algoritmul tău trebuie să fie capabil să rezolve **o întreagă categorie de probleme**, nu doar un singur caz norocos.
* 👍 **Așa da:** Un cod care adună oricare două numere introduse de la tastatură.
* 👎 **Așa nu:** Un cod care știe să adune doar $3$ cu $5$ și nimic altceva.

## 2. Claritatea (Să fie precis)
Fiecare pas trebuie să fie **la obiect, fără ghicitori sau interpretări**. Calculatorul trebuie să știe în orice secundă ce are de făcut în pasul următor.
* 👍 **Așa da:** `x 🡨 x + 1` (Mărește-l pe $x$ cu 1).
* 👎 **Așa nu:** „Fă-l pe $x$ un pic mai mare.”

## 3. Finitudinea (Să aibă un sfârșit)
Algoritmul trebuie să se oprească după un **număr limitat de pași**. Dacă programul tău intră într-o „buclă infinită” (un ecran blocat care calculează la nesfârșit), înseamnă că ai dat greș la acest capitol.

## 4. Corectitudinea (Să dea rezultatul bun)
Pare evident, nu? Algoritmul tău trebuie să livreze **răspunsul corect** pentru orice date de intrare logice. Dacă îi ceri o sumă și el îți dă o scădere, ceva e greșit.

## 5. Eficiența (Să fie rapid)
Un algoritm bun nu doar că rezolvă problema, dar o face **într-un timp record și fără să sufoce memoria calculatorului**. Nimeni nu vrea un algoritm care stă 3 ore ca să calculeze o medie de note!

---

## Rezumat de reținut

| Caracteristică | Ce înseamnă, pe scurt? |
| :--- | :--- |
| **Generalitate** | Rezolvă orice caz, nu doar unul singur. |
| **Claritate** | Instrucțiuni exacte, fără dubii sau „scurtcircuite”. |
| **Finitudine** | Are un număr limitat de pași și se oprește la un moment dat. |
| **Corectitudine** | Oferă mereu rezultatul corect și dorit. |
| **Eficiență** | Se mișcă rapid și consumă puține resurse (RAM). |
