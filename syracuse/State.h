#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <filesystem>
class State
{
public:
	double R=0;
	double H=0;
	double slew=0;

	State(double R, double H, double slew) :R(R), H(H), slew(slew) {}
	State() {};
	void read_state_file(int fileNum);
	
};

