#include"head.h"
#include"function.h"
 
// * 管理员登录
void Signin()
{
	int i;// * 用来循环输入密码便于隐藏
	int j = 0;
	char account[40];
	
 
	while (1)
	{
		char password[50] = { '\0' };// * 初始化密码数组
 
		Star();
		Space();
		Space();
		cout << "欢迎使用汽车站车票管理系统\n\n";
		Star();
		Space();
		Space();
		cout << "账号：";
		cin >> account;
		cin.ignore();// * 消化掉换行符
		Space();
		Space();
		cout << "\n密码：";
		system("cls");
 
		i = 0;// * 隐藏密码
		while (1)
		{
			Star();
			Space();
			Space();
			cout << "欢迎使用汽车站车票管理系统\n\n";
			Star();
			Space();
			Space();
			cout << "账号：";
			cout << account << endl;
			cout << endl;
			Space();
			Space();
			cout << "密码：";
			
			for (j = 0; j < i; j++)
				cout << "*";
 
			password[i] = getch();
 
		//	cout << endl << password;// * 这个到时候要删掉的
			
			if (password[i] == '\r')
				break;
 
 
			// * 输入backspace的时侯删除字符串中的字符
			if (password[i] == '\b')
			{
					password[i] = '\0';
					i--;
 
					// * 防止减多了
					if (i != -1)
						i--;
			}
			system("cls");
			i++;
 
			if (i > 20)
			{
				break;
			}
		}
		
		
		
		// * 比较是否一致
		if (!strcmp(account, "admin") && !strcmp(password, "123456\r") )
		{
			system("cls");
			return;
		}
		
		cout << "\n\n\n";
		Space();
		Space();
		cout << "输入的账号或密码有误\n";
		Space();
		Space();
 
 
		
		system("pause");
		system("cls");
 
	}
 
 
}
 
// * 从文件中读取数据,返回数据的数量
int ReadFromFile(Timetable* timetables, int n, char* filename)
{
	fstream file;
	file.open(filename, ios::in);
 
	// * 如果找不到文件就建立一个新的文件
	if (file.fail())
	{
		file.close();
 
		file.open(filename, ios::out);
 
		file.close();
 
		file.open(filename, ios::in);
	}
 
	
	while (!file.eof())
	{
		file >> timetables[n].no;
 
		// * 防止第一行是空的被读取进去
		if (file.eof())
		{
			file.close();
			break;
		}
		file >> timetables[n].hour;
		file >> timetables[n].minute;
		file >> timetables[n].Starting_station;
		file >> timetables[n].Last_station;
		file >> timetables[n].time;
		file >> timetables[n].fare;
		file >> timetables[n].max_number;
		file >> timetables[n].sold_number;
		n++;
	}
 
	return n;
}
 
// * 将数据保存到文件中
int WritetoFile(Timetable* timetables, int n, char* filename)
{
	SortbyTime(timetables, n);
 
	fstream file;
	file.open(filename, ios::out);
 
	int i; // * 循环变量
	
	// * 如果n为0的话就不写入文件了
	if (n == 0)
	{
		file.close();
		return 0;
	}
	//====================================================
	file << setw(10) << timetables[0].no;
	file << setw(10) << timetables[0].hour;
	file << setw(10) << timetables[0].minute;
	file << setw(10) << timetables[0].Starting_station;
	file << setw(10) << timetables[0].Last_station;
	file << setw(10) << timetables[0].time;
	file << setw(10) << timetables[0].fare;
	file << setw(10) << timetables[0].max_number;
	file << setw(10) << timetables[0].sold_number;
	
	
	for (i = 1; i < n; i++)
	{
		cout.setf(ios::left);
		file << endl;
		file << setw(10) << timetables[i].no;
		file << setw(10) << timetables[i].hour;
		file << setw(10) << timetables[i].minute;
		file << setw(10) << timetables[i].Starting_station;
		file << setw(10) << timetables[i].Last_station;
		file << setw(10) << timetables[i].time;
		file << setw(10) << timetables[i].fare;
		file << setw(10) << timetables[i].max_number;
		file << setw(10) << timetables[i].sold_number;
 
	}
 
	// * 分开写入文件是因为如果不分开最后一个endl会往下走一行导致一行空的被读取
	// =============================================================
	return 0;
}
 
 
// * 根据当天日期生成日志名
void GenerateLogFileName(char* LogFileName)
{
	time_t t = time(0);
 
	struct tm* time;
 
	time = localtime(&t);
	
	char year[5], month[2], day[3];// * 定义接受年月日字符串的字符串数组
 
	// * 时间是int型，将它转换为char型
	itoa(time->tm_mday, day, 10);
	itoa(time->tm_year + 1900, year, 10);
	itoa(time->tm_mon + 1, month, 10);
	
 
	strcpy(LogFileName, year);
	strcat(LogFileName, "-");
	strcat(LogFileName, month);
	strcat(LogFileName, "-");
	strcat(LogFileName, day);
	strcat(LogFileName, ".log");
 
}
 
 
 
// *  将timetable里面的元素按照发车的时间进行排序
void SortbyTime(Timetable* timetables, int n)
{
	// * 采用冒泡排序法
	int i, j;
 
	Timetable t;// * 用来交换的量
 
	// * 冒泡排序
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (timetables[j].hour * 60 + timetables[j].minute > timetables[j + 1].hour * 60 + timetables[j + 1].minute)
			{
				t = timetables[j + 1];
				timetables[j + 1] = timetables[j];
				timetables[j] = t;
			}
		}
	}
 
 
}
 
// * 传入相应的车次号，判断是否停止售票和退票
int StopSevice(Timetable* timetables, int n, char* no)
{
	struct tm* local;// * 时间结构体
 
	time_t t = time(0);// * 把当前的时间给t
 
	local = localtime(&t);// * 获取当前系统时间
 
	int i = find(timetables, n, no);
 
	if ((local -> tm_hour * 60 + local -> tm_min) + 10 < timetables[i].hour * 60 + timetables[i].minute)
	{
		return 0;
	}
 
	return 1;
 
 
}
 
 
 
 
// **    辅助函数
// 
// 
// * 查询车辆时选择是要按车次查询还是终点站查询
int QueryChioce()
{
 
	int choice;
 
	Star();
	Space();
	Space();
	cout << "请选择查询方式\n\n";
	Star();
	Space();
	Space();
	cout << "1.按照车次查询\n\n";
	Space();
	Space();
	cout << "2.按照终点站查询\n\n";
	Star();
 
	Space();
	Space();
	cout << "请输入查询方式：";
	cin >> choice;
	// * 这里没有如果输入了1，2以外的数的处理情况
	// * 之后可以选择补加
 
	system("cls");
	return choice;
}
 
// * 输出下标为i的timetables结构体里面的所有值
 
void BeforeOutPutBus()
{
	cout.setf(ios::left);
	cout << setw(10) << "车次号";
	cout << setw(10) << "发车时间";
	cout << "  ";
	cout << setw(10) << "始发站";
	cout << setw(10) << "终点站";
	cout << setw(10) << "预计用时";
	cout << setw(10) << "票价";
	cout << setw(15) << "最大载客量";
	cout << setw(10) << "已售票数" << endl;
}
 
void OutPutBus(Timetable* timetables, int i)
{
	cout.setf(ios::left);
	cout << setw(10) << timetables[i].no;
	cout << timetables[i].hour << ":";
	cout << setw(10) << timetables[i].minute;
	cout << setw(10) << timetables[i].Starting_station;
	cout << setw(10) << timetables[i].Last_station;
	cout << setw(10) << timetables[i].time;
	cout << setw(10) << timetables[i].fare;
	cout << setw(15) << timetables[i].max_number;
	cout << setw(10) << timetables[i].sold_number << endl;
 
}
 
 
// * 输入车次号，返回下标
int find(Timetable* timetables, int n, char* no)
{
	int i; // * 循环变量
	
	for ( i = 0; i < n; i++)
	{
		if (!strcmp(no, timetables[i].no))
		{
			return i;
		}
	}
	
	return -1;
}
 
// * 按终点站进行查询，返回终点站的数目，数组b[]返回终点站的下标
int find(Timetable* timetables, int n, char* Last_station, int* b)
{
	int i; // * 循环变量
 
	int num = 0; // * 记录车次的数目
 
	for (i = 0; i < n; i++)
	{
		if (!strcmp(Last_station, timetables[i].Last_station))
		{
			b[num] = i;
			num++;
		}
	}
 
	if (num != 0)
	{
		return num;
	}
	else
		return -1;
}
 
 
// * 上面那个是乘客的输出，这个是管理员的输出（doge）
 
void BeforeOutPutBus_2()
{
	cout.setf(ios::left);
	cout << setw(10) << "车次号";
	cout << setw(10) << "发车时间";
	cout << "  ";
	cout << setw(10) << "始发站";
	cout << setw(10) << "终点站";
	cout << setw(10) << "预计用时";
	cout << setw(10) << "票价";
	cout << setw(15) << "最大载客量" << endl;
}
 
void OutPutBus_2(Timetable* timetables, int i)
{
	cout.setf(ios::left);
	cout << setw(10) << timetables[i].no;
	cout << timetables[i].hour << ":";
	cout << setw(10) << timetables[i].minute;
	cout << setw(10) << timetables[i].Starting_station;
	cout << setw(10) << timetables[i].Last_station;
	cout << setw(10) << timetables[i].time;
	cout << setw(10) << timetables[i].fare;
	cout << setw(15) << timetables[i].max_number << endl;
 
}