/*
 * linkstr.c
 *
 *  Created on: 2019年1月13日
 *      Author: Jinjin
 */
/*解决Symbol 'NULL' could not be resolved问题*/
#ifndef NULL
#define NULL   ((void *) 0)
#endif
/**/

typedef struct node
{
	char ch;
	struct node * next;
}linkstr;
/*基本操作再链串上的实现*/

/*初始化操作,创建一个只含有头结点的空链串*/
linkstr * initstring()
{
	linkstr * s;
	s = (linkstr *)malloc(sizeof(linkstr));
	s->next = NULL;
	return s;
}

/*串赋值操作，将一个字符串常量t赋给一个字符串变量s*/
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
		else{//存储空间不足
			p = (linkstr *)malloc(sizeof(linkstr));
			p->ch = t[i];
			r->next = p;
			r = p;
		}
	//赋值完后，s有多余的空间
	r->next = NULL;
	while(q!=NULL){
		p = q->next;free(q);
		q = p;
	}
	}

}
/*串复制操作，将串变量t的值赋给串变量s*/
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
/*求长度*/
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

/*判等操作，判断两个串s和t是否相等，若相等返回1，若不相等，则返回0*/
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
连接操作，将串s2连接到串s1的后面，结果存到串s中*/
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

/*取字串操作，将串t的从第i个字符开始的连续j个字符存到s中*/
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

/*插入操作，在串s中的第i个位置之前插入子串t*/
int insert(linkstr * s,int i,linkstr * t){
	int k;
	linkstr * p,* q,* r,* u;
	p = s->next;r = t->next;
	q = s;
	if(i<=0||i>length(s)+1)return 0;
	for(k=1;k<i;k++){//找到第i个位置之前
		q = p;
		p = p->next;
	}
	while(r->next!=NULL){//
		r = r->next;
	}
	u = r;//找到t最后一个节点
	u->next = p;
	q->next = t->next;
	return 1;
}

/*删除操作，删除串s的从第i个字符开始的连续j个字符*/
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

/*替换操作，将链串s的从第i个字符开始的连续j个字符用串t替换。*/
int replace(linkstr * s,int i,int j,linkstr * t)
{
	linkstr * p,* q,* u,* r,* m;
		int k;
		p = s->next;q = s;m = t->next;
		if(i<=0||i>length(s)||j<=0||j>length(s)-i+1)return 0;
		for(k=1;k<i;k++){//找到第i个字符
			q = p;
			p = p->next;
		}
		r = q;//第i个字符前一个节点
		while(j>0){//删除第i个字符开始的连续j个字符
			u = p;
			p = p->next;
			q->next = p;
			free(u);
			j--;
		}
		while(m->next!=NULL){//找到t串最后一个节点
			m = m->next;
		}
		m->next = p;//将t串加入s串
		r->next = t->next;
		return 1;
}

/*输出操作*/
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
