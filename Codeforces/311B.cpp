#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ll long long
const ll INF=1e16;
int n,m,k;
int d[maxn],t[maxn],h[maxn];
ll a[maxn],s[maxn];
deque<int> dq;
ll dp[maxn],pre[maxn];
ll y(int k){return pre[k]+s[k];}
main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=2;i<=n;i++)scanf("%d",&d[i]),d[i]+=d[i-1];
    for(int i=1;i<=m;i++)scanf("%d%d",&h[i],&t[i]);
    for(int i=1;i<=m;i++)a[i]=t[i]-d[h[i]];
    sort(a+1,a+m+1);
    //for(int i=1;i<=m;i++)printf("%I64d ",a[i]);puts("");
    for(int i=1;i<=m;i++)s[i]=s[i-1]+a[i];
    for(int i=1;i<=m;i++)pre[i]=INF;
    for(int i=1;i<=k;i++)
    {
        while(!dq.empty())dq.pop_front();
        dq.push_back(0);
        for(int j=1;j<=m;j++)
        {
            while(dq.size()>=2)
            {
                int p=dq.front();dq.pop_front();
                int q=dq.front();
                double X=1.0*a[j]*(q-p);
                double Y=1.0*(y(q)-y(p));
                if(Y>=X)
                {
                    //printf("%d %d\n",p,q);
                    dq.push_front(p);
                    break;
                }
            }
            int t=dq.front();
            //printf("%d: %d\n",j,t);
            dp[j]=pre[t]+(j-t)*a[j]-s[j]+s[t];
            while(dq.size()>=2)
            {
                int q=dq.back();dq.pop_back();
                int p=dq.back();
                double X=1.0*(y(q)-y(p))*(j-q);
                double Y=1.0*(y(j)-y(q))*(q-p);
                if(Y>=X)
                {
                    dq.push_back(q);
                    break;
                }
            }
            dq.push_back(j);
        }
        for(int j=1;j<=m;j++)pre[j]=dp[j];
        //for(int j=1;j<=m;j++)printf("%I64d ",dp[j]);puts("");
    }
    printf("%I64d\n",dp[m]);
    return 0;
}
