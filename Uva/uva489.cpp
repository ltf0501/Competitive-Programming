#include<cstdio>
#include<cstring>
#include<map>
#include<set>

using namespace std;

set<char> answer; //�x�s���ת��r�����X
set<char> guess;  //�x�s�ϥΪ̲q�쵪�ת��r�����X
map<char,int> sta; //�O���r�������A
 //set�u�|�O���Ҧ������ƪ��F��
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

        while(c=getchar()) //Ū���ðO�����ת��r�����X
        {
            if(c=='\n') break;
            answer.insert(c);
            sta[c]=1; //status��1,��ܦ��r��������
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
            if(sta.find(c)!=sta.end()) //�p�G�䪺��key��ܦ��r��������or���Q�q�L
            {
                if(sta[c]==1) //�p�G���r��������,�h�N���r����iguess�o��set�̭�
                {
                    guess.insert(c);
                }
            }
            else //�p�G�䤣��key, ��ܦ��r���S�Q�q�L�B�ëD����
            {
                lose++;
                sta[c]=2; //status��2,��ܦ��r���Q�q�L,�����O����
            }

            if(lose==7)
            {
                puts("You lose.");
                chicken=false; //��F�N���Ochicken out
                break;
            }

            int guessSize=(int)guess.size();
            if(guessSize==ansSize) //�p�Gguess�Manswer�o2��set�j�p�@��,��ܦr�����Q���F
            {
                puts("You win.");
                chicken=false; //Ĺ�F�N���Ochicken out
                break;
            }
        }

        if(chicken) //�SĹ�S��N�Ochicken out
        {
            puts("You chickened out.");
        }
    }
}
