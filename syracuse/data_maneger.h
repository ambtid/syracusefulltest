#pragma once
#include "Frame.h"
#include "State.h"
#include <filesystem>
#include "data_combin.h"
class data_maneger
{
public:
	std::vector<data_combin*> dataList;

	data_maneger();
	~data_maneger();
	
};
