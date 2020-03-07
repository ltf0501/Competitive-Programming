#include<bits/stdc++.h>
using namespace std;
#define maxn 500010
int n,m,k;
string s,t;
int f[maxn];
int pre[maxn],suf[maxn],tmp[maxn];
void kmp()
{
    f[0]=f[1]=0;
    for(int i=1;i<m;i++)
    {
        int j=f[i];
        while(j && t[i]!=t[j])j=f[j];
        f[i+1]=(t[i]==t[j]) ? j+1 : 0;
    }
    int j=0;
    for(int i=0;i<n;i++)
    {
        while(j && t[j]!=s[i])j=f[j];
        if(t[j]==s[i])j++;
        tmp[i]=j;
    }
}
main()
{
    scanf("%d%d%d",&n,&m,&k);
    cin>>s>>t;
    kmp();
    for(int i=0;i<n;i++)pre[i]=tmp[i];
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    kmp();
    for(int i=n-1;i>=0;i--)suf[i]=tmp[i];

    puts("NO");
    return 0;
}
