#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define pii pair<int,int>
#define F first
#define S second
int n,q,a[maxn];
vector<int> v;
bool ok;
int l[maxn],r[maxn];
set<int> s;
vector<pii> ll,rr;
main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i])v.push_back(a[i]);
        if(a[i]==q)ok=1;
    }
    if(!ok && v.size()==n)return 0*puts("NO");
    memset(l,-1,sizeof(l)),memset(r,-1,sizeof(r));
    for(int i=0;i<v.size();i++)
    {
        if(l[v[i]]==-1)l[v[i]]=i;
        r[v[i]]=i;
    }
    for(int i=1;i<=q;i++)
    {
        if(l[i]!=-1)ll.push_back(pii(l[i],i));
        if(r[i]!=-1)rr.push_back(pii(r[i]+1,i));
    }
    //for(int i=1;i<=q;i++)printf("%d: %d %d\n",i,l[i],r[i]);
    int m=ll.size();
    sort(ll.begin(),ll.end()),sort(rr.begin(),rr.end());
    int l_idx=0,r_idx=0;
    for(int i=0;i<v.size();i++)
    {
        while(l_idx<m && ll[l_idx].F==i)s.insert(ll[l_idx++].S);
        while(r_idx<m && rr[r_idx].F==i)s.erase(rr[r_idx++].S);
        //printf("%d %d %d\n",i,l_idx,r_idx);
        if(v[i]<*(--s.end()))return 0*puts("NO");
    }
    int idx=0;
    for(int i=1;i<=n;i++)if(!a[i])idx=i;
    if(!a[1])a[1]=1;
    for(int i=2;i<=n;i++)if(!a[i])a[i]=a[i-1];
    if(!ok)a[idx]=q;
    puts("YES");
    for(int i=1;i<=n;i++)printf("%d ",a[i]);
    return 0;
}
