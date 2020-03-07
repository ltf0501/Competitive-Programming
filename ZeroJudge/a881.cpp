#include<bits/stdc++.h>
using namespace std;
int a[505],s[505];
int d[505][15];
void init(int n)
{
    memset(s,0,sizeof(s));
    memset(d,0,sizeof(d));
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++)d[i][0]=a[i];
    for(int j=1;(1<<j)<=n;j++)
    {
        for(int i=1;i+j-1<=n;i++)d[i][j]=max(d[i][j-1],d[i+(1<<(j-1))][j-1]);
    }
}
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,q;scanf("%d%d",&n,&q);
        init(n);
        while(q--)
        {
            int k,x,y;scanf("%d",&k);
            if(k==1)
            {
                scanf("%d%d",&x,&y);x++,y++;
                if(x>y)swap(x,y);
                int j=0;
                while((1<<(j+1))<=y-x+1)j++;
                printf("%d\n",max(d[x][j],d[y+1-(1<<j)][j]));
            }
            else if(k==2)
            {
                scanf("%d%d",&x,&y);x++,y++;
                if(x>y)swap(x,y);
                printf("%d\n",(s[y]-s[x-1])/(y-x+1));
            }
            else
            {
                scanf("%d",&x);x++;
                printf("%d\n",a[x]);
            }
        }
    }
    return 0;
}
