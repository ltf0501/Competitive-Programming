#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int n,k;
int nxt[maxn];
main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)
    {
        int num;scanf("%d",&num);
        int tmp;scanf("%d",&tmp);
        for(int j=1;j<num;j++)
        {
            int x;scanf("%d",&x);
            nxt[tmp]=x;
            tmp=x;
        }
    }
    int l=1;
    for(int i=1;i<n;i++)
    {
        if(nxt[i]!=i+1)break;
        l++;
    }
    printf("%d\n",2*n-k-2*l+1);
    return 0;
}
