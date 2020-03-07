#include<bits/stdc++.h>
using namespace std;

int n,d;
list<int>num;
string s;
main()
{
    while(cin>>s>>d)
    {
        int n=s.size();
        d=n-d;
        list<int> num;
        num.push_back(10);
        for(int i=0;s[i];i++)num.push_back(s[i]-'0');
        num.push_back(10);

        list<int>::iterator hd,ed;
        hd = num.begin();
        ed = num.begin();
        hd++;
        while(d)
        {
            if(*hd>*ed)
            {
                num.erase(ed);
                hd--;
                ed=hd;
                hd++;
                d--;
            }
            else
            {
                hd++;
                ed++;
            }
        }
        num.pop_front();
        num.pop_back();
        for(hd=num.begin();hd!=num.end();hd++)
        {
            printf("%d",*hd);
        }
        printf("\n");
    }
    return 0;
}
