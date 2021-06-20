#include "Pointcloud_handler.h"

#include "compers.h"


namespace fs = std::filesystem;

void Pointcloud_handler::slicing(int axis, int N)
{
	if (sortData == nullptr)
		sortData = new vector<vector<Lidar_sample*>*>();
	int courrentSort =0;
	for (size_t i = 0; i < dataList->dataList.size(); i = i + N)
	{
		if (sortData->size() <= i)
			sortData->push_back( new vector<Lidar_sample*>());
		vector<Lidar_sample*> above;
		vector<Lidar_sample*> below;

		for (size_t j = 0; j <= N && i + j < dataList->dataList.size(); j++)
		{
			dataList->dataList.at(j + i)->slicing(axis, &above, &below);
		}

		size_t j = 0;
		for (j = 0; j < above.size(); j++)
		{
			sortData->at(courrentSort)->push_back( above.at(j));
			
		}
		for (size_t k = 0; k < below.size(); k++)
		{
			sortData->at(courrentSort)->push_back( below.at(k));
		}
		courrentSort++;
	}
}

void Pointcloud_handler::slicing( char axis)
{
	if (sortData == nullptr)
		sortData = new vector<vector<Lidar_sample*>*>(dataList->dataList.size());
	for (size_t i = 0; i < dataList->dataList.size(); i++)
	{

		if (sortData->at(i) == NULL)
			sortData->at(i) = new vector<Lidar_sample*>(dataList->dataList.at(i)->frame->sampls->size());
		vector<Lidar_sample*> above;
		vector<Lidar_sample*> below;
		dataList->dataList.at(i)->slicing(axis, &above, &below);
		size_t j = 0;
		for (j = 0; j < above.size(); j++)
		{
			sortData->at(i)->at(j) = above.at(j);
		}
		for (size_t k = 0; k < below.size(); k++)
		{
			sortData->at(i)->at(j++) = below.at(k);
		}
		
	}

}

void Pointcloud_handler::clustering()
{
	if (sortData == nullptr)
		sortData = new vector<vector<Lidar_sample*>*>(dataList->dataList.size());
	for (size_t i = 0; i < dataList->dataList.size(); i++)
	{
		if (sortData->at(i) == NULL)
			sortData->push_back(new vector<Lidar_sample*>());

		dataList->dataList.at(i)->clustering(sortData->at(i));

	}
}

void Pointcloud_handler::clustering(int N)
{

	if (sortData == nullptr)
		sortData = new vector<vector<Lidar_sample*>*>();
	int courrentSort = 0;
	for (size_t i = 0; i < dataList->dataList.size(); i = i + N)
	{
		if (sortData->size() < i)
			sortData->push_back(new vector<Lidar_sample*>());
		
		for (size_t j = 0; j <= N && i + j < dataList->dataList.size(); j++)
		{
			dataList->dataList.at(j + i)->clustering(sortData->at(courrentSort));
			
		}

		courrentSort++;
	}
}






void Pointcloud_handler::inspection(char viewPoint)
{
	if (sortData == nullptr)
		sortData = new vector<vector<Lidar_sample*>*>(dataList->dataList.size());
	for (size_t i = 0; i < dataList->dataList.size(); i++)
	{
		if (sortData->at(i) == NULL)
			sortData->at(i) = new vector<Lidar_sample*>(dataList->dataList.at(i)->frame->sampls->size());

		dataList->dataList.at(i)->inspection(viewPoint, (sortData->at(i)));
	}
}


void Pointcloud_handler::inspection(char viewPoint, int N)
{
	if (sortData == nullptr)
		sortData = new vector<vector<Lidar_sample*>*>();
	int courrentSort = 0;
	for (size_t i = 0; i < dataList->dataList.size(); i = i + N)
	{
		if (sortData->size() < i)
			sortData->push_back(new vector<Lidar_sample*>());

		for (size_t j = 0; j <= N && i + j < dataList->dataList.size(); j++)
		{
			dataList->dataList.at(j + i)->inspection(viewPoint,sortData->at(courrentSort));

		}
		switch (viewPoint)
		{
		case 'X':
			sort(sortData->at(courrentSort)->begin(), sortData->at(courrentSort)->end(), comper_lidar_byX);
			break;
		case 'Y':
			sort(sortData->at(courrentSort)->begin(), sortData->at(courrentSort)->end(), comper_lidar_byY);
			break;
		case 'Z':
			sort(sortData->at(courrentSort)->begin(), sortData->at(courrentSort)->end(), comper_lidar_byZ);
			break;
		}

		courrentSort++;
	}


}

void Pointcloud_handler::print_vector(int num)
{
	for (size_t i = 0; i < sortData->size() && sortData->at(i)!=NULL; i++)
	{
		cout << sortData->at(num)->at(i)->X << "  " << sortData->at(num)->at(i)->Y << "  " << sortData->at(num)->at(i)->Z << endl;
	}
}



