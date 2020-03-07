#include<stdio.h>

int map[105][105] = {0};
int longest[105][105] = {0};

int DFS( int x, int y )//dfs以該格為起點的最大長度
{
    int result[4] = {0};
    if( map[y][x+1] > map[y][x] )
    {
        if( longest[y][x+1] )
            result[0] = 1+longest[y][x+1];
        else
            result[0] = 1+DFS(x+1,y);
    }
    if( map[y][x-1] > map[y][x] )
    {
        if( longest[y][x-1] )
            result[1] = 1+longest[y][x-1];
        else
            result[1] = 1+DFS(x-1,y);
    }
    if( map[y+1][x] > map[y][x] )
    {
        if( longest[y+1][x] )
            result[2] = 1+longest[y+1][x];
        else
            result[2] = 1+DFS(x,y+1);
    }
    if( map[y-1][x] > map[y][x] )
    {
        if( longest[y-1][x] )
            result[3] = 1+longest[y-1][x];
        else
            result[3] = 1+DFS(x,y-1);
    }
    int answer = 1;
    int i;
    for( i = 0 ; i <= 3 ; i++ )
        if( answer < result[i] )
            answer = result[i];
    return answer;
}

int main()
{
    int N;
    while( scanf( "%d", &N ) != EOF )
    {
        int i;
        for( i = 0 ; i < N ; i++ )
        {
            char S[100];
            int R, C;
            scanf( "%s%d%d", S, &R, &C );
            int i, j;
            for( i = 1 ; i <= R ; i++ )
                for( j = 1 ; j <= C ; j++ )
                {
                    scanf( "%d", &map[i][j] );
                    longest[i][j] = 0;
                }
            int answer = 0;
            for( i = 1 ; i <= R ; i++ )
                for( j = 1 ; j <= C ; j++ )
                {
                    longest[i][j] = DFS( j, i );
                    if( answer < longest[i][j] )
                        answer = longest[i][j];
                }
            printf( "%s: %d\n", S, answer );
        }
    }
    return 0;
}
