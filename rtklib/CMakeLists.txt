cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

# Set the build type.  Options are:
#  Coverage       : w/ debug symbols, w/o optimization, w/ code-coverage
#  Debug          : w/ debug symbols, w/o optimization
#  Release        : w/o debug symbols, w/ optimization
#  RelWithDebInfo : w/ debug symbols, w/ optimization
#  MinSizeRel     : w/o debug symbols, w/ optimization, stripped binaries
#set(ROS_BUILD_TYPE RelWithDebInfo)

rosbuild_init()

set (CMAKE_C_FLAGS      "-DNFREQ=3 -Wall -Wno-missing-field-initializers -DLAPACK -O3 -ansi -pedantic")


set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
include_directories(${PROJECT_SOURCE_DIR}/src/)
set(RTKLIB_SRCS ${PROJECT_SOURCE_DIR}/src/rtkcmn.c)
list(APPEND RTKLIB_SRCS ${PROJECT_SOURCE_DIR}/src/rtksvr.c
                        ${PROJECT_SOURCE_DIR}/src/rtkpos.c
                        ${PROJECT_SOURCE_DIR}/src/geoid.c
                        ${PROJECT_SOURCE_DIR}/src/solution.c
                        ${PROJECT_SOURCE_DIR}/src/lambda.c
                        ${PROJECT_SOURCE_DIR}/src/sbas.c
                        ${PROJECT_SOURCE_DIR}/src/stream.c
                        ${PROJECT_SOURCE_DIR}/src/rcvraw.c
                        ${PROJECT_SOURCE_DIR}/src/rtcm.c
                        ${PROJECT_SOURCE_DIR}/src/preceph.c
                        ${PROJECT_SOURCE_DIR}/src/options.c
                        ${PROJECT_SOURCE_DIR}/src/pntpos.c
                        ${PROJECT_SOURCE_DIR}/src/ppp.c
                        ${PROJECT_SOURCE_DIR}/src/rcv/novatel.c
                        ${PROJECT_SOURCE_DIR}/src/rcv/ublox.c
                        ${PROJECT_SOURCE_DIR}/src/rcv/ss2.c
                        ${PROJECT_SOURCE_DIR}/src/rcv/crescent.c
                        ${PROJECT_SOURCE_DIR}/src/rcv/skytraq.c
                        ${PROJECT_SOURCE_DIR}/src/rcv/gw10.c
                        ${PROJECT_SOURCE_DIR}/src/rcv/javad.c
                        ${PROJECT_SOURCE_DIR}/src/ephemeris.c
                        ${PROJECT_SOURCE_DIR}/src/rinex.c
                        ${PROJECT_SOURCE_DIR}/src/ionex.c)

rosbuild_add_library(${PROJECT_NAME} ${RTKLIB_SRCS})
target_link_libraries(${PROJECT_NAME} pthread lapack blas)

#rosbuild_add_boost_directories()
#rosbuild_link_boost(${PROJECT_NAME} thread)
#rosbuild_add_executable(example examples/example.cpp)
#target_link_libraries(example ${PROJECT_NAME})
