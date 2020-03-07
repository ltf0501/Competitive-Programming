#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,L;
ll c[35];
bool flag[35];
bool vis[35];
vector<int> v;
main()
{
    scanf("%d%d",&n,&L);
    for(int i=0;i<n;i++)scanf("%I64d",&c[i]);
    int hi=0;
    for(int i=30;i>=0;i--)
    {
        if(L&(1<<i))
        {
            v.push_back(i),vis[i]=1;
            if(!hi)hi=i;
        }
    }
    for(int i=1;i<n;i++)if(c[i]>2*c[i-1])c[i]=2*c[i-1];
    ll ans=4e18,cur=0;
    for(int i=n-1;i>=0;i--)
    {
        ll tmp=L/(1<<i);
        if(L%(1<<i)==0){ans=min(ans,cur+tmp*c[i]);break;}
        ans=min(ans,cur+(tmp+1)*c[i]);
        cur+=tmp*c[i],L%=(1<<i);
    }
    printf("%I64d\n",ans);
    return 0;
}
/*
4 3
10 100 1000 10000
*/
