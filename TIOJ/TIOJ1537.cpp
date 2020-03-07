#include<bits/stdc++.h>
using namespace std;
int a[30];
void dfs(int cur,int l)
{
    if(l<0)return ;
    if(l==0)
    {
        if(cur>2)
        {
            for(int i=1;i<cur-1;i++)printf("%d, ",a[i]);
            printf("%d\n",a[cur-1]);
        }
        return ;
    }
    for(int i=a[cur-1];i<=l;i++)
    {
        a[cur]=i;
        //printf("%d\n",cur);
        dfs(cur+1,l-i);
        a[cur]=0;
    }
}
main()
{
    int n,cas=0;scanf("%d",&n);
    a[0]=1;
    while(n--)
    {
        int x;scanf("%d",&x);
        printf("Plank %d:\n",++cas);
        dfs(1,x);
    }
    return 0;
}
