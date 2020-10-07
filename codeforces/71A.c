#include<stdio.h>
#include<string.h>
int main()
{
    int x,i,len;
    char str[500];
    scanf("%d",&x);
    for(i=0;i<=x;i++)
    {
        scanf("%s",&str);
        len = strlen(str);
        if(len<=10)
        {
            printf("%s\n",str);
        }
        else
        {
            printf("%c%d%c\n",str[0],len-2,str[len-1]);
        }
    }
    return 0;
}
