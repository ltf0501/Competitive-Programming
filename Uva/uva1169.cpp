//單調佇列
#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 100000+10
int d[maxn]/*從原點出發清完前i個垃圾回到原點 */,q[maxn];
int x[maxn],y[maxn];
int tot_dist[maxn]/*從第1個垃圾,一次經過2,3,...,i距離*/,tot_weight[maxn],dist2origin[maxn];
/*d[i]=min{d[j]+dist2origin[j+1]+tot_dist[i]-tot_dist[j+1]+dist2origin[i]|j<=i,w(j+1,i)<c}
=min{fun(j)|j<=i,w(j+1,i)<c}+tot_dist[i]+dist2origin[i]*/
int fun(int i)
{
    return d[i]-tot_dist[i+1]+dist2origin[i+1];
}
main()
{
    int t,c,n,w,fro,rear;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&c,&n);
        tot_dist[0]=tot_weight[0]=x[0]=y[0]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&x[i],&y[i],&w);
            dist2origin[i]=abs(x[i])+abs(y[i]);
            tot_dist[i]=tot_dist[i-1]+abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
            tot_weight[i]=tot_weight[i-1]+w;
        }
        fro=rear=1;
        for(int i=1;i<=n;i++)
        {
            while(fro<=rear && tot_weight[i]-tot_weight[q[fro]]>c)fro++;
            d[i]=fun(q[fro])+tot_dist[i]+dist2origin[i];
            while(fro<=rear && fun(i)<=fun(q[rear]))rear--;
            q[++rear]=i;
        }
        printf("%d\n",d[n]);
        if(t>0)printf("\n");
    }
    return 0;
}

