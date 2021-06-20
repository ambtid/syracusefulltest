#include "State.h"
namespace fs = std::filesystem;

void State::read_state_file(int fileNum)
{

	fs::path p{ "./Dev_Data/State/state" + std::to_string(fileNum)+".csv" };

	auto line = std::string();
	// read file line by line
	auto x = 0, y = 0, z = 0;



	std::string base_filename = p.string();
	
	std::ifstream ifs;
	//auto file = std::ifstream{ base_filename };
	ifs.open(base_filename);
	std::getline(ifs, line);
	std::string                cellR;
	std::string                cellSlew;
	std::string                cellH;
	std::stringstream          lineStream(line);
	std::getline(lineStream, cellR, ',');
	std::getline(lineStream, cellSlew, ',');
	std::getline(lineStream, cellH, ',');
	R = std::stod(cellR);
	slew = std::stod(cellSlew);
	H = std::stod(cellH);



}