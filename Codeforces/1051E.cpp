#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define ll long long
const int mod=1e9+7;
int zl[maxn<<1],zr[maxn<<1];
string s,l,r;
ll dp[maxn],suf[maxn];
int n;
void z_function(int *z,string s)
{
    int L=0,R=0;
    int n=s.size();
    for(int i=1;i<n;i++)
    {
        if(i>R)
        {
            L=R=i;
            while(R<n && s[R-L]==s[R])R++;
            z[i]=(R--)-L;
        }
        else
        {
            int ii=i-L;
            if(i+z[ii]<R+1)z[i]=z[ii];
            else
            {
                L=i;
                while(R<n && s[R-L]==s[R])R++;
                z[i]=(R--)-L;
            }
        }
    }
}
int cmp(int *z,string t,int pos)
{
    int len=t.size();
    if(n-pos<len)return -1;
    int id=z[len+1+pos];
    if(id==len)return 0;
    if(s[pos+id]<t[id])return -1;
    return 1;
}
main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    cin>>s>>l>>r;
    z_function(zl,l+"#"+s);
    z_function(zr,r+"#"+s);
    n=s.size();
    dp[n]=suf[n]=1;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]=='0')
        {
            if(l=="0")dp[i]=dp[i+1];
            suf[i]=(dp[i]+suf[i+1])%mod;
            continue;
        }
        int L=(int)l.size()+i;
        int flag=cmp(zl,l,i);
        if(flag==-1)L++;
        int R=(int)r.size()+i;
        flag=cmp(zr,r,i);
        if(flag==1)R--;
        if(L<=R && L<=n)
        {
            R=min(R,n);
            dp[i]=(suf[L]-suf[R+1]+mod)%mod;
        }
        suf[i]=(dp[i]+suf[i+1])%mod;
    }
    cout<<dp[0]<<'\n';
    return 0;
}
