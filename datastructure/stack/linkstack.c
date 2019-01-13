/*
 * linkstack.c
 *
 *  Created on: 2018年11月27日
 *      Author: Jinjin
 */
#include<stdio.h>
#include<malloc.h>
//链栈的表示和实现，带头结点
//链栈的类型定义
typedef int ElemType;
typedef struct node{
	ElemType data;
	struct node *next;
}linkstack;
//初始化操作
linkstack *initstack() {
	linkstack *S;
	S=(linkstack *)malloc(sizeof(linkstack));
	S->next=NULL;
	return S;
}
//取栈顶操作元素
int gettop(linkstack *S,ElemType *e){
	if(S->next==NULL)return 0;//链栈为空
	*e=S->next->data;
	return 1;
}
//求栈长操作
int getlen(linkstack *S){
	linkstack *p;
	int i;
	p=S->next;i=0;
	while(p!=NULL){
		i++;
		p=p->next;
	}
	//printf("%d",i);
	return i;
}
//入栈操作，相当于在头结点后新增一个结点
int push(linkstack *S,ElemType x){
	linkstack *p;
	p=(linkstack *)malloc(sizeof(linkstack));
	if(!p)return 0;//若分配不成功返回0
	p->data=x;
	p->next=S->next;
	S->next=p;
	return 1;
}
//出栈操作，相当于在头结点后删除一个结点，*e保存删除后的元素
int pop(linkstack *S,ElemType *e){
 	linkstack *p;
	if(S->next==NULL)return 0;//栈空，出栈失败
	p=S->next;
	*e=p->data;
	S->next=p->next;
	free(p);
	return 1;
}
//判栈空操作（判断栈是否为空）
int emptystack(linkstack *S){
	if(S->next==NULL)return 1;
	else return 0;
}
//输出栈操作（遍历栈）
void list(linkstack *S){
	linkstack *p;
	p=S->next;
	while(p!=NULL){
		printf("%4d ",p->data);
		p=p->next;
	}
	printf("\n");
	//return 1;
}

/*
 *

int main(){
	ElemType e;
	int i;
	i=0;
	linkstack s;
	initstack();
	i=gettop(&s,&e);
	push(&s,3);
	push(&s,9);
	list(&s);
}
 */

