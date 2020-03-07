#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
int n,m;
int a[maxn],c[maxn];
int id[maxn];
bool cmp(int i,int j){return c[i]==c[j] ? (i<j) : (c[i]<c[j]);}
ll ans;

void cal(int idd,int &cur)
{
    int mi=min(cur,a[idd]);
    a[idd]-=mi,cur-=mi;
    ans+=1ll*mi*c[idd];
}
main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&c[i]);
    for(int i=1;i<=n;i++)id[i]=i;
    sort(id+1,id+n+1,cmp);
    int pos=1;
    while(m--)
    {
        int t,d;scanf("%d%d",&t,&d);
        ans=0;
        cal(t,d);
        while(d && pos<=n)
        {
            cal(id[pos],d);
            if(!a[id[pos]])pos++;
        }
        printf("%lld\n",d ? 0 : ans);
    }
    return 0;
}
