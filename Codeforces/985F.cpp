#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
#define pll pair<ll,ll>
#define F first
#define S second
const pll p=pll(880301,890501);
const pll mod=pll(1000000007ll,1000000009ll);
char c[maxn];
int n,q;
pll h[26][maxn];
pll ex[maxn];
pll operator + (const pll a,const pll b){return pll((a.F+b.F)%mod.F,(a.S+b.S)%mod.S);}
pll operator - (const pll a,const pll b){return pll((a.F-b.F+mod.F)%mod.F,(a.S-b.S+mod.S)%mod.S);}
pll operator * (const pll a,const pll b){return pll(a.F*b.F%mod.F,a.S*b.S%mod.S);}
pll operator * (const ll a,const pll b){return pll(a*b.F%mod.F,a*b.S%mod.S);}
main()
{
    scanf("%d%d",&n,&q);
    scanf("%s",c+1);
    ex[0]=pll(1,1);
    for(int i=1;i<=n;i++)ex[i]=ex[i-1]*p;
    for(int i=0;i<26;i++)h[i][0]=pll(0,0);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<26;j++)
        {
            if(c[i]=='a'+j)h[j][i]=h[j][i-1]+ex[i-1];
            else h[j][i]=h[j][i-1];
        }
    }
    while(q--)
    {
        int x,y,len;scanf("%d%d%d",&x,&y,&len);
        x--,y--;
        vector<pll> tmp[2];
        for(int i=0;i<26;i++)tmp[0].push_back((h[i][x+len]-h[i][x])*ex[y]);
        for(int i=0;i<26;i++)tmp[1].push_back((h[i][y+len]-h[i][y])*ex[x]);
        for(int i=0;i<2;i++)sort(tmp[i].begin(),tmp[i].end());
        bool flag=1;
        for(int i=0;i<26;i++)
            if(tmp[0][i]!=tmp[1][i]){flag=0;break;}
        puts(flag ? "YES" : "NO");
    }
    return 0;
}
