#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

using namespace std;
const int INF = 1e8;
const int MAXN = 5e3 + 5;

char p[MAXN],q[MAXN];
int sp[26],sq[26],ep[26],eq[26];
int d[MAXN][MAXN],c[MAXN][MAXN];
//dp(i,j)=min{dp(i-1,j)+c(i-1,j),dp(i,j-1)+c(i,j-1)}
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",p+1,q+1);
        int n=strlen(p+1),m=strlen(q+1);
        c[0][0]=0;
        for(int i=1;i<=n;i++)p[i]-='A';
        for(int i=1;i<=m;i++)q[i]-='A';
        for(int i=0;i<26;i++)
        {
            sp[i]=sq[i]=INF;
            ep[i]=eq[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            sp[p[i]]=min(sp[p[i]],i);//p開始
            ep[p[i]]=i;//p結束
        }
        for(int i=1;i<=m;i++)
        {
            sq[q[i]]=min(sq[q[i]],i);//q開始
            eq[q[i]]=i;//q結束
        }
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(!i && !j)continue;
                int v1=INF,v2=INF;
                if(i>0)v1=d[i-1][j]+c[i-1][j];
                if(j>0)v2=d[i][j-1]+c[i][j-1];
                d[i][j]=min(v1,v2);//計算d

                if(i>0)
                {
                    c[i][j]=c[i-1][j];
                    if(sp[p[i]]==i && sq[p[i]]>j)c[i][j]++;
                    if(ep[p[i]]==i && eq[p[i]]<=j)c[i][j]--;
                }
                else
                {
                    c[i][j]=c[i][j-1];
                    if(sq[q[j]]==j && sp[q[j]]>i)c[i][j]++;
                    if(eq[q[j]]==j&&ep[q[j]]<=i)c[i][j]--;
                }
            }
        }
        printf("%d\n",d[n][m]);

    }
    return 0;
}
