#include <stdio.h>
#include <string.h>

#define MAXN 20
typedef enum {false, true} bool;

bool palindrome( char *s );
bool palindrome1( char *s );

int main()
{
    char s[MAXN];

    scanf("%s", s);
    if ( palindrome(s)==true )
        printf("Yes\n");
    else
        printf("No\n");
    printf("%s\n", s);

    return 0;
}

bool palindrome( char *s ){

	bool rtn = true;
	int len = 0, iter;
	while(s[len++]);
	len--;
//	printf("%d\n", len);
	for(iter = 0; iter < len * 1.0 / 2; iter++){
//		printf("iter = %d, %c %c\n", iter, s[iter], s[len - 1 - iter]);
		if(s[iter] != s[len - 1 - iter]) {			
			rtn = false;
			break;
		}	
	}
	
	return rtn;
}
