#include<cstdio>
#include<cstring>
int main()
{
    char x[1000];
    while(~scanf("%s",&x))
    {
        int s=strlen(x),sum=0,fact1=0,fact2=0,fact3=0;
        if(s>=8)sum++;
        for(int i=0;i<s;i++)
        {
            if((x[i]>='a' && x[i]<='z')) fact1++;
            else if(x[i]>='A' && x[i]<='Z') fact2++;
            else fact3++;
        }
        if(fact1>0 && fact2>0)sum++;
        if(fact1+fact2>0 && fact3>0)sum++;

        printf("This password is ");
        if(sum==3) printf("STRONG");
        else if(sum==2) printf("GOOD");
        else if(sum==1) printf("ACCEPTABLE");
        else printf("WEAK");
        printf("\n");
    }
}
