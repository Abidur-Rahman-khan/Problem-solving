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


//FILE *fptr;


///this is the registration part

void reg()
{

    FILE *log;

    log=fopen("project.txt","a");
    struct login l;

    printf("\n\t\t\t======> Enter your first name : ");
    scanf("%s",l.fname);
    printf("\n\t\t\======> Enter your last name : ");
    scanf("%s",l.lname);
    printf("\n\t\t\======> Enter Your email : ");
    scanf("%s",l.email);
    printf("\n\t\t\======> Enter your user name : ");
    scanf("%s",l.username);
    printf("\n\t\t\======> Enter your password: ");
    scanf("%s",l.password);

    fwrite(&l,sizeof(l),1,log);
    fprintf(log,"%s\t%s\t\t%s\t%s\t%s\n",l.fname,l.lname,l.email,l.username,l.password);



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

    }


 fclose(log);


}
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
    printf("\t\t**                                **\n");
    system("color 8");
    printf("\t\t**                              **\n");
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
        //aboutinfo();
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
