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
    for(int i=0;i<(int)ET[u].size();i++)if(!VIS[ET[u][i]])Dfs(ET[u][i]);//����l�`�I�ۦ�
    int sum=0;
    for(int i=0;i<(int)ET[u].size();i++)if(ANS[ET[u][i]]!=-1)CNT[ANS[ET[u][i]]]++,sum++;
    int &ans=ANS[u]=0;
    while(CNT[ans]>0&&sum-->0)ans++;//�M�wu�۬ƻ��C��A����sum�O�S�Ϊ��A�u�O���A���D�j��̦h����o��h�^
    for(int i=0;i<(int)ET[u].size();i++)if(ANS[ET[u][i]]!=-1)CNT[ANS[ET[u][i]]]--;//��CNT�٭�
}
int main()
{
//    freopen("in.txt","r",stdin);
    while(scanf("%d%d",&N,&M)==2)
    {
        for(int i=0;i<N;i++)ET[i].clear();
        for(int i=0,a,b;i<M;i++)scanf("%d%d",&a,&b),a--,b--,ET[a].push_back(b),ET[b].push_back(a);//�o��u���عϡA�e���Y���@��aXD
        K=0;
        for(int i=0;i<N;i++)if((int)ET[i].size()>K)K=(int)ET[i].size();
        if(K%2==0)K++;//��XK
        for(int i=0;i<=K;i++)CNT[i]=0;
        int mn=INF,source=-1;
        for(int i=0;i<N;i++)if((int)ET[i].size()<mn)mn=(int)ET[i].size(),source=i;//��X�׼Ƴ̤֪��I�A�O�ҫ׼�<K
        for(int i=0;i<N;i++)VIS[i]=false,ANS[i]=-1;
        Dfs(source);
        static int kase=0;
        if(kase++)puts("");
        printf("%d\n",K);
        for(int i=0;i<N;i++)printf("%d\n",ANS[i]+1);
    }
    return 0;
}
