#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
#define maxn 2000+5
int A[maxn][maxn];
int n;
int query(int L,int R,int T,int B)
{
    int ret=-1;
    map<int,int> cnt;
    for(int i=L;i<=R;i++)
        for(int j=T;j<=B;j++)cnt[A[i][j]]++;


}
main()
{
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)scaf("%d",&A{[i][j]);
        int q;scanf("%d",&q);
        while(q--)
        {

        }
    }
    return 0;
}

