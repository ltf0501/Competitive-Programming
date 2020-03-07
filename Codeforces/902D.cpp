#include<bits/stdc++.h>
using namespace std;
#define maxn 155
int A[2][maxn];
int tmp1[maxn],tmp2[maxn],tmp3[maxn];
bool check(int a[])
{
    for(int i=0;i<=150;i++)if(a[i]>=2 || a[i]<=-2)return 0;
    return 1;
}
void add(int (&a)[maxn],int b[maxn])
{
    for(int i=0;i<=150;i++)a[i]+=b[i];
}
int cnt=0;
void gao(int (&a)[maxn],int (&b)[maxn])
{
    cnt++;
    //for(int i=0;i<=10;i++)printf("%d ",a[i]);puts("");
    //for(int i=0;i<=10;i++)printf("%d ",b[i]);puts("");
    for(int i=0;i<=150;i++)tmp1[i]=tmp2[i]=a[i];
    for(int i=151;i>=1;i--)tmp2[i]=tmp2[i-1];
    tmp2[0]=0;
    for(int i=0;i<=150;i++)tmp3[i]=tmp2[i];
    add(tmp3,b);
    ///for(int i=0;i<=10;i++)printf("%d ",tmp1[i]);puts("");
    if(check(tmp3))
    {
        for(int i=0;i<=150;i++)a[i]=tmp3[i],b[i]=tmp1[i];
        return ;
    }
    for(int i=0;i<=150;i++)tmp3[i]=-tmp2[i];
    add(tmp3,b);
    //if(!check(tmp3))printf("%d\n",cnt);
    for(int i=0;i<=150;i++)a[i]=tmp3[i],b[i]=tmp1[i];
}
main()
{
    int n;scanf("%d",&n);
    A[1][0]=1;
    for(int i=1;i<=n;i++)gao(A[1],A[0]);
    printf("%d\n",n);
    int flag=A[1][n]>0?1:-1;
    for(int j=0;j<=n;j++)printf("%d ",A[1][j]*flag);puts("");
    printf("%d\n",n-1);
    flag=A[0][n-1]>0?1:-1;
    for(int j=0;j<n;j++)printf("%d ",A[0][j]*flag);puts("");
    return 0;
}
