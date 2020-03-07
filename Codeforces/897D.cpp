#include<bits/stdc++.h>
using namespace std;
int a[1005];
int n,m,c;
bool check()
{
    for(int i=1;i<n;i++)if(!a[i] || a[i]>a[i+1])return 0;
    return 1;
}
main()
{
    scanf("%d%d%d",&n,&m,&c);
    for(int i=1;i<=m;i++)
    {
        int x;scanf("%d",&x);
        if(x<=c/2)
        {
            for(int i=1;i<=n;i++)if(!a[i] || x<a[i])
            {
                a[i]=x;
                printf("%d\n",i);
                fflush(stdout);
                break;
            }
        }
        else
        {
            for(int i=n;i>=1;i--)if(!a[i] || x>a[i])
            {
                a[i]=x;
                printf("%d\n",i);
                fflush(stdout);
                break;
            }
        }
        if(check())return 0;
    }
    return 0;
}
