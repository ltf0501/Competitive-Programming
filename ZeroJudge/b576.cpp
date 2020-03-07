#include<cstdio>
#include<algorithm>
using namespace std;
int p[31];
void init()
{
    p[0]=1;
    for(int i=1;i<=30;i++)p[i]=2*p[i-1];
}
main()
{
    int t;scanf("%d",&t);
    int a[4];
    a[3]=3;
    a[1]=1;
    a[2]=2;
    init();
    while(t--)
    {
        int n;scanf("%d",&n);
        if(n<=3){printf("%d\n",n);continue;}
        /*
        int k=0;
        while(3*p[k]<=n)k++;
        k--;
        //printf("%d %d\n",k,3*p[k]);
        */
        int m=n%3;
        int l=(n-1)/3;
        int cnt=0;
        for(int i=0;i<=30;i++)
        {
            if(l & p[i])cnt++;
        }
        if(m==0)m+=3;
        if(cnt%2==1)printf("%d\n",4-a[m]);
        else printf("%d\n",a[m]);
    }
    return 0;
}
