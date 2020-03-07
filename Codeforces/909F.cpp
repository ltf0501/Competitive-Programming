#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int p[maxn],q[maxn];
int n;
int get_pw(int n)
{
    int ans=1;
    while(ans<=n)ans*=2;
    ans/=2;
    return ans;
}
main()
{
    scanf("%d",&n);
    int N=n;
    if(n&1)puts("NO");
    else
    {
        puts("YES");
        while(n>0)
        {
            int k=get_pw(n);
            int tmp=n-k;
            for(int i=0;i<=tmp;i++)p[k+i]=k-i-1,p[k-i-1]=k+i;
            n=k-tmp-2;
        }
        for(int i=1;i<=N;i++)printf("%d ",p[i]);puts("");
        //for(int i=1;i<=N;i++)printf("%d ",p[i]&i);puts("");
    }
    n=N;
    if(N<=5)puts("NO");
    else
    {
        if(N==6)printf("YES\n 3 6 1 5 4 2\n");
        else
        {
            int k=get_pw(n);if(n==k){puts("NO");return 0;}
            p[1]=3,p[2]=7,p[3]=1,p[4]=5,p[5]=4,p[6]=2,p[7]=6;
            puts("YES");
            for(int i=3;(1<<i)<=N;i++)
            {
                int t=min(N,(1<<(i+1))-1);
                for(int j=(1<<i);j<=t;j++)p[j]=j+1;
                p[t]=(1<<i);
            }
            for(int i=1;i<=N;i++)printf("%d ",p[i]);puts("");
            //for(int i=1;i<=N;i++)printf("%d ",p[i]&i);puts("");
        }
    }
    return 0;
}
