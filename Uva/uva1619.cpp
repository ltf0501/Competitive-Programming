#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
typedef long long LL;
const int maxn=100000+100;
const int oo=0x3f3f3f3f;

stack<int> q;
int n, a[maxn], L[maxn], R[maxn];
LL sum[maxn];

void init()
{
    a[0]=a[n+1]=-oo;
    while(!q.empty())q.pop();
    q.push(0);
    for(int i=1; i<=n; i++)
    {
        while(a[q.top()]>=a[i])q.pop();
        L[i]=q.top();
        q.push(i);
    }
    while(!q.empty())q.pop();
    q.push(n+1);
    for(int i=n; i; i--)
    {
        while(a[q.top()]>=a[i])q.pop();
        R[i]=q.top();
        q.push(i);
    }
}

int main()
{
    int kase=0;
    while(~scanf("%d", &n))
    {
        if(kase++)puts("");
        for(int i=1; i<=n; i++)
        {
            scanf("%d", a+i);
            sum[i]=sum[i-1]+a[i];
        }
        init();
        LL ans=0;
        int l, r;
        for(int i=1; i<=n; i++)
        {
            LL tmp=a[i]*(sum[R[i]-1]-sum[L[i]]);
            if(tmp>ans)
                ans=tmp, l=L[i]+1, r=R[i]-1;
            else if(tmp==ans && R[i]-L[i]-1<r-l+1)
                l=L[i]+1, r=R[i]-1;
        }
        if(ans==0)
            printf("0\n1 1\n");
        else printf("%lld\n%d %d\n", ans, l, r);
    }
    return 0;
}
