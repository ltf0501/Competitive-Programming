 #include<cstdio>
 #include<algorithm>
 #include<cstring>
 #include<vector>
 using namespace std;
 #define maxn 10000+10
 main()
 {
     int n,a[maxn],t=0;
     while(scanf("%d",&n)==1 && n)
     {
         for(int i=0;i<n;i++)scanf("%d",&a[i]);
         if(t++)printf("\n");
         sort(a,a+n);
         int cur=0,piece=0;
         while(cur<n)
         {
             int pre=cur;
             while(cur<n && a[cur]==a[pre])cur++;
             piece=max(piece,cur-pre);
         }//�p��ܦh���X��(�Y�P�Ʀr�ӼƳ̤j��)
         vector<int> b[maxn];
         for(int i=0;i<n;i++)b[i%piece].push_back(a[i]);
         printf("%d\n",piece);
         for(int i=0;i<piece;i++)
         {
             for(int j=0;j<b[i].size();j++)
             {
                 if(!j)printf("%d",b[i][j]);
                 else printf(" %d",b[i][j]);
             }
             printf("\n");
         }
     }

 }
