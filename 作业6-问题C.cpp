#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char TElemType;
typedef struct BiNode{
	TElemType data;
	struct BiNode *lchild;
	struct BiNode *rchild;
}BiNode,*BiTree;
BiTree CreatePM(TElemType *prestr,TElemType *midstr,int length){
	if(length==0)
	   return NULL;
	TElemType *p;
	int len_lchild=0,len_rchild=0;
	BiNode *root=(BiNode *)malloc(sizeof(BiNode));
	root->data=*prestr;
	for(p=midstr;p<midstr+length;p++){
		if(*p==*prestr)
		   break;
		len_lchild++;
	}
	root->lchild=CreatePM(prestr+1,midstr,len_lchild);
	len_rchild=length-len_lchild-1;
	root->rchild=CreatePM(prestr+1+len_lchild,p+1,len_rchild);
	return root;
}
BiTree Create(TElemType *data,int *loc){
	BiNode *root;
	if(data[*loc]=='#'){
		++(*loc);
		return NULL;
	}
	root=(BiNode *)malloc(sizeof(BiNode));
	root->data=data[*loc];
	(*loc)++;
	root->lchild=Create(data,loc);
	root->rchild=Create(data,loc);
	return root;
} 
void PostOrder(BiTree T){
	if(T==NULL)
	  return ;
	PostOrder(T->lchild);
	PostOrder(T->rchild);
	printf("%c",T->data);
}
void Destroy(BiTree *T){
	if(*T==NULL)
	   return ;
	Destroy(&((*T)->lchild));
	Destroy(&((*T)->rchild));
	free(*T);
	*T=NULL;
}
int main()
{
	BiTree T;
	int length,n;
	char prestr[1000],midstr[1000];
	scanf("%d",&n);
	while(n--){
		scanf("%s%s",prestr,midstr);
		length=strlen(prestr);
		T=CreatePM(prestr,midstr,length);
		PostOrder(T);
		printf("\n");
		Destroy(&T);
	}
} 
