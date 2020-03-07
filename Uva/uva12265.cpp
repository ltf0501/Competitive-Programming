#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stack>
using namespace std;
#define maxw 1010
int n,m;
char g[maxw][maxw];
int ans[maxw][maxw],h[maxw],g2[maxw][maxw];
struct point
{
    int c,h;
};
main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%s",g[i]);
            for(int j=0;j<m;j++)
            {
                if(g[i][j]=='#')g2[i+1][j+1]=1;
                if(g[i][j]=='.')g2[i+1][j+1]=0;
            }
        }
        memset(h,0,sizeof(h));
        memset(ans,0,sizeof(ans));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(g2[i][j]==1)h[j]=0;
                if(g2[i][j]==0)h[j]++;

                //printf("%d ",h[j]);
            }
            //printf("\n");

            stack<point> rec;
            int curj=0;
            for(int j=1;j<=m;j++)
            {
                if(h[j]==0){curj=j;continue;}
                if(rec.empty() || rec.top().c<curj)
                {
                    while(!rec.empty())rec.pop();
                    point k;k.c=j;k.h=h[j];rec.push(k);
                    ans[i][j]=rec.top().h-rec.top().c;
                    continue;
                }
                if(rec.top().c>curj)
                {
                    if(!rec.empty() && h[j]<=rec.top().h)
                    {
                        point e=rec.top();rec.pop();
                        e.h=h[j];
                        if(rec.empty())rec.push(e);
                        else if(e.h-e.c>rec.top().h-rec.top().c)rec.push(e);
                        ans[i][j]=rec.top().h-rec.top().c;
                        continue;
                    }

                    if(!rec.empty() && h[j]>rec.top().h)
                    {
                        if(h[j]-j>rec.top().h-rec.top().c){point k;k.c=j;k.h=h[j];rec.push(k);ans[i][j]=k.h-k.c;continue;}
                        else ans[i][j]=rec.top().h-rec.top().c;
                        continue;
                    }
                }
            }

        }
        int cnt[4005];
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(g2[i][j]==1)continue;
                cnt[2*(ans[i][j]+1+j)]++;
            }
        }
        for(int i=2;i<=2*(m+n);i+=2)
        {
            if(cnt[i]>0)printf("%d x %d\n",cnt[i],i);
        }

    }
    return 0;
}
/*
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 1000 + 10;
char s[maxn][maxn];

int height[maxn], ans[maxn << 1];

struct Rect
{
    int c, h;
    Rect(int c = 0, int h = 0):c(c), h(h) {}
}rect[maxn];

int n, m;

int main()
{
    //freopen("in.txt", "r", stdin);

    int T; scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++) scanf("%s", s[i]);

        memset(height, 0, sizeof(height));
        memset(ans, 0, sizeof(ans));

        for(int i = 0; i < n; i++)
        {
            int top = -1;
            for(int j = 0; j < m; j++)
            {
                if(s[i][j] == '#')
                {
                    top = -1;
                    height[j] = 0;
                }
                else
                {
                    height[j]++;
                    Rect r(j, height[j]);
                    if(top < 0) rect[++top] = r;    //空栈直接入栈
                    else
                    {
                        while(top >= 0 && rect[top].h >= r.h) r.c = rect[top--].c; //栈中的h应小于height[j]
                        if(top < 0 || r.h - r.c > rect[top].h - rect[top].c) rect[++top] = r;
                    }
                    r = rect[top];
                    ans[r.h + j - r.c + 1]++;
                }
            }
        }
        for(int i = 2; i <= m + n; i++) if(ans[i]) printf("%d x %d\n", ans[i], i * 2);
    }

    return 0;
}
*/
