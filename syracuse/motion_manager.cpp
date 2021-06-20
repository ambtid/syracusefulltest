#include "motion_manager.h"

void motion_manager::run_Motion_detection()
{
	stateMoves = new vector<State*>{ data->dataList.size() };
	for (size_t i = 0; i < data->dataList.size() - 1; i++)
	{
		double R = abs(data->dataList[i]->state->R - data->dataList[i + 1]->state->R) * 5;
		double H = abs(data->dataList[i]->state->H - data->dataList[i + 1]->state->H) * 5;
		double slew = abs(data->dataList[i]->state->slew - data->dataList[i + 1]->state->slew) * 5;
		stateMoves->at(i)= new State(R, H, slew);

	}



}
void motion_manager::system_log()
{
	cout << "to print all the state press 1" << "to change state press 2" << endl;
	int x;
	cin >> x;
	switch (x)
	{
	case 1:
		for (size_t i = 0; i < data->dataList.size(); i++)
		{
			cout << data->dataList.at(i)->state->R << data->dataList.at(i)->state->slew << data->dataList.at(i)->state->H << endl;
		}
	case 2:
		cout << "enter state number to cahnge" << endl;
		cin >> x;
		double R;
		double slew;
		double H;
			cout << "enter R" << endl;
			cin >> data->dataList.at(x)->state->R;
		cout << "enter slew" << endl;
		cin >> data->dataList.at(x)->state->slew;
		cout << "enter H" << endl;
		cin >> data->dataList.at(x)->state->H;


	default:
		break;
	}

}
motion_manager::~motion_manager() {
	for (size_t i = 0; i < stateMoves->size(); i++)
		delete stateMoves->at(i);

}
void motion_manager::motion_velocity(double bounder, bool alarm , bool delete_file )
{
	for (size_t i = 0; i < stateMoves->size() && stateMoves->at(i)!=NULL; i++)
	{

		if (stateMoves->at(i)->R > bounder || stateMoves->at(i)->H > bounder || stateMoves->at(i)->slew > bounder)
		{
			std::cout << "moving at frame: " << i << "at speed " << stateMoves->at(i)->R << " " << stateMoves->at(i)->H << " " << stateMoves->at(i)->slew << std::endl;
			if (alarm) {

				cout << "warning the speeed of state:"  <<i <<" is out of range delete "<<endl;
				if (delete_file)
					delete data->dataList.at(i);
			}
		}
	}

}