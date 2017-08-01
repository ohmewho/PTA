#include <stdio.h>
#define MAXN 20

void CountOff( int n, int m, int out[] );

int main()
{
    int out[MAXN], n, m;
    int i;

    scanf("%d %d", &n, &m);
    CountOff( n, m, out );   
    for ( i = 0; i < n; i++ )
        printf("%d ", out[i]);
    printf("\n");

    return 0;
}

/* 你的代码将被嵌在这里 */
void CountOff( int n, int m, int out[] ){
	int temp[n], itera, iterb = 1, iterc = 0;
	
	for(itera = 0; itera < n; itera++){
		temp[itera] = 0;
	}
	
	for(itera = 0; itera < n; itera++){
		while(iterb < m){
			while(temp[iterc % n] ) {
				printf("iterc = %d, %d is skipped.\n", iterc, iterc % n + 1);
				iterc++;
			}
			
			printf("iterc = %d, number %d now count %d!\n", iterc, iterc % n + 1, iterb);
			iterb++;
			iterc++;		
		}
		while(temp[iterc % n]) {
			printf("iterc = %d, %d is skipped.\n", iterc, iterc % n + 1);
			iterc++;	
		}
		out[iterc % n] = itera + 1;
		temp[iterc % n] = 1;
		printf("iterc = %d, %d now counts %d off.\n", iterc, (iterc) % n + 1, iterb);
		iterb = 1;
		iterc++;
	}
	
}
