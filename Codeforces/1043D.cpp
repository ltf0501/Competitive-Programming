#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
int a[10][maxn];
int pos[maxn],cal[maxn];
int n,m;
main()
{
    scanf("%d%d",&n,&m);
    for(int j=0;j<m;j++)for(int i=1;i<=n;i++)scanf("%d",&a[j][i]);
    for(int i=1;i<=n;i++)pos[a[0][i]]=i;
    for(int j=1;j<m;j++)for(int i=1;i<=n;i++)
        a[j][i]=pos[a[j][i]];
    for(int i=1;i<=n;i++)cal[i]=n;
    for(int j=1;j<m;j++)
    {
        for(int i=1,cur=1;i<=n;i++)
        {
            if(cur<i)cur++;
            while(cur<n && (a[j][cur+1]-a[j][cur]==1))cur++;
            cal[a[j][i]]=min(cal[a[j][i]],a[j][cur]);
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++)ans+=cal[i]-i+1;
    printf("%lld\n",ans);
    return 0;
}
