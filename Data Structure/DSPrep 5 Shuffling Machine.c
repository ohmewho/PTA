#include <stdio.h>

void shuffle(int *origin, int*shuffling);

void printdeck(int *);

	char deck[54][4] = { "S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13", 
"H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13",
"C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13",
"D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13",
"J1", "J2"
};

int main() {
	
	int n, iter, origin_order[54], shuffling_order[54], first = 1;
	for(iter = 0; iter < 54; iter++){
		origin_order[iter] = iter;
	}	
	scanf("%d", &n);
	for(iter = 0; iter < 54; iter++){
		scanf("%d", &shuffling_order[iter]);
	}
	for(iter = 0; iter < n; iter++){
		shuffle(origin_order, shuffling_order);
	}
    
    printdeck(origin_order);
    
    return 0;
}


void shuffle(int *origin_order, int *shuffling_order){
	int iter, initer, first = 1, number, temp[54];
	for(iter = 0; iter < 54; iter++){
		
		temp[shuffling_order[iter] - 1] = origin_order[iter];
	//	printf("temp[%d] = %d\n", shuffling_order[iter] - 1, origin_order[iter]); 
	}
	
	for(iter = 0; iter < 54; iter++){
		origin_order[iter] = temp[iter];
	}	
	
	
}

void printdeck(int *order){
	
	int iter, first = 1;
	for(iter = 0; iter < 54; iter++){
		if(first) first = 0;
		else printf(" ");
		printf("%s", deck[order[iter]]);
	}
	printf("\n");
}
