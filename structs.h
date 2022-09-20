#pragma once
#include <iostream>
#include "processing.h"

using namespace std;

enum StartMenu
{
	SHOW_CARS = 1,
	MY_BALANCE = 2,
	CHOICE_CAR = 3,
	SHOW_CHOICES_CAR = 4,
	SHOW_APPLICATION_CLIENT = 5,
	CREATE_APLICATION = 6,
	ADMIN_PANEL = 7,
	RE_ENTER_PASSWORD = 8,
	EXIT = 9
};

enum AdminMenu
{
	SHOW_APPLICATION_ADMIN = 10,
	CHANGE_STATUS_APPLICATION = 11,
	EXIT_ADMIN = 12
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
	unsigned long long _id;
	CarsStruct car;
	string fullname;
	string pasport_id;
	string lease_term;
	string status;
	
	void print_application() {
		cout
			<< "ID order: " << _id << endl
			<< "Your full name: " << fullname << endl
			<< "Your passport ID: " << pasport_id << endl
			<< "Your lease_term: " << lease_term << endl << endl
			<< "Car info" << endl
			<< car.brand << " " << car.model << endl
			<< "Cost: " << car.price << endl
			<< "Status: " << status << endl << endl;
	}
};
