#include<bits/stdc++.h>
using namespace std;
#define maxn 20000+5
struct node
{
    int x,type;
    bool operator < (const node& b)const
    {
        return x<b.x || (x==b.x && type<b.type);
    }
}a[maxn];
main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            a[2*i]=(node){l,1},a[2*i+1]=(node){r,-1};
        }
        int ans=0,cnt=0;
        sort(a,a+2*n);
        for(int i=0;i<2*n;i++)
        {
            if(i && cnt>0)ans+=a[i].x-a[i-1].x;
            cnt+=a[i].type;
        }
        printf("%d\n",ans);
    }
    return 0;
}
