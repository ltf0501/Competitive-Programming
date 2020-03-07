#include<cstdio>
#include<algorithm>
using namespace std;
int a[35][35],tmp[35][35],m[35][35];
char c[35];
main()
{
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",c);
        for(int j=0;j<n;j++)m[i][j]=(c[j]=='1');
    }
    int p,q,N;
    scanf("%d%d%d",&p,&q,&N);
    int ans=0;

    for(int i=0;i<n;i++)a[i][i]=1;
    for(int s=1;s<=N;s++)
    {
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)tmp[i][j]=a[i][j],a[i][j]=0;

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    a[i][j]+=tmp[i][k]*m[k][j];

        ans+=a[p-1][q-1];
        //printf("%d\n",a[p-1][q-1]);
    }
    printf("%d\n",ans);
    return 0;
}
