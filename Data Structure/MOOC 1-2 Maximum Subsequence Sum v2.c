#include <stdio.h>

int main(){
	
	int K, iter, start_idx = 0, max_start_idx = 0, end_idx = 0;
	int this_sum = 0, max = -1, negative = 1;
	scanf("%d", &K);
	
	int nums[K];
	for(iter = 0; iter < K; iter++){
		scanf("%d", &nums[iter]);
		
		if(nums[iter] >= 0) {
			//sq_started = 1;
			//printf("sequence started from %d\n", iter);
		
			negative = 0;
		}
		
		this_sum += nums[iter];
		
		if(this_sum > max) {
			max_start_idx = start_idx;
			max = this_sum;
			end_idx = iter;
		}
		  
		else if(this_sum < 0) {
			this_sum = 0;
			start_idx = iter + 1;
		}
		//printf("%d %d %d\n", max, max_start_idx, end_idx);
	}
	if(negative) {
		max_start_idx = 0;
		end_idx = K - 1;
	}
	max = max > 0? max : 0;
	printf("%d %d %d %d\n", max, max_start_idx, nums[max_start_idx], nums[end_idx]);
	return 0;
}
