List Insert( List L, ElementType X ){
	PtrToNode  pnode = (PtrToNode)malloc(sizeof(struct Node));
	pnode->Data = X;
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
