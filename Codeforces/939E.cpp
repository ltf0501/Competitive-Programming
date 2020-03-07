#include<bits/stdc++.h>
using namespace std;
#define maxn 500010
#define ll long long
ll s[maxn];
double ans=0.0;
main()
{
    int q;scanf("%d",&q);
    int n=0;
    int cur=1;
    while(q--)
    {
        int type;scanf("%d",&type);
        if(type==1)
        {
            int x;scanf("%d",&x);
            n++;
            s[n]=s[n-1]+x;
            //printf("cur=%d\n",cur);
            while(cur<n-1 && x>(cur+1)*s[cur+1]-(cur+2)*s[cur])cur++;
            //printf("%d %lld\n",x,(cur+1)*s[cur+1]-(cur+2)*s[cur]);
            ans=max(ans,x-((s[cur]+x)*1.0)/((cur+1)*1.0));
        }
        else printf("%.10f\n",ans);
    }
    return 0;
}
