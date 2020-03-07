#include<bits/stdc++.h>
using namespace std;
const int maxn=500001,maxm=200001;
#define pii pair<int,int>
#define F first
#define S second
pii d[maxn];
int s[maxm],a[maxn],dp[maxm];
int n,m;
struct node
{
    node *lc,*rc;
    int sz;
    node()
    {
        sz=0;
        lc=rc=NULL;
    }
    node *build(int l,int r)
    {
        node *u=new node();
        if(l==r)return u;
        int m=(l+r)>>1;
        u->lc=build(l,m);
        u->rc=build(m+1,r);
        return u;
    }
    /*
    void print()
    {
        printf("%d ",sz);
        if(lc)lc->print();
        if(rc)rc->print();
    }
    */
    int query(int l,int r,int x)
    {
        if(x<=l)return sz;
        if(x>r)return 0;
        int m=(l+r)>>1;
        return lc->query(l,m,x)+rc->query(m+1,r,x);
    }
    node *insrt(int l,int r,int *a,int s)
    {
        node *u=new node(*this);
        u->sz+=s;
        if(l<r)
        {
            int m=(l+r)>>1;
            int t=upper_bound(a,a+s,m)-a;
            if(t)u->lc=lc->insrt(l,m,a,t);
            if(t<s)u->rc=rc->insrt(m+1,r,a+t,s-t);
        }
        return u;
    }
}*root[maxn];
int query(node *a,node *b,int x)
{
    return b->query(1,n,x)-a->query(1,n,x);
}
int query2(node *a,node *b,int x)
{
    int l=1,r=n;
    if(b->sz-a->sz<x)return 0;
    while(l<r)
    {
        int m=(l+r)>>1;
        //printf("%d %d %d\n",b->rc->sz,a->rc->sz,x);
        if(b->rc->sz-a->rc->sz<=x)
        {
            x-=b->rc->sz-a->rc->sz;
            r=m;
            a=a->lc,b=b->lc;
        }
        else
        {
            l=m+1;
            a=a->rc,b=b->rc;
        }
    }
    return l+1;
}
struct P
{
    list<int> best;
    vector<list<int>::iterator> v;
    priority_queue<pii,vector<pii>,greater<pii> > dead;
    P()
    {
        best.push_back(0),v.push_back(best.begin());
    }
    void clean()
    {
        best.clear(),v.clear();
        while(!dead.empty())dead.pop();
    }
    void update(int x)
    {
        while(!dead.empty() && dead.top().F<=x)
        {
            int tmp=dead.top().S;
            dead.pop();
            if(v[tmp]!=best.end())
            {
                if(next(v[tmp])!=best.end())
                {
                    int pre=*prev(v[tmp]),nx=*next(v[tmp]);
                    dead.push(pii(query2(root[s[pre]],root[s[nx]],dp[nx]-dp[pre]),nx));
                }
                best.erase(v[tmp]);
                v[tmp]=best.end();
            }
        }
    }
    void push()
    {
        int now=v.size(),pre=best.back();
        int t=query2(root[s[pre]],root[s[now]],dp[now]-dp[pre]);
        //printf("%d %d %d\n",pre,now,t);
        best.push_back(now);
        v.push_back(prev(best.end()));
        dead.push(pii(t,now));
    }
};
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        root[0]=root[0]->build(1,n);
        //root[0]->print();puts("");
        for(int i=0;i<n;i++)scanf("%d%d",&d[i].F,&d[i].S);
        sort(d,d+n);
        int l=0,cnt=0;
        for(int i=0;i<n;i++)
        {
            root[i+1]=root[i];
            while(l<n && d[l].F<=i+1)a[cnt++]=d[l].S,l++;
            if(cnt)
            {
                root[i+1]=root[i+1]->insrt(1,n,a,cnt);
                cnt=0;
            }
        }
        /*
        for(int i=0;i<=n;i++)
        {
            printf("%d:\n",i);
            root[i]->print();
            puts("");
        }
        */
        int q;scanf("%d",&q);
        while(q--)
        {
            scanf("%d",&m);
            for(int i=1;i<=m;i++)scanf("%d",&s[i]);
            sort(s+1,s+m+1);
            dp[0]=0;
            P ans;
            bool flag=1;
            for(int i=0;i<m;i++)
            {
                ans.update(s[i+1]);
                dp[i+1]=dp[ans.best.back()]+query(root[s[ans.best.back()]],root[s[i+1]],s[i+1])-s[i+1];
                if(dp[i+1]<0){flag=0;}
                //printf("%d: %d\n",i+1,dp[i+1]);
                ans.push();
            }
            printf("%d\n",flag);
            ans.clean();
        }
    }
    return 0;
}
/*
1
4
1 2
2 3
2 3
2 4
2
2 1 3
2 1 1
*/
