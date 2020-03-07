#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct point
{
    int x,y;
};
int g[5][5];
int a[30];
//(i,j)=>5i+j
main()
{
    int r[5],c[5],p=5,q=5,vis[30],val[30];
    for(int i=0;i<5;i++){r[i]=5;c[i]=5;}
    for(int i=0;i<30;i++){vis[i]=0;val[i]=0;}
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            int k;
            scanf("%d",&k);
            g[i][j]=k;
            a[k]=5*i+j;
        }
    }
    int n;
    while(scanf("%d",&n)==1 && n!=-1)
    {
        int s=a[n];
        r[s/5]--;c[s%5]--;
        if(s==0 || s==6 || s==12 || s==18 || s==24)p--;
        if(s==4 || s==8 || s==12 || s==16 || s==20)q--;
        vis[s]=1;
    }
    /*
    for(int i=0;i<5;i++)printf("%d ",r[i]);
    puts("");
    for(int i=0;i<5;i++)printf("%d ",c[i]);
    puts("");
    printf("%d %d\n",p,q);
    */
    int ans=-1,m[30];
    int cnt=0;
    for(int i=0;i<=24;i++)
    {
        if(vis[i])continue;
        if(r[i/5]==1)val[i]++;
        if(c[i%5]==1)val[i]++;
        if((i==0 || i==6 || i==12 || i==18 || i==24) && p==1)val[i]++;
        if((i==4 || i==8 || i==12 || i==16 || i==20) && q==1)val[i]++;
        if(ans==-1)ans=i;
        if(val[i]>val[ans] ||(val[i]==val[ans] && g[i/5][i%5]<g[ans/5][ans%5])){ans=i;}
    }
    printf("%d\n",g[ans/5][ans%5]);
    return 0;
}
