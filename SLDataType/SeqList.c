#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"


//具体实现顺序表里定义的接口/方法

//初始化
void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

//顺序表赋值
void SLValue(SL* ps)
{
	ps->size = ps->capacity = 4;
	for (int i = 0; i < ps->size; i++)
	{
		ps->arr[i] = i;
	}
}

//顺序表打印
void SLPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}

//扩容
void SLCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		//realloc申请以字节为单位
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, newCapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(1);
		}
		//扩容成功
		ps->arr = tmp;
		ps->capacity = newCapacity;
	}
}

//头部插入
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	//判断是否扩容
	SLCheckCapacity(ps);

	//旧数据往后移动1位
	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = x;
	ps->size++;
}

//头部删除
void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size);

	//不为空执行挪动操作
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

//尾部插入
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	//判断是否扩容
	SLCheckCapacity(ps);

	//空间足够，直接插入
	ps->arr[ps->size++] = x;
}

//尾部删除
void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->size);

	ps->size--;
}

//指定位置之前插入数据
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);

	SLCheckCapacity(ps);

	//pos及之后的数据往后挪动一位，pos空出来
	for (int i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1]; 
	}
	ps->arr[pos] = x;
	ps->size++;
}

//删除指定位置数据
void SLErase(SL* ps, int pos) 
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);

	//pos以后的数据往前挪动一位
	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}