#include<bits/stdc++.h>
using namespace std;
#define maxn 100010
int n;
char c[maxn];
int num[maxn];
main()
{
    scanf("%d",&n);
    scanf("%s",c);
    int len=strlen(c);
    int sum=0;
    for(int i=0;i<len;i++)num[i]=c[i]-'0',sum+=num[i];
    sort(num,num+len);
    int cnt=0;
    for(int i=0;i<len,sum<n;i++)
    {
        sum+=(9-num[i]);
        cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}
