#include<bits/stdc++.h>
using namespace std;
/*
int c[20][12];
void pre()
{
    for(int i=0;i<20;i++)c[i][0]=c[i][i]=1;
    for(int i=1;i<=19;i++)for(int j=1;j<i;j++)
        c[i][j]=c[i-1][j-1]+c[i-1][j];
    for(int i=1;i<=19;i++)
    {
        printf("%d: ",i);
        for(int j=0;j<=i;j++)printf("%d ",c[i][j]);
        puts("");
    }
}
int H(int a,int b)
{
    return c[a+b-1][b];
}
main()
{
    pre();
    int k;scanf("%d",&k);
    int cur=2;
    while(H(cur-1,10)-(cur-1)<=k)cur++;
    cur--;
    printf("%d\n",cur);
    int now=10;
    int t,cnt=0;
    cur--;
    for(int i=1;i<=9;i++)
    {
        if(cnt>k){t=i-1;break;}
        cnt+=H(cur,now-i);
    }
    cnt-=H(cur,now-t);
    now-=t;k-=cnt;
    printf("%d",t);
    while(cur--)
    {
        if(!cur){printf("%d",now);break;}
        cnt=0;
        for(int i=0;i<=9;i++)
        {
            if(cnt>k){t=i-1;break;}
            cnt+=H(cur,now-i);
        }
        cnt-=H(cur,now-t);
        now-=t;printf("%d",t);
        k-=cnt;
        //printf("now,k=%d %d\n",now,k);
        if(!now)
        {
            while(cur--)printf("0");
            return 0;
        }
    }
    return 0;
}
*/
int num(int a)
{
    int ret=0;
    while(a)
    {
        ret+=a%10;
        a/=10;
    }
    return ret;
}
main()
{
    int k;scanf("%d",&k);
    int ans=10;
    while(1)
    {
        ans+=9;
        if(num(ans)==10)k--;
        if(!k)return 0*printf("%d\n",ans);
    }
}
