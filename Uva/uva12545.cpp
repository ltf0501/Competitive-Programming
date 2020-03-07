#include <stdio.h>
#include <string.h>

int main() {
	int testcase, cases = 0;
	int i, j, k;
	char S[105], T[105];
	scanf("%d", &testcase);
	while(testcase--) {
		scanf("%s %s", &S, &T);
		printf("Case %d: ", ++cases);
		int tone = 0, tzero = 0;
		int sone = 0, szero = 0, snone = 0;
		int serr = 0, step = 0;
		for(i = 0; T[i]; i++) {
			if(T[i] == '0')	tzero++;
			else			tone++;
		}
		for(i = 0; S[i]; i++) {
			if(S[i] == '0')
				szero++;
			else if(S[i] == '1')
				sone++;
			else
				snone++;
		}
		if(szero+snone < tzero) {
			puts("-1");
			continue;
		}
		for(i = 0; S[i]; i++) {
			if(S[i] == '?') {
				step++;
				if(T[i] == '0' && szero < tzero)
					S[i] = '0', szero++;
				else if(T[i] == '1' && sone < tone)
					S[i] = '1', sone++;
				else if(szero < tzero)
					S[i] = '0', szero++;
				else
					S[i] = '1', sone++;
			}
		}
		for(i = 0; S[i]; i++) {
			if(sone < tone && S[i] == '0' && T[i] == '1')
				sone++, szero--, step++, S[i] = '1';
		}
		for(i = 0; S[i]; i++)
			serr += S[i] != T[i];
		printf("%d\n", serr/2+step);
	}
	return 0;
}
