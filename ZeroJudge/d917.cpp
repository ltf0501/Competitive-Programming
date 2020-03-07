#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
vector<int> s1[505],s2[505];
queue<int> que;
int in1[505]={0},in2[505]={0};
int d[505]={0},v[505]={0};
int main()
{
    int L=0,R=0,i,j,n,w,x,y,z;
    scanf("%d%d",&n,&w);
    for(i=0;i<n*(n-1)/2;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        if(z) s1[x].push_back(y),in1[y]++;
        else s2[x].push_back(y),in2[y]++;
    }
    for(i=1;i<=n;i++)
        if(in1[i]==0)v[i]=1,que.push(i);
    while(que.size())
    {
        x=que.front();
        que.pop();
        d[x]++;
        if(d[x]>L)L=d[x];
        for(i=0;i<s1[x].size();i++)
        {
            y=s1[x][i];
            if(d[x]>d[y])d[y]=d[x];
            in1[y]--;
            if(!v[y] && in1[y]==0)
            {
                v[y]=1;
                que.push(y);
            }
        }
    }
    memset(d,0,sizeof(d));
    memset(v,0,sizeof(v));
    for(i=1;i<=n;i++)
        if(in2[i]==0)v[i]=1,que.push(i);
    while(que.size())
    {
        x=que.front();
        que.pop();
        d[x]++;
        if(d[x]>R)R=d[x];
        for(i=0;i<s2[x].size();i++)
        {
            y=s2[x][i];
            if(d[x]>d[y])d[y]=d[x];
            in2[y]--;
            if(!v[y] && in2[y]==0)
            {
                v[y]=1;
                que.push(y);
            }
        }
    }
    printf("%d\n",w*w*L*R);
}
