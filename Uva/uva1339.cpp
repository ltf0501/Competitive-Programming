#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s1[105],s2[105];
main()
{
    while(scanf("%s%s",s1,s2)==2)
    {
        int len=strlen(s1);
        int cnt1[30]={0},cnt2[30]={0};
        for(int i=0;i<len;i++)
        {
            cnt1[s1[i]-'A']++;
            cnt2[s2[i]-'A']++;
        }
        sort(cnt1,cnt1+26);
        sort(cnt2,cnt2+26);
        int flag=1;
        for(int i=0;i<26;i++)
        {
            if(cnt1[i]!=cnt2[i])
            {
                flag=0;
                break;
            }
        }
        if(flag)puts("YES");
        else puts("NO");
    }
    return 0;
}
