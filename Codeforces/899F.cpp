#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
char s[maxn];
set<int> v[65];
int get_id(char c)
{
    if('0'<=c && c<='9')return c-'0';
    if('a'<=c && c<='z')return c-'a'+10;
    if('A'<=c && c<='Z')return c-'A'+36;
}
int n,m;
int bit[maxn];
void add(int x,int d)
{
    for(int i=x;i<=n;i+=i&-i)bit[i]+=d;
}
int query(int x)
{
    int ret=0;
    for(int i=x;i;i-=i&-i)ret+=bit[i];
    return ret;
}
int binary(int x)
{
    int l=1,r=n;
    while(r>l)
    {
        int m=(l+r)>>1;
        if(query(m)>=x)r=m;
        else l=m+1;
    }
    return l;
}
main()
{
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)v[get_id(s[i])].insert(i);
    for(int i=1;i<=n;i++)bit[i]=i;
    for(int i=n;i>=1;i--)bit[i]-=bit[i-(i&-i)];
    while(m--)
    {
        int l,r;char c[2];
        scanf("%d%d%s",&l,&r,c);
        int ii=get_id(c[0]);
        l=binary(l),r=binary(r);
        auto x=v[ii].lower_bound(l);
        auto y=v[ii].upper_bound(r);
        for(auto it=x;it!=y;it++)
        {
            s[*it]='!';
            add(*it,-1);
        }
        v[ii].erase(x,y);

    }
    for(int i=1;i<=n;i++)
        if(s[i]!='!')printf("%c",s[i]);
    puts("");
    return 0;
}
