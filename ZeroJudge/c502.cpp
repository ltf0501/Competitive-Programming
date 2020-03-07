#include<bits/stdc++.h>
using namespace std;
#define maxn 105
string s;
int n;
int f[maxn];
main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    while(cin>>n>>s)
    {
        int m=s.size();
        f[0]=-1;
        for(int i=1,k=-1;i<m;i++)
        {
            while(k>=0 && s[k+1]!=s[i])k=f[k];
            if(s[k+1]==s[i])k++;
            f[i]=k;
        }
        int ans=0;
        while(n--)
        {
            string t;cin>>t;
            int l=t.size();
            for(int i=0,j=-1;i<l;i++)
            {
                while(j>=0 && s[j+1]!=t[i])j=f[j];
                if(s[j+1]==t[i])j++;
                if(j==m-1)ans++,j=f[j];
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
