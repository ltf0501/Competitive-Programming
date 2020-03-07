#include<bits/stdc++.h>
using namespace std;

main()
{
    int t,cas=0;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        if(!n){printf("Case %d: 0\n",++cas);continue;}
        int b[50];
        int ntmp=abs(n),k=0;
        while(ntmp)
        {
            b[k++]=ntmp%2;
            ntmp/=2;
        }
        int mi=n>0 ? 0 : 1;
        int carry=0;
        int i;
        for(i=0;i<k;i++)
        {
            int temp=carry;
            carry=(b[i]+temp)/2;
            b[i]=(b[i]+temp)%2;
            if(i%2!=mi && b[i])carry++;
        }
        if(carry)
        {
            if(i%2!=mi)
            {
                b[k++]=1;
                b[k++]=1;
            }
            else
                b[k++]=1;
        }
        printf("Case #%d: ",++cas);
        for(int i=k-1;i>=0;i--)printf("%d",b[i]);puts("");
    }
    return 0;
}
