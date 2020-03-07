#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
int n;
int cnt[maxn];
main()
{
    scanf("%d",&n);
    int ans=1;
    int N=n;
    for(int i=2;i<=n;i++)if(N%i==0)
    {
        ans*=i;
        while(N%i==0)cnt[i]++,N/=i;
    }
    int mx=0;
    for(int i=2;i<=n;i++)mx=max(mx,cnt[i]);
    //printf("%d\n",mx);
    int num=0;
    if(mx!=1)
    {
        int cur=1;
        for(int id=0;;cur<<=1,id++)
            if(cur+1>mx){num=id;break;}
        for(int i=2;i<=n;i++)
            if(cnt[i] && (cnt[i]!=cur)){num++;break;}
    }
    printf("%d %d\n",ans,num);
    return 0;
}
