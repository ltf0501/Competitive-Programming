#include<bits/stdc++.h>
using namespace std;
struct G
{
    vector<int> v;
    bool operator < (const G& rhs) const
    {
        for(int i=0;i<min(v.size(),rhs.v.size());i++)
        {
            if(v[i]>rhs.v[i])return 1;
            if(v[i]<rhs.v[i])return 0;
        }
        if(v.size()>rhs.v.size())return 1;
        return 0;
    }
    bool operator != (const G& b) const
    {
        return (b<*this) || (*this<b);
    }
}g[105];
map<string,G> mp;
bool cmp(int x,int y){return x>y;}
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        string s;
        int k;
        cin>>s>>k;
        for(int j=0;j<k;j++)
        {
            int x;scanf("%d",&x);
            g[i].v.push_back(x);
        }
        //for(int m : g[i].v)printf("%d ",m);puts("");
        sort(g[i].v.begin(),g[i].v.end(),cmp);
        mp[s]=g[i];
    }
    sort(g+1,g+n+1);
    string s;
    while(cin>>s)
    {
        int cnt=0;
        int now=1;
        while(mp[s]!=g[now])
        {
            now++;
            if(g[now]!=g[now-1])cnt++;
        }
        printf("%d\n",cnt+1);
    }
    return 0;
}
