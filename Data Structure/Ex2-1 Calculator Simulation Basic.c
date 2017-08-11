#include <stdio.h> 

int main(){
	
	int num, result, error = 0;
	char ch; 
	scanf("%d %c", &num, &ch);
	result = num;
	while(ch != '='){
		scanf("%d", &num);
		switch(ch){
			case '+': result += num;
			break;
			case '-': result -= num;
			break;
			case '*': result *= num;
			break;
			case '/': if(num == 0) error = 1;
			else result /= num;
			break;
			default: error = 1;
			break;
		}
		scanf("%c", &ch);
		
	}
	if(error) printf("ERROR\n");
	else printf("%d\n", result);
	
	return 0;
}
