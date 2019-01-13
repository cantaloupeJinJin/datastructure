/*
 * cqueue.c
 *
 *  Created on: 2018��11��27��
 *      Author: Jinjin
 */

#include<stdio.h>
#include<malloc.h>
//ѭ�����еı�ʾ��ʵ��
//ѭ���������Ͷ���
#define MAXCSIZE 100
typedef int ElemType;
typedef struct {
	ElemType *base;
	int front;
	int rear;
}cqueue;
//��ʼ������
void initqueue(cqueue *cq){
	cq->base=(ElemType *)malloc(MAXCSIZE*sizeof(ElemType));
	cq->front=cq->rear=0;
}
//��ӳ�����
int getlen(cqueue *cq){
	return ((cq->rear-cq->front+MAXCSIZE)%MAXCSIZE);
}
//ȡ��ͷԪ�ز���
int getfront(cqueue *cq,ElemType *e){
	if(cq->front==cq->rear)return 0;
	*e=cq->base[cq->front];
	return 1;
}
//�����Ԫ�ز���
int enqueue(cqueue *cq,ElemType x){
	if((cq->rear+1)%MAXCSIZE==cq->front)return 0;//��������ʧ��
	cq->base[cq->rear]=x;
	cq->rear=(cq->rear+1)%MAXCSIZE;
	return 1;
}
//������Ԫ��
int outqueue(cqueue *cq,ElemType *e){
	if(cq->front==cq->rear)return 0;//�ӿգ�����ʧ��
	*e=cq->base[cq->front];
	cq->front=(cq->front+1)%MAXCSIZE;
	return 1;
}
//�жӿղ���
int emptyqueue(cqueue *cq){
	if(cq->front==cq->rear)return 1;//�ӿ�
	else return 0;//�Ӳ���
}
//�������
void list(cqueue *cq){
	int front1,rear1;
	front1=cq->front;
	rear1=cq->rear;
	//while(cq->front!=cq->rear){
	//	printf("%d ",cq->base[cq->front]);
	//	cq->front=(cq->front+1)%MAXCSIZE;
	//}���д�����֣�����������rear,frontλ�ö��б䶯
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
