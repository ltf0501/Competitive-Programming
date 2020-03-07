#include<cstdio>
#include<algorithm>
using namespace std;
int a[101];
main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        int q;scanf("%d",&q);
        while(q--)
        {
            int x,y;scanf("%d%d",&x,&y);
            swap(a[x],a[y]);
        }
        for(int i=0;i<n;i++)printf("%d ",a[i]);
        puts("");
    }
    return 0;
}
