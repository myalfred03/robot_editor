#include <QApplication>
#include <ros/ros.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"

int main(int argc, char** argv)
{
	if(!ros::isInitialized())
	{
		ros::init(argc, argv, "robot_editor", ros::init_options::AnonymousName);
	}

	QApplication app(argc, argv);

  MainWindow robot_editor;
	robot_editor.show();

	return app.exec();
}
