#pragma once//��ֹͷ�ļ��ظ�����
#include <iostream>//�������������ͷ�ļ�
using namespace std;//ʹ�ñ�׼�����ռ�
#include<string>
#include<fstream>
#include"Worker.h"
#include"Boss.h"
#include"Manger.h"
#include"OrdinaryEmployee.h"
class WorkerManager {
public:
	//���캯��
	WorkerManager();
	//չʾ�˵�
	void Show_Menu();
	//�˳�ϵͳ
	void ExitSystem();
	//��������
	~WorkerManager();
	//ְ������
	int m_WorkerNum;
	//ְ������ָ��
	Worker** m_WorkerArray;
	//���ְ��
	void Add_Worker();
};


