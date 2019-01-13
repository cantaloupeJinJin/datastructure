/*
 * sclink.c
 *
 *  Created on: 2018年11月27日
 *      Author: Jinjin
 */


#include<stdio.h>
#include<malloc.h>

//单向循环链表的表示与实现（该链表带头结点head）
typedef int ElemType;
typedef struct node{
	ElemType data;
	struct node * next;
}slink;

//创建链表
slink *creasclink(int n){
	slink *head,*p,*s;
	int i;
	p=head=(slink*)malloc(sizeof(slink));
	for(i=1;i<=n;i++){
		s=(slink*)malloc(sizeof(slink));
		scanf("%d",&s->data);
		p->next = s;
		p=s;
	}
	p->next=head;
	return head;
}
//遍历链表
slink *showsclink(slink *head){
	slink *p;
	p=head->next;
	while(p!=head){
		printf("%d ",p->data);
		p=p->next;
	}
	return head;
}
//求表长操作
int getlen(slink *head){
	slink *p;
	int i=0;
	p=head->next;
	while(p!=head){
		i++;
		p=p->next;
	}
	return i;
}
//取元素操作,取第i个结点的元素的值
int getElem(slink *head,int i){
	int j;
	slink *p;
	p=head->next;j=1;
	if(i<1)return 0;
	while(p!=head&&j<i){
		p=p->next;
		j=j+1;
	}
	if(p==head)return 0;
	return p->data;
}
//定位操作，取链表中第一个值为x 的位置
int locate(slink *head,ElemType x){
	int i;
	slink *p;
	p=head->next;i=1;
	while(p!=head&&p->data!=x){
		p=p->next;
		i++;
	}
	if(p==head)return 0;
	else return i;
}

//删除操作，删除单链表中的第i个结点
int deletei(slink *head,int i){
	slink *p,*s;
	int j;
	p=head->next;j=1;
	if(i<1)return 0;
	while(p!=head&&j<i-1){
		p=p->next;
		j++;
	}
	if(p==head||p->next==head)return 0;//i长于表长
	s=p->next;
	p->next=s->next;
	free(s);
	return 1;
}
//插入操作（在链表中第i个结点之前插入一个值为x的结点）
int inserti(slink *head,ElemType x,int i){
	slink *p,*s;
	int j;
	p=head->next;j=1;
	s=(slink *)malloc(sizeof(slink));
	if(i<1)return 0;//结点不合法
	while(p!=head&&j<i-1){
		p=p->next;
		j++;
	}
	if(p==head||p->next==head)return 0;
	s->data=x;
	s->next=p->next;
	p->next=s;
	return 1;
}
/*int main(){
	slink *head;
	int i;
	head=creasclink(4);
//	showsclink(head);
//	printf("该链表表长为：%d",getlen(head));

//    scanf("%d",&i);
//    printf("该位置元素为：%d",locate(head,i));

//    deletei(head,3);
//	inserti(head,9,3);
}
*/
