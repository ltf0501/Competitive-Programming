#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define pii pair<int,int>
#define F first
#define S second
#define ll long long
const int mod=1e9+7;
vector<pii> v;
deque<int> tmp;
int n,x,y;
main()
{
    scanf("%d%d%d",&n,&x,&y);
    int k=x/y;
    for(int i=1;i<=n;i++)
    {
        int l,r;scanf("%d%d",&l,&r);
        v.push_back(pii(l,-1)),v.push_back(pii(r,r-l));
    }
    sort(v.begin(),v.end());
    ll ans=0;
    tmp.push_back(-mod);
    for(pii s : v)
    {
        if(s.S==-1)
        {
            if(!tmp.empty() && s.F-tmp.back()<=k)
            {
                ans=(ans+1ll*y*(s.F-tmp.back()))%mod;
                tmp.pop_back();
            }
            else tmp.clear(),ans=(ans+x)%mod;
        }
        else
        {
            ans=(ans+1ll*y*(s.S))%mod;
            tmp.push_back(s.F);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
