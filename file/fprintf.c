#include<stdio.h>
int main()
{
    FILE *file;
    char name[20];
    int age;
    file = fopen("test.txt","a");
    if(file == NULL)
    {
        printf("Your file dose not exist");
    }
    else
    {
        printf("Your file is opened \n");
        printf("Enter your name :");
        gets(name);
        printf("Enter your age :");
        scanf("%d",&age);
        fprintf(file,"Name = %s, Age = %d \n",name,age);
        printf("Your file is written successfully ");
        fclose(file);
    }
    return 0;
}

