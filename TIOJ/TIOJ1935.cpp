#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 100010
int k,n;
int a[2*maxn];
struct P
{
    int l,r;
    bool operator < (const P& b)const
    {
        return l+r<b.l+b.r;
    }
}c[maxn];
struct M
{
    priority_queue<int> pqmx;
    priority_queue<int,vector<int>,greater<int> > pqmi;
    int cnt,m1,m2;
    void init()
    {
        while(!pqmx.empty())pqmx.pop();
        while(!pqmi.empty())pqmi.pop();
        cnt=m1=m2=0;
    }
    void update(int x)
    {
        if(!cnt)m1=x;
        else if(cnt&1)
        {
            if(x>m1)
            {
                pqmi.push(x);
                m2=pqmi.top();pqmi.pop();
            }
            else
            {
                pqmx.push(x);
                m2=m1;
                m1=pqmx.top();pqmx.pop();
            }
        }
        else
        {
            if(x<m1)
            {
                pqmx.push(x);
                pqmi.push(m2);
            }
            else if(x>m2)
            {
                pqmi.push(x);
                pqmx.push(m1);
                m1=m2;
            }
            else
            {
                pqmx.push(m1);
                pqmi.push(m2);
                m1=x;
            }
        }
        cnt++;
    }
    int query(){return m1;}
}s;
vector<ll> v[2];
main()
{
    scanf("%d%d",&k,&n);
    ll ans=0;
    if(k==1)
    {
        int num=0;
        for(int i=1;i<=n;i++)
        {
            char s[2][2];int x,y;
            scanf("%s%d%s%d",s[0],&x,s[1],&y);
            if(s[0][0]==s[1][0])ans+=abs(y-x);
            else
            {
                a[++num]=x,a[++num]=y;
                ans++;
            }
        }
        sort(a+1,a+num+1);
        for(int i=1;i<=num;i++)ans+=abs(a[(num+1)/2]-a[i]);
        printf("%lld\n",ans);
    }
    else
    {
        int num=0;
        for(int i=1;i<=n;i++)
        {
            char s[2][2];int x,y;
            scanf("%s%d%s%d",s[0],&x,s[1],&y);
            if(s[0][0]==s[1][0])ans+=abs(y-x);
            else c[++num]={x,y},ans++;
        }
        sort(c+1,c+num+1);
        s.init();
        ll cur=0;
        for(int i=1;i<=num;i++)
        {
            int pre=s.query();
            s.update(c[i].l),s.update(c[i].r);
            int m=s.query();
            if(m==pre)cur+=abs(c[i].r-c[i].l);
            else if(m>pre)cur+=(ll)(c[i].r-m)+(ll)(c[i].l-m);
            else cur+=(ll)(pre-c[i].l)+(ll)(pre-c[i].r);
            v[0].push_back(cur);
        }
        s.init();
        cur=0;
        for(int i=num;i>=1;i--)
        {
            int pre=s.query();
            s.update(c[i].l),s.update(c[i].r);
            int m=s.query();
            if(m==pre)cur+=abs(c[i].r-c[i].l);
            else if(m>pre)cur+=(ll)(c[i].r-m)+(ll)(c[i].l-m);
            else cur+=(ll)(pre-c[i].l)+(ll)(pre-c[i].r);
            v[1].push_back(cur);
        }
        ll mi=min(v[0][num-1],v[1][num-1]);
        for(int i=0;i<num-1;i++)mi=min(mi,v[0][i]+v[1][num-2-i]);
        ans+=mi;
        printf("%lld\n",ans);
    }
    return 0;
}
