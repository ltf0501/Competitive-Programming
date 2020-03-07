#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
bool c[maxn];
int n;
void update(int x)
{
    while(x<=n)c[x]^=1,x+=(x&-x);
}
bool sum(int x)
{
    bool ans=0;
    while(x)ans^=c[x],x-=(x&-x);
    return ans;
}
main()
{
    int q;scanf("%d%d",&n,&q);
    while(q--)
    {
        int v;scanf("%d",&v);
        if(v==1)
        {
            int x;scanf("%d",&x);
            update(x);
        }
        else
        {
            int l,r;scanf("%d%d",&l,&r);
            puts(sum(l-1)^sum(r) ? "1" : "0");
        }
    }
    return 0;
}
