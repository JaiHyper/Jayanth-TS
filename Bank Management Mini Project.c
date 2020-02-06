
/* Hi There
 * This is an effort to make a Bank Management system which can be easily understood by any CSE student
 * Linked list is used because its my wish ;P
 * Happy Coding :)
 
 * For further help contact email: jwill.hyper@gmail.com

########################################################################################################################################*/

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
int acc_num;    //for viewing and editing functions
int start_num = 1000;   //account numbers start from this number
int bnk_pwd = 8080;     // 4 digit password for displying ALL ACCOUNT DETAILS
int option;     //to read choices in all functions but main
int del_list[20];   //to keep recored of deleted numbers
int i = 0;      //just variable
///////////////////////////////////////////////////////////////////////////////
void create_account();  //see struct account for variables available
void view_account();    //read account number and view account details
void edit_account();    //can edit the name and phone number
void transact();        //deposite or withdrawl 
void delete_account();
void display_all_accounts();    //read password and display all account details 
void deleted_list(int);
int is_deleted(int);

struct account{
    char name[20];
    char phone_num[10];
    int amount;
    int age;
    int account_num;
    struct account *next;   //link named next
};

struct account *first_account = NULL;  //pointer to first account 

int main(){
    int choice;
    printf("\nWELCOME to the process of J-Trust Banking Associations <<<Your trust is out Strength>>>");

    while(1){
        
        printf("\n\nThe Bank provides the following Options for you, please select your choice :\n\n");
        printf("1. Create account\n2. View account Details\n3. Edit account Details\n4. Do Transactions\n5. Delete Account\n6. Show all Account Details (Needs 4 digit Password)\n\n\tEnter the choice here : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:create_account(); break;
            case 2:view_account(); break;
            case 3:edit_account(); break;
            case 4:transact(); break;
            case 5:delete_account(); break;
            case 6:display_all_accounts(); break;
            default:printf("\nInvalid Choice!!!\n\n\tPress Enter to continue\n");
            getch();
        }
    }
}
void create_account(){
    struct account *new_account;
    new_account=(struct account *)malloc(sizeof(struct account));
    printf("\nEnter your name : ");
    scanf("%s",new_account->name);
    printf("Enter age: ");
    scanf("%d",&new_account->age);
    printf("Enter your Phone Number : ");
    scanf("%s",new_account->phone_num);
    new_account->amount = 0;
    start_num += 1;
    new_account->account_num=start_num;
    new_account->next = NULL;
    if(first_account==NULL)
        first_account=new_account;
    else{
        struct account *trav;
        trav = first_account;
        while(trav->next != NULL) trav=trav->next;
        trav->next = new_account;
        new_account->next = NULL;
    }
    printf("\nCongrats %s and Welcome to our Family!!!\n\nYour account Number is : %d\n\n\tPress Enter to continue\n",new_account->name,new_account->account_num);
    getch();
}


void display_all_accounts(){
    int pwd;
    printf("\n\t\tEnter the 4 digit Password : ");
    scanf("%d",&pwd);
    if(pwd != bnk_pwd){
        printf("\n\t\t\tWrong Password!!!\n\n\t\tPress Enter to continue...\n");
        getch();
    }
    else{
        printf("\n\t\t\tPassword Match Found!!!\n");
        if(first_account == NULL) {
            printf("\n\tNo Data Found!!!\n\tPress Enter to continue...\n");
            getch();
        }
        else{
            struct account *trav;
            trav = first_account;
            while(trav->next != NULL){
                printf("Name : %s\nAccount Number : %d\nPhone Number : %s\nDebit Amount : %d\n/////////////////////////////\n",trav->name,trav->account_num,trav->phone_num,trav->amount);
                trav = trav->next;
            }
            printf("Name : %s\nAccount Number : %d\nPhone Number : %s\nDebit Amount : %d\n/////////////////////////////\n\n\tPress Enter to continue...\n",trav->name,trav->account_num,trav->phone_num,trav->amount);
            getch();
        }
    }
}

void view_account(){
    if(first_account == NULL) {
        printf("\nNo Data Found!!!\n\n\tPress Enter to continue...\n");
        getch();
    }
    else{
        printf("Enter your account number : ");
        scanf("%d",&acc_num);
        if(acc_num <= 1000 || acc_num > start_num){
            printf("\n\t\tThis Account Number is Invalid!!!\n\n\t\tPress Enter to continue");
            getch();
        }
        else{
            struct account *trav;
            trav = first_account;
            while(trav->account_num != acc_num) trav=trav->next;
            printf("The details of %d :\n\n",acc_num);
            printf("\tName : %s\n\tAge : %d\n\tPhone Number : %s\n\tAmount : %d\n\n\tPress Enter to contine",trav->name,trav->age,trav->phone_num,trav->amount);
            getch();
        }
    }
}
void edit_account(){
    printf("\nEnter your Account Number : ");
    scanf("%d",&acc_num);
    if(acc_num <= 1000 || acc_num > start_num){
        printf("\n\t\tThis Account Number is Invalid!!!\n\n\t\tPress Enter to continue");
        getch();
    }
    else{
        struct account *trav;
        trav = first_account;
        while(trav->account_num != acc_num) trav = trav->next;
        printf("\n\tWhat do youb want to do?\n\t1. Edit Name\n\t2. Edit Phone Number\n\n\tEnter your choice here : ");
        scanf("%d",&option);
        if(option==1){
            printf("Enter New Name : ");
            scanf("%s",trav->name);
            printf("\nNew name Updated Sucssfully---\n\n\tPress Enter to continue\n");
        }
        else if(option==2){
            printf("Enter New Phone Numeber : ");
            scanf("%s",trav->phone_num);
            printf("\nNew Phone Number Updated Sucssfully---\n\n\tPress Enter to continue\n");
        }
        else printf("\n\n\t\tRequest Invalid!!!\n\n\t\tPress Enter to continue");
        getch();
    }
}

void transact(){
    int money;  //for reading the amount to be deposited or withdrawn
    printf("\nEnter your Account Number : ");
    scanf("%d",&acc_num);
    struct account *trav;
    trav = first_account;
    if(acc_num <= 1000 || acc_num > start_num){
        printf("\n\t\tThis Account Number is Invalid!!!\n\n\t\tPress Enter to continue");
        getch();
    }
    else{
        printf("\n\tWhat do youb want to do?\n\t1. Deposite Money\n\t2. Withdraw Money\n\n\tEnter your choice here : ");
        scanf("%d",&option);
        while(trav->account_num != acc_num) trav = trav->next;
        printf("\nYour Current Balance is : %d\n",trav->amount );
        
        if(option==1){
            printf("Deposit Amount : ");
            scanf("%d",&money);
            trav->amount += money;
            printf("\n\tYour Deposite of %d Rupees was Successful!!!\n\n\t\tPress Enter to continue",money);
            getch();
        }
        else if(option==2){
            printf("Withdrawal Amount : ");
            scanf("%d",&money);
            if(money > trav->amount) printf("\n\t\tRequest Not Possible (Requested amount is more than Available Balance)");
            else{
                trav->amount -= money;
                printf("\n\tYour Withdrawl of %d Rupees was Successful!!!\n\n\t\tPress Enter to continue",money);
                getch();
            }
        }
        else printf("\n\n\t\tRequest Invalid!!!\n\n\t\tPress Enter to continue");
        getch();
    }
}

void delete_account(){
    if(first_account == NULL) {
        printf("\nNo Data Found!!!\n\n\tPress Enter to continue...\n");
        getch();
    }
    else{
        printf("\nEnter your Account Number : ");
        scanf("%d",&acc_num);
        if(acc_num <= 1000 || acc_num > start_num){
            printf("\n\t\tThis Account Number is Invalid!!!\n\n\t\tPress Enter to continue");
            getch();
        }
        else{
            if(acc_num == first_account->account_num){
                first_account = first_account->next;
                printf("\n\t\tYour Account was Successfully Deleted!!!\n\n\tPress Enter to continue");
                getch();
            }
            else if(acc_num == first_account->account_num && first_account->next == NULL){
                first_account = NULL;
                printf("\n\t\tYour Account was Successfully Deleted!!!\n\n\tPress Enter to continue");
                getch();
            }
            else{
                struct account *trav,*del_node;
                trav=first_account;
                while(trav->account_num < (acc_num-1)) trav = trav->next;
                del_node = trav->next;
                trav->next = del_node->next;
                del_node->next = NULL;
                printf("\n\t\tYour Account was Successfully Deleted!!!\n\n\tPress Enter to continue");
                getch();
            }
        }
    }
}
