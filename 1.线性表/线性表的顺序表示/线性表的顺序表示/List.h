#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 100 //���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 10 //���Ա�洢�ռ�ķ�������
#define OK 1
#define ERROR 0

typedef int Status;
typedef struct  {
	int* elem; //�洢�ռ�Ļ�ַ
	int length; //���Ա�ǰ�ĳ���
	int listSize; //��ǰ���Ա����Ĵ洢����
}SqList ;


SqList InitList(void); //��ʼ��һ�����Ա�
SqList ListInsert(SqList L, int i, int e); //�ڵ�i��λ��֮ǰ����һ��ֵΪe������Ԫ��
SqList DelList(SqList, int i); //ɾ��ָ��λ�õ�Ԫ��
int LocalList(SqList L, int e); //����һ��ֵ�ڸñ��е�һ�γ��ֵ�λ��
Status PrintList(SqList L); //����������ȫ����ӡ���