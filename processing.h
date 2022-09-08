#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "structs.h"

using namespace std;


class Cars {
private:
	CarsStruct* cars;
	long int size_struct;

public:
	/* Constructors */
	Cars() {};
	Cars(CarsStruct* c, int size_str) {
		cars = new CarsStruct[size_struct];
		cars = c;
		size_struct = size_str;
	};
	/* End Constructors */

	/* Getters and Setters */
	void setCars(CarsStruct* cars) {
		this->cars = cars;
	}
	CarsStruct* getCars() {
		return this->cars;
	}

	void setSizeStruct(int _size) {
		this->size_struct = _size;
	}
	int getSizeStruct() {
		return this->size_struct;
	}
	/* End Getters and Setters */

	/* Methods */
	/* Methods */
};

class Aplications {
private:
	string paspot_id;
	string fullname;
	AplicationStruct* aplications;
	
public:
	/* Constructors */
	Aplications() {};
	Aplications(string fullname, string pasp_id) {
		this->fullname = fullname;
		this->paspot_id = pasp_id;
	};
	/* End Constructors */
	
	/* Getters and Setters */
	void setFullNameApp(string fullname) { this->fullname = fullname; };
	string getFullNameApp() { return this->fullname; };
	
	void setPasportIdApp(string pass_id) { this->paspot_id = pass_id; };
	string getPasportIdApp() { return this->paspot_id; };
	
	void setAplications(AplicationStruct aplc_struct) { this->aplications = new AplicationStruct(aplc_struct); };
	AplicationStruct* getAplications() { return this->aplications; };
	/* End Getters and Setters */

	/* Methods */
	void createAplication(AplicationStruct aplication) {
		ofstream file;
		file.open("aplications.txt", ios::app);
		file << aplication._id << " "
			<< aplication.car.id_car << " "
			<< aplication.car.brand << " " 
			<< aplication.car.model << " " 
			<< aplication.car.year << " " 
			<< aplication.car.price << " " 
			<< aplication.fullname << " "
			<< aplication.pasport_id << " " 
			<< aplication.lease_term 
			<< endl;
		file.close();
	};
	/* End Methods */
};

class Man {
private:
	string name;
	string surname;
	string password;
	string adminpass = "admin";
	
public:
	/* Constructors */
	Man() {};
	Man(string name, string surname, string password) {
			this->name = name;
			this->surname = surname;
			this->password = password;
		};
	/* End Constructors */
		
	/* Getters and Setters */
	string getPassword() { return this->password; };
	string getFullName() { return this->name + " " + this->surname; };
	void setNamae(string name) { this->name = name; };
	void setSurname(string surname) { this->surname = surname; };
	void setPassword(string password) { this->password = password; };
	/* End Getters and Setters */
		
	/* Methods */
	bool is_admin() { return this->password == this->adminpass; };
	/* End Methods */
};

class Client : public Man {
private:
	string pasport_id;
	CarsStruct choice_client_car;
		
public:
	/* Constructors */
	Client(string name, string surname, string password) : Man(name, surname, password) {};
	Client(string name, string surname, string password, string pasp_id) : Man(name, surname, password) {
		this->pasport_id = pasp_id;
	};
	/* End Constructors */
		
	/* Getters and Setters */
	string getPasportId() { return this->pasport_id; };
	void setPasportId(string pasport_id) { this->pasport_id = pasport_id; };

	CarsStruct getChoiceClientCar() { return this->choice_client_car; };
	void setChoiceClientCar(CarsStruct choice_client_car) { this->choice_client_car = choice_client_car; };
	/* End Getters and Setters */
	
	/* Methods */
	CarsStruct getCarByNumber(Cars* cars, int number) {
		CarsStruct* c = cars->getCars();
		for (int i = 0; i < cars->getSizeStruct(); i++) {
			if (c[i].id_car == number) {
				return c[i];
			};
		};
	};
	void showCars(Cars* cars) {
		CarsStruct* c = cars->getCars();
		for (int i = 0; i < cars->getSizeStruct(); i++) {
			c[i].printCar();
		};
	};
	/* End Methods */
};
	
class Administrator : public Man {
private:

public:
	Administrator(string name, string surname, string password) : Man(name, surname, password) {};
	
	void showApplications() {
		if (this->is_admin()) {
			return;
		}
	};
};
