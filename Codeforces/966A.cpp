#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
#define ALL(v) v.begin(),v.end()
vector<int> v1,v2;
int n,m,a,b,v;
int flo(int x,int y)
{
    if(x%y==0)return x/y;
    return x/y+1;
}
main()
{
    scanf("%d%d%d%d%d",&n,&m,&a,&b,&v);
    for(int i=1;i<=a;i++)
    {
        int x;scanf("%d",&x);
        v1.push_back(x);
    }
    for(int i=1;i<=b;i++)
    {
        int x;scanf("%d",&x);
        v2.push_back(x);
    }
    sort(ALL(v1)),sort(ALL(v2));
    int q;scanf("%d",&q);
    while(q--)
    {
        int x1,y1,x2,y2;scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        if(y1>y2)swap(y1,y2);
        int k=abs(x2-x1);
        if(!k){printf("%d\n",abs(y2-y1));continue;}
        int ans=(int)1e9;
        if(a)
        {
            int s1=lower_bound(ALL(v1),y1)-v1.begin();
            if(s1<a)ans=min(ans,abs(v1[s1]-y1)+abs(v1[s1]-y2)+abs(x1-x2));
            s1--;
            if(s1>=0)ans=min(ans,abs(v1[s1]-y1)+abs(v1[s1]-y2)+abs(x1-x2));
        }
        if(b)
        {
            int s1=lower_bound(ALL(v2),y1)-v2.begin();
            if(s1<b)ans=min(ans,abs(v2[s1]-y1)+abs(v2[s1]-y2)+flo(abs(x1-x2),v));
            s1--;
            if(s1>=0)ans=min(ans,abs(v2[s1]-y1)+abs(v2[s1]-y2)+flo(abs(x1-x2),v));
        }
        //printf("%d %d %d\n",v1[s1],v1[s2],ans);
        //("%d %d\n",v2[s1],v2[s2]);
        printf("%d\n",ans);
    }
    return 0;
}
