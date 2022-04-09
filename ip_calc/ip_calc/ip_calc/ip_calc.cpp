#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int a = 0;
int d = 0;
int Net = 0;
int n, b, N;
int network[32]{};
int workn[4]{};
int bin[32]{};
int musk[32]{};
int mesk[4]{};

void Network(int mask);
void Schet(int okt[]); // функция для перевода "октета" в двоичку
void Mask(int mask); // функция для маски

int main()
{
    setlocale(LC_ALL, "rus");

	string pipa;
	string oktet[4];
    int mask;
	int i = 0;
	int zxc = 0;

	int okt[4]={};

	cout << "Пример ввода ip адреса: 192.168.16.2/" << endl << endl;
	
	cout << "Введите ip адрес: ";
	getline(cin, pipa);

	cout << "Введите маску: ";
	cin >> mask;
	cout << endl;

	if (mask > 32)
	{
		cout << "Вы ввели некорректную маску";
		return 0;
		cout << endl;
	}

	for (auto c : pipa)
	{
		if (c == '.' || c == '/')
		{
			try
			{
				okt[i] = stoi(oktet[i]); // если нашло точку или слеш преобразует ячейку стринг массива в инт и передает в ячейку инт массива 
			}
			catch (invalid_argument e)
			{
				cout << "Caught Invalid Argument Exception\n"; // если для преобразования получили invalid прикол, то выводится иди нахуй
			}
			i++; // если нашло точку или слеш произойдет перемешение заполняемых ячеек массивов
			continue;
		}
		else if (c >= '0' && c <= '9')
		{
			oktet[i] += c; // если нашло цифру передает в ячейку стринг массива
		}
	}

	cout << "Ваш ip адрес: " + pipa << mask << "\t";
	Schet(okt);

	for (int i = 0; i < 32; i++) // вывод двоички ip
	{
		if (i == mask)
		{
			cout << " ";
		}
		if (i == 8 || i == 16 || i == 24)
		{
			cout << "." << bin[i];
		}
		else
		{
			cout << bin[i];
		}
	}
	cout << endl << endl;

	Mask(mask);
	cout << "Маска: " << mesk[0] << "." << mesk[1] << "." << mesk[2] << "." << mesk[3] << " = " << mask << "\t";

	for (int i = 0; i < 32; i++) // вывод двоички маски
	{
		if (i == mask)
		{
			cout << " ";
		}
		if (i == 8 || i == 16 || i == 24)
		{
			cout << "." << musk[i];
		}
		else
		{
			cout << musk[i];
		}
	}
	cout << endl;

	Network(mask);
	cout << "Network: " << workn[0] << "." << workn[1] << "." << workn[2] << "." << workn[3] << "/" << mask;
}

void Schet(int okt[]) // функция для перевода "октета" в двоичку
{
	for (; a < 4; a++)
	{
		int abiba = 128;
		for (int i = 0; i < 8; i++)
		{
			if (okt[a] >= abiba)
			{
				okt[a] -= abiba;
				bin[n] = 1;
			}
			else if (okt[a] <= abiba)
			{
				bin[n] = 0;
			}
			abiba /= 2;
			n++;
		}
	}
}

void Mask(int mask) 
{
	for (int i = 0; i < mask; i++)
	{
		musk[i] = 1;
	}
	for (; d < 4; d++)
	{
		int aboba = 128;
		for (int i = 0; i < 8; i++)
		{
			if (musk[b] == 1)
			{
				mesk[d] += aboba;
				aboba /= 2;
			}
			else if (musk[b] == 0)
			{
				continue;
			}
			b++;
		}
	}
}

void Network(int mask)
{
	for (int i = 0; i < mask; i++)
	{
		network[i] = bin[i];
	}
	for (; Net < 4; Net++)
	{
		int abeba = 128;
		for (int i = 0; i < 8; i++)
		{
			if (network[N] == 1)
			{
				workn[Net] += abeba;
				abeba /= 2;
				N++;
			}
			if (network[N] == 0)
			{
				N++;
				continue;
			}
		}
	}
}