#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

//structura de tip tranzactie cu urmatoarele specificatii: id, descriere, tip, data la care a fost inregistrata, suma
typedef struct {
    unsigned int id;
    char description[10001];
    char type[101];
    time_t date;
    double sum;
} transaction;

//creaza o strcutura de tip tranzactie
transaction *new_transaction(unsigned int id, char description[10001], char type[101], time_t date, double sum){
    transaction *t = malloc(sizeof(transaction));
    if(t == NULL) {
        return NULL;
    }
    t->id = id;
    strcpy(t->description, description);
    strcpy(t->type, type);
    t->date = date;
    t->sum = sum;

    return t;
}

//returneaza id-ul
unsigned int get_id(transaction *transaction1) {
    return transaction1->id;
}

//returneaza descrierea
char *get_description(transaction *transaction){
    return transaction->description;
}

//returneaza tipul
char *get_type(transaction *transaction){
    return transaction->type;
}

//returneaza data
time_t get_date(transaction *transaction){
    return transaction->date;
}

//returneaza suma
double get_sum(transaction *transaction){
    return transaction->sum;
}

//modifica descrierea
void set_description(transaction *transaction, char description[]){
    strcpy(transaction->description, description);
}

//modifica tipul
void set_type(transaction *transaction, char type[]){
    strcpy(transaction->type, type);
}

//modifica suma
void set_sum(transaction *transaction, double sum){
    transaction->sum = sum;
}

//format afisare tranzactie
void print_transaction(transaction *transaction1) {
    if(transaction1 == NULL) {
        printf("Transaction doesn't exist\n");
        return;
    }

    printf("ID: %d\n", transaction1->id);
    printf("Description: %s\n", transaction1->description);
    printf("Type: %s\n", transaction1->type);
    printf("Date: %s", ctime(&transaction1->date));
    printf("Sum: %.2f\n", transaction1->sum);
}

//distrugere tranzactie
void destroy_transaction(transaction *transaction) {
    free(transaction);
}