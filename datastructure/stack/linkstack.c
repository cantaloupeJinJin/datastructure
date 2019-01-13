/*
 * linkstack.c
 *
 *  Created on: 2018��11��27��
 *      Author: Jinjin
 */
#include<stdio.h>
#include<malloc.h>
//��ջ�ı�ʾ��ʵ�֣���ͷ���
//��ջ�����Ͷ���
typedef int ElemType;
typedef struct node{
	ElemType data;
	struct node *next;
}linkstack;
//��ʼ������
linkstack *initstack() {
	linkstack *S;
	S=(linkstack *)malloc(sizeof(linkstack));
	S->next=NULL;
	return S;
}
//ȡջ������Ԫ��
int gettop(linkstack *S,ElemType *e){
	if(S->next==NULL)return 0;//��ջΪ��
	*e=S->next->data;
	return 1;
}
//��ջ������
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
//��ջ�������൱����ͷ��������һ�����
int push(linkstack *S,ElemType x){
	linkstack *p;
	p=(linkstack *)malloc(sizeof(linkstack));
	if(!p)return 0;//�����䲻�ɹ�����0
	p->data=x;
	p->next=S->next;
	S->next=p;
	return 1;
}
//��ջ�������൱����ͷ����ɾ��һ����㣬*e����ɾ�����Ԫ��
int pop(linkstack *S,ElemType *e){
 	linkstack *p;
	if(S->next==NULL)return 0;//ջ�գ���ջʧ��
	p=S->next;
	*e=p->data;
	S->next=p->next;
	free(p);
	return 1;
}
//��ջ�ղ������ж�ջ�Ƿ�Ϊ�գ�
int emptystack(linkstack *S){
	if(S->next==NULL)return 1;
	else return 0;
}
//���ջ����������ջ��
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

