#include<bits/stdc++.h>
using namespace std;
char s[4];
int a[4];
bool flag[4];
main()
{
    scanf("%s",s);
    for(int i=0;i<4;i++)a[i]=s[i]-'0';
    for(int i=0;i<=2;i+=2)for(int j=0;j<=2;j+=2)for(int k=0;k<=2;k+=2)
        if(a[0]+(i-1)*a[1]+(j-1)*a[2]+(k-1)*a[3]==7)
        {
            printf("%d%c%d%c%d%c%d=7\n",a[0],i?'+':'-',a[1],j?'+':'-',a[2],k?'+':'-',a[3]);
            return 0;
        }
    return 0;
}
