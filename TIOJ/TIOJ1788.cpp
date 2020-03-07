#include<bits/stdc++.h>
using namespace std;
#define maxn 500010
#define ll long long
char c[maxn];
int l[maxn],r[maxn];
struct P
{
    ll val;
    int id;
    bool operator < (const P& b)const{return val>b.val;}
};
priority_queue<P> pq;
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%s",c);
        while(!pq.empty())pq.pop();
        int n=strlen(c);
        int l=0,r=0;
        bool flag=1;
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            if(c[i]=='(')l++;
            else if(c[i]==')')r++;
            else
            {
                ll x,y;scanf("%lld%lld",&x,&y);
                pq.push({x-y,i});
                sum+=y;
                r++;
            }
            if(l<r)
            {
                if(pq.empty())flag=0;
                else
                {
                    int id=pq.top().id;
                    sum+=pq.top().val;
                    l++,r--;
                    pq.pop();
                }
            }
        }
        if(l!=r || !flag)puts("QAQ");
        else printf("%lld\n",sum);
    }
    return 0;
}

