#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

#define maxn 100000+10
vector<int> sons[maxn];//maxn�����ݭ��u�C��

int n,t;
int dp(int u)//�����u����H�é��W�o�H�ֻ̤ݭn���u�H��
{
    if(sons[u].empty())return 1;
    int k=sons[u].size();
    vector<int> d;
    for(int i=0;i<k;i++)
    {
        d.push_back(dp(sons[u][i]));
    }
    sort(d.begin(),d.end());
    int re=0;
    int c=(k*t-1)/100+1;
    for(int i=0;i<c;i++)re+=d[i];
    return re;
}
main()
{
    while(scanf("%d %d",&n,&t)==2)
    {
        if(!n && !t)break;
        int p;
        for(int i=0;i<=n;i++)sons[i].clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&p);
            sons[p].push_back(i);//��i�[�JB[i]�����ݭ��u
        }
        printf("%d\n",dp(0));

    }
    return 0;
}
