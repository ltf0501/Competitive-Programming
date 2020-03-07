#include<bits/stdc++.h>
using namespace std;
priority_queue<int> pqmx;
priority_queue<int,vector<int>,greater<int> > pqmi;
int m1,m2;
template<class T>
T input(T ___)
{
  T _=0,__=1; char tc=getchar();
  while((tc<'0'||tc>'9')&&tc!='-') tc=getchar();
  if(tc=='-') tc=getchar(),__=-1;
  while(tc>='0'&&tc<='9') _=_*10+(tc-'0'),tc=getchar();
  return _*__;
}
main()
{
    int q;q=input(q);
    int cnt=0;
    while(q--)
    {
        int type;type=input(type);
        if(type==1)
        {
            int x;x=input(x);
            if(!cnt)m1=x;
            else if(cnt&1)
            {
                if(x>m1)
                {
                    pqmi.push(x);
                    m2=pqmi.top();pqmi.pop();
                }
                else
                {
                    pqmx.push(x);
                    m2=m1;
                    m1=pqmx.top();pqmx.pop();
                }
            }
            else
            {
                if(x>m2)
                {
                    pqmi.push(x);
                    pqmx.push(m1);
                    m1=m2;
                }
                else if(x<m1)
                {
                    pqmx.push(x);
                    pqmi.push(m2);
                }
                else
                {
                    pqmx.push(m1);
                    pqmi.push(m2);
                    m1=x;
                }
            }
            cnt++;
            ///printf("%d %d\n",m1,m2);
        }
        else printf("%d\n",m1);
    }
    return 0;
}
