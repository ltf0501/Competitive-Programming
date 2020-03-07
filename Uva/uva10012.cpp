#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define ABS(X) ((X) < 0 ? -(X) : (X))

#define MAX_CIRCLES 8

double R[MAX_CIRCLES], C[MAX_CIRCLES];

double distance(const int k, const int l)
{
   return sqrt(pow(R[k] + R[l], 2) - pow(ABS(R[k] - R[l]), 2));
}


double dfs(const int m)
{
   int i, j;
   double max;

   if (m == 1) {
      return 2 * R[0];
   }

   C[0] = R[0];
   for (i = 1; i < m; i++) {
      for (j = max = 0; j < i; j++) {
         max = MAX(max, C[j] + distance(i, j));
      }

      C[i] = MAX(R[i], max);
   }

   for (i = max = 0; i < m; i++) {
      max = MAX(max, C[i] + R[i]);
   }

   return max;
}



double minWidth(int start, int m)
{
   if (start ==m - 1)
   {
      return dfs(m);
   }
   else
   {
      int i;

      double tmp, min = .0, w;
      for (i = start; i < m; i++)
      {
         tmp = R[i];
         R[i] = R[start];
         R[start] = tmp;

         w = minWidth(start + 1,m);
         if (w < min || min == .0)min = w;

         R[start] = R[i];
         R[i] = tmp;
       }

      return min;
   }
}


main()
{
   int i, j, n,m;
   double radius, width;

   while(scanf("%d",&n)==1)
   {
      for (i = 0; i < n; i++)
      {
          scanf("%d",&m);

      for (j = 0; j < m; j++)
      {
        scanf("%lf", &radius);
        R[j] = radius;
      }

      printf("%.3f\n", minWidth(0, m));
      }
   }


   return 0;
}
