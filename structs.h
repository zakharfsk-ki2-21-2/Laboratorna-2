#pragma once
#include <iostream>
#include <string>

using namespace std;

enum StartMenu
{
	SHOW_CARS = 1,
	CHOICE_CAR = 2,
	EXIT = 3
};

struct CarsStruct
{
	int id_car;
	long int price;
	string brand;
	string model;
	int year;
	int speed;
	bool rent;
	void printCar() {
		if (bool(rent) == false)
			cout
				<< "Number: " << id_car
				<< "\n"
				<< "Brand: " << brand
				<< "\n"
				<< "Model: " << model
				<< "\n"
				<< "Year: " << year
				<< "\n"
				<< "Max speed: " << speed
				<< "\n"
				<< "Cost to retal: " << price << " UAH"
				<< "\n\n";
	};
};

struct AplicationStruct
{
	int _id;
	CarsStruct car;
	string fullname;
	string pasport_id;
	string lease_term;
};
