#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int C[15][15],p[15],vis[15],q[15];
int n,k,cnt,ans,flag;
void backtrack(int cur,int id)
{
    if(cur==k)
    {
        cnt++;
        if(cnt==ans+1)
        {
            flag=1;
            for(int i=0;i<k;i++)printf("%d ",q[i]);
            puts("");
        }
        int check=1;
        for(int i=0;i<k;i++)
        {
            if(p[i]!=q[i]){check=0;break;}
        }
        if(check==1)
        {
            ans=cnt;
            printf("%d\n",ans);
        }

        return;
    }
    for(int i=id;i<n;i++)
    {
        if(vis[i])continue;
        q[cur]=i+1;
        vis[i]=1;
        backtrack(cur+1,i+1);
        vis[i]=0;
    }
}
main()
{
    while(scanf("%d%d",&n,&k)==2)
    {
        memset(vis,0,sizeof(vis));
        for(int i=0;i<k;i++)scanf("%d",&p[i]);
        cnt=0,flag=0,ans=1231231;
        backtrack(0,0);
        if(!flag)puts("no next combination");
    }
    return 0;
}

