#include <stdio.h>

int main(){
	
	int K, iter, start_idx = 0, max_start_idx = 0, end_idx = 0;
	int this_sum = 0, max = -1, negative = 1, started = 0, first = 1;
	scanf("%d", &K);
	
	int nums[K];
	for(iter = 0; iter < K; iter++){
		scanf("%d", &nums[iter]);
		
		if(nums[iter] >= 0) {
			
			negative = 0;
			
			if(this_sum == 0) {
				if(first){
					start_idx = iter;
					first = 0;//make sure that zeros are counted from the very first one.
				}
			}
		}
		
		
		this_sum += nums[iter];
		
		if(this_sum > max) {
			max_start_idx = start_idx;
			max = this_sum;
			end_idx = iter;
		}
		  
		else if(this_sum < 0) {
			this_sum = 0;
			first = 1;// first must be set to 1 for another possible subsequence.
			//start_idx = iter + 1;
		}
		//printf("%d %d %d\n", max, max_start_idx, end_idx);
	}
	if(negative) {
		max_start_idx = 0;
		end_idx = K - 1;
	}
	max = max > 0? max : 0;
	printf("%d %d %d\n", max, nums[max_start_idx], nums[end_idx]);
	return 0;
}
