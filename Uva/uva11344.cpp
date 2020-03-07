#include<bits/stdc++.h>
using namespace std;
int a[15];
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        string s;cin>>s;
        int n;scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        int len=s.size();
        bool flag=1;
        for(int i=0;i<n;i++)
        {
            int rem=0;
            for(int j=0;j<len;j++)
            rem=(rem*10+(s[j]&15))%a[i];
            if(rem){flag=0;break;}
        }
        if(flag)cout<<s<<" - "<<"Wonderful."<<endl;
        else cout<<s<<" - "<<"Simple."<<endl;
    }
    return 0;
}
