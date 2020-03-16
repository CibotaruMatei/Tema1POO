# Programare Orientata pe Obiecte: tema 1

Tema este implementarea clasei Polinom cu urmatoarele cerinte:
- fiecare coeficient va fi de tip double;

- membri privati pentru vectorul propriuzis si numarul de elemente;

- constructori pentru initializare si copiere;

- destructor (în cazul alocarii statice, se seteaza dimensiunea vectorului la zero, iar în cazul alocarii dinamice, se dezaloca zona de memorie utilizata);

- metoda publica pentru calculul valorii unui polinom intr-un punct;

- suma a doua polinoame, implementata prin supraincarcarea operatorului +;

- diferenta a doua polinoame, implementata prin supraincarcarea operatorului -;

- produsul a doua polinoame, implementat prin supraincarcarea operatorului *;

- supraincarcarea operatorilor << si >> pentru iesiri si intrari de obiecte;

- sa existe o metoda publica prin care se realizeaza citirea informațiilor complete a n obiecte, memorarea și afisarea acestora.

Pe langa acestea, pentru a usura munca, am implementat urmatoarele:

- in cazul polinomului nul, care are matematic gradul -infinit, am setat gradul ca fiind -1

- supraincarcarea operatorului unar de negare - pentru definirea mai simpla a scaderii

- supraincarcarea operatorului conditional == pentru verificarea cazurilor particulare de la scadere

- supraincarcarea operatorului de atribuire =
