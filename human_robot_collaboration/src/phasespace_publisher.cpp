#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>
#include <geometry_msgs/Point.h>

#include "robot_utils/rviz_publisher.h"
#include "human_robot_collaboration_msgs/PhasespacePt.h"
#include "human_robot_collaboration_msgs/PhasespacePtArray.h"


using namespace std;

class PhasespacePublisher
{
private:
    ros::NodeHandle nh;
    RVIZPublisher   rviz_pub;
    ros::Subscriber phasespace_sub;

public:
    PhasespacePublisher(std::string name);
    void passMarkers(const human_robot_collaboration_msgs::PhasespacePtArray&);

};

PhasespacePublisher::PhasespacePublisher (std::string name) :
                                          nh(name), rviz_pub(name)
{
    phasespace_sub = nh.subscribe("phasespace_points",
                                  SUBSCRIBER_BUFFER,
                                  &PhasespacePublisher::passMarkers, this);
    rviz_pub.start();

    ROS_INFO("PhasespacePublisher created!");
}

void PhasespacePublisher::passMarkers(const human_robot_collaboration_msgs::PhasespacePtArray& markers)
{
    vector <RVIZMarker> rviz_markers;

    ROS_INFO("POINT %d: %.2f, %.2f, %.2f", markers.points[0].id,
                                       markers.points[0].pt.x,
                                       markers.points[0].pt.y,
                                       markers.points[0].pt.z);

    std::vector<geometry_msgs::Point> _points;

    for(size_t i = 0; i < markers.points.size(); ++i)
    {
        _points.push_back(markers.points[i].pt);
    }


    rviz_markers.push_back(RVIZMarker(_points));

    rviz_pub.setMarkers(rviz_markers);

}



int main(int argc, char ** argv)
{
    ROS_INFO("Reading points:");
    ros::init(argc, argv, "ps_markers");
    PhasespacePublisher ps("ps_markers");


    ros::spin();
    return 0;
}
