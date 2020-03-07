#include<bits/stdc++.h>
using namespace std;
main()
{
    int n;
    char c;
    stack<char> s;
    while(scanf("%d",&n)!=EOF)
    {
        getchar();
        getchar();
        for(int i=0;i<n;i++)
        {
            if(i)puts("");
            while(scanf("%c",&c)!=EOF && c!='\n')
            {
                getchar();
                if(isdigit(c))printf("%c",c);
                else if(c=='(')s.push(c);
                else if(c=='*' || c=='/')
                {
                    while(!s.empty() && (s.top() == '*' || s.top() == '/') )
                    {
                        printf("%c",s.top());
                        s.pop();
                    }
                    s.push(c);
                }
                else if(c=='+' || c=='-')
                {
                    while(!s.empty() &&(s.top() == '*' || s.top() == '/' || s.top() == '+' || s.top() == '-' ))
                    {
                        printf("%c",s.top());
                        s.pop();
                    }
                    s.push(c);
                }
                else if(c==')')
                {
                    while(s.top()!='(')
                    {
                        printf("%c",s.top());
                        s.pop();
                    }
                    s.pop();
                }
            }
            while(!s.empty())
            {
                printf("%c",s.top());
                s.pop();
            }
            puts("");
        }
    }
    return 0;
}
