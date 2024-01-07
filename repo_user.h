#ifndef PROJECT_2_C_REPO_USER_H
#define PROJECT_2_C_REPO_USER_H

#include "user.h"

typedef struct {} array_users;

array_users *new_array_users();
void destroy_array_users(array_users *arrayUsers);
void add_user(array_users *arrayUsers, user *newUser);
void remove_user(array_users *arrayUsers, user *user1);
void upload_users(array_users *arrayUsers);
void save_users(array_users *arrayUsers);
size_t get_capacity_array_users(array_users *arrayUsers);
size_t get_size_array_users(array_users *arrayUsers);
user *get_user(array_users *arrayUsers, size_t index);
user *search_user(array_users *arrayUsers, char username[101]);

#endif //PROJECT_2_C_REPO_USER_H
