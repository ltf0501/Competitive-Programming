#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[105];
bool cmp(int x,int y)
{
    return x>y;
}
main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)scanf("%d",&a[i]);
    int tot=2*n,mid=n;
    bool flag=1;
    sort(a+1,a+k+1,cmp);
    for(int i=1;i<=k;i++)if(a[i]>=4)
    {
        if(mid>=(a[i]+3)/4)
        {
            mid-=(a[i]+3)/4;
            a[i]=a[i]%4;
        }
        else
        {
            a[i]-=4*mid;
            mid=0;
            break;
        }
    }
    sort(a+1,a+k+1,cmp);
    for(int i=1;i<=k;i++)if(a[i]>=2)
    {
        if(tot>=(a[i]+1)/2)tot-=(a[i]+1)/2,a[i]=a[i]%2;
        else
        {
            a[i]-=2*tot;
            tot=0;
            break;
        }
    }
    int num[4]={0};
    for(int i=1;i<=k;i++)
    {
        num[1]+=(a[i]%2);
        num[2]+=(a[i]/2);
    }
    //printf("%d %d %d %d\n",mid,tot,num[1],num[2]);
    if(num[2]>tot+mid)flag=0;
    else if(num[2]+num[1]>tot+mid*2)flag=0;
    //printf("%d %d\n",sum,flag);
    puts(flag ? "YES" : "NO");
    return 0;
}
