#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
#define pli pair<ll,int>
#define F first
#define S second
const ll p=890501;
const ll mod=1e9+9;
ll pw[maxn],h[maxn];
char c[maxn],tmp[maxn];
int k[maxn],len[maxn];
vector<int> pos[maxn];
vector<pli> v[maxn];
main()
{
    scanf("%s",c+1);
    int n=strlen(c+1);
    pw[0]=1;
    for(int i=1;i<maxn;i++)pw[i]=pw[i-1]*p%mod;
    h[0]=0;
    for(int i=1;i<=n;i++)h[i]=(h[i-1]+pw[i-1]*(c[i]-'a')%mod)%mod;
    int q;scanf("%d",&q);
    for(int s=1;s<=q;s++)
    {
        scanf("%d %s",&k[s],tmp+1);
        len[s]=strlen(tmp+1);
        ll a=0;
        for(int i=1;i<=len[s];i++)a=(a+pw[i-1]*(tmp[i]-'a')%mod)%mod;
        a=a*pw[n]%mod;
        v[len[s]].push_back(pair<int,int>(a,s));
    }
    for(int len=1;len<=n;len++)if(!v[len].empty())
    {
        sort(v[len].begin(),v[len].end());
        for(int i=0;i+len<=n;i++)
        {
            ll c=(h[i+len]-h[i]+mod)%mod;
            c=c*pw[n-i]%mod;
            auto it=lower_bound(v[len].begin(),v[len].end(),pli(c,0));
            if(it!=v[len].end() && it->F==c)pos[it->S].push_back(i);
        }
    }
    for(int i=1;i<=q;i++)
    {
        if(pos[i].size()<k[i]){puts("-1");continue;}
        int ans=maxn;
        for(int j=0;j+k[i]<=pos[i].size();j++)
            ans=min(ans,pos[i][j+k[i]-1]-pos[i][j]+len[i]);
        printf("%d\n",ans);
    }
    return 0;
}
