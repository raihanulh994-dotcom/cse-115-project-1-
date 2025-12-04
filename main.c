#include <stdio.h>

/* ================================
   CONSTANTS & BASIC DATA TYPES
   ================================ */

#define MAX_CUSTOMERS 100
#define NAME_SIZE     30

/* ================================
   STRUCTURE (Customer)
   ================================ */

typedef struct {
    int  id;
    char name[NAME_SIZE];  // char array (string)
    float balance;
} Customer;

/* ================================
   GLOBAL ARRAY OF CUSTOMERS
   ================================ */

Customer customers[MAX_CUSTOMERS];  // array of structures
int customerCount = 0;              // how many customers are stored

/* ================================
   FUNCTION PROTOTYPES
   ================================ */

void showMenu(void);
void createCustomer(void);
void depositMoney(void);
void withdrawMoney(void);
void showCustomer(void);
void listAllCustomers(void);
int  findCustomerIndex(int id);

/* ================================
   MAIN FUNCTION
   ================================ */

int main(void)
{
    int choice;

    do {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            createCustomer();
            break;
        case 2:
            depositMoney();
            break;
        case 3:
            withdrawMoney();
            break;
        case 4:
            showCustomer();
            break;
        case 5:
            listAllCustomers();
            break;
        case 0:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }

        printf("\n");

    } while (choice != 0);

    return 0;
}

/* ================================
   MENU (BASIC OUTPUT)
   ================================ */

void showMenu(void)
{
    printf("========== SIMPLE BANK SYSTEM ==========\n");
    printf("1. Create new customer account\n");
    printf("2. Deposit money\n");
    printf("3. Withdraw money\n");
    printf("4. Show single customer\n");
    printf("5. List all customers\n");
    printf("0. Exit\n");
}

/* ================================
   CREATE CUSTOMER (STRUCT + ARRAY)
   ================================ */

void createCustomer(void)
{
    if (customerCount >= MAX_CUSTOMERS) {
        printf("Cannot add more customers.\n");
        return;
    }

    Customer c;

    printf("Enter customer ID (integer): ");
    scanf("%d", &c.id);

    printf("Enter customer name (one word): ");
    scanf("%s", c.name);   // simple: no spaces

    printf("Enter starting balance: ");
    scanf("%f", &c.balance);

    customers[customerCount] = c;  // store in array
    customerCount++;

    printf("Customer created successfully.\n");
}

/* ================================
   FIND CUSTOMER (LOOP + IF)
   ================================ */

int findCustomerIndex(int id)
{
    int i;
    for (i = 0; i < customerCount; i++) {
        if (customers[i].id == id) {
            return i;      // return index if found
        }
    }
    return -1;             // not found
}

/* ================================
   DEPOSIT MONEY
   ================================ */

void depositMoney(void)
{
    int id, index;
    float amount;

    printf("Enter customer ID: ");
    scanf("%d", &id);

    index = findCustomerIndex(id);

    if (index == -1) {
        printf("Customer not found.\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Amount must be positive.\n");
        return;
    }

    customers[index].balance += amount;

    printf("Deposit successful. New balance = %.2f\n",
           customers[index].balance);
}

/* ================================
   WITHDRAW MONEY
   ================================ */

void withdrawMoney(void)
{
    int id, index;
    float amount;

    printf("Enter customer ID: ");
    scanf("%d", &id);

    index = findCustomerIndex(id);

    if (index == -1) {
        printf("Customer not found.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Amount must be positive.\n");
        return;
    }

    if (amount > customers[index].balance) {
        printf("Not enough balance.\n");
        return;
    }

    customers[index].balance -= amount;

    printf("Withdrawal successful. New balance = %.2f\n",
           customers[index].balance);
}

/* ================================
   SHOW SINGLE CUSTOMER
   ================================ */

void showCustomer(void)
{
    int id, index;

    printf("Enter customer ID: ");
    scanf("%d", &id);

    index = findCustomerIndex(id);

    if (index == -1) {
        printf("Customer not found.\n");
        return;
    }

    printf("\n--- Customer Info ---\n");
    printf("ID      : %d\n", customers[index].id);
    printf("Name    : %s\n", customers[index].name);
    printf("Balance : %.2f\n", customers[index].balance);
}

/* ================================
   LIST ALL CUSTOMERS (ARRAY LOOP)
   ================================ */

void listAllCustomers(void)
{
    int i;

    if (customerCount == 0) {
        printf("No customers in the system.\n");
        return;
    }

    printf("\nID\tName\t\tBalance\n");
    printf("---------------------------------\n");

    for (i = 0; i < customerCount; i++) {
        printf("%d\t%-10s\t%.2f\n",
               customers[i].id,
               customers[i].name,
               customers[i].balance);
    }
}
