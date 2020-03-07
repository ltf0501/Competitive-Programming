#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<vector>
int Mod(int a,int p)
{
 a%=p;
 if(a<0)
  a+=p;
 return a;
}
int main()
{

 int T;scanf("%d",&T);
 int n,k;
 for(int lT=1;lT<=T;lT++)
 {
  int inp;
  std::vector<int> line;
  bool stamp[100];memset(stamp,false,sizeof(stamp));
  bool tmp[100];memset(tmp,false,sizeof(tmp));
  scanf("%d %d",&n,&k);
  for(int lx=1;lx<=n;lx++)
  {
   scanf("%d",&inp);
   if(inp%k!=0)
    line.push_back(Mod(inp,k));
  }
  //for(int lx=0;lx<line.size();lx++)
  // printf("%d ",line[lx]);
  //printf("\n");
  stamp[0]=1;
  for(int lx=0;lx<line.size();lx++)
  {
   for(int lr=0;lr<k;lr++)
   {
    if(stamp[lr])
    {
     tmp[Mod(lr+line[lx],k)]++;
     tmp[Mod(lr-line[lx],k)]++;
     //printf("lr=%d line[lx]=%d\n",lr,line[lx]);
    }
   }
   for(int lr=0;lr<k;lr++)
    stamp[lr]=tmp[lr];
   memset(tmp,0,sizeof(tmp));
  }
  if(stamp[0]>0)
   printf("Divisible\n");
  else
   printf("Not divisible\n");
 }
 return 0;
}
