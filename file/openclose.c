#include<stdio.h>
int main()
{
    FILE *file;
    char a[20] = "Suvo nobobrsho ";
    int length = strlen(a);
    int i;
    file = fopen("test.txt","w");
    if(file == NULL)
    {
        printf("Your file dose not exist");
    }
    else
    {
        printf("Your file is opened \n");
        for(i=0;i<length;i++)
        {
            fputc(a[i],file);
        }
        printf("Your file is written successfully ");
        fclose(file);
    }
    return 0;
}
