
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    int id;
    char name[30];
    int quantity;
    float price;
};

void addItem() {
    FILE *fp;
    struct item it;
    fp = fopen("inventory.txt", "a");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter item ID: ");
    scanf("%d", &it.id);
    printf("Enter item name: ");
    scanf("%s", it.name);
    printf("Enter quantity: ");
    scanf("%d", &it.quantity);
    printf("Enter price: ");
    scanf("%f", &it.price);

    fwrite(&it, sizeof(struct item), 1, fp);
    fclose(fp);

    printf("Item added successfully!\n");
}

void viewItems() {
    FILE *fp;
    struct item it;
    fp = fopen("inventory.txt", "r");

    if (fp == NULL) {
        printf("No items to display!\n");
        return;
    }

    printf("\n--- Inventory List ---\n");
    while (fread(&it, sizeof(struct item), 1, fp)) {
        printf("ID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n\n", it.id, it.name, it.quantity, it.price);
    }

    fclose(fp);
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Inventory Management ---\n");
        printf("1. Add Item\n");
        printf("2. View Items\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                viewItems();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Try again!\n");
        }
    }

    return 0;
}
