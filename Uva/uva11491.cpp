#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<list>
using namespace std;
#define maxn 100000+10
int n,d;
list<int>num;
char s[maxn];
main()
{
    while(scanf("%d%d",&n,&d)!=EOF)
    {
        if (n==0 && d==0) break;
        scanf("%s",s);
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
/*
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <list>
using namespace std;

#define N 100020
char str[N];
int main() {
    int n, d;
    while (scanf("%d%d",&n, &d) != EOF) {
        if (n == 0 && d == 0) break;
        scanf("%s", str);
        list<int> num;
        num.push_back(10);
        for (int i = 0; str[i]; i++) {
            num.push_back(str[i]-'0');
        }
        num.push_back(10);

        list<int>::iterator hd, ed, tmp;
        hd = num.begin();
        ed = num.begin();
        hd++;
        while (d) {
            if (*hd > *ed) {
                num.erase(ed);
                hd--;
                ed = hd;
                hd++;

                d--;
            } else {
                hd++;
                ed++;
            }
        }
        num.pop_front();
        num.pop_back();
        for (hd = num.begin(); hd != num.end(); hd++) {
            printf("%d", *hd);
        }
        puts("");
    }
    return 0;
}
*/
