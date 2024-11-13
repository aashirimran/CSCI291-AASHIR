#include <stdio.h>

#define SIZE 7

int main() {
    int balance = 1000;
    int transactions[SIZE] = {200, -150, -500, -400, -50, -200, 300};
    int tobeprocessed[SIZE];
    int processed_count = 0;

    for (int i = 0; i < SIZE; i++) {
        int current_transaction = transactions[i];

        if (balance == 0) {
            printf("Balance reached zero. No further transactions will be processed.\n");
            break;
        } else if (balance + current_transaction < 0) {
            printf("Invalid transaction: %d (Insufficient balance)\n", current_transaction);
            tobeprocessed[processed_count++] = current_transaction;
        } else {
            balance += current_transaction;
        }
    }

    printf("Final balance: %d AED\n", balance);

    if (processed_count > 0) {
        printf("Transactions that could not be processed:\n");
        for (int i = 0; i < processed_count; i++) {
            printf("%d ", tobeprocessed[i]);
        }
    }

    return 0;
}
