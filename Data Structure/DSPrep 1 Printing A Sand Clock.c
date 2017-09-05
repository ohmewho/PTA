 #include <stdio.h>
#include <math.h>

void printsandclock(int, char);

int main() {
    int N;
    char ch;
    scanf("%d %c", &N, &ch);
    printsandclock(N, ch);
    return 0;
}

void printsandclock(int n, char ch){
	int maxcol, iter, mid, dist, spiter, sgiter;
	maxcol = (int)(sqrt((n + 1) *  2) - 1);
	//printf("%d %d\n", maxcol, (maxcol + 1) * (maxcol + 1) / 2 - 1);
	if(!(maxcol % 2)) maxcol--;
	mid = (maxcol - 1) / 2;
	for(iter = 0; iter < maxcol; iter++){
		dist = abs(iter - mid);
		for(spiter = 0; spiter < mid - dist; spiter++){
			printf(" ");
		}
		for(sgiter = 0; sgiter < maxcol - 2 * (mid - dist); sgiter++){
			printf("%c", ch);
		}
		printf("\n");
	}
	printf("%d", n - (maxcol + 1) * (maxcol + 1) / 2 + 1);
}
