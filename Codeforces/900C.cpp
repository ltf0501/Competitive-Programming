#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int n,p[maxn];
int cnt[maxn];
bool check[maxn];
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&p[i]);
    int mx=0,secmx=0;
    for(int i=1;i<=n;i++)
    {
        if(p[mx]<p[i])secmx=mx,mx=i,check[p[i]]=1;
        else if(p[secmx]<p[i])secmx=i,cnt[p[mx]]++;
    }
    int t=1;
    ///for(int i=1;i<=n;i++)printf("%d ",cnt[i]);puts("");
    ///for(int i=1;i<=n;i++)printf("%d ",check[i]);puts("");
    for(int i=2;i<=n;i++)
    {
        if(cnt[i]-check[i]>cnt[t]-check[t])t=i;
    }
    printf("%d\n",t);
    return 0;
}
