#include "compers.h"


double distance_from_max(Lidar_sample* l) {
	return ((DBL_MAX - l->X) * (DBL_MAX - l->X) + (DBL_MAX - l->Y) * (DBL_MAX - l->Y) + (DBL_MAX - l->Z) * (DBL_MAX - l->Z));
}
bool comper_lidar_clustering(Lidar_sample* i, Lidar_sample* j) { return distance_from_max(i) < distance_from_max(j); }



bool comper_lidar_byX(Lidar_sample* i, Lidar_sample* j) { return i->X < j->X; }

bool comper_lidar_byY(Lidar_sample* i, Lidar_sample* j) { return i->X < j->Y; }

bool comper_lidar_byZ(Lidar_sample* i, Lidar_sample* j) { return i->X < j->Z; }


