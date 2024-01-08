#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "UIUser.h"
#include "user.h"
#include "UIAccount.h"

void UIPrintUser(user *user1) {
    printf("Name User: %s\n", get_username(user1));
    printf("Number Accounts: %zu\n", get_size_user(user1));

    size_t n = get_size_user(user1), i;
    account *account1;

    for(i = 0; i < n; ++i) {
        account1 = get_account(user1, i);

        printf("\n");
        printf("ID Account: %lu\n", get_id_account(account1));
        printf("Name Account: %s\n", get_name(account1));
        printf("Type Account: %s\n", get_type_account(account1));
    }

    printf("\n");
}

void UIAddAccount(user *user1) {
    char typeAccount[101][101] = {"salary", "credit", "retirement", "savings", "checking"};
    int nrTypes = 5, i;

    account *newAccount;
    size_t id, len;
    char file_name[101], name[101], type[101];

    printf("Enter Name Account: ");
    fgets(name, sizeof (name), stdin);
    len = strlen(name);
    if(len > 0 && name[len - 1] == '\n')
        name[len - 1] = '\0';

    printf("Enter Type Account: ");
    fgets(type, sizeof(type), stdin);
    len = strlen(type);
    if(len > 0 && type[len - 1] == '\n')
        type[len - 1] = '\0';

    printf("\n");

    account *account1;
    size_t n = get_size_user(user1);
    for(i = 0; i < n; ++i) {
        account1 = get_account(user1, i);
        if(strcmp(name, get_name(account1)) == 0) {
            printf("The name must be unique!\n\n");
            return;
        }
    }

    bool ok = false;
    for(i = 0; i < nrTypes; ++i) {
        if(strcmp(type, typeAccount[i]) == 0) {
            ok = true;
        }
    }

    if(ok == false) {
        printf("Type Invalid!\n\n");
        return;
    }

    strcpy(file_name, get_username(user1));
    strcat(file_name, "\\");
    strcat(file_name, name);

    id = 1;

    if(n != 0) {
        account *lastAccount = get_account(user1, n - 1);
        id = get_id_account(lastAccount) + 1;
    }

    newAccount = new_account(id, file_name, name, type);

    add_account(user1, newAccount);
}

void UIDeleteAccount(user *user1) {
    size_t id;

    printf("Enter ID Account: ");
    scanf("%lu", &id);
    printf("\n");
    while (getchar() != '\n');

    account *delAccount = search_account_by_id(user1, id);

    if(delAccount == NULL) {
        printf("Account with ID:%lu doesn't exist\n\n", id);
        return;
    }

    remove(get_file_name(delAccount));
    remove_account(user1, delAccount);
}

void UIUser(user *user1){
    upload_user(user1, get_username(user1));
    char command[101];
    while(true) {
        printf(">>> ");

        fgets(command, sizeof (command), stdin);
        size_t len = strlen(command);
        if(len > 0 && command[len - 1] == '\n')
            command[len - 1] = '\0';

        int i, n;
        n = strlen(command);
        for(i = 0; i < n; ++i)
            command[i] = tolower(command[i]);

        printf("\n");

        switch (command[0]) {
            case 'a': {
                if(strcmp(command, "add") == 0) {
                    UIAddAccount(user1);
                    break;
                }
            }
            case 'e': {
                if(strcmp(command, "exit") == 0) {
                    save_user(user1);
                    delete_all_accounts(user1);
                    return;
                }
            }
            case 'p': {
                if(strcmp(command, "print") == 0) {
                    UIPrintUser(user1);
                    break;
                }
            }
            case 'r': {
                if(strcmp(command, "remove") == 0) {
                    UIDeleteAccount(user1);
                    break;
                }
            }
            case 'g': {
                if(strcmp(command, "go to") == 0) {
                    size_t id;

                    printf("Enter ID Account: ");
                    scanf("%lu", &id);
                    printf("\n");

                    account *account1 = search_account_by_id(user1, id);

                    if(account1 == NULL) {
                        printf("Account with ID:%lu doesn't exist\n\n", id);
                        break;
                    }

                    while (getchar() != '\n');

                    UIAccount(account1);
                    break;
                }
            }
            default: {
                printf("Invalid Command!\n\n");
                break;
            }
        }
    }
}
