#include <stdio.h>
#include <string.h>
#include "transaction.h"
#include "repo_transaction.h"

#define read_mode "r"
#define write_mode "w"

//incarca din fisier tranzactiile
void upload_transactions(array_transaction *list, char file_in[101]) {
    FILE *fptr;

    fptr = fopen(file_in, read_mode);

    size_t n, i;

    int id;
    char description[10001];
    char type[101];
    time_t date;
    float sum;

    transaction *a;

    if(fptr == NULL) {
        fptr = fopen(file_in, write_mode);
        fprintf(fptr, "0\n");
        fclose(fptr);

        return;
    }

    fscanf(fptr, "%zu\n", &n);

    for(i = 0; i < n; ++i) {
        fscanf(fptr, "%d\n", &id);
        fgets(description, 10001, fptr);
        fgets(type, 101, fptr);
        fscanf(fptr, "%ld\n", &date);
        fscanf(fptr, "%f\n", &sum);

        if(strlen(description) > 0)
            description[strlen(description) - 1] = '\0';

        if(strlen(type) > 0)
            type[strlen(type) - 1] = '\0';

        a = new_transaction(id, description, type, date, sum);
        add_transaction(list, a);
    }

    fclose(fptr);
}

//salveaza in fisier tranzactiile
void save_transactions(array_transaction *list, char file_out[101]) {
    FILE *fptr;

    fptr = fopen(file_out, write_mode);

    size_t n = get_size(list), i;
    unsigned int id;
    char description[10001];
    char type[101];
    time_t date;
    float sum;
    transaction *a;

    fprintf(fptr, "%lu\n", n);
    for(i = 0; i < n; ++i) {
        a = get_transaction(list, i);

        id = get_id(a);
        strcpy(description, get_description(a));
        strcpy(type, get_type(a));
        date = get_date(a);
        sum = get_sum(a);

        fprintf(fptr, "%lu\n", id);
        fprintf(fptr, "%s\n", description);
        fprintf(fptr, "%s\n", type);
        fprintf(fptr, "%lu\n", date);
        fprintf(fptr, "%.2f\n", sum);
    }

    fclose(fptr);
}