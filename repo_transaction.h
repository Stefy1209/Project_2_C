#ifndef PROJECT_2_C_REPO_TRANSACTION_H
#define PROJECT_2_C_REPO_TRANSACTION_H

#include "transaction.h"

typedef struct {} array_transaction;

array_transaction *new_list();
size_t get_size(array_transaction *list);
transaction *get_transaction(array_transaction *list, size_t index);
void add_transaction(array_transaction *list, transaction *transaction1);
void remove_transaction(array_transaction *list, transaction *transaction1);
void delete_array(array_transaction *arrayTransaction);
transaction *search_transaction(const array_transaction *arrayTransaction, int id);
void destroy_array(array_transaction *list);
void print_array(array_transaction *list);

#endif //PROJECT_2_C_REPO_TRANSACTION_H
