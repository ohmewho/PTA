#include <stdio.h>
void leftShift(int *intArr, int n, int shift);


int main(){
	
	int n, m;
	scanf("%d %d", &n, &m);
	
	int nums[n], first = 1, iter;
	for(iter = 0; iter < n; iter++){
		scanf("%d", &nums[iter]);
	}
//	for(iter = 0; iter < n; iter++){
//		if(first) first = 0;
//		else printf(" ");
//		printf("%d", nums[iter]);
//	}
//	printf("\n");
	leftShift(nums, n, m);
	first = 1;
	for(iter = 0; iter < n; iter++){
		if(first) first = 0;
		else printf(" ");
		printf("%d", nums[iter]);
	}
	printf("\n");	
	
	return 0;
}

void leftShift(int *intArr, int n, int shift){
	int m = shift % n;
	if(m){
		int temp[m], iter;
		for(iter = 0; iter < m; iter++){
			temp[iter] = intArr[iter];
		}
		for(iter = 0; iter < n - m; iter++){
			intArr[iter] = intArr[iter + m];
		}
		for(iter = n - m; iter < n; iter++){
			intArr[iter] = temp[iter - n + m];
		}
	}
	
}
