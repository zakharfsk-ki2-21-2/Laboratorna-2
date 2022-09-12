#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include "structs.h"

using namespace std;


class Client;
class Cars;
class Application;
class Man;
class Administrator;


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
	void updateCarsStatus(CarsStruct cars) {
		for (int i = 0; i < getSizeStruct(); i++)
		{
			cout << "cars.id_car " << cars.id_car << endl;
			cout << "this->cars[i].id_car " << this->cars[i].id_car << endl;
			if (cars.id_car == this->cars[i].id_car)
			{
				cout << "Change status";
				this->cars[i].rent = true;
			}
		}
	}
	/* Methods */
};

class Applications {
private:
	string paspot_id;
	string fullname;
	string lease_term;
	Cars cars_app;
	vector<ApplicationStruct> aplications;

public:
	/* Constructors */
	Applications() {};
	Applications(string fullname, string pasp_id, string lease_term) {
		this->fullname = fullname;
		this->paspot_id = pasp_id;
		this->lease_term = lease_term;
	};
	/* End Constructors */

	/* Getters and Setters */
	void setFullNameApp(string fullname) { this->fullname = fullname; };
	string getFullNameApp() { return this->fullname; };

	void setApplications(ApplicationStruct aplc_struct) { this->aplications.push_back(aplc_struct); };
	vector<ApplicationStruct> getApplications() { return this->aplications; };

	void setCars(Cars cars) { this->cars_app = cars; };

	void setLeaseTerm(string lease_term) { this->lease_term = lease_term; };
	string getLeaseTerm() { return this->lease_term; };
	/* End Getters and Setters , const string filepath*/

	/* Methods */
	void file_txt(ApplicationStruct application, const string filepath)
	{
		ofstream file(filepath, ios::app);
		file
			<< "ID order: " << application._id << endl
			<< "Your full name: " << application.fullname << endl
			<< "Your passport ID: " << application.pasport_id << endl
			<< "Your lease_term: " << endl << endl
			<< "Car info" << endl
			<< application.car.brand << " " << application.car.model << endl
			<< "Cost: " << application.car.price
			<< endl << endl;
		file.close();
	}
	void file_dat(ApplicationStruct application, const string filepath)
	{
		ofstream file(filepath, ios::out | ios::binary | ios::app);
		for (int i = 0; i < this->aplications.size(); i++)
		{
			file << setw(12) << 
				this->aplications[i]._id << setw(10) << 
				this->aplications[i].fullname << setw(10) << 
				this->aplications[i].pasport_id << setw(10) << 
				this->aplications[i].lease_term << endl;
		}
		file.close();
	}
	void createAplication(ApplicationStruct application) {
		file_txt(application, "aplications.txt");
		file_dat(application, "aplications.dat");
		setApplications(application);
		this->cars_app.updateCarsStatus(application.car);
	};
	/* End Methods */
};

class Man {
private:
	string name;
	string surname;
	string password;
	string adminpass = "admin";
	long int money;
	
public:
	/* Constructors */
	Man() {};
	Man(string name, string surname, string password) {
			this->name = name;
			this->surname = surname;
			this->password = password;
			this->money = 5000;
		};
	/* End Constructors */
		
	/* Getters and Setters */
	string getPassword() { return this->password; };
	string getFullName() { return this->name + " " + this->surname; };
	
	long int getMoney() { return this->money; };
	void setMoney(long int money) { this->money = money; };

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
	Cars cars_clinet_side;

public:
	Client() {};
	/* Constructors */
	Client(string name, string surname, string password, Cars cars) : Man(name, surname, password) {
		this->cars_clinet_side = cars;
	};
	/* End Constructors */
		
	/* Getters and Setters */
	string getPasportId() { return this->pasport_id; };
	void setPasportId(string pasport_id) { this->pasport_id = pasport_id; };

	CarsStruct getChoiceClientCar() { return this->choice_client_car; };
	void setChoiceClientCar(CarsStruct choice_client_car) { this->choice_client_car = choice_client_car; };
	/* End Getters and Setters */
	
	/* Methods */
	CarsStruct getCarByNumber(int number) {
		CarsStruct* c = cars_clinet_side.getCars();
		for (int i = 0; i < cars_clinet_side.getSizeStruct(); i++) {
			if (c[i].id_car == number) {
				return c[i];
			};
		};
	};
	void showCars() {
		CarsStruct* c = cars_clinet_side.getCars();
		for (int i = 0; i < cars_clinet_side.getSizeStruct(); i++) {
			c[i].printCar();
		};
	};
	/* End Methods */
};
	
class Administrator : public Man {
private:
	Applications applications;
public:
	/* Constructors */
	Administrator() {};
	Administrator(string name, string surname, string password, Applications appl) : Man(name, surname, password) {
		this->applications = appl;
	};
	/* End Constructors */
	
	void showApplications() {
		for (int i = 0; i < this->applications.getApplications().size(); i++)
		{
			this->applications.getApplications()[i].print_application();
		}
	};

};
