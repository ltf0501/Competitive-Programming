#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
long long hp[2][20][20];
void dfs(int idx,long long num)
{
    for(int i=1;i<=17;i++)
    {
        if(num%(1<<i)==0)
        {
            hp[0][idx][i]=min(hp[0][idx][i],num);
            hp[1][idx][i]=max(hp[1][idx][i],num);
        }
        else break;
    }
    if(idx==17)
        return;
    dfs(idx+1,num*10+1);
    dfs(idx+1,num*10+2);
}
main()
{
    int t;scanf("%d",&t);
    int p,q,cas=0;
    memset(hp[0],127,sizeof(hp[0]));
    memset(hp[1],0,sizeof(hp[1]));
    dfs(0,0);
    while(t--)
    {
        scanf("%d%d",&p,&q);
        printf("Case %d: ",++cas);
        if(hp[0][p][q]==hp[1][p][q])printf("%lld\n",hp[0][p][q]);
        else if(hp[1][p][q]==0)printf("impossible\n");
        else printf("%lld %lld\n",hp[0][p][q],hp[1][p][q]);
    }
    return 0;
}
