#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

bool isValid(const int arr[], int length, int pos);
void remove_element(int arr[], int length, int pos);
void insert_element(int arr[], int length, int pos, int value);

int main() {
    int arr[SIZE] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int length = 10;
    int pos, value, choice;

    printf("Original array:\n");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Remove an element\n");
        printf("2. Insert an element\n");
        printf("3. Display the array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the index to remove (1 to %d): ", length - 1);
                scanf("%d", &pos);
                remove_element(arr, length, pos);
                break;

            case 2:
                printf("Enter the index to insert (0 to %d): ", length - 1);
                scanf("%d", &pos);
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert_element(arr, length, pos, value);
                break;

            case 3:
                printf("Current array:\n");
                for (int i = 0; i < length; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 4:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice. Please select 1, 2, 3, or 4.\n");
                break;
        }
    }

    return 0;
}

bool isValid(const int arr[], int length, int pos) {
    return (pos >= 0 && pos < length);
}

void remove_element(int arr[], int length, int pos) {
    if (!isValid(arr, length, pos)) {
        printf("Invalid index position\n");
        return;
    }
    for (int i = pos; i < length - 1; i++) {
        arr[i] = arr[i + 1];
    }
    printf("Element at index %d removed successfully.\n", pos);
}

void insert_element(int arr[], int length, int pos, int value) {
    if (!isValid(arr, length, pos)) {
        printf("Invalid index position\n");
        return;
    }

    for (int i = 0; i <  pos; i++) {
        arr[i] = arr[i + 1];
    }

    arr[pos] = value;

    printf("Element %d inserted at index %d successfully.\n", value, pos);
}
