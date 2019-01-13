///*
// * sqstack.c
// *
// *  Created on: 2018年11月27日
// *      Author: Jinjin
// */
///*
//	顺序栈的表示和实现
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
////初始化操作
//void initstack(sqstack *S){
//	S->base=(ElemType *)malloc(INITSIZE*sizeof(ElemType));
//	S->top=0;
//	S->stacksize=INITSIZE;
//}
////求表长操作
//int getlen(sqstack *S){
//	return (S->top);
//}
//
////取栈顶元素
//int gettop(sqstack *S,ElemType *e){
//	*e=S->base[S->top-1];
//	return 1;
//}
////入栈操作
//int push(sqstack *S,ElemType x){
//	if(S->top>=S->stacksize){
//		S->base=(ElemType *)realloc(S->base,(S->stacksize+1)*sizeof(ElemType));
//		if(!S->base)return 0;//空间分配不成功，返回0
//		S->stacksize++;
//	}//栈满，申请空间
//	S->base[S->top++]=x;
//	return 1;
//}
////出栈操作
//int pop(sqstack *S,ElemType *e){
//	if(S->top==0)return 0;//栈空
//	*e=S->base[--S->top];//先将指针减1，再返回栈顶元素值
//	return 1;
//}
////判断栈是否为空
//int emptystack(sqstack *S){
//	if(S->top==0)return 1;
//	return 0;
//}
////输出栈操作
//void list(sqstack *S){
//	int i;
//	for(i=S->top-1;i>=0;i--){
//		printf("%d",S->base[i]);
//	}
//	printf("\n");
//}
///*int main(){
//	sqstack s;//如果是sqstack *S
//	initstack(&s);//initstack(S);则是错误的
//	printf("%d\n",emptystack(&s));
//	printf("%d\n",push(&s,3));
//	list(&s);
//}
//*/
