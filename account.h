#ifndef PROJECT_2_C_ACCOUNT_H
#define PROJECT_2_C_ACCOUNT_H

#include "transaction.h"

typedef struct {} account;

account *new_account(size_t id, char file_name [101], char name[101], char type[101]);
void destroy_account(account *a);
size_t get_id_account(account *a);
char *get_name(account *a);
char *get_file_name(account *a);
char *get_type_account(account *a);
transaction *get_transaction_from_account(account *account1, size_t index);
size_t get_size_list(account *a);
void add_transaction_to_account(transaction *transaction1, account *account1);
void remove_transaction_to_account(transaction *transaction1, account *account1);
void delete_all_transactions_from_account(account *account1);
transaction *search_transaction_from_account(account *account1, int id);
void print_account(account *account1);
float balance(account *account1);
void upload_account_transactions(account *account1);
void save_account_transactions(account *account1);

#endif //PROJECT_2_C_ACCOUNT_H
