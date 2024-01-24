#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//����˳���Ľṹ��˳���Ҫʵ�ֵĽӿ�/����

//��̬˳���
typedef int SLDataType;

typedef struct SeqList
{
	SLDataType* arr; //�洢���ݵĵײ�ṹ
	int capacity;    //��¼˳���Ŀռ��С
	int size;        //��¼˳���ǰ��Ч�����ݸ���
}SL;


//��ʼ��������
void SLInit(SL*ps);
void SLDestroy(SL* ps);

//˳����ӡ
void SLPrint(SL* ps);

//����
void SLCheckCapacity(SL* ps);

//ͷ������ɾ�� / β������ɾ��
void SLPushBack(SL* ps, SLDataType x);
void SLPopBack(SL* ps);
void SLPushFront(SL* ps, SLDataType x);
void SLPopFront(SL* ps);

//ָ��λ��֮ǰ����/ɾ������
void SLInsert(SL* ps, int pos, SLDataType x);
void SLErase(SL* ps, int pos);
//int SLFind(SL* ps, SLDataType x);