```c
#include <stdio.h>

void PrintN ( int N );

int main ()
{
    int N;

    scanf("%d", &N);
    PrintN( N );

    return 0;
}

/* 你的代码将被嵌在这里 */
void PrintN (int N){
	int i = 1;
	for(; i <= N; i++){
		printf("%d\n", i);
	}
}
```
