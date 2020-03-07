#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
#define pii pair<int,int>
#define F first
#define S second
#define mkp make_pair
#define P pair<pii,int>
P a[maxn],b[maxn];
bool cmp(P x,P y)
{
    pii a=x.F,b=y.F;
    return 1ll*a.S*b.F<1ll*a.F*b.S;
}
int n,p,q;
int ans[maxn];
int ok[maxn];
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        if(x<0)x=-x,y=-y,ok[i]=-1;
        a[i]=mkp(pii(x,y),i);
    }
    sort(a+1,a+n+1);
    int now=1;
    for(int i=1;i<=n;i++)ans[a[i].S]=now*ok[a[i].S],now*=-1;//,printf("%d ",a[i].S);puts("");
    //for(int i=1;i<=q;i++)ans[b[i].S]=now*ok[b[i].S],now*=-1;//,printf("%d ",b[i].S);puts("");
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
    return 0;
}
