
#include <iostream>
#include <string>
#include <iomanip>
#include <locale>
#include <Windows.h> 

using namespace std;



struct Student
{
	string lastname;
	string cours;
	string spec;
	int physic;
	int math;
	int informatic;
};

void Create(Student* s, const int N)

{

	for (int i = 0; i < N; i++)
	{
		cout << "������� � " << i + 1 << ":" << endl;
		cin.get(); // ������� ����� ��������� � �� ����������� �������
		cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� �����

		cout << " �������: "; cin >> s[i].lastname;
		cout << " ����: "; cin >> s[i].cours;
		cout << " ������������: "; cin >> s[i].spec;
		cout << " ������ � ������: "; cin >> s[i].physic;
		cout << " ������ � ����������: "; cin >> s[i].math;
		cout << " ������ � �����������: "; cin >> s[i].informatic;
		cout << endl;
	}
}
void Print(Student* s, const int N)
{

	cout << "========================================================================="
		<< endl;
	cout << "| � | ������� | ���� | ������������ | Գ���� | ���������� | ����������� | "
		<< endl;
	cout << "-------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << " ";
		cout << "| " << setw(9) << left << s[i].lastname
			<< "| " << setw(4) << right << s[i].cours << " "
			<< "| " << setw(11) << left << s[i].spec << " "
			<< "| " << setw(6) << right << s[i].physic << " "
			<< "| " << setw(6) << left << s[i].math << " "
			<< "| " << setw(7) << right << s[i].informatic << endl;
	}
	cout << "========================================================================="
		<< endl;
	cout << endl;
}
void Avarage(Student* s, const int N)
{
	double avP = 0.0, avM = 0.0, avI = 0.0;
	for (int i = 0; i < N; i++)
	{
		avP += (double)s[i].physic;
		avM += (double)s[i].math;
		avI += (double)s[i].informatic;
	}
	cout << "������ ��� ��� :" << endl;
	cout << "������: " << avP / N << endl
		<< "����������: " << avM / N << endl
		<< "�����������: " << avI / N;
}

int Count(Student* s, const int N)
{
	int count = 0;
	for (int i = 0; i < N; i++)
		if (s[i].physic > 3)
			count++;
	cout << "������� �������� �� � ������ �������� 4, 5 :\t" << count << endl;
	return count;
}

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "������ N: "; cin >> N;

	Student* s = new Student[N];

	Create(s, N);
	Print(s, N);

	int menuItem;

	do {
		cout << endl << endl << endl;
		cout << "������� ��:" << endl << endl;
		cout << " [1] - �������� ����� � ���������" << endl;
		cout << " [2] - ���� ����� �� �����" << endl;
		cout << " [3] - ��������� ������� ��������, " << endl;
		cout << " �� �������� � ������ ������ �5� ��� �4" << endl;
		cout << " [4] - ��������� ������� ��� ��� ������� ��������" << endl << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> menuItem;
		cout << endl << endl << endl;


		switch (menuItem)
		{
		case 1:
			Create(s, N);
			break;
		case 2:
			Print(s, N);
			break;
		case 3:
			Count(s, N);
			break;
		case 4:
			Avarage(s, N);
			break;
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! "
				"��� ������ ����� - ����� ��������� ������ ����" << endl;
		}
	} while (menuItem != 0);
	return 0;
}

