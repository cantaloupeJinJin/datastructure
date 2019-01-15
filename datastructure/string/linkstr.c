/*
 * linkstr.c
 *
 *  Created on: 2019��1��13��
 *      Author: Jinjin
 */
/*���Symbol 'NULL' could not be resolved����*/
#ifndef NULL
#define NULL   ((void *) 0)
#endif
/**/

typedef struct node
{
	char ch;
	struct node * next;
}linkstr;
/*���������������ϵ�ʵ��*/

/*��ʼ������,����һ��ֻ����ͷ���Ŀ�����*/
linkstr * initstring()
{
	linkstr * s;
	s = (linkstr *)malloc(sizeof(linkstr));
	s->next = NULL;
	return s;
}

/*����ֵ��������һ���ַ�������t����һ���ַ�������s*/
void strassign(linkstr * s,char * t)
{
	int i;
	linkstr * p,* q,* r;
	r = s;q = s->next;
	for(i=0;t[i]!='\0';i++){
		if(q!=NULL){
			q->ch = t[i];
			r = q;
			q = q->next;
		}
		else{//�洢�ռ䲻��
			p = (linkstr *)malloc(sizeof(linkstr));
			p->ch = t[i];
			r->next = p;
			r = p;
		}
	//��ֵ���s�ж���Ŀռ�
	r->next = NULL;
	while(q!=NULL){
		p = q->next;free(q);
		q = p;
	}
	}

}
/*�����Ʋ�������������t��ֵ����������s*/
void  assign(linkstr * s,linkstr * t)
{
	  linkstr * p,* q,* r,* u;
	  p = s->next;r = t->next;q = s;
	  while(r!=NULL){
		  if(p!=NULL){
			  p->ch = r->ch;
			  q = p;
			  p = p->next;
		  }
		  else{
			  u = (linkstr *)malloc(sizeof(linkstr));
			  u->ch = r->ch;
			  q->next = u;
			  q = u;
		  }
		  r = r->next;
	  }
	  q->next = NULL;
	  while(p!=NULL){
		  q = p->next;
		  free(q);
		  q = p;
	  }
}
/*�󳤶�*/
int length(linkstr * s){
	linkstr * p;
	int i = 0;
	p = s->next;
	while(p!=NULL){
		i++;
		p = p->next;
	}
	return i;
}

/*�еȲ������ж�������s��t�Ƿ���ȣ�����ȷ���1��������ȣ��򷵻�0*/
int equal(linkstr * s,linkstr * t){
	linkstr * p,* q;
	int i,j;
	p = s->next;q = t->next;i=j=0;
	while(p!=NULL&&q!=NULL){
		if(p->ch!=q->ch)return 0;
		else p = p->next;q = q->next;
	}
	if(q!=NULL||p!=NULL)return 0;
	else return 1;
}
/*
���Ӳ���������s2���ӵ���s1�ĺ��棬����浽��s��*/
void concat(linkstr *s1,linkstr * s2,linkstr * s){
	linkstr * p,* q,* r,* u;
	p = s->next;r = s1->next;q = s;
	while(r!=NULL){
		if(p!=NULL){
			p->ch = r->ch;
		    q = p;
			p = p->next;
			  }
		else{
			u = (linkstr *)malloc(sizeof(linkstr));
			u->ch = r->ch;
			q->next = u;
		    q = u;
			 }
			 r = r->next;
	}
	r = s2->next;
	while(r!=NULL){
			if(p!=NULL){
				p->ch = r->ch;
			    q = p;
				p = p->next;
				  }
			else{
				u = (linkstr *)malloc(sizeof(linkstr));
				u->ch = r->ch;
				q->next = u;
			    q = u;
				 }
				 r = r->next;
		}
		  q->next = NULL;
		  while(p!=NULL){
			  q = p->next;
			  free(q);
			  q = p;
		  }
}

/*ȡ�ִ�����������t�Ĵӵ�i���ַ���ʼ������j���ַ��浽s��*/
int substr(linkstr * s,int i, int j,linkstr * t){
	 linkstr * p,* q,* r,* u;
	 int k = 1,m = 0;
	 p = s->next;r = t->next;q = s;
	 if(i<=0||i>length(t)||j<=0||i+j-1>length(t))return 0;
	 while(k<i){
		 k++;
		 r = r->next;
	 }
		  while(r!=NULL&&m<j){
			  if(p!=NULL){
				  p->ch = r->ch;
				  q = p;
				  p = p->next;
			  }
			  else{
				  u = (linkstr *)malloc(sizeof(linkstr));
				  u->ch = r->ch;
				  q->next = u;
				  q = u;
			  }
			  r = r->next;
			  m++;
		  }
		  q->next = NULL;
		  while(p!=NULL){
			  q = p->next;
			  free(q);
			  q = p;
		  }
		  return 1;
}

/*����������ڴ�s�еĵ�i��λ��֮ǰ�����Ӵ�t*/
int insert(linkstr * s,int i,linkstr * t){
	int k;
	linkstr * p,* q,* r,* u;
	p = s->next;r = t->next;
	q = s;
	if(i<=0||i>length(s)+1)return 0;
	for(k=1;k<i;k++){//�ҵ���i��λ��֮ǰ
		q = p;
		p = p->next;
	}
	while(r->next!=NULL){//
		r = r->next;
	}
	u = r;//�ҵ�t���һ���ڵ�
	u->next = p;
	q->next = t->next;
	return 1;
}

/*ɾ��������ɾ����s�Ĵӵ�i���ַ���ʼ������j���ַ�*/
int delete(linkstr * s,int i,int j){
	linkstr * p,* q,* u;
	int k;
	p = s->next;q = s;
	if(i<=0||i>length(s)||j<=0||j>length(s)-i+1)return 0;
	for(k=1;k<i;k++){
		q = p;
		p = p->next;
	}
	while(j>0){
		u = p;
		p = p->next;
		q->next = p;
		free(u);
		j--;
	}
	return 1;
}

/*�滻������������s�Ĵӵ�i���ַ���ʼ������j���ַ��ô�t�滻��*/
int replace(linkstr * s,int i,int j,linkstr * t)
{
	linkstr * p,* q,* u,* r,* m;
		int k;
		p = s->next;q = s;m = t->next;
		if(i<=0||i>length(s)||j<=0||j>length(s)-i+1)return 0;
		for(k=1;k<i;k++){//�ҵ���i���ַ�
			q = p;
			p = p->next;
		}
		r = q;//��i���ַ�ǰһ���ڵ�
		while(j>0){//ɾ����i���ַ���ʼ������j���ַ�
			u = p;
			p = p->next;
			q->next = p;
			free(u);
			j--;
		}
		while(m->next!=NULL){//�ҵ�t�����һ���ڵ�
			m = m->next;
		}
		m->next = p;//��t������s��
		r->next = t->next;
		return 1;
}

/*�������*/
void list(linkstr * s)
{
	linkstr * p;
	p = s->next;
	while(p!=NULL){
		printf("%c ",p->ch);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	linkstr * s,* s1,* s3;
	char * t1;
	char * t2;
	t1 = "hello";
	t2 = "world";
	s = initstring();
	s1 = initstring();
	s3 = initstring();
	strassign(s,t1);
	strassign(s1,t2);
	replace(s,2,3,s1);
	list(s);
}
