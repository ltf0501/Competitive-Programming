#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ALL(v) v.begin(),v.end()
int n,k;
int cnt[maxn],a[maxn];
vector<int> v;
main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        v.push_back(x);
        a[i]=x;
    }
    if(k==0)
    {
        for(int i=1;i<=n;i++)
            if(a[i]==1)return 0*puts("-1");
        return 0*puts("1");
    }
    sort(ALL(v));
    v.resize(unique(ALL(v))-v.begin());
    for(int i=1;i<=n;i++)a[i]=lower_bound(ALL(v),a[i])-v.begin();
    int m=v.size();
    //for(int i=1;i<=n;i++)printf("%d ",a[i]);
    for(int i=1;i<=n;i++)cnt[a[i]]++;
    for(int i=1;i<m;i++)cnt[i]+=cnt[i-1];
    int ans=-1;
    for(int i=0;i<m;i++)
        if(cnt[i]==k){ans=i;break;}
    if(ans!=-1)printf("%d\n",v[ans]);
    else puts("-1");
    return 0;
}


