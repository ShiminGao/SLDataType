#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

//测试动作：测试顺序表
void slTest()
{
	SL s1;
	SLInit(&s1);

	//SLValue(&s1);
	//SLPrint(&s1);

	//头部插入
	SLPushFront(&s1, 1);
	SLPushFront(&s1, 2);
	SLPushFront(&s1, 3);
	SLPushFront(&s1, 4);
	SLPrint(&s1); //4 3 2 1

	//尾部插入
	SLPushBack(&s1, 1);
	SLPushBack(&s1, 2);
	SLPushBack(&s1, 3);
	SLPrint(&s1); //4 3 2 1 1 2 3

	//头部删除
	SLPopFront(&s1); 
	SLPrint(&s1); //3 2 1 1 2 3

    //尾部删除
	SLPopBack(&s1);
	SLPrint(&s1); //3 2 1 1 2

	//指定位置之前插入数据
	SLInsert(&s1, 2, 100);
	SLPrint(&s1); //3 2 100 1 1 2

	//删除指定位置数据
	SLErase(&s1, 2);
	SLPrint(&s1); //3 2 1 1 2

}

int main()
{
	slTest();
	return 0;
}