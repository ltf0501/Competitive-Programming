#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 100+5
main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        int ans[maxn],data[maxn][maxn];
        for(int i=0;i<m;i++)scanf("%d",&ans[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<=m;j++)scanf("%d",&data[i][j]);

        for(int i=0;i<n;i++)
        {
            int tmp=data[i][m],flag=0;
            for(int j=m-1;j>=0;j--)
            {
                if(tmp>=data[i][j])
                {
                    if(ans[j]!=1)flag=1;
                }
                else
                {
                    if(ans[j]!=0)flag=1;
                }
                tmp=abs(data[i][j+1]-data[i][j]);
            }
            if(flag==0)
            {
                for(int j=0;j<=m;j++)printf("%d ",data[i][j]);
                puts("");
                break;
            }
        }
    }
    return 0;
}
