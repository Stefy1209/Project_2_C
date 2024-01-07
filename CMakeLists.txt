cmake_minimum_required(VERSION 3.26)
project(Project_2_C C)

set(CMAKE_C_STANDARD 23)

add_executable(Project_2_C main.c
        transaction.c
        transaction.h
        repo_transaction.h
        repo_transaction.c
        service_transaction.h
        service_transaction.c
        account.h
        account.c
        UIAccount.h
        UIAccount.c
        user.h
        user.c
        UIUser.h
        UIUser.c
        repo_user.h
        repo_user.c
        mainUI.h
        mainUI.c
)
