#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "account.h"

#define read_mode "r"
#define write_mode "w"

typedef struct {
    char username[101];
    char password[101];
    size_t capacity;
    size_t size;
    account **list_accounts;
}user;

user *new_user(char username[101], char password[101]) {
    user *new_user = malloc(sizeof (user));
    strcpy(new_user->username, username);
    strcpy(new_user->password, password);
    new_user->capacity = 1;
    new_user->size = 0;
    new_user->list_accounts = malloc(sizeof(account*));

    return new_user;
}

void destroy_user(user *user1) {
    size_t n = user1->size, i;
    for(i = 0; i < n; ++i)
        destroy_account(user1->list_accounts[i]);

    free(user1->list_accounts);
    free(user1);
}

char *get_username(user *user1) {
    return user1->username;
}

char *get_password(user *user1) {
    return user1->password;
}

account *get_account(user *user1, size_t index) {
    return user1->list_accounts[index];
}

size_t get_size_user(user *user1) {
    return user1->size;
}

void add_account(user *user1, account *account1) {
    if(user1->size == user1->capacity) {
        account **temp = user1->list_accounts;
        user1->capacity <<= 1;
        user1->list_accounts = realloc(user1->list_accounts, user1->capacity * sizeof(account *));

        if(user1->list_accounts == NULL) {
            printf("Out of memory\n");
            user1->list_accounts = temp;
            return;
        }
    }
    user1->list_accounts[user1->size++] = account1;
}

void remove_account(user *user1, account *account1) {
    size_t n = user1->size, i = 0;
    while(i < n && user1->list_accounts[i] != account1)
        ++i;

    if(i == n) {
        printf("Account not found!\n");
        return;
    }

    destroy_account(user1->list_accounts[i]);

    for(;i+1 < n; i++) {
        user1->list_accounts[i] = user1->list_accounts[i+1];
    }

    user1->size--;
}

void delete_all_accounts(user *user1) {
    size_t n = user1->size, i;
    account *account1;

    for(i = 0; i < n; ++i) {
        account1 = get_account(user1, 0);
        remove_account(user1, account1);
    }
}

account *search_account(user *user1, char name[101]) {
    size_t n = user1->size, i;
    for(i = 0; i < n; ++i){
        if(strcmp(name, get_name(user1->list_accounts[i])) == 0) {
            return user1->list_accounts[i];
        }
    }

    return NULL;
}

account *search_account_by_id(user *user1, size_t id) {
    size_t n = user1->size, i;
    for(i = 0; i < n; ++i){
        if(id == get_id_account(user1->list_accounts[i]))
            return user1->list_accounts[i];
    }

    return NULL;
}

void upload_user(user *user1, char file_name[101]) {
    FILE *fptr;

    fptr = fopen(file_name, read_mode);

    if(fptr == NULL){
        fptr = fopen(file_name, write_mode);

        fprintf(fptr, "0\n");
        fclose(fptr);

        return;
    }

    size_t n, i, id;

    char file_name_account[101], name_account[101], type[101];

    fscanf(fptr, "%zu\n", &n);

    account *newAccount;
    for(i = 0; i < n; ++i) {
        fscanf(fptr, "%lu\n", &id);
        fgets(file_name_account, 101, fptr);
        fgets(name_account, 101, fptr);
        fgets(type, 101, fptr);

        file_name_account[strlen(file_name_account) - 1] = '\0';
        name_account[strlen(name_account) - 1] = '\0';
        type[strlen(type) - 1] = '\0';

        newAccount = new_account(id, file_name_account, name_account, type);
        add_account(user1, newAccount);
    }

    fclose(fptr);
}

void save_user(user *user1) {
    FILE *fptr;

    fptr = fopen(user1->username, write_mode);

    size_t n = user1->size, i;
    char file_name_account[101], name_account[101],type[101];
    account *account1;

    fprintf(fptr, "%lu\n", n);
    for(i = 0; i < n; ++i) {
        account1 = user1->list_accounts[i];

        strcpy(file_name_account, get_file_name(account1));
        strcpy(name_account, get_name(account1));
        strcpy(type, get_type_account(account1));

        fprintf(fptr, "%zu\n", get_id_account(account1));
        fprintf(fptr, "%s\n", file_name_account);
        fprintf(fptr, "%s\n", name_account);
        fprintf(fptr, "%s\n", type);
    }

    fclose(fptr);
}

void print_user(user *user1) {
    printf("Username: %s\n", user1->username);
    printf("Password: %s\n", user1->password);
}