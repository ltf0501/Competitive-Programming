#include<cstdio>
#include<cstring>
#include<map>
#include<set>

using namespace std;

set<char> answer; //儲存答案的字母集合
set<char> guess;  //儲存使用者猜到答案的字母集合
map<char,int> sta; //記錄字母的狀態
 //set只會記錄所有不重複的東西
main()
{
    int rnd;
    while(scanf("%d",&rnd)==1 && rnd!=-1)
    {
        if(!sta.empty())sta.clear();
        if(!answer.empty())answer.clear();
        if(!guess.empty())guess.clear();

        getchar();
        char c;

        while(c=getchar()) //讀取並記錄答案的字母集合
        {
            if(c=='\n') break;
            answer.insert(c);
            sta[c]=1; //status為1,表示此字母為答案
        }

        int lose=0;
        int ansSize=(int)answer.size();

        char str[100];
        memset(str,0,sizeof(str));
        scanf("%s",str);
        bool chicken=true;
        printf("Round %d\n",rnd);
        for(int i=0;i<strlen(str);i++)
        {
            c=str[i];
            if(sta.find(c)!=sta.end()) //如果找的到key表示此字母為答案or有被猜過
            {
                if(sta[c]==1) //如果此字母為答案,則將此字母塞進guess這個set裡面
                {
                    guess.insert(c);
                }
            }
            else //如果找不到key, 表示此字母沒被猜過且並非答案
            {
                lose++;
                sta[c]=2; //status為2,表示此字母被猜過,但不是答案
            }

            if(lose==7)
            {
                puts("You lose.");
                chicken=false; //輸了就不是chicken out
                break;
            }

            int guessSize=(int)guess.size();
            if(guessSize==ansSize) //如果guess和answer這2個set大小一樣,表示字母全被找到了
            {
                puts("You win.");
                chicken=false; //贏了就不是chicken out
                break;
            }
        }

        if(chicken) //沒贏沒輸就是chicken out
        {
            puts("You chickened out.");
        }
    }
}
