#pragma once
#include <string>
#include "LinkedList.cpp"
#include <iostream>
#include <fstream>
#include <iomanip>

#define BUS_DATA "bus_data.txt"

struct bus_info {
	int bus_id;
	std::string driver_name;
	int route_id;
	bus_info(int b, std::string drv, int r) : bus_id(b), driver_name(drv), route_id(r) {

	}
};

LinkedList<bus_info>& read_buses();