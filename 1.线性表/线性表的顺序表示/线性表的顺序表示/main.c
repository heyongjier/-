#include"List.h"

int main()
{
	int A[10] = { 100,2,3,50,23,88,45,122,50,1 };
	SqList L = InitList();
	
	for (int i = 1; i <= 10; i++)
	{
		L = ListInsert(L, i, A[i-1]);
	}
	PrintList(L);

	L = DelList(L, 2);
	PrintList(L);

	printf("���ֵ�λ���ǣ�%d", LocalList(L, 3));
}