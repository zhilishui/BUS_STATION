#include"head.h"
#include"function.h"
 
 
//  * 初始化乘客模式，如果有日志，就读日志，如果没有，就读取车次文件
int InitializationPassagerMode(Timetable* timetables, char* LogFileName, char* filename)
{
	int n;// * 统计车次数量
 
	int i; // * 将车次的售票量初始化为0的循环变量
	
	fstream file_log;// * 定义日志文件操作
	fstream file;// * 定义bus.txt的操作
 
	file_log.open(LogFileName, ios::in);
 
	if (file_log.fail())
	{
		// BuildLogFile(LogFileName);// * 这个函数有点没用了
		
		n = ReadFromFile(timetables, 0, filename);
 
		for ( i = 0; i < n; i++)
		{
			timetables[i].sold_number = 0;
		}
 
		WritetoFile(timetables, n, LogFileName);
 
		return n;
	}
 
	file_log.close();
 
	n = ReadFromFile(timetables, 0, LogFileName);
 
	return n;
}
 
//  *  订票
void TicketOrder(Timetable* timetables, int n)
{
	char find_no[20];// * 要购买的车次
 
	int num;
 
	cout << "\n\n\n";
	Space();
	Space();
	cout << "请输入要购买的车次：";
	cin >> find_no;// * 输入要购买的车次
 
 
	// * 判断车次是否存在
	if (find(timetables, n, find_no) == -1)
	{
		Space();
		Space();
		cout << "车次不存在" << endl;
		return;
	}
	
			   // * 判断无法购票的条件
	if (StopSevice(timetables, n, find_no))
	{
		Space();
		Space();
		cout << "无法购票！(即将发车或已经发车)" << endl;
 
		return;
	}
 
	Space();
	Space();
	cout << "请输入要购买数目：";
 
	cin >> num;// * 输入要购买数目
 
	if ((timetables[find(timetables, n, find_no)].max_number
		- timetables[find(timetables, n, find_no)].sold_number) < num)
	{
		Space();
		Space();
		cout << "余票不足！" << endl;
 
		return;
	}
 
	timetables[find(timetables, n, find_no)].sold_number += num;
 
}
 
// * 退票
void TicketDelete(Timetable* timetables, int n)
{
	char find_no[20];// * 要退票的车次
 
	int num;// * 退票数量
 
	cout << "\n\n\n";
	Space();
	Space();
	cout << "请输入要退票的车次：";
	cin >> find_no;// * 输入要退票的车次
 
 
	// * 判断车次是否存在
	if (find(timetables, n, find_no) == -1)
	{
		Space();
		Space();
		cout << "车次不存在" << endl;
		return;
	}
 
			   // * 判断无法退票的条件
	if (StopSevice(timetables, n, find_no))
	{
		Space();
		Space();
		cout << "无法退票！(即将发车或已经发车)" << endl;
 
		return;
	}
 
 
	Space();
	Space();
	cout << "请输入要退票数目：";
	cin >> num;// * 输入要退票数目
 
	if (timetables[find(timetables, n, find_no)].sold_number < num)
	{
 
		Space();
		Space();
		cout << "输入退票数目有误！" << endl;
 
		return;
	}
 
	timetables[find(timetables, n, find_no)].sold_number -= num;
 
}