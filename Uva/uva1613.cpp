#include<cstdio>
#include<vector>
using namespace std;
const int INF=2147483647;
int N,M,K,ANS[9999],CNT[10000];
vector<int>ET[9999];
bool VIS[9999];
void Dfs(const int u)
{
    VIS[u]=true;
    for(int i=0;i<(int)ET[u].size();i++)if(!VIS[ET[u][i]])Dfs(ET[u][i]);//先把子節點著色
    int sum=0;
    for(int i=0;i<(int)ET[u].size();i++)if(ANS[ET[u][i]]!=-1)CNT[ANS[ET[u][i]]]++,sum++;
    int &ans=ANS[u]=0;
    while(CNT[ans]>0&&sum-->0)ans++;//決定u著甚麼顏色，那個sum是沒用的，只是讓你知道迴圈最多執行這麼多回
    for(int i=0;i<(int)ET[u].size();i++)if(ANS[ET[u][i]]!=-1)CNT[ANS[ET[u][i]]]--;//把CNT還原
}
int main()
{
//    freopen("in.txt","r",stdin);
    while(scanf("%d%d",&N,&M)==2)
    {
        for(int i=0;i<N;i++)ET[i].clear();
        for(int i=0,a,b;i<M;i++)scanf("%d%d",&a,&b),a--,b--,ET[a].push_back(b),ET[b].push_back(a);//這邊只有建圖，容我縮成一行吧XD
        K=0;
        for(int i=0;i<N;i++)if((int)ET[i].size()>K)K=(int)ET[i].size();
        if(K%2==0)K++;//算出K
        for(int i=0;i<=K;i++)CNT[i]=0;
        int mn=INF,source=-1;
        for(int i=0;i<N;i++)if((int)ET[i].size()<mn)mn=(int)ET[i].size(),source=i;//找出度數最少的點，保證度數<K
        for(int i=0;i<N;i++)VIS[i]=false,ANS[i]=-1;
        Dfs(source);
        static int kase=0;
        if(kase++)puts("");
        printf("%d\n",K);
        for(int i=0;i<N;i++)printf("%d\n",ANS[i]+1);
    }
    return 0;
}
