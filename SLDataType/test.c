#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

//���Զ���������˳���
void slTest()
{
	SL s1;
	SLInit(&s1);

	//SLValue(&s1);
	//SLPrint(&s1);

	//ͷ������
	SLPushFront(&s1, 1);
	SLPushFront(&s1, 2);
	SLPushFront(&s1, 3);
	SLPushFront(&s1, 4);
	SLPrint(&s1); //4 3 2 1

	//β������
	SLPushBack(&s1, 1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 3);
	SLPrint(&s1); //4 3 2 1 1 2 3

	//ͷ��ɾ��
	SLPopFront(&s1); 
	SLPrint(&s1); //3 2 1 1 2 3

    //β��ɾ��
	SLPopBack(&s1);
	SLPrint(&s1); //3 2 1 1 2

	//ָ��λ��֮ǰ��������
	SLInsert(&s1, 2, 100);
	SLPrint(&s1); //3 2 100 1 1 2

	//ɾ��ָ��λ������
	SLErase(&s1, 2);
	SLPrint(&s1); //3 2 1 1 2

}

int main()
{
	slTest();
	return 0;
}