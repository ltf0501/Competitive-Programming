#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
int isp[maxn];
void pre()
{
    for(int i=2;i<maxn;i++)if(!isp[i])
    {
        for(int j=i;j<maxn;j+=i)isp[j]=i;
    }
}
vector<int> v;
int sz;
int cal(int n)
{
    int ret=0;
    for(int i=1;i<(1<<sz);i++)
    {
        int tmp=1;
        int cnt=0;
        for(int j=0;j<sz;j++)if(i&(1<<j))
        {
            cnt++;
            tmp*=v[j];
        }
        if(cnt&1)ret+=n/tmp;
        else ret-=n/tmp;
    }
    return n-ret;
}
main()
{
    pre();
    int t;scanf("%d",&t);
    while(t--)
    {
        v.clear();
        int x,p,k;scanf("%d%d%d",&x,&p,&k);
        while(p>1)
        {
            int s=isp[p];
            v.push_back(s);
            while(p%s==0)p/=s;
        }
        sz=v.size();
        k+=cal(x);
        int l=1,r=2e9;
        while(l<=r)
        {
            int m=(l+r)>>1;
            if(cal(m)>=k)r=m-1;
            else l=m+1;
        }
        printf("%d\n",l);
    }
    return 0;
}
