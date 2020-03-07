#include<bits/stdc++.h>
using namespace std;
#define maxn 300010
#define pii pair<int,int>
#define F first
#define S second
#define ll long long
const int INF=1e9+7;
set<pii> s;
set<pii>::iterator it,tt;
vector<pii> v[maxn];
int n,k;
int pre[maxn];
ll ans;
bool check(int m)
{
    memset(pre,0,sizeof(pre));
    ll s1=0,s2=0,t1=0,t2=0;
    for(int i=1,j=1;i<=n;i++)
    {
        for(pii ss : v[i])
        {
            if(ss.F<j)t1+=1ll*ss.F*ss.S;
            else t1+=1ll*(j-1)*ss.S,t2+=ss.S,pre[ss.F]+=ss.S;
        }
        while(j<=i && t2>=m)t1+=t2,t2-=pre[j++];
        s1+=t1,s2+=(j-1);
    }
    if(s2>=k)
    {
        ans=s1-(s2-k)*m;
        return 1;
    }
    return 0;
}
main()
{
    scanf("%d%d",&n,&k);
    s.insert(pii(1,0));s.insert(pii(1e9,0));
    for(int i=1;i<=n;i++)
	{
        int l,r;scanf("%d%d",&l,&r);
		tt=(it=s.upper_bound(pii(l,n)))--;
		int id;
		v[i].push_back(pii(id=it->S,it->F-tt->F));
		if(it->F<l)v[i].push_back(pii(id=it->S,l-it->F));
		else s.erase(it);
		v[i].push_back(pii(i,r-l));s.insert(pii(l,i));
		while(tt->F<r)it=tt++,v[i].push_back(pii(id=it->S,it->F-tt->F)),s.erase(it);
		if(tt->F>r)v[i].push_back(pii(id,tt->F-r)),s.insert(pii(r,id));
	}
	int now=0;
    for(int i=30;i>=0;i--)
    {
        now+=(1<<i);
        if(!check(now))now-=(1<<i);
    }
    printf("%lld\n",ans);
    return 0;
}
