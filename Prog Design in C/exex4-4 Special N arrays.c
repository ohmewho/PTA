#include <stdio.h>

int cal(int * result, int a, int n);
void printres(int * result, int n);

int main()
{
    int a, n, iter;
    scanf("%d %d", &a, &n);
	
	int result[n + 1];
//	for(iter = 0; iter <= n; iter++){
//		result[]
//	}
    
    if(cal(result, a, n)){
    	printres(result, n + 1);
	}
	else printres(result, n);
    

    return 0;
}

int cal(int *result, int a, int n){
	int iter, carry = 0, sum, rtn = 0;
	for(iter = 0; iter < n; iter++){
		sum = a * (n - iter) + carry;
		result[iter] = sum % 10;
		carry = sum / 10;
	}
	if(carry) {
		rtn = 1;
		result[n] = carry;
	}
		
	return rtn;
}

void printres(int * result, int n){
	int iter;
	printf("s = ");
	for(iter = 0; iter < n; iter++){
		printf("%d", result[n - 1 - iter]);
	}
	printf("\n");
}
