#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <dos.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define ROW 3
#define COL 5


/// this is the structure part
struct login
{
    char fname[20];
    char lname[20];
    char username[20];
    char password[32];
    char email[100];
};

struct student
{
    int rollno;
    char name[50];
    int p_marks,c_marks,m_marks,e_marks,cs_marks;
    float per;
    char grade;
    int std;
} st;

FILE *fptr;

///this is the registration part

void reg()
{

    FILE *log;

    log=fopen("project.txt","w+");
    struct login l;
    printf("\n\t\t\t======> Enter your first name : ");
    scanf("%s",l.fname);
    printf("\n\t\t\======> Enter your last name ");
    scanf("%s",l.lname);
    printf("\n\t\t\======> Enter Your email");
    scanf("%s",l.email);
    printf("\n\t\t\======> Enter your user name ");
    scanf("%s",l.username);
    printf("\n\t\t\======> Enter your password");
    scanf("%s",l.password);

    fwrite(&l,sizeof(l),1,log);

    fclose(log);

    printf("press any key to continue .........");

    system("cls");

    login();

}

/// this is the log in part



void login()
{
    char username[200],password[20];
    FILE *log;
    log=fopen("project.txt","r");
    struct login l;
    system("color 7");
    printf("\n\t\t\>>>>>>>>>>> UserID   : ");
    scanf("%s",&username);
    system("color 8");
    printf("\n\t\t\>>>>>>>>>>> Password : ");
    scanf("%s",&password);


    while(fread(&l,sizeof(l),1,log))
    {
        if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0)
        {
            system("color B");
            printf("successfully log in\n");
        }
        else
        {
            system("color 4");
            printf("log in failed \a");
        }
        getch();
    }

    printf("Loading please wait");

    page_1();
}



///this is our App page 1 after log in

void page_1()

{
    char ch;

    system("cls");
    printf("\n\n\n\t Welcome to our Result Management");
    printf("\n\n\t [01] Go For Published Result ");
    printf("\n\n\t [02] ENTRY/EDIT MENU");
    printf("\n\n\t [03] EXIT");
    printf("\n\n\tPlease Select Your Option (1-3) ");
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
        exit(0);
    default :
        printf("\a");
    }

}

/// this is our page no 2 from log in ,case number 1 ////////// avoid this function///////

void result ()
{
    int n,roll;

    system("cls");
    printf("Welcome to Publish your Result ");
    printf("\n\n\n\n     [1] Class Result ");
    printf("\n\n         [2] Search individual Result");
    n=getche();
    switch(n)
    {
    ///all student result

    case '1':
        all_result();
        break;

    ///search by roll number case 2
    case '2':
        system("cls");
        printf("\n\n Search Roll Number: ");
        scanf("%d",&roll);
        search(roll);
        break;
    }

}


///this is our all student data sheet



void all_result()
{
    system("cls");

    fptr=fopen("student.dat","rb");
    if(fptr==NULL)
    {
        printf("There is an error occurred\n\n\n ");
        printf("Go To Entry Menu to create File");
        printf("\n\n\n Program is closing ....");
        getch();
        exit(0);
    }
    printf("====================================================\n");
    printf("R.No.  Name       P   C   M   E   CS  percantage   Grade\n");
    printf("====================================================\n");

    while((fread(&st,sizeof(st),1,fptr))>0)
    {
        printf("%-6d %-10s %-3d %-3d %-3d %-3d %-3d %-3.2f  %-1c\n",st.rollno,st.name,st.p_marks,st.c_marks,st.m_marks,st.e_marks,st.cs_marks,st.per,st.grade);
    }
    fclose(fptr);
    getch();
}


///this is the part 1 , 2nd option individual result;


void search(int n)
{

    int flag=0;
    fptr=fopen("student.dat","rb");
    while((fread(&st,sizeof(st),1,fptr))>0)
    {
        if(st.rollno==n)
        {
            system("CLS");
            printf("\nRoll number of student : %d",st.rollno);
            printf("\nName of student : %s",st.name);
            printf("\nMarks in Physics : %d",st.p_marks);
            printf("\nMarks in Chemistry : %d",st.c_marks);
            printf("\nMarks in Maths : %d",st.m_marks);
            printf("\nMarks in English : %d",st.e_marks);
            printf("\nMarks in Computer Science : %d",st.cs_marks);
            printf("\nPercentage of student is  : %.2f",st.per);
            printf("\nGrade of student is : %c",st.grade);
            flag=1;
        }
    }
    fclose(fptr);
    if(flag==0)
        printf("\n\nrecord not exist");
    getch();
}

///part one in close ,it means log in + search is done
///by upper part now data add option;

/// this part is for create a student result ;



void data_student()
{
    fptr=fopen("student.dat","ab");

    printf("\nPlease Enter The New Details of student \n");

    printf("\nEnter The roll number of student ");
    scanf("%d",&st.rollno);

    fflush(stdin);

    printf("\n\nEnter The Name of student ");
    gets(st.name);

    printf("\nEnter The marks in physics out of 100 : ");
    scanf("%d",&st.p_marks);

    printf("\nEnter The marks in chemistry out of 100 : ");
    scanf("%d",&st.c_marks);

    printf("\nEnter The marks in maths out of 100 : ");
    scanf("%d",&st.m_marks);

    printf("\nEnter The marks in english out of 100 : ");
    scanf("%d",&st.e_marks);

    printf("\nEnter The marks in computer science out of 100 : ");
    scanf("%d",&st.cs_marks);

    st.per=(st.p_marks+st.c_marks+st.m_marks+st.e_marks+st.cs_marks)/5.0;


    if(st.per>=80)
        st.grade='A+';

    else if(st.per>=70 &&st.per<80)
        st.grade='A';

    else if(st.per>=60 &&st.per<70)
        st.grade='A-';

    else if(st.per>=50 &&st.per<60)
        st.grade='B';

    else if(st.per>=40 &&st.per<60)
        st.grade='c';

    else if(st.per>=33&&st.per<40)
        st.grade='D';


    else
        st.grade='F';

    fwrite(&st,sizeof(st),1,fptr);
    fclose(fptr);
    printf("\n\nStudent Record Has Been Created ");
    getch();
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
    printf("\t\t**             Back End & Font End Developers:                **\n");
    printf("\t\t**                                                           **\n");
    system("color B");
    printf("\t\t**       [1]Md.Mahfuzur Rahman      || Id:193-15-13416       **\n");
    system("color E");
    printf("\t\t**       [2]Md.Abdullah Ibna Harun  || Id:193-15-13426       **\n");
    system("color D");
    printf("\t\t**       [3]Md.Abidur Rahman Khan   || Id:193-15-13374       **\n");
    system("color 8");
    printf("\t\t**       [4]Md.Mahadi Hassan Forhad || Id:193-15-13355       **\n");
    system("color 7");
    printf("\t\t**                                                           **\n");
    system("color 6");
    printf("\t\t**                                                           **\n");
    system("color 4");
    printf("\t\t**     (C)2020 PPS Project  Group:2  All Rights Reserved     **\n");
    printf("\t\t**                                                           **\n");
    printf("\t\t**                                                           **\n");
    system("color A");
    printf("\t\t**                Press [1] for Main Manu!!...               **\n");
    printf("\t\t**                Press [0] for Exit!!...                    **\n");
    printf("\t\t**                                                           **\n");
    printf("\t\t===============================================================\n");
    system("color A");
    n=getche();
    switch (n)//👎
    {
    case '1':
        system("cls");
        mainsystem();
        break;
    case '0':
        system("cls");
        exit(0);
        break;
    }
}


///this is the main function;


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
    printf("\t\t**             [1]Login                                    **\n");
    system("color E");
    printf("\t\t**             [2]Register as Class teacher                **\n");
    system("color D");
    printf("\t\t**             [3]Register as Student                      **\n");
    system("color 8");
    printf("\t\t**             [4]Go to Developer option                   **\n");
    system("color 7");
    printf("\t\t**                                                         **\n");
    system("color 6");
    printf("\t\t**                                                         **\n");
    system("color 4");
    printf("\t\t**                                                         **\n");
    system("color A");
    printf("\t\t**                                                         **\n");
    printf("\t\t*************************************************************\n");
    system("color B");
    printf("\t\t\n\n=========>>Enter Your Choise :");

    n=getche();

    switch(n)
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

        break;

    case '4':
        system("cls");
        aboutinfo();
        break;

    case '5':
        system("cls");
    default :
        system("cls");

    }

}

int main()
{
    mainsystem();
    return 0;
}
