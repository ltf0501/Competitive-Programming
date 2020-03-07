#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<sstream>

using namespace std;
const int MAXNM=20+100+10;
const int MAXS=8+2;
const int INF=1e7;

struct Teacher
{
    int cost,canteach;
    Teacher(){}
    void get()
    {
        string s;getline(cin,s);
        stringstream ss(s);ss>>cost;
        canteach=0;
        int k;
        while(ss>>k)
        {
            k--;
            canteach|=1<<k;
        }
    }
}teacher[MAXNM];

int s,m,n;

int memo[MAXNM][1<<MAXS][1<<MAXS];
int dp(int k,int s0,int s1,int s2){
    if(k==m+n)return(s2==(1<<s)-1) ? 0 : INF;
    int &ans=memo[k][s1][s2];
    if(ans>=0)return ans;
    ans=INF;
    if(k>=m)ans=dp(k+1,s0,s1,s2);
    int ns2=(teacher[k].canteach & s1) | s2;
    int ns1=(teacher[k].canteach & s0) | s1;
    int ns0=s0-(s0 & teacher[k].canteach);
    ans=min(ans,teacher[k].cost+dp(k+1,ns0,ns1,ns2));
    return ans;
}

main()
{
    ios::sync_with_stdio(false);
    while(cin>>s>>m>>n && s)
    {
        string z;getline(cin,z);
        for(int i=0;i<m+n;i++)teacher[i].get();
        for(int i=0;i<m+n;i++)cout<<teacher[i].canteach<<" ";
        memset(memo,-1,sizeof(memo));
        cout << dp(0,(1<<s)-1,0,0) << endl;
    }
    return 0;
}

