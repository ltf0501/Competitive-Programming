#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100010
vector<int> pos[maxn];
int n;
int bit[maxn];
void add(int x,int d)
{
    for(int i=x;i<=n;i+=i&-i)bit[i]+=d;
}
int query(int x)
{
    int ret=0;
    for(int i=x;i;i-=i&-i)ret+=bit[i];
    return ret;
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        pos[x].push_back(i);
    }
    for(int i=1;i<=n;i++)
    {
        bit[i]++;
        if(i+(i&-i)<=100000)bit[i+(i&-i)]+=bit[i];
    }
    ll ans=0;
    int cur=0;
    for(int i=1;i<=100000;i++)
    {
        if(pos[i].empty())continue;
        int k=lower_bound(pos[i].begin(),pos[i].end(),cur)-pos[i].begin();
        k--;
        //printf("%d\n",k);
        if(k==-1)
        {
            ans+=query(*(--pos[i].end()))-query(cur);
            cur=*(--pos[i].end());
        }
        else
        {
            ans+=query(n)-query(cur)+query(pos[i][k]);
            cur=pos[i][k];
        }
        //printf("%d: %d\n",i,cur);
        for(int j : pos[i])add(j,-1);
    }
    printf("%lld\n",ans);

    return 0;
}
