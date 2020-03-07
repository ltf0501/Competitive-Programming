#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int vis[15]={0};
int a[30];
int n,r;
int cnt;
void backtrack(int now)
{
    if(now==r)
    {
        cnt++;
        if(cnt==n+r)
        {
            for(int i=0;i<r;i++)printf("%d",a[i]);
            puts("");
        }
        return ;
    }
    for(int i=n-1;i>=0;i--)
    {
        if(!vis[i])
        {
            vis[i]=1;
            a[now]=i;
            backtrack(now+1);
            vis[i]=0;
        }
    }
}
main()
{
    scanf("%d%d",&n,&r);
    cnt=0;

    if(r==1 || (n==2 && r==2))
    {
        for(int i=0;i<r;i++)printf("%d",i);
        puts("");
        return 0;
    }

    backtrack(0);

    return 0;
}
