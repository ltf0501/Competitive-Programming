#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10;
struct P{int x,y,k;};
bool cmp1(const P &a,const P &b)
{
    return a.k==b.k ? (a.x==b.x ? a.y<b.y : a.x<b.x) : a.k<b.k;
}
bool cmp2(const P &a,const P &b)
{
    return a.k==b.k ? (a.x==b.x ? a.y<b.y : a.x<b.x) : a.k>b.k;
}
vector<P> v;
int p[maxn],n;
int finds(int x)
{
    return p[x]==x ? x : p[x]=finds(p[x]);
}
int Kruskal()
{
    for(int i=1;i<=n;i++)p[i]=i;
    int cnt=1,ans=0;
    for(auto i : v)
    {
        int x=finds(i.x),y=finds(i.y);
        if(x==y)continue;
        p[x]=y;ans+=i.k;
        if((++cnt)==n)return ans;
    }
    return -1;
}
main()
{
    int m,k;scanf("%d%d%d",&n,&m,&k);
    while(m--)
    {
        int x,y,w;scanf("%d%d%d",&x,&y,&w);
        v.push_back((P){x,y,w});
    }
    sort(v.begin(),v.end(),cmp1);
    int mi=Kruskal();
    sort(v.begin(),v.end(),cmp2);
    int ma=Kruskal();
    if(k<=ma && k>=mi)puts("TAK");
    else puts("NIE");
}
