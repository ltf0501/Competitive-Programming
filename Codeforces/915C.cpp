#include<bits/stdc++.h>
using namespace std;
#define ll long long
char a[20],b[20];
int cnt[10],p,q;
bool ok(int m)
{
    string s,t;
    for(int i=0;i<10;i++)
        for(int j=0;j<cnt[i];j++)s+=('0'+i);
    for(int i=m+1;i<=q;i++)t+=b[i];
    //cout<<"XD"<<s<<' '<<t<<'\n';
    return s<=t;
}
main()
{
    scanf("%s%s",a+1,b+1);
    p=strlen(a+1),q=strlen(b+1);
    for(int i=1;i<=p;i++)cnt[a[i]-'0']++;
    if(p<q)
    {
        for(int i=9;i>=0;i--)
            for(int j=0;j<cnt[i];j++)printf("%d",i);
        puts("");
        return 0;
    }
    for(int i=1;i<=q;i++)
    {
        int t=b[i]-'0';
        if(cnt[t])
        {
            cnt[t]--;
            if(!ok(i))
            {
                cnt[t]++;
                for(int j=t-1;j>=0;j--)if(cnt[j])
                {
                    printf("%d",j);
                    cnt[j]--;
                    break;
                }
                for(int j=9;j>=0;j--)for(int k=0;k<cnt[j];k++)printf("%d",j);
                return 0;
            }
            printf("%d",t);
        }
        else
        {
            for(int j=t-1;j>=0;j--)if(cnt[j])
            {
                printf("%d",j);
                cnt[j]--;
                break;
            }
            for(int j=9;j>=0;j--)for(int k=0;k<cnt[j];k++)printf("%d",j);
            return 0;
        }
    }
    return 0;
}
