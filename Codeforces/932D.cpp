#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 400010
int anc[20][maxn];
ll sum[20][maxn],w[maxn];
main()
{
    int q;scanf("%d",&q);
    ll ans=0;
    int cnt=1;
    while(q--)
    {
        int type;
        ll x,y;scanf("%d%lld%lld",&type,&x,&y);
        x^=ans,y^=ans;
        //printf("%lld %lld\n",x,y);
        if(type==1)
        {
            cnt++;w[cnt]=y,sum[0][cnt]=y;
            if(w[x]>=y)anc[0][cnt]=x;
            else
            {
                int now=x;
                while(now && w[now]<y)now=anc[0][now];
                anc[0][cnt]=now;
                /*
                for(int i=20;i>=0;i--)
                    if(w[anc[i][now]]<y)now=anc[i][now];
                anc[0][cnt]=anc[0][now];
                */
            }
            for(int i=1;i<=19;i++)
            {
                anc[i][cnt]=anc[i-1][anc[i-1][cnt]];
                sum[i][cnt]=sum[i-1][cnt]+sum[i-1][anc[i-1][cnt]];
            }
        }
        else
        {
            ll tmp=0;
            for(int i=19;i>=0;i--)if(anc[i][x] && sum[i][x]<=y)
            {
                //printf("%d %d %lld %lld\n",i,anc[i][x],sum[i][x],y);
                tmp+=(1<<i);
                y-=sum[i][x];
                x=anc[i][x];
            }
            if(x && w[x]<=y)tmp++;
            ans=tmp;
            printf("%lld\n",ans);
        }
        //puts("");
    }
    return 0;
}
/*
7
1 1 3
1 2 3
2 3 4
1 2 0
1 5 3
2 5 5
2 7 22
*/
/*
7
1 1 3
1 3

1 2 3
2 3

2 3 4
3 4
0 2 3 4
1

1 2 0
3 1

1 5 3
4 2

2 5 5
4 4
1 2 4 4
2

2 7 22
5 20
1 3 3 20
0 2 3 17
4
*/
