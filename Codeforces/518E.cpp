#include<bits/stdc++.h>
using namespace std;
#define INF 2147483646
#define maxn 100000+5
int a[2*maxn];
main()
{
    int n,k;scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        char s[12];scanf("%s",s);
        if(s[0]=='?')a[i]=INF;
        else sscanf(s,"%d",&a[i]);
    }
    for(int i=n+1;i<=n+k;i++)a[i]=INF+1;
    for(int i=1;i<=k;i++)
    {
        int cnt=0,cur=-INF;
        for(int j=i;j<=n+k;j+=k)
        {
            if(a[j]==INF)cnt++;
            else
            {
                if(a[j]<=cnt+cur)
                {
                    puts("Incorrect sequence");
                    return 0;
                }
                int r=max(cur+1,min(a[j]-cnt,-cnt/2));
                for(int l=cnt;l>0;l--)a[j-l*k]=r++;
                cnt=0,cur=a[j];
            }
        }
    }
    for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
    return 0;
}
