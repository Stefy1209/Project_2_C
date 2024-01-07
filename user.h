#ifndef PROJECT_2_C_USER_H
#define PROJECT_2_C_USER_H

#include "account.h"

typedef struct {} user;

user *new_user(char username[101], char password[101]);
void destroy_user(user *user1);
char *get_username(user *user1);
char *get_password(user *user1);
account *get_account(user *user1, size_t index);
size_t get_size_user(user *user1);
void add_account(user *user1, account *account1);
void remove_account(user *user1, account *account1);
account *search_account(user *user1, char name[101]);
account *search_account_by_id(user *user1, size_t id);
void upload_user(user *user1, char file_name[101]);
void save_user(user *user1);
void print_user(user *user1);
void delete_all_accounts(user *user1);

#endif //PROJECT_2_C_USER_H
