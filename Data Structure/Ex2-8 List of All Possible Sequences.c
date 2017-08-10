#include <stdio.h> 

void backswap(int start, int times);
void forswap(int start, int tiems);
void permutate(int *list, int start, int end);
void printlist(int len);

int list[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

int main(){
	
	int n, iter; 
	scanf("%d", &n);
	permutate(list, 0, n - 1);


	return 0;
}

void backswap(int start, int times){
	int iter, temp;
	for(iter = start + times; iter > start; iter--){
		temp = list[iter];
		list[iter] = list[iter - 1];
		list[iter - 1] = temp;
	}
}

void forswap(int start, int times){
	int iter, temp;
	for(iter = start; iter < start + times; iter++){
		temp = list[iter];
		list[iter] = list[iter + 1];
		list[iter + 1] = temp;
	}
}

void permutate(int *list, int start, int end){
	int iter, iter_start;
	if(start == end){
		printlist(end + 1);
		return;
	}
	else{
		for(iter = start; iter <= end; iter++){
			backswap(start, iter - start);
			
			permutate(list, start + 1, end);
			
			forswap(start, iter - start);
		}
	}
}

void printlist(int len){
	int iter;
	for(iter = 0; iter < len; iter++){
		printf("%d", list[iter]);
	}
	printf("\n");
}
