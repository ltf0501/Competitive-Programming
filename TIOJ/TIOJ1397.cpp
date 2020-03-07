#include<bits/stdc++.h>
using namespace std;
#define maxn 100000+10
int n,d;
list<int>num;
char s[maxn];
main()
{
    while(scanf("%d%d",&n,&d)!=EOF)
    {
        scanf("%s",s);
        list<int> num;
        num.push_back(0);
        for(int i=0;s[i];i++)num.push_back(s[i]-'0');
        num.push_back(0);

        list<int>::iterator hd,ed;
        hd = num.begin();
        ed = num.begin();
        hd++;
        while(d)
        {
            if(*hd<*ed)
            {
                if(*hd==0)continue;
                num.erase(ed);
                printf("%d\n",*ed);
                hd--;
                ed=hd;
                hd++;
                d--;
            }
            else
            {
                if(*ed!=0)
                {
                    hd++;
                    ed++;
                }
                else
                {
                    ed--;
                    if(*hd<*ed)
                    {
                        num.erase(ed);
                        d--;
                        ed=hd;ed--;
                        if(d)num.erase(ed);
                        d--;
                        ed=hd;ed--;
                    }
                    else ed++;
                }

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
