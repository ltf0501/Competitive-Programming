#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<map>
using namespace std;
map<string,int>M;
vector<int>edge[30],cir[30];
int d[30][30],vis[30];
string nam[30];
void dfs(int cur,int k)
{
    if(vis[cur])return;
    vis[cur]=1;
    cir[k].push_back(cur);
    for(int i=0;i<edge[cur].size();i++)
    {
        int v=edge[cur][i];
        if(!vis[v])dfs(v,k);
    }
}
main()
{
    int n,m,cas=1;
    while(scanf("%d%d",&n,&m)==2 && n+m)
    {
        M.clear();
        memset(vis,0,sizeof(vis));
        for(int i=0;i<30;i++){edge[i].clear();cir[i].clear();}
        for(int i=0;i<30;i++)
            for(int j=0;j<=30;j++)d[i][j]=0;

        string name1,name2;
        int idx=1;
        for(int i=0;i<m;i++)
        {
            cin>>name1>>name2;
            if(!M[name1]){M[name1]=idx;nam[idx++]=name1;}
            if(!M[name2]){M[name2]=idx;nam[idx++]=name2;}
            d[M[name1]][M[name2]]=1;
        }
        for(int k=1;k<=n;k++)//floyd
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)d[i][j]=d[i][j] || (d[i][k] && d[k][j]);
            }
        }

        for(int i=1;i<=n;i++)//在同一個電話圈連邊
        {
            for(int j=i+1;j<=n;j++)
            {
                if(d[i][j] && d[j][i])
                {
                    edge[i].push_back(j);
                    edge[j].push_back(i);
                }
            }
        }
        /*
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<edge[i].size();j++)
            {
                printf("%d ",edge[i][j]);
            }
            puts("");
        }
        */
        int cnt=0;

        for(int i=1;i<=n;i++)//找連通分量
        {
            if(!vis[i])dfs(i,cnt++);

        }

        if(cas!=1)puts("");
        printf("Calling circles for data set %d:\n",cas++);
        //printf("%d\n",cnt);

        for(int i=0;i<cnt;i++)//輸出
        {
            for(int j=0;j<cir[i].size()-1;j++)cout<<nam[cir[i][j]]<<", ";
            cout<<nam[cir[i].back()]<<endl;
        }
    }
    return 0;
}
/*
5 6
Ben Alexander
Alexander Dolly
Dolly Ben
Dolly Benedict
Benedict Dolly
Alexander Aaron

Calling circles for data set 1:
Ben, Alexander, Dolly, Benedict
Aaron

14 34
John Aaron
Aaron Benedict
Betsy John
Betsy Ringo
Ringo Dolly
Benedict Paul
John Betsy
John Aaron
Benedict George
Dolly Ringo
Paul Martha
George Ben
Alexander George
Betsy Ringo
Alexander Stephen
Martha Stephen
Benedict Alexander
Stephen Paul
Betsy Ringo
Quincy Martha
Ben Patrick
Betsy Ringo
Patrick Stephen
Paul Alexander
Patrick Ben
Stephen Quincy
Ringo Betsy
Betsy Benedict
Betsy Benedict
Betsy Benedict
Betsy Benedict
Betsy Benedict
Betsy Benedict
Quincy Martha

Calling circles for data set 2:
John, Betsy, Ringo, Dolly
Aaron
Benedict
Paul, George, Martha, Ben, Alexander, Stephen, Quincy, Patrick
*/
