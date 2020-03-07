#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e5+10;
const int C=2e5+10;
vector<int> v[2][maxn];
ll ans=0;
int lmx[maxn],lmi[maxn],rmx[maxn],rmi[maxn];
void sol(int id)
{
    lmx[0]=-maxn,lmi[0]=maxn;
    for(int i=1;i<maxn;i++)
    {
        lmx[i]=lmx[i-1],lmi[i]=lmi[i-1];
        for(int s : v[id][i])
            lmx[i]=max(lmx[i],s),lmi[i]=min(lmi[i],s);
    }
    rmx[maxn-1]=-maxn,rmi[maxn-1]=maxn;
    for(int i=maxn-2;i>=0;i--)
    {
        rmx[i]=rmx[i+1],rmi[i]=rmi[i+1];
        for(int s : v[id][i])
            rmx[i]=max(rmx[i],s),rmi[i]=min(rmi[i],s);
    }
    for(int i=1;i<maxn;i++)
    {
        if(i%2==id)continue;
        int l=max(lmi[i-1],rmi[i+1])+1;
        int r=min(lmx[i-1],rmx[i+1])-1;
        if(((l+C)%2)!=(i%2))l++;
        if(((r+C)%2)!=(i%2))r--;
        int t=(r-l);
        if(t>=0)ans+=max(0,t/2+1);
    }
}
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        v[(x+y+C)%2][x+y+C].push_back(x-y);
    }
    sol(0),sol(1);
    printf("%lld\n",ans);
    return 0;
}
