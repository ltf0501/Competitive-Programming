#include<bits/stdc++.h>
using namespace std;
#define maxn 5050
#define SZ(v) (int)v.size()
vector<int> v[maxn];
vector<int> lg;
int n,m;
int dis(int now,int pos)
{
    if(now>=pos)return now-pos;
    return now+(n-pos);
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int a,b;scanf("%d%d",&a,&b);
        a--,b--;
        v[a].push_back(b);
    }
    for(int i=0;i<n;i++)sort(v[i].begin(),v[i].end());
    int mx=0;
    for(int i=0;i<n;i++)
    {
        if(SZ(v[i])>mx)lg.clear(),lg.push_back(i),mx=SZ(v[i]);
        else if(SZ(v[i])==mx)lg.push_back(i);
    }
    int ans=n*(mx-1);
    for(int j : lg)printf("%d ",j);puts("");
    for(int i=0;i<n;i++)
    {
        int tmp=n;
        int id=lower_bound(lg.begin(),lg.end(),i)-lg.begin();
        id--;
        if(id==-1)id=SZ(lg)-1;
        id=lg[id];
        int k=lower_bound(v[id].begin(),v[id].end(),i)-v[id].begin();
        if(k==SZ(v[id]))k=0;
        printf("%d %d: ",id,v[id][k]);
        printf("%d\n",ans+dis(i,id)+dis(id,v[id][k]));
    }
    return 0;
}
