#include<bits/stdc++.h>
using namespace std;
int a[55][55];
int n,k;
const int dx[]={0,-1,0,1};
const int dy[]={-1,0,1,0};
main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
        scanf("%d",&a[i][j]);
    printf("%d",a[(n+1)/2][(n+1)/2]);
    int x=(n+1)/2,y=(n+1)/2;
    int cnt=1;
    while(cnt<=2*n-2)
    {
        for(int i=1;i<=(cnt+1)/2;i++)
        {
            x+=dx[k],y+=dy[k];
            printf("%d",a[x][y]);
        }
        k=(k+1)%4;
        cnt++;
    }
    cnt=n-1;
    while(cnt--)
    {
        x+=dx[k],y+=dy[k];
        printf("%d",a[x][y]);
    }
    puts("");
    return 0;
}
