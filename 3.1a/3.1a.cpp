
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
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
		cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок

		cout << " Прізвище: "; cin >> s[i].lastname;
		cout << " Курс: "; cin >> s[i].cours;
		cout << " Спеціальність: "; cin >> s[i].spec;
		cout << " Оцінка з фізики: "; cin >> s[i].physic;
		cout << " Оцінка з математики: "; cin >> s[i].math;
		cout << " Оцінка з інформатики: "; cin >> s[i].informatic;
		cout << endl;
	}
}
void Print(Student* s, const int N)
{

	cout << "========================================================================="
		<< endl;
	cout << "| № | Прізвище | Курс | Спеціальність | Фізика | Математика | Інформатика | "
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
	cout << "середнії бал для :" << endl;
	cout << "фізики: " << avP / N << endl
		<< "математики: " << avM / N << endl
		<< "інформатики: " << avI / N;
}

int Count(Student* s, const int N)
{
	int count = 0;
	for (int i = 0; i < N; i++)
		if (s[i].physic > 3)
			count++;
	cout << "кількість студентів що з фізики отримати 4, 5 :\t" << count << endl;
	return count;
}

int main()
{

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "Введіть N: "; cin >> N;

	Student* s = new Student[N];

	Create(s, N);
	Print(s, N);

	int menuItem;

	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - Обчислити кількість студентів, " << endl;
		cout << " які отримали з фізики оцінки “5” або “4" << endl;
		cout << " [4] - обчислити середній бал для кожного пердмету" << endl << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
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
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);
	return 0;
}

