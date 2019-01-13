/*
 * dlink.c
 *
 *  Created on: 2018年11月27日
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

//建立双链表
dlink * credlink(int n){
	dlink *head,*p,*s;int i;
	p=head=(dlink * )malloc(sizeof(dlink));
	for(i=1;i<=n;i++){
		s=(dlink * )malloc(sizeof(dlink));
		printf("请输入数字!");
		scanf("%d",&s->data);
		s->prior=p;
		p->next=s;
		p=s;
	}
	p->next=head->prior=NULL;
	return head;
}
//遍历双链表,和单链表相同
dlink *showlink(dlink *head){
	dlink *p;
	p=head->next;//p=head
	while(p!=NULL){//p->next!=NULL,如果写成这样，输出结果是错误的
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

//求表长操作
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
//取元素操作（取出双链表head中第i个结点的值）
int getelem(dlink *head,int i){
	dlink *p,*s;
	int j;
	int e;
	p=head->next;j=1;
	if(i<1)return 0;//判断i结点的合法性
	while(p!=NULL&&j<i){
		p=p->next;
		j=j+1;
	}
	if(p==NULL)return 0;//结点i超过表长
	e=p->data;
	return e;
}

//删除节点（删除双链表中第i个节点）
dlink *deletei(dlink *head,int i){
	dlink *p,*s;
	int j;
	p=head->next;j=1;
	if(i<1)return 0;//判断i结点的合法性
	while(p!=NULL&&j<i-1){
		p=p->next;
		j=j+1;
	}
	if(p->next==NULL)return 0;//结点i超过表长
	s=p->next;
	s->next->prior=p;
	p->next=s->next;
	free(s);
	return head;
}

//定位操作（返回双链表中第1个为值为x的结点的位置）
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

//插入操作（在双链表中第i个结点之前插入一个值为x的结点）
int insertx(dlink *head,ElemType x,int i){
	dlink *p,*s;
	int j=1;
	p=head->next;
	s=(dlink * )malloc(sizeof(dlink));
	if(i<1)return 0;//插入失败
	while(p!=NULL&&j<i-1){
		p=p->next;
		j=j+1;
	}
	if(p==NULL)return 0;//插入失败，插入位置超出表长
	s->data=x;
	s->next=p->next;
	s->prior=p;
	p->next->prior=s;
	p->next=s;
	return 1;
}
//输出操作（从反方向输出双链表中各个结点的值）
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
	printf("请输入数字输入个数：");
	scanf("%d",&n);
	//创建双链表
	head = credlink(n);
	//遍历双链表
	showlink(head);
	//获取表长
//	printf("该双链表表长为：%d",getlen(head));
//	printf("请输入取出第i个结点\n");
//	scanf("%d",&i);
//	//取节点
//	printf("所取元素为：%d",getelem(head,i));
//	printf("请输入要删除的结点i\n");
//	scanf("%d",&i);
//	deletei(head,i);
//	printf("删除后剩余链表为：\n");
//	showlink(head);
//	printf("请输入你想找到位置的x的值");
//	scanf("%d",&x);
//	printf("该位置为:%d",locate(head,x));
//    printf("请输入插入数值x以及插入位置i");
//    scanf("%d%d",&x,&i);
//    insertx(head,x,i);
//    showlink(head);
	invertshow(head);

}
*/
