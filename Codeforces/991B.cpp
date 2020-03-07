#include<bits/stdc++.h>
using namespace std;
int n,sum;
int num[6];
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        num[x]++;
        sum+=x;
    }
    if(2*sum>=9*n)return 0*puts("0");
    int cnt=0;
    while(2*sum<9*n)
    {
        cnt++;
        int s;
        for(int i=1;i<=5;i++)if(num[i]){s=i;break;}
        num[s]--;
        sum+=(5-s);
    }
    printf("%d\n",cnt);
    return 0;
}
