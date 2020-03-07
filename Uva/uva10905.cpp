#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
bool cmp(string a,string b)
{
    string s1=a+b,s2=b+a;
    if(s1>s2)return true;
    return false;
}
main()
{
    int n;
    string num[55];
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=0;i<n;i++)cin >> num[i];
        sort(num,num+n,cmp);
        for(int i=0;i<n;i++)cout << num[i];
        printf("\n");
    }
    return 0;
}
