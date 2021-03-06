/*

 * sqstring.c
 *
 *  Created on: 2018年11月27日
 *      Author: Jinjin

#include<stdio.h>
#include<malloc.h>
#define INITSTRLEN 100
typedef struct
{
	char *ch;
	int length;
	int strsize;
}string;

 * 初始化操作，创建一个空串s

void initstring(string * s)
{
	s->ch = (char *)malloc(INITSTRLEN*sizeof(char));
	s->length = 0;
	s->strsize = INITSTRLEN;
}

 * 串赋值操作（将字符串常量s2赋给字符串变量s1）

void strassign(string * s1,char  * s2)
{
	int i;
	i = 0;
	while(s2[i]!='\0')i++;
	if(i>s1->strsize){
		s1->ch =(char *)realloc(s1->ch,i*sizeof(char)); //存储空间不够，增加空间
		s1->strsize = i;
	}
	s1->length = i;
	for(i=0;i<s1->length;i++){
		s1->ch[i] = s2[i];
	}
}

 * 串复制操作（将字符串变量s2的值赋给字符串变量s1的值）

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

 * 求串长操作

int length(string *s)
{
	return s->length;
}

 * 串连接操作（将字符串s1和s2连接后存到串s中）

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

 * 判串等操作（判断两个字符串s和t是否相等，包括长度和对应字符，若相等返回1，否则返回0）

int equal(string *s,string *t)
{
	int i;
	for(i=0;i<s->length&&i<t->length;i++){
		if(s->ch[i]!=t->ch[i])return 0;
	}
	if(i<s->length||i<t->length)return 0;
	else return 1;
}

 * 取子串操作（在字符串s中，把从第i个字符开始的连续 j个字符存到字符串t中）

int substr(string *s,int i,int j,string *t)
{
	int k;
	if(i>j||i<=0||j<0||j>s->length-i+1)return 0;//i，j不合法
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

 * 串替换操作（把字符串s的第i个字符开始的j个连续字符用字符串t替换）

int replace(string *s,int i,int j,string *t)
{
	int k,m;
	if(i<=0||i>s->length||j<=0||j>s->length-i+1)return 0;
	if(j<t->length){//替换字符长度大于原字符串长度
		if(s->length+t->length-j>s->strsize){//存储空间不足
			s->ch = (char *)realloc(s->ch,(s->length-j+t->length)*sizeof(char));
			s->strsize = s->length + t->length - j;
		}
		//需要后移
		for(k=s->length-1;k>=i+j-1;k--){
			s->ch[k-j+t->length] = s->ch[k];
		}
	}
	else{//替换字符串长度小于等于原字符串长度
		//需要前移
		for(k=i-1+j;k<s->length;k++){
			s->ch[k-j+t->length] = s->ch[k];
		}
	}
	s->length = s->length+t->length-j;
	for(k=0;k<t->length;k++)
		s->ch[k+i-1] = t->ch[k];
	return 1;
}


 * 在字符串s 的第i个字符之前插入字符串t

int insert(string * s,int i,string *t)
{
	int j;
	if(i<=0||i>s->length+1)return 0;
	if(s->strsize<s->length+t->length){
		s->ch = (char *)realloc(s->ch,(s->length+t->length)*sizeof(char));
		s->strsize = s->length+t->length;
	}
	//位置后移
	for(j=s->length-1;j>=i-1;j--){
		s->ch[j+t->length] = s->ch[j];
	}
	//复制
	for(j=0;j<t->length;j++){
		s->ch[i+j-1]=t->ch[j];
	}
	s->length+=t->length;
	return 1;
}


 * 删除操作，
 * 在字符串中，
 * 删除从第i个字符开始的连续j个字符
 *
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
	printf("s1字符串为：\n");
	list(&s1);
	printf("s字符串为：\n");
	list(&s);
	printf("&&");
	printf("删除t字符串后为：\n");
	delete(&s,2,3);
	list(&s);
}




*/
