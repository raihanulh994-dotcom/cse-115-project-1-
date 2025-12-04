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

