#include<bits/stdc++.h>
using namespace std;
char c[55];
main()
{
    scanf("%s",c);
    int n=strlen(c);
    bool flag=1;
    for(int i=1;i<n;i++)
        if(c[i]!=c[0]){flag=0;break;}
    if(flag)return 0*puts("0");
    flag=1;
    for(int i=0;i<n/2;i++)
        if(c[i]!=c[n-i-1]){flag=0;break;}
    if(flag)printf("%d\n",n-1);
    else printf("%d\n",n);
    return 0;
}
