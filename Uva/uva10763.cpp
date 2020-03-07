#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

#define maxn 500000+10
int a[maxn],b[maxn];
main()
{
    int n;
    while(scanf("%d",&n)==1&&n)
    {
        for(int i=0;i<n;i++)scanf("%d %d",&a[i],&b[i]);
        sort(a,a+n);
        sort(b,b+n);
        int yes=1;
        for(int i=0;i<n;i++){if(a[i]!=b[i]){yes=0;break;}}
        printf("%s\n",yes?"YES":"NO");
    }
    return 0;
}
