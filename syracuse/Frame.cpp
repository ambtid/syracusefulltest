#include "Frame.h"
namespace fs = std::filesystem;
void Frame::read_file(int fileNum)
{
	sampls = new std::vector < Lidar_sample* >();
	fs::path p{ "./Dev_Data/PC/frame" + std::to_string(fileNum)+".csv" };

	// read file line by line
	


	std::string base_filename = p.string();
	std::ifstream ifs;;
	ifs.open(base_filename);
	std::string line;
	while (std::getline(ifs, line)) {
		std::string                cellX;
		std::string                cellY;
		std::string                cellZ;
		std::stringstream          lineStream(line);
		std::getline(lineStream, cellX, ',');
		std::getline(lineStream, cellY, ',');
		std::getline(lineStream, cellZ, ',');
		Lidar_sample* l=new Lidar_sample(std::stod(cellX), std::stod(cellY), std::stod(cellZ));

		sampls->push_back(l);

	}
	ifs.close();
}

Frame::~Frame()
{
	for (size_t i = 0; i < sampls->size(); i++)
	{
		delete sampls->at(i);
	}
}



