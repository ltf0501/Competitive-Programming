#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 300010
const int INF=2e9+10;
struct P{int t,c;}p[maxn];
int n;
ll st,a,b,c,d;
int len;
ll sum1[maxn],sum2[maxn];
multiset<ll> s;
main()
{
    scanf("%d%I64d%I64d%I64d%I64d%I64d%d",&n,&a,&b,&c,&d,&st,&len);
    b=-b;d=-d;
    p[0].t=-1,p[0].c=-1;
    for(int i=1;i<=n;i++)scanf("%d%d",&p[i].t,&p[i].c);
    for(int i=1;i<=n;i++)sum1[i]=sum1[i-1]+(p[i].c==0 ? b : a);
    for(int i=1;i<=n;i++)sum2[i]=sum2[i-1]+(p[i].c==0 ? d : c);
    //for(int i=1;i<=n;i++)printf("%I64d ",sum1[i]);puts("");
    //for(int i=1;i<=n;i++)printf("%I64d ",sum2[i]);puts("");
    int r=1;
    for(int i=0;i<=n;i++)
    {
        int tt=p[i].t+1;
        if(sum1[i]+st<0)return 0*puts("-1");
        if(i)s.erase(s.find(sum2[i]));
        while(r<=n && p[r].t<tt+len)s.insert(sum2[r++]);
        //printf("%d %d\n",l,r);
        //for(ll v : s)printf("%I64d ",v);puts("");
        if(s.empty())return 0*printf("%d\n",tt);
        ll k=*s.begin();
        if(sum1[i]-sum2[i]+k+st>=0)return 0*printf("%d\n",tt);
    }
    return 0;
}
