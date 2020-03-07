# include<iostream>
# include<cstdio>
# include<cstring>
# include<algorithm>
using namespace std;

int a[2000],head,tail,n,b[505];

bool ok(int id,int d)
{
    for(int i=0;i<n;++i){
        int p=(id+d*b[i]-d+n)%n;
        if(p!=i)
            return false;
    }
    return true;
}

int getAns(int id,int d)
{
    for(int i=0;i<n;++i)  b[i]=a[i];
    int res=0;
    while(!ok(id,d))
    {
        for(int i=0;i<n;++i){
            int p=(id+d*b[i]-d+n)%n;
            if(i!=p){
                ++res;
                swap(b[i],b[p]);
            }
        }
    }
    return res;
}


void solve()
{
    head=0,tail=n;
    while(a[head]!=1)
        a[tail++]=a[head++];
    for(int i=0;i<n;++i)
        a[i]=a[head++];

    int ans=100000000;
    for(int i=0;i<n;++i)
        ans=min(ans,min(getAns(i,1),getAns(i,-1)));
    printf("%d\n",ans);
}

void read()
{
    for(int i=0;i<n;++i)
        scanf("%d",a+i);
}

int main()
{

    ///freopen("UVA-10570 Meeting with Aliens.txt","r",stdin);
    while(scanf("%d",&n)&&n)
    {
        read();
        solve();
    }
    return 0;
}
