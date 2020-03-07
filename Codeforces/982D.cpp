#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ALL(v) v.begin(),v.end()
int n;
int a[maxn],id[maxn];
vector<int> v;
struct P
{
    int l,r,len;
    bool operator < (const P& b)const
    {
        return l<b.l;
    }
};
set<P> s;
multiset<int> ss;
void gao(int k)
{
    auto it=ss.lower_bound(k);
    //printf("%d ",k);
    ss.erase(it);
}
bool check()
{
    auto it1=ss.begin(),it2=(--ss.end());
    //if((*it1)==0)it1++;
    //if((*it2)==0)it2--;
    return (*it1)==(*it2);
}
int cur,ans,mx;
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),v.push_back(a[i]);
    sort(ALL(v));
    v.resize(unique(ALL(v))-v.begin());
    for(int i=1;i<=n;i++)a[i]=lower_bound(ALL(v),a[i])-v.begin()+1;
    for(int i=1;i<=n;i++)id[a[i]]=i;
    s.insert({-1,-1,0}),s.insert({n+2,n+2,0});
    //ss.insert(0),ss.insert(0);
    for(int i=1;i<=n;i++)
    {
        int now=id[i];
        auto it=s.lower_bound({now,now,1});
        auto it2=it;
        it2--;
        if(it->l==now+1 && it2->r==now-1)
        {
            int x=it->len,y=it2->len;
            int l=it2->l,r=it->r;
            gao(x),gao(y);ss.insert(x+y+1);
            s.erase(it),s.erase(it2);
            s.insert({l,r,x+y+1});
            cur--;
        }
        else if(it->l==now+1)
        {
            int x=it->len,r=it->r;
            gao(x);ss.insert(x+1);
            s.erase(it);
            s.insert({now,r,x+1});
        }
        else if(it2->r==now-1)
        {
            int x=it2->len,l=it2->l;
            gao(x);ss.insert(x+1);
            s.erase(it2);
            s.insert({l,now,x+1});
        }
        else
        {
            ss.insert(1);
            s.insert({now,now,1});
            cur++;
        }
        if(check())
        {
            if(cur>mx)ans=i,mx=cur;
        }
       // printf("%d %d\n",i,cur);
    }
    printf("%d\n",v[ans-1]+1);
    return 0;
}
