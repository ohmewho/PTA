#include <stdio.h> 

int main(){
	
	int n, start = 0, end = 0, started = 0, length = 1, maxstart = 0, maxend = 0, first = 1; 
	scanf("%d", &n);
	int nums[n], iter;
	for(iter = 0; iter < n; iter++){
		scanf("%d", &nums[iter]);
		if(iter > 0){
			if(nums[iter] > nums[iter - 1]){
				if(!started) {
					started = 1;
					start = iter - 1;  /*There are two incremental elements till this iteration.*/
				//	printf("max incremental sequence starts from %d\n", start);
				}
			}
			else if(started) {     /* nums[iter] <= nums[iter -1]*/
				started = 0;
				end = iter - 1;
			//	printf("max incremental sequence ends at %d\n", end);
				if(end - start + 1 > length){
					length = end - start + 1;
					maxstart = start;
					maxend = end;
				//	printf("\nMax incremental sequence starts from %d, end at %d\n\n", maxstart, maxend);
				}
				
			}
			
		}
	}
	
	
	if(end == 0) {
		maxstart = start;
		maxend = end;	
	}
	if(started){
		maxstart = start;
		maxend = n - 1;
	}
		
	//printf("\nResult: Max incremental sequence starts from %d, end at %d\n\n", maxstart, maxend);

	for(iter = maxstart; iter < maxend + 1; iter++){
		if(first) first = 0;
		else printf(" ");
		printf("%d", nums[iter]);
	}	
	
	printf("\n");
	
	return 0;
}
