#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int m,k;
int r[maxn];
int t[maxn],x[maxn];
main()
{
    scanf("%d%d",&m,&k);
    for(int i=1;i<=k;i++)scanf("%d",&r[i]);
    int q;scanf("%d",&q);
    for(int i=1;i<=q;i++)scanf("%d%d",&t[i],&x[i]);
    bool flag=1;//0 A¤W,1 A¤U
    int a=0,b=0,c=m;
    r[k+1]=t;
    int cur=1;
    for(int i=1;i<=k+1;i++)
    {
        flag^=1;
        while(cur<=q && (i==k+1 || t[cur]<=r[i]))
        {
            int tmp=t[cur]-t[cur-1];
            if(!flag)
            {
                c=max(c-tmp,0);
                b=max(b-tmp,0);
                a=min(a+(tmp-b),m);
            }
            else
            {
                a=min(a+tmp,m);
                b=min(b+tmp,m);
                c=max(c-(tmp-b),0);
            }
        }
        if(t>r[i])break;
        flag^=1;
        int tmp=r[i]-r[i-1];

    }
    int ans;
    printf("%d %d %d\n",a,b,c);
    if(0<=x && x<=a)ans=a+c;
    else if(a<x && x<b)ans=x+c;
    else ans=b+c;
    printf("%d\n",ans);

    return 0;
}
/*
7 5
2 4 6 7 10
5
2 3
3 4
8 1
*/
