#include<stdio.h>
int main()
{
    FILE *file;
    char ch[100];
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
           fgets(ch,100,file);
           printf("\n");
           printf("%s\n",ch);

       }
        printf("Your file is written successfully ");
        fclose(file);
    }
    return 0;
}

