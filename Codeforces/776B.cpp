#include<bits/stdc++.h>
using namespace std;
#define maxn 100000+5
int a[maxn];
main()
{
    int n;scanf("%d",&n);
    if(n==1){printf("%d\n%d\n",1,1);return 0;}
    if(n==2){printf("%d\n%d %d\n",1,1,1);return 0;}
    printf("%d\n",2);
    for(int i=2;i*i<=n+5;i++)
    {
        if(a[i]==0)
        {
            a[i]=1;
            for(int j=i*i;j<=n+5;j+=i)a[j]=2;
        }
    }
    for(int i=2;i<=n+1;i++)if(!a[i])a[i]=1;
    for(int i=2;i<=n+1;i++)printf("%d ",a[i]);
    puts("");
    return 0;
}

