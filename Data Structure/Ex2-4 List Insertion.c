#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表 */

List Insert( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    L = Read();
    scanf("%d", &X);
    L = Insert(L, X);
    Print(L);
    return 0;
}

/* 你的代码将被嵌在这里 */

List Read(){
	int num, iter;
	ElementType ele;
	scanf("%d", &num);
	List l = (List)malloc(sizeof(struct Node));
	l->Next = NULL;
	for(iter = 0; iter < num; iter++){
		scanf("%d", &ele);
		Insert(l, ele);	
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

List Insert( List L, ElementType X ){
	PtrToNode pnode = (PtrToNode)malloc(sizeof(struct Node));
	pnode->Data = X;
//	int inserted = 0;
	PtrToNode curNode = L;
	while(curNode->Next && curNode->Next->Data < X){
		curNode = curNode->Next;
	}
	if(!curNode->Next) {
		pnode->Next = NULL; 
		curNode->Next = pnode;
	}
	else{
		pnode->Next = curNode->Next;
		curNode->Next = pnode;
	}
	return L;
}
