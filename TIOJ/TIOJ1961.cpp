#include<bits/stdc++.h>
//#include"lib1961.h"
using namespace std;
#define maxn 100010
#define maxm 1000010
#define ll long long
const ll INF=1e15;
int n,m,k;
struct P
{
    int l,r;
    bool operator < (const P& b)const
    {
        if(l!=b.l)return l<b.l;
        return r>b.r;
    }
}c[maxn];
vector<P> v;
ll dp[maxn],tmp[maxn];
ll square(ll x){return x*x;}
ll a(int i){return -2*(c[i+1].l-1);}
ll b(int i){return dp[i]+square((ll)(c[i+1].l-1))-square(1ll*max(0,c[i].r-c[i+1].l+1));}
deque<int> dq;
main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        x++,y++;
        if(x>y)swap(x,y);
        v.push_back({x,y});
    }
    sort(v.begin(),v.end());
    int num=0;
    for(P s : v)
    {
        if(c[num].l<=s.l && s.r<=c[num].r)continue;
        c[++num]=s;
    }
    n=num;
    for(int i=1;i<=n;i++)printf("%d %d\n",c[i].l,c[i].r);
    for(int i=1;i<=n;i++)dp[i]=INF;
    for(int s=1;s<=k;s++)
    {
        dq.clear();
        dq.push_back(0);
        for(int i=1;i<=n;i++)
        {
            tmp[i]=INF;
            for(int j=0;j<i;j++)
                if(dp[j]!=INF)tmp[i]=min(tmp[i],dp[j]+square(1ll*(c[i].r-c[j+1].l+1))-square(1ll*(max(0,c[j].r-c[j+1].l+1))));
            //for(int j=0;j<i;j++)tmp[i]=min(tmp[i],square(1ll*c[i].r)+a(j)*c[i].r+b(j));
            /*
            while(dq.size()>=2)
            {
                int l=dq[0],j=dq[1];
                if(1ll*c[i].r*(a(l)-a(j))>=b(j)-b(l))dq.pop_front();
                else break;
            }
            int j=dq.front();
            tmp[i]=square(1ll*c[i].r)+a(j)*c[i].r+b(j);
            while(dq.size()>=2)
            {
                int j=dq[dq.size()-1],l=dq[dq.size()-2];
                if(1ll*(a(l)-a(j))*(b(i)-b(j))<=1ll*(a(j)-a(i))*(b(j)-b(l)))dq.pop_back();
                else break;
            }
            dq.push_back(i);
            */
        }
        for(int i=1;i<=n;i++)dp[i]=tmp[i];
        for(int i=1;i<=n;i++)printf("%lld ",dp[i]);puts("");
    }
    printf("%lld\n",dp[n]);
    return 0;
}

/*
5 7 2
0 3
4 4
4 6
4 5
4 6
ans=25

6 7 3
0 4
2 1
2 6
5 3
5 7
6 5

*/
