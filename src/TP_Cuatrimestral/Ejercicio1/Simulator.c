/**
 * Simulator of the exercise 1.
 * @authors Tomas Iturralde, Diego Mancini
 */

#include <stdlib.h>
#include <stdio.h>
#include "Cart.h"
#include "Business.h"

void printCatalogue(Catalogue* catalogue1){
    for (int i = 0; i < catalogue1->amountOfItems; ++i) {
        printf("Item: %s, unitary price: %.2f" ,catalogue1->listItems[i]->name, catalogue1->listItems[i]->price);
    }
}

void printCart(Cart* cart1){
    for (int i = 0; i < cart1->amountOfItemsOnCart; ++i) {
        generateLineCart(cart1->itemsOnCart[i]);
    }
}

void addItemToTheCart(Catalogue* catalogue, Business* business, Cart* cart){
    char* name = malloc(sizeof(char) * 10);
    printf("Enter name: \n");
    scanf("%s", name);
    int units;
    printf("Enter units: \n");
    scanf("%d", &units);
    for (int i = 0; i < catalogue->amountOfItems; ++i) {
        if (name == catalogue->listItems[i]->name){
            addItemToCart(newLineCart(catalogue->listItems[i]->label->id,catalogue->listItems[i],units), cart);
            removeItemFromCatalogue(business, catalogue->listItems[i]->label->id);
        }
    }
}

void removeItemToTheCart(Business* business, Cart* cart){
    char* name = malloc(sizeof(char) * 10);
    printf("Enter name: \n");
    scanf("%s", name);
    int units;
    printf("Enter units: \n");
    scanf("%d", &units);
    for (int i = 0; i < cart->amountOfItemsOnCart; ++i) {
        if (name == cart->itemsOnCart[i]->item->name){
            for (int j = 0; j < units; ++j) {
                removeItemFromCart(cart, cart->itemsOnCart[i]->item->label->id);
                addItemToCatalogue(cart->itemsOnCart[i]->item, business);
            }
        }
    }
}

void makeManufacturerProduce(Manufacturer* manufacturer1){
    int units;
    printf("Enter units: \n");
    scanf("%d", &units);
    char* name = malloc(sizeof(char) * 10);
    printf("Enter name: \n");
    scanf("%s", name);
    char* model = malloc(sizeof(char) * 10);
    printf("Enter model: \n");
    scanf("%s", model);
    char* id = malloc(sizeof(char) * 10);
    printf("Enter id: \n");
    scanf("%s", id);
    float price;
    printf("Enter price: \n");
    scanf("%.2f", &price);
    for (int i = 0; i < units; ++i) {
        produceItem(name, model, price, newLabel(id, name), manufacturer1);
    }
}

int main(){
    Cart* cart = newCart("0001");
    Catalogue* catalogue = newCatalogue("1234", "catalogo");
    Business* business = newBusiness("El negocio", catalogue);
    addItemToCatalogue(newItem("item1", "model1", 15.00, newLabel("4151", "item1")), business);
    addItemToCatalogue(newItem("item2", "model2", 30.00, newLabel("4152", "item2")), business);
    addItemToCatalogue(newItem("item3", "model3", 406.00, newLabel("4153", "item3")), business);
    Supplier* supplier = newSupplier("supplier", "blabla", "dentro de algun lugar", "algun lugar", "UnTelefono", "www.LeSupplier.com");
    Manufacturer* manufacturer = newManufacturer("manufacturer", "blabla", "dentro de alguna zona", "alguna zona", "OtroTelefono", "www.LeManufacturer.com");
    addManufacturer(manufacturer, supplier);
    addSupplier(supplier, business);
    int units;
    produceItem("item4", "model4", 60.00, newLabel("4154", "item4"), manufacturer);
    produceItem("item5", "model5", 70.00, newLabel("4155", "item5"), manufacturer);
    produceItem("item6", "model6", 80.00, newLabel("4156", "item6"), manufacturer);
    int choice;
    while (choice != 8) {
        printf("\n\n-------------Welcome to the business, please choose an option\n");
        printf("1- Check catalogue\n");
        printf("2- Add Item to Cart\n");
        printf("3- Check Cart\n");
        printf("4- Remove item from Cart\n");
        printf("5- Print Ticket\n");
        printf("6- Make manufacturer produce items (admins only)\n");
        printf("7- Ask for supplies from a supplier (admins only)\n");
        printf("8- Exit\n");
        printf("\nCHOICE: ");

        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printCatalogue(business->catalogue);
                break;
            case 2:
                addItemToTheCart(catalogue, business, cart);
                break;
            case 3:
                printCart(cart);
                break;
            case 4:
                removeItemToTheCart(business, cart);
                break;
            case 5:
                printTicket(produceTicket(cart));
                break;
            case 6:
                makeManufacturerProduce(manufacturer);
                break;
            case 7:
                printf("Enter units: \n");
                scanf("%d", &units);
                askForSupplies(supplier->name, business, manufacturer->name, units);
                break;
            case 8:
                destroyBusiness(business);
                destroyCart(cart);
                exit(0);
            default:
                printf("Please choose a value from 1 to 8!\n");
        }
    }

    return 0;
}