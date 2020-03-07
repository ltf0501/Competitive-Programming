#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,int> m;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    m[0]=1;
    ll s=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        ll x;
        scanf("%I64d",&x);
        s+=x;
        if(k==1)
        {
            if(m.count(s-1))ans+=m[s-1];
            //printf("%I64d\n",ans);
        }

        else if(k==-1)
        {
            if(m.count(s-1))ans+=m[s-1];
            if(m.count(s+1))ans+=m[s+1];
            //printf("%I64d\n",ans);
        }
        else
        {
            ll t=1;
            while(t<=2*1e14)
            {
                if(m.count(s-t))ans+=m[s-t];
                t*=k;
            }
            //printf("%I64d\n",ans);
        }
        if(!m.count(s)) m[s]=0;
        m[s]++;
    }
    printf("%I64d\n",ans);
    return 0;
}

