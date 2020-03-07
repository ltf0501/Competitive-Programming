#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define maxn 200000+10
int n,m;
vector<int> v;
int l[maxn],r[maxn];
int ST[4*maxn];
int tag[4*maxn],le[4*maxn],ri[4*maxn];
void push_down(int o)
{
    if(!tag[o])return ;
    ST[2*o]+=1-le[2*o]-ri[2*o];
    le[2*o]^=1;ri[2*o]^=1;tag[2*o]^=1;

    ST[2*o+1]+=1-le[2*o+1]-ri[2*o+1];
    le[2*o+1]^=1;ri[2*o+1]^=1;tag[2*o+1]^=1;

    tag[o]=0;
}
void update(int l,int r,int L,int R,int id)
{
    if(l==L && r==R)
    {
        ST[id]+=1-le[id]-ri[id];
        tag[id]^=1;
        le[id]^=1,ri[id]^=1 ;
        return ;
    }
    push_down(id);

    int mid=L+(R-L)/2;
    if(r<=mid)update(l,r,L,mid,2*id);
    else if(l>mid)update(l,r,mid+1,R,2*id+1);
    else
    {
        update(l,mid,L,mid,2*id);
        update(mid+1,r,mid+1,R,2*id+1);
    }

    ST[id]=ST[2*id]+ST[2*id+1];
    le[id]=le[2*id];ri[id]=ri[2*id+1];
    if(ri[2*id] && le[2*id+1])ST[id]--;
}
main()
{
    scanf("%d%d",&n,&m);
    v.push_back(m),v.push_back(1);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&l[i],&r[i]);
        v.push_back(l[i]);v.push_back(r[i]);
        if(l[i]>r[i])swap(l[i],r[i]);
        if(l[i]!=1)v.push_back(l[i]-1);
        if(r[i]!=m)v.push_back(r[i]+1);
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    m=v.size()-1;
    for(int i=1;i<=n;i++)
    {
        l[i]=lower_bound(v.begin(),v.end(),l[i])-v.begin();
        r[i]=lower_bound(v.begin(),v.end(),r[i])-v.begin();
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        update(l[i],r[i],0,m,1);
        ans=max(ans,ST[1]);
    }
    printf("%d\n",ans);
    return 0;
}
