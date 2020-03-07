#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<set>
using namespace std;
int Sum(string s)
{
    int sum=0;
    for(int i=0;i<s.size();i++)sum+=(s[i]-'0');
    if(sum<10)return sum;
    string t;
    while(sum!=0)
    {
        int k=sum%10;
        sum/=10;
        t+=(k+'0');
    }
    return Sum(t);
}
main()
{
    int n,m;
    string s;
    set<string> v;
    scanf("%d%d",&n,&m);
    cin>>s;
    int cnt=0;
    if(Sum(s+'9')==m && Sum(s)==m)
    {
        for(int i=s.size()-1;i>=-1;i--)
        {
            string t;
            for(int j=0;j<=i;j++)t+=s[j];
            t+='0';
            for(int j=i+1;j<s.size();j++)t+=s[j];
            if(!v.count(t)){v.insert(t);cnt++;}
            string r;
            for(int j=0;j<=i;j++)r+=s[j];
            r+='9';
            for(int j=i+1;j<s.size();j++)r+=s[j];
            if(!v.count(r)){v.insert(r);cnt++;}
        }
    }
    else
    {
        int k;
        for(int i=0;i<=9;i++)
        {
            char t=i+'0';
            if(Sum(s+t)==m){k=i;break;}
        }
        for(int i=s.size()-1;i>=-1;i--)
        {
            string t;
            for(int j=0;j<=i;j++)t+=s[j];
            char r=k+'0';
            t+=r;
            for(int j=i+1;j<s.size();j++)t+=s[j];
            if(!v.count(t)){v.insert(t);cnt++;}
        }
    }
    int cnt2=0;
    //printf("%d\n",cnt);
    for(set<string>::iterator it=v.begin();it!=v.end();it++)
    {
        if(cnt2==0 || cnt2==cnt-1){cnt2++;continue;}
        cout<<*it<<endl;
        cnt2++;
    }
    return 0;
}
