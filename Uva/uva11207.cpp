#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

double value( int h, int w )
{
	if ( h < w ) swap( h, w );
	return max( w/2.0, min( h/4.0, w+0.0 ) );
}

int main()
{
	int n;
	int h,w;
	while ( ~scanf("%d",&n) && n ) {
		double max = 0,now = 1;
		for ( int i = 1 ; i <= n ; ++ i ) {
			scanf("%d%d",&h,&w);
			if ( max < value( h, w ) ) {
				max = value( h, w );
				now = i;
			}
		}
		printf("%.0lf\n",now);
	}
	return 0;
}
