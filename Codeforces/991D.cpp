#include<bits/stdc++.h>
using namespace std;
#define maxn 105
char c[maxn];
int a[maxn],n;
main()
{
    for(int i=0;i<2;i++)
    {
        scanf("%s",c+1);
        n=strlen(c+1);
        for(int j=1;j<=n;j++)if(c[j]=='0')a[j]+=(1<<i);
    }
    //for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
    int cnt=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]==3)
        {
            if(a[i+1]==3)cnt++,a[i+1]=1;
            else if(a[i+1])cnt++,a[i+1]=0;
        }
        else if(a[i])
        {
            if(a[i+1]==3)cnt++,a[i+1]=0;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
