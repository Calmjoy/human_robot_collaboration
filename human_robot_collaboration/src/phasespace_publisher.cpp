#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>
#include <geometry_msgs/Point.h>

#include "robot_utils/rviz_publisher.h"


using namespace std;


void makeMarkers(const geometry_msgs::Point& coord)
{
    print("RECEIVED MARKER LET'S GooOO")
    RVIZPublisher rviz_pub;
    vector <RVIZMarker> rviz_markers;

    for(size_t i = 0; i < coord.size(); ++i)
    {
        rviz_markers.push_back(RVIZMarker(coord,
                                          Color.RGBA(1.0, 0.0, 1.0)));
    }

    rviz_pub.setMarkers(rviz_markers);

}


int main(int argc, char ** argv)
{
    ros::init(argc, argv, "ps_markers");
    ros::NodeHandle nh("ps_markers");


    ros::Subscriber phasespace_sub = nh.subscribe("phasespace_points",
                                                SUBSCRIBER_BUFFER,
                                                makeMarkers);

    ros::spin();
    return 0;

}
