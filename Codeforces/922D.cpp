#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
string s[maxn],t;
int n;
int a[maxn],b[maxn];
int id[maxn];
bool cmp(int i,int j)
{
    return 1ll*a[i]*b[j]>1ll*a[j]*b[i];
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)cin>>s[i],id[i]=i;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<s[i].size();j++)
        {
            if(s[i][j]=='s')a[i]++;
            else b[i]++;
        }
    }
    sort(id+1,id+n+1,cmp);
    for(int i=1;i<=n;i++)t+=s[id[i]];
    //cout<<t<<'\n';
    memset(a,0,sizeof(a));
    for(int i=0;i<t.size();i++)
        if(t[i]=='h')a[i]++;
    for(int i=t.size()-2;i>=0;i--)a[i]+=a[i+1];
    ll ans=0;
    for(int i=0;i<t.size()-1;i++)if(t[i]=='s')ans+=a[i+1];
    printf("%lld\n",ans);
    return 0;
}
