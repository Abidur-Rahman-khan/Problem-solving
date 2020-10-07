#include<stdio.h>
int main()
{
    FILE *file;
    char fname[20];
    char lname[20];
    int age;
    file = fopen("test.txt","r");
    if(file == NULL)
    {
        printf("Your file dose not exist");
    }
    else
    {
        printf("Your file is opened \n");
        fscanf(file,"%s %s  %d",&fname,&lname,&age);
        printf("%s\t%s\t%d\n",fname,lname,age);
        printf("Your file is written successfully ");
        fclose(file);
    }
    return 0;
}


