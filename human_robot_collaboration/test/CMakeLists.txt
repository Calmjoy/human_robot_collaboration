# Copyright: (C) 2017 Social Robotics Lab - Yale University
# Author: Alessandro Roncone <alessandro.roncone@yale.edu>
# CopyPolicy: Released under the terms of the LGPLv2.1.

find_package(rostest            REQUIRED)
find_package(baxter_description REQUIRED)

## Phasespace tests

catkin_add_gtest(phasespace_test phasespace_test.cpp)

# We add include directories specifically for this test since we don't want to propagate
# include directories to other targets when that is not necessary
target_include_directories(phasespace_test PUBLIC ../src/phasespace_publisher)

target_link_libraries(phasespace_test ${catkin_LIBRARIES})
