#include "List.h"

SqList InitList(void)
{
	SqList L;
	L.elem = (int*)malloc(LIST_INIT_SIZE * sizeof(int));
	if (!L.elem)
	{
		printf("分配空间失败，初始化错误");
		exit;
	}
	L.length = 0;
	L.listSize = LIST_INIT_SIZE;
	return L;
}
SqList ListInsert(SqList L, int i, int e)
{
	if (i > L.length + 1 || i < 1)
	{
		printf("请输入合法值");
		exit(0);
	}
	if (L.length >= L.listSize)
	{
		int* newbase = (int*)realloc(L.elem, (L.listSize + LISTINCREMENT * sizeof(int)));
		if (!newbase)
		{
			printf("分配失败，空间不足");
			exit(0);
		}
		L.elem = newbase;
		L.listSize += LISTINCREMENT;
	}
	
	int* q = &(L.elem[i - 1]); //q为插入的位置，数组从0计数，插入位置为i-1
	for (int* p = &(L.elem[L.length - 1]); p >= q; p--) //通过最后一个元素到插入位置的原本元素以此后移，进行插入操作
	{
		*(p + 1) = *p;
	}
	*q = e; //原本的位置空出来，将插入值插入
	L.length += 1;
	return L;
}

SqList DelList(SqList L, int i)
{
	if (i<1 || i>L.length)
	{
		printf("请输入合法值");
		exit(0);
	}
	int* p = &(L.elem[i - 1]); //定义p表示需要删除的位置
	for (int* q = &(L.elem[L.length - 1]); p <= q; p++)
	{
		*p = *(p + 1); //将被删位置之后的所有元素全部左移
	}
	L.length--;
	return L;
}

int LocalList(SqList L, int e)
{
	if (!L.length)
	{
		printf("该表为空");
		return ERROR;
	}
	int* p = &(L.elem[0]); //定义p指向第一个表元素
	for (int n = 1; n <= L.length; n++)
	{
		if (*p == e)
		{
			return n;
		}
		*p = *(p+1);
	}
	return NULL;
}

Status PrintList(SqList L)
{
	if (!L.length)
	{
		printf("该表为空表");
		return ERROR;
	}
	for (int i = 1; i < L.length; i++)
	{
		printf("%d ", *&(L.elem[i-1]));
	}
	return OK;
}
