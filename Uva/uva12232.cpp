#include<bits/stdc++.h>
using namespace std;
#define maxn 20010
int p[maxn],d[maxn];
int n,Q,cas=0;
int finds(int x)
{
    if(p[x]==x)return x;
    int tmp=p[x];
    p[x]=finds(p[x]);
    d[x]^=d[tmp];
    return p[x];
}
main()
{
    while(~scanf("%d%d",&n,&Q) && n+Q)
    {
        for(int i=0;i<=n;i++)p[i]=i;
        memset(d,0,sizeof(d));
        char c[5];
        int cnt=0;
        bool flag=0;
        printf("Case %d:\n",++cas);
        while(Q--)
        {
            scanf("%s ",c);
            if(c[0]=='I')
            {
                cnt++;
                char s[200];
                cin.getline(s,200);
                int a,b,v=-1;
                sscanf(s,"%d%d%d",&a,&b,&v);
                a++;
                if(v==-1)v=b,b=0;
                else b++;
                int fa=finds(a),fb=finds(b);
                if(!fa)swap(a,b);
                if(fa!=fb)
                {
                    p[fa]=fb;
                    d[fa]=d[a]^d[b]^v;
                }
                else
                {
                    if(d[a]^d[b]!=v)
                    {
                        printf("The first %d facts are conflicting.\n",cnt);
                        flag=1;
                    }
                }
            }
            else
            {
                int num;scanf("%d",&num);
                int r[20];
                for(int i=0;i<num;i++)
                    scanf("%d",&r[i]),r[i]++;
                if(flag)continue;
                bool vis[20],out=0;
                memset(vis,false,sizeof(vis));
                for(int i=0;i<num;i++)
                {
                    int root=finds(r[i]),ct=1;
                    if(!root || vis[i])continue;

                    for(int j=i+1;j<num;j++)
                    {
                        if(finds(r[j])==root)
                            ct++,vis[j]=1;
                    }

                    if(ct&1){puts("I don't know.");out=1;break;}
                }
                if(!out)
                {
                    int ret=0;
                    for(int i=0;i<num;i++)ret^=d[r[i]];
                    printf("%d\n",ret);
                }
            }
        }
        puts("");
    }
    return 0;
}
