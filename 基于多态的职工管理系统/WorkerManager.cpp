#define _CRT_SECURE_NO_WARNINGS 1
#include"WorkerManager.h"
WorkerManager::WorkerManager() {
	this->m_WorkerNum=0;//初始化
	this->m_WorkerArray=NULL;
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())//文件不存在
	{
		cout << "文件不存在" << endl;
		this->m_WorkerNum = 0;//初始化人数
		this->m_WorkerFileEmpty = true;//设定文件状态
		this->m_WorkerArray=NULL;//初始化数组
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->m_WorkerNum = 0;//初始化人数
		this->m_WorkerFileEmpty = true;//设定文件状态
		this->m_WorkerArray = NULL;//初始化数组
		ifs.close();
		return;
	}
	int num = this->m_GetNum();//获取人数
	cout << "职工数为： " << num << endl;//显示人数
	this->m_WorkerNum = num;//更新人数
	this->m_WorkerArray = new Worker * [this->m_WorkerNum];//根据人数初始化数组
	//初始化职工
	this->m_InitWorker();
	////测试代码
	//for (int i = 0; i < m_WorkerNum; i++)
	//{
	//	cout << this->m_WorkerArray[i]->m_ID << this->m_WorkerArray[i]->m_Name << this->m_WorkerArray[i]->m_Post << endl;
	//}
}
void WorkerManager:: Show_Menu() {
	cout << "******************" << endl;
	cout << "***职工管理系统***" << endl;
	cout << "* 0、退出管理程序*" << endl;
	cout << "* 1、增加职工信息*" << endl;
	cout << "* 2、显示职工信息*" << endl;
	cout << "* 3、删除离职职工*" << endl;
	cout << "* 4、修改职工信息*" << endl;
	cout << "* 5、查找职工信息*" << endl;
	cout << "* 6、按照编号排序*" << endl;
	cout << "* 7、清空所有文档*" << endl;
	cout << "******************" << endl;
	cout << endl;
}

void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
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
		cout << "文件不存在或为空" << endl;
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
		//根据不同的部门编号创建对象
		switch (post)
		{
		case 1:worker = new OrdinaryEmployee(id, name, post); break;//普通职工
		case 2:worker = new Manger(id, name, post); break;//经理
		case 3:worker = new Boss(id, name, post); break;//老板
		}
		this->m_WorkerArray[index] = worker;
		index++;
	}
	ifs.close();
	
}
//判断职工是否存在，存在则返回在数组中的位置，不存在则返回-1
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
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		cout << "亲输入要修改的职工的编号" << endl;
		int id;
		cin >> id;
		int index = IsExist(id);
		if (index == -1)
		{
			cout << "该职工不存在" << endl;
		}
		else
		{//查找到对应编号的员工
			delete m_WorkerArray[index];
			int newId;
			string newname;
			int post;
			cout << "查到" << id << "号职工，请输入新的职工号：" << endl;
			while (true)
			{
				cin >> newId;
				if (IsExist(newId) == -1)
				{
					break;
				}
				cout << "已存在重复的职工编号，请重新输入" << endl;
			}
			cout << "请输入新的姓名" << endl;
			cin >> newname;
			cout << "请选择该职工岗位：" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
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
			this->m_WorkerArray[index] = worker;//更新数据到数组中
			cout << "修改成功" <<  endl;
			//同步数据到文件中
			Save();
		}
	}
	//按任意键清屏
	system("pause");
	system("cls");
}

void WorkerManager::DeleWorker()
{
	if (this->m_WorkerFileEmpty)
	{
		cout<<"文件不存在或记录为空" << endl;
	}
	else {
		cout<<"亲输入要删除职工的编号" << endl;
		int id;
		cin >> id;
		int index = IsExist(id);
		if ( index== -1)
		{
			cout << "该职工不存在" << endl;
		}
		else
		{
			for ( int i = index; i < m_WorkerNum-1; i++)
			{
				m_WorkerArray[i] = m_WorkerArray[i + 1];//数据前移
			}
			m_WorkerNum--;//更新人数
			Save();//更新同步到文件中
			cout<<"删除成功" << endl;
		}
	}
	//按任意键清屏
	system("pause");
	system("cls");

}

void WorkerManager::Find_Worker()
{
	if (this->m_WorkerFileEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请选择查找的方式" << endl;
		cout << "1.通过职工编号查找" << endl;
		cout << "2.通过姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{//按照编号查找
			cout << "请输入要查找的编号" << endl;
			int id;
			cin >> id;
			int index = IsExist(id);
			if ( index== -1)
			{
				cout << "查无此人" << endl;
			}
			else
			{
				cout<<"找到了" << endl;
				m_WorkerArray[index]->ShowInfo();
			}
		}
		else if(select==2)
		{//按照姓名查找
			cout << "请输入要查找的姓名" << endl;
			string name;
			cin >> name;
			int num = 0;//记录同名人数
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
				cout << "查无此人" << endl;
			}
			else
			{
				cout << "总共" << num << "人" << endl;
			}
		}
		else
		{
			cout << "输入项有误" << endl;
		}
	}
	//按任意键清屏
	system("pause");
	system("cls");
}

void WorkerManager::Sort()
{

	cout << "请选择排序的方式" << endl;
	cout << "1.职工号降序排列" << endl;
	cout << "2.职工号升序排列" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{//职工号降序排列
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
		//职工号升序排列
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
		cout << "请输入正确的选择" << endl;
	}
	cout << "结果为：" << endl;
	Save();
	this->ShowWorker();
	//按任意键清屏
	system("pause");
	system("cls");
}

void WorkerManager::Clean_File()
{
	cout << "确认清空？" << endl;
	cout << "1.确认" << endl;
	cout<<"2.返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//打开模式ios::trunc 如果文件存在删除文件并重新创建
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
		cout << "清空成功" << endl;
	}

	//按任意键清屏
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
	cout << "请输入职工的数量" << endl;
	int addworker = 0;//保存用户输入数量
	cin >> addworker;				
	if (addworker > 0)
	{
		//计算大小
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
			
			cout << "请输入第" << i + 1<< " 个新职工的编号"<<endl;
			while (true)
			{
				cin >> id;
				if(IsExist(id)<0)
				{
					break;
				}
				cout << "已存在重复的职工编号，请重新输入" << endl;
			}
			cout << "请输入第" << i + 1 << " 个新职工的姓名" << endl;
			cin >> name;
			cout << "请选择该职工岗位：" << endl;
			cout << "1.普通职工"<<endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
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
			//将创建的职工指针保存到数组里面
			newspace[this->m_WorkerNum + i] = worker;
		}
		//释放原来的空间
		delete[] this->m_WorkerArray;
		//更新空间的指向	
		this->m_WorkerArray = newspace;
		//更新人数
		this->m_WorkerNum = newSize;
		//提示添加成功
		cout << "成功添加" <<addworker<<" 名新职工" << endl;
		this->Save();
	}
	else
	{
		cout<<"输入不规范" << endl;
	}

	//按任意键清屏
	system("pause");
	system("cls");
}
