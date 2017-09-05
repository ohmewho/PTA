#include <stdio.h>
#include <math.h>

int notprime[100000] = {1,1};

void printres(int);

int main() {
    int n;
    
    scanf("%d", &n);
    
    printres(n);
    return 0;
}

void printres(int n){
	int oiter, initer, first = 1, num = 0;
	
	for(oiter = 2; oiter * oiter <= n; oiter++){
		for(initer = 2; oiter * initer <= n; initer++){
			notprime[oiter * initer] = 1;
		}
	}
	
	for(oiter = 1; oiter + 2 <= n; oiter++){
		if(!notprime[oiter] && !notprime[oiter + 2]){
//			if(first) first = 0;
//			else printf(" ");
//			printf("%d %d\n", oiter, oiter + 2);
			num++;
		}	
	}
	
	
	
	
	printf("%d", num);
}
