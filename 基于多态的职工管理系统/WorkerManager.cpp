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
			cin >> id;
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
