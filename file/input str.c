#include<stdio.h>
int main()
{
    FILE *file;
    char a[20];
    file = fopen("test.txt","a");
    if(file == NULL)
    {
        printf("Your file dose not exist");
    }
    else
    {
        printf("Your file is opened \n");
        printf("Enter your string :\n");
        gets(a);
        fputs(a,file);
        fputs("\n",file);
        printf("Your file is written successfully ");
        fclose(file);
    }
    return 0;
}

