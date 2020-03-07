#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define pii pair<int,int>
#define F first
#define S second
int a[maxn],dep[maxn];
pii q[maxn];
int s[maxn];
main()
{
    int n,k;scnaf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)
    {
        int x;scanf("%d",&x);
        q[i]=pii(x,i);
    }
    sort(q+1,q+n+1);
    dep[1]=1;
    for(int i=2;i<=n;i++)
    {
        int x;scanf("%d",&x);
        dep[i]=dep[x]+1;
    }
    return 0;
}
