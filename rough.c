#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
struct first
{
    char name[20];
    char lname[20];
    char pin[10];
    char ph[10];
    double amt;

}s;
struct first s1;
FILE *f,*fp;
void create()
{
    printf("Enter the First Name\n");
    scanf("%s",s.name);
    fflush(stdin);
    printf("Enter Last Name\n");
    gets(s.lname);
    printf("Enter The Local Pin Code\n");
    gets(s.pin);
    printf("Enter the mobile no.\n");
    gets(s.ph);
   printf("Enter Account Opening Amount\nRs.");
   scanf("%lf",&s.amt);
   f=fopen("User.txt","ab+");
   fwrite(&s,sizeof(struct first),1,f);
   fclose(f);
}
void list()
{
    f=fopen("User.txt","ab+");
   while(fread(&s1,sizeof(struct first),1,f))
   {
   printf("***************************************\n");
   printf("Name:%s %s\n",s1.name,s1.lname);
   printf("Mobile No.:%s\n",s1.ph);
   printf("Pin Code:%s\n",s1.pin);
   printf("Balance: Rs.%lf\n",s1.amt);
   }
   fclose(f);
}
void account(char p[10])
{
    f=fopen("User.txt","ab+");
   while(fread(&s1,sizeof(struct first),1,f))
   {
            if(strcmp(s1.ph,p)==0)
            {
           printf("Name:%s\n",s1.name);
           printf("Mobile No:%s\n",s1.ph);
           printf("Pin Code:%s\n",s1.pin);
           printf("Balance Amount=Rs.%lf\n",s1.amt);
           break;
            }

   }
   fclose(f);
}
void delete(char p[10])
{
    f=fopen("User.txt","ab+");
    fp=fopen("copy.txt","ab+");
    while(fread(&s1,sizeof(struct first),1,f))
    {
        if(strcmp(s1.ph,p)!=0)
        {
            fwrite(&s1,sizeof(struct first),1,fp);
        }
    }
    fclose(f);
    fclose(fp);
    printf("Account Successfully Deleted\n");
    remove("User.txt");
    rename("copy.txt","User.txt");
}
void update(char p[10])
{
    f=fopen("User.txt","ab+");
    fp=fopen("copy.txt","ab+");
    while(fread(&s1,sizeof(struct first),1,f))
    {
        if(strcmp(s1.ph,p)!=0)
        {
            fwrite(&s1,sizeof(struct first),1,fp);
        }
        if(strcmp(s1.ph,p)==0)
        {
            printf("Enter the First Name\n");
            scanf("%s",s1.name);
            fflush(stdin);
            printf("Enter the Last Name\n");
            gets(s1.lname);
            printf("Enter the mobile no.\n");
            gets(s1.ph);

            printf("Enter Local Pin Code\n");
            gets(s1.pin);

            fwrite(&s1,sizeof(struct first),1,fp);
        }
    }
   fclose(f);
   fclose(fp);
   remove("User.txt");
   rename("copy.txt","User.txt");
}
void withdrawl(char p[10])
{
    double dd;
    f=fopen("User.txt","ab+");
    fp=fopen("Copy.txt","ab+");
    while(fread(&s1,sizeof(struct first),1,f))
    {
      if(strcmp(s1.ph,p)==0)
      {
          printf("Enter The Amount you want to withdraw\n");
          scanf("%lf",&dd);
          if(dd>s1.amt)
          {
              printf("You Don't Have Sufficient Balance\n");
          }
          else
          {
              s1.amt=s1.amt-dd;
              printf("Withdrawl Succesful\n");
              printf("Balance=Rs.%lf\n",s1.amt);
          }
          fwrite(&s1,sizeof(struct first),1,fp);
      }
      if(strcmp(s1.ph,p)!=0)
      {
        fwrite(&s1,sizeof(struct first),1,fp);
      }
    }
    fclose(f);
    fclose(fp);
    remove("User.txt");
   rename("copy.txt","User.txt");
}
void deposit(char p[10])
{
    double dd;
    f=fopen("User.txt","ab+");
    fp=fopen("copy.txt","ab+");
    while(fread(&s1,sizeof(struct first),1,f))
    {
      if(strcmp(s1.ph,p)==0)
      {
          printf("Enter The Amount you want to deposit\n");
          scanf("%lf",&dd);
          s1.amt=s1.amt+dd;
          printf("Deposit Succesful\n");
          printf("Balance=Rs.%lf\n",s1.amt);
          fwrite(&s1,sizeof(struct first),1,fp);
      }
        if(strcmp(s1.ph,p)!=0)
      {
        fwrite(&s1,sizeof(struct first),1,fp);
      }
    }
    fclose(f);
    fclose(fp);
    remove("User.txt");
   rename("copy.txt","User.txt");
}
void main()
{
   int n,r;char p[10];
   do{
   printf("--------BANKING SYSTEM--------\n");
   printf("Press 1 to Create Account\n");
   printf("Press 2 to Print Customer List\n");
   printf("Press 3 for Account Details\n");
   printf("Press 4 to Delete Account\n");
   printf("Press 5 to Update Account\n");
   printf("Press 6 for Transactions\n");
   printf("Press 0 for Exit\n");
   scanf("%d",&n);
   switch(n)
   {
    case 1:
        system("cls");
   create();
   printf("Account Successfully Created\n");
   printf("For Exit Press 0\n");
   printf("For Menu Press 1\n");
   scanf("%d",&n);
   if(n==1)
   {
       system("cls");
   }
   break;
   case 2:
       system("cls");
   list();
   printf("For Exit Press 0\n");
   printf("For Menu Press 1\n");
   scanf("%d",&n);
   if(n==1)
   {
       system("cls");
   }
   break;
   case 3:
       system("cls");
    printf("Enter your Registered Mobile No.\n");
    fflush(stdin);
    gets(p);
    account(p);
     printf("For Exit Press 0\n");
   printf("For Menu Press 1\n");
   scanf("%d",&n);
   if(n==1)
   {
       system("cls");
   }
    break;
   case 4:
       system("cls");
       printf("Enter your Registered Mobile No.\n");
    fflush(stdin);
    gets(p);
       delete(p);
        printf("For Exit Press 0\n");
   printf("For Menu Press 1\n");
   scanf("%d",&n);
   if(n==1)
   {
       system("cls");
   }
       break;
   case 5:
       system("cls");
    printf("Enter your Registered Mobile No.\n");
    fflush(stdin);
    gets(p);
    update(p);
     printf("For Exit Press 0\n");
   printf("For Menu Press 1\n");
   scanf("%d",&n);
   if(n==1)
   {
       system("cls");
   }
    break;
   case 6:
       system("cls");
    printf("For Withdrawl Press 1\nFor Deposit Press 2\n");
    scanf("%d",&r);
    if(r==1)
    {
      printf("Enter Your Mobile No.\n");
      fflush(stdin);
      gets(p);
      withdrawl(p);
    }
    else if(r==2)
    {
       printf("Enter Your Mobile No.\n");
      fflush(stdin);
      gets(p);
      deposit(p);
    }
    else
    {
        printf("Wrong Input\n");
    }
     printf("For Exit Press 0\n");
   printf("For Menu Press 1\n");
   scanf("%d",&n);
   if(n==1)
   {
       system("cls");
   }
    break;
   }
   }while(n!=0);
   printf("Thank You");
}
