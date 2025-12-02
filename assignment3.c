#include<stdio.h>
#include<string.h>

struct food //defining struct again in this file so that the further code know there exist a struct of this
{
    int no;
    char name[50];
    int price_full;
    int price_half;
};
struct choice //defining struct again in this file so that the further code know there exist a struct of this
{
    int id;
    int amount;
    char quant[50];
};
struct bill //defining struct again in this file so that the further code know there exist a struct of this
{
    char name[50];
    char phone_no[12];
};

extern struct food starters[6];
extern struct food maincourse[20];
extern struct food drinks[6]; //extern give defination of this variable which is defined in another file
extern struct food continental[8]; //telling the code that there exists content of these structs in another file
extern struct food asian[6];
extern struct food sweetdish[6]; 

int main()
{
    printf("Hello! sir/mam welcome to our restaurant please select your choice from the menu \n");

    struct choice order[50];
    struct bill x;
    int order_count = 0;
    int choice;  //initialising variables
    char final;
    int category;
    int cat[50];

    while(1) //continous loop until it breaks
    {
        printf("1 : STARTERS\n");
        printf("2 : MAINCOURSE\n");
        printf("3 : DRINKS\n");
        printf("4 : CONTINENTAL\n");
        printf("5 : ASIAN\n");          //choices
        printf("6 : SWEET DISH\n");
        printf("7 : Pay Bill \n");
        printf("choice = ");
        printf("\n");
        scanf("%d", &choice);

        if (choice == 7) 
        {
            break;
        }

        switch (choice)  //using switch case which works with the choice of user until user asks for bill
        { 
        case 1:
            printf("--- Starters Menu ---\n");
            for (int i = 0; i < 6; i++)
            {
                printf("%d || %s || full = Rs%d || half = Rs%d\n", starters[i].no, starters[i].name, starters[i].price_full, starters[i].price_half );
            }
            printf("\n");
            printf("\n");
            break;

        case 2:
            printf("--- Main Course Menu ---\n");
            for (int i = 0; i < 20; i++)
            {
                printf("%d || %s || full = Rs%d || half = Rs%d\n", maincourse[i].no, maincourse[i].name, maincourse[i].price_full, maincourse[i].price_half);
            }
            printf("\n");
            printf("\n");
            break;

        case 3:
            printf("--- Drinks Menu ---\n");
            for (int i = 0; i < 6; i++)
            {
                printf("%d || %s || full = Rs%d || half = Rs%d\n", drinks[i].no, drinks[i].name, drinks[i].price_full, drinks[i].price_half);
            }
            printf("\n");
            printf("\n");
            break;

        case 4:
            printf("---Continental Menu---\n");
            for(int i = 0; i < 8; i++)
            {
                printf("%d || %s || full = Rs%d || half = Rs%d\n", continental[i].no, continental[i].name, continental[i].price_full, continental[i].price_half);
            }
            printf("\n");
            printf("\n");
            break;

        case 5:
            printf("---Asian Menu---\n");
            for(int i = 0; i < 6; i++)
            {
                printf("%d || %s || full = Rs%d || half = Rs%d\n", asian[i].no, asian[i].name, asian[i].price_full, asian[i].price_half);
            }
            printf("\n");
            printf("\n");
            break;

        case 6:
            printf("---Sweet Dish Menu---\n");
            for(int i = 0; i < 6; i++)
            {
                printf("%d || %s || full = Rs%d || half = Rs%d\n", sweetdish[i].no, sweetdish[i].name, sweetdish[i].price_full, sweetdish[i].price_half);
            }
            printf("\n");
            printf("\n");
            break;

        default:  //if answer is out of choice it asks user to give input again
            printf("Invalid category! Try again.\n");
            continue;
        }

        printf("Enter item number to order = ");
        scanf("%d", &order[order_count].id); 

        printf("Enter item amount = ");
        scanf("%d", &order[order_count].amount);

        printf("Enter quantity (full OR half) = ");
        scanf("%s", order[order_count].quant);

        cat[order_count] = choice;  //assigning choice to cat variable for further use

        printf("Please confirm your order again: ");
        printf("ITEM NUMBER = %d    ITEM AMOUNT = %d    ITEM QUANTITY = %s \n",
               order[order_count].id , order[order_count].amount, order[order_count].quant);

        while(1)
        {
            printf("TYPE \"Y\" to continue \"N\" to try again \n"); //asking user for final choice to change or not change order
            printf("YOUR CHOICE = ");
            scanf(" %c", &final); //used %c cause only string required

            if(final == 'Y' || final == 'y') 
            {
                if(choice == 1)
                    printf("Thank you for ordering your order will arive in 7-8 mins\n");

                else if(choice == 2)
                    printf("Thank you for ordering your order will arive in 10-12 mins\n");

                else if(choice == 3)
                    printf("Thank you for ordering your order will arive in 3-4 mins\n");

                else if(choice == 4)
                    printf("Thank you for ordering your order will arive in 10-12 mins\n");

                else if(choice == 5)
                    printf("Thank you for ordering your order will arive in 6-7 mins\n");

                else if(choice == 6)
                    printf("Thank you for ordering your order will arive in 2 mins\n");

                order_count++;
                break;
            }
            else if(final == 'N' || final == 'n')
            {
                printf("Try your order again \n");
                break;
            }
            else
            {
                printf("invalid choice \n");
            }
        }
    }
    //if the user exits the loop and asks for bill printing the bill prints
    printf("Please enter your First Name only = "); //printing the bill
    scanf("%s", x.name);
    printf("Please enter your Phone number = ");
    scanf("%s", &x.phone_no);

    printf("____________________________________________\n");
    printf("\n");
    printf("               HERE IS YOUR BILL            \n");
    printf("____________________________________________\n");
    printf("\nCustomer: %s\nPhone No: %s\n", x.name, x.phone_no); //user details
    printf("--------------------------------------\n");
    printf("%s %s %s\n", "Item", "Qty", "Amount"); 
    printf("--------------------------------------\n");

    float total = 0; //total bill price variable initialisation

    for (int i = 0; i < order_count; i++) //loop for bill printing
    {   
        int id = order[i].id;
        int price = 0;   //defining local variables 
        char item_name[50];

        if (cat[i] == 1) //usage of previous cat variable
            strcpy(item_name, starters[id-1].name); //strcpy copies string name to variable
        else if (cat[i] == 2)
            strcpy(item_name, maincourse[id-1].name); 
        else if (cat[i] == 3)
            strcpy(item_name, drinks[id-1].name);
        else if (cat[i] == 4)
            strcpy(item_name, continental[id-1].name);
        else if (cat[i] == 5)
            strcpy(item_name, asian[id-1].name);
        else if (cat[i] == 6)
            strcpy(item_name, sweetdish[id-1].name);

        if (cat[i] == 1)
        {
            if (strcmp(order[i].quant,"full")==0) //0 means no error occured comparison is equal //took this from chatgpt
                price = starters[id-1].price_full;
            else
                price = starters[id-1].price_half;
        }
        else if (cat[i] == 2)  
        {
            if (strcmp(order[i].quant,"full")==0)
                price = maincourse[id-1].price_full;
            else
                price = maincourse[id-1].price_half;
        }
        else if (cat[i] == 3)                         //these all print the price according to quantity of the food
        {
            if (strcmp(order[i].quant,"full")==0)
                price = drinks[id-1].price_full;
            else
                price = drinks[id-1].price_half;
        }
        else if (cat[i] == 4)
        {
            if (strcmp(order[i].quant,"full")==0)
                price = continental[id-1].price_full;
            else
                price = continental[id-1].price_half;
        }
        else if (cat[i] == 5)
        {
            if (strcmp(order[i].quant,"full")==0)
                price = asian[id-1].price_full;
            else
                price = asian[id-1].price_half;
        }
        else if (cat[i] == 6)
        {
            if (strcmp(order[i].quant,"full")==0)
                price = sweetdish[id-1].price_full;
            else
                price = sweetdish[id-1].price_half;
        }

        total = total + price * order[i].amount;   //total original price
        printf("%s %s Rs%d\n", item_name, order[i].quant, price * order[i].amount);
    }

    printf("--------------------------------------\n");

    float gst = total * 0.05; //calculatin gst
    float discount = (total >= 600) ? total * 0.10 : 0;  //discount if greater than 600
    float final_amt = total + gst - discount;

    printf("Subtotal:            Rs%.2f\n", total);
    printf("GST (5%%):            Rs%.2f\n", gst);

    if (discount > 0)
        printf("Discount (10%%):      -Rs%.2f\n", discount);

    printf("--------------------------------------\n");
    printf("FINAL AMOUNT:        Rs%.2f\n", final_amt);
    printf("--------------------------------------\n");
    printf("\nThank you for dining with us!\n");
}
//i took help of google and a bit of chatgpt to do this code
//sap id = 590022445 batch- 33 name - abhay verma

