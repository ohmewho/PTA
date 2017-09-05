#include <stdio.h>


int main() {
	
	char ch;
	
    int n, temp, iter, cnt = 0, numcount[10] = {0}, resultcount[10] = {0}, carry = 0, same = 1;
    
    int nums[20] = {0}, result[21] = {0};
    for(iter = 0; iter < 20; iter++){
    	scanf("%c",&ch);
    	if(ch < '0' || ch > '9') break;
    	cnt++;
    	nums[iter] = ch - '0';
    	numcount[ch - '0']++;
	}
	
	for(iter = cnt - 1; iter >= 0; iter--){
		n = nums[iter] * 2 + carry;
		result[cnt - 1 - iter] += n % 10;
		carry = n / 10;	
		resultcount[n % 10]++;
	}
	if(carry) {
		same = 0;
		cnt++;
		result[cnt - 1] += carry;
		resultcount[carry]++;
	}
	else{
		for(iter = 0; iter < 10; iter++){
			if(numcount[iter] != resultcount[iter]) same = 0;
		}
	}	
	if(same) printf("Yes\n");
	else printf("No\n");
	
	for(iter = 0; iter < cnt; iter++){
		printf("%d", result[cnt - iter - 1]);
	}
    
    return 0;
}
