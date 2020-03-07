#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 50;
int d1[MAXN][MAXN], d2[MAXN][MAXN];
char b1[MAXN], b2[MAXN];

main()
{
    return 0;
    int t,cnt=0;
    scanf("%d",&t);
    while(t--)
    {
        gets(b1+1);gets(b2+1);
        for(int i=0;i<MAXN;i++)
            d1[0][i]=d1[i][0]=i,
            d2[0][i]=d2[i][0]=1;
    }
}
