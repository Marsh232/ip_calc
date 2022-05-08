#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include "ConsoleColor.h"


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


void Submask(int submask);  // функция для счета сабмаски
int submask_10[4]{};
int submask_2[32]{};


void Subnet(int mask, int submask); // функция для подсчета подсетей
int subnet_10[4]{};
int subnet_2[32]{};
int subbroad_10[4]{};
int subbroad_2[32]{};
int num_subnet = 0;


void Nom_ip(int mask, int nom_ip_10); // функция считает ip по номеру
int nom_ip_10_2[4]{};
int bin_2[32]{};


void Nom_ip_net(int mask); // функция вывод вместе со всей инфой номер ip-шника 
int ip_net = 0;


void Up_net(int mask);


int main()
{
	setlocale(LC_ALL, "rus");

	START:
		char nom_ip;
		char vopros;
		string pipa;
		string oktet[5];

		int submask;
		int mask;
		int i = 0;
		int zxc = 0;
		int nworkn = workn[0];
		int nom_ip_10;

		int okt[4]{};

	
		cout << "\t\t\t//////////////////////////////////" << endl;
		cout << "\t\t\t//	IP Calculator v1.2	//" << endl;
		cout << "\t\t\t//	   by Trunov	        //" << endl;
		cout << "\t\t\t//////////////////////////////////" << endl << endl << endl;

		cout << "Пример ввода ip адреса: 192.168.16.2/24" << endl << endl;
	
		cout << "Введите ip адрес: ";
		cin >> pipa;

		pipa += '/';

		for (auto c : pipa)
		{
			if (c == '.' || c == '/')
			{
				if (i < 4)
				{
					try
					{
						okt[i] = stoi(oktet[i]); // если нашло точку или слеш преобразует ячейку стринг массива в инт и передает в ячейку инт массива 
					}
					catch (invalid_argument e)
					{
						cout << "Caught Invalid Argument Exception\n"; // если для преобразования получили invalid прикол, то выводится иди нахуй
					}
				}
				else if (i == 4)
				{
					try
					{
						mask = stoi(oktet[i]); 
					}
					catch (invalid_argument e)
					{
						cout << "Caught Invalid Argument Exception\n"; 
					}
				}
				i++; // если нашло точку или слеш произойдет перемешение заполняемых ячеек массивов
				continue;
			}
			else if (c >= '0' && c <= '9')
			{
				oktet[i] += c; // если нашло цифру передает в ячейку стринг массива
			}
		}
		if (mask > 32)
		{
			cout << "Вы ввели некорректную маску";
			return 0;
			cout << endl;
		}

		cout << "Ваш ip адрес: "<< blue << okt[0] << "." << okt[1] << "." << okt[2] << "." << okt[3] <<"/" << mask << white << "\t\t"; // вывод ip
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
		cout << "Маска: " << blue << mask_10[0] << "." << mask_10[1] << "." << mask_10[2] << "." << mask_10[3] << " = " << mask << red << "\t\t";

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
		cout << white;
		cout << endl << endl << endl;

		Network(mask); // вывод сети
		cout << "Network: " << blue << workn[0] << "." << workn[1] << "." << workn[2] << "." << workn[3] << "/" << mask << white << "\t\t";

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
		cout << endl;

		Broadcast(mask); // вывод броды
		cout << "Broadcast: " << blue << broad_10[0] << "." << broad_10[1] << "." << broad_10[2] << "." << broad_10[3] << white << "\t\t";

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
		cout << "HostMin: " << blue << workn[0] << "." << workn[1] << "." << workn[2] << "." << worknn << white << "\t\t\t";

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
		network[31] = 0;

		// вывод макс.Адрес
		int broad = broad_10[3] - 1;
		cout << "HostMax: " << blue << broad_10[0] << "." << broad_10[1] << "." << broad_10[2] << "." << broad << white << "\t\t\t";

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
		broad_2[31] = 1;

		// вывод кол-ва хостов

		cout << "Host/Net: " << blue << pow(2, (32 - mask)) - 2 << white << endl;

		Nom_ip_net(mask);
		cout << "№ в сети: " << blue << ip_net << white << endl << endl;

		cout << "Считать подсети? y/n: ";
		cin >> vopros;

		if (vopros == 'y')
		{
			cout << "Введите маску:";
			cin >> submask;
			cout << endl << endl << endl;

			cout << green << "Подсети" << white << endl << endl;

			Submask(submask); // вывод маски
			cout << "Маска: " << blue << submask_10[0] << "." << submask_10[1] << "." << submask_10[2] << "." << submask_10[3] << " = " << submask << red << "\t\t";

			for (int i = 0; i < 32; i++) // вывод двоички маски
			{
				if (mask <= i && i < submask)
				{
					cout << red;
				}
				else
				{
					cout << white;
				}
				if (i == submask)
				{
					cout << " ";
				}
				if (i == 8 || i == 16 || i == 24)
				{
					cout << "." << submask_2[i];
				}
				else
				{
					cout << submask_2[i];
				}
			}
		
			cout << endl << endl ;

			Subnet(mask, submask);
		}
		else if (vopros == 'n') 
		{ 
			cout << endl;
		}

		cout << "Хотите найти ip адрес по номеру? y/n: ";
		cin >> nom_ip;

		if (nom_ip == 'y')
		{
			cout << "Введите номер: ";
			cin >> nom_ip_10;

			cout << endl;
			Nom_ip(mask, nom_ip_10);
			cout << "IP адресс под № " << nom_ip_10 << ": " << blue << nom_ip_10_2[0] << "." << nom_ip_10_2[1] << "." << nom_ip_10_2[2] << "." << nom_ip_10_2[3] << "/" << mask << white << "\t\t";

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
			cout << endl << endl;
			system("pause");
		}
		else if (nom_ip == 'n')
		{
			cout << endl;
		}
		cout << endl;
		mask = 0;
		nom_ip_10 = 0;
		ip_net = 0;
		num_subnet = 0;
		for (int i = 0; i < 4; i++)
		{
			nom_ip_10_2[i] = 0;
			subnet_10[i] = 0;
			subbroad_10[i] = 0;
			submask_10[i] = 0;
			broad_10[i] = 0;
			workn[i] = 0;
			mask_10[i] = 0;
			okt[i] = 0;
			oktet[i] = " ";
		}
		for (int i = 0; i < 32; i++)
		{
			bin_2[i] = 0;
			subnet_2[i] = 0;
			subbroad_2[i] = 0;
			submask_2[i] = 0;
			mask_2[i] = 0;
			bin[i] = 0;
			broad_2[i] = 0;
			mask_2[i] = 0;
			network[i] = 0;
		}
	goto START;
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

void Submask(int submask)  // функция для счета сабмаски
{
	int b = 0;
	int d = 0;
	for (int i = 0; i < submask; i++)
	{
		submask_2[i] = 1;
	}
	for (; d < 4; d++)
	{
		int abuba = 128;
		for (int i = 0; i < 8; i++)
		{
			if (submask_2[b] == 1)
			{
				submask_10[d] += abuba;
				abuba /= 2;
			}
			else if (submask_2[b] == 0)
			{
				continue;
			}
			b++;
		}
	}
}

void Subnet(int mask, int submask)
{
	int all_num_host = 0;
	int num_host = (pow(2, (32 - submask))) - 2;
	int k = (pow(2, (submask - mask)));
	for (int i = 0; i < 32; i++)
	{
		subnet_2[i] = network[i];
	}

	for (int i = 0; i < k; i++)
	{
// ///////////////////////////////////////////////////////

		int n = 0;
		int net = 0;
		for (; net < 4; net++)
		{
			int abeba = 128;
			for (int i = 0; i < 8; i++)
			{
				if (subnet_2[n] == 1)
				{
					subnet_10[net] += abeba;
				}
				abeba /= 2;
				n++;
				continue;
			}
		}
		cout << "Network: " << blue << subnet_10[0] << "." << subnet_10[1] << "." << subnet_10[2] << "." << subnet_10[3] << "/" << submask << white << "\t\t";

		for (int i = 0; i < 32; i++) // вывод двоички сети
		{
			if (mask <= i && i < submask)
			{
				cout << red;
			}
			else
			{
				cout << white;
			}
			if (i == submask)
			{
				cout << " ";
			}
			if (i == 8 || i == 16 || i == 24)
			{
				cout << "." << subnet_2[i];
			}
			else
			{
				cout << subnet_2[i];
			}
		}
		cout << endl;

// ///////////////////////////////////////////////////////

		int brd = 0;
		int brdcst = 0;
		int submask2 = submask;
		for (int i = 0; i < 32; i++)
		{
			subbroad_2[i] = subnet_2[i];
		}
		for (; submask2 < 32; submask2++)
		{
			subbroad_2[submask2] = 1;
		}
		for (; brd < 4; brd++)
		{
			int ababa = 128;
			for (int i = 0; i < 8; i++)
			{
				if (subbroad_2[brdcst] == 1)
				{
					subbroad_10[brd] += ababa;
				}
				ababa /= 2;
				brdcst++;
				continue;
			}
		}
		cout << "Broadcast: " << blue << subbroad_10[0] << "." << subbroad_10[1] << "." << subbroad_10[2] << "." << subbroad_10[3] << white << "\t\t";

		for (int i = 0; i < 32; i++) // вывод двоички броды 
		{
			if (mask <= i && i < submask)
			{
				cout << red;
			}
			else
			{
				cout << white;
			}
			if (i == submask)
			{
				cout << " ";
			}
			if (i == 8 || i == 16 || i == 24)
			{
				cout << "." << subbroad_2[i];
			}
			else
			{
				cout << subbroad_2[i];
			}
		}
		cout << endl;

// ///////////////////////////////////////////////////////

		int subnet2_10 = subnet_10[3] + 1;
		cout << "HostMin: " << blue << subnet_10[0] << "." << subnet_10[1] << "." << subnet_10[2] << "." << subnet2_10 << white << "\t\t\t";

		subnet_2[31] = 1;
		for (int i = 0; i < 32; i++)
		{
			if (mask <= i && i < submask)
			{
				cout << red;
			}
			else
			{
				cout << white;
			}
			if (i == submask)
			{
				cout << " ";
			}
			if (i == 8 || i == 16 || i == 24)
			{
				cout << "." << subnet_2[i];
			}
			else
			{
				cout << subnet_2[i];
			}
		}
		subnet_2[31] = 0;
		cout << endl;
// ///////////////////////////////////////////////////////
		int subbroad = subbroad_10[3] - 1;
		cout << "HostMax: " << blue << subbroad_10[0] << "." << subbroad_10[1] << "." << subbroad_10[2] << "." << subbroad << white << "\t\t\t";

		subbroad_2[31] = 0;
		for (int i = 0; i < 32; i++)
		{
			if (mask <= i && i < submask)
			{
				cout << red;
			}
			else
			{
				cout << white;
			}
			if (i == submask)
			{
				cout << " ";
			}
			if (i == 8 || i == 16 || i == 24)
			{
				cout << "." << subbroad_2[i];
			}
			else
			{
				cout << subbroad_2[i];
			}
		}
		subbroad_2[31] = 1;
		cout << endl;

// ///////////////////////////////////////////////////////

		cout << "Host/Net: " << blue << num_host << white << endl << endl;

// ///////////////////////////////////////////////////////
		subnet_2[submask - 1] += 1;
		for (int j = submask - 1; mask <= j && j < submask; j--)
		{
			if (subnet_2[j] == 2)
			{
				subnet_2[j - 1] += 1;
				subnet_2[j] = 0;
				j++;
			}
		}
		num_subnet += 1;
		all_num_host += num_host;

		for (int i = 0; i < 4; i++)
		{
			subnet_10[i] = 0;
			subbroad_10[i] = 0;
		}

	}
	cout << endl << endl;
	cout << green << "Subnts: " << blue << num_subnet << endl << white;
	cout << "Hosts: " << blue << all_num_host << endl << endl << endl << white;
	system("pause");
	cout << endl << endl;
}

void Nom_ip(int mask, int nom_ip_10)
{
	int net_2 = 0;
	int n_2 = 0;
	int q = mask;
	int abuba = pow(2, (31-mask));
	for (int i = 31; i >= mask; i--)
	{
		if (nom_ip_10 >= abuba)
		{
			nom_ip_10 -= abuba;
			bin_2[i] = 1;
		}
		else if (nom_ip_10 <= abuba)
		{
			bin_2[i] = 0;
		}
		abuba /= 2;
	}
	for (int i = 31; i >= mask; i--)
	{
		network[i] = bin_2[q];
		q++;
	}
	for (; net_2 < 4; net_2++)
	{
		int abuba = 128;
		for (int i = 0; i < 8; i++)
		{
			if (network[n_2] == 1)
			{
				nom_ip_10_2[net_2] += abuba;
			}
			abuba /= 2;
			n_2++;
			continue;
		}
	}
}

void Nom_ip_net(int mask)
{
	int akaka = pow(2, (31 - mask));

	for (int i = mask; i < 32; i++)
	{
		if (bin[i] == 1)
		{
			ip_net += akaka;
		}
		akaka /= 2;
	}
}

void Up_net(int mask)
{

}