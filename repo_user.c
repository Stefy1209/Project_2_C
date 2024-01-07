#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "user.h"

#define file_name "users"
#define write_mode "w"
#define read_mode "r"

typedef struct {
    size_t capacity;
    size_t size;
    user **list;
}array_users;

array_users *new_array_users() {
    array_users *newArrayUsers = malloc(sizeof(array_users));
    newArrayUsers->capacity = 1;
    newArrayUsers->size = 0;
    newArrayUsers->list = malloc(sizeof(user *));

    return newArrayUsers;
}

void destroy_array_users(array_users *arrayUsers) {
    size_t n = arrayUsers->size, i;
    for(i = 0; i < n; ++i) {
        destroy_user(arrayUsers->list[i]);
    }

    free(arrayUsers->list);

    free(arrayUsers);
}

void add_user(array_users *arrayUsers, user *newUser) {
    if(arrayUsers->size == arrayUsers->capacity) {
        user **temp = arrayUsers->list;
        arrayUsers->capacity <<= 1;
        arrayUsers->list = realloc(arrayUsers->list, arrayUsers->capacity * sizeof (user*));

        if(arrayUsers->list == NULL) {
            printf("Out of memory\n");
            arrayUsers->list = temp;
            return;
        }
    }
    arrayUsers->list[arrayUsers->size++] = newUser;
}

void remove_user(array_users *arrayUsers, user *user1) {
    size_t n = arrayUsers->size, i = 0;

    while(i < n && arrayUsers->list[i] != user1);
        ++i;

    if(i == n) {
        return;
    }

    destroy_user(arrayUsers->list[i]);

    for(; i+1 < n; ++i)
        arrayUsers->list[i] = arrayUsers->list[i+1];
}

void upload_users(array_users *arrayUsers) {
    FILE *fptr;

    fptr = fopen(file_name, read_mode);

    size_t n, i;

    fscanf(fptr, "%lu\n", &n);

    user *newUser;
    char userName[101], password[101];
    size_t len;

    for(i = 0; i < n; ++i) {
        fgets(userName, sizeof(userName), fptr);
        fgets(password, sizeof(password), fptr);

        len = strlen(userName);
        if (len > 0 && userName[len - 1] == '\n')
            userName[len - 1] = '\0';

        len = strlen(password);
        if(len > 0 && password[len - 1] == '\n')
            password[len - 1] = '\0';

        newUser = new_user(userName, password);

        add_user(arrayUsers, newUser);
    }

    fclose(fptr);
}

void save_users(array_users *arrayUsers) {
    FILE *fptr;

    fptr = fopen(file_name, write_mode);

    size_t n = arrayUsers->size, i;

    fprintf(fptr, "%lu\n", n);

    for(i = 0; i < n; ++i) {
        fprintf(fptr, "%s\n", get_username(arrayUsers->list[i]));
        fprintf(fptr, "%s\n", get_password(arrayUsers->list[i]));
    }

    fclose(fptr);
}

size_t get_capacity_array_users(array_users *arrayUsers) {
    return arrayUsers->capacity;
}

size_t get_size_array_users(array_users *arrayUsers) {
    return arrayUsers->size;
}

user *get_user(array_users *arrayUsers, size_t index) {
    return arrayUsers->list[index];
}

user *search_user(array_users *arrayUsers, char username[101]) {
    size_t n = arrayUsers->size, i = 0;

    while(i < n && (strcmp(get_username(arrayUsers->list[i]), username) != 0) )
        ++i;

    if(i == n)
        return NULL;

    return arrayUsers->list[i];
}
