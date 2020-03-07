#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
int n,m;
ll s[maxn];
main()
{
    scanf("%d%d",&n,&m);
    ll sum1=0,sum2=0;
    for(int i=1;i<=n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        sum1+=x,sum2+=y;
        s[i]=x-y;
    }
    if(sum2>m)return 0*puts("-1");
    sort(s+1,s+n+1,greater<ll>());
    if(sum1<=m)return 0*puts("0");
    for(int i=1;i<=n;i++)
    {
        sum1-=s[i];
        if(sum1<=m)return 0*printf("%d\n",i);
    }
    return 0;
}
