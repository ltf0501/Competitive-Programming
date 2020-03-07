#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
struct node
{
    int x,type;
    bool operator < (const node& rhs)const
    {
        return x<rhs.x || (x==rhs.x && type>rhs.type);
    }
}a[maxn*2];
int b[maxn*2],c[maxn*2];
int n,k,q;
vector<int> ss;
main()
{
    scanf("%d%d%d",&n,&k,&q);
    for(int i=1;i<=n;i++)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        a[2*i-1]=(node){l,1};
        a[2*i]=(node){r+1,-1};
    }
    sort(a+1,a+2*n+1);
    //for(int i=1;i<=2*n;i++)printf("%d %d\n",a[i].x,a[i].type);
    int cnt=0;
    for(int i=1;i<=2*n;i++)
    {
        cnt+=a[i].type;
        b[i]=cnt;
        c[i]=a[i].x;
        if(b[i]>=cnt)ss.push_back(i);
    }
    while(q--)
    {
        int l,r;scanf("%d%d",&l,&r);
        int k1=upper_bound(c+1,c+2*n+1,l)-c;
        int k2=upper_bound(c+1,c+2*n+1,r)-c;
        k1--,k2--;
        //printf("%d %d\n",k1,k2);
        int ans=0;
        if(k1==k2)
        {
            if(b[k1]>=k)ans=r-l+1;
        }
        else
        {
            if(b[k1]>=k)ans+=c[k1+1]-l;
            if(b[k2]>=k)ans+=r-c[k2]+1;
            int t1=*upper_bound(ss.begin(),ss.end(),k1);
            int t2=*(--lower_bound(ss.begin(),ss.end(),k2));
            for(int i=t1;i<=t2;i++)
                ans+=(c[ss[i]+1]-c[ss[i]]);
            /*
            for(int i=k1+1;i<=k2-1;i++)
                if(b[i]>=k)ans+=(c[i+1]-c[i]);
            */
        }
        printf("%d\n",ans);
    }
    return 0;
}
