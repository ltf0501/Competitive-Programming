#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
int a[maxn];
stack<int> s;
main()
{
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]%=2;
    for(int i=1;i<=n;i++)
    {
        if(s.empty() || s.top()!=a[i])
            s.push(a[i]);
        else s.pop();
    }
    puts(s.size()<=1 ? "YES" : "NO");
    return 0;
}
