#include <QHBoxLayout>

#include <rviz/visualization_manager.h>
#include <rviz/render_panel.h>
#include <rviz/display.h>

#include "robot_preview.h"

RobotPreview::RobotPreview(QWidget* parent) :
	QWidget(parent)
{
	// construct and lay out render panel
	render_panel_ = new rviz::RenderPanel();
	//render_panel_->setMinimumWidth(parent->width());
	//render_panel_->setMinimumHeight(520);
	QHBoxLayout* main_layout = new QHBoxLayout;
	main_layout->addWidget(render_panel_);

	// set the top-level layout for this widget
	setLayout(main_layout);

	// initialize the main RViz Classes
	manager_ = new rviz::VisualizationManager(render_panel_);
	render_panel_->initialize(manager_->getSceneManager(), manager_);
	manager_->initialize();
	manager_->startUpdate();

	// Create a grid display
	grid_ = manager_->createDisplay("rviz/Grid", "Robot Preview", true);
	ROS_ASSERT(grid_ != NULL);

	// create a robot model display
	robot_model_ = manager_->createDisplay("rviz/RobotModel", "Robot Model", true);
	ROS_ASSERT(robot_model_ != NULL);
}

RobotPreview::~RobotPreview()
{
	delete manager_;
}