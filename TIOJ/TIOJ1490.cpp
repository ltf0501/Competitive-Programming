#include<bits/stdc++.h>
using namespace std;
int n;
int cnt[105];
main()
{
    while(~scanf("%d",&n) && n)
    {
        memset(cnt,0,sizeof(cnt));
        int tot=0;
        bool flag=1;
        for(int i=1;i<=n;i++)
        {
            int x;scanf("%d",&x);
            cnt[x]++,tot+=x;
            if(x>=n)flag=0;
        }
        if((tot&1) || !flag){puts("no");continue;}
        for(int i=100;i;i--)while(cnt[i])
        {
            int now=i;
            cnt[i]--;
            int last=0,tlast;
            for(int j=i;now>0&&j>0;j--)
            {
                if(now>cnt[j])tlast=cnt[j],now-=cnt[j],cnt[j]=0;
                else cnt[j]-=now,cnt[j-1]+=now,now=0;
                cnt[j]+=last;
                last=tlast;
            }
            if(now){flag=0;break;}
        }
        puts(flag ? "yes" : "no");
    }
    return 0;
}
