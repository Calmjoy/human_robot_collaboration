#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <visualization_msgs/MarkerArray.h>
#include <geometry_msgs/Point.h>

#include "robot_utils/rviz_publisher.h"
#include "human_robot_collaboration_msgs/PhasespacePt.h"
#include "human_robot_collaboration_msgs/PhasespacePtArray.h"

class PhasespacePublisher
{
private:
    ros::NodeHandle nh;
    RVIZPublisher   rviz_pub;
    ros::Subscriber phasespace_sub;

public:
    PhasespacePublisher(std::string name);

    void passMarkers(const human_robot_collaboration_msgs::PhasespacePtArray&);

    std::vector<RVIZMarker> getMarkers() { return rviz_pub.getMarkers(); };

};
