#pragma once
#include <cstring>
#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;

struct Card
{
	char name[50] = "undefined";	//Прізвище клієнта
	unsigned long number = 0;		//Номер рахунку
	double cash = 0;				//Сума коштів на рахунку

	void createCard() {
		cout << "Input your name: ";
		cin.getline(name, 50); //Зчитування рядку з пробілами
		number = rand() * 100'000 + rand();
		cout << "Topup your cash (UAH): ";
		cin >> cash;
	}

	void showCard() {
		cout << "+++++++++++++++++++++++++++++++++++++\n";
		cout << "| Client: " << name << endl;
		cout << "| Card:   " << number << endl;
		cout << "| Cash:   " << cash << " UAH" << endl;
		cout << "+++++++++++++++++++++++++++++++++++++\n";
	}
};