#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
#define maxm 1000+5
int p[15],n,m;
int u[maxm],v[maxm],w[maxm],r[maxm];

int cmp(const int i,const int j)
{
    return w[i]<w[j];
}
struct Ans
{
    int p,q;
    bool operator < (const Ans &rhs)const
    {
        return p<rhs.p || (p==rhs.p && q<rhs.q);
    }
}ans[15];
int findset(int x)
{
    return p[x]==x ? x : p[x]=findset(p[x]);
}
int Kruskal()
{
    int res=0;
    for(int i=0;i<n;i++)p[i]=i;
    for(int i=0;i<m;i++)r[i]=i;
    sort(r,r+m,cmp);
    int cnt=1;
    for(int i=0;i<m;i++)
    {
        int e=r[i];int x=findset(u[e]),y=findset(v[e]);
        if(x!=y){res+=w[e];p[x]=y;ans[cnt].p=u[e];ans[cnt].q=v[e];cnt++;}
    }
    return res;
}
main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        char A[3],B[3];
        int c;
        A[2]=B[2]=' ';
        for(int i=0;i<m;i++)
        {
            cin>>A>>B>>c;
            int a,b;
            if(A[2]=='0')a=9;
            else a=A[1]-'0'-1;
            if(B[2]=='0')b=9;
            else b=B[1]-'0'-1;
            u[i]=a;v[i]=b;w[i]=c;
           // printf("%d %d %d\n",a,b,c);
        }
        int res=Kruskal();
        sort(ans+1,ans+n);

        for(int i=1;i<=n-2;i++)printf("(W%d W%d) ",ans[i].p+1,ans[i].q+1);
        printf("(W%d W%d)\n",ans[n-1].p+1,ans[n-1].q+1);
        printf("%d\n",res);
    }
    return 0;
}
