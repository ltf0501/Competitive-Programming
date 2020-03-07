#include<bits/stdc++.h>
using namespace std;
#define maxn 3000010
int a[maxn],r[maxn];
bool vis[maxn];
main()
{
    int na=0,nb=0;
    char c='0';
    while(c!='\n')
    {
        int p=0;
        c=getchar();
        while('0'<=c && c<='9')
            p=p*10+(c-'0'),c=getchar();
        a[++na]=p;
    }
    c='0';
    while(c!='\n')
    {
        int p=0;
        c=getchar();
        while('0'<=c && c<='9')
            p=p*10+(c-'0'),c=getchar();
        r[p]=++nb;
    }
    //printf("%d %d\n",na,nb);
    if(na!=nb)return 0*puts("-1");
    int ans=na;
    for(int i=1;i<=na;i++)if(!vis[i])
    {
        ans--;
        while(!vis[i])vis[i]=1,i=a[r[i]];
    }
    printf("%d\n",ans);
    return 0;
}
