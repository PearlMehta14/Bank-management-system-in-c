#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
int i,j;
int main_exit;
void menu();
struct date{
    int month,day,year;

    };
struct {

    char name[60];
    int acc_no,age;
    char bankress[60];
    char aadhar[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

    }bank,upd,check,rem,transaction;

float interest(float t,float amount,int rate)
{
    float SI;
    SI=(rate*t*amount)/100.0;
    return (SI);

}
void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

         void loading()
         {
             for(i=0;i<=6;i++)
        {
            fordelay(100000000);
           // printf(" ");
            printf(".");
        }
         }

void main()
{
    int choice;
    int a;
    system("cls");
    //system("color 50");
    //system("color 9");
    //printf("\n\n\t\t\tBANKIN MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE BANK MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    //printf("press enter");
   // Scanf("printf("\n\n\nLOADING");
       /* for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(" ");
            printf(".");
        }",&a);*/
        loading();
    //printf("\n\n\t\t1.Press 1 to create a new account\n\t\t2.Press 2 for transactions\n\t\t3.Press 3 to check the details of existing account\n\t\t4. Press 4 for removing existing account\n\t\t5.Press 5 to update information of existing account\n\t\t6. Press 6 to view customer's list\n\t\t7.Press 7 for Exit\n\n\n\n\n\t\t Enter your choice:");
   // scanf("%d",&choice);
   printf("\n\n\n\t\t\t\t\t\t\tLOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(" ");
            printf(".");
        }
                system("cls");
            menu();
           // choice:
           // scanf("%d",&choice);

   /* system("cls");
    switch(choice)
    {
        case 1:new_acc();
        break;
        case 2:transact();
        break;
        case 3:see();
        break;
        case 4:erase();
        break;
        case 5:edit();
        break;
        case 6:view_list();
        break;
        case 7:close();
        break;

    }*/
}

//void new_acc()
void new_acc()

{
    system("color F");
    int choice;
    FILE *ptr;


    ptr=fopen("record.dat","a+");
    account_no:
    system("cls");
    printf("\t\t\t\t\t\xB2\xB2\xB2\ACCOUNT OPENING PROCESS\xB2\xB2\xB2\xB2");
    printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&bank.deposit.month,&bank.deposit.day,&bank.deposit.year);
    printf("\nEnter the account number:");
    scanf("%d",&check.acc_no);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",&bank.acc_no,bank.name,&bank.dob.month,&bank.dob.day,&bank.dob.year,&bank.age,bank.bankress,bank.aadhar,&bank.phone,bank.acc_type,&bank.amt,&bank.deposit.month,&bank.deposit.day,&bank.deposit.year)!=EOF)
    {
        if (check.acc_no==bank.acc_no)
            {printf("Account no. already in use!");
            fordelay(1000000000);
                goto account_no;

            }
    }
    bank.acc_no=check.acc_no;
        printf("\nEnter the name:");
    scanf("%s",bank.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&bank.dob.month,&bank.dob.day,&bank.dob.year);
    printf("\nEnter the age:");
    scanf("%d",&bank.age);
    printf("\nEnter the Address:");
    scanf("%s",bank.bankress);
    printf("\nEnter the aadhar number:");
    scanf("%s",bank.aadhar);
    printf("\nEnter the phone number: ");
    scanf("%1f",&bank.phone);
    printf("\nEnter the amount to deposit:$");
    scanf("%f",&bank.amt);
    printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter type of account you want:");
    scanf("%s",bank.acc_type);

        fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",bank.acc_no,bank.name,bank.dob.month,bank.dob.day,bank.dob.year,bank.age,bank.bankress,bank.aadhar,bank.phone,bank.acc_type,bank.amt,bank.deposit.month,bank.deposit.day,bank.deposit.year);


    fclose(ptr);
    printf("\n\t\t\tYOUR ACCOUNT IS CREATED SUCCESFULLY!!!");
    bank_invalid:

    printf("\n\n\n\t\tEnter 1 to go to the main screen and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto bank_invalid;
        }
}


void transact(void)
{    system("color 7");
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

        printf("Enter the account no. of the customer:");
    scanf("%d",&transaction.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&bank.acc_no,bank.name,&bank.dob.month,&bank.dob.day,&bank.dob.year,&bank.age,bank.bankress,bank.aadhar,&bank.phone,bank.acc_type,&bank.amt,&bank.deposit.month,&bank.deposit.day,&bank.deposit.year)!=EOF)
   {

            if(bank.acc_no==transaction.acc_no)
            {   test=1;
                if(strcmpi(bank.acc_type,"fixed1")==0||strcmpi(bank.acc_type,"fixed2")==0||strcmpi(bank.acc_type,"fixed3")==0)
                {
                    printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                    fordelay(1000000000);
                    system("cls");
                    menu();

                }
                printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
                scanf("%d",&choice);
                if (choice==1)
                {
                    printf("Enter the amount you want to deposit:$ ");
                    scanf("%f",&transaction.amt);
                    bank.amt+=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",bank.acc_no,bank.name,bank.dob.month,bank.dob.day,bank.dob.year,bank.age,bank.bankress,bank.aadhar,bank.phone,bank.acc_type,bank.amt,bank.deposit.month,bank.deposit.day,bank.deposit.year);
                    printf("\n\nDEPOSITED SUCCESSFULLY!");
                }
                else
                {
                    printf("Enter the amount you want to withdraw:$ ");
                    scanf("%f",&transaction.amt);
                    bank.amt-=transaction.amt;
                    fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",bank.acc_no,bank.name,bank.dob.month,bank.dob.day,bank.dob.year,bank.age,bank.bankress,bank.aadhar,bank.phone,bank.acc_type,bank.amt,bank.deposit.month,bank.deposit.day,bank.deposit.year);
                    printf("\n\nWITHDRAWN SUCCESSFULLY!!");
                }

            }
            else
            {
               fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",bank.acc_no,bank.name,bank.dob.month,bank.dob.day,bank.dob.year,bank.age,bank.bankress,bank.aadhar,bank.phone,bank.acc_type,bank.amt,bank.deposit.month,bank.deposit.day,bank.deposit.year);
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test!=1)
   {
       printf("\n\nRecord not found!!");
       transact_invalid:
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&main_exit);
      system("cls");
      if (main_exit==0)
        transact();
    else if (main_exit==1)
        menu();
    else if (main_exit==2)
        close();
    else
    {
        printf("\nInvalid!");
        goto transact_invalid;
    }

   }
   else
   {
       printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
   }

}

void see(void)
{
     system("color B");
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    ptr=fopen("record.dat","r");
    printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("Enter the account number:");
        scanf("%d",&check.acc_no);

        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&bank.acc_no,bank.name,&bank.dob.month,&bank.dob.day,&bank.dob.year,&bank.age,bank.bankress,bank.aadhar,&bank.phone,bank.acc_type,&bank.amt,&bank.deposit.month,&bank.deposit.day,&bank.deposit.year)!=EOF)
        {
            if(bank.acc_no==check.acc_no)
            {   system("cls");
                test=1;

                printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nbankress:%s \naadhar No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$ %.2f \nDate Of Deposit:%d/%d/%d\n\n",bank.acc_no,bank.name,bank.dob.month,bank.dob.day,bank.dob.year,bank.age,bank.bankress,bank.aadhar,bank.phone,
                bank.acc_type,bank.amt,bank.deposit.month,bank.deposit.day,bank.deposit.year);
                if(strcmpi(bank.acc_type,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,bank.amt,rate);
                        printf("\n\nYou will get $%.2f as interest on %d/%d/%d",intrst,bank.deposit.month,bank.deposit.day,bank.deposit.year+1);
                    }
                else if(strcmpi(bank.acc_type,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,bank.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,bank.deposit.month,bank.deposit.day,bank.deposit.year+2);

                    }
                else if(strcmpi(bank.acc_type,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,bank.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,bank.deposit.month,bank.deposit.day,bank.deposit.year+3);

                    }
                 else if(strcmpi(bank.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,bank.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d of every month",intrst,bank.deposit.day);

                     }
                 else if(strcmpi(bank.acc_type,"current")==0)
                    {

                        printf("\n\nYou will get no interest\a\a");

                     }

            }
        }
    }
    else if (choice==2)
    {   printf("Enter the name:");
        scanf("%s",&check.name);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&bank.acc_no,bank.name,&bank.dob.month,&bank.dob.day,&bank.dob.year,&bank.age,bank.bankress,bank.aadhar,&bank.phone,bank.acc_type,&bank.amt,&bank.deposit.month,&bank.deposit.day,&bank.deposit.year)!=EOF)
        {
            if(strcmpi(bank.name,check.name)==0)
            {   system("cls");
                test=1;
                printf("\nAccount No.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nbankress:%s \naadhar No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$%.2f \nDate Of Deposit:%d/%d/%d\n\n",bank.acc_no,bank.name,bank.dob.month,bank.dob.day,bank.dob.year,bank.age,bank.bankress,bank.aadhar,bank.phone,
                bank.acc_type,bank.amt,bank.deposit.month,bank.deposit.day,bank.deposit.year);
                if(strcmpi(bank.acc_type,"fixed1")==0)
                    {
                        time=1.0;
                        rate=9;
                        intrst=interest(time,bank.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,bank.deposit.month,bank.deposit.day,bank.deposit.year+1);
                    }
                else if(strcmpi(bank.acc_type,"fixed2")==0)
                    {
                        time=2.0;
                        rate=11;
                        intrst=interest(time,bank.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,bank.deposit.month,bank.deposit.day,bank.deposit.year+2);

                    }
                else if(strcmpi(bank.acc_type,"fixed3")==0)
                    {
                        time=3.0;
                        rate=13;
                        intrst=interest(time,bank.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,bank.deposit.month,bank.deposit.day,bank.deposit.year+3);

                    }
                 else if(strcmpi(bank.acc_type,"saving")==0)
                    {
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,bank.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d of every month",intrst,bank.deposit.day);

                     }
                 else if(strcmpi(bank.acc_type,"current")==0)
                    {

                        printf("\n\nYou will get no interest\a\a");

                     }

            }
        }
    }


    fclose(ptr);
     if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            see_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    see();
                else
                    {
                        system("cls");
                        printf("\nInvalid!\a");
                        goto see_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);}
        if (main_exit==1)
        {
            system("cls");
            menu();
        }

        else
           {

             system("cls");
            close();
            }

}


void erase(void)
{
     system("color 4");
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d",&rem.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&bank.acc_no,bank.name,&bank.dob.month,&bank.dob.day,&bank.dob.year,&bank.age,bank.bankress,bank.aadhar,&bank.phone,bank.acc_type,&bank.amt,&bank.deposit.month,&bank.deposit.day,&bank.deposit.year)!=EOF)
   {
        if(bank.acc_no!=rem.acc_no)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",bank.acc_no,bank.name,bank.dob.month,bank.dob.day,bank.dob.year,bank.age,bank.bankress,bank.aadhar,bank.phone,bank.acc_type,bank.amt,bank.deposit.month,bank.deposit.day,bank.deposit.year);

        else
            {test++;
            printf("\nRecord deleted successfully!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
            erase_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    erase();
                else
                    {printf("\nInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }

}

void edit(void)
{
     system("color E");
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");

    printf("\nEnter the account no. of the customer whose info you want to change:");
    scanf("%d",&upd.acc_no);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&bank.acc_no,bank.name,&bank.dob.month,&bank.dob.day,&bank.dob.year,&bank.age,bank.bankress,bank.aadhar,&bank.phone,bank.acc_type,&bank.amt,&bank.deposit.month,&bank.deposit.day,&bank.deposit.year)!=EOF)
    {
        if (bank.acc_no==upd.acc_no)
        {   test=1;
            printf("\nWhich information do you want to change?\n1.address\n2.Phone\n\nEnter your choice\n\n(Press 1 for address and 2 for phone):");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
                {printf("Enter the new address:");
                scanf("%s",upd.bankress);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",bank.acc_no,bank.name,bank.dob.month,bank.dob.day,bank.dob.year,bank.age,upd.bankress,bank.aadhar,bank.phone,bank.acc_type,bank.amt,bank.deposit.month,bank.deposit.day,bank.deposit.year);
               // system("cls");
                printf("\n\n\nCHANGES ARE SAVED!");
                }
            else if(choice==2)
                {
                    printf("Enter the new phone number:");
                scanf("%lf",&upd.phone);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",bank.acc_no,bank.name,bank.dob.month,bank.dob.day,bank.dob.year,bank.age,bank.bankress,bank.aadhar,upd.phone,bank.acc_type,bank.amt,bank.deposit.month,bank.deposit.day,bank.deposit.year);
                system("cls");
                printf("CHANGES ARE SAVED!");
                }

        }
        else
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",bank.acc_no,bank.name,bank.dob.month,bank.dob.day,bank.dob.year,bank.age,bank.bankress,bank.aadhar,bank.phone,bank.acc_type,bank.amt,bank.deposit.month,bank.deposit.day,bank.deposit.year);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            edit_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)

                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    edit();
                else
                    {printf("\nInvalid!\a");
                    goto edit_invalid;}
        }
    else
        {printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }
}
void view_list()
{
     system("color A");
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    system("cls");
    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");

    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&bank.acc_no,bank.name,&bank.dob.month,&bank.dob.day,&bank.dob.year,&bank.age,bank.bankress,bank.aadhar,&bank.phone,bank.acc_type,&bank.amt,&bank.deposit.month,&bank.deposit.day,&bank.deposit.year)!=EOF)
       {
           printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf",bank.acc_no,bank.name,bank.bankress,bank.phone);
           test++;
       }

    fclose(view);
    if (test==0)
        {   system("cls");
            printf("\n\n\t\t\t\t\t\t\t\t\tNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}

void close()
{
    system("color 7");
    printf("\n\n\t\t\tThankyou for visiting");
    printf("\n\t\t\tProject by Error Terror");
    printf("\n\t\t\tVISIT US AGAIN");
}
void menu()
{
    //system("color 5");
    int choice;
  printf("\n\n\t\t1.Create a new account\n\t\t2.Make any transactions\n\t\t3.Check the details of existing account\n\t\t4.Removing existing account\n\t\t5.Update information of existing account\n\t\t6.View customer's list\n\t\t7.Exit\n\n\n\n\n\t\t Press any key of your choice:");
scanf("%d",&choice);
//goto choice

system("cls");
    switch(choice)
    {
        case 1:new_acc();
        break;
        case 2:transact();
        break;
        case 3:see();
        break;
        case 4:erase();
        break;
        case 5:edit();
        break;
        case 6:view_list();
        break;
        case 7:close();
        break;

    }
}
