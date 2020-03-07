#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
int cnt[maxn],tmp[maxn];
int t;
bool check(int n,int m,int x,int y)
{
   // printf("now: %d %d %d %d\n",n,m,x,y);
    memset(tmp,0,sizeof(tmp));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)tmp[abs(x-i)+abs(y-j)]++;
    for(int i=0;i<t;i++)if(cnt[i]!=tmp[i])return 0;
    return 1;
}
main()
{
    scanf("%d",&t);
    int mx=0;
    for(int i=1;i<=t;i++)
    {
        int x;scanf("%d",&x);
        cnt[x]++;
        mx=max(mx,x);
    }
    if(cnt[0]!=1)return 0*puts("-1");
    int mi;
    for(int i=1;i<=t;i++)if(cnt[i]!=4*i){mi=i;break;}
    //for(int i=0;i<=mx;i++)printf("%d ",cnt[i]);puts("");
    for(int n=1;n<=t;n++)if(t%n==0)
    {
        int m=t/n;
        int x=mi;
        int y=mx+2-x;
        if(check(n,m,x,y))return 0*printf("%d %d %d %d\n",n,m,x,y);
        y=n+m-x-mx;
        if(check(n,m,x,y))return 0*printf("%d %d %d %d\n",n,m,x,y);
    }
    puts("-1");
    return 0;
}
