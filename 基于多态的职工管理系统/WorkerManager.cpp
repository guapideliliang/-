#define _CRT_SECURE_NO_WARNINGS 1
#include"WorkerManager.h"
WorkerManager::WorkerManager() {
	this->m_WorkerNum=0;//��ʼ��
	this->m_WorkerArray=NULL;
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())//�ļ�������
	{
		cout << "�ļ�������" << endl;
		this->m_WorkerNum = 0;//��ʼ������
		this->m_WorkerFileEmpty = true;//�趨�ļ�״̬
		this->m_WorkerArray=NULL;//��ʼ������
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		this->m_WorkerNum = 0;//��ʼ������
		this->m_WorkerFileEmpty = true;//�趨�ļ�״̬
		this->m_WorkerArray = NULL;//��ʼ������
		ifs.close();
		return;
	}
	int num = this->m_GetNum();//��ȡ����
	cout << "ְ����Ϊ�� " << num << endl;//��ʾ����
	this->m_WorkerNum = num;//��������
	this->m_WorkerArray = new Worker * [this->m_WorkerNum];//����������ʼ������
	//��ʼ��ְ��
	this->m_InitWorker();
	////���Դ���
	//for (int i = 0; i < m_WorkerNum; i++)
	//{
	//	cout << this->m_WorkerArray[i]->m_ID << this->m_WorkerArray[i]->m_Name << this->m_WorkerArray[i]->m_Post << endl;
	//}
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

	if (this->m_WorkerArray != NULL)
	{
		delete[] this->m_WorkerArray;
		this->m_WorkerArray = NULL;
	}
}

void WorkerManager::ShowWorker()
{
	if (this->m_WorkerFileEmpty)
	{
		cout << "�ļ������ڻ�Ϊ��" << endl;
		return;
	}
	else {
		for (int i = 0; i < m_WorkerNum; i++)
		{
			this->m_WorkerArray[i]->ShowInfo();
		}
	}
	system("pause");
	system("cls");

}

void WorkerManager::m_InitWorker()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int post;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> post)
	{
		Worker* worker = NULL;
		//���ݲ�ͬ�Ĳ��ű�Ŵ�������
		switch (post)
		{
		case 1:worker = new OrdinaryEmployee(id, name, post); break;//��ְͨ��
		case 2:worker = new Manger(id, name, post); break;//����
		case 3:worker = new Boss(id, name, post); break;//�ϰ�
		}
		this->m_WorkerArray[index] = worker;
		index++;
	}
	ifs.close();
	
}

int WorkerManager::m_GetNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int ID;
	string name;
	int post;

	int num = 0;
	while (ifs>>ID&&ifs>>name&&ifs>>post)
	{
		num++;
	}
	ifs.close();
	return num;
}

void WorkerManager::Save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < m_WorkerNum; i++)
	{
		ofs << this->m_WorkerArray[i]->m_ID << " "
			<< this->m_WorkerArray[i]->m_Name << " "
			<< this->m_WorkerArray[i]->m_Post << endl;
	}
	ofs.close();
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
		this->Save();
	}
	else
	{
		cout<<"���벻�淶" << endl;
	}

	//�����������
	system("pause");
	system("cls");
}
