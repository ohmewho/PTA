#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *readlist();
struct ListNode *deletem( struct ListNode *L, int m );
void printlist( struct ListNode *L )
{
    struct ListNode *p = L;
	int c = 0;
    while (p && c < 20) {
        printf("%d ", p->data);
        p = p->next;
        c++;
     }
     printf("\n");
     
}

int main()
{
    int m;
    struct ListNode *L = readlist();
    
    scanf("%d", &m);
    printlist(L);
    L = deletem(L, m);
//    printf("After deleting m from the list:\n");
    printlist(L);

    return 0;
}


/* 你的代码将被嵌在这里 */
struct ListNode *readlist(){
	struct ListNode *phead, *ptail, *qnode;  /*attach new nodes to tail*/
	int num, empty = 1;

	scanf("%d", &num);
	while(num!=-1 ){
		
		qnode = (struct ListNode *)malloc(sizeof(struct ListNode));
		qnode->data = num;
		qnode->next = NULL;
		
		if(empty){
			phead = qnode;
			ptail = phead;
			empty = 0;
		}
		else{
			ptail->next = qnode;
			ptail = ptail->next;
		}
				
		scanf("%d", &num);
	}
	return phead;
}

struct ListNode *deletem( struct ListNode *L, int m ){
	struct ListNode *phead = L, *pfirst, *psecond, *ptemp, *plnode, *ptail;
	//int c= 0, flag = 1;
	
	while(phead && phead->data == m /*&&c<15*/){ /*find the first node*/

		ptemp = phead;
	//	printf("data of phead is %d\n", ptemp->data);
	//	c++;
	//	printf("%d Found a node.\n", c);
		phead = ptemp->next;
	//	printf("data of phead is %d\n", phead->data);
		free(ptemp);		
	}
	
	
	if(phead){ /* the first node could be NULL*/ 
		
		pfirst = phead->next;
		ptail = phead;
	//	printf("Hello, data of ptail is %d\n", ptail->data);
		while(pfirst->next /*&& c<20*/){
			if(pfirst->data == m){
			//	c++;				
		//		printf("%d Found a node.\n", c);
				ptemp = pfirst;
				pfirst = pfirst->next;
				ptail->next = pfirst;
		//		printf("ptail is %d\n", ptail->next == NULL);
				
				free(ptemp); 
			}
			else{
				ptail = pfirst;
				pfirst = pfirst->next;
		//		printf("data of pfirst is %d\n", pfirst->data);
				
			}
		
			
		}
		if(pfirst->data == m){
		//	printf(" hehehoho data of pfirst is %d\n", pfirst->data);
			
			ptail->next = pfirst->next;
			free(pfirst);
		}
	//	plnode->next = pfirst;
	}
	 	
	return phead; 
} 
