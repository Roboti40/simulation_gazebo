# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "${prefix}/include".split(';') if "${prefix}/include" != "" else []
PROJECT_CATKIN_DEPENDS = "geometry_msgs;hector_elevation_msgs;hector_map_tools;nodelet;pcl_ros;roscpp;sensor_msgs;tf".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-lElevationMapping".split(';') if "-lElevationMapping" != "" else []
PROJECT_NAME = "hector_elevation_mapping"
PROJECT_SPACE_DIR = "/home/laborobotique/catkin_ws/install"
PROJECT_VERSION = "0.0.0"
