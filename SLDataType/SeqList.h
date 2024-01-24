#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//定义顺序表的结构，顺序表要实现的接口/方法

//动态顺序表
typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* arr; //存储数据的底层结构
	int capacity;    //记录顺序表的空间大小
	int size;        //记录顺序表当前有效的数据个数
}SL;


//初始化和销毁
void SLInit(SL*ps);
void SLDestroy(SL* ps);

//顺序表打印
void SLPrint(SL* ps);

//扩容
void SLCheckCapacity(SL* ps);

//头部插入删除 / 尾部插入删除
void SLPushBack(SL* ps, SLDataType x);
void SLPopBack(SL* ps);
void SLPushFront(SL* ps, SLDataType x);
void SLPopFront(SL* ps);

//指定位置之前插入/删除数据
void SLInsert(SL* ps, int pos, SLDataType x);
void SLErase(SL* ps, int pos);
//int SLFind(SL* ps, SLDataType x);