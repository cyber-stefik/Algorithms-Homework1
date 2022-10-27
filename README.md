# Algorithms-Homework1

# Copyright Stefanita Ionita, 324CA, 2021-2022

Tema este implementata in C++, folosindu-ma de scheletul de laborator putin.

********************************************************************************
Walsh:

Am o clasa Task ce contine n, k si coordonatele, perechile de numere naturale
x si y. In aceasta clasa am o metoda solve, ce apeleaza citirea si rezolvarea
propriu zisa, metoda walsh().

Metoda read_input() imi citeste din fisiere, asemanator va fi si la urmatoarele
taskuri.

Metoda walsh() scrie in fisier pentru fiecare pereche de coordonate rezultatul.

Metoda checkWalsh() verifica cadranul in care se afla perechea de coordonate si
reduce totul la cadranul 1, functia fiind apelata recursiv.
- Pentru cadranul 1 se modifica doar dimensiunea matricii, coordonatele raman
la fel.
- Pentru cadranul 2, y-ul trebuie redus la cadranul 1 si asta se face prin
scaderea a jumatate din dimensiune.
- Pentru cadranul 3, x-ul trebuie readus la cadranul 1 si asta se face la fel ca
la y.
- Pentru cadranul 4, ambele coordonate trebuie reduse la cadranul 1.
Metoda ajunge la final cand dimensiunea matricei este 1, fiind returnata
valoarea in functie de flagul rev.
Flagul rev este negat de fiecare data cand perechea de coordonate ajunge in
cadranul 4.
COMPLEXITATE: O(k * logn)

********************************************************************************
Statistics:

Clasa Task este asemanatoare cu cea de la problema anterioara, asemenea si
metoda solve().

Metoda statistics() trece prin toate literele alfabetului englez si calculeaza
dominanta fiecarei litere in cuvintele date ca input. Acestea sunt sortate
descrescator. Parcurg dominantele sortate si adaug tot ce este pozitiv la o
suma si verific daca mai pot adauga elemente negative, conditia fiind ca suma
sa fie mai mare decat 0, astfel obtinand cea mai mare dominanta.
COMPLEXITATE: 

********************************************************************************
Prinel:

Metoda myKnapsack calculeaza vectorul de divizori pana la target.
Sunt doua cazuri:
	* Primul, in care pot adauga dublul numarului anterior
	* Al doilea, in care caut elementul maxim mai mic decat elementul anterior,
		pe care il pot adauga pana la target.
Flow-ul pe un exemplu:
	k = 4 si target = 7
	1 -> 2 -> 4 -> 6 -> 7 care nu verifica cerinta
COMPLEXITATE: O(k * logk)

********************************************************************************
Crypto:

Metoda crypto calculeaza numarul unic de litere din secventa, pentru a putea fi
folosit mai tarziu, si initializeaza un vector de forma (1, 0, 0, ..., 0),
lungimea acestuia fiind l. Acest vector reprezinta numarul initial de secvente
posibile de forma (null, secv[0], secv[1] ..., secv[l - 1]). Initial, avem un
sir null si iterez prin literele cheii. Sunt doua cazuri:
- ?
	* In acest caz, putem avea (numarul de litere unice din secventa)
	posibilitati, astfel inmultesc fiecare subsecventa gasita cu numarul de
	litere unice si adaug subsecventele gasite inaintea lor. In cazul
	subsecventei null, aceasta este inmultita cu numarul unic de litere.
- litera
	* In cazul in care avem o litera, verfic ce litera din secventa este si
	modific vectorul astfel: la elementul de pe pozitia j + 1 adaug numarul
	de subsecvente gasite inaintea lui, adica elementul de pe pozitia j.
	Ma folosesc de programare dinamica, presupunand ca am calculat deja
	elementul j.
Astfel, in urma tuturor modificarilor, elementul final din vector este
rezultatul.

Flowul unui input este urmatorul:
Test 0 - 5 2 p?ap? pa
Am un vector ce presupune:
_	p   a
1	0	0 - initial
1	1	0 - litera p este updatata folosindu-ma de sirul null
2	3   1 - cazul ?, deci voi inmulti fiecare element cu numarul de caractere
			unice, la care adaug valoarea actuala (caz special pentru index 0)
2	3   4 - litera a este updatata
2	5	4 - litera p este updatata
4	12	13 - cazul ?, asemanator celui de mai sus.
COMPLEXITATE: O(n * l)

