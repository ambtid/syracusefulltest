#pragma once

#include <list>

#include <string>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <filesystem>
#include "Lidar_sample.h"

class Frame
{
public:
	std::vector<Lidar_sample*>* sampls;
	void read_file(int fileNum);
	~Frame();
};