#pragma once//��ֹͷ�ļ��ظ�����
#include <iostream>//�������������ͷ�ļ�
using namespace std;//ʹ�ñ�׼�����ռ�
#include<string>
#include<fstream>
#include"Worker.h"
#include"Boss.h"
#include"Manger.h"
#include"OrdinaryEmployee.h"
#define FILENAME "worker.txt"//�洢�ļ���
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
	//�鿴ְ��
	void ShowWorker();
	//ְ������
	int m_WorkerNum;
	//��ʼ��ְ��
	void m_InitWorker();
	//��ְ���Ƿ���ڡ������������е�λ��
	int IsExist(int id);
	//�޸���Ϣ
	void Mod_Worker();
	//ɾ��ְ��
	void DeleWorker();
	//����ְ��
	void Find_Worker();
	//��ְ�����������
	void Sort();
	//����ļ�
	void Clean_File();
	//��ȡ�ļ��е�����
	int m_GetNum();
	//��ʾ�ļ���״̬��tureΪ��
	bool m_WorkerFileEmpty;
	//�����ݱ��浽�ļ���
	void Save();
	//ְ������ָ��
	Worker** m_WorkerArray;
	//���ְ��
	void Add_Worker();
};


