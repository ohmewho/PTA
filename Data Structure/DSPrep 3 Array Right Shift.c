#include <stdio.h>
#define MAXN 100

int ArrayShift( int a[], int n, int m );

int main()
{
    int a[MAXN], n, m;
    int i;

    scanf("%d %d", &n, &m);
    for ( i = 0; i < n; i++ ) scanf("%d", &a[i]);

    ArrayShift(a, n, m);

    for ( i = 0; i < n; i++ ) {
        if (i != 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");

    return 0;
}

int ArrayShift( int a[], int n, int m ){
	m = m % n;
	int iter, iiter, temp;
	
	if(m){
		for(iter = 0; iter < m; iter++){
			temp = a[n - 1];
			for(iiter = n - 1; iiter > 0; iiter--){
				a[iiter] = a[iiter - 1];
			}
			a[0] = temp;
		}
	}

	return 1;	
}
