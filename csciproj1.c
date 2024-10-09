#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define esp_bean_req 8
#define esp_water_req 30
#define esp_price 3.5

#define cap_bean_req 8
#define cap_water_req 30
#define cap_milk_req 70
#define cap_price 4.5

#define moc_bean_req 8
#define moc_water_req 39
#define moc_milk_req 160
#define moc_choco_req 30
#define moc_price 5.5

#define bean_low 15
#define water_low 10
#define milk_low 10
#define choco_low 10

float beans = 100;
float water = 1000;
float milk = 1000;
float chocolate = 100;
float total_amount = 0.0;

void main_menu();
void coffee_order();
int ingredient_check(int coffee_choice);
void ingredients_used(int coffee_choice);
void payment_process(double amount_due);

int main() {
    while (1) {
        main_menu();
    }
    return 0;
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
            exit(0);
        default:
            printf("Invalid option. Please try again.\n");
    }
}

void coffee_order() {
    int coffee_choice;
    double price;
    int confirmation;

    while (1) {
        printf("\nAvailable Coffee Types\n");

        printf("Select your coffee (0 to cancel): ");
        scanf("%d", &coffee_choice);

        if (coffee_choice == 0) {
            printf("Order canceled.\n");
            return;
        }

        if (coffee_choice == 1 && ingredient_check(1)) {
            price = esp_price;
            printf("You selected Espresso (AED %.2f). Confirm? (1 for Yes, 0 for No): ", price);
        } else if (coffee_choice == 2 && ingredient_check(2)) {
            price = cap_price;
            printf("You selected Cappuccino (AED %.2f). Confirm? (1 for Yes, 0 for No): ", price);
        } else if (coffee_choice == 3 && ingredient_check(3)) {
            price = moc_price;
            printf("You selected Mocha (AED %.2f). Confirm? (1 for Yes, 0 for No): ", price);
        } else {
            printf("Invalid selection or insufficient ingredients. Please choose again.\n");
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
    if (coffee_choice == 1) {
        return (beans >= esp_bean_req && water >= esp_water_req);
    } else if (coffee_choice == 2) {
        return (beans >= cap_bean_req && water >= cap_water_req && milk >= cap_milk_req);
    } else if (coffee_choice == 3) {
        return (beans >= moc_bean_req && water >= moc_water_req && milk >= moc_milk_req && chocolate >= moc_choco_req);
    }
    return 0;
}

void ingredients_used(int coffee_choice) {
    if (coffee_choice == 1) {
        beans -= esp_bean_req;
        water -= esp_water_req;
    } else if (coffee_choice == 2) {
        beans -= cap_bean_req;
        water -= cap_water_req;
        milk -= cap_milk_req;
    } else if (coffee_choice == 3) {
        beans -= moc_bean_req;
        water -= moc_water_req;
        milk -= moc_milk_req;
        chocolate -= moc_choco_req;
    }

    if (beans <= bean_low) {
        printf("Alert: Coffee beans running low!\n");
    }
    if (water <= water_low) {
        printf("Alert: Water running low!\n");
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
