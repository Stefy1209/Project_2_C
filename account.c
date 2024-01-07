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

account *new_account(size_t id, char file_name [101], char name[101], char type[101]) {
    account *a = malloc(sizeof(account));

    a->id = id;
    strcpy(a->file_name, file_name);
    strcpy(a->name, name);
    strcpy(a->type, type);
    a->list = new_list();

    return a;
}

void destroy_account(account *a) {
    destroy_array(a->list);
    free(a);
}

size_t get_id_account(account *a) {
    return a->id;
}

char *get_name(account *a) {
    return a->name;
}

char *get_file_name(account *a) {
    return a->file_name;
}

char *get_type_account(account *a) {
    return a->type;
}

size_t get_size_list(account *a) {
    array_transaction *list = a->list;
    return get_size(list);
}

transaction *get_transaction_from_account(account *account1, size_t index) {
    array_transaction *list = account1->list;
    return get_transaction(list, index);
}

void add_transaction_to_account(transaction *transaction1, account *account1) {
    array_transaction *list = account1->list;
    add_transaction(list, transaction1);
}

void remove_transaction_to_account(transaction *transaction1, account *account1) {
    array_transaction *list = account1->list;
    remove_transaction(list, transaction1);
}

void delete_all_transactions_from_account(account *account1) {
    array_transaction *list = account1->list;
    transaction *transaction1;
    size_t n = get_size(list), i;
    for(i = 0; i < n; ++i) {
        transaction1 = get_transaction(list, 0);
        remove_transaction(list, transaction1);
    }
}

transaction *search_transaction_from_account(account *account1, int id) {
    array_transaction *list = account1->list;
    return search_transaction(list, id);
}

void print_account(account *account1) {
    printf("Name Account: %s\n", account1->name);
    printf("Type Account: %s\n", account1->type);
    printf("\n");
    print_array(account1->list);
}

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

void upload_account_transactions(account *account1) {
    upload_transactions(account1->list, account1->file_name);
}

void save_account_transactions(account *account1) {
    save_transactions(account1->list, account1->file_name);
}