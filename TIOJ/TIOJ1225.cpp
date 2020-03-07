#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
#define maxn 1000000+5
#define LL long long
int a[maxn],le[maxn],ri[maxn];
struct node
{
    int id,v;
    bool operator < (const node& b)const
    {
        return v>b.v;
    }
};
priority_queue<node> pq;
main()
{
    int n;scanf("%d",&n);
    LL ans=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        le[i]=i-1;ri[i]=i+1;
        pq.push((node){i,a[i]});
    }
    while(pq.size()>1)
    {
        node u=pq.top();pq.pop();
        if(!le[u.id]){ans+=a[ri[u.id]];le[ri[u.id]]=0;continue;}
        if(ri[u.id]==n+1){ans+=a[le[u.id]];ri[le[u.id]]=n+1;continue;}
        ans+=min(a[le[u.id]],a[ri[u.id]]);
        le[ri[u.id]]=le[u.id];
        ri[le[u.id]]=ri[u.id];
    }
    printf("%lld\n",ans);
    return 0;
}
