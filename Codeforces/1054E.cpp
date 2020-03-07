#include<bits/stdc++.h>
using namespace std;
#define maxn 310
string s[maxn][maxn],t[maxn][maxn];
deque<char> dq[maxn][maxn];
int n,m;
struct P{int x1,y1,x2,y2;};
vector<P> ans;
void oper(int x1,int y1,int x2,int y2)
{
    ans.push_back({x1,y1,x2,y2});
    //printf("%d %d %d %d\n",x1,y1,x2,y2);
    //assert(!dq[x1][y1].empty());
    assert(x1==x2 || y1==y2);
    char c=dq[x1][y1].back();dq[x1][y1].pop_back();
    dq[x2][y2].push_front(c);
}
main()
{
    cin.tie(0);ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)cin>>s[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)cin>>t[i][j];
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
        for(char ss : s[i][j])dq[i][j].push_back(ss);
    while(!dq[1][1].empty())oper(1,1,1,2);
    while(!dq[n][m].empty())oper(n,m,n-1,m);
    while(!dq[1][m].empty())
    {
        char c=dq[1][m].back();
        if(c=='0')oper(1,m,1,1);
        else oper(1,m,n,m);
    }
    while(!dq[n][1].empty())
    {
        char c=dq[n][1].back();
        if(c=='0')oper(n,1,1,1);
        else oper(n,1,n,m);
    }
    for(int i=2;i<n;i++)
    {
        while(!dq[i][1].empty())
        {
            char c=dq[i][1].back();
            if(c=='0')oper(i,1,1,1);
            else oper(i,1,n,1);
        }
        while(!dq[i][m].empty())
        {
            char c=dq[i][m].back();
            if(c=='1')oper(i,m,n,m);
            else oper(i,m,1,m);
        }
    }
    for(int i=2;i<m;i++)
    {
        while(!dq[1][i].empty())
        {
            char c=dq[1][i].back();
            if(c=='0')oper(1,i,1,1);
            else oper(1,i,1,m);
        }
        while(!dq[n][i].empty())
        {
            char c=dq[n][i].back();
            if(c=='1')oper(n,i,n,m);
            else oper(n,i,n,1);
        }
    }
    while(!dq[1][m].empty())
    {
        char c=dq[1][m].back();
        if(c=='0')oper(1,m,1,1);
        else oper(1,m,n,m);
    }
    while(!dq[n][1].empty())
    {
        char c=dq[n][1].back();
        if(c=='0')oper(n,1,1,1);
        else oper(n,1,n,m);
    }

    for(int i=2;i<n;i++)for(int j=2;j<m;j++)
    {
        while(!dq[i][j].empty())
        {
            char c=dq[i][j].back();
            if(c=='0')oper(i,j,i,1);
            else oper(i,j,i,m);
        }
    }
    for(int i=2;i<n;i++)
    {
        while(!dq[i][1].empty())
        {
            oper(i,1,1,1);
        }
        while(!dq[i][m].empty())
        {
            oper(i,m,n,m);
        }
    }
    for(int i=2;i<n;i++)for(int j=2;j<m;j++)
    {
        for(int k=t[i][j].size();k--;)
        {
            if(t[i][j][k]=='0')oper(1,1,i,1),oper(i,1,i,j);
            else oper(n,m,i,m),oper(i,m,i,j);
        }
    }
    for(int i=2;i<n;i++)
    {
        for(int k=t[i][1].size();k--;)
        {
            if(t[i][1][k]=='0')oper(1,1,i,1);
            else oper(n,m,n,1),oper(n,1,i,1);
        }
        for(int k=t[i][m].size();k--;)
        {
            if(t[i][m][k]=='1')oper(n,m,i,m);
            else oper(1,1,1,m),oper(1,m,i,m);
        }
    }
    for(int i=2;i<m;i++)
    {
        for(int k=t[1][i].size();k--;)
        {
            if(t[1][i][k]=='0')oper(1,1,1,i);
            else oper(n,m,1,m),oper(1,m,1,i);
        }
        for(int k=t[n][i].size();k--;)
        {
            if(t[n][i][k]=='1')oper(n,m,n,i);
            else oper(1,1,n,1),oper(n,1,n,i);
        }
    }
    for(int k=t[1][1].size();k--;)
    {
        if(t[1][1][k]=='0')oper(1,1,n,1),oper(n,1,1,1);
        else oper(n,m,n,1),oper(n,1,1,1);
    }
    for(int k=t[n][m].size();k--;)
    {
        if(t[n][m][k]=='1')oper(n,m,n,1),oper(n,1,n,m);
        else oper(1,1,n,1),oper(n,1,n,m);
    }
    for(int k=t[n][1].size();k--;)
    {
        if(t[n][1][k]=='0')oper(1,1,n,1);
        else oper(n,m,n,1);
    }
    for(int k=t[1][m].size();k--;)
    {
        if(t[1][m][k]=='0')oper(1,1,1,m);
        else oper(n,m,1,m);
    }
    printf("%d\n",ans.size());
    for(P ss : ans)printf("%d %d %d %d\n",ss.x1,ss.y1,ss.x2,ss.y2);
    /*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(char c : dq[i][j])putchar(c);
            printf(" ");
        }
        puts("");
    }
    */
    return 0;
}

