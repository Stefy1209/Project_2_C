# Project 2 C
By Stefan Lucian Gramada

Tin sa precisez de la inceput ca aceasta aplicatie nu este completa si mai sunt aspecte care trebuie imbunatatite.

## Descriere UI
In stadiul actual aplicatia este conceputa pentru a rula in terminal. 

In momentul in care aplicatia este reluta, primele caractere care vor aparea sunt ">>> ", semn ca programul asteapta o comanda. De retinut ca programul accepta comenzi scrise doar cu litere mici.

Aplicatia este impartita pe 3 UI-uri:
* Log In UI
* User UI
* Account UI

Cele 3 interfete nu se disting cu nimic din punct de vedere grafic. De aceea este important de retinut in care UI ne aflat.

Primul UI care se activeaza in momentul deschiderii programului este Log In UI.

## Log In UI
Comenzi acceptate:
* log in
* sign up
* exit

Comanda "log in" este folosita pentru a intra in urmatoarea interfata, "sign up" introduce un nou utilizator in sistem, iar "exit" iese cu totul din aplicatie.

Daca, dupa apelul comenzii "log in", datele au fost introduse corect, atunci programul va trece la User UI.

## User UI
Comezi acceptate:
* print
* add
* remove
* go to
* exit

### Functie "print"
La apelul functiei "print" vor aparea 2 informatii principale:
* username
* numarul de conturi

In cazul existentei a unui sau mai multe conturi, atunci pentru fiecare cont vor aparea:
* ID-ul contului
* numele contului
* tipul contului

### Functia "add"
La apelul functiei "add" vor trebui introduse datele:
* numele contului
* tipul contului( __salary__, __credit__, __retirement__, __savings__, __checking__)

### Functia "remove"
La apelul functie "remove" va trebui introdus ID-ul contului pe care il dorim sa il stergem.

### Functia "go to"
La apelul functie "go to" va trebui introdus ID-ul contului pe care vrem sa-l accesam, intrand in __Account UI__.

### Functia "exit"
La apelul functie "exit" vom iesi din __User UI__ si reveni in __Log In UI__.

## Account UI
Comenzi acceptate:
* print
* add
* remove
* balance
* exit

### Functia "print"
La apelul functiei "print" vor aparea informatiile:
* nume cont
* tip cont

In cazul existentei unui sau mai multor tranzactii vor aparea si informatii cum ar fi:
* ID tranzactie
* descriere
* tipul
* data la care a fost introdusa
* suma

### Functia "add"
La apelul functiei "add" vor fi introduse informatiile:
* descrierea
* suma

### Functia "remove"
La apelul functiei "remove" se va cere ID-ul tranzactiei pe care dorim sa o eliminam

### Functia "balance"
La apelul functiei "balance" se va afisa suma de bani din contul respectiv

### Functia "exit"
La apelul functiei "exit" se va reveni la __User UI__
