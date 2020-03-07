//A*演算法
#include<queue>
#include<set>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
const int dx[]={1,-1,0,0},dy[]={0,0,-1,1};
int goal[18][2],ans;

struct state
{
    int h,step,x,y;
    string mov;
    int board[4][4];
    bool operator<(const state &rhs) const
    {
        return h+step>rhs.h+rhs.step;
    }
};
bool check(int a[][4])
{
    int t[16],sum=0,x,y,z=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            t[z++]=a[i][j];
            if(!a[i][j])x=i,y=j;
        }
    }
    for(int i=0;i<16;i++)
    {
        for(int j=i+1;j<16;j++)
        {
            if(t[j]<t[i] && t[j])sum++;
        }
    }
    if((sum+x)%2==0)return false;//無解
    return true;//有解
}
int dis(int a,int b,int c,int d)
{
    return abs(a-c)+abs(b-d);
}

int h(int b[][4])
{
    int sum=0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(b[i][j]==0 || (i==goal[b[i][j]][0] && j==goal[b[i][j]][1]))continue;
            sum+=dis(i,j,goal[b[i][j]][0],goal[b[i][j]][1]);
        }
    }
    return sum;
}
void solve(state a)
{
    priority_queue<state> q;
    int x,y;
    state u,v;
    q.push(a);
    while(!q.empty())
    {
        u=q.top(),q.pop();
        for(int i=0;i<4;i++)
        {
            x=u.x+dx[i];
            y=u.y+dy[i];
            if(x>=0 && y>=0 && x<4 && y<4)
            {
                v=u;
                swap(v.board[x][y], v.board[u.x][u.y]);
                v.step=u.step+1;
                if(i==0)v.mov.push_back('R');
                else if(i==1)v.mov.push_back('L');
                else if(i==2)v.mov.push_back('D');
                else if(i==3)v.mov.push_back('U');
                if(v.mov.size()>=2)
                {
                    int b1=v.mov.size()-1;
                    int b2=v.mov.size()-2;
                    if((v.mov[b1]=='U' && v.mov[b2]=='D')
                        ||(v.mov[b1]=='D' && v.mov[b2]=='U')
                        ||(v.mov[b1]=='L' && v.mov[b2]=='R')
                        ||(v.mov[b1]=='R' && v.mov[b2]=='L'))
                    continue;
                }
                v.h=h(v.board);
                v.x=x;
                v.y=y;
                if(v.h==0){ans=v.step;return;}
                q.push(v);
            }
        }
    }
}
main()
{
    int n=1,t;
    memset(goal,0,sizeof(goal));
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            goal[n][0]=i;
            goal[n++][1]=j;
        }
    }
    scanf("%d",&t);
    while(t--)
    {
        state s;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                scanf("%d",&s.board[i][j]);
                if(!s.board[i][j])s.x=i,s.y=j;
            }
        }
        if(!check(s.board))
        {
            printf("This puzzle is not solvable.\n");
            continue;
        }
        s.h=0;
        s.step=0;
        solve(s);
        printf("%d\n",ans);
    }
    return 0;
}
