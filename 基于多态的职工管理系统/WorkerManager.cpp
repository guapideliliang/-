#define _CRT_SECURE_NO_WARNINGS 1
#include"WorkerManager.h"
WorkerManager::WorkerManager() {
	this->m_WorkerNum=0;//初始化
	this->m_WorkerArray=NULL;
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
	}
	else
	{
		cout<<"输入不规范" << endl;
	}

	//按任意键清屏
	system("pause");
	system("cls");
}
