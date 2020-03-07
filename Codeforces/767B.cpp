#include<bits/stdc++.h>
using namespace std;
#define maxn 100000+10
#define INF 1e12+5
#define ll long long
ll ts,tf,t,ans,m=INF;
int n;
main()
{
    scanf("%I64d%I64d%I64d%d",&ts,&tf,&t,&n);
    if(!n){printf("%I64d\n",ts);return 0;}
    for(int i=1;i<=n;i++)
    {
        ll a;scanf("%I64d",&a);
        if(a && a<=tf-t)
        {
            if(max(ts,a-1)<=tf-t && ts-a+1<m)m=ts-a+1,ans=min(ts,a-1);
            ts=max(ts,a)+t;
        }
    }
    if(ts<=tf-t)ans=ts;
    printf("%I64d\n",ans);
    return 0;
}
