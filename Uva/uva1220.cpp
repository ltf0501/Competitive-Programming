#include<cstdio>
#include<algorithm>
#include<map>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

#define maxn 200+10
int n;
vector<int> S[maxn];
map<string, int> Name;
int d[maxn][2],ff[maxn][2];//d判斷最大,f判斷唯一d[?][1]表有取? 0反之
int dp(int u,int f)
{
    if(d[u][f])return d[u][f];
    if(S[u].size()==0)d[u][f]=f;
    else
    {
        if(f==1)
        {
            d[u][f]=1;
            for(int i=0;i<S[u].size();i++)
            {
                d[u][f]+=dp(S[u][i],0);
                if(ff[S[u][i]][0]) ff[u][f] = 1;
            }
        }
        else
        {
            d[u][f] = 0;
            for(int i=0;i<S[u].size();i++)
            {
                int a = dp(S[u][i], 0), b = dp(S[u][i], 1), c = max(a,b);
                d[u][f] += c;
                if( a == b
                    || (a > b && ff[S[u][i]][0])
                    || (a < b && ff[S[u][i]][1])
                   ) ff[u][f] = 1;
            }
        }

    }
    return d[u][f];
}
void init()
{
    for(int i=0;i<maxn;i++)S[i].clear();
    Name.clear();
    memset(d,0,sizeof(d));
    memset(ff,0,sizeof(ff));
    char tmp[100],tmpboss[100];
    int cnt=0;
    scanf("%s",tmp);
    Name[tmp]=cnt++;
    for(int i=1;i<n;i++)
    {
        scanf("%s %s",tmp,tmpboss);
        int a,b;
        if(!Name.count(tmp)){Name[tmp]=cnt++;a=Name[tmp];}
        else a=Name[tmp];
        if(!Name.count(tmpboss)){Name[tmpboss]=cnt++;b=Name[tmpboss];}
        else b=Name[tmpboss];
        S[b].push_back(a);

    }


}

main()
{
    while(scanf("%d",&n)==1&&n)
    {
        init();
        int a = dp(0,0), b = dp(0,1);
        if(a == b)
            ff[0][0] =ff[0][1] = 1;
        if(a > b)
            printf("%d %s\n", a, (ff[0][0])?"No":"Yes");
        else
            printf("%d %s\n", b, (ff[0][1])?"No":"Yes");
    }
    return 0;
}
