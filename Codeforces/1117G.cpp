#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
int n,q;
int a[maxn];
int s[maxn],t[maxn];
int l[maxn],r[maxn];
ll ans[maxn];
vector<pii> v[maxn];
vector<int> cc[maxn];
ll bit[2][maxn];
void add(int idx,int x,ll d)
{
    for(int i=x;i<=n;i+=i&-i)bit[idx][i]+=d;
}
ll query(int idx,int x)
{
    ll res=0;
    for(int i=x;i;i-=i&-i)res+=bit[idx][i];
    return res;
}
main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    a[0]=a[n+1]=maxn;
    stack<int> S;
    S.push(0);
    for(int i=1;i<=n;i++)
    {
        while(a[S.top()]<a[i])S.pop();
        l[i]=S.top()+1;
        S.push(i);
    }
    while(!S.empty())S.pop();
    S.push(n+1);
    for(int i=n;i>=1;i--)
    {
        while(a[S.top()]<a[i])S.pop();
        r[i]=S.top()-1;
        S.push(i);
    }
    //for(int i=1;i<=n;i++)printf("%d ",l[i]);puts("");
    //for(int i=1;i<=n;i++)printf("%d ",r[i]);puts("");
    for(int i=1;i<=q;i++)scanf("%d",&s[i]);
    for(int i=1;i<=q;i++)scanf("%d",&t[i]);
    for(int i=1;i<=q;i++)ans[i]=t[i]-s[i]+1;
    for(int i=1;i<=q;i++)
        v[s[i]].push_back(pii(t[i],i));
    for(int i=1;i<=n;i++)cc[l[i]].push_back(i);
    for(int i=1;i<=n;i++)add(0,i,l[i]);
    for(int i=1;i<=n;i++)
    {
        for(int j : cc[i])add(0,j,-l[j]),add(1,j,1);
        for(pii tmp : v[i])
        {
            int le=i,ri=tmp.F,id=tmp.S;
            ans[id]-=(query(0,ri)-query(0,le-1))+1ll*i*(query(1,ri)-query(1,le-1));

        }
    }
    for(int i=1;i<=n;i++)v[i].clear(),cc[i].clear();
    memset(bit,0,sizeof(bit));
    for(int i=1;i<=q;i++)
        v[t[i]].push_back(pii(s[i],i));
    for(int i=1;i<=n;i++)cc[r[i]].push_back(i);
    for(int i=1;i<=n;i++)add(0,i,r[i]);
    for(int i=n;i>=1;i--)
    {
        for(int j : cc[i])add(0,j,-r[j]),add(1,j,1);
        for(pii tmp : v[i])
        {
            int le=tmp.F,ri=i,id=tmp.S;
            ans[id]+=(query(0,ri)-query(0,le-1))+1ll*i*(query(1,ri)-query(1,le-1));
        }
    }
    for(int i=1;i<=q;i++)printf("%lld ",ans[i]);
    return 0;
}
