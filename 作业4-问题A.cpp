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
int main()
{
	Stack S;
	ElemType e;
	InitStack(&S);
	char str[256];
	char left='(',road=')';
	while(scanf("%s",str)!=EOF){
		int i,count;
		for(i=0;str[i]!='\0';i++){
			count=1;
			if(str[i]==left)
			   Push(&S,left);
			else if(str[i]==road){
				Pop(&S,&e);
				while(e==road){
					count++;
                    Pop(&S,&e);
				}
				printf("%d ",count);
				int j=0;
				for(;j<count;j++)
				   Push(&S,road);
			}
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
