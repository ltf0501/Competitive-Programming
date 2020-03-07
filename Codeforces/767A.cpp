#include<bits/stdc++.h>
using namespace std;
#define maxn 100000+5
int a[maxn];
main()
{
    int n;scanf("%d",&n);
    int t=n;
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        a[x]=1;
        while(a[t])printf("%d ",t--);
        puts("");
    }
    return 0;
}
