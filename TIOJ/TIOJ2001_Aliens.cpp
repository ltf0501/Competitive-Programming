#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
const double eps=3e-16;
double t[maxn],sum[maxn];
int n,k;
double dp[maxn];
double p[maxn],q[maxn];
deque<int> dq;
double a(int i){return -sum[i];}
double b(int i){return dp[i]-p[i]+sum[i]*q[i];}
double g(int i,int j){return (b(i)-b(j))/(a(j)-a(i));}
struct P{double ans;int pos;};
int turn[maxn];
P sol(double s)
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
        dp[i]=a(j)*q[i]+b(j)+p[i]+s;
        turn[i]=turn[j]+1;
        while(dq.size()>=2)
        {
           int j=dq[dq.size()-1],l=dq[dq.size()-2];
           if(g(i,j)<=g(j,l))dq.pop_back();
           else break;
        }
        dq.push_back(i);
    }
    return (P){dp[n],turn[n]};
}
main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%lf",&t[i]),sum[i]=sum[i-1]+t[i];
    for(int i=1;i<=n;i++)p[i]=p[i-1]+(double)sum[i]/(double)t[i];
    for(int i=1;i<=n;i++)q[i]=q[i-1]+1.0/(double)t[i];
    //for(int i=1;i<=n;i++)printf("%f ",p[i]);puts("");
    //for(int i=1;i<=n;i++)printf("%f ",q[i]);puts("");
    double l=-1,r=p[n]+1;
    double ans;
    while(1)
    {
        double m=(l+r)/2.0;
        P ret=sol(m);
        if(ret.pos==k){ans=ret.ans-m*k;break;}
        //if(r-l<eps){ans=ret.ans-m*k;break;}
        if(ret.pos<k)r=m;
        else l=m;
    }
    printf("%f\n",ans);
    return 0;
}
