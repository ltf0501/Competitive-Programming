#include<bits/stdc++.h>
using namespace std;
int a[105];
int cnt;
int n,l;
bool dfs(int cur)
{
    if(cnt++==n)
    {
        for(int i=0;i<cur;i++)
        {
            if(i && (i%64==0))puts("");
            else if(i && (i%4==0))printf(" ");
            printf("%c",'A'+a[i]);
        }
        puts("");
        printf("%d\n",cur);
        return 0;
    }
    for(int i=0;i<l;i++)
    {
        a[cur]=i;
        bool ok=1;
        for(int j=1;j*2<=cur+1;j++)
        {
            bool flag=1;
            for(int k=0;k<j;k++)
                if(a[cur-k]!=a[cur-j-k]){flag=0;break;}
            if(flag){ok=0;break;}
        }
        if(ok)
        {
            if(!dfs(cur+1))return 0;
        }
    }
    return 1;
}
main()
{
    while(~scanf("%d%d",&n,&l) && n+l)
    {
        memset(a,0,sizeof(a));
        cnt=0;
        dfs(0);
    }
    return 0;
}
