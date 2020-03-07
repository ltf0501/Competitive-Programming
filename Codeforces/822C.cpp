#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define INF 2000000010
#define pii pair<int,int>
#define F first
#define S second
struct P
{
    int l,r,c;
    void input()
    {
        scanf("%d%d%d",&l,&r,&c);
    }
    bool operator < (const P& b)const
    {
        return l<b.l;
    }
}a[maxn];
int n,x;
int b[maxn],id[maxn];
bool cmp(int x,int y){return a[x].r<a[y].r;}
main()
{
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++)a[i].input(),id[i]=i;
    for(int i=1;i<=200000;i++)b[i]=INF;
    sort(a+1,a+n+1);
    sort(id+1,id+n+1,cmp);
    int ans=INF;
    int cur=1;
    //for(int i=1;i<=n;i++)printf("%d %d %d\n",a[i].l,a[i].r,a[i].c);
    //for(int i=1;i<=n;i++)printf("%d ",id[i]);puts("");
    for(int i=1;i<=n;i++)
    {
        while(cur<=n && a[id[cur]].r<a[i].l)
            b[a[id[cur]].r-a[id[cur]].l+1]=min(b[a[id[cur]].r-a[id[cur]].l+1],a[id[cur]].c),cur++;
        if(x>a[i].r-a[i].l+1 && b[x-(a[i].r-a[i].l+1)]!=INF)ans=min(ans,a[i].c+b[x-(a[i].r-a[i].l+1)]);
    }
    if(ans!=INF)printf("%d\n",ans);
    else puts("-1");
    return 0;
}
