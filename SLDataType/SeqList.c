#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"


//����ʵ��˳����ﶨ��Ľӿ�/����

//��ʼ��
void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

//˳���ֵ
void SLValue(SL* ps)
{
	ps->size = ps->capacity = 4;
	for (int i = 0; i < ps->size; i++)
	{
		ps->arr[i] = i;
	}
}

//˳����ӡ
void SLPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}

//����
void SLCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		//realloc�������ֽ�Ϊ��λ
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, newCapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(1);
		}
		//���ݳɹ�
		ps->arr = tmp;
		ps->capacity = newCapacity;
	}
}

//ͷ������
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	//�ж��Ƿ�����
	SLCheckCapacity(ps);

	//�����������ƶ�1λ
	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = x;
	ps->size++;
}

//ͷ��ɾ��
void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size);

	//��Ϊ��ִ��Ų������
	for (int i = 0; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}

//β������
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	//�ж��Ƿ�����
	SLCheckCapacity(ps);

	//�ռ��㹻��ֱ�Ӳ���
	ps->arr[ps->size++] = x;
}

//β��ɾ��
void SLPopBack(SL* ps)
{
	assert(ps);
	assert(ps->size);

	ps->size--;
}

//ָ��λ��֮ǰ��������
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);

	SLCheckCapacity(ps);

	//pos��֮�����������Ų��һλ��pos�ճ���
	for (int i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1]; 
	}
	ps->arr[pos] = x;
	ps->size++;
}

//ɾ��ָ��λ������
void SLErase(SL* ps, int pos) 
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);

	//pos�Ժ��������ǰŲ��һλ
	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}