---
layout: default
---

## Risultati Challenge 1: Hexadoku

### Il problema

La challenge consisteva nel realizzare un programma in python che risolvesse l'*hexadoku*, ovvero un sudoku su griglia 16 x 16 anziché 9 x 9, seguendo gli stessi principi di risoluzione del sudoku classico.

Gli studenti hanno ricevuto due input di prova per testare la correttezza del loro programma.

### Valutazione

La valutazione è stata effettuata in maniera automatizzata. Le consegne in cui non è stata inserita la matricola dello studente non sono state testate. Ogni implementazione è stata testata su quattro input differenti, due dei quali sono quelli forniti agli studenti per prova.

**Tutte le implementazioni in cui le soluzioni fornite inizialmente allo studente erano già associate alla soluzione finale sono state modificate per effettuare nuovamente il calcolo della soluzione**.

Sono stati misurati i tempi d'esecuzione su tutti e quattro gli input. **È stato impostato un timeout di 20 minuti**: al termine dei 20 minuti, il risolutore veniva interrotto. La graduatoria è stata compilata anteponendo la correttezza alle performance: implementazioni che non riuscivano a trovare la soluzione nel limite di 20 minuti o che fornivano una soluzione non corretta sono scese nella graduatoria.

Il codice utilizzato per la valutazione è [disponibile qui](evaluate.zip).

### Graduatoria

Tutti i tempi sono in secondi.

| Rank | Matricola | [Input 1](input1.csv) | [Input 2](input2.csv) | [Input 3](input3.csv) | [Input 4](input4.csv) | Punti |
| ---: | :-------: | :-------------------: | :-------------------: | :-------------------: | :-------------------: | :---: |
|    1 |  0266938  |         0.04          |         0.04          |         0.02          |         0.14          |  +2   |
|    2 |  0252289  |         0.11          |         0.11          |         0.09          |         0.19          |  +2   |
|    3 |  0269592  |         0.16          |         0.08          |         0.02          |        542.20         |  +2   |
|    4 |  0266387  |         0.03          |         0.04          |         0.03          |        Timeout        |       |
|    5 |  0268350  |         0.13          |         0.13          |         0.02          |        Timeout        |       |
|    6 |  0239972  |         0.14          |         0.13          |         0.02          |        Timeout        |       |
|    7 |  0269093  |         0.04          |         0.04          |         0.03          |        Timeout        |       |
|    8 |  0253591  |         0.04          |         0.04          |         0.02          |        Timeout        |       |
|    9 |  0268029  |         0.06          |         0.06          |         0.03          |        Timeout        |       |
|   10 |  0266523  |         0.02          |         0.02          |         0.02          |   Soluzione errata    |       |
|   11 |  0240739  |         69.60         |        Timeout        |         0.02          |        Timeout        |       |
|   12 |  0266492  |        564.37         |        Timeout        |         0.02          |        Timeout        |       |
|   13 |  0266403  |   Soluzione errata    |   Soluzione errata    |         0.02          |   Soluzione errata    |       |
|   14 |  0266997  |   Soluzione errata    |   Soluzione errata    |         0.02          |   Soluzione errata    |       |
|   15 |  0270865  |   Soluzione errata    |   Soluzione errata    |         0.02          |   Soluzione errata    |       |
|   16 |  0256508  |   Soluzione errata    |   Soluzione errata    |         0.02          |   Soluzione errata    |       |
|   17 |  0270788  |   Soluzione errata    |   Soluzione errata    |         0.02          |   Soluzione errata    |       |
|   18 |  0270289  |   Soluzione errata    |   Soluzione errata    |         0.03          |   Soluzione errata    |       |
|   19 |  0251843  |   Soluzione errata    |   Soluzione errata    |   Soluzione errata    |   Soluzione errata    |       |