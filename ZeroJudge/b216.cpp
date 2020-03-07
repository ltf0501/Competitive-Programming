#include<cstdio>
#include<algorithm>
using namespace std;

main()
{
    int g[3][3],score=0,line=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)g[i][j]=0;
    for(int i=0;i<9;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x%10 && y%10 && x>0 && y>0 && x<30 && y<30)
            g[x/10][y/10]=1;
    }
    /*
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)printf("%d ",g[i][j]);
        puts("");
    }
    */
    for(int i=0;i<3;i++)
    {
        int flag_r=0,flag_c=0;
        for(int j=0;j<3;j++)
        {
            if(g[i][j])
            {
                if((i==0 && j==0) || (i==2 && j==0) || (i==0 && j==2) || (i==2 && j==2))score+=8;
                else score+=5;
                flag_r++;
            }

            if(g[j][i])flag_c++;
        }
        if(flag_r==3)line++;
        if(flag_c==3)line++;
    }
    if(g[1][1])score-=3;
    printf("%d %d\n",line,score);
    return 0;
}
