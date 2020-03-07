#include<bits/stdc++.h>
using namespace std;
#define maxn 500010
int p[maxn<<1],n;
int finds(int x){return p[x]==x ? x : p[x]=finds(p[x]);}
void Union(int x,int y)
{
    int u=finds(x),v=finds(y);
    if(u==v)return ;
    if(u<=v)p[v]=u;
    else p[u]=v;
}
bool friends(int x,int y)
{
    if(finds(x)==finds(y) && finds(x+n)==finds(y+n))return 1;
    return 0;
}
bool enemies(int x,int y)
{
    if(finds(x)==finds(y+n) && finds(x+n)==finds(y))return 1;
    return 0;
}
main()
{
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++)p[i]=i;
    int x,y;
    char s1[10],s2[10],s3[10];
    while(~scanf("%s %s %s %d %d",s1,s2,s3,&x,&y))
    {
        if(s1[0]=='y')
        {
            if(s3[0]=='f')
            {
                if(enemies(x,y))puts("angry");
                else Union(x,y),Union(x+n,y+n);
            }
            else
            {
                if(friends(x,y))puts("angry");
                else Union(x,y+n),Union(x+n,y);
            }
        }
        else
        {
            if(s3[0]=='f')
            {
                if(friends(x,y))puts("yeap");
                else puts("nope");
            }
            else
            {
                if(enemies(x,y))puts("yeap");
                else puts("nope");
            }
        }
    }
    return 0;
}
