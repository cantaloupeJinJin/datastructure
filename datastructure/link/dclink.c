/*
 * dclink.c
 *
 *  Created on: 2018年11月27日
 *      Author: Jinjin
 */

#include<stdio.h>
#include<malloc.h>
//双向循环链表的表示和实现，带头结点
typedef int ElemType;
typedef struct node{
	struct node *next;
	struct node *prior;
	ElemType data;
}dlink;
//创建循环链表
dlink *creatdlink(int n){
	dlink *head,*p,*s;
	int i;
	p=head=(dlink *)malloc(sizeof(dlink));
	for(i=1;i<=n;i++){
		 s=(dlink *)malloc(sizeof(dlink));
		 scanf("%d",&s->data);
		 p->next=s;
		 s->prior=p;
		 p=s;
	}
	p->next=head;
	head->prior=p;
	return head;
}
//输出操作，从正向输出链表
dlink *showdlink(dlink *head){
	dlink *p;
	p=head->next;
	while(p!=head){
		printf("%d ",p->data);
		p=p->next;
	}
	return head;
}

//求表长操作，
int getlen(dlink *head){
	int i;
	dlink *p;
	p=head->next;i=0;
	while(p!=head){
		p=p->next;
		i++;
	}
	return i;
}
//删除操作，删除带头结点的双向循环链表的第i个结点
int deletei(dlink *head,int i){
	dlink *p,*s;
	int j;
	p=head->next;j=1;
	if(i<1)return 0;//未删除成功
	while(p!=head&&j<i-1){
		p=p->next;
		j++;
	}
	if(p==head)return 0;
	s=p->next;
	p->next=s->next;
	s->next->prior=p;
	free(s);
	return 1;//删除成功
}
//插入操作，向带有头结点的双向循环链表第i个结点前插入一个结点
int insertx(dlink *head,int i,ElemType x){
	dlink *p,*s;
	int j;
	p=head->next;j=1;
	if(i<1)return 0;
	while(p!=head&&j<i-1){
		p=p->next;
		j++;
	}
	if(p==head)return 0;
	s=(dlink *)malloc(sizeof(dlink));
	s->data=x;
	s->next=p->next;
	s->prior=p;
	p->next->prior=s;
	p->next=s;
	return 1;
}
/*int main(){
	dlink *head;
	head=creatdlink(5);
	showdlink(head);
	printf("该链表表长为：%d\n",getlen(head));
//	deletei(head,3);//删除第3个结点
//	insertx(head,3,9);//在第3个结点前插入9
	showdlink(head);
}
*/
