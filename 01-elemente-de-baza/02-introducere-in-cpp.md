# Ghidul tău de supraviețuire în C++

Limbajul **C++ a fost creat de Bjarne Stroustrup în 1979** ca un „upgrade” pentru limbajul C. La rândul lui, **limbajul C a fost inventat de Dennis Ritchie (între 1969 și 1973)** ca să scrie sistemul de operare Unix. Pentru că C++ s-a născut direct din C, aproape orice cod scris în C va rula perfect și în C++, fără să-i schimbi mare lucru.

---

## 💻 Ce este, mai exact, un limbaj de programare?

Gândește-te la limbajele de programare ca la niște limbi străine, dar destinate calculatoarelor. Au reguli de gramatică stricte (sintaxă), semne de punctuație și câteva cuvinte-cheie. Toate jocurile și aplicațiile de pe telefonul sau PC-ul tău sunt scrise așa.

Pe lângă **C și C++**, probabil ai mai auzit de **Python, Java, JavaScript sau PHP**. 

### Cum ajunge codul tău să devină o aplicație reală?
Codul pe care îl scrii tu în editor se numește **cod sursă**. Procesorul de pe calculator nu știe să-l citească direct (el înțelege doar curent electric: 0 și 1). Așa că textul tău trebuie tradus în **cod mașină (fișierul executabil)**. 

În funcție de cum se face această traducere, limbajele sunt de două feluri:
* **Limbaje compilate (cum e C++):** Un program special numit **compilator** ia tot codul tău, îl verifică și îl traduce dintr-o singură mișcare într-un fișier gata de rulare.
* **Limbaje interpretate (cum e Python):** Un **interpretor** citește și execută codul linie cu linie, în timp real, direct când pornești programul.

---

## Traseul unui cod C++: Din editor până pe ecran

Ca să transformi o idee într-un program funcțional în C++, treci prin 4 pași rapizi:

1. **Editarea:** Scrii liniile de cod într-un program și salvezi fișierul cu extensia `.cpp` (de la C Plus Plus).
2. **Compilarea:** Dai click pe "Compile". Calculatorul verifică dacă ai greșit vreo regulă gramaticală. Dacă totul e perfect, îți creează un fișier obiect (`.o` sau `.obj`).
3. **Link-editarea (Linking):** Calculatorul leagă fișierul tău cu alte unelte și librăria standard din C++. Din acest pas iese programul final: celebrul fișier `.exe` pe Windows.
4. **Execuția:** Dai "Run" și programul tău pornește!

---

## Primul tău program în C++: Clasicul „Hello World”

Ca să nu scrii codul într-un Notepad obositor, cel mai bine e să folosești un **IDE (un program „all-in-one” care are și editor de text, și compilator)**. Recomand **Code::Blocks**.

Uite cum arată cel mai simplu program pe care îl poți scrie:

```cpp
// Primul program C++
#include <iostream>
using namespace std;

int main()
{
    /* 
      Acesta este un comentariu de tip bloc.
      Îl poți scrie pe mai multe rânduri.
    */
    cout << "Hello world!" << endl;
    cout << "Primul program C++!";
    return 0; 
}
```

### Ce vezi pe ecran când îi dai Run:
```text
Hello world!
Primul program C++!
```

---

## Analiza detaliată a codului:

* **`// Primul program C++`**
  Aceasta e o linie de **comentariu**. E doar o notiță pentru tine sau colegii tăi ca să înțelegeți ce face codul. Compilatorul o ignoră complet, deci poți scrie orice acolo.
* **`#include <iostream>`**
  O **directivă preprocesor**. Îi spune calculatorului: *„Hei, adu-mi biblioteca iostream pentru că am nevoie de uneltele de afișare pe ecran și citire de la tastatură”*.
* **`using namespace std;`**
  O scurtătură super utilă. Îi spune programului că folosești biblioteca standard. Fără linia asta, ar fi trebuit să scrii `std::cout` în loc de un simplu `cout`.
* **`int main()`**
  **Șeful programului (funcția principală)**. Orice cod în C++ are nevoie de o funcție numită `main`. Când dai Run, calculatorul caută fix linia asta și începe să execute ce găsește imediat sub ea.
* **`{ }` (Acoladele)**
  Sunt ca niște paranteze mari care definesc teritoriul funcției `main`. Tot ce vrei să execute programul trebuie pus între ele.
* **`cout << "Hello world!" << endl;`**
  Aici se întâmplă magia! `cout` înseamnă consola/ecranul, `<<` trimite textul spre ecran, iar `endl` înseamnă "end line" (adică dă un Enter și mută cursorul pe rândul următor).
  * ⚠️ **Atenție maximă:** Orice instrucțiune din C++ se termină obligatoriu cu punct și virgulă `;`. Dacă îl uiți, o să primești o eroare la compilare. 
* **`return 0;`**
  Anunță că funcția `main` s-a terminat cu succes. Când programul ajunge aici, se închide. Tot ce scrii după `return 0;` va fi ignorat total.

### C++ e flexibil: Scrie cum vrei!
Compilatorului nu-i pasă de spații sau dacă ai trecut la rând nou în interiorul funcției. Cele două variante de mai jos fac **exact același lucru**:

**Varianta aerisită:**
```cpp
int main()
{
    cout << "Salut";
    return 0;
}
```

**Varianta „la grămadă” (pe o singură linie):**
```cpp
int main() { cout << "Salut"; return 0; }
```

---

## 📝 Rezumat rapid despre comentarii

Folosește-le ca să nu uiți ce ai făcut în cod când îl deschizi peste o săptămână:
* `//` — Când vrei să scrii o notiță scurtă, **pe un singur rând**.
* `/* ... */` — Când vrei să lași un mesaj lung, **întins pe mai multe rânduri**.
