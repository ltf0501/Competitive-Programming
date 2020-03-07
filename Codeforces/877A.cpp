#include<bits/stdc++.h>
using namespace std;
string s,ch[5]={"Danil","Olya","Slava","Ann","Nikita"};
main()
{
    cin>>s;
    int ans=0;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j+ch[i].size()<=s.size();j++)
        {
            bool flag=1;
            for(int k=0;k<ch[i].size();k++)
				if(ch[i][k]!=s[j+k])flag=0;
            if(flag)ans++;
        }
    }
    //printf("%d\n",ans);
    puts(ans==1 ? "YES" : "NO");
    return 0;
}

