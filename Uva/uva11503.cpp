#include<bits/stdc++.h>
using namespace std;
#define maxn 200000+10
int p[maxn],sz[maxn];
map<string,int> mp;
int finds(int x)
{
    return p[x]==x ? x : p[x]=finds(p[x]);
}
int Union(int x,int y)
{
    x=finds(x),y=finds(y);
    if(x==y)return sz[x];
    if(sz[x]<sz[y])
    {
        p[x]=y,sz[y]+=sz[x];
        return sz[y];
    }
    p[y]=x,sz[x]+=sz[y];
    return sz[x];
}
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        mp.clear();
        for(int i=1;i<=200000;i++)p[i]=i,sz[i]=1;
        int n;scanf("%d",&n);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            string a,b;cin>>a>>b;
            if(!mp.count(a))mp[a]=++cnt;
            if(!mp.count(b))mp[b]=++cnt;
            printf("%d\n",Union(mp[a],mp[b]));
        }
    }
    return 0;
}
