#pragma once
 
//  *  ����ṹ��
 
typedef struct
{
	char no[10] = {'\0'};// * ���
	int hour;// * ����ʱ��*Сʱ
	int minute;// * ����ʱ�� * ����
	char Starting_station[10] = {'\0'};// * ʼ��վ
	char Last_station[10] = { '\0' };// * �յ�վ
	float time;// * �г�ʱ��
	int fare;// * Ʊ��
	int max_number;// * ����ؿ���
	int sold_number;// * ����Ʊ��
}Timetable;
 
 
//==========================================================================================
 
// * ������֮��ĺ�������
void AdminMode(Timetable* timetables, char* filename);
void PassagerMode(Timetable* timetables, char* filename);
 
 
//===============================================================================================
 
// * ���ں���������
 
int MainWindowSelect();
int AdminWindowSelect();
int PassagerWindowSelect();
//=================================================================================================================
 
 
 
// * Ԥ����ͽ�������ĺ�������
 
void Signin();//  * ��¼
 
int ReadFromFile(Timetable* timetables, int n, char* filename);// * ���ļ��ж���
 
int WritetoFile(Timetable* timetables, int n, char* filename);// * �����ݱ��浽�ļ���
 
void GenerateLogFileName(char* LogFileName);// * ���ݵ�������������־��
 
int InitializationPassagerMode(Timetable* timetables,
								char* LogFileName,
								char* filename);//  * ��ʼ���˿�ģʽ���������־���Ͷ���־�����û�У��Ͷ�ȡ�����ļ�
 
void SortbyTime(Timetable* timetables, int n);// *  ��timetable�����Ԫ�ذ��շ�����ʱ���������
 
int Quit();// * �˳�����
 
// * ������Ӧ�ĳ��κţ��ж��Ƿ�ֹͣ��Ʊ����Ʊ
int StopSevice(Timetable* timetables, int n, char* no);
 
//=====================================================================================================================
 
 
// * ����Ա�ĺ���
 
int AddBus(Timetable* timetables, int n);// * ��ӳ���
 
void ShowTimeTable(Timetable* timetables, int n);// * �г����г���
 
void Query(Timetable* timetables, int n);// * ��ѯ����
 
int DelBus(Timetable* timetables, int n);// * ɾ������
 
//=======================================================================================
 
 
// * �˿͵ĺ���
 
 
void TicketOrder(Timetable* timetables, int n);// * ��Ʊ
 
void TicketDelete(Timetable* timetables, int n);// * ��Ʊ
 
 
 
// =========================================================================================
 
 
// * �����Ľ�����Ƶĺ���
 
 
void Enter();// * ����س�����
 
void Space();//����20���ո�
 
void Star();//��������
 
 
// =============================================================================================
// * ��Ҫ���ܺ����м�ĸ�������
 
// * ѡ���ѯ�ķ�ʽ
int QueryChioce();
 
// * ����±�Ϊi��timetables�ṹ�����������ֵ
void OutPutBus(Timetable* timetables, int i);
 
// * ���복�κţ������±�
int find(Timetable* timetables, int n, char* no);
 
// * ���յ�վ���в�ѯ�������յ�վ����Ŀ������b[]�����յ�վ���±�
int find(Timetable* timetables, int n, char* Last_station, int* b);
 
// * ������־�ļ�
void BuildLogFile(char* LogFileName);
 
// * ��ÿ��ǰ����ʾÿ����Ϣ����
void BeforeOutPutBus();
 
 
// * ����±�Ϊi��timetables�ṹ�����������ֵ(����Ա�汾)
void OutPutBus_2(Timetable* timetables, int i);
 
// * ��ÿ��ǰ����ʾÿ����Ϣ���֣�����Ա�汾��
void BeforeOutPutBus_2();