#pragma once
#include "Lidar_sample.h"
#include <float.h>
class compers
{
};


double distance_from_max(Lidar_sample* l);
bool comper_lidar_clustering(Lidar_sample* i, Lidar_sample* j);



bool comper_lidar_byX(Lidar_sample* i, Lidar_sample* j);

bool comper_lidar_byY(Lidar_sample* i, Lidar_sample* j);

bool comper_lidar_byZ(Lidar_sample* i, Lidar_sample* j);


