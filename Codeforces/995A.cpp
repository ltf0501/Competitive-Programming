#include<bits/stdc++.h>
using namespace std;
#define maxn 105
int a[4][maxn];
int n,k;
int pos1[maxn],pos2[maxn];
struct P{int id,x,y;};
vector<P> ans;
vector<int> v;
bool vis[maxn];
main()
{
    scanf("%d%d",&n,&k);
    int m=2*n;
    for(int i=0;i<4;i++)for(int j=0;j<n;j++)scanf("%d",&a[i][j]);
    for(int i=0;i<n;i++)
        if(a[0][i])pos1[a[0][i]]=i;
    for(int i=n-1;i>=0;i--)
        if(a[3][i])pos1[a[3][i]]=m-1-i;
    for(int i=0;i<n;i++)
        if(a[1][i])pos2[a[1][i]]=i;
    for(int i=n-1;i>=0;i--)
        if(a[2][i])pos2[a[2][i]]=m-1-i;
    int z=k;
    for(int i=1;i<=z;i++)if(pos1[i]==pos2[i])
    {
        int x,y;
        if(pos1[i]<n)x=0,y=pos1[i];
        else x=3,y=m-1-pos1[i];
        ans.push_back({i,x+1,y+1});
        x=((x==0)?1:2);
        a[x][y]=0;
        k--;
    }
    if(k==m)return 0*puts("-1");
    if(k)
    {
        int r;
        for(int i=0;i<n;i++)if(!a[1][i])r=i;
        for(int i=n-1;i>=0;i--)if(!a[2][i])r=m-1-i;
        for(int i=0;i<m;i++)
        {
            int x,y;
            if(r<n)x=1,y=r;
            else x=2,y=m-1-r;
            if(a[x][y])v.push_back(a[x][y]);
            r=(r+m-1)%m;
        }
        //for(int s : v)printf("%d ",s);puts("");
        int cur=0;
        while(1)
        {
            bool flag=0;
            for(int s : v)if(!vis[s])
            {
                int x,y;
                if(pos2[s]==pos1[s])
                {
                    if(pos2[s]<n)x=0,y=pos2[s];
                    else x=3,y=2*n-1-pos2[s];
                    ans.push_back({s,x+1,y+1});
                    vis[s]=1;cur++;
                }
                else
                {
                    pos2[s]=(pos2[s]+1)%m;
                    if(pos2[s]<n)x=1,y=pos2[s];
                    else x=2,y=m-1-pos2[s];
                    ans.push_back({s,x+1,y+1});
                }
                if(cur==k){flag=1;break;}
            }
            if(flag)break;
        }
    }
    int XD=ans.size();
    assert(XD<=20000);
    printf("%d\n",XD);
    for(auto s : ans)printf("%d %d %d\n",s.id,s.x,s.y);
    return 0;
}
