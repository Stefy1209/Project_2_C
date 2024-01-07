#ifndef PROJECT_2_C_TRANSACTION_H
#define PROJECT_2_C_TRANSACTION_H

#include <time.h>

typedef struct {} transaction;

transaction *new_transaction(unsigned int id, char description[10001], char type[101], time_t date, double sum);
unsigned int get_id(transaction *transaction1);
char *get_description(transaction *transaction);
char *get_type(transaction *transaction);
time_t get_date(transaction *transaction);
double get_sum(transaction *transaction);
void set_description(transaction *transaction, char description[]);
void set_type(transaction *transaction, char type[]);
void set_sum(transaction *transaction, double sum);
void print_transaction(transaction *transaction1);
void destroy_transaction(transaction *transaction);

#endif //PROJECT_2_C_TRANSACTION_H
