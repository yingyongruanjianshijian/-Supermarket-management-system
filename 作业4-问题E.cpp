#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 100
typedef int ElemType;
typedef int Status;
typedef struct{
	ElemType *space;
	int top;
}Stack;
Status InitStack(Stack *S);
Status Push(Stack *S,ElemType e);
Status Pop(Stack *S,ElemType *ep);
Status ClearStack(Stack *S);
Status StackEmpty(Stack S);
int main()
{
	Stack S;
	ElemType e;
	InitStack(&S);
	long n;
	while(scanf("%ld",&n)!=EOF){
	    while(n){
		    Push(&S,n%8);
		    n=n/8;
	    }
	    while(!StackEmpty(S)){
		    Pop(&S,&e);
		    printf("%ld",e);
	    }
		ClearStack(&S);
		printf("\n");
	}
}
Status InitStack(Stack *S){
	S->space=(ElemType *)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if(!S->space)
	   return ERROR;
	S->top=-1;
	return OK;
}
Status Push(Stack *S,ElemType e){
	if(S->top+1==STACK_INIT_SIZE)
	    return ERROR;
	S->space[++S->top]=e;
	return OK;
}
Status Pop(Stack *S,ElemType *ep){
	if(S->top==-1)
	     return ERROR;
	*ep=S->space[S->top--];
	return OK;
}
Status ClearStack(Stack *S){
	if(!S->space)
	    return ERROR;
	S->top=-1;
	return OK;
}
Status StackEmpty(Stack S){
	if(S.top==-1)
	    return OK;
	else
	    return ERROR;
}

