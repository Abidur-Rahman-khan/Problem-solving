#include<stdio.h>
#include<conio.h>
#include<string.h>

int write_student()
   {
       int rollno,pm,cm,mm,em,csm,stper;
       char stname[20],stgrade;
    //fptr=fopen("student.dat","ab");
    printf("\nPlease Enter The New Details of student \n");
    printf("\nEnter The roll number of student ");
    scanf("%d",&rollno);
    //fflush(stdin);
    printf("\n\nEnter The Name of student :\n");
    gets(stname);
    printf("\nEnter The marks in physics out of 100 : ");
    scanf("%d",&pm);
    printf("\nEnter The marks in chemistry out of 100 : ");
    scanf("%d",&cm);
    printf("\nEnter The marks in maths out of 100 : ");
    scanf("%d",&mm);
    printf("\nEnter The marks in english out of 100 : ");
    scanf("%d",&em);
    printf("\nEnter The marks in computer science out of 100 : ");
    scanf("%d",&csm);
    stper=(pm+cm+mm+em+csm)/5.0;
    if(stper>=60)
       stgrade='A';
    else if(stper>=50 &&stper<60)
      stgrade='B';
    else if(stper>=33 &&stper<50)
      stgrade='C';
    else
     stgrade='F';
   // fwrite(&st,sizeof(st),1,fptr);
    //fclose(fptr);
    printf("\n\nStudent Record Has Been Created ");
    getch();
}
int main()
{
    int data;

    data=write_student();
    return 0;
}
