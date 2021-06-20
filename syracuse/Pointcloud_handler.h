#pragma once
#include "data_maneger.h"
class Pointcloud_handler
{
public:
	data_maneger* dataList;
	Pointcloud_handler(data_maneger* data) :dataList(data) {
		vector<vector<Lidar_sample*>*>* sortData = nullptr;
	}
	
	
	vector<vector<Lidar_sample*>*>* sortData =nullptr;
	void slicing(int axis, int N);
	void slicing( char axis);
	void clustering();
	void clustering(int N);
	void inspection( char viewPoint);
	void inspection(char viewPoint, int N);
	void print_vector(int num);
};

