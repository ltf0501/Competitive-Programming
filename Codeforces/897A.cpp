#include<bits/stdc++.h>
using namespace std;
int n,m;
char c[105];
main()
{
    scanf("%d%d",&n,&m);
    scanf("%s",c+1);
    for(int i=1;i<=m;i++)
    {
        int l,r;char a,b;
        scanf("%d %d %c %c",&l,&r,&a,&b);
        for(int j=l;j<=r;j++)if(c[j]==a)c[j]=b;
    }
    printf("%s\n",c+1);
    return 0;
}

