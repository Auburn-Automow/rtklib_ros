
#include "ros/ros.h"

#include "rtklib.h"


int main(int argc, char ** argv)
{
	ros::init(argc, argv, "rtk_node");

	traceopen("trace");
	tracelevel(5);

	rtksvr_t svr;
	rtksvrinit( &svr );

	while(ros::ok())
	{
		ros::spinOnce();
	}
}

