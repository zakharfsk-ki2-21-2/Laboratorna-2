#pragma once
#include <iostream>
#include <string>

using namespace std;

enum StartMenu
{
	SHOW_CARS = 1,
	CHOICE_CAR = 2,
	SHOW_CHOICES_CAR = 3,
	CREATE_APLICATION = 4,
	EXIT = 5
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
				<< endl << "Number: " << id_car << endl
				<< "Brand: " << brand << endl
				<< "Model: " << model << endl
				<< "Year: " << year << endl
				<< "Max speed: " << speed << endl
				<< "Cost to retal: " << price << " UAH" << endl << endl;
	};
};

struct ApplicationStruct
{
	int _id;
	CarsStruct car;
	string fullname;
	string pasport_id;
	string lease_term;
	
	void print_application() {
		cout
			<< "ID order: " << _id << endl
			<< "Your full name: " << fullname << endl
			<< "Your passport ID: " << pasport_id << endl
			<< "Your lease_term: " << endl << endl
			<< "Car info" << endl
			<< car.brand << " " << car.model << endl
			<< "Cost: " << car.price << endl << endl;
	}
	
};
