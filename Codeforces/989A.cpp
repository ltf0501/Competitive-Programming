#include<bits/stdc++.h>
using namespace std;
char c[105];
bool vis[3];
main()
{
    scanf("%s",c+1);
    int n=strlen(c+1);
    c[0]='.',c[n+1]='.';
    for(int i=2;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        bool flag=0;
        for(int j=0;j<3;j++)if(c[i+j-1]=='.'){flag=1;break;}
        if(flag)continue;
        flag=1;
        for(int j=0;j<3;j++)vis[c[i+j-1]-'A']=1;
        for(int j=0;j<3;j++)if(!vis[j]){flag=0;break;}
        if(flag)return 0*puts("YES");
    }
    puts("NO");
    return 0;
}

