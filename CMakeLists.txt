cmake_minimum_required(VERSION 2.8.3)
project(robot_editor)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  roslib
  rviz
  urdf
  tf
  kdl_parser
  robot_state_publisher
)

find_package(Boost REQUIRED COMPONENTS thread)

#find_package(Qt4 COMPONENTS QtCore QtGui REQUIRED)
#include(${QT_USE_FILE})
#add_definitions(-DQT_NO_KEYWORDS)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
set(QT_LIBRARIES Qt5::Widgets)
set(QT_LIBRARIES Qt5::Core)
set(QT_LIBRARIES Qt5::Gui)

# catkin_python_setup()

catkin_package(
  INCLUDE_DIRS include
#  LIBRARIES interpreter_gui
  CATKIN_DEPENDS
  roscpp
  std_msgs
  roslib
#  DEPENDS system_lib
)

###########
## Build ##
###########

link_directories(
     ${GAZEBO_LIBRARY_DIRS}
     ${GTKMM_LIBRARY_DIRS}  #es la interfaz C++ oficial para
                            #la popular biblioteca de interfaz gráfica GTK+.
     ${catkin_LIBRARY_DIRS}
    )

include_directories(
#  ${catkin_INCLUDE_DIRS}
#  ${Boost_INCLUDE_DIRS}
#  ${QT_INCLUDES}
  ${CMAKE_CURRENT_BINARY_DIR}
  include
  ${Qt5Core_INCLUDE_DIRS}
  ${Qt5Widgets_INCLUDE_DIRS}
  #  ${Qt5X11Extras_INCLUDE_DIRS}
  ${Boost_INCLUDE_DIR}
  ${catkin_INCLUDE_DIRS}
  ${GAZEBO_INCLUDE_DIRS}
  ${roscpp_INCLUDE_DIRS}
  ${Qt5Widgets_INCLUDE_DIRS}

)

set(QT_LIBRARIES Qt5::Widgets)

include_directories (${PROJECT_SOURCE_DIR})
include_directories (${PROJECT_BINARY_DIR})

set (MyProject_src
          src/main.cpp
	  src/robot_preview.cpp
          src/codeeditor.cpp
          src/completelistwidget.cpp
          src/console.cpp
          src/highlighter.cpp
          src/mainwindow.cpp
    )

set (MyProjectLib_ui
          ui/mainwindow.ui
    )

set (MyProjectLib_hdr
            include/robot_preview.h
            include/codeeditor.h
            include/completelistwidget.h
            include/console.h
            include/highlighter.h
            include/mainwindow.h
            include/ui_mainwindow.h

    )

set (MyProjectLib_qrc
           image.qrc
    )
QT5_WRAP_CPP(MyProjectLib_hdr_MOC ${MyProjectLib_hdr})
QT5_WRAP_UI(MyProjectLib_ui_MOC ${MyProjectLib_ui})
QT5_ADD_RESOURCES(MyProjectLib_qrc_MOC ${MyProjectLib_qrc})




add_executable(robot_editor ${MyProject_src}  ${MyProjectLib_hdr_MOC} ${MyProjectLib_ui_MOC} ${MyProjectLib_qrc_MOC})
target_link_libraries(robot_editor  ${QT_LIBRARIES}
                                    ${catkin_LIBRARIES}
                                    ${Boost_LIBRARIES}
                                    Qt5::Widgets
                                    Qt5::Core
                                    Qt5::Gui
                                    )


add_definitions(-std=c++11
                )
#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

#############
## Testing ##
#############
