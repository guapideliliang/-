#define _CRT_SECURE_NO_WARNINGS 1
#include"WorkerManager.h"
WorkerManager::WorkerManager() {
	this->m_WorkerNum=0;//��ʼ��
	this->m_WorkerArray=NULL;
}
void WorkerManager:: Show_Menu() {
	cout << "******************" << endl;
	cout << "***ְ������ϵͳ***" << endl;
	cout << "* 0���˳��������*" << endl;
	cout << "* 1������ְ����Ϣ*" << endl;
	cout << "* 2����ʾְ����Ϣ*" << endl;
	cout << "* 3��ɾ����ְְ��*" << endl;
	cout << "* 4���޸�ְ����Ϣ*" << endl;
	cout << "* 5������ְ����Ϣ*" << endl;
	cout << "* 6�����ձ������*" << endl;
	cout << "* 7����������ĵ�*" << endl;
	cout << "******************" << endl;
	cout << endl;
}

void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

WorkerManager::~WorkerManager() {

}

void WorkerManager::Add_Worker()
{
	cout << "������ְ��������" << endl;
	int addworker = 0;//�����û���������
	cin >> addworker;				
	if (addworker > 0)
	{
		//�����С
		int newSize = this->m_WorkerNum + addworker;
		Worker** newspace = new Worker*[newSize];
		for (int i = 0; i < m_WorkerNum; i++)
		{
			newspace[i] = m_WorkerArray[i];

		}
		int id;
		string name;
		int post;
		for ( int i=0; i < addworker; i++)
		{
			
			cout << "�������" << i + 1<< " ����ְ���ı��"<<endl;
			cin >> id;
			cout << "�������" << i + 1 << " ����ְ��������" << endl;
			cin >> name;
			cout << "��ѡ���ְ����λ��" << endl;
			cout << "1.��ְͨ��"<<endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> post;
			Worker* worker = NULL;
			switch (post)
			{
			case 1:worker = new OrdinaryEmployee(id, name, post); break;
			case 2:worker = new Manger(id, name, post); break;
			case 3:worker = new Boss(id, name, post); break;
			default:
				break;
			}
			//��������ְ��ָ�뱣�浽��������
			newspace[this->m_WorkerNum + i] = worker;
		}
		//�ͷ�ԭ���Ŀռ�
		delete[] this->m_WorkerArray;
		//���¿ռ��ָ��	
		this->m_WorkerArray = newspace;
		//��������
		this->m_WorkerNum = newSize;
		//��ʾ��ӳɹ�
		cout << "�ɹ����" <<addworker<<" ����ְ��" << endl;
	}
	else
	{
		cout<<"���벻�淶" << endl;
	}

	//�����������
	system("pause");
	system("cls");
}
