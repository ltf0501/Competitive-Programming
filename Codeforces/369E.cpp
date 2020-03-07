#include<bits/stdc++.h>
using namespace std;
#define maxn 300010
#define maxc 1000010
#define pii pair<int,int>
#define F first
#define S second
pii a[maxn];
int ans[maxn];
vector<int> q[maxn];
vector<int> ls[maxc];
vector<pii> q2[maxc];
int n,m;
int bit[maxc];
void add(int x,int d)
{
    for(int i=x;i<maxc;i+=i&-i)bit[i]+=d;
}
int query(int x)
{
    int ret=0;
    for(int i=x;i;i-=i&-i)ret+=bit[i];
    return ret;
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d%d",&a[i].F,&a[i].S),ls[a[i].S].push_back(a[i].F);
    for(int i=1;i<=m;i++)
    {
        int cnt;scanf("%d",&cnt);
        q[i].push_back(0);
        while(cnt--)
        {
            int x;scanf("%d",&x);
            q[i].push_back(x);
        }
        q[i].push_back((int)(1e6+5));
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<q[i].size()-1;j++)
        {
            int l=q[i][j]+1,r=q[i][j+1]-1;
            q2[r].push_back(pii(l,i));
        }
    }
    for(int i=0;i<maxc;i++)
    {
        for(int s : ls[i])add(s,1);
        for(pii s : q2[i])ans[s.S]+=query(i)-query(s.F-1);
    }
    for(int i=1;i<=m;i++)printf("%d\n",n-ans[i]);
    return 0;
}
