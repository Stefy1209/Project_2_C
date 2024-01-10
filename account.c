#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "repo_transaction.h"
#include "service_transaction.h"

typedef struct {
    size_t id;
    char file_name[101];
    char name[101];
    char type[101];
    array_transaction *list;
}account;

// creaza un cont
account *new_account(size_t id, char file_name [101], char name[101], char type[101]) {
    account *a = malloc(sizeof(account));

    a->id = id;
    strcpy(a->file_name, file_name);
    strcpy(a->name, name);
    strcpy(a->type, type);
    a->list = new_list();

    return a;
}

// elibereaza memoria folosita pentru cont
void destroy_account(account *a) {
    destroy_array(a->list);
    free(a);
}

//returneaza id-ul contului
size_t get_id_account(account *a) {
    return a->id;
}

// returneaza numele contului
char *get_name(account *a) {
    return a->name;
}

//returneaza numele fisierului in care se salveaza informatiile despre un cont
char *get_file_name(account *a) {
    return a->file_name;
}

// returneaza tipul contului
char *get_type_account(account *a) {
    return a->type;
}

// returneaza numarul de tranzactii dintr-un cod
size_t get_size_list(account *a) {
    array_transaction *list = a->list;
    return get_size(list);
}

// returneaza tranzactia in functie de indexul acestuia
transaction *get_transaction_from_account(account *account1, size_t index) {
    array_transaction *list = account1->list;
    return get_transaction(list, index);
}

// adauga tranzactia in cont
void add_transaction_to_account(transaction *transaction1, account *account1) {
    array_transaction *list = account1->list;
    add_transaction(list, transaction1);
}

// elimina tranzactia in cont
void remove_transaction_to_account(transaction *transaction1, account *account1) {
    array_transaction *list = account1->list;
    remove_transaction(list, transaction1);
}

// elimina toate tranzactiile din cont
void delete_all_transactions_from_account(account *account1) {
    array_transaction *list = account1->list;
    transaction *transaction1;
    size_t n = get_size(list), i;
    for(i = 0; i < n; ++i) {
        transaction1 = get_transaction(list, 0);
        remove_transaction(list, transaction1);
    }
}

// returneaza o tranzactie in functie de id
transaction *search_transaction_from_account(account *account1, int id) {
    array_transaction *list = account1->list;
    return search_transaction(list, id);
}

// afiseaza cont
void print_account(account *account1) {
    printf("Name Account: %s\n", account1->name);
    printf("Type Account: %s\n", account1->type);
    printf("\n");
    print_array(account1->list);
}

// returneaza suma de bani din cont
float balance(account *account1) {
    float sum = 0;
    array_transaction *list = account1->list;
    transaction *a;
    size_t n = get_size(list), i;

    for(i = 0; i < n; ++i) {
        a = get_transaction(list, i);
        sum += get_sum(a);
    }

    return sum;
}

// informatia din fisier e adaugata in structura
void upload_account_transactions(account *account1) {
    upload_transactions(account1->list, account1->file_name);
}

// salveaza informatia de in cont in fisier
void save_account_transactions(account *account1) {
    save_transactions(account1->list, account1->file_name);
}