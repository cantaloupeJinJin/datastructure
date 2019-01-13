/*
 * cqueue.c
 *
 *  Created on: 2018年11月27日
 *      Author: Jinjin
 */

#include<stdio.h>
#include<malloc.h>
//循环队列的表示和实现
//循环队列类型定义
#define MAXCSIZE 100
typedef int ElemType;
typedef struct {
	ElemType *base;
	int front;
	int rear;
}cqueue;
//初始化操作
void initqueue(cqueue *cq){
	cq->base=(ElemType *)malloc(MAXCSIZE*sizeof(ElemType));
	cq->front=cq->rear=0;
}
//求队长操作
int getlen(cqueue *cq){
	return ((cq->rear-cq->front+MAXCSIZE)%MAXCSIZE);
}
//取队头元素操作
int getfront(cqueue *cq,ElemType *e){
	if(cq->front==cq->rear)return 0;
	*e=cq->base[cq->front];
	return 1;
}
//入队列元素操作
int enqueue(cqueue *cq,ElemType x){
	if((cq->rear+1)%MAXCSIZE==cq->front)return 0;//队满插入失败
	cq->base[cq->rear]=x;
	cq->rear=(cq->rear+1)%MAXCSIZE;
	return 1;
}
//出队列元素
int outqueue(cqueue *cq,ElemType *e){
	if(cq->front==cq->rear)return 0;//队空，出队失败
	*e=cq->base[cq->front];
	cq->front=(cq->front+1)%MAXCSIZE;
	return 1;
}
//判队空操作
int emptyqueue(cqueue *cq){
	if(cq->front==cq->rear)return 1;//队空
	else return 0;//队不空
}
//输出操作
void list(cqueue *cq){
	int front1,rear1;
	front1=cq->front;
	rear1=cq->rear;
	//while(cq->front!=cq->rear){
	//	printf("%d ",cq->base[cq->front]);
	//	cq->front=(cq->front+1)%MAXCSIZE;
	//}如果写成这种，遍历结束后，rear,front位置都有变动
	while(front1!=rear1){
		printf("%d ",cq->base[front1]);
		front1=(front1+1)%MAXCSIZE;
	}
	printf("\n");
}
//int main(){
//	cqueue cq;
//	initqueue(&cq);
//	enqueue(&cq,3);
//	enqueue(&cq,9);
//	list(&cq);
//	printf("%d",getlen(&cq));
//}
