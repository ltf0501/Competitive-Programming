#include<bits/stdc++.h>
using namespace std;
int a[6],b[6];
main()
{
    int n;scanf("%d",&n);
    int k;
    for(int i=1;i<=n;i++)scanf("%d",&k),a[k]++;
    for(int i=1;i<=n;i++)scanf("%d",&k),b[k]++;
    int sum=0;
    for(int i=1;i<=5;i++)
    {
        if((a[i]+b[i])%2==1){puts("-1");return 0;}
        sum+=abs(a[i]-b[i]);
    }
    sum/=4;
    printf("%d\n",sum);
    return 0;
}
