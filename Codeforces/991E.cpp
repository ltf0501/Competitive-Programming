#include<bits/stdc++.h>
using namespace std;
#define ll long long
char s[20];
int num[10],a[10],sum[10];
int c[20][20];
void pre()
{
    for(int i=0;i<20;i++)c[i][0]=c[i][i]=1;
    for(int i=1;i<20;i++)for(int j=1;j<i;j++)c[i][j]=c[i-1][j]+c[i-1][j-1];
}
int C(int n,int m)
{
    if(m==-1)return 0;
    return c[n][m];
}
main()
{
    scanf("%s",s);
    int k=strlen(s);
    pre();
    for(int i=0;i<k;i++)num[s[i]-'0']++;
    ll ans=0;
    for(a[0]=0;a[0]<=num[0];a[0]++)for(a[1]=0;a[1]<=num[1];a[1]++)for(a[2]=0;a[2]<=num[2];a[2]++)for(a[3]=0;a[3]<=num[3];a[3]++)
    for(a[4]=0;a[4]<=num[4];a[4]++)for(a[5]=0;a[5]<=num[5];a[5]++)for(a[6]=0;a[6]<=num[6];a[6]++)for(a[7]=0;a[7]<=num[7];a[7]++)
        for(a[8]=0;a[8]<=num[8];a[8]++)for(a[9]=0;a[9]<=num[9];a[9]++)
    {
        bool flag=0;
        for(int i=0;i<=9;i++)if(num[i] && !a[i]){flag=1;break;}
        if(flag)continue;
        //for(int i=0;i<=9;i++)printf("%d ",a[i]);puts("");
        sum[0]=a[0];
        for(int i=1;i<=9;i++)sum[i]=sum[i-1]+a[i];
        ll tmp=0;
        ll x=1;
        for(int i=1;i<=9;i++)x*=C(sum[i],a[i]);
        tmp+=x;
       // printf("%lld ",x);
        sum[0]--;
        for(int i=1;i<=9;i++)sum[i]=sum[i-1]+a[i];
        x=1;
        for(int i=1;i<=9;i++)x*=C(sum[i],a[i]);
        tmp-=x;
        //printf("%lld\n",x);
        ans+=tmp;
    }
    printf("%lld\n",ans);
    return 0;
}
