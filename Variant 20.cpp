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
		CarsStruct{5, 350, "Reno", "Logan", 2001, 180, true}
	};
	Cars* car = new Cars(s, size(s));

	int number_menu = 0, number_car;
	string name, surname, password, pasp_id, choice, lease_term;

	cout << "Hello and welcome to the CarRental services." << endl;
	cout << "Pleas enter your name, surname and password." << endl << endl;

	cout << "Name: ";
	cin >> name;
	cout << "Surname: ";
	cin >> surname;
	cout << "Password: ";
	cin >> password;

	Client client(name, surname, password);

	cout << endl << "You sucssesful login. Welcome, " << client.getFullName() << endl << endl;

	if (!client.is_admin())
	{	
		while (number_menu != EXIT)
		{
			cout << "Please, choose the option:" << endl;
			cout << SHOW_CARS << ". Show car" << endl;
			cout << CHOICE_CAR << ". Choice car" << endl;
			cout << SHOW_CHOICES_CAR << ". My car" << endl;
			cout << CREATE_APLICATION << ". Create aplications" << endl;
			cout << EXIT << ". Exit" << endl << endl;

			cout << "Enter choice: ";
			cin >> number_menu;

			if (number_menu == SHOW_CARS)
			{
				client.showCars(car);
			}
			else if (number_menu == CHOICE_CAR)
			{
				cout << "Enter number car: ";
				cin >> number_car;
				CarsStruct car_client = client.getCarByNumber(car, number_car);
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
					Sleep(1000);
					
					Applications app(client.getFullName(), pasp_id, lease_term);
					app.createAplication(
						ApplicationStruct{
							1,
							client.getChoiceClientCar(),
							client.getFullName(),
							client.getPasportId(),
							app.getLeaseTerm()
						}
					);

					cout << "Thanks you! We recive your applications and will consider in the near future." << endl << endl;
					cout << "Your check" << endl << endl;
					app.getApplications()->print_application();
				}
			}
			else {
				cout << "Sorry i dont understand this command" << endl;
			}
		}
	}
}
