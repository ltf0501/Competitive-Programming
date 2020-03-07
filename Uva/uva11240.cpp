#include<algorithm>
#include <cstdio>
#include <cstring>
#define maxn 30000+10
using namespace std;

int A[maxn],BIT[2][maxn];  //[0] prev <, [1] prev >
void modify(int row, int idx, int val, int L) {
    while(idx <= L) {
        BIT[row][idx] = max(BIT[row][idx], val);
        idx += idx&(-idx);
    }
}

int query(int row,int idx)
{
    int ret=0;
    while(idx)
    {
        ret=max(ret,BIT[row][idx]);
        idx-=idx&(-idx);
    }
    return ret;
}
main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&A[i]);
        memset(BIT,0,sizeof(BIT));
        int ret=0;
        for(int i=0;i<n;i++)
        {
            int dp1=0,dp2=0; //< A[i], > A[i]
            dp1=query(1,A[i]-1)+1;
            dp2=query(0,n-A[i])+1;
            if(dp1==2)dp1=1;
            ret = max(ret, dp1);
            ret = max(ret, dp2);
            modify(0, n-A[i]+1, dp1, n);
            modify(1, A[i], dp2, n);
        }
        printf("%d\n",ret);
    }
    return 0;
}

