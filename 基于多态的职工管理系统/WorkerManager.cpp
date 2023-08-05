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

	if (m_WorkerArray != NULL)
	{
		for (int i = 0; i < m_WorkerNum; i++)
		{
			if (m_WorkerArray[i] != 0)
			{
				delete m_WorkerArray[i];
			}
		}
		m_WorkerNum = 0;
		delete[] m_WorkerArray;
		m_WorkerArray = NULL;
		this->m_WorkerFileEmpty = true;
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
//�ж�ְ���Ƿ���ڣ������򷵻��������е�λ�ã��������򷵻�-1
int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < m_WorkerNum; i++)
	{
		if (m_WorkerArray[i]->m_ID == id)
		{
			index = i;
			break;
		}
	}

	return index;
}

void WorkerManager::Mod_Worker()
{
	if (this->m_WorkerFileEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		cout << "������Ҫ�޸ĵ�ְ���ı��" << endl;
		int id;
		cin >> id;
		int index = IsExist(id);
		if (index == -1)
		{
			cout << "��ְ��������" << endl;
		}
		else
		{//���ҵ���Ӧ��ŵ�Ա��
			delete m_WorkerArray[index];
			int newId;
			string newname;
			int post;
			cout << "�鵽" << id << "��ְ�����������µ�ְ���ţ�" << endl;
			while (true)
			{
				cin >> newId;
				if (IsExist(newId) == -1)
				{
					break;
				}
				cout << "�Ѵ����ظ���ְ����ţ�����������" << endl;
			}
			cout << "�������µ�����" << endl;
			cin >> newname;
			cout << "��ѡ���ְ����λ��" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> post;
			Worker* worker = NULL;
			switch (post)
			{
			case 1:worker = new OrdinaryEmployee(newId, newname, post); break;
			case 2:worker = new Manger(newId, newname, post); break;
			case 3:worker = new Boss(newId, newname, post); break;
			default:
				break;
			}
			this->m_WorkerArray[index] = worker;//�������ݵ�������
			cout << "�޸ĳɹ�" <<  endl;
			//ͬ�����ݵ��ļ���
			Save();
		}
	}
	//�����������
	system("pause");
	system("cls");
}

void WorkerManager::DeleWorker()
{
	if (this->m_WorkerFileEmpty)
	{
		cout<<"�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		cout<<"������Ҫɾ��ְ���ı��" << endl;
		int id;
		cin >> id;
		int index = IsExist(id);
		if ( index== -1)
		{
			cout << "��ְ��������" << endl;
		}
		else
		{
			for ( int i = index; i < m_WorkerNum-1; i++)
			{
				m_WorkerArray[i] = m_WorkerArray[i + 1];//����ǰ��
			}
			m_WorkerNum--;//��������
			Save();//����ͬ�����ļ���
			cout<<"ɾ���ɹ�" << endl;
		}
	}
	//�����������
	system("pause");
	system("cls");

}

void WorkerManager::Find_Worker()
{
	if (this->m_WorkerFileEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��ѡ����ҵķ�ʽ" << endl;
		cout << "1.ͨ��ְ����Ų���" << endl;
		cout << "2.ͨ����������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{//���ձ�Ų���
			cout << "������Ҫ���ҵı��" << endl;
			int id;
			cin >> id;
			int index = IsExist(id);
			if ( index== -1)
			{
				cout << "���޴���" << endl;
			}
			else
			{
				cout<<"�ҵ���" << endl;
				m_WorkerArray[index]->ShowInfo();
			}
		}
		else if(select==2)
		{//������������
			cout << "������Ҫ���ҵ�����" << endl;
			string name;
			cin >> name;
			int num = 0;//��¼ͬ������
			for (int i = 0; i < m_WorkerNum; i++)
			{
				if (m_WorkerArray[i]->m_Name.compare(name)==0)
				{
					m_WorkerArray[i]->ShowInfo();
					num++;
				}
			}
			if (num == 0)
			{
				cout << "���޴���" << endl;
			}
			else
			{
				cout << "�ܹ�" << num << "��" << endl;
			}
		}
		else
		{
			cout << "����������" << endl;
		}
	}
	//�����������
	system("pause");
	system("cls");
}

void WorkerManager::Sort()
{

	cout << "��ѡ������ķ�ʽ" << endl;
	cout << "1.ְ���Ž�������" << endl;
	cout << "2.ְ������������" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{//ְ���Ž�������
		for (int i = 0; i <m_WorkerNum; i++)
		{
			
			for (int j = 0;j< m_WorkerNum-1; j++)
			{
				if (m_WorkerArray[j]->m_ID < m_WorkerArray[j+1]->m_ID)
				{
					Worker* worker = NULL;
					worker = m_WorkerArray[j];
					m_WorkerArray[j] = m_WorkerArray[j+1];
					m_WorkerArray[j+1] = worker;
				}
			}
		
		}
		
	}
	else if(select==2)
	{
		//ְ������������
		for (int i = 0; i < m_WorkerNum; i++)
		{

			for (int j = 0; j < m_WorkerNum - 1; j++)
			{
				if (m_WorkerArray[j]->m_ID > m_WorkerArray[j + 1]->m_ID)
				{
					Worker* worker = NULL;
					worker = m_WorkerArray[j];
					m_WorkerArray[j] = m_WorkerArray[j + 1];
					m_WorkerArray[j + 1] = worker;
				}
			}

		}
	}
	else
	{
		cout << "��������ȷ��ѡ��" << endl;
	}
	cout << "���Ϊ��" << endl;
	Save();
	this->ShowWorker();
	//�����������
	system("pause");
	system("cls");
}

void WorkerManager::Clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1.ȷ��" << endl;
	cout<<"2.����" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//��ģʽios::trunc ����ļ�����ɾ���ļ������´���
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (m_WorkerArray != NULL)
		{
			for (int i = 0; i < m_WorkerNum; i++)
			{
				if (m_WorkerArray[i] != 0)
				{
					delete m_WorkerArray[i];
				}
			}
			m_WorkerNum = 0;
			delete[] m_WorkerArray;
			m_WorkerArray = NULL;
			this->m_WorkerFileEmpty = true;
		}
		cout << "��ճɹ�" << endl;
	}

	//�����������
	system("pause");
	system("cls");
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
			while (true)
			{
				cin >> id;
				if(IsExist(id)<0)
				{
					break;
				}
				cout << "�Ѵ����ظ���ְ����ţ�����������" << endl;
			}
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
