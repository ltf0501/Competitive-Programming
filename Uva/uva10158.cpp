#include<bits/stdc++.h>
using namespace std;
#define maxn 20000+5
int p[maxn],sz[maxn];
int finds(int x)
{
    return p[x]==x ? x : p[x]=finds(p[x]);
}
void Union(int x,int y)
{
    x=finds(x),y=finds(y);
    if(x!=y)
    {
        if(sz[x]<sz[y])p[x]=y,sz[y]+=sz[x];
        else p[y]=x,sz[x]+=sz[y];
    }
}
main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int c,x,y;
        for(int i=0;i<2*n;i++)
            p[i]=i,sz[i]=1;
        while(~scanf("%d%d%d",&c,&x,&y) && c+x+y)
        {
            if(c==1)
            {
                if(finds(x)==finds(y+n) || finds(x+n)==finds(y)){puts("-1");continue;}
                Union(x,y),Union(x+n,y+n);
            }
            else if(c==2)
            {
                if(finds(x)==finds(y) || finds(x+n)==finds(y+n)){puts("-1");continue;}
                Union(x,y+n),Union(x+n,y);
            }
            else if(c==3)
            {
                if(finds(x)==finds(y) || finds(x+n)==finds(y+n))puts("1");
                else puts("0");
            }
            else
            {
                if(finds(x)==finds(y+n) || finds(x+n)==finds(y))puts("1");
                else puts("0");
            }
        }
    }


    return 0;
}
