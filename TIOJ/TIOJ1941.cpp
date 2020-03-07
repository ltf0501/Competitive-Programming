#include<bits/stdc++.h>
using namespace std;
#define maxn 800010
int c[maxn],n;
void add(int x,int d)
{
    for(int i=x;i<=n;i+=i&-i)
        c[i]+=d;
}
int query(int x)
{
    int ret=0;
    for(int i=x;i;i-=i&-i)
        ret+=c[i];
    return ret;
}
set<int> s;
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int l,r;scanf("%d%d",&l,&r);
        l++,r++;
        add(l,1);add(r+1,-1);
        s.insert(l-1);
        int a=query(r),b=query(r+1);
        if(r<n && a==b)s.erase(r);
        else if(r<n && a>b)
        {
            auto it=s.lower_bound(r);
            int k;
            if(it==s.end())k=n;
            else k=*it;
            add(r+1,1);add(k+1,-1);
            if(k<n && query(k)==query(k+1))s.erase(k);
        }
        //printf("%d\n",query(n));
    }
    printf("%d\n",query(n));
    return 0;
}
