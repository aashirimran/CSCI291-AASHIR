#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define esp_bean_req 8
#define esp_water_req 30
#define cap_bean_req 8
#define cap_water_req 30
#define cap_milk_req 70
#define moc_bean_req 8
#define moc_water_req 39
#define moc_milk_req 160
#define moc_choco_req 30
#define bean_low 15
#define water_low 10
#define milk_low 10
#define choco_low 10

float beans = 100;
float water = 1000;
float milk = 1000;
float chocolate = 100;
float total_amount = 0.0;

float esp_price = 3.5;
float cap_price = 4.5;
float moc_price = 5.5;

void coffee_order();
int ingredient_check(int coffee_choice);
void ingredients_used(int coffee_choice);
void payment_process(double amount_due);
void main_menu();

int main() {
    while (1) {
        main_menu();
    }
    return 0;
}

void coffee_order() {
    int coffee_choice;
    double price;
    int confirmation;

    while (1) {
        printf("\nAvailable Coffee Types\n");
        printf("1. Espresso (AED %.2f)\n", esp_price);
        printf("2. Cappuccino (AED %.2f)\n", cap_price);
        printf("3. Mocha (AED %.2f)\n", moc_price);
        printf("Select your coffee (0 to cancel): ");
        scanf("%d", &coffee_choice);

        if (coffee_choice == 0) {
            printf("Order canceled.\n");
            return;
        }

        switch (coffee_choice) {
            case 1:
                if (ingredient_check(1)) {
                    price = esp_price;
                    printf("You selected Espresso (AED %.2f). Confirm? (1 for Yes, 0 for No): ", price);
                } else {
                    printf("Espresso is unavailable due to insufficient ingredients.\n");
                    continue;
                }
                break;
            case 2:
                if (ingredient_check(2)) {
                    price = cap_price;
                    printf("You selected Cappuccino (AED %.2f). Confirm? (1 for Yes, 0 for No): ", price);
                } else {
                    printf("Cappuccino is unavailable due to insufficient ingredients.\n");
                    continue;
                }
                break;
            case 3:
                if (ingredient_check(3)) {
                    price = moc_price;
                    printf("You selected Mocha (AED %.2f). Confirm? (1 for Yes, 0 for No): ", price);
                } else {
                    printf("Mocha is unavailable due to insufficient ingredients.\n");
                    continue;
                }
                break;
            default:
                printf("Invalid selection. Please choose again.\n");
                continue;
        }

        scanf("%d", &confirmation);
        if (confirmation == 1) {
            payment_process(price);
            ingredients_used(coffee_choice);
            printf("Enjoy your coffee!\n");
            printf("You paid AED %.2f for your order.\n", price);
            break;
        } else {
            printf("Order not confirmed. Please select again.\n");
        }
    }
}


int ingredient_check(int coffee_choice) {
    switch (coffee_choice) {
        case 1:
            return (beans >= esp_bean_req && water >= esp_water_req);
        case 2:
            return (beans >= cap_bean_req && water >= cap_water_req && milk >= cap_milk_req);
        case 3:
            return (beans >= moc_bean_req && water >= moc_water_req && milk >= moc_milk_req && chocolate >= moc_choco_req);
        default:
            return 0; 
    }
}

void ingredients_used(int coffee_choice) {
    switch (coffee_choice) {
        case 1:
            beans -= esp_bean_req;
            water -= esp_water_req;
            break;
        case 2:
            beans -= cap_bean_req;
            water -= cap_water_req;
            milk -= cap_milk_req;
            break;
        case 3:
            beans -= moc_bean_req;
            water -= moc_water_req;
            milk -= moc_milk_req;
            chocolate -= moc_choco_req;
            break;
        default:
            printf("Invalid coffee choice.\n");
            return; 
    }

    if (beans <= bean_low) {
        printf("Alert: Coffee beans running low!\n");
    }
    if (water <= water_low) {
        printf("Alert: Water running low!\n");
    }
    if (milk <= milk_low) {
        printf("Alert: Milk running low!\n");
    }
    if (chocolate <= choco_low) {
        printf("Alert: Chocolate syrup running low!\n");
    }
}


void payment_process(double amount_due) {
    double total_payment = 0.0;
    double coin;

    while (total_payment < amount_due) {
        printf("Insert coin (1 AED or 0.5 AED): ");
        scanf("%lf", &coin);

        if (coin == 1.0 || coin == 0.5) {
            total_payment += coin;
            printf("Current payment: AED %.2f\n", total_payment);
        } else {
            printf("Invalid coin. Please collect and insert a valid one.\n");
        }
    }
}

void main_menu() {
    int choice;

    printf("\nWelcome to the Coffee Machine\n");
    printf("1. Order Coffee\n");
    printf("2. Exit\n");
    printf("Select an option: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            coffee_order();
            break;
        case 2:
            printf("Thank you for using the Coffee Machine. Goodbye!\n");
            break;
        default:
            printf("Invalid option. Please try again.\n");
    }
}
