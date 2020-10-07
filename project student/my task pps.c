//student mark section//
struct student
{
 int rollno;
 char name[50];
 int phymarks,chemmarks,mathmarks,engmarks,csmarks;
 float avg;
 char grade;
}
int write_student()
   {
    printf("\nPlease Enter The New Details of student \n");
    printf("\nEnter The roll number of student ");
    scanf("%d",&rollno);
    printf("\n\nEnter The Name of student ");
    gets(name);
    printf("\nEnter The marks in physics out of 100 : ");
    scanf("%d",&phymarks);
    printf("\nEnter The marks in chemistry out of 100 : ");
    scanf("%d",&chemmarks);
    printf("\nEnter The marks in maths out of 100 : ");
    scanf("%d",&mathmarks);
    printf("\nEnter The marks in english out of 100 : ");
    scanf("%d",&engmarks);
    printf("\nEnter The marks in computer science out of 100 : ");
    scanf("%d",&csmarks);
    avg=(phymarks+chemmarks+mathmarks+engmarks+csmarks)/5.0;
    if(avg>=60)
    grade='A';
    else if(avg>=50 && avg<60)
      grade='B';
    else if(avg>=33 && avg<50)
      grade='C';
    else
     grade='F';
    printf("\n\nStudent Record Has Been Created ");
   // getch();
   return write_student;
}
int display_all()
{
    system("CLS");
    printf("\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n");
    {
      printf("\nRoll Number of Student : %d",rollno);
      printf("\nName of student : %s",name);
      printf("\nMarks in Physics : %d",phymarks);
      printf("\nMarks in Chemistry : %d",chemmarks);
      printf("\nMarks in Maths : %d",mathmarks);
      printf("\nMarks in English : %d",engmarks);
      printf("\nMarks in Computer Science : %d",csmarks);
      printf("\nPercentage of student is  : %.2f",avg);
      printf("\nGrade of student is : %c",grade);
      printf("\n\n====================================\n");
    }
    return display_all;
}
#include<stdio.h>
#include<windows.h>
int main()
{
  int intput,output;
   input=write_student();
   output=display_all();
  return 0;
}
