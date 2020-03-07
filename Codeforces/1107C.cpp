#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 200010
int a[maxn];
char c[maxn];
main()
{
    int n,k;scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    scanf("%s",c+1);
    ll ans=0;
    for(int i=1,j;i<=n;i=j)
    {
        j=i;
        vector<ll> tmp;
        while(c[j]==c[i])j++;
        for(int l=i;l<j;l++)tmp.push_back(a[l]);
        sort(tmp.begin(),tmp.end());
        reverse(tmp.begin(),tmp.end());
        for(int l=0;l<min(k,(int)tmp.size());l++)ans+=tmp[l];
        i=j;
    }
    printf("%lld\n",ans);
    return 0;
}
