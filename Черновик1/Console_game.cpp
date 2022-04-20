#include <iostream>
#include <random>
#include <stdio.h>
#include <conio.h>

using namespace std;
random_device Rand;

void create_map(char**& mas_player, char**& mas_points, char**& mas_computer, char**& mas_points_2, short int size)
{
	for (int i = 0; i < 1; i++)
	{
		for (int j = 1; j < size; j++)
		{
			mas_player[i][j] = j + 48;
			mas_player[j][i] = j + 64;
			mas_points[i][j] = j + 48;
			mas_points[j][i] = j + 64;
			mas_points_2[i][j] = j + 48;
			mas_points_2[j][i] = j + 64;
			mas_computer[i][j] = j + 48;
			mas_computer[j][i] = j + 64;
		}
	}
	mas_player[0][10] = 48;	
	mas_points[0][10] = 48;
	mas_points_2[0][10] = 48;
	mas_computer[0][10] = 48;
	for (int i = 1; i < size; i++)
	{
		for (int j = 1; j < size; j++)
		{
			mas_player[i][j] = '~';
			mas_points[i][j] = '~';
			mas_points_2[i][j] = '~';
			mas_computer[i][j] = '~';
		}
	}
}

void print_map(char**& mas_player, char**& mas_points, char**& mas_computer, short int size)
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
			cout << mas_points[j][i] << ' ';
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

void print_map(char**& mas_player, short int size)
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
}

void print_map(char**& mas_player, char**& mas_points, short int size)
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
			cout << mas_points[j][i] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

void computer_boat(char**& mas_computer)
{
	int x_comp = 0, y_comp = 0;
	bool direction = false;
	//1-st boat
	for (int c = 0; c < 4; c++)
	{
		x_comp = Rand() % 10 + 1;
		y_comp = Rand() % 10 + 1;
		mas_computer[x_comp][y_comp] = '#';
	}
	//2-st boat
	for (int c = 0; c < 3; c++)
	{
		direction = Rand() % 2;
		x_comp = Rand() % 10 + 1;
		y_comp = Rand() % 10 + 1;
		for (int i = x_comp, j = y_comp; j < y_comp + 2; j++)
		{
			if (direction == true)
			{
				if (mas_computer[i][j] != '#')
				{
					mas_computer[i][j] = '#';
				}
				else
				{
					mas_computer[j][i] = '#';
				}
			}
			else if (direction == false)
			{
				if (mas_computer[i][j] != '#')
				{
					mas_computer[j][i] = '#';
				}
				else
				{
					mas_computer[j][i] = '#';
				}
			}
		}
	}
	//3-rd boat
	for (int c = 0; c < 2; c++)
	{
		direction = Rand() % 2;
		x_comp = Rand() % 10 + 1;
		y_comp = Rand() % 10 + 1;
		for (int i = x_comp, j = y_comp; j < y_comp + 3; j++)
		{
			if (direction == true)
			{
				if (mas_computer[i][j] != '#')
				{
					mas_computer[i][j] = '#';
				}
				else
				{
					mas_computer[j][i] = '#';
				}
			}
			else if (direction == false)
			{
				if (mas_computer[i][j] != '#')
				{
					mas_computer[j][i] = '#';
				}
				else
				{
					mas_computer[j][i] = '#';
				}
			}
		}
	}
	//4-rd boat
	direction = Rand() % 2;
	x_comp = Rand() % 10 + 1;
	y_comp = Rand() % 10 + 1;
	for (int i = x_comp, j = y_comp; j < y_comp + 4; j++)
	{
		if (direction == true)
		{
			if (mas_computer[i][j] != '#')
			{
				mas_computer[i][j] = '#';
			}
			else
			{
				mas_computer[j][i] = '#';
			}
		}
		else if (direction == false)
		{
			if (mas_computer[i][j] != '#')
			{
				mas_computer[j][i] = '#';
			}
			else
			{
				mas_computer[j][i] = '#';
			}
		}
	}
}

void add_boat(char**& mas_player)
{
	int x = 0, y = 0;
	bool direction = false;
	//����������� 1-�� �������� �����
	for (int c = 0; c < 4; c++)
	{
		cout << "������� ���������� 1-�������� �����" << endl;
		cout << "������� ����� �����: ";
		cin >> x;
		cout << "������� ����� �����: ";
		cin >> y;
		mas_player[x][y] = '#';
		print_map(mas_player,11);
	}
	system("cls");
	//����������� 2�� �������� �����
	for (int c = 0; c < 3; c++)
	{
		cout << "������� ����������� �����(0-����� �������, 1-������ ����): ";
		cin >> direction;
		cout << "������� ���������� 2-�������� �����" << endl;
		cout << "������� ����� �����: ";
		cin >> x;
		cout << "������� ����� �����: ";
		cin >> y;
		for (int i = x, j = y; j < y + 2; j++)
		{
			if (direction == true)
			{
				if (mas_player[i][j] != '#')
				{
					mas_player[i][j] = '#';
				}
				else
				{
					mas_player[i][j] = '#';
				}
			}
			else if (direction == false)
			{
				if (mas_player[j][i] != '#')
				{
					mas_player[j][i] = '#';
				}
				else
				{
					mas_player[j][i] = '#';
				}
			}
		}
		print_map(mas_player, 11);
	}
	system("cls");
	//����������� 3�� �������� �����
	for (int c = 0; c < 2; c++)
	{
		cout << "������� ����������� �����(0-����� �������, 1-������ ����): ";
		cin >> direction;
		cout << "������� ���������� 3-�������� �����" << endl;
		cout << "������� ����� �����: ";
		cin >> x;
		cout << "������� ����� �����: ";
		cin >> y;
		for (int i = x, j = y; j < y + 3; j++)
		{
			if (direction == true)
			{
				if (mas_player[i][j] != '#')
				{
					mas_player[i][j] = '#';
				}
				else
				{
					mas_player[i][j] = '#';
				}
			}
			else if (direction == false)
			{
				if (mas_player[j][i] != '#')
				{
					mas_player[j][i] = '#';
				}
				else
				{
					mas_player[j][i] = '#';
				}
			}
		}
		print_map(mas_player, 11);
	}
	system("cls");
	//������������ 4�� �������� �����
	cout << "������� ����������� �����(0-����� �������, 1-������ ����): ";
	cin >> direction;
	cout << "������� ���������� 4-�������� �����" << endl;
	cout << "������� ����� �����: ";
	cin >> x;
	cout << "������� ����� �����: ";
	cin >> y;
	for (int i = x, j = y; j < y + 4; j++)
	{
		if (direction == true)
		{
			if (mas_player[i][j] != '#')
			{
				mas_player[i][j] = '#';
			}
			else
			{
				mas_player[i][j] = '#';
			}
		}
		else if (direction == false)
		{
			if (mas_player[j][i] != '#')
			{
				mas_player[j][i] = '#';
			}
			else
			{
				mas_player[j][i] = '#';
			}
		}
	}
}

bool winer_check(char**& mas_player, short int player_num)
{
	int counter = 0;
	for (int i = 1; i < 11; i++)
	{
		for (int j = 1; j < 11; j++)
		{
			if (mas_player[i][j] == '#')
			{
				++counter;
			}
		}
	}
	if (counter == 0)
	{
		system("cls");
		cout << "\n\n\n\n\n";
		cout << "========== ����� ����� " << player_num << " �������! ==========" << endl;
		return true;
	}
	else
	{
		return false;
	}
}

void start_game_vs_pc(char**& mas_player, char**& mas_points, char**& mas_computer)
{
	int map_size = 11;
	int x = 0, y = 0;
	int x_comp = 0, y_comp = 0;
	char voice = 7;
	bool winer = false;
	bool step = false;
	while (true)
	{
		if (step == false) //�������� �� ���� player
		{
			cout << "������� ���������� ����" << endl;
			cout << "������� ����� �����: ";
			cin >> x;
			cout << "������� ����� �����: ";
			cin >> y;
			if (mas_computer[x][y] == '#')
			{
				cout << "���� ��������!" << endl;
				cout << voice;
				mas_computer[x][y] = 164;
				mas_points[x][y] = 164;
				system("cls"); //����� �����
				print_map(mas_player, mas_points, mas_computer, map_size);
				winer_check(mas_computer, winer);
				if (winer == true)
				{
					system("cls");
					cout << "========== �� ��������! ==========" << endl;
					break;
				}
				step = false;
			}
			else
			{
				system("cls"); //����� �����
				cout << "����!" << endl;
				mas_points[x][y] = 'P';
				print_map(mas_player, mas_points, mas_computer, map_size);
				step = true;
			}
		}

		if (step == true) //�������� �� ���� computer
		{
			x_comp = Rand() % 10+1;
			y_comp = Rand() % 10+1;
			if (mas_player[x_comp][y_comp] == '#')
			{
				cout << voice;
				mas_player[x_comp][y_comp] = 164;
				winer_check(mas_player, winer);
				if (winer == true)
				{
					system("cls");
					cout << "========== �� ���������! ==========" << endl;
					break;
				}
				step = true;
			}
			else
			{
				mas_player[x_comp][y_comp] = 'E';
				step = false;
			}
		}
	}
}

void start_game_1vs1(char**& mas_player_1, char**& mas_points_1, char**& mas_player_2, char**& mas_points_2)
{
	short int map_size = 11;
	short int x = 0, y = 0;
	char voice = 7;
	bool step = false;
	while (true)
	{
		if (step == false) //�������� �� ���� player_1
		{
			system("cls");
			print_map(mas_player_1, mas_points_1, map_size);
			cout << "========== ����� 1 ==========" << endl;
			cout << "������� ���������� ����" << endl;
			cout << "������� ����� �����: ";
			cin >> x;
			cout << "������� ����� �����: ";
			cin >> y;
			if (mas_player_2[x][y] == '#')
			{
				cout << "���� ��������!" << endl;
				cout << voice;
				mas_player_2[x][y] = 164;
				mas_points_1[x][y] = 164;
				system("cls"); //����� �����
				print_map(mas_player_1, mas_points_1, map_size);
				winer_check(mas_player_2, 1);
				if (winer_check(mas_player_2, 1)!=false)
				{
					return;
				}
				step = false;
				system("cls");
			}
			else
			{
				system("cls"); //����� �����
				cout << "����!" << endl;
				mas_points_1[x][y] = 'P';
				system("cls");
				step = true;
			}

		}
		if (step == true) //�������� �� ���� player_2
		{
			system("cls");
			print_map(mas_player_2, mas_points_2, map_size);
			cout << "========== ����� 2 ==========" << endl;
			cout << "������� ���������� ����" << endl;
			cout << "������� ����� �����: ";
			cin >> x;
			cout << "������� ����� �����: ";
			cin >> y;
			if (mas_player_1[x][y] == '#')
			{
				cout << "���� ��������!" << endl;
				cout << voice;
				mas_player_1[x][y] = 164;
				mas_points_2[x][y] = 164;
				system("cls"); //����� �����
				print_map(mas_player_2, mas_points_2, map_size);
				winer_check(mas_player_1, 2);
				if (!winer_check(mas_player_1, 2)!=false)
				{
					return;
				}
				step = true;
				system("cls");
			}
			else
			{
				system("cls"); //����� �����
				cout << "����!" << endl;
				mas_points_2[x][y] = 'P';
				system("cls");
				step = false;
			}

		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");

	short int choise;
	const short int map_size = 11;

	char** mas_player = new char* [map_size] {};
	char** mas_player_2 = new char* [map_size] {};
	char** mas_computer = new char* [map_size] {};
	char** mas_points = new char* [map_size] {};
	char** mas_points_2 = new char* [map_size] {};
	for (int i = 0; i < map_size; i++)//������������� ������������ ��������
	{
		mas_player[i] = new char[map_size] {};
		mas_player_2[i] = new char [map_size] {};
		mas_computer[i] = new char[map_size] {};
		mas_points[i] = new char[map_size] {};
		mas_points_2[i] = new char[map_size] {};
	}

	cout << "===============================================" << endl;
	cout << "---          ������� ��� 1vs1               ---" << endl;
	cout << "---        �������� ����� ����:             ---" << endl;
	cout << "---    1 - 1 �� 1 (��� ������)              ---" << endl;
	cout << "---    2 - ��������� ����(������ ���������) ---" << endl;
	cout << "---    0 - ����� �� ����                    ---" << endl;
	cout << "===============================================" << endl;
	cin >> choise;
	switch (choise)
	{
	case 1:
		create_map(mas_player, mas_points, mas_player_2, mas_points_2, map_size);
		cout << endl << "========== ����� 1 ==========" << endl;
		add_boat(mas_player);
		cout << endl << "========== ����� 2 ==========" << endl;
		add_boat(mas_player_2);
		start_game_1vs1(mas_player, mas_points, mas_player_2, mas_points_2);
		return main();
		break;
	case 2:
		create_map(mas_player, mas_points, mas_computer, mas_points, map_size);
		cout << "========== ���������� ����� ==========" << endl;
		add_boat(mas_player);
		computer_boat(mas_computer);
		print_map(mas_player, mas_points, mas_computer, map_size);
		start_game_vs_pc(mas_player, mas_points, mas_computer);
		return main();
		break;
	case 0:
		system("cls");
		delete[] mas_player;
		delete[] mas_player_2;
		delete[] mas_computer;
		delete[] mas_points;
		delete[] mas_points_2;
		cout << "=========             =========="
			<< "========== Good bye! ==========="
			<< "=========             ==========" << endl;
		return 0;
		break;
	default:
		return 0;
		break;
	}

	system("pause");
	return 0;
}
