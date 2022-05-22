#include "pch.h"
#include "BusTracker.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "LinkedList.cpp"


// Распарсить csv строку в структуру bus_info
bus_info parse_bus(std::string bus_def) {
	int idx = bus_def.find(",");
	int bus_id = std::stoi(bus_def.substr(0, idx));
	bus_def = bus_def.substr(idx+1);
	idx = bus_def.find(",");
	std::string driver_name = bus_def.substr(0, idx);
	int	route_id = std::stoi(bus_def.substr(idx+1));

	return bus_info(bus_id, driver_name, 1);
}

// открыть csv файл и обойти все строки. 
LinkedList<bus_info>& read_buses() {
	std::ifstream file;
	file.open(BUS_DATA);
	if (!file) {
		std::cout << "Can't open " << BUS_DATA << '\n';
		exit(1);
	}

	LinkedList<bus_info> *lst = new LinkedList<bus_info>();
	std::string line;
	
	while (std::getline(file, line)) {
		bus_info b = parse_bus(line);
		lst->add(b);

	}
	return *lst;
}
