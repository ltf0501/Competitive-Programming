#include<bits/stdc++.h>
using namespace std;
const int maxn=2345678+2;
#define pii pair<int,int>
#define F first
#define S second
#define ll long long
int n;
vector<int> p;
vector<pii> ans;
bool not_p[maxn<<2];
void init()
{
    for(int i=2;i<4*n;i++)if(!not_p[i])
    {
        p.push_back(i);
        for(ll j=1ll*i*i;j<4*n;j+=i)not_p[j]=1;
    }
}
main()
{
    scanf("%d",&n);
    init();
    int l=0;
    while(l<2*n)
    {
        auto it=upper_bound(p.begin(),p.end(),4*n-2*l-1);
        int pp=*prev(it);
        int k=l+1;
        for(;4*n-pp-l>=k;l+=2)ans.push_back(pii(l,4*n-pp-l));
    }
    for(pii& ss : ans)if(ss.F>ss.S)swap(ss.F,ss.S);
    sort(ans.begin(),ans.end());
    for(pii ss : ans)printf("%d %d\n",ss.F,ss.S);
    return 0;
}
