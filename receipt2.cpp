
#include <stdio.h>
#include <time.h>


int main()
{
    // Variable declarations
    const int MAX_MEALS=100;
    int choice;
    int invoiceNumber = 1;
    int totalMealsSold = 0;
    int mealCount;
    int mealNumber[MAX_MEALS];
    int quantity[MAX_MEALS];
    int i;

    double unitPrice[MAX_MEALS];
    double subtotal, gst, qst, total;
    double totalSalesAmount = 0;

    const double GST_RATE = 0.05;
    const double QST_RATE = 0.09975;

    char phone[20];
    char address[100];
    char pizzaType[MAX_MEALS];
    char payment;
    char another;

    char dateTime[50];
    time_t now;

    // Welcome message
    printf("====================================\n");
    printf("       WELCOME TO PIZZA POUR TOUS\n");
    printf("====================================\n");
    printf("This program allows you to:\n");
    printf("1. Bill a customer order\n");
    printf("2. Display total meals sold and sales\n");
    printf("3. Quit the program\n");

    // Main menu
    do
    {
        printf("\n========== MAIN MENU ==========\n");
        printf("1. Bill an order\n");
        printf("2. Display sales information\n");
        printf("3. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Menu validation
        while (choice < 1 || choice > 3)
        {
            printf("Invalid choice! Enter 1, 2 or 3: ");
            scanf("%d", &choice);
        }

        switch (choice)
        {
            // OPTION 1: BILL AN ORDER
            case 1:

                subtotal = 0;
                mealCount = 0;

                printf("\n========== CUSTOMER INFORMATION ==========\n");

                printf("Enter customer phone number: ");
                scanf("%19s", phone);

                printf("Enter customer address: ");
                scanf(" %99[^\n]", address);

                // Meal selection
                do
                {
                    i = mealCount;

                    printf("\nAvailable meals: 3, 4, 8, 9, 13, 14\n");
                    printf("Enter meal number: ");
                    scanf("%d", &mealNumber[i]);

                    // Meal number validation
                    while (mealNumber[i] != 3 &&
                           mealNumber[i] != 4 &&
                           mealNumber[i] != 8 &&
                           mealNumber[i] != 9 &&
                           mealNumber[i] != 13 &&
                           mealNumber[i] != 14)
                    {
                        printf("Invalid meal number! Try again: ");
                        scanf("%d", &mealNumber[i]);
                    }

                    // Pizza type validation
                    printf("\nPizza types:\n");
                    printf("V = Vegetarian\n");
                    printf("F = Cheese\n");
                    printf("T = All-dressed\n");
                    printf("E = Spinach\n");
                    printf("M = Seafood\n");

                    printf("Enter pizza type: ");
                    scanf(" %c", &pizzaType[i]);

                    while (pizzaType[i] != 'v' &&
                           pizzaType[i] != 'V' &&
                           pizzaType[i] != 'f' &&
                           pizzaType[i] != 'F' &&
                           pizzaType[i] != 't' &&
                           pizzaType[i] != 'T' &&
                           pizzaType[i] != 'e' &&
                           pizzaType[i] != 'E' &&
                           pizzaType[i] != 'm' &&
                           pizzaType[i] != 'M')
                    {
                        printf("Invalid pizza type! Try again: ");
                        scanf(" %c", &pizzaType[i]);
                    }

                    // Quantity validation
                    printf("Enter quantity: ");
                    scanf("%d", &quantity[i]);

                    while (quantity[i] <= 0)
                    {
                        printf("Quantity must be greater than zero: ");
                        scanf("%d", &quantity[i]);
                    }

                    // Assign meal price
                    switch (mealNumber[i])
                    {
                        case 3:
                            unitPrice[i] = 20.49;
                            break;

                        case 4:
                            unitPrice[i] = 21.99;
                            break;

                        case 8:
                            unitPrice[i] = 24.49;
                            break;

                        case 9:
                            unitPrice[i] = 25.99;
                            break;

                        case 13:
                            unitPrice[i] = 28.49;
                            break;

                        case 14:
                            unitPrice[i] = 29.99;
                            break;
                    }

                    // Calculate subtotal
                    subtotal += unitPrice[i] * quantity[i];

                    mealCount++;

                    // Ask for another meal
                    if (mealCount < MAX_MEALS)
                    {
                        printf("\nDo you want to add another meal? (O/N): ");
                        scanf(" %c", &another);

                        while (another != 'o' && another != 'O' &&
                               another != 'n' && another != 'N')
                        {
                            printf("Invalid answer! Enter O or N: ");
                            scanf(" %c", &another);
                        }
                    }
                    else
                    {
                        printf("\nMaximum number of meal entries reached.\n");
                        another = 'n';
                    }

                } while (another == 'o' || another == 'O');

                // Payment validation
                printf("\nPayment methods:\n");
                printf("C = Cash\n");
                printf("D = Debit\n");
                printf("R = Credit\n");

                printf("Enter payment method: ");
                scanf(" %c", &payment);

                while (payment != 'c' && payment != 'C' &&
                       payment != 'd' && payment != 'D' &&
                       payment != 'r' && payment != 'R')
                {
                    printf("Invalid payment method! Try again: ");
                    scanf(" %c", &payment);
                }

                // Invoice calculations
                gst = subtotal * GST_RATE;
                qst = subtotal * QST_RATE;
                total = subtotal + gst + qst;

                // Generate date and time
                now = time(NULL);

                strftime(dateTime, sizeof(dateTime),
                         "%d/%m/%Y %H:%M:%S", localtime(&now));

                // Display invoice
                printf("\n\n============================================\n");
                printf("             PIZZA POUR TOUS\n");
                printf("              Keyce Titi garage\n");
                printf("             +237 620 239 480\n");
                printf("============================================\n");

                printf("Invoice Number: %d\n", invoiceNumber);
                printf("Date and Time: %s\n", dateTime);

                printf("\nCustomer Information\n");
                printf("Phone: %s\n", phone);
                printf("Address: %s\n", address);

                printf("\n-------------- ORDER DETAILS --------------\n");

                for (i = 0; i < mealCount; i++)
                {
                    printf("\nMeal Number: %d\n", mealNumber[i]);

                    // Display pizza type
                    printf("Pizza Type: ");

                    switch (pizzaType[i])
                    {
                        case 'v':
                        case 'V':
                            printf("Vegetarian\n");
                            break;

                        case 'f':
                        case 'F':
                            printf("Cheese\n");
                            break;

                        case 't':
                        case 'T':
                            printf("All-dressed\n");
                            break;

                        case 'e':
                        case 'E':
                            printf("Spinach\n");
                            break;

                        case 'm':
                        case 'M':
                            printf("Seafood\n");
                            break;
                    }

                    // Display meal description
                    printf("Description: ");

                    switch (mealNumber[i])
                    {
                        case 3:
                            printf("1 Medium 12-inch Pizza + 1 Small Shawama + 1 Pepsi (355 ml)\n");
                            break;

                        case 4:
                            printf("1 Medium 12-inch Pizza + 10 Chicken Wings + Fries + 1 Pepsi (355 ml)\n");
                            break;

                        case 8:
                            printf("1 Large 14-inch Pizza + 1 Medium Shawama + 1 Pepsi (355 ml)\n");
                            break;

                        case 9:
                            printf("1 Large 14-inch Pizza + 12 Chicken Wings + Fries + 1 Pepsi (355 ml)\n");
                            break;

                        case 13:
                            printf("1 X-Large 16-inch Pizza + 1 Large Shawama + 1 Pepsi (355 ml)\n");
                            break;

                        case 14:
                            printf("1 X-Large 16-inch Pizza + 15 Chicken Wings + 1 Pepsi (355 ml)\n");
                            break;
                    }

                    printf("Quantity: %d\n", quantity[i]);
                    printf("Unit Price: $%.2f\n", unitPrice[i]);

                    printf("Meal Total: $%.2f\n",
                           unitPrice[i] * quantity[i]);
                }

                // Display invoice totals
                printf("\n============================================\n");
                printf("Subtotal:       $%.2f\n", subtotal);
                printf("GST (5%%):       $%.2f\n", gst);
                printf("QST (9.975%%):   $%.2f\n", qst);
                printf("--------------------------------------------\n");
                printf("TOTAL:          $%.2f\n", total);

                printf("Payment Method: ");

                switch (payment)
                {
                    case 'c':
                    case 'C':
                        printf("Cash\n");
                        break;

                    case 'd':
                    case 'D':
                        printf("Debit\n");
                        break;

                    case 'r':
                    case 'R':
                        printf("Credit\n");
                        break;
                }

                printf("============================================\n");
                printf("Thank you for choosing Pizza Pour Tous!\n");
                printf("Merci et a la prochaine!\n");
                printf("============================================\n");

                // Update total meals sold
                for (i = 0; i < mealCount; i++)
                {
                    totalMealsSold += quantity[i];
                }

                // Update total sales
                totalSalesAmount += total;

                // Increment invoice number
                invoiceNumber++;

                break;

            // OPTION 2: DISPLAY SALES
            case 2:

                now = time(NULL);

                strftime(dateTime, sizeof(dateTime),
                         "%d/%m/%Y %H:%M:%S", localtime(&now));

                printf("\n====================================\n");
                printf("          PIZZA POUR TOUS\n");
                printf("          Keyce Titi garage\n");
                printf("          +237 620 239 480\n");
                printf("====================================\n");

                printf("Date and Time: %s\n", dateTime);

                printf("\nTotal Meals Sold: %d\n", totalMealsSold);

                printf("Total Sales Amount: $%.2f\n",
                       totalSalesAmount);

                printf("====================================\n");

                break;

            // OPTION 3: QUIT
            case 3:

                printf("\nMerci et a la prochaine!\n");
                printf("Thank you for choosing Pizza Pour Tous!\n");

                break;
        }

    } while (choice != 3);

    return 0;
}

