#include"head.h"
#include"function.h"
 
#define NUM1 20
#define NUM2 60
 
 
 
int MainWindowSelect()				// * ���˵�
{
	int choice;
 
	Star();
	Space();
	Space();
	cout << "��ӭʹ������վ��Ʊ����ϵͳ\n\n";
	Star();
	Space();
	Space();
	cout << "1.����Ա��¼\n\n";
	Space();
	Space();
	cout << "2.�û���¼\n\n";
	Space();
	Space();
	cout << "3.�˳�ϵͳ\n\n";
	Star();
 
	// * ����ѡ��
	while (1)
	{
		cout << "��������Ҫѡ����еĲ�����";
		cin >> choice;
 
		system("cls");
		return choice;
	}
}
 
 
int AdminWindowSelect()				// * ����Ա�˵�
{
	int choice;
 
	Star();
	Space();
	Space();
	cout << "��ӭ�������Աϵͳ\n\n";
	Star();
	Space();
	Space();
	cout << "1.��ӳ�����Ϣ\n\n";
	Space();
	Space();
	cout << "2.���ʱ�̱�\n\n";
	Space();
	Space();
	cout << "3.������Ϣ��ѯ\n\n";
	Space();
	Space();
	cout << "4.ɾ��������Ϣ\n\n";
	Space();
	Space();
	cout << "5.�����ϼ��˵�\n\n";
	Star();
 
	// * ����ѡ��
	while (1)
	{
		cout << "��������Ҫѡ����еĲ�����";
		cin >> choice;
 
		system("cls");
		return choice;
	}
	return 0;
}
 
 
int PassagerWindowSelect()				// * �˿Ͳ˵�
{
	int choice;
 
	Star();
	Space();
	Space();
	cout << "��ӭ����˿�ϵͳ\n\n";
	Star();
	Space();
	Space();
	cout << "1.������Ϣ��ѯ\n\n";
	Space();
	Space();
	cout << "2.��Ʊ\n\n";
	Space();
	Space();
	cout << "3.��Ʊ\n\n";
	Space();
	Space();
	cout << "4.�����ϼ��˵�\n\n";
	Star();
 
	// * ����ѡ��
	while (1)
	{
		cout << "��������Ҫѡ����еĲ�����";
		cin >> choice;
 
		system("cls");
		return choice;
	}
	
	return 0;
}
 
 
// * �˳�����
int Quit()
{
	char judge;
	
	while (1)
	{
		cout << "\n\n\n";
		Space();
		Space();
		cout << "�Ƿ��˳�ϵͳ��y/n��:";
		cin >> judge;
 
		if (judge == 'y' || judge == 'Y')
		{
			system("cls");
			return 1;
		}
		if (judge == 'n' || judge == 'N')
		{
			system("cls");
			return 0;
		}
		system("cls");
	}
}
 
 
 
 
// * ����س�����
void Enter()
{
	int i;
 
	for (i = 0; i < 3; i++)
	{
		cout << endl;
	}
 
 
 
}
//����20���ո�
void Space()
{
	for (size_t i = 0; i < NUM1; i++)
	{
		cout << " ";
	}
}
 
 
//��������
void Star()
{
	Space();
	for (size_t i = 0; i < NUM2; i++)
	{
		cout << "*";
	}
	cout << "\n\n";
 
}