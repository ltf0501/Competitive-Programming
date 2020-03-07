#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
int n,a[maxn];
int cnt[maxn];
vector<int> v;
bool vis[maxn];
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),cnt[a[i]]++;
    for(int i=1;i<=n;i++)if(!cnt[i])v.push_back(i);
    printf("%d\n",v.size());
    if(!v.size())
    {
        for(int i=1;i<=n;i++)printf("%d ",a[i]);
        return 0;
    }
    //for(int s : v)printf("%d ",s);puts("");
    for(int i=1,cur=0;i<=n,cur<v.size();i++)
    {
        if(cnt[a[i]]==1)continue;
        if(v[cur]>a[i] && !vis[a[i]])vis[a[i]]=1;
        else cnt[a[i]]--,a[i]=v[cur++];
    }
    for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
    return 0;
}
