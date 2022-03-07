#include<stdio.h>
#include<conio.h>

struct customer
{
    char bank_name [80];
    char bank_branch[80];
    int account_no;
    char name[80];
    int balance;
};

void accept(struct customer[], int);
void display(struct customer[], int);
int search(struct customer[], int, int);
void deposit(struct customer[], int, int, int);
void withdraw(struct customer[], int, int, int);
//void _2D();

int main()
{
    system ("COLOR E");
    struct customer data[20];
    int n, choice, account_no, amount, index;

    printf("\n\t\t*****  Welcome to Bank Application  *****\n");

    printf("Number of customer records you want to enter? : ");
    scanf("%d", &n);
    accept(data, n);
    do
    {

        printf("\nBanking System Menu :\n");
        printf("Press 1 to display all records.\n");
        printf("Press 2 to search a record.\n");
        printf("Press 3 to deposit amount.\n");
        printf("Press 4 to withdraw amount.\n");
        printf("Press 0 to exit\n");
        printf("\nEnter choice(0-4) : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                display(data, n);
                break;
            case 2:
                printf("Enter account number to search : ");
                scanf("%d", &account_no);
                index = search(data, n, account_no);
                if (index ==  - 1)
                {
                    printf("Record not found : ");
                }
                else
                {
                    printf("A/c Number: %d\nName: %s\nBalance: %d\n",
                        data[index].account_no, data[index].name,
                        data[index].balance);
                }
                break;
            case 3:
                printf("Enter account number : ");
                scanf("%d", &account_no);
                printf("\nMoney can be Deposited like this --> \n");
                int array[3][3]= {{500, 1000, 3000},{ 5000, 7000, 9000},{10000 , 20000, 40000} };
                int a=0, b=0;

                for(a=0 ; a< 3 ;a++)
                    {
                        for(b=0; b<3 ; b++)
                            {

                                printf("\n** %d ", array[a][b]);
                            }
                    }
                printf("\nEnter amount to deposit : ");
                scanf("%d", &amount);
                deposit(data, n, account_no, amount);
                break;
            case 4:
                printf("Enter account number : ");
                scanf("%d", &account_no);
                printf("Enter amount to withdraw : ");
                scanf("%d", &amount);
                withdraw(data, n, account_no, amount);
        }
    }
    while (choice != 0);

    return 0;
}

void accept(struct customer list[80], int s)
{
    int i;
    for (i = 0; i < s; i++)
    {
        printf("\nEnter data for Record #%d", i + 1);

        printf("\nEnter account_no : ");
        scanf("%d", &list[i].account_no);
        fflush(stdin);
        printf("Enter name : ");
        gets(list[i].name);
        printf ("Enter bank name:");
        gets (list[i].bank_name);
        printf ("Enter bank branch:");
        gets (list[i].bank_branch);
          list[i].balance = 0;
    }
}

void display(struct customer list[80], int s)
{
    int i;


    for (i = 0; i < s; i++)
    {
        printf(" \n\n A/c No :%d\n Name :%s\n Balance : %d\n Bank_name : %s\n Bank_branch: %s\n\n",
            list[i].account_no,
            list[i].name,
            list[i].balance,
            list[i].bank_name,
            list[i].bank_branch);
    }
}

int search(struct customer list[80], int s, int number)
{
    int i;

    for (i = 0; i < s; i++)
    {
        if (list[i].account_no == number)
        {
            return i;
        }
    }
    return  - 1;
}

void deposit(struct customer list[], int s, int number, int amt)
{

    int i = search(list, s, number);
    if (i ==  - 1)
    {
        printf("Record not found");
    }
    else
    {
        list[i].balance += amt;
    }
}

void withdraw(struct customer list[], int s, int number, int amt)
{
    int i = search(list, s, number);
    if (i ==  - 1)
    {
        printf("Record not found\n");
    }
    else if (list[i].balance < amt)
    {
        printf("Insufficient balance\n");
    }
    else
    {
        list[i].balance -= amt;
    }
}
