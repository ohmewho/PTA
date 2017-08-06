#include <stdio.h>
#include <stdlib.h>

#define ERROR -1

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */
void attachtoTail(List L, ElementType ele);
void attachtoHead(List L, ElementType ele);

ElementType Find( List L, int m );

int main()
{
    List L;
    int m;
    L = Read();
    Print(L);
    attachtoHead(L, 15);
    Print(L);
    scanf("%d", &m);
    printf("%d\n", Find(L,m));
    Print(L);
    return 0;
}

/* 你的代码将被嵌在这里 */
List Read(){
	int num, iter;
	printf("Please input a number:\n");
	scanf("%d", &num);
	List l = (List)malloc(sizeof(struct Node));
	if(!l){
		printf("Memory allocation failed.\n");
		exit(0);
	}
	else{
		printf("Memory allocation succeeded. 12 1 %s\n", __func__);
	}
	l->Next = NULL;
	PtrToNode ptail = l;
	ElementType ele;
	for(iter = 0; iter < num; iter++){
		scanf("%d", &ele);
		attachtoTail(l, ele);
		while(ptail->Next){
			ptail = ptail->Next;
		}
		printf("iter = %d, data is %d.\n\n", iter, ptail->Data);		
	}         
	return l;
}

void Print( List L ){
	PtrToNode pnode = L->Next;
	int first = 1;
	while(pnode){
		if(first) first = 0;
		else printf(" ");
		printf("%d", pnode->Data);
		pnode = pnode->Next;
	}
	printf("\n");	
}

ElementType Find( List L, int m ){
	PtrToNode pnode = L->Next;
	int count = 0, fcount;
	ElementType ele = ERROR;
	while(pnode){
		count++;
		pnode = pnode->Next;
	}
//	printf("%d\n", count);
	pnode = L->Next;
//	printf("I am hi!\n");
	if(m <= count){
		fcount = count - m;
		count = 0;
		while(count < fcount){
			count++;
//			printf("data is %d\n", pnode->Data);
			pnode = pnode->Next;		
		}
		ele = pnode->Data;
	}
	return ele;	
}

void attachtoTail(List L, ElementType ele){
	Print(L);
	PtrToNode ptail = L;
	if(!ptail->Next) printf("I am empty!.\n");
	else {
		ptail = ptail->Next;
		while(ptail->Next){
			printf("%d_", ptail->Data);
			ptail = ptail->Next;		
		}
		printf("%d\n", ptail->Data);
	}	
	if(ptail == L)printf("I am at the head node, I do not have a data.\n");
	else printf("\ndata of ptail is %d.\n", ptail->Data);
	PtrToNode pnode = (PtrToNode)malloc(sizeof(struct Node));
	if(!pnode){
		printf("Memory allocation failed.\n");
		exit(0);
	}
	else{
		printf("Memory allocation succeeded. My name is %s.\n", __func__);
	}
	pnode->Data = ele;
	printf("data of pnode is %d\n", pnode->Data);
	pnode->Next = NULL;
	ptail->Next = pnode;
	
//	return;
}

void attachtoHead(List L, ElementType ele){
	PtrToNode pnode = (PtrToNode)malloc(sizeof(struct Node));
	pnode->Data = ele;
	pnode->Next = L->Next;
	L->Next = pnode;
}
