#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
const double INF=1e18;
int t[maxn];
ll sum[maxn];
int n,k;
double dp[maxn],tmp[maxn];
double p[maxn],q[maxn];
deque<int> dq;
double a(int i){return -sum[i];}
double b(int i){return dp[i]-p[i]+sum[i]*q[i];}
double g(int i,int j){return (b(i)-b(j))/(a(j)-a(i));}
main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&t[i]),sum[i]=sum[i-1]+t[i];
    for(int i=1;i<=n;i++)p[i]=p[i-1]+(double)sum[i]/(double)t[i];
    for(int i=1;i<=n;i++)q[i]=q[i-1]+1.0/(double)t[i];
    //for(int i=1;i<=n;i++)printf("%f ",p[i]);puts("");
    //for(int i=1;i<=n;i++)printf("%f ",q[i]);puts("");
    for(int i=1;i<=n;i++)dp[i]=INF;
    for(int s=1;s<=k;s++)
    {
        dq.clear();
        dq.push_back(0);
        for(int i=1;i<=n;i++)
        {
            while(dq.size()>=2)
            {
                int l=dq[0],j=dq[1];
                if(q[i]>=g(j,l))dq.pop_front();
                else break;
            }
            int j=dq.front();
            //printf("%d: %d\n",i,j);
            tmp[i]=a(j)*q[i]+b(j)+p[i];
            while(dq.size()>=2)
            {
               int j=dq[dq.size()-1],l=dq[dq.size()-2];
               if(g(i,j)<=g(j,l))dq.pop_back();
               else break;
            }
            dq.push_back(i);
        }
        for(int i=1;i<=n;i++)dp[i]=tmp[i];
        //for(int i=1;i<=n;i++)printf("%f ",dp[i]);puts("");
        //puts("");
    }
    printf("%.6f\n",dp[n]);
    return 0;
}
