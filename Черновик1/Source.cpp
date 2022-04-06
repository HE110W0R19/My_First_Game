#include <iostream>
#include <random>
#include <string.h>
#include <stdio.h>
#include <conio.h>

using namespace std;
random_device Rand;

void create_map(char mas_player[10][10], char mas_enemy[10][10], char mas_computer[10][10], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			mas_player[i][j] = '-';
			mas_enemy[i][j] = '-';
			mas_computer[i][j] = '-';
		}
	}
}

void print_map(char mas_player[10][10], char mas_enemy[10][10], char mas_computer[10][10], int size)
{
	cout << "+-+-+- ���� ����� -+-+-+" << endl;
	for (int i = 0; i < size; i++) //����� �����
	{
		for (int j = 0; j < size; j++)
		{
			cout << mas_player[j][i] << ' ';
		}
		cout << endl;
	}
	cout << endl << "+-+-+- ����� ��������� -+-+-+" << endl;
	for (int i = 0; i < size; i++) //����� ����� ����� 
	{
		for (int j = 0; j < size; j++)
		{
			cout << mas_enemy[j][i] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	cout << "����� �����(���������)" << endl;
	for (int i = 0; i < size; i++) //����� ����� ����� 
	{
		for (int j = 0; j < size; j++)
		{
			cout << mas_computer[j][i] << ' ';
		}
		cout << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");

	const int map_size = 10;
	int x = 0, y = 0;
	int x_comp = 0, y_comp = 0;

	char mas_player[map_size][map_size] = {};
	char mas_computer[map_size][map_size] = {};
	char mas_enemy[map_size][map_size] = {};

	bool step = false;

	//���������� �����
	create_map(mas_player, mas_enemy, mas_computer, map_size);

	//���� ����� 5-���-�� �����
	for (int i = 0; i < 2; i++)
	{
		/*����������� ����� ������*/
		cout << "������� ���������� �����: " << endl;
		cin >> x;
		cin >> y;
		mas_player[x][y] = '#';

		/*����������� ����� ���������*/
		x_comp = Rand() % 10;
		y_comp = Rand() % 10;
		mas_computer[x_comp][y_comp] = '#';
	}

	//����� �����
	print_map(mas_player, mas_enemy, mas_computer, map_size);

	while (true)
	{
		if (step == false) //�������� �� ���� player
		{
			cout << "������� ���������� ����: ";
			cin >> x >> y;
			if (mas_computer[x][y] == '#')
			{
				cout << "���� ��������!" << endl;
				mas_computer[x][y] = 'x';
				mas_enemy[x][y] = 'x';
				system("cls"); //����� �����
				print_map(mas_player, mas_enemy, mas_computer, map_size);
			}
			else
			{
				system("cls"); //����� ����� 
				cout << "����!" << endl;
				mas_enemy[x][y] = 'P';
				print_map(mas_player, mas_enemy, mas_computer, map_size);
			}
			step = true;
		}

		if (step == true) //�������� �� ���� computer 
		{
			x_comp = Rand() % 10;
			y_comp = Rand() % 10;
			if (mas_player[x_comp][y_comp] == '#')
			{
				mas_player[x_comp][y_comp] = 'x';
			}
			else
			{
				mas_player[x_comp][y_comp] = 'E';
			}
			step = false;
		}
	}
	system("pause");
	return 0;
}