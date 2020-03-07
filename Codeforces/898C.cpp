#include<bits/stdc++.h>
using namespace std;
int n;
map<string,int> mp;
map<int,string> M;
vector<string> S[22];
int Cnt[22];
bool is(string s,string t)
{
    if(s.size()<t.size())return 0;
    for(int i=t.size()-1,j=s.size()-1;i>=0;i--,j--)
    {
        ///cout<<t[i]<<' '<<s[j]<<'\n';
        if(t[i]!=s[j])return 0;
    }
    return 1;
}
main()
{
    //string s="1",t="2";
    //cout<<is(t,s);
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        string s;int k;
        cin>>s>>k;
        if(mp.find(s)==mp.end())mp[s]=++cnt,M[cnt]=s;
        int now=mp[s];
        for(int i=1;i<=k;i++)
        {
            string t;cin>>t;
            bool flag=0;
            for(string r : S[now])
            {
                if(is(r,t)){/*cout<<t<<' '<<r<<'\n';*/flag=1;break;}
            }
            if(flag)continue;
            for(int i=0;i<S[now].size();i++)
            {
                string r=S[now][i];
                if(is(t,r)){/*cout<<t<<' '<<r<<'\n';*/S[now].erase(S[now].begin()+i);Cnt[now]--;}
            }

            S[now].push_back(t),Cnt[now]++;///cout<<"XD: ";
            ///for(string r : S[now])cout<<r<<' ';cout<<'\n';
        }

    }
    cout<<cnt<<'\n';
    for(int i=1;i<=cnt;i++)
    {
        cout<<M[i]<<' ';
        cout<<Cnt[i]<<' ';
        for(string r : S[i])cout<<r<<' ';
        cout<<'\n';
    }
    return 0;
}
/*
4
ivan 3 2 122 456
ivan 2 456 456
ivan 8 2 789 3 23 6 56 9 89
dasha 2 23 789
*/
