#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 1000000
int s[maxn];
int mi[maxn],mx[maxn];
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);

        for(int i=1;i<=n;i++)scanf("%d",&s[i]);
        mx[1]=s[1];
        for(int i=2;i<=n;i++)mx[i]=max(mx[i-1],s[i]);
        mi[n]=s[n];
        for(int i=n-1;i>=1;i--)mi[i]=min(mi[i+1],s[i]);

        int cnt=0;
        for(int i=2;i<=n-1;i++)
            if(s[i]>mx[i-1] && s[i]<mi[i+1])cnt++;

        printf("%d\n",cnt);
    }
    return 0;
}
