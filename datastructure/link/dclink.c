/*
 * dclink.c
 *
 *  Created on: 2018��11��27��
 *      Author: Jinjin
 */

#include<stdio.h>
#include<malloc.h>
//˫��ѭ������ı�ʾ��ʵ�֣���ͷ���
typedef int ElemType;
typedef struct node{
	struct node *next;
	struct node *prior;
	ElemType data;
}dlink;
//����ѭ������
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
//����������������������
dlink *showdlink(dlink *head){
	dlink *p;
	p=head->next;
	while(p!=head){
		printf("%d ",p->data);
		p=p->next;
	}
	return head;
}

//���������
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
//ɾ��������ɾ����ͷ����˫��ѭ������ĵ�i�����
int deletei(dlink *head,int i){
	dlink *p,*s;
	int j;
	p=head->next;j=1;
	if(i<1)return 0;//δɾ���ɹ�
	while(p!=head&&j<i-1){
		p=p->next;
		j++;
	}
	if(p==head)return 0;
	s=p->next;
	p->next=s->next;
	s->next->prior=p;
	free(s);
	return 1;//ɾ���ɹ�
}
//��������������ͷ����˫��ѭ�������i�����ǰ����һ�����
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
	printf("�������Ϊ��%d\n",getlen(head));
//	deletei(head,3);//ɾ����3�����
//	insertx(head,3,9);//�ڵ�3�����ǰ����9
	showdlink(head);
}
*/
