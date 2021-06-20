#include "data_combin.h"

#include "compers.h"













data_combin::data_combin(int fileNum)
{
	frame = new Frame();
	state = new State();
	frame->read_file(fileNum);
	state->read_state_file(fileNum);

}

void data_combin::clustering(vector<Lidar_sample*>* pointC)
{
	for (int i=0; i< frame->sampls->size();i++)
	{
		
			pointC->push_back( frame->sampls->at(i));

	}
	sort(pointC->begin(), pointC->end(), comper_lidar_clustering);


}

void data_combin::inspection(char viewPoint, vector<Lidar_sample*>* sortVector)
{
	for (int i = 0; i < frame->sampls->size(); i++)
	{
		sortVector -> push_back(frame->sampls->at(i));

	}



	switch (viewPoint)
	{
	case 'X':
		sort(sortVector->begin(), sortVector->end(), comper_lidar_byX);
		break;
	case 'Y':
		sort(sortVector->begin(), sortVector->end(), comper_lidar_byY);
		break;
	case 'Z':
		sort(sortVector->begin(), sortVector->end(), comper_lidar_byZ);
		break;
	}
}

void data_combin::slicing(char axis, vector<Lidar_sample*>* above, vector<Lidar_sample*>* below)
{
	int above_conter = 0;
	int below_conter = 0;
	for (int i = 0; i < frame->sampls->size() ; i++)
	{

		switch (axis)
		{
		case 'X':
			if (frame->sampls->at(i)->X > 0)
				above->push_back(frame->sampls->at(i));
			else
				below->push_back(frame->sampls->at(i));
			break;
		case 'Y':
			if (frame->sampls->at(i)->Y > 0)
				above->push_back(frame->sampls->at(i));
			else
				below->push_back(frame->sampls->at(i));
			break;
		case 'Z':
			if (frame->sampls->at(i)->Z > 0)
				above->push_back(frame->sampls->at(i));
			else
				below->push_back( frame->sampls->at(i));
			break;
		default:
			break;
		}
	}
}