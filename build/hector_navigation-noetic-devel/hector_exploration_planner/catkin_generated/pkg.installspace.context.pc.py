# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "${prefix}/include".split(';') if "${prefix}/include" != "" else []
PROJECT_CATKIN_DEPENDS = "costmap_2d;dynamic_reconfigure;geometry_msgs;hector_nav_msgs;nav_core;nav_msgs;pluginlib;rosconsole;roscpp;rospy".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-lhector_exploration_base_global_planner_plugin;-lhector_exploration_planner".split(';') if "-lhector_exploration_base_global_planner_plugin;-lhector_exploration_planner" != "" else []
PROJECT_NAME = "hector_exploration_planner"
PROJECT_SPACE_DIR = "/home/laborobotique/catkin_ws/install"
PROJECT_VERSION = "0.0.0"
