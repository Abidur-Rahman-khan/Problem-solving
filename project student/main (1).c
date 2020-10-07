#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>


/// this is login structure part
struct login
{
    char fname[20];
    char lname[20];
    char username[20];
    char password[32];
    char email[100];
};

///this is student structure part
struct student
{
    int rollno;
    char name[50];
    int p_marks,c_marks,m_marks,e_marks,cs_marks;
    float per;
    char grade[3];
    int std;
} st;

///Global file pointer
FILE *fptr;


///this is the registration part

void reg()
{

    FILE *log=fopen("project.txt","a+");
    struct login l;

    printf("\n\t\t\======> Enter your first name : ");
    scanf("%s",&l.fname);
    printf("\n\t\t\======> Enter your last name  : ");
    scanf("%s",&l.lname);
    printf("\n\t\t\======> Enter Your email      : ");
    scanf("%s",&l.email);
    printf("\n\t\t\======> Enter your user name  : ");
    scanf("%s",&l.username);
    printf("\n\t\t\======> Enter your password   : ");
    scanf("%s",&l.password);

    fprintf(log,"%s\t%s\t\t%s\t%s\t%s\n",l.fname,l.lname,l.email,l.username,l.password);

    fclose(log);

    printf("\n\n\t press any key to continue .........");

    system("cls");

    login();
}

/// this is the log in part

void login()
{
    FILE *log=fopen("project.txt","r");
    struct login l;

    printf("\n\t\t\t#########[ LOG IN ]#########\n");

    char line[500],fName[100],lName[100],email[100],username[200],password[20];
    system("color 7");
    printf("\n\t\t\>>>>>>>>>>> UserID   : ");
    scanf("%s",&username);
    system("color 8");
    printf("\n\t\t\>>>>>>>>>>> Password : ");
    scanf("%s",&password);

    int flag=0;

    while(fgets(line, sizeof line, log)!=NULL)
    {
        sscanf(line,"%s\t%s\t\t%s\t\t%s\t%s",fName,lName,email,l.username,l.password);

        if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0)
        {
            system("cls && color B");
            printf("\n\t\t *successfully log in\n");
            flag=1;
            printf("\n\t\t *Press any key to continue.....");
            getch();
            page_1();
        }
    }

    if(flag==0)
    {
        system("color 4");
        printf("\a\n\n\t\t log in failed\n\n\t\t press any key to try again...");
        getch();
        system("cls");
        login();
    }

    fclose(log);
}

///this is our App page 1 after log in

void page_1()

{
    char ch;

    system("cls");
    printf("\n\n\n\t>>>> Welcome to Result Management system");
    printf("\n\n\t=====> [01] Go For Published Result ");
    printf("\n\n\t=====> [02] ENTRY/EDIT MENU");
    printf("\n\n\t=====> [03] Main Menu.");
    printf("\n\n\t=====> [04] Logout.");
    printf("\n\n\t=========>>Enter Your Choice :  ");
    ch=getche();
    switch(ch)
    {
    case '1':
        system("cls");
        result();
        break;
    case '2':
        system("cls");
        data_student();
        break;
    case '3':
        system("cls");
        mainsystem();
        break;
    case '4':
        system("cls");
        logout();
        break;
    default :
        printf("\a");
        page_1();
    }

}

///this is logout function

void logout()
{
    system("cls");
    printf("\n\n\n\t\t\t Log out successfully !.....\n");
    printf("\n\n\n\t\t\t Any key to continue.........");
    getch();
    mainsystem();
}

/// this is our page no 2 from log in ,case number 1

void result ()
{
    int n,roll;

    system("cls");
    system("color 3");
    printf("\n\n\t\t+++[Welcome to Publish your Result]+++");
    printf("\n\t\t\t [1] Show all  Result ");
    printf("\n\t\t\t [0] EXit!! \n");
    printf("========> ");
    n=getche();
    switch(n)
    {
    ///all student result
    case '1':
        all_result();
        break;

    case '0':
        exit(0);

    default:
        system("cls");
        printf("\a");
        result();
        break;
    }
}

///this is our all student data sheet

void all_result()
{
    system("cls");

    fptr=fopen("student.txt","r");
    if(fptr==NULL)
    {
        system("color 4");
        printf("\a\aThere is an error occurred\n\n\n ");
        printf("Go To Entry Menu to create File");
        printf("\n\n\n Program is closing ....");
        getch();
        aboutinfo();
        exit(0);
    }
    system("color 7");
    printf("\n########  All Student Result :\n\n");
    printf("**********************************************************************************\n");
    printf("Roll.No.    Name       Physics  Chemistry  Math  English   ICT  percentage Grade\n");
    printf("==================================================================================\n");
    char ch;
    do
    {
        /* Read single character from file */
        ch = fgetc(fptr);
        /* Print character read on console */
        putchar(ch);
    }
    while(ch != EOF);   /* Repeat this if last read character is not EOF */

    /* Done with this file, close file to release resource */
    fclose(fptr);
    printf("\nPress any key to continue......");
    getch();
    mainsystem();
}

///part one in close ,it means log in + search is done
///by upper part now data add option;
/// this part is for create a student result

void data_student()
{
    system("color 6");

    FILE *fptr;
    fptr=fopen("student.txt","a+");

    printf("\n\t\t\t====|Please Enter The New Details of student|====\n");

    printf("\n======Enter The roll number of student  : ");
    scanf("%d",&st.rollno);

    fflush(stdin);

    printf("\n======Enter The Name of student         : ");
    gets(st.name);

    printf("\nEnter The marks in Physics out of 100   : ");
    scanf("%d",&st.p_marks);

    printf("\nEnter The marks in Chemistry out of 100 : ");
    scanf("%d",&st.c_marks);

    printf("\nEnter The marks in Maths out of 100     : ");
    scanf("%d",&st.m_marks);

    printf("\nEnter The marks in English out of 100   : ");
    scanf("%d",&st.e_marks);

    printf("\nEnter The marks in    ICT    out of 100 : ");
    scanf("%d",&st.cs_marks);

    st.per=(st.p_marks+st.c_marks+st.m_marks+st.e_marks+st.cs_marks)/5.0;

    if(st.per>=80)
        strcpy(st.grade,"A+");

    else if(st.per>=70 &&st.per<80)
        strcpy(st.grade,"A");

    else if(st.per>=60 &&st.per<70)
        strcpy(st.grade,"A-");

    else if(st.per>=50 &&st.per<60)
        strcpy(st.grade,"B");

    else if(st.per>=40 &&st.per<60)
        strcpy(st.grade,"c");

    else if(st.per>=33&&st.per<40)
        strcpy(st.grade,"D");
    else
        strcpy(st.grade,"F");

    /*writing data to the text*/
    fprintf(fptr,"%4d \t %10s \t %5d \t %5d \t %5d \t %5d \t %5d \t %5.2f \t %5s\n",st.rollno,st.name,st.p_marks,st.c_marks,st.m_marks,st.e_marks,st.cs_marks,st.per,st.grade);
    fclose(fptr);
    /*closing file*/
    printf("\n\n\t::::::: Student Record Has Been Created.\n\t\t ::::::any key to continue........");

    getch();
    page_1();
}

///this is our team information

void aboutinfo()
{
    int n;
    system("cls");
    system("color A");
    printf("\n\n\n\n\n\n");
    printf("\t\t===============================================================\n");
    printf("\t\t**--------Welcome to our Result Management system!-----------**\n");
    printf("\t\t**                                                           **\n");
    printf("\t\t**             Back End & Font End Developers:               **\n");
    printf("\t\t**                                                           **\n");
    system("color B");
    printf("\t\t**       [1]Md.Mahfuzur Rahman      || Id:193-15-13416       **\n");
    system("color E");
    printf("\t\t**       [2]Md.Abdullah Ibna Harun  || Id:193-15-13426       **\n");
    system("color D");
    printf("\t\t**       [3]Md.Abidur Rahman Khan   || Id:193-15-13374       **\n");
    system("color 8");
    printf("\t\t**       [4]Md.Mahadi Hassan Forhad || Id:193-15-13355       **\n");
    printf("\t\t**                                                           **\n");
    system("color 7");
    printf("\t\t**       |||>>> Thank you for using our software <<<|||      **\n");
    system("color 6");
    printf("\t\t**                                                           **\n");
    system("color 4");
    printf("\t\t**     (C)2020 PPS Project  Group:2  All Rights Reserved     **\n");
    printf("\t\t**                                                           **\n");
    printf("\t\t**                                                           **\n");
    system("color A");
    printf("\t\t**                Press any key for Main Menu!!...           **\n");
    printf("\t\t**                Press [0] for Exit!!...                    **\n");
    printf("\t\t**                                                           **\n");
    printf("\t\t===============================================================\n");
    system("color A");
    printf("\t\t\n\n=========>>Enter Your Choice :");
    n=getche();
    switch (n)
    {
    case '0':
        system("cls");
        exit(0);
        break;
    default:
        system("cls");
        mainsystem();
        break;
    }
}

///this is the front page;

void mainsystem()
{
    int n;
    system("cls");
    system("color A");
    printf("\n\n\n\n\n\n");
    printf("\t\t*************************************************************\n");
    printf("\t\t**----------Welcome to Result Management system!-----------**\n");
    printf("\t\t**                                                         **\n");
    printf("\t\t**                                                         **\n");
    system("color B");
    printf("\t\t**             [1] Login                                   **\n");
    system("color E");
    printf("\t\t**             [2] Register as Class teacher               **\n");
    system("color 8");
    printf("\t\t**             [3] Show all result                         **\n");
    system("color 7");
    printf("\t\t**             [4] Go to Developer option                  **\n");
    system("color 6");
    printf("\t\t**             [0] EXIT!                                   **\n");
    system("color 4");
    printf("\t\t**                                                         **\n");
    system("color A");
    printf("\t\t**                                                         **\n");
    printf("\t\t*************************************************************\n");
    system("color B");
    printf("\t\t\n\n=========>>Enter Your Choise :");

    n=getche();

    switch (n)
    {
    case '1':
        system("cls");
        login();
        break;
    case '2':
        system("cls");
        reg();
        break;
    case '3':
        system("cls");
        all_result();
        break;
    case '0':
        system("cls");
        exit(0);
        break;
    case '4':
        system("cls");
        aboutinfo();
        break;
    default :
        system("cls");
        mainsystem();
        break;
    }

}
///this is main function
int main()
{
    mainsystem();
    return 0;
}
