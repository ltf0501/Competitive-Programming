#include<bits/stdc++.h>
using namespace std;
#define maxn 310
int n,t;
int a[maxn];
int query(int l,int r,int& umr)
{
    printf("? %d %d\n",l,r);fflush(stdout);
    int x;scanf("%d",&x);
    return umr=x;
}
main()
{
    scanf("%d%d",&n,&t);
    if(n%2==0)
    {
        int cur=0;
        for(int i=1;i<=n;i++)
        {
            int tmp;
            while(((10000+t-query(i,i,tmp))&1)^(i&1));
            /*
            0-1=tmp-t
            0+1=i
            =>1=(i+t-tmp)/2
            */
            a[i]=(i+t-tmp)/2-cur;
            cur+=a[i];
        }
    }
    else
    {
        int cur=0;
        while(((10000+t-query(1,2,cur))&1)^(n&1)==0);
        cur=2-(cur-t+2)/2;
        int tmp;
        while(((10000+t-query(2,n,tmp))&1)^(n&1)==0);
        a[1]=tmp>t ? 1 : 0;
        a[2]=cur-a[1];
        for(int i=3;i<=n;i++)
        {
            while(((10000+t-query(i-1,i,tmp))&1)^(i&1));
            a[i]=(i+t-tmp)/2-cur;
            cur+=a[i];
        }
    }
    printf("! ");
    for(int i=1;i<=n;i++)printf("%d",a[i]);fflush(stdout);
    return 0;
}
