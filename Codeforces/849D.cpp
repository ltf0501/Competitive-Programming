#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
struct P
{
    int g,p,t,id,c;
    void input(int i)
    {
        scanf("%d%d%d",&g,&p,&t);
        id=i;c=p-t;
    }
    bool operator < (const P& b)const
    {
        if(c!=b.c)return c<b.c;
        if(g!=b.g)return g<b.g;
        if(g==1)return p<b.p;
        return p>b.p;
    }
}a[maxn];
struct Q{int g,p;}b[maxn];
int n,w,h;
int id[maxn];
vector<int> v;
main()
{
    scanf("%d%d%d",&n,&w,&h);
    for(int i=1;i<=n;i++)a[i].input(i),b[i]=(Q){a[i].g,a[i].p};
    sort(a+1,a+n+1);
    int cnt[3]={0};
    v.push_back(a[1].id);
    cnt[a[1].g]++;
    for(int i=2;i<=n+1;i++)
    {
        if(i==n+1 || a[i-1].c!=a[i].c)
        {
            ///id[v[0]]:=v[cnt],...;
            int sz=v.size();
            if(!(cnt[1] && cnt[2]))for(int j=0;j<sz;j++)id[v[j]]=v[j];
            else for(int j=0;j<sz;j++)id[v[j]]=v[(j+cnt[2])%sz];
            cnt[1]=cnt[2]=0;v.clear();v.resize(0);
        }
        cnt[a[i].g]++;
        v.push_back(a[i].id);
    }
    for(int i=1;i<=n;i++)
    {
        int ii=id[i];
        if(b[ii].g==1)printf("%d %d\n",b[ii].p,h);
        else printf("%d %d\n",w,b[ii].p);
    }
    return 0;
}
