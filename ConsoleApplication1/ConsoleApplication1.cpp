// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <clocale>

#include "LinkedList.cpp"
#include "BusTracker.h"
using namespace std;

void print_list(LinkedList<bus_info>& lst) {       //функция вывода
	for (int i = 0; i < lst.length(); i++) {
		bus_info b = lst.get(i);
		cout << "  [" << i << "] " << b.bus_id << " " << b.driver_name << " " << b.route_id << '\n';
	}
}


int main() {                                       //LinkedList и вызов функций
	setlocale(LC_CTYPE, "rus");
	LinkedList<int> lst;
	lst.add(123);
	lst.add(100);
	for (int i = 0; i < lst.length(); i++) {
		cout << lst.get(i) << " ";
	}
	cout << '\n';
	cout << "фнкция lst.length(): " << lst.length() << '\n';
	lst.remove(0);
	cout << "функция lst.remove(0) вызвана\n";
	cout << "функция lst.length(): " << lst.length() << '\n';
	cout << "функция lst.get(0): " << lst.get(0) << '\n';

	return 0;
}

int main1() {                                         //информация по автобусам
	setlocale(LC_CTYPE, "rus");
	LinkedList<bus_info> free_buses = read_buses();
	LinkedList<bus_info> busy_buses;

	cout << "Доступные операции:\n"
		<< "list_free     - вывести свободные автобусы\n"
		<< "list_busy     - вывести автобусы в маршруте\n"
		<< "add_free <id> - добавить автобус из занятых в свободные\n"
		<< "add_busy <id> - добавить автобус из свободных в занятые\n"
		<< "exit          - выход\n";

	cout << "Автобусы в парке:\n";
	print_list(free_buses);
	while (true) {
		string command;
		int idx;

		cout << " > ";
		cin >> command;
		if (command == "list_free") {
			cout << "Автобусы в парке:\n";
			print_list(free_buses);
		}
		else if (command == "list_busy") {
			cout << "Автобусы в маршруте:\n";
			print_list(busy_buses);
		}
		else if (command == "add_free") {
			cin >> idx;
			if (idx >= busy_buses.length() || idx < 0) {
				cout << "Автобуса под номером " << idx << " нет в списке\n";
				continue;
			}
			bus_info b = busy_buses.get(idx);
			busy_buses.remove(idx);
			free_buses.add(b);
			cout << "  " << b.bus_id << " " << b.driver_name << " " << b.route_id << " вернулся в парк \n";
		}
		else if (command == "add_busy") {
			cin >> idx;
			if (idx >= free_buses.length() || idx < 0) {
				cout << "Автобуса под номером " << idx << " нет в списке\n";
				continue;
			}
			bus_info b = free_buses.get(idx);
			free_buses.remove(idx);
			busy_buses.add(b);
			cout << "  " << b.bus_id << " " << b.driver_name << " " << b.route_id << " вышел в рейс \n";
		}
		else if (command == "exit") {
			exit(0);
		}
		else {
			cout << "Команда не найдена.\n";
		}
	}
	return 0;
}