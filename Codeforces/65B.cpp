#include<bits/stdc++.h>
using namespace std;
#define maxn 1010
string s[maxn];
int n;
main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)cin>>s[i];
    for(int i=1;i<=n;i++)
    {
        string tmp="2012";
        for(int j=0;j<4;j++)for(int k=0;k<10;k++)
        {
            string t=s[i];
            t[j]=char('0'+k);
            if(t[0]!='0' && (!i || t>=s[i-1]) && t<tmp)tmp=t;
        }
        if(tmp!="2012")s[i]=tmp;
        else return 0*puts("No solution");
    }
    for(int i=1;i<=n;i++)cout<<s[i]<<'\n';
    return 0;
}

