#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
#define LL long long
#define maxn 200000+10000
int fro[maxn],nex[maxn];
vector<int> v;
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,m,s;
        scanf("%d%d%d",&n,&m,&s);
        v.clear();
        LL sum=0;
        memset(nex,0,sizeof(nex));memset(fro,0,sizeof(fro));
        while(m--)
        {
            int k,a,b,c;
            scanf("%d%d%d%d",&k,&a,&b,&c);
            if(k==1)
            {
                if(c==1)
                {
                    int p=fro[b];
                    nex[a]=b;
                    if(p)nex[p]=a;
                    fro[a]=p;
                    fro[b]=a;
                }
                if(c==2)
                {
                    int p=nex[b];
                    fro[a]=b;
                    if(p)fro[p]=a;
                    nex[a]=p;
                    nex[b]=a;
                }
            }
            if(k==2)
            {
                int p=fro[c],u=fro[a],v=nex[b];
                if(u)nex[u]=v;
                if(v)fro[v]=u;
                if(p)nex[p]=a;
                fro[a]=p;
                nex[b]=c;
                fro[c]=b;
            }
            if(k==3)
            {
                if(c==1)
                {
                    int p=nex[a];
                    v.push_back(a);
                    b--;
                    while(fro[a] && b)
                    {
                        a=fro[a];
                        b--;
                        v.push_back(a);
                    }
                    fro[p]=fro[a];
                    if(fro[a])nex[fro[a]]=p;
                    sum+=b;
                }
                if(c==2)
                {
                    int p=fro[a];
                    v.push_back(a);
                    b--;
                    while(nex[a] && b)
                    {
                        a=nex[a];
                        b--;
                        v.push_back(a);
                    }
                    nex[p]=nex[a];
                    if(nex[a])fro[nex[a]]=p;
                    sum+=b;
                }
            }
        }
        printf("%lld\n",sum);
        for(int i=0;i<v.size();i++)printf("%d\n",v[i]);
    }
    return 0;
}
