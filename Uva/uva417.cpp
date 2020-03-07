#include<cstdio>
#include<cstring>
using namespace std;

main()
{
    int c[50][50];
    c[0][0]=1;
    for(int i=1;i<50;i++)
    {
		c[i][0]=1;
		for(int j=1;j<=i;j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
	char s[10];
	while(scanf("%s",s)==1)
    {
        int len=strlen(s),idx=0,cur=0;
        for(int i=1;i<len;i++)
        {
            cur=i;
            if(s[i]<=s[i-1]){printf("0\n");break;}
            idx+=c[26][i];
        }
        if(cur!=len-1)continue;
        for(int i=0;i<len;i++)
        {
            for(int j=(i==0)?1:s[i-1]-'a'+2;j<=s[i]-'a';j++)
            {
                idx+=c[26-j][len-i-1];
            }
        }
        printf("%d\n",idx+1);
    }
    return 0;
}
