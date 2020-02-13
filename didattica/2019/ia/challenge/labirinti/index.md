---
layout: default
---

## Risultati Challenge 3: labirinti

### Valutazione

La valutazione è stata effettuata in maniera automatizzata. Le consegne in cui non è stata inserita la matricola dello studente non sono state testate. Ogni implementazione è stata testata su nove input differenti. I labirinti utilizzati per il test hanno caratteristiche differenti, per stressare possibili bias implementativi (direzione della ricerca, posizione dell'ingresso/uscita, presenza di cicli, presenza di "aree libere").

Sono stati misurati i tempi d'esecuzione di risoluzione di tutti gli input. **È stato impostato un timeout di 5 minuti**: al termine dei 5 minuti, il risolutore veniva interrotto. La graduatoria è stata compilata anteponendo la correttezza alle performance: implementazioni che non riuscivano a trovare la soluzione nel limite di 5 minuti o che fornivano una soluzione non corretta sono scese nella graduatoria.

Il codice utilizzato per la valutazione è [disponibile qui](evaluate.zip).

### Graduatoria

Tutti i tempi sono in secondi.

| Rank | Matricola | Input 1 | Input 2 | Input 3 | Input 4 | Input 5 | Input 6 | Input 7 | Input 8 | Input 9 | Punti |
| ---: | :-------: | :-------: | :-------: | :-------: | :-------: | :-------: | :-------: | :-------: | :-----------------: | :---: | ----- |
| 1 | 0266643 | 0.04 | 0.03 | 0.03 | 0.04 | 0.03 | 0.04 | 0.04 | 0.03 | 0.04 | +2 |
| 2 | 0266523 | 0.04 | Soluzione errata | 0.03 | 0.03 | 0.03 | 0.05 | 0.29 | 0.04 | 0.04 |  |
| 3 | 0266938 | 0.03 | Soluzione errata | 0.03 | 0.04 | 0.03 | 0.03 | 0.04 | 0.03 | 0.04 |  |
| 4 | 0268350 | 0.05 | Timeout | 0.04 | 0.03 | Timeout | Timeout | Timeout | Timeout | 0.07 |  |
| 5 | 0266833 | Timeout | Timeout | Timeout | 0.04 | 0.03 | Timeout | Timeout | Timeout | 0.04 |  |
| 6 | 0268603 | Soluzione errata | Soluzione errata | Soluzione errata | Soluzione errata | Soluzione errata | Soluzione errata | Soluzione errata | Soluzione errata | 0.05 |  |

