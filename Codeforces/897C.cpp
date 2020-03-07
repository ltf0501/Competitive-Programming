#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
string s="What are you doing at the end of the world? Are you busy? Will you save us?";
string t1="What are you doing while sending \"";
string t2="\"? Are you busy? Will you send \"";
string t3="\"?";
long long a[55];
void pre()
{
    a[0]=s.size();
    for(int i=1;i<=53;i++)a[i]=2*a[i-1]+t1.size()+t2.size()+t3.size();
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    pre();
    int q;cin>>q;
    while(q--)
    {
        int n;long long k;cin>>n>>k;
        if(n<=53 && a[n]<k){cout<<".";continue;}
        bool flag=0;
        while(n>53)
        {
            if(k<=t1.size()){cout<<t1[k-1];flag=1;break;}
            else n--,k-=t1.size();
        }
        if(flag)continue;
        while(n)
        {
            if(k<=t1.size()){cout<<t1[k-1];break;}
            else if(k<=t1.size()+a[n-1])k-=t1.size(),n--;
            else if(k<=t1.size()+a[n-1]+t2.size()){cout<<t2[k-(t1.size()+a[n-1])-1];break;}
            else if(k<=t1.size()+a[n-1]+t2.size()+a[n-1])k-=t1.size()+a[n-1]+t2.size(),n--;
            else {cout<<t3[k-(t1.size()+a[n-1]+t2.size()+a[n-1])-1];break;}
        }
        if(!n)cout<<s[k-1];
    }
    return 0;
}
