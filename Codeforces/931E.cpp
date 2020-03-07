#include<bits/stdc++.h>
using namespace std;
#define maxn 5010
char c[maxn];
int cnt[1010];
int num[26];
main()
{
    scanf("%s",c);
    int n=strlen(c);
    for(int i=1;i<n;i++)
    {
        memset(cnt,0,sizeof(cnt));
        for(int j=0;j<n;j++)
        {
            int k=(c[j]-'a')*26+(c[(i+j)%n]-'a');
            cnt[k]++;
        }
        for(int j=0;j<26;j++)
        {
            int cc=0;
            for(int k=0;k<26;k++)
                if(cnt[26*j+k]==1)cc++;
            num[j]=max(num[j],cc);
        }
    }
    int ans=0;
    for(int i=0;i<26;i++)ans+=num[i];
    double ret=(double)ans/(double)n;
    printf("%.10f\n",ret);
    return 0;
}
