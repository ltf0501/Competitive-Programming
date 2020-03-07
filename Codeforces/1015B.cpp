#include<bits/stdc++.h>
using namespace std;
char s[55],t[55];
int n;
int cnt[30];
vector<int> ans;
main()
{
    scanf("%d",&n);
    scanf("%s %s",s,t);
    for(int i=0;i<n;i++)cnt[s[i]-'a']++,cnt[t[i]-'a']--;
    for(int i=0;i<26;i++)if(cnt[i])return 0*puts("-1");
    for(int i=0;i<n;i++)
    {
        if(t[i]!=s[i])
        {
            for(int j=i;j<n;j++)
            {
                if(t[i]==s[j])
                {
                    for(int k=j-1;k>=i;k--)
                    {
                        ans.push_back(k);
                        swap(s[k],s[k+1]);
                    }
                    break;
                }
            }
        }
    }
    printf("%d\n",ans.size());
    for(int s : ans)printf("%d ",s+1);
    return 0;
}

