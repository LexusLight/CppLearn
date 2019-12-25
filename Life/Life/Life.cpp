// Life.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <string>


using namespace std;


class Field{
	string map[22][22];
public:
	Field (vector<int> VecX, vector<int> VecY , int C) {
		for (int i = 0; i < C; i++) {
			int x1 = VecX.back();
			int y1 = VecY.back();
			VecX.pop_back();
			VecY.pop_back();
			map[y1][x1] = "@ ";
		}
		PrintMap();
	}

	void PrintMap() {
		for (int i = 1; i < 21; i++) {
			for (int j = 1; j < 21; j++) {
				if (map[i][j] == "@ ") {
					cout << map[i][j];
				}
				else {
					cout << "  ";
				}
			}
			cout << endl;
		}

	}

	void CycleMap() {
		string cycle_map[22][22];
		int sum = 0; //количество живых клеток
		for (int i = 1; i < 21; i++) {
			sum = 0;
			for (int j = 1; j < 21; j++) {
				sum = 0;
				sum += (map[i - 1]	[j ] == "@ ") ? 1 : 0;
				sum += (map[i - 1]	[j + 1] == "@ ") ? 1 : 0;
				sum += (map[i]		[j + 1] == "@ ") ? 1 : 0;
				sum += (map[i + 1]	[j+1] == "@ ") ? 1 : 0;
				sum += (map[i + 1]	[j] == "@ ") ? 1 : 0;
				sum += (map[i+1]	[j - 1] == "@ ") ? 1 : 0;
				sum += (map[i]		[j - 1] == "@ ") ? 1 : 0;
				sum += (map[i - 1]	[j - 1] == "@ ") ? 1 : 0;

				if (map[i][j] != "@ ") {//мёртвая клетка
					if (sum == 3) {
						cycle_map[i][j] = "@ ";
					}
					else {
						cycle_map[i][j] = "  ";
					}
				}
				else {//живая клетка
					if (sum == 3 || sum == 2) {
						cycle_map[i][j] = "@ ";
					}
					if (sum < 2 || sum > 3) {
						cycle_map[i][j] = "  ";
					}
				}
			}
		}

		for (int i = 1; i < 21; i++) {
			sum = 0;
			for (int j = 1; j < 21; j++) {
				map[i][j] = cycle_map[i][j];
			}
		}

			

		Sleep(1000);
		system("cls");
		PrintMap();

		CycleMap();
	}

	~Field() {

	}
};

int main()
{	
	SetConsoleCP(1251); //В свойствах консоли должен стоять шрифт Lucida
	SetConsoleOutputCP(1251);
	int count;
	int y;
	int x;
	int aut;
	vector<int> VX;
	vector<int> VY;

	cout << "Выберите действие:" << endl << "1. Автоматическая задача." << endl << "2. Задать самому." << endl;
	cin >> aut;
	system("cls");
	if(aut == 2){
		for (int i = 0; i < 20; i++) {	//Показываем структуру поля
				for (int j = 0; j < 20; j++) {
					cout << "* ";
				}
				cout << endl;
		}
		cout << "Поле 20 на 20." << endl;
		cout << "Введите число изначительных клеток:" << endl;
		cin >> count;
		system("cls");
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				cout << "* ";
			}
			cout << endl;
		}
		for (int i = 1; i < count + 1; i++) {	//Вносим координаты клеток и выводим их расположение
		cout << "Введите X " << i << " клетки:" << endl;
		cin >> x;
		VX.push_back(x);

		cout << "Введите Y " << i << " клетки:" << endl;
		cin >> y;
		VY.push_back(y);
		system("cls");

		Field *LF = new Field(VX,VY,i);
		LF->~Field();
		}
	}
	else if (aut == 1) {
		VX.push_back(3);// Это глайдер
		VX.push_back(1);
		VX.push_back(3);
		VX.push_back(2);
		VX.push_back(3);

		VY.push_back(1);
		VY.push_back(2);
		VY.push_back(2);
		VY.push_back(3);
		VY.push_back(3);

		VX.push_back(8);// Это глайдер этот глайдер и первый делают крутую систему
		VX.push_back(6);
		VX.push_back(8);
		VX.push_back(7);
		VX.push_back(8);

		VY.push_back(2);
		VY.push_back(3);
		VY.push_back(4);
		VY.push_back(3);
		VY.push_back(4);

		VX.push_back(16);// Это Осцилирация
		VX.push_back(16);
		VX.push_back(17);
		VX.push_back(15);

		VY.push_back(13);
		VY.push_back(14);
		VY.push_back(14);
		VY.push_back(14);

		VX.push_back(13);// Это глайдер
		VX.push_back(11);
		VX.push_back(13);
		VX.push_back(12);
		VX.push_back(13);

		VY.push_back(1);
		VY.push_back(2);
		VY.push_back(2);
		VY.push_back(3);
		VY.push_back(3);
		system("cls");

		count = 19;
	}
	

	system("cls");
	Field *MP = new Field(VX, VY, count);
	MP->CycleMap();
}

