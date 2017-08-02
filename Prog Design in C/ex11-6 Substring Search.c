#include <stdio.h>
#define MAXS 30

char *search(char *s, char *t);
void ReadString( char s[] ); /* 裁判提供，细节不表 */

int main()
{
    char s[MAXS], t[MAXS], *pos;

    ReadString(s);
    ReadString(t);
    pos = search(s, t);
    if ( pos != NULL )
        printf("%d\n", pos - s);
    else
        printf("-1\n");

    return 0;
}

/* 你的代码将被嵌在这里 */
char *search(char *s, char *t){
	int slen, tlen, iter, iiter, found = 1;
	char*pos = NULL;
	while(s[slen++]);
	slen--;
	while(t[tlen++]);
	tlen--;
	for(iter = 0; iter < slen; iter++){
		if(s[iter] == t[0]){
//			printf("iter = %d, tlen = %d, slen = %d\n", iter, tlen, slen);
			if(iter + tlen <= slen){/*Why should it be inclusive?*/
				for(iiter = iter; t[iiter - iter]; iiter++){
					if(s[iiter] != t[iiter - iter]) {
						found = 0;
						break;	
					}
				}
				if(found) {
					pos = s + iter;
					break;
				}
				else found = 1;		
			}
			
		}
	}
	return pos;
}
	
void ReadString( char s[] ){/*Details are here*/
	char temp[MAXS];
	gets(temp);
	int iter = 0;
	while(iter < MAXS && temp[iter]){
		s[iter] = temp[iter];
		iter++;
	}
		
	printf("iter = %d\n", iter);
	s[iter] = '\0';
}
