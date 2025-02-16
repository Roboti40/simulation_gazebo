# generated from catkin/cmake/template/pkgConfig.cmake.in

# append elements to a list and remove existing duplicates from the list
# copied from catkin/cmake/list_append_deduplicate.cmake to keep pkgConfig
# self contained
macro(_list_append_deduplicate listname)
  if(NOT "${ARGN}" STREQUAL "")
    if(${listname})
      list(REMOVE_ITEM ${listname} ${ARGN})
    endif()
    list(APPEND ${listname} ${ARGN})
  endif()
endmacro()

# append elements to a list if they are not already in the list
# copied from catkin/cmake/list_append_unique.cmake to keep pkgConfig
# self contained
macro(_list_append_unique listname)
  foreach(_item ${ARGN})
    list(FIND ${listname} ${_item} _index)
    if(_index EQUAL -1)
      list(APPEND ${listname} ${_item})
    endif()
  endforeach()
endmacro()

# pack a list of libraries with optional build configuration keywords
# copied from catkin/cmake/catkin_libraries.cmake to keep pkgConfig
# self contained
macro(_pack_libraries_with_build_configuration VAR)
  set(${VAR} "")
  set(_argn ${ARGN})
  list(LENGTH _argn _count)
  set(_index 0)
  while(${_index} LESS ${_count})
    list(GET _argn ${_index} lib)
    if("${lib}" MATCHES "^(debug|optimized|general)$")
      math(EXPR _index "${_index} + 1")
      if(${_index} EQUAL ${_count})
        message(FATAL_ERROR "_pack_libraries_with_build_configuration() the list of libraries '${ARGN}' ends with '${lib}' which is a build configuration keyword and must be followed by a library")
      endif()
      list(GET _argn ${_index} library)
      list(APPEND ${VAR} "${lib}${CATKIN_BUILD_CONFIGURATION_KEYWORD_SEPARATOR}${library}")
    else()
      list(APPEND ${VAR} "${lib}")
    endif()
    math(EXPR _index "${_index} + 1")
  endwhile()
endmacro()

# unpack a list of libraries with optional build configuration keyword prefixes
# copied from catkin/cmake/catkin_libraries.cmake to keep pkgConfig
# self contained
macro(_unpack_libraries_with_build_configuration VAR)
  set(${VAR} "")
  foreach(lib ${ARGN})
    string(REGEX REPLACE "^(debug|optimized|general)${CATKIN_BUILD_CONFIGURATION_KEYWORD_SEPARATOR}(.+)$" "\\1;\\2" lib "${lib}")
    list(APPEND ${VAR} "${lib}")
  endforeach()
endmacro()


if(mrs_gazebo_common_resources_CONFIG_INCLUDED)
  return()
endif()
set(mrs_gazebo_common_resources_CONFIG_INCLUDED TRUE)

# set variables for source/devel/install prefixes
if("FALSE" STREQUAL "TRUE")
  set(mrs_gazebo_common_resources_SOURCE_PREFIX /home/laborobotique/catkin_ws/src/mrs_gazebo_common_resources-master)
  set(mrs_gazebo_common_resources_DEVEL_PREFIX /home/laborobotique/catkin_ws/devel)
  set(mrs_gazebo_common_resources_INSTALL_PREFIX "")
  set(mrs_gazebo_common_resources_PREFIX ${mrs_gazebo_common_resources_DEVEL_PREFIX})
else()
  set(mrs_gazebo_common_resources_SOURCE_PREFIX "")
  set(mrs_gazebo_common_resources_DEVEL_PREFIX "")
  set(mrs_gazebo_common_resources_INSTALL_PREFIX /home/laborobotique/catkin_ws/install)
  set(mrs_gazebo_common_resources_PREFIX ${mrs_gazebo_common_resources_INSTALL_PREFIX})
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "WARNING: package 'mrs_gazebo_common_resources' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  message("${_msg}")
endif()

# flag project as catkin-based to distinguish if a find_package()-ed project is a catkin project
set(mrs_gazebo_common_resources_FOUND_CATKIN_PROJECT TRUE)

if(NOT "include;/usr/include;/usr/include/gazebo-11;/usr/include/bullet;/usr/include/simbody;/usr/include/sdformat-9.8;/usr/include/ignition/math6;/usr/include/OGRE;/usr/include/OGRE/Terrain;/usr/include/OGRE/Paging;/usr/include/ignition/transport8;/usr/include/ignition/msgs5;/usr/include/ignition/common3;/usr/include/ignition/fuel_tools4;/usr/include/x86_64-linux-gnu/qt5/;/usr/include/x86_64-linux-gnu/qt5/QtWidgets;/usr/include/x86_64-linux-gnu/qt5/QtGui;/usr/include/x86_64-linux-gnu/qt5/QtCore;/usr/lib/x86_64-linux-gnu/qt5//mkspecs/linux-g++;/usr/include/eigen3;/usr/include/opencv4 " STREQUAL " ")
  set(mrs_gazebo_common_resources_INCLUDE_DIRS "")
  set(_include_dirs "include;/usr/include;/usr/include/gazebo-11;/usr/include/bullet;/usr/include/simbody;/usr/include/sdformat-9.8;/usr/include/ignition/math6;/usr/include/OGRE;/usr/include/OGRE/Terrain;/usr/include/OGRE/Paging;/usr/include/ignition/transport8;/usr/include/ignition/msgs5;/usr/include/ignition/common3;/usr/include/ignition/fuel_tools4;/usr/include/x86_64-linux-gnu/qt5/;/usr/include/x86_64-linux-gnu/qt5/QtWidgets;/usr/include/x86_64-linux-gnu/qt5/QtGui;/usr/include/x86_64-linux-gnu/qt5/QtCore;/usr/lib/x86_64-linux-gnu/qt5//mkspecs/linux-g++;/usr/include/eigen3;/usr/include/opencv4")
  if(NOT " " STREQUAL " ")
    set(_report "Check the issue tracker '' and consider creating a ticket if the problem has not been reported yet.")
  elseif(NOT " " STREQUAL " ")
    set(_report "Check the website '' for information and consider reporting the problem.")
  else()
    set(_report "Report the problem to the maintainer 'Vojtech Spurny <vojtech.spurny@fel.cvut.cz>, Tomas Baca <tomas.baca@fel.cvut.cz>' and request to fix the problem.")
  endif()
  foreach(idir ${_include_dirs})
    if(IS_ABSOLUTE ${idir} AND IS_DIRECTORY ${idir})
      set(include ${idir})
    elseif("${idir} " STREQUAL "include ")
      get_filename_component(include "${mrs_gazebo_common_resources_DIR}/../../../include" ABSOLUTE)
      if(NOT IS_DIRECTORY ${include})
        message(FATAL_ERROR "Project 'mrs_gazebo_common_resources' specifies '${idir}' as an include dir, which is not found.  It does not exist in '${include}'.  ${_report}")
      endif()
    else()
      message(FATAL_ERROR "Project 'mrs_gazebo_common_resources' specifies '${idir}' as an include dir, which is not found.  It does neither exist as an absolute directory nor in '\${prefix}/${idir}'.  ${_report}")
    endif()
    _list_append_unique(mrs_gazebo_common_resources_INCLUDE_DIRS ${include})
  endforeach()
endif()

set(libraries "MrsGazeboCommonResources_GuiManager;MrsGazeboCommonResources_RvizCameraSynchronizer;MrsGazeboCommonResources_StaticTransformRepublisher;MrsGazeboCommonResources_RangefinderPlugin;MrsGazeboCommonResources_2DLidarPlugin;MrsGazeboCommonResources_3DLidarPlugin;MrsGazeboCommonResources_3DLidarGpuPlugin;MrsGazeboCommonResources_CameraPlugin;MrsGazeboCommonResources_RealsensePlugin;MrsGazeboCommonResources_ParachutePlugin;MrsGazeboCommonResources_WaterGunPlugin;MrsGazeboCommonResources_GPSPlugin;MrsGazeboCommonResources_MagnetometerPlugin;MrsGazeboCommonResources_LightPlugin;MrsGazeboCommonResources_ServoCameraPlugin;MrsGazeboCommonResources_DynamicModelPlugin;MrsGazeboCommonResources_SafetyLedPlugin;MrsGazeboCommonResources_FluidResistancePlugin;MrsGazeboCommonResources_MotorSpeedRepublisherPlugin;MrsGazeboCommonResources_MotorPropModelPlugin;MrsGazeboCommonResources_LinkStaticTFPublisher;BulletSoftBody;BulletDynamics;BulletCollision;LinearMath;/usr/lib/x86_64-linux-gnu/libSimTKcommon.so.3.6;/usr/lib/x86_64-linux-gnu/libSimTKmath.so.3.6;/usr/lib/x86_64-linux-gnu/libSimTKsimbody.so.3.6;/usr/lib/x86_64-linux-gnu/libdart.so.6.9.2;/usr/lib/x86_64-linux-gnu/libgazebo.so;/usr/lib/x86_64-linux-gnu/libgazebo_client.so;/usr/lib/x86_64-linux-gnu/libgazebo_gui.so;/usr/lib/x86_64-linux-gnu/libgazebo_sensors.so;/usr/lib/x86_64-linux-gnu/libgazebo_rendering.so;/usr/lib/x86_64-linux-gnu/libgazebo_physics.so;/usr/lib/x86_64-linux-gnu/libgazebo_ode.so;/usr/lib/x86_64-linux-gnu/libgazebo_transport.so;/usr/lib/x86_64-linux-gnu/libgazebo_msgs.so;/usr/lib/x86_64-linux-gnu/libgazebo_util.so;/usr/lib/x86_64-linux-gnu/libgazebo_common.so;/usr/lib/x86_64-linux-gnu/libgazebo_gimpact.so;/usr/lib/x86_64-linux-gnu/libgazebo_opcode.so;/usr/lib/x86_64-linux-gnu/libgazebo_opende_ou.so;/usr/lib/x86_64-linux-gnu/libboost_system.so.1.71.0;/usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.71.0;/usr/lib/x86_64-linux-gnu/libboost_program_options.so.1.71.0;/usr/lib/x86_64-linux-gnu/libboost_regex.so.1.71.0;/usr/lib/x86_64-linux-gnu/libboost_iostreams.so.1.71.0;/usr/lib/x86_64-linux-gnu/libprotobuf.so;-lpthread;/usr/lib/x86_64-linux-gnu/libsdformat9.so.9.8.0;/usr/lib/x86_64-linux-gnu/libboost_date_time.so.1.71.0;optimized;/usr/lib/x86_64-linux-gnu/libOgreTerrain.so;debug;/usr/lib/x86_64-linux-gnu/libOgreTerrain.so;optimized;/usr/lib/x86_64-linux-gnu/libOgrePaging.so;debug;/usr/lib/x86_64-linux-gnu/libOgrePaging.so;OgreTerrain;OgrePaging;OgreMain;pthread;/usr/lib/x86_64-linux-gnu/libignition-math6.so.6.15.1;/usr/lib/x86_64-linux-gnu/libignition-transport8.so.8.3.0;/usr/lib/x86_64-linux-gnu/libignition-msgs5.so.5.10.0;/usr/lib/x86_64-linux-gnu/libignition-common3-graphics.so.3.14.2;/usr/lib/x86_64-linux-gnu/libignition-fuel_tools4.so.4.6.0;/usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.12.8;/usr/lib/x86_64-linux-gnu/libboost_thread.so.1.71.0;/usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_core.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_dnn.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_features2d.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_flann.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_highgui.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_imgcodecs.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_ml.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_photo.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_stitching.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_video.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_videoio.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_aruco.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_bgsegm.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_bioinspired.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_ccalib.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_datasets.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_dnn_objdetect.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_dnn_superres.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_dpm.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_face.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_freetype.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_fuzzy.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_hdf.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_hfs.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_img_hash.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_line_descriptor.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_optflow.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_phase_unwrapping.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_plot.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_quality.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_reg.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_rgbd.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_saliency.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_shape.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_stereo.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_structured_light.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_superres.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_surface_matching.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_text.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_tracking.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_videostab.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_viz.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_ximgproc.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_xobjdetect.so.4.2.0;/usr/lib/x86_64-linux-gnu/libopencv_xphoto.so.4.2.0")
foreach(library ${libraries})
  # keep build configuration keywords, target names and absolute libraries as-is
  if("${library}" MATCHES "^(debug|optimized|general)$")
    list(APPEND mrs_gazebo_common_resources_LIBRARIES ${library})
  elseif(${library} MATCHES "^-l")
    list(APPEND mrs_gazebo_common_resources_LIBRARIES ${library})
  elseif(${library} MATCHES "^-")
    # This is a linker flag/option (like -pthread)
    # There's no standard variable for these, so create an interface library to hold it
    if(NOT mrs_gazebo_common_resources_NUM_DUMMY_TARGETS)
      set(mrs_gazebo_common_resources_NUM_DUMMY_TARGETS 0)
    endif()
    # Make sure the target name is unique
    set(interface_target_name "catkin::mrs_gazebo_common_resources::wrapped-linker-option${mrs_gazebo_common_resources_NUM_DUMMY_TARGETS}")
    while(TARGET "${interface_target_name}")
      math(EXPR mrs_gazebo_common_resources_NUM_DUMMY_TARGETS "${mrs_gazebo_common_resources_NUM_DUMMY_TARGETS}+1")
      set(interface_target_name "catkin::mrs_gazebo_common_resources::wrapped-linker-option${mrs_gazebo_common_resources_NUM_DUMMY_TARGETS}")
    endwhile()
    add_library("${interface_target_name}" INTERFACE IMPORTED)
    if("${CMAKE_VERSION}" VERSION_LESS "3.13.0")
      set_property(
        TARGET
        "${interface_target_name}"
        APPEND PROPERTY
        INTERFACE_LINK_LIBRARIES "${library}")
    else()
      target_link_options("${interface_target_name}" INTERFACE "${library}")
    endif()
    list(APPEND mrs_gazebo_common_resources_LIBRARIES "${interface_target_name}")
  elseif(TARGET ${library})
    list(APPEND mrs_gazebo_common_resources_LIBRARIES ${library})
  elseif(IS_ABSOLUTE ${library})
    list(APPEND mrs_gazebo_common_resources_LIBRARIES ${library})
  else()
    set(lib_path "")
    set(lib "${library}-NOTFOUND")
    # since the path where the library is found is returned we have to iterate over the paths manually
    foreach(path /home/laborobotique/catkin_ws/install/lib;/home/laborobotique/catkin_ws/devel/lib;/opt/ros/noetic/lib)
      find_library(lib ${library}
        PATHS ${path}
        NO_DEFAULT_PATH NO_CMAKE_FIND_ROOT_PATH)
      if(lib)
        set(lib_path ${path})
        break()
      endif()
    endforeach()
    if(lib)
      _list_append_unique(mrs_gazebo_common_resources_LIBRARY_DIRS ${lib_path})
      list(APPEND mrs_gazebo_common_resources_LIBRARIES ${lib})
    else()
      # as a fall back for non-catkin libraries try to search globally
      find_library(lib ${library})
      if(NOT lib)
        message(FATAL_ERROR "Project '${PROJECT_NAME}' tried to find library '${library}'.  The library is neither a target nor built/installed properly.  Did you compile project 'mrs_gazebo_common_resources'?  Did you find_package() it before the subdirectory containing its code is included?")
      endif()
      list(APPEND mrs_gazebo_common_resources_LIBRARIES ${lib})
    endif()
  endif()
endforeach()

set(mrs_gazebo_common_resources_EXPORTED_TARGETS "")
# create dummy targets for exported code generation targets to make life of users easier
foreach(t ${mrs_gazebo_common_resources_EXPORTED_TARGETS})
  if(NOT TARGET ${t})
    add_custom_target(${t})
  endif()
endforeach()

set(depends "gazebo_plugins;gazebo_ros;geometry_msgs;roscpp;std_msgs;tf2;tf2_msgs;tf2_ros")
foreach(depend ${depends})
  string(REPLACE " " ";" depend_list ${depend})
  # the package name of the dependency must be kept in a unique variable so that it is not overwritten in recursive calls
  list(GET depend_list 0 mrs_gazebo_common_resources_dep)
  list(LENGTH depend_list count)
  if(${count} EQUAL 1)
    # simple dependencies must only be find_package()-ed once
    if(NOT ${mrs_gazebo_common_resources_dep}_FOUND)
      find_package(${mrs_gazebo_common_resources_dep} REQUIRED NO_MODULE)
    endif()
  else()
    # dependencies with components must be find_package()-ed again
    list(REMOVE_AT depend_list 0)
    find_package(${mrs_gazebo_common_resources_dep} REQUIRED NO_MODULE ${depend_list})
  endif()
  _list_append_unique(mrs_gazebo_common_resources_INCLUDE_DIRS ${${mrs_gazebo_common_resources_dep}_INCLUDE_DIRS})

  # merge build configuration keywords with library names to correctly deduplicate
  _pack_libraries_with_build_configuration(mrs_gazebo_common_resources_LIBRARIES ${mrs_gazebo_common_resources_LIBRARIES})
  _pack_libraries_with_build_configuration(_libraries ${${mrs_gazebo_common_resources_dep}_LIBRARIES})
  _list_append_deduplicate(mrs_gazebo_common_resources_LIBRARIES ${_libraries})
  # undo build configuration keyword merging after deduplication
  _unpack_libraries_with_build_configuration(mrs_gazebo_common_resources_LIBRARIES ${mrs_gazebo_common_resources_LIBRARIES})

  _list_append_unique(mrs_gazebo_common_resources_LIBRARY_DIRS ${${mrs_gazebo_common_resources_dep}_LIBRARY_DIRS})
  _list_append_deduplicate(mrs_gazebo_common_resources_EXPORTED_TARGETS ${${mrs_gazebo_common_resources_dep}_EXPORTED_TARGETS})
endforeach()

set(pkg_cfg_extras "")
foreach(extra ${pkg_cfg_extras})
  if(NOT IS_ABSOLUTE ${extra})
    set(extra ${mrs_gazebo_common_resources_DIR}/${extra})
  endif()
  include(${extra})
endforeach()
