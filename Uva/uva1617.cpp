#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 100000+10
struct task
{
    int l,r;
}T[maxn];
bool cmp(task a,task b)
{
    if(a.r<b.r)return true;
    if(a.r==b.r && a.l<=b.l)return true;
    return false;
}
int n;
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d%d",&T[i].l,&T[i].r);
        sort(T+1,T+n+1,cmp);
        int ans=0,p=-1;
        for(int i=1;i<=n;i++)
        {
            if(T[i].r==p)continue;
            if(T[i].l>p)
            {
                ans++;
                p=T[i].r;
            }
            else p++;
        }
        printf("%d\n",ans-1);
    }
    return 0;
}
