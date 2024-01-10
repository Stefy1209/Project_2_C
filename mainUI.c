#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "repo_user.h"
#include "UIUser.h"

// ruleaza UI-ul pentru logare
void logInUI(array_users *arrayUsers) {
    char username[101], password[101];
    size_t len;

    printf("Enter Username: ");
    fgets(username, sizeof(username), stdin);
    len = strlen(username);
    if(len > 0 && username[len - 1] == '\n')
        username[len - 1] = '\0';

    printf("Enter Password: ");
    fgets(password, sizeof(password), stdin);
    len = strlen(password);
    if(len > 0 && password[len - 1] == '\n')
        password[len - 1] = '\0';

    user *user1 = search_user(arrayUsers, username);

    if(user1 == NULL) {
        printf("\nInvalid username\n\n");
        return;
    }

    if(strcmp(password, get_password(user1)) == 0) {
        printf("\n");
        UIUser(user1);
        return;
    }

    printf("\nIncorrect password\n\n");
}

// ruleaza UI-ul pentru inregistrare
void signUpUI(array_users *arrayUsers) {
    char username[101], password[101], passwordAgain[101];
    size_t len;

    printf("Enter Username: ");
    fgets(username, sizeof(username), stdin);
    len = strlen(username);
    if(len > 0 && username[len - 1] == '\n')
        username[len - 1] = '\0';

    printf("Enter Password: ");
    fgets(password, sizeof(password), stdin);
    len = strlen(password);
    if(len > 0 && password[len - 1] == '\n')
        password[len - 1] = '\0';

    printf("Enter Password Again: ");
    fgets(passwordAgain, sizeof(passwordAgain), stdin);
    len = strlen(passwordAgain);
    if(len > 0 && passwordAgain[len - 1] == '\n')
        passwordAgain[len - 1] = '\0';

    user *user1;
    size_t n = get_size_array_users(arrayUsers), i;
    for(i = 0; i < n; ++i){
        user1 = get_user(arrayUsers, i);
        if(strcmp(username, get_username(user1)) == 0) {
            printf("\nUsername already used\n\n");
            return;
        }
    }

    len = strlen(username);
    for(i = 0; i < len; ++i) {
        if(strchr("\\ ", username[i])) {
            printf("\nThe username must not contain spaces or \\ \n\n");
            return;
        }
    }

    if(strcmp(password, passwordAgain) != 0) {
        printf("\nThe first password is not the same as the second one\n\n");
        return;
    }

    user *newUser = new_user(username, password);
    add_user(arrayUsers, newUser);
    printf("\n");
}

// ruleaza UI-ul principal
void UI() {
    array_users *arrayUsers = new_array_users();
    upload_users(arrayUsers);

    char command[101];
    size_t len;

    while (true) {
        printf(">>> ");
        fgets(command, sizeof(command), stdin);
        len = strlen(command);
        if(len > 0 && command[len - 1] == '\n')
            command[len - 1] = '\0';

        printf("\n");

        switch (command[0]) {
            case 'l': {
                if(strcmp(command, "log in") == 0) {
                    logInUI(arrayUsers);
                    break;
                }
            }
            case 's': {
                if(strcmp(command, "sign up") == 0) {
                    signUpUI(arrayUsers);
                    break;
                }
            }
            case 'e': {
                if(strcmp(command, "exit") == 0) {
                    save_users(arrayUsers);
                    destroy_array_users(arrayUsers);
                    return;
                }
            }
            default: {
                printf("Invalid Command\n\n");
                break;
            }
        }
    }
}
