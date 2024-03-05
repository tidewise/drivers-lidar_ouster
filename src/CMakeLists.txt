rock_library(lidar_ouster
    SOURCES Dummy.cpp
    HEADERS Dummy.hpp)

rock_executable(lidar_ouster_bin Main.cpp
    DEPS lidar_ouster)

