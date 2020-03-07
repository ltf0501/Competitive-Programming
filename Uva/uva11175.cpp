#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=300+5;
int T,n,m,x,y;
int maps[maxn][maxn];
bool judge()
{
    int i,j,k;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            int f1=0,f2=0;
            for(k=0;k<n;k++)
            {
                if (maps[i][k]&&maps[j][k])
                    f1=1;
                if (maps[i][k]^maps[j][k])
                    f2=1;
            }
            if(f1&&f2)
                return false;
        }
    return true;
}
int main()
{
    scanf("%d",&T);
    for(int C=0;C<T;++C)
    {
        int i;
        memset(maps,0,sizeof(maps));
        scanf("%d%d",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            maps[x][y]=1;
        }
        printf("Case #%d: ",C+1);
        if (judge())
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
