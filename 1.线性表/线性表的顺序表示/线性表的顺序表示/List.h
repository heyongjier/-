#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 100 //线性表存储空间的初始分配量
#define LISTINCREMENT 10 //线性表存储空间的分配增量
#define OK 1
#define ERROR 0

typedef int Status;
typedef struct  {
	int* elem; //存储空间的基址
	int length; //线性表当前的长度
	int listSize; //当前线性表分配的存储容量
}SqList ;


SqList InitList(void); //初始化一个线性表
SqList ListInsert(SqList L, int i, int e); //在第i个位置之前插入一个值为e的数据元素
SqList DelList(SqList, int i); //删除指定位置的元素
int LocalList(SqList L, int e); //返回一个值在该表中第一次出现的位置
Status PrintList(SqList L); //将表中数据全部打印输出