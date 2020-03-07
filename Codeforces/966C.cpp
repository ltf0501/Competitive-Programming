#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
int n;
ll a[maxn],cur;
vector<ll> v[70],ans;
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<=n;i++)
        for(int j=60;j>=0;j--)if(a[i]&(1ll<<j)){v[j].push_back(a[i]);break;}
    for(int i=60;i>=0;i--)
    {
        if(v[i].empty())continue;
        vector<ll> tmp;
        int cur=0;
        tmp.push_back(v[i][0]);
        for(int j=1;j<v[i].size();j++)
        {
            bool flag=0;
            while(cur<ans.size())
            {
                tmp.push_back(ans[cur]);
                if(ans[cur++]&(1ll<<i)){flag=1;break;}
            }
            if(!flag)return 0*puts("No");
            tmp.push_back(v[i][j]);
        }
        while(cur<ans.size())tmp.push_back(ans[cur++]);
        ans=tmp;
    }
    puts("Yes");
    for(ll s : ans)printf("%lld ",s);
    return 0;
}
