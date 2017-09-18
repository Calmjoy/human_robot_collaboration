#include "phasespace_publisher.h"


using namespace std;

TEST(PhasespaceTest, testPassPoints)
{
    PhasespacePublisher ps("ps_markers");

    ros::NodeHandle nh("phasespace_test");
    ros::Publisher pub = nh.advertise<human_robot_collaboration_msgs::PhasespacePtArray>
                                    ("/ps_markers/phasespace_points", SUBSCRIBER_BUFFER);

    human_robot_collaboration_msgs::PhasespacePtArray msg;
    human_robot_collaboration_msgs::PhasespacePt point_;
    human_robot_collaboration_msgs::PhasespacePt point_2;
    human_robot_collaboration_msgs::PhasespacePt point_3;


    point_.id = 0;
    point_.pt.x = 1;
    point_.pt.y = 2;
    point_.pt.z = 3;

    point_2.id = 1;
    point_2.pt.x = 0.5;
    point_2.pt.y = 1.5;
    point_2.pt.z = 2.5;

    point_3.id = 2;
    point_3.pt.x = -0.5;
    point_3.pt.y = -1.5;
    point_3.pt.z = -2.5;


    msg.points.push_back(point_);
    msg.points.push_back(point_2);
    msg.points.push_back(point_3);

    phasespace_sub = nh.subscribe("/visualization_marker_array",
                                  SUBSCRIBER_BUFFER);

    while(ros::ok())
    {
        pub.publish(msg);

        ros::spinOnce();
        loop_rate.sleep();
    }

    std::vector<RVIZMarker> markers = ps.getMarkers();

    EXPECT_EQ(markers._points[0].x, 1.0);
    EXPECT_EQ(markers._points[0].y, 2.0);
    EXPECT_EQ(markers._points[0].z, 3.0);

    EXPECT_EQ(markers._points[1].x, 0.5);
    EXPECT_EQ(markers._points[1].y, 1.5);
    EXPECT_EQ(markers._points[1].z, 2.5);

    EXPECT_EQ(markers._points[1].x, -0.5);
    EXPECT_EQ(markers._points[1].y, -1.5);
    EXPECT_EQ(markers._points[1].z, -2.5);

}


int main(int argc, char **argv)
{
    ros::init(argc, argv, "phasespace_test");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
