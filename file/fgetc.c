#include<stdio.h>
int main()
{
    FILE *file;
    char ch;
    file = fopen("test.txt","r");
    if(file == NULL)
    {
        printf("Your file dose not exist");
    }
    else
    {
        printf("Your file is opened \n");
       while(!feof(file))
       {
           ch = fgetc(file);
           printf("%c",ch);
       }
        printf("Your file is written successfully ");
        fclose(file);
    }
    return 0;
}

