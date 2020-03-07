#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;

main()
{
    int t;
    scanf("%d",&t);
    string s;
    while(t--)
    {
        cin>>s;
        int len=s.size();
        int left=0,right=0;
        int flag=1;
        for(int i=0;i<len;i++)
        {
            if(s[i]=='(')left++;
            else right++;
            if(right>left)
            {
                flag=0;
                break;
            }
        }
        //printf("%d %d\n",left,right);
        if(flag=0 || left!=right)printf("0\n");
        else printf("%d\n",left);
    }
    return 0;
}
