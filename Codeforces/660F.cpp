#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
int a[maxn];
ll sum[maxn],p[maxn];
int n;
ll y(int i){return p[i]-i*sum[i];}
deque<int> dq;
ll gao(int i,int j){return p[i]-p[j]-j*(sum[i]-sum[j]);}
int sol(ll x)
{
    int sz=dq.size();
    if(sz==1)return dq[0];
    int l=0,r=sz-2,ret=0;
    while(l<=r)
    {
        int m=(l+r)>>1;
        if(y(dq.at(m+1))-y(dq.at(m))<-x*(dq.at(m+1)-dq.at(m)))l=m+1,ret=m+1;
        else r=m-1;
    }
    return dq[ret];
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
        p[i]=p[i-1]+1ll*i*a[i];
    }
    dq.push_back(0);
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        int j=sol(sum[i]);
        ans=max(ans,gao(i,j));
        while(dq.size()>=2)
        {
            int j=dq.back();dq.pop_back();
            int k=dq.back();
            if((y(i)-y(j))*(j-k)>=(y(j)-y(k))*(i-j))
            {
                dq.push_back(j);
                break;
            }
        }
        dq.push_back(i);
    }
    printf("%I64d\n",ans);
    return 0;
}
