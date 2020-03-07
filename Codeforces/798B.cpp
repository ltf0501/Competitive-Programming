#include<bits/stdc++.h>
using namespace std;
#define INF 100000000
string s[55],t[55];
bool check[55];
string rot(string s)
{
    string t="";
    for(int i=1;i<s.size();i++)t.push_back(s[i]);
    t.push_back(s[0]);
    return t;
}
main()
{
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)cin>>s[i];
    int len=s[0].size();

    string tar=s[0];
    for(int j=0;j<len;j++)
    {
        for(int k=0;k<n;k++)if(tar==s[k])check[k]=1;
        tar=rot(tar);
    }
    bool ok=1;
    for(int i=0;i<n;i++)ok=(ok && check[i]);
    if(!ok){puts("-1");return 0;}
    int mi=INF;
    tar=s[0];
    for(int i=0;i<len;i++)
    {
        int cnt=0;
        for(int k=0;k<n;k++)
        {
            t[k]=s[k];
            while(1)
            {
                if(tar==t[k])break;
                cnt++;
                t[k]=rot(t[k]);
            }
        }
        mi=min(mi,cnt);
        tar=rot(tar);
    }
    printf("%d\n",mi);
    return 0;
}
/*
4
abcabcabc
bcabcabca
cabcabcab
cabcabcab
*/
