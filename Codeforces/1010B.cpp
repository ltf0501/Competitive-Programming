#include<bits/stdc++.h>
using namespace std;
const int maxn=35;
int p[maxn];
int m,n;
main()
{
    scanf("%d%d",&m,&n);
    for(int i=0;i<n;i++)
    {
        printf("1\n");fflush(stdout);
        int x;scanf("%d",&x);
        if(x==0)return 0;
        if(x==1)p[i]=1;else p[i]=0;
    }
    int l=1,r=m;
    for(int cnt=0;;cnt++)
    {
        int m=(l+r)>>1;
        printf("%d\n",m);fflush(stdout);
        int x;scanf("%d",&x);
        if(x==0)return 0;
        if(!((x==1)^p[cnt%n]))l=m+1;
        else r=m-1;
    }
    return 0;
}
