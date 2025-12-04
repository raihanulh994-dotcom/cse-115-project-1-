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

