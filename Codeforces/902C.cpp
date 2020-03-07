#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
int a[maxn];
int n=0;
int fa1[maxn],fa2[maxn];
main()
{
    int h;scanf("%d",&h);
    bool flag=0;
    for(int i=0;i<=h;i++)
    {
        scanf("%d",&a[i]);
        n+=a[i];
    }
    int t;
    for(int i=1;i<=h;i++)
    {
        if(a[i]!=1 && a[i-1]!=1){t=i-1,flag=1;break;}
    }
    if(!flag){puts("perfect");return 0;}
    puts("ambiguous");
    ///printf("%d\n",t);
    int cur=1;
    int tmp=1;
    for(int i=1;i<=t;i++)
    {
        for(int j=1;j<=a[i];j++)cur++,fa1[cur]=fa2[cur]=tmp;
        tmp=cur;
    }
    for(int j=1;j<=a[t+1];j++)cur++,fa1[cur]=tmp,fa2[cur]=tmp-1;
    fa2[cur]=tmp;
    tmp=cur;
    for(int i=t+2;i<=h;i++)
    {
        for(int j=1;j<=a[i];j++)cur++,fa1[cur]=fa2[cur]=tmp;
        tmp=cur;
    }
    for(int i=1;i<=n;i++)printf("%d ",fa1[i]);puts("");
    for(int i=1;i<=n;i++)printf("%d ",fa2[i]);puts("");
    return 0;
}
