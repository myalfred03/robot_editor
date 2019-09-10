#include <QHBoxLayout>
#include <QString>

#include <rviz/visualization_manager.h>
#include <rviz/render_panel.h>
#include <rviz/display.h>
#include <rviz/yaml_config_reader.h>
#include <rviz/yaml_config_writer.h>
#include <ros/package.h>
#include "robot_preview.h"

RobotPreview::RobotPreview(QWidget* parent) :
	QWidget(parent)
{
	// construct and lay out render panel
	render_panel_ = new rviz::RenderPanel();
	//render_panel_->setMinimumWidth(parent->width());
//	render_panel_->setMinimumHeight(1000);
//	render_panel_->setMinimumWidth(1000);
	QHBoxLayout* main_layout = new QHBoxLayout;
	main_layout->addWidget(render_panel_);

	// set the top-level layout for this widget
	setLayout(main_layout);

	// initialize the main RViz Classes
	manager_ = new rviz::VisualizationManager(render_panel_);
	render_panel_->initialize(manager_->getSceneManager(), manager_);

	rviz::YamlConfigReader reader;
	rviz::Config config;
	std::string filename = ros::package::getPath("rvizglabre")+"/config/lvr.rviz" ;
	reader.readFile( config, QString::fromStdString( filename ));
	  if( !reader.error() )
	  {
	      manager_->load( config.mapGetChild( "Visualization Manager" ));
	  }

	manager_->initialize();
	manager_->startUpdate();

	// Create a grid display
   grid_ = manager_->createDisplay("rviz/Grid", "Robot Preview", true);
   grid_->subProp( "Plane Cell Count" )->setValue( 30 );
   grid_->subProp( "Cell Size" )->setValue( 1 );
  // grid_->subProp( "Line Style" )->setValue( "Billboards" );
   //grid_->subProp( "Color" )->setValue( QColor( Qt::black ) );
   grid_->subProp( "Color" )->setValue( QColor(0, 0, 0));




  tF_   = manager_->createDisplay( "rviz/TF","TF", true); // active mode or disable at load model robot
  tF_->subProp( "Show Names" )->setValue(false);
  tF_->subProp( "Show Axes" )->setValue(true);
  tF_->subProp( "Show Arrows" )->setValue(false);
  tF_->subProp( "Marker Scale" )->setValue(1);
  tF_->subProp( "Frame Timeout" )->setValue(1);

	ROS_ASSERT(grid_ != NULL);

	// create a robot model display
	this->refresh();
}

RobotPreview::~RobotPreview()
{
	delete manager_;
  delete tF_;

}

void RobotPreview::refresh(const std::string& fixed_frame)
{
	manager_->setFixedFrame(QString::fromStdString(fixed_frame));
	
	if(robot_model_ != NULL)
		delete robot_model_;

	robot_model_ = manager_->createDisplay("rviz/RobotModel", "Robot Model", true);
	ROS_ASSERT(robot_model_ != NULL);

	robot_model_->subProp("TF Prefix")->setValue("robot_editor");
	robot_model_->subProp("Robot Description")->setValue("robot_editor/robot_description");
}
