rock_library(lidar_ouster
    SOURCES
    HEADERS
    DEPS_PKGCONFIG base-types lidar_ouster_sdk)

rock_executable(lidar_ouster_bin Main.cpp
    DEPS_PKGCONFIG lidar_ouster_sdk)

