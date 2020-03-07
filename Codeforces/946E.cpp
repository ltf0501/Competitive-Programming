#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
char c[maxn];
int s[maxn];
main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        scanf("%s",c);
        int n=strlen(c);
        for(int i=0;i<n;i++)s[i]=0;
        bool ok=0;
        if(c[0]!='1' || c[n-1]>'1')ok=1;
        for(int i=1;i<n-1;i++)if(c[i]!='0'){ok=1;break;}
        for(int i=0;i<n;i++)s[i]=(c[i]=='0');
        for(int i=1;i<n;i++)s[i]+=s[i-1];
        if(!ok)
        {
            for(int i=0;i<n-2;i++)putchar('9');
            puts("");continue;
        }
        bool num[10]={};
        int cnt=0,pos=-1;
        for(int i=0;i<n;i++)
        {
            num[c[i]-'0']^=1;
            cnt+=((num[c[i]-'0']&1) ? 1 : -1);
            if(n-i-1<cnt)
            {
                num[c[i]-'0']^=1;
                cnt+=((num[c[i]-'0']&1) ? 1 : -1);
                pos=i;break;
            }
            if(s[n-cnt-1]-s[i]<n-cnt-1-i)continue;
            vector<int> v;
            for(int j=0;j<10;j++)if(num[j]&1)v.push_back(j);
            bool flag=0;
            for(int j=0;j<cnt;j++)
            {
                if(v[j]<c[n-cnt+j]-'0'){flag=1;break;}
                if(v[j]>c[n-cnt+j]-'0')break;
            }
            if(flag)continue;
            else
            {
                num[c[i]-'0']^=1;
                cnt+=((num[c[i]-'0']&1) ? 1 : -1);
                pos=i;break;
            }
        }
        //printf("%d\n",pos);
        if(pos>=0)
        {
            //for(int i=0;i<10;i++)printf("%d ",num[i]);puts("");
            for(int i=0;i<pos;i++)printf("%c",c[i]);
            for(int i=c[pos]-'0'-1;i>=0;i--)
            {
                num[i]^=1;
                cnt+=((num[i]&1) ? 1 : -1);
                if(n-pos-1>=cnt)
                {
                    putchar(i+'0');
                    for(int j=pos+1;j<n-cnt;j++)putchar('9');
                    for(int j=9;j>=0;j--)if(num[j]&1)putchar(j+'0');
                    puts("");break;
                }
                num[i]^=1;
                cnt+=((num[i]&1) ? 1 : -1);
            }
        }
    }
    return 0;
}
/*
6298760
639876320
818181618463
18446
1845654
*/
