#include<cstdio>
int main()
{
    int a;
    scanf("%d",&a);
    for(int i=2;i*i<=a;i++)
    {
        if(a%i==0) printf("%d\n",a/i);
    }
    return 0;
}
