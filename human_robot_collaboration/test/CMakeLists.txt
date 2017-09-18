

find_package(rostest            REQUIRED)
find_package(baxter_description REQUIRED)

## Phasespace tests

add_rostest_gtest(phasespace_test phasespace_test.test
                                  phasespace_test.cpp)
## target_link_libraries(phasespace_test robot_interface)
