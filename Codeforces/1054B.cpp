#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int a[maxn];
int n;
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int mx=-1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>mx+1)return 0*printf("%d\n",i);
        mx=max(mx,a[i]);
    }
    puts("-1");
    return 0;
}

