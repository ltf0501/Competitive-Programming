#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
int cnt[maxn],a[maxn];
vector<int> v1,v2;
int n,m;
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n+m;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n+m;i++)
    {
        int x;scanf("%d",&x);
        if(x)v1.push_back(a[i]);
        else v2.push_back(a[i]);
    }
    v1.push_back(2e9+7);
    for(int s : v2)
    {
        int k=lower_bound(v1.begin(),v1.end(),s)-v1.begin();
        if(k==0)cnt[0]++;
        else
        {
            if(s-v1[k-1]<=v1[k]-s)cnt[k-1]++;
            else cnt[k]++;
        }
    }
    for(int i=0;i<m;i++)printf("%d ",cnt[i]);
    return 0;
}
