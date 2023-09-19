#include"head.h"
#include"function.h"
 
// * 添加车次
 
int AddBus(Timetable* timetables, int n)
{
	int i;// * 循环变量
	// * 调整输出格式
	cout << "\n\n\n";
	Space();
	Space();
 
	cout << "请输入车次号:";
	cin >> timetables[n].no;
	cout << endl;
	for ( i = 0; i < n; i++)
	{
		if (!strcmp(timetables[i].no, timetables[n].no))
		{
			cout << "已存在相同车次";
			return n;
		}
	}
	Space();
	Space();
	cout << "请输入出发时间（小时）：";
	cin >> timetables[n].hour;
	cout << endl;
	Space();
	Space();
	cout << "请输入出发时间（分钟）：";
	cin >> timetables[n].minute;
	cout << endl;
	Space();
	Space();
	cout << "请输入始发站：";
	cin >> timetables[n].Starting_station;
	cout << endl;
	Space();
	Space();
	cout << "请输入终点站：";
	cin >> timetables[n].Last_station;
	cout << endl;
	Space();
	Space();
	cout << "请输入大约时长：";
	cin >> timetables[n].time;
	cout << endl;
	Space();
	Space();
	cout << "请输入票价：";
	cin >> timetables[n].fare;
	cout << endl;
	Space();
	Space();
	cout << "请输入最大载客量：";
	cin >> timetables[n].max_number;
 
	
	timetables[n].sold_number = 0;
 
	
	return n + 1;
}
 
 
// * 列出所有车次
void ShowTimeTable(Timetable* timetables, int n)
{
	int i;
	BeforeOutPutBus_2();
	for ( i = 0; i < n; i++)
	{
		OutPutBus_2(timetables, i);
 
		// * 驼峰命名法
	}
	
}
 
 
// * 车辆信息查询
void Query(Timetable* timetables, int n)
{
	char find_both[20];// * 储存查询用的变量
	int low[100];
 
	int choice = QueryChioce(); // * 用来选择
	int i; // * 循环变量
	if (choice == 1)// * 按车次查询
	{
		Star();
		Space();
		Space();
		cout << "请输入要查询的车次：";
		cin >> find_both;
 
		// * 判断find的返回值是否是-1，如果是，输出车次不存在并返回
		if (find(timetables, n, find_both) == -1)
		{
			cout << "所查询的车次不存在！" << endl;
			return;
		}
		BeforeOutPutBus();
		OutPutBus(timetables, find(timetables, n, find_both));
	}
 
	else
	{
		Star();
		Space();
		Space();
		cout << "请输入要查询的终点站：";
		cin >> find_both;
 
		// * 判断find的返回值是否是-1，如果是，输出车次不存在并返回
		if (find(timetables, n, find_both, low) == -1)
		{
			cout << "所查询的终点站不存在！" << endl;
			return;
		}
 
		BeforeOutPutBus();
		for ( i = 0; i < find(timetables, n, find_both, low); i++)
		{
			OutPutBus(timetables, low[i]);
		}
 
	}
 
 
	
 
}
 
// * 删除车辆信息
int DelBus(Timetable* timetables, int n)
{
	char find_no[20];
	int i;
	
	Star();
	Space();
	Space();
	cout << "请输入要删除的车次:";
	cin >> find_no;
 
	// * 判断是否存在
	if (find(timetables, n, find_no) == -1)
	{
		Space();
		Space();
		cout << "所删除的车次不存在！\n";
 
		return n;
	}
 
	// * 删除车次
	for (i = find(timetables, n, find_no); i < n; i++)
	{
		timetables[i] = timetables[i + 1];
	}
 
	return n - 1;
 
}