#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,t1,t2;
int cnt[2];
int num[33];
main()
{
    scanf("%d",&n);
    bool flag=0;
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        if(!flag)
        {
            if(!t1)t1=x,cnt[0]++;
            else if(x==t1)cnt[0]++;
            else if(x!=t1)t2=x,flag=1,cnt[1]++;
        }
        else
        {
            if(x==t1)cnt[0]++;
            else if(x==t2)cnt[1]++;
        }
        for(int j=0;(1<<j)<=(int)1e9;j++)
            if(x&(1<<j))num[j]++;
    }
    //for(int i=0;i<5;i++)printf("%d ",num[i]);puts("");
    if(!flag)return 0*printf("%d\n",t1);
    m=max(cnt[0],cnt[1]);///m>1
    //printf("%d\n",m);
    int ans=0;
    for(int j=0;(1<<j)<=(int)1e9;j++)
        if(num[j]%m!=0)ans^=(1<<j);
    printf("%d\n",ans);
    return 0;
}
