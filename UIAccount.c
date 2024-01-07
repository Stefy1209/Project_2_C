#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "account.h"

void UIAddTransaction(account *account1) {
    char description[10001];
    float sum;

    printf("Enter description: ");
    fgets(description, sizeof (description), stdin);
    size_t len = strlen(description);
    if (len > 0 && description[len - 1] == '\n') {
        description[len - 1] = '\0';
    }

    printf("Enter Sum: ");
    scanf("%f", &sum);

    size_t n = get_size_list(account1), id = 1;

    if(n != 0){
        transaction *transaction1 = get_transaction_from_account(account1, n-1);
        id = get_id(transaction1) + 1;
    }

    add_transaction_to_account(
            new_transaction(
                    id,
                    description,
                    get_type_account(account1),
                    time(NULL),
                    sum
                    ),
            account1
            );
}

void UIRemoveTransaction(account *account1) {
    size_t id;

    printf("Enter ID Transaction: ");
    scanf("%lu", &id);

    transaction *transaction1 = search_transaction_from_account(account1, id);

    remove_transaction_to_account(transaction1, account1);
}

void UIAccount(account *account1) {
    upload_account_transactions(account1);
    char command[101];
    while(true) {
        printf(">>> ");

        fgets(command, sizeof (command), stdin);
        size_t len = strlen(command);
        if (len > 0 && command[len - 1] == '\n') {
            command[len - 1] = '\0';
        }

        int i, n;
        n = strlen(command);
        for(i = 0; i < n; ++i)
            command[i] = tolower(command[i]);

        printf("\n");

        switch (command[0]) {
            case 'e': {
                if(strcmp(command, "exit") == 0) {
                    save_account_transactions(account1);
                    delete_all_transactions_from_account(account1);
                    return;
                }
            }
            case 'p': {
                if(strcmp(command, "print") == 0) {
                    print_account(account1);
                    break;
                }
            }
            case 'a': {
                if(strcmp(command, "add") == 0) {
                    UIAddTransaction(account1);
                    printf("\n");
                    while (getchar() != '\n');
                    break;
                }
            }
            case 'b': {
                if(strcmp(command, "balance") == 0) {
                    printf("Balance: %.2f\n\n", balance(account1));
                    break;
                }
            }
            case 'r': {
                if(strcmp(command, "remove") == 0){
                    UIRemoveTransaction(account1);
                    printf("\n");
                    while (getchar() != '\n');
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