#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;
int LIS(vector<int> &s,vector<int> &pos)
{
    if(s.size()==0) return 0;
    v.push_back(s[0]);
    pos[0]=0;
    for(int i=1;i<s.size();i++)
    {
        int n=s[i];
        if(n>v.back())
        {
            v.push_back(n);
            pos[i]=v.size()-1;
        }
        else
        {
            auto it=lower_bound(v.begin(), v.end(), n);
            *it=n;
            pos[i]=it-v.begin();
        }
    }
    return v.size();
}
vector<int> forprint;
void Print(int ans,int k, vector<int> &pos,vector<int> &s)
{
    if(ans<0) return;
    for(int i=k; i>=0; i--)
    {
        if(pos[i]==ans-1)
        {
            forprint.push_back(s[i]);
            Print(ans-1,i-1,pos,s);
            return;
        }
    }
}
int main()
{
    vector<int> s;
    int n;
    while(scanf("%d",&n)!=EOF) s.push_back(n);
    vector<int> pos(s.size());
    int ans=LIS(s,pos);
    cout<<ans<<endl;
    printf("-\n");
    Print(ans,s.size()-1,pos,s);
    for(int i=forprint.size()-1;i>=0;i--) cout<<forprint[i]<<endl;
    return 0;
}

