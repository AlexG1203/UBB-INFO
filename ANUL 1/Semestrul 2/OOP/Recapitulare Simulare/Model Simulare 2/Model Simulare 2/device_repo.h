#pragma once

#include "device.h"

#include <vector>

class DeviceRepo
{
private:
	std::string filename;
	std::vector<Device> items;
public:
	DeviceRepo(std::string _filename);
	const std::vector<Device>& get_items() const;
};
