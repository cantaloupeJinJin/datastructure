/*
 * linkqueue.c
 *
 *  Created on: 2018年11月27日
 *      Author: Jinjin
 */
/*
 * linkqueue.c
 *
 *  Created on: 2018年11月22日
 *      Author: Jinjin
 */

#include<stdio.h>
#include<malloc.h>
//链队列的表示和实现
//链队列的类型定义
typedef int ElemType;
typedef struct node{
	ElemType data;
	struct node *next;
}qlink;
typedef struct{
	qlink *front;
	qlink *rear;
}linkqueue;
//初始化操作
void initqueue(linkqueue *LQ){
	LQ->front=LQ->rear=(qlink *)malloc(sizeof(qlink));
	//需要同时给队头指针和队尾指针申请空间
	LQ->front->next=NULL;
}
//求队列长度操作
int getlen(linkqueue *LQ){
	int i;
	qlink *p;
	p=LQ->front->next;
	i=0;p=LQ->front->next;
	while(p!=NULL){
		i++;
		p=p->next;
	}
	return i;
}
//判队空操作
int emptyqueue(linkqueue *LQ){
	if(LQ->front==LQ->rear)return 1;
	else return 0;
}
//取队头元素
int getfront(linkqueue *LQ,ElemType *e){
	if(LQ->front==LQ->rear)return 0;//队空，返回0
	*e=LQ->front->next->data;
	return 1;
}
//入队列操作
int enqueue(linkqueue *LQ,ElemType x){
	qlink *p;
	p=(qlink *)malloc(sizeof(qlink));
	//if(!p)return 0;//分配空间失败
	p->data=x;
	p->next=NULL;
	LQ->rear->next=p;
	LQ->rear=p;//队尾指针后移一位
	return 1;
}
//出队操作
int outqueue(linkqueue *LQ,ElemType *e){
	qlink *p;
	if(LQ->rear==LQ->front)return 0;//队空
	p=LQ->front->next;
	*e=p->data;
	LQ->front->next=p->next;
	free(p);
	return 1;
}
//输出队列操作
void list(linkqueue *LQ){
	qlink *p;
	p=LQ->front->next;
	while(p!=NULL){
		printf("%d",p->data);
		p=p->next;
	}
}
//int main(){
//	linkqueue LQ;
//	ElemType e;
//	initqueue(&LQ);
//	enqueue(&LQ,3);
//	enqueue(&LQ,4);
//	enqueue(&LQ,5);
//	outqueue(&LQ,&e);
//	printf("%d",getlen(&LQ));
//	list(&LQ);
//	return 0;
//}



