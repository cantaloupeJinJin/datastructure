/*
 * sqstring.c
 *
 *  Created on: 2018��11��27��
 *      Author: Jinjin
 */
#include<stdio.h>
#include<malloc.h>
#define INITSTRLEN 100
typedef struct
{
	char *ch;
	int length;
	int strsize;
}string;
/*
 * ��ʼ������������һ���մ�s
 */
void initstring(string * s)
{
	s->ch = (char *)malloc(INITSTRLEN*sizeof(char));
	s->length = 0;
	s->strsize = INITSTRLEN;
}
/*
 * ����ֵ���������ַ�������s2�����ַ�������s1��
 */
void strassign(string * s1,char  * s2)
{
	int i;
	i = 0;
	while(s2[i]!='\0')i++;
	if(i>s1->strsize){
		s1->ch =(char *)realloc(s1->ch,i*sizeof(char)); //�洢�ռ䲻�������ӿռ�
		s1->strsize = i;
	}
	s1->length = i;
	for(i=0;i<s1->length;i++){
		s1->ch[i] = s2[i];
	}
}
/*
 * �����Ʋ��������ַ�������s2��ֵ�����ַ�������s1��ֵ��
 */
void assign(string * s1,string * s2)
{
	int i;
	if(s1->strsize<s2->length){
		s1->ch = (char *)realloc(s1->ch,s2->length*sizeof(char));
		s1->strsize = s2->length;
	}
	s1->length = s2->length;
	for(i=0;i<s1->length;i++){
		s1->ch[i] = s2->ch[i];
	}
}
/*
 * �󴮳�����
 */
int length(string *s)
{
	return s->length;
}
/*
 * �����Ӳ��������ַ���s1��s2���Ӻ�浽��s�У�
 */
void concat(string * s1,string * s2,string * s)
{
	int i;
	if((s1->length+s2->length)>s->strsize){
		s->ch = (char *)realloc(s->ch,(s1->length+s2->length)*sizeof(char));
		s->strsize = s1->length + s2->length;
	}
	s->length = s1->length + s2->length;
	for(i=0;i<s1->length;i++){
		s->ch[i] = s1->ch[i];
	}
	for(;i<s->length;i++){
		s->ch[i] = s2->ch[i-s1->length];
	}
}
/*
 * �д��Ȳ������ж������ַ���s��t�Ƿ���ȣ��������ȺͶ�Ӧ�ַ�������ȷ���1�����򷵻�0��
 */
int equal(string *s,string *t)
{
	int i;
	for(i=0;i<s->length&&i<t->length;i++){
		if(s->ch[i]!=t->ch[i])return 0;
	}
	if(i<s->length||i<t->length)return 0;
	else return 1;
}
/*
 * ȡ�Ӵ����������ַ���s�У��Ѵӵ�i���ַ���ʼ������ j���ַ��浽�ַ���t�У�
 */
int substr(string *s,int i,int j,string *t)
{
	int k;
	if(i>j||i<=0||j<0||j>s->length-i+1)return 0;//i��j���Ϸ�
	if(j>t->strsize){
		t->ch = (char *)realloc(t->ch,j*sizeof(char));
		t->strsize = j;
	}
	for(k=0;k<j;k++){
		t->ch[k] = s->ch[k+i-1];
	}
	t->length = j;
	return 1;
}
/*
 * ���滻���������ַ���s�ĵ�i���ַ���ʼ��j�������ַ����ַ���t�滻��
 */
int replace(string *s,int i,int j,string *t)
{
	int k,m;
	if(i<=0||i>s->length||j<=0||j>s->length-i+1)return 0;
	if(j<t->length){//�滻�ַ����ȴ���ԭ�ַ�������
		if(s->length+t->length-j>s->strsize){//�洢�ռ䲻��
			s->ch = (char *)realloc(s->ch,(s->length-j+t->length)*sizeof(char));
			s->strsize = s->length + t->length - j;
		}
		//��Ҫ����
		for(k=s->length-1;k>=i+j-1;k--){
			s->ch[k-j+t->length] = s->ch[k];
		}
	}
	else{//�滻�ַ�������С�ڵ���ԭ�ַ�������
		//��Ҫǰ��
		for(k=i-1+j;k<s->length;k++){
			s->ch[k-j+t->length] = s->ch[k];
		}
	}
	s->length = s->length+t->length-j;
	for(k=0;k<t->length;k++)
		s->ch[k+i-1] = t->ch[k];
	return 1;
}

/*
 * ���ַ���s �ĵ�i���ַ�֮ǰ�����ַ���t
 */
int insert(string * s,int i,string *t)
{
	int j;
	if(i<=0||i>s->length+1)return 0;
	if(s->strsize<s->length+t->length){
		s->ch = (char *)realloc(s->ch,(s->length+t->length)*sizeof(char));
		s->strsize = s->length+t->length;
	}
	//λ�ú���
	for(j=s->length-1;j>=i-1;j--){
		s->ch[j+t->length] = s->ch[j];
	}
	//����
	for(j=0;j<t->length;j++){
		s->ch[i+j-1]=t->ch[j];
	}
	s->length+=t->length;
	return 1;
}

/*
 * ɾ��������
 * ���ַ����У�
 * ɾ���ӵ�i���ַ���ʼ������j���ַ�
 * */
int delete(string * s,int i,int j)
{
	int k;
	if(i<=0||i>s->length+1||j<=0||j>s->length-i+1)return 0;
	for(k=i+j-1;k<s->length;k++){
		s->ch[k-j] = s->ch[k];
	}
	s->length = s->length-j;
	return 1;
}


void list(string * s)
{
	int i;
	for(i=0;i<s->length;i++){
		printf("%c ",s->ch[i]);
	}
	printf("\n");
}

int  main()
{
	int len = 0;
	string s1,s2,s,s3,s4,t;
	char *c2 = "hello";
	char *c1 = "world";
	initstring(&s1);
	initstring(&s2);
	initstring(&s);
	initstring(&t);
	strassign(&s1,c2);
	assign(&s2,&s1);
	concat(&s1,&s2,&s);
	printf("s1�ַ���Ϊ��\n");
	list(&s1);
	printf("s�ַ���Ϊ��\n");
	list(&s);
	printf("&&");
	printf("ɾ��t�ַ�����Ϊ��\n");
	delete(&s,2,3);
	list(&s);
}
























