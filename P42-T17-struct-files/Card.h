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

	void saveToTextFile(FILE* file) {
		fprintf(file, "\n%s \n%ul \n%0.2lf", name, number, cash);
	}
	void loadFromTextFile(FILE* file) {
		fscanf_s(file, "\n");
		fgets(name, 50, file);//"Golovina Valeria \n"
		name[strlen(name) - 1] = '\0'; //        \n -> \0
		fscanf_s(file, "%ul %lf", &number, &cash);
	}

	void saveToBinFile(FILE* file) {
		int sizename = strlen(name) + 1;
		fwrite(&sizename, sizeof(int), 1, file);	//save name
		fwrite(name, sizeof(char), sizename, file);
		fwrite(&number, sizeof(unsigned long), 1, file); //save number
		fwrite(&cash, sizeof(double), 1, file);			//save cash
	}

	void loadFromBinFile(FILE* file) {
		int sizename = 0;
		fread(&sizename, sizeof(int), 1, file);
		fread(name, sizeof(char), sizename, file);
		fread(&number, sizeof(unsigned long), 1, file);
		fread(&cash, sizeof(double), 1, file);
	}
};