/*

������� ������ ���������. �볺�� ������ ��������� � ������ ���������, �������� ����� ����������,
�������� �������� ���, ����� ������. ����������� ���� �������� ������, �������� ������� ������. ���
����������� ������ �볺�� ������ ����������. ������� ������ ����. � ������� ���������� ���������
�볺���� ����������� ������� ������� ��������.

*/

#include <windows.h>
#include "processing.h"

using namespace std;

int main()
{
	CarsStruct s[5] = {
		CarsStruct{1, 1000, "BMW", "X5", 2009, 300, false},
		CarsStruct{2, 3000, "Mercedes", "G5", 2009, 400, false},
		CarsStruct{3, 500, "Toyota", "SUPRA", 1994, 250, false},
		CarsStruct{4, 1300, "Audi", "R8", 2021, 350, false},
		CarsStruct{5, 350, "Reno", "Logan", 2001, 180, false}
	};
	Cars car = Cars(s, size(s));

	int number_menu = 0, number_car, number_admin = 0;
	string name, surname, password, pasp_id, choice, lease_term;

	cout << "Hello and welcome to the CarRental services." << endl;
	cout << "Pleas enter your name, surname and password." << endl << endl;

	cout << "Name: ";
	cin >> name;
	cout << "Surname: ";
	cin >> surname;
	cout << "Password: ";
	cin >> password;

	Client client(name, surname, password, car);
	Applications app(client.getFullName(), pasp_id, lease_term);

	cout << endl << "You sucssesful login. Welcome, " << client.getFullName() << endl << endl;

	while (number_menu != EXIT)
	{
		cout << endl << "Please, choose the option:" << endl;
		cout << SHOW_CARS << ". Show car" << endl;
		cout << CHOICE_CAR << ". Choice car" << endl;
		cout << SHOW_CHOICES_CAR << ". My car" << endl;
		cout << CREATE_APLICATION << ". Create aplications" << endl;
		if (client.is_admin())
		{
			cout << ADMIN_PANEL << ". Admin panel" << endl;
		}
		cout << EXIT << ". Exit" << endl << endl;

		cout << "Enter choice: ";
		cin >> number_menu;

		if (number_menu == SHOW_CARS)
		{
			client.showCars();
		}
		else if (number_menu == CHOICE_CAR)
		{
			cout << "Enter number car: ";
			cin >> number_car;
			CarsStruct car_client = client.getCarByNumber(number_car);
			cout << endl << "You choice: " << endl;
	
			car_client.printCar();
			client.setChoiceClientCar(car_client);
		}
		else if (number_menu == SHOW_CHOICES_CAR)
		{
			client.getChoiceClientCar().printCar();
		}
		else if (number_menu == CREATE_APLICATION)
		{
			cout << "Do you want confirm order? (Y/n) ";
			cin >> choice;
			if (choice == "y" || choice == "Y")
			{
				cout << "Please, enter your Pasport ID: ";
				cin >> pasp_id;
				client.setPasportId(pasp_id);
					
				cout << "Enter lease term: ";
				cin >> lease_term;
					
				cout << "We processing your application..." << endl << endl;
					
				app.setLeaseTerm(lease_term);
				app.setCars(car);
					
				Sleep(1000);
					
				app.createAplication(
					ApplicationStruct{
						app.getApplications().size() + 1,
						client.getChoiceClientCar(),
						client.getFullName(),
						client.getPasportId(),
						app.getLeaseTerm(),
					}
				);

				cout << "Thanks you! We recive your applications and will consider in the near future." << endl << endl;
				cout << "Your check" << endl << endl;
				app.getApplications()[app.getApplications().size() - 1].print_application();
				cout 
					<< "UAH " << client.getChoiceClientCar().price 
					<< " will be deducted from your balance."
					<< endl << endl;
			}
		}
		else if (number_menu == ADMIN_PANEL) {
			if (client.is_admin()) 
			{
				Administrator admin(name, surname, password, app);
				while (number_admin != EXIT_ADMIN)
				{
					cout << "Please, choose the option:" << endl;
					cout << SHOW_APPLICATION << ". Show applications" << endl;
					cout << EXIT_ADMIN << ". Exit admin panel" << endl << endl;

					cout << "Enter choice: ";
					cin >> number_admin;
					
					if (number_admin == EXIT_ADMIN)
					{
						number_menu = 0;
					}
					else if (number_admin == SHOW_APPLICATION)
					{
						admin.showApplications();
					}
				}
			}
			else
			{
				cout << "You shouldn't have seen it" << endl;
			}
		}
	}
}
