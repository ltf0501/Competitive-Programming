#include<bits/stdc++.h>
using namespace std;
#define maxn 150010
#define ll long long
ll a[maxn];
main()
{
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%lld",&a[i]);
    bool flag=1;
    for(int i=1;i<n;i++)if(a[i]!=a[i-1]){flag=0;break;}
    if(flag)
    {
        if(a[0])return 0*puts("NO");
        puts("YES");
        for(int i=0;i<n;i++)printf("1 ");
        return 0;
    }
    int id=-1;
    for(int i=0;i<n;i++)
        if(id==-1 || a[i]>a[id])id=i;
    int tmp=id;

    while(a[tmp]==a[id])tmp=(tmp+n-1)%n;
    id=(tmp+1)%n;
    a[tmp]+=a[id];
    for(int i=1;i<n;i++)
    {
        int now=(id+n-1)%n;
        a[now]+=a[id];
        id=now;
    }
    puts("YES");
    for(int i=0;i<n;i++)printf("%lld ",a[i]);
    return 0;
}
