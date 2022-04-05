#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <windows.h>


using namespace std;


void Schet(int okt[]); // функция для перевода "октета" в двоичку
int bin[32]{};


void Mask(int mask); // функция для маски
int mask_2[32]{};
int mask_10[4]{};


void Network(int mask); // функция для подсчёта сети
int network[32]{};
int workn[4]{};


void Broadcast(int mask); // функция для подсчета броды
int broad_10[4]{};
int broad_2[32]{};


int main()
{
	setlocale(LC_ALL, "rus");

	string pipa;
	string oktet[4];
	int mask;
	int i = 0;
	int zxc = 0;

	int okt[4]{};

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

	cout << "Ваш ip адрес: " + pipa << mask << "\t"; // вывод ip
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

	Mask(mask); // вывод маски
	cout << "Маска: " << mask_10[0] << "." << mask_10[1] << "." << mask_10[2] << "." << mask_10[3] << " = " << mask << "\t";

	for (int i = 0; i < 32; i++) // вывод двоички маски
	{
		if (i == mask)
		{
			cout << " ";
		}
		if (i == 8 || i == 16 || i == 24)
		{
			cout << "." << mask_2[i];
		}
		else
		{
			cout << mask_2[i];
		}
	}
	cout << endl << endl << endl;

	Network(mask); // вывод сети
	cout << "Network: " << workn[0] << "." << workn[1] << "." << workn[2] << "." << workn[3] << "/" << mask << "\t";

	for (int i = 0; i < 32; i++) // вывод двоички сети
	{
		if (i == mask)
		{
			cout << " ";
		}
		if (i == 8 || i == 16 || i == 24)
		{
			cout << "." << network[i];
		}
		else
		{
			cout << network[i];
		}
	}
	if (0 < workn[0] < 128)
	{
		cout << "(Class A)";
	}
	else if (128 < workn[0] < 192)
	{
		cout << "(Class B)";
	}
	else if (192 < workn[0] < 224)
	{
		cout << "(Class C)";
	}
	else if (224 < workn[0] < 240)
	{
		cout << "(Class D)";
	}
	else if (240 < workn[0])
	{
		cout << "(Class E)";
	}
	cout << endl;

	Broadcast(mask); // вывод броды
	cout << "Broadcast: " << broad_10[0] << "." << broad_10[1] << "." << broad_10[2] << "." << broad_10[3] << "/" << mask << "\t";

	for (int i = 0; i < 32; i++) // вывод двоички броды 
	{
		if (i == mask)
		{
			cout << " ";
		}
		if (i == 8 || i == 16 || i == 24)
		{
			cout << "." << broad_2[i];
		}
		else
		{
			cout << broad_2[i];
		}
	}
	cout << endl;

	// вывод мин.Адрес
	int worknn = workn[3] + 1;
	cout << "HostMin: " << workn[0] << "." << workn[1] << "." << workn[2] << "." << worknn << "/" << mask << "\t";

	network[31] = 1;
	for (int i = 0; i < 32; i++)
	{
		if (i == mask)
		{
			cout << " ";
		}
		if (i == 8 || i == 16 || i == 24)
		{
			cout << "." << network[i];
		}
		else
		{
			cout << network[i];
		}
	}
	cout << endl;

	// вывод макс.Адрес
	int broad = broad_10[3] - 1;
	cout << "HostMax: " << broad_10[0] << "." << broad_10[1] << "." << broad_10[2] << "." << broad << "/" << mask << "\t";

	broad_2[31] = 0;
	for (int i = 0; i < 32; i++)
	{
		if (i == mask)
		{
			cout << " ";
		}
		if (i == 8 || i == 16 || i == 24)
		{
			cout << "." << broad_2[i];
		}
		else
		{
			cout << broad_2[i];
		}
	}
	cout << endl;

	// вывод кол-ва хостов

	cout << "Host/Net: ";
	system("color c1");
	cout << pow(2, (31 - mask)) << endl << endl;
}

void Schet(int okt[]) // функция для перевода "октета" в двоичку
{
	int m = 0;
	int a = 0;
	for (; a < 4; a++)
	{
		int abiba = 128;
		for (int i = 0; i < 8; i++)
		{
			if (okt[a] >= abiba)
			{
				okt[a] -= abiba;
				bin[m] = 1;
			}
			else if (okt[a] <= abiba)
			{
				bin[m] = 0;
			}
			abiba /= 2;
			m++;
		}
	}
}

void Mask(int mask)  // функция для счета маски
{
	int b = 0;
	int d = 0;
	for (int i = 0; i < mask; i++)
	{
		mask_2[i] = 1;
	}
	for (; d < 4; d++)
	{
		int aboba = 128;
		for (int i = 0; i < 8; i++)
		{
			if (mask_2[b] == 1)
			{
				mask_10[d] += aboba;
				aboba /= 2;
			}
			else if (mask_2[b] == 0)
			{
				continue;
			}
			b++;
		}
	}
}

void Network(int mask) // функция для счета сети
{
	int n = 0;
	int net = 0;
	for (int i = 0; i < mask; i++)
	{
		network[i] = bin[i];
	}
	for (; net < 4; net++)
	{
		int abeba = 128;
		for (int i = 0; i < 8; i++)
		{
			if (network[n] == 1)
			{
				workn[net] += abeba;
			}
			abeba /= 2;
			n++;
			continue;
		}
	}
}

void Broadcast(int mask) // функция для счета броды
{
	int brd = 0;
	int brdcst = 0;
	for (int i = 0; i < 32; i++)
	{
		broad_2[i] = network[i];
	}
	for (; mask < 32; mask++)
	{
		broad_2[mask] = 1;
	}
	for (; brd < 4; brd++)
	{
		int ababa = 128;
		for (int i = 0; i < 8; i++)
		{
			if (broad_2[brdcst] == 1)
			{
				broad_10[brd] += ababa;
			}
			ababa /= 2;
			brdcst++;
			continue;
		}
	}
}