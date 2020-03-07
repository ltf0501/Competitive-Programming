#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 1000000+10
int p[maxn],d[maxn],r[maxn];
int cmp(const int x,const int y)
{
    return p[x]<p[y];
}
main()
{
    int n,l;scanf("%d%d",&n,&l);
    int step=-1;
    for(int i=0;i<n;i++)
    {
        int D;
        scanf("%d%d",&p[i],&D);
        d[i]=(D==1) ? 1 : -1;
        if(d[i]==1)step=max(step,l-p[i]);
        else step=max(step,p[i]);
    }
    for(int i=0;i<n;i++)r[i]=i;
    sort(r,r+n,cmp);
    //for(int i=0;i<n;i++)c[r[i]]=i;
    //for(int i=0;i<n;i++)printf("%d %d\n",r[i],c[i]);
    for(int i=0;i<n;i++)p[i]=p[i]+step*d[i];
    int idx=0;
    for(int i=0;i<n;i++)if(p[i]<0)idx++;
    printf("%d\n",r[idx]);
    return 0;
}
