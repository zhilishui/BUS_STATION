#pragma once
 
//  *  定义结构体
 
typedef struct
{
	char no[10] = {'\0'};// * 班次
	int hour;// * 发车时间*小时
	int minute;// * 发车时间 * 分钟
	char Starting_station[10] = {'\0'};// * 始发站
	char Last_station[10] = { '\0' };// * 终点站
	float time;// * 行车时长
	int fare;// * 票价
	int max_number;// * 最大载客量
	int sold_number;// * 以售票数
}Timetable;
 
 
//==========================================================================================
 
// * 主函数之间的函数声明
void AdminMode(Timetable* timetables, char* filename);
void PassagerMode(Timetable* timetables, char* filename);
 
 
//===============================================================================================
 
// * 窗口函数的声明
 
int MainWindowSelect();
int AdminWindowSelect();
int PassagerWindowSelect();
//=================================================================================================================
 
 
 
// * 预处理和结束后处理的函数声明
 
void Signin();//  * 登录
 
int ReadFromFile(Timetable* timetables, int n, char* filename);// * 从文件中读入
 
int WritetoFile(Timetable* timetables, int n, char* filename);// * 将数据保存到文件中
 
void GenerateLogFileName(char* LogFileName);// * 根据当天日期生成日志名
 
int InitializationPassagerMode(Timetable* timetables,
								char* LogFileName,
								char* filename);//  * 初始化乘客模式，如果有日志，就读日志，如果没有，就读取车次文件
 
void SortbyTime(Timetable* timetables, int n);// *  将timetable里面的元素按照发车的时间进行排序
 
int Quit();// * 退出程序
 
// * 传入相应的车次号，判断是否停止售票和退票
int StopSevice(Timetable* timetables, int n, char* no);
 
//=====================================================================================================================
 
 
// * 管理员的函数
 
int AddBus(Timetable* timetables, int n);// * 添加车次
 
void ShowTimeTable(Timetable* timetables, int n);// * 列出所有车次
 
void Query(Timetable* timetables, int n);// * 查询车次
 
int DelBus(Timetable* timetables, int n);// * 删除车次
 
//=======================================================================================
 
 
// * 乘客的函数
 
 
void TicketOrder(Timetable* timetables, int n);// * 订票
 
void TicketDelete(Timetable* timetables, int n);// * 退票
 
 
 
// =========================================================================================
 
 
// * 辅助的界面设计的函数
 
 
void Enter();// * 输入回车控制
 
void Space();//输入20个空格
 
void Star();//输入星形
 
 
// =============================================================================================
// * 主要功能函数中间的辅助函数
 
// * 选择查询的方式
int QueryChioce();
 
// * 输出下标为i的timetables结构体里面的所有值
void OutPutBus(Timetable* timetables, int i);
 
// * 输入车次号，返回下标
int find(Timetable* timetables, int n, char* no);
 
// * 按终点站进行查询，返回终点站的数目，数组b[]返回终点站的下标
int find(Timetable* timetables, int n, char* Last_station, int* b);
 
// * 生成日志文件
void BuildLogFile(char* LogFileName);
 
// * 在每列前面显示每列信息名字
void BeforeOutPutBus();
 
 
// * 输出下标为i的timetables结构体里面的所有值(管理员版本)
void OutPutBus_2(Timetable* timetables, int i);
 
// * 在每列前面显示每列信息名字（管理员版本）
void BeforeOutPutBus_2();