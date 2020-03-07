#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define ll long long
int n,k;
int isp[maxn];
void pre()
{
    for(int i=2;i<maxn;i++)if(!isp[i])
    {
        for(int j=i;j<maxn;j+=i)isp[j]=i;
    }
    //printf("%d\n",sz);
}
int cnt[maxn];
main()
{
    pre();
    scanf("%d%d",&n,&k);
    while(n--)
    {
        int x;scanf("%d",&x);
        while(x>1)
        {
            int c=0;
            int p=isp[x];
            while(x%p==0)
            {
                c++,x/=p;
            }
            cnt[p]=max(cnt[p],c);
        }
    }
    //for(int i=0;i<20;i++)printf("%d ",cnt[i]);puts("");
    bool flag=1;
    while(k>1)
    {
        //printf("%d\n",cnt[isp[n]]);
        int p=isp[k];
        flag&=(cnt[p]>0);
        k/=p;cnt[p]--;
    }
    puts(flag ? "Yes" : "No");
    return 0;
}
