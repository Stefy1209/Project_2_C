#include <stdio.h>
#include <stdlib.h>
#include "transaction.h"

//structura de tip lista tranzactii care contine: capacitatea maxima, size/numarul de tranzactii inregistrate, lista de tranzactii
typedef struct {
    size_t capacity;
    size_t size;
    transaction **array;
}array_transaction;

//creaza structura de tip lista tranzactii
array_transaction *new_list() {
    array_transaction *list = malloc(sizeof (array_transaction));
    list->capacity = 1;
    list->size = 0;
    list->array = malloc(sizeof(transaction*));

    return list;
}

//returneaza numarul de tranzactii inregistrate
size_t get_size(array_transaction *list) {
    return list->size;
}

//returneaza tranzactia in functie de ordinea in care a fost inregistrata
transaction *get_transaction(array_transaction *list, size_t index) {
    return list->array[index];
}

//adauga tranzactie in lista
void add_transaction(array_transaction *list, transaction *transaction1) {
    if(list->capacity == list->size) {
        transaction **temp = list->array;
        list->capacity <<= 1;
        list->array = realloc(list->array, list->capacity*sizeof (transaction*));

        if(!list->array) {
            printf("Out of memory\n");
            list->array = temp;
            return;
        }
    }
    list->array[list->size++] = transaction1;
}

//elimina tranzactie
void remove_transaction(array_transaction *list, transaction *transaction1) {
    size_t n = list->size, i = 0;
    while(i < n && list->array[i] != transaction1)
        ++i;

    if(i == n)
        return;

    free(list->array[i]);

    for(; i+1 < n; ++i)
        list->array[i] = list->array[i+1];

    list->size --;
}

//elimina toate tranzactiile
void delete_array(array_transaction *arrayTransaction) {
    size_t n = arrayTransaction->size, i;
    for(i = 0; i < n; ++i)
        destroy_transaction(arrayTransaction->array[i]);

    arrayTransaction->size = 0;
}

//returneaza tranzactia dupa id-ul unic
transaction *search_transaction(const array_transaction *arrayTransaction, int id) {
    size_t n = arrayTransaction->size, i;
    for(i = 0; i < n; ++i)
        if(get_id(arrayTransaction->array[i]) == id)
            return arrayTransaction->array[i];

    return NULL;
}

//distruge lista de tranzactii
void destroy_array(array_transaction *list) {
    size_t n = list->size, i;
    for(i = 0; i < n; ++i)
        free(list->array[i]);
    free(list->array);
    free(list);
}

//afiseaza lista de tranzacatii
void print_array(array_transaction *list) {
    size_t n = list->size, i;

    if(n == 0){
        printf("There are no transactions\n\n");
        return;
    }

    for(i = 0; i < n; ++i) {
        print_transaction(list->array[i]);
        printf("\n");
    }
}