/*

Система Прокат автомобілів. Клієнт вибирає Автомобіль зі списку доступних, заповнює форму Замовлення,
вказуючи паспортні дані, строк оренди. Адміністратор може відхилити Заявку, указавши причини відмови. При
підтвердженні Заявки Клієнт оплачує Замовлення. Система виписує суму. У випадку ушкодження Автомобіля
Клієнтом Адміністратор вносить відповідні позначки.

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

	int number_menu = 0, number_admin = 0, number_car, number_application;
	string name, surname, password, pasp_id, choice, lease_term, choice_status;

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
		cout << MY_BALANCE << ". My balance" << endl;
		cout << CHOICE_CAR << ". Choice car" << endl;
		cout << SHOW_CHOICES_CAR << ". My car" << endl;
		cout << SHOW_APPLICATION_CLIENT << ". Show applications" << endl;
		cout << CREATE_APLICATION << ". Create applications" << endl;
		if (client.is_admin())
		{
			cout << ADMIN_PANEL << ". Admin panel" << endl;
		}
		cout << RE_ENTER_PASSWORD << ". Re-enter password" << endl;
		cout << EXIT << ". Exit" << endl << endl;

		cout << "Enter choice: ";
		cin >> number_menu;

		if (number_menu == SHOW_CARS)
		{
			client.showCars();
		}
		else if (number_menu == MY_BALANCE)
		{
			cout << "Your Balance: " << client.getMoney() << " UAH" << endl;
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
						"Processing"
					}
				);

				cout << "Thanks you! We recive your applications and will consider in the near future." << endl << endl;
				cout << "Your check" << endl << endl;
				app.getApplications()[app.getApplications().size() - 1].print_application();
				cout 
					<< "UAH " << client.getChoiceClientCar().price 
					<< " will be deducted from your balance."
					<< endl << endl;
				client.setApplicat(app);
			}
		}
		else if (number_menu == SHOW_APPLICATION_CLIENT)
		{
			client.showApplications();
		}
		else if (number_menu == ADMIN_PANEL) {
			if (client.is_admin()) 
			{
				Administrator admin(name, surname, password);
				while (number_admin != EXIT_ADMIN)
				{
					cout << "Please, choose the option:" << endl;
					cout << SHOW_APPLICATION_ADMIN << ". Show applications" << endl;
					cout << CHANGE_STATUS_APPLICATION << ". Change status applications" << endl;
					cout << EXIT_ADMIN << ". Exit admin panel" << endl << endl;

					cout << "Enter choice: ";
					cin >> number_admin;
					
					if (number_admin == EXIT_ADMIN)
					{
						number_menu = 0;
					}
					else if (number_admin == SHOW_APPLICATION_ADMIN)
					{
						admin.showApplications(&app);
					}
					else if (number_admin == CHANGE_STATUS_APPLICATION)
					{
						cout << "Enter number application: ";
						cin >> number_application;
						cout << "Enter status (Aprove, Reject): ";
						cin >> choice_status;
						admin.changeStatus(number_application, choice_status, &client, &app);
					}
				}
			}
			else
			{
				cout << "You shouldn't have seen it" << endl;
			}
		}
		else if (number_menu == RE_ENTER_PASSWORD)
		{
			cout << "Enter new Password: ";
			cin >> password;
			client.setPassword(password);
		}
	}
}
