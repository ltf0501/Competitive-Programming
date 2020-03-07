///WA
#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
int n;
int a[maxn];
int nxt[maxn],cnt[maxn],fir[maxn],r[maxn],l[maxn];
vector<int> v;
bool vis[maxn];
int R[maxn],L[maxn];
struct P
{
    int pos,cnt;
    bool operator < (const P& b)const
    {
        if(cnt!=b.cnt)return cnt<b.cnt;
        return pos>b.pos;
    }
};
priority_queue<P> pq;
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)L[i]=i-1,R[i]=i+1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);v.push_back(a[i]);
        if(a[i]!=a[i-1])l[i]=i;
        else l[i]=l[i-1];
    }
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end())-v.begin());
    for(int i=1;i<=n;i++)a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
    //for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
    for(int i=n;i>=1;i--)
    {
        if(a[i]!=a[i+1])cnt[i]=1,r[i]=i;
        else cnt[i]=cnt[i+1]+1,r[i]=r[i+1];
    }
    for(int i=1;i<=n;i++)fir[i]=n+1;
    for(int i=n;i>=1;i--)
    {
        nxt[i]=fir[a[i]];
        fir[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=a[i-1])pq.push({i,cnt[i]});
    }
    int ans=0;
    while(!pq.empty())
    {
        P t=pq.top();pq.pop();
        if(vis[t.pos])continue;
        vis[t.pos]=1;
        //printf("%d\n",t.pos);
        a[t.pos]=a[r[t.pos]]=-1;
        int ll=L[t.pos],rr=R[r[t.pos]];
        R[ll]=rr,L[rr]=ll;
        ans++;
        //printf("%d %d\n",ll,rr);
        if(ll>0 && rr<n+1 && a[ll]==a[rr] && a[ll]!=-1)
        {
            vis[rr]=1;
            //printf("%d %d\n",t.pos,rr);
            cnt[l[ll]]+=cnt[rr];
            r[l[ll]]=r[rr];
            pq.push({l[ll],cnt[l[ll]]});
        }
    }
    //puts("");
    printf("%d\n",ans);
    //for(int i=1;i<=n;i++)printf("%d ",nxt[i]);
    return 0;
}
/*
8
1 2 2 3 3 2 2 1
26
1 2 2 3 3 3 4 4 4 4 5 5 5 5 5 6 6 6 6 6 6 5 4 3 2 1
*/
