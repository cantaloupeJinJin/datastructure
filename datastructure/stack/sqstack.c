///*
// * sqstack.c
// *
// *  Created on: 2018��11��27��
// *      Author: Jinjin
// */
///*
//	˳��ջ�ı�ʾ��ʵ��
//*/
//
//#include<stdio.h>
//#include<malloc.h>
//#define INITSIZE 100
//typedef int ElemType;
//typedef struct{
//	int top;
//	ElemType *base;
//	int stacksize;
//}sqstack;
//
////��ʼ������
//void initstack(sqstack *S){
//	S->base=(ElemType *)malloc(INITSIZE*sizeof(ElemType));
//	S->top=0;
//	S->stacksize=INITSIZE;
//}
////�������
//int getlen(sqstack *S){
//	return (S->top);
//}
//
////ȡջ��Ԫ��
//int gettop(sqstack *S,ElemType *e){
//	*e=S->base[S->top-1];
//	return 1;
//}
////��ջ����
//int push(sqstack *S,ElemType x){
//	if(S->top>=S->stacksize){
//		S->base=(ElemType *)realloc(S->base,(S->stacksize+1)*sizeof(ElemType));
//		if(!S->base)return 0;//�ռ���䲻�ɹ�������0
//		S->stacksize++;
//	}//ջ��������ռ�
//	S->base[S->top++]=x;
//	return 1;
//}
////��ջ����
//int pop(sqstack *S,ElemType *e){
//	if(S->top==0)return 0;//ջ��
//	*e=S->base[--S->top];//�Ƚ�ָ���1���ٷ���ջ��Ԫ��ֵ
//	return 1;
//}
////�ж�ջ�Ƿ�Ϊ��
//int emptystack(sqstack *S){
//	if(S->top==0)return 1;
//	return 0;
//}
////���ջ����
//void list(sqstack *S){
//	int i;
//	for(i=S->top-1;i>=0;i--){
//		printf("%d",S->base[i]);
//	}
//	printf("\n");
//}
///*int main(){
//	sqstack s;//�����sqstack *S
//	initstack(&s);//initstack(S);���Ǵ����
//	printf("%d\n",emptystack(&s));
//	printf("%d\n",push(&s,3));
//	list(&s);
//}
//*/
