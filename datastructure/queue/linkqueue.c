/*
 * linkqueue.c
 *
 *  Created on: 2018��11��27��
 *      Author: Jinjin
 */
/*
 * linkqueue.c
 *
 *  Created on: 2018��11��22��
 *      Author: Jinjin
 */

#include<stdio.h>
#include<malloc.h>
//�����еı�ʾ��ʵ��
//�����е����Ͷ���
typedef int ElemType;
typedef struct node{
	ElemType data;
	struct node *next;
}qlink;
typedef struct{
	qlink *front;
	qlink *rear;
}linkqueue;
//��ʼ������
void initqueue(linkqueue *LQ){
	LQ->front=LQ->rear=(qlink *)malloc(sizeof(qlink));
	//��Ҫͬʱ����ͷָ��Ͷ�βָ������ռ�
	LQ->front->next=NULL;
}
//����г��Ȳ���
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
//�жӿղ���
int emptyqueue(linkqueue *LQ){
	if(LQ->front==LQ->rear)return 1;
	else return 0;
}
//ȡ��ͷԪ��
int getfront(linkqueue *LQ,ElemType *e){
	if(LQ->front==LQ->rear)return 0;//�ӿգ�����0
	*e=LQ->front->next->data;
	return 1;
}
//����в���
int enqueue(linkqueue *LQ,ElemType x){
	qlink *p;
	p=(qlink *)malloc(sizeof(qlink));
	//if(!p)return 0;//����ռ�ʧ��
	p->data=x;
	p->next=NULL;
	LQ->rear->next=p;
	LQ->rear=p;//��βָ�����һλ
	return 1;
}
//���Ӳ���
int outqueue(linkqueue *LQ,ElemType *e){
	qlink *p;
	if(LQ->rear==LQ->front)return 0;//�ӿ�
	p=LQ->front->next;
	*e=p->data;
	LQ->front->next=p->next;
	free(p);
	return 1;
}
//������в���
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



