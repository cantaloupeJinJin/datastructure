/*
 * dlink.c
 *
 *  Created on: 2018��11��27��
 *      Author: Jinjin
 */

#include<stdio.h>
#include<malloc.h>
typedef int ElemType;
typedef struct node{
	ElemType data;
	struct node *next;
	struct node *prior;
	}dlink;

//����˫����
dlink * credlink(int n){
	dlink *head,*p,*s;int i;
	p=head=(dlink * )malloc(sizeof(dlink));
	for(i=1;i<=n;i++){
		s=(dlink * )malloc(sizeof(dlink));
		printf("����������!");
		scanf("%d",&s->data);
		s->prior=p;
		p->next=s;
		p=s;
	}
	p->next=head->prior=NULL;
	return head;
}
//����˫����,�͵�������ͬ
dlink *showlink(dlink *head){
	dlink *p;
	p=head->next;//p=head
	while(p!=NULL){//p->next!=NULL,���д���������������Ǵ����
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

//�������
int getlen(dlink *head){
	dlink *p;
	int len=0;
	p=head->next;
	while(p!=NULL){
		len+=1;
		p=p->next;
	}
	return len;
}
//ȡԪ�ز�����ȡ��˫����head�е�i������ֵ��
int getelem(dlink *head,int i){
	dlink *p,*s;
	int j;
	int e;
	p=head->next;j=1;
	if(i<1)return 0;//�ж�i���ĺϷ���
	while(p!=NULL&&j<i){
		p=p->next;
		j=j+1;
	}
	if(p==NULL)return 0;//���i������
	e=p->data;
	return e;
}

//ɾ���ڵ㣨ɾ��˫�����е�i���ڵ㣩
dlink *deletei(dlink *head,int i){
	dlink *p,*s;
	int j;
	p=head->next;j=1;
	if(i<1)return 0;//�ж�i���ĺϷ���
	while(p!=NULL&&j<i-1){
		p=p->next;
		j=j+1;
	}
	if(p->next==NULL)return 0;//���i������
	s=p->next;
	s->next->prior=p;
	p->next=s->next;
	free(s);
	return head;
}

//��λ����������˫�����е�1��ΪֵΪx�Ľ���λ�ã�
int locate(dlink *head,ElemType x){
	dlink *p;
	int i;
	i=1;
	p=head->next;
	while(p!=NULL&&p->data!=x){
		p=p->next;
		i=i+1;
	}
	if(p==NULL)return 0;
	return i;
	//return p;
}

//�����������˫�����е�i�����֮ǰ����һ��ֵΪx�Ľ�㣩
int insertx(dlink *head,ElemType x,int i){
	dlink *p,*s;
	int j=1;
	p=head->next;
	s=(dlink * )malloc(sizeof(dlink));
	if(i<1)return 0;//����ʧ��
	while(p!=NULL&&j<i-1){
		p=p->next;
		j=j+1;
	}
	if(p==NULL)return 0;//����ʧ�ܣ�����λ�ó�����
	s->data=x;
	s->next=p->next;
	s->prior=p;
	p->next->prior=s;
	p->next=s;
	return 1;
}
//����������ӷ��������˫�����и�������ֵ��
dlink *invertshow(dlink *head){
	dlink *p,*s;
	int j=1;
	p=head;
	while(p->next!=NULL){
		p=p->next;
	}
	while(p!=head){
		printf("%d ",p->data);
		p=p->prior;
	}
}

/*int main(){
	dlink *head;
	int n,i,x;
	head = NULL;
	printf("�������������������");
	scanf("%d",&n);
	//����˫����
	head = credlink(n);
	//����˫����
	showlink(head);
	//��ȡ��
//	printf("��˫�����Ϊ��%d",getlen(head));
//	printf("������ȡ����i�����\n");
//	scanf("%d",&i);
//	//ȡ�ڵ�
//	printf("��ȡԪ��Ϊ��%d",getelem(head,i));
//	printf("������Ҫɾ���Ľ��i\n");
//	scanf("%d",&i);
//	deletei(head,i);
//	printf("ɾ����ʣ������Ϊ��\n");
//	showlink(head);
//	printf("�����������ҵ�λ�õ�x��ֵ");
//	scanf("%d",&x);
//	printf("��λ��Ϊ:%d",locate(head,x));
//    printf("�����������ֵx�Լ�����λ��i");
//    scanf("%d%d",&x,&i);
//    insertx(head,x,i);
//    showlink(head);
	invertshow(head);

}
*/
