#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QFileDialog>
#include <QFile>
#include <QTextStream>
#include <ros/package.h>


#include "robot_preview.h"
#include <QString>
#include <cstdlib>
#include <fstream>
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>
#include <XmlRpcValue.h>
#include <sensor_msgs/JointState.h>
#include <kdl_parser/kdl_parser.hpp>
#include <robot_state_publisher/robot_state_publisher.h>

double ToG    = 57.295779513;


MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  firstLoad=true;
  ui->setupUi(this);

  robot_preview_ = new RobotPreview(ui->mdiArea);

  ui->mdiArea->addSubWindow(robot_preview_, Qt::FramelessWindowHint); //mdiarea various screen

  robot_preview_->showMaximized();


  setUpHighlighter();
  //init status bar
//  ui->outputText->parentWindow=this;
  ui->statusBar->showMessage(tr("Ready"));
  //--------init toolbar------------
  //ui->statusBar->setStyleSheet("QStatusBar{background:rgb(50,50,50);}");
  ui->mainToolBar->setMovable(false);
  ui->mainToolBar->setStyleSheet("QToolButton:hover {background-color:darkgray} QToolBar {background: rgb(179, 204, 204);border: none;}");
  //--------------------------------

  runIcon.addPixmap(QPixmap(":/img/robot.png"));
  stopIcon.addPixmap(QPixmap(":/img/stop.png"));
//  errorIcon.addPixmap(QPixmap(":/img/error.png"));
//  RerrorIcon.addPixmap(QPixmap(":/img/error_red.png"));


  QPalette windowPalette=this->palette();
  windowPalette.setColor(QPalette::Active,QPalette::Window,QColor(82,82,82));
  windowPalette.setColor(QPalette::Inactive,QPalette::Window,QColor(82,82,82));
  this->setPalette(windowPalette);
  //--------------------------------
  initFileData();
  connect(ui->actionNewFile,SIGNAL(triggered(bool)),this,SLOT(newFile()));
  connect(ui->actionOpen,SIGNAL(triggered(bool)),this,SLOT(openFile()));
  connect(ui->actionSave_File,SIGNAL(triggered(bool)),this,SLOT(saveFile()));
  connect(ui->actionUndo,SIGNAL(triggered(bool)),this,SLOT(undo()));
  connect(ui->actionRedo,SIGNAL(triggered(bool)),this,SLOT(redo()));
  connect(ui->editor,SIGNAL(textChanged()),this,SLOT(changeSaveState()));
  connect(ui->actionRun,SIGNAL(triggered(bool)),this,SLOT(run()));
//  connect(&process,SIGNAL(finished(int)),this,SLOT(runFinished(int)));
//  connect(&process,SIGNAL(readyReadStandardOutput()),this,SLOT(updateOutput()));
//  connect(&process,SIGNAL(readyReadStandardError()),this,SLOT(updateError()));
  connect(ui->actionAbout,SIGNAL(triggered(bool)),this,SLOT(about()));
  fileSaved=true;

  connect(ui->slider1, SIGNAL(valueChanged(int)), SLOT(updateDialer()));
  connect(ui->slider2, SIGNAL(valueChanged(int)), this, SLOT(updateDialer()));
  connect(ui->slider3, SIGNAL(valueChanged(int)), this, SLOT(updateDialer()));
  connect(ui->slider4, SIGNAL(valueChanged(int)), this, SLOT(updateDialer()));
  connect(ui->slider5, SIGNAL(valueChanged(int)), this, SLOT(updateDialer()));
  connect(ui->slider6, SIGNAL(valueChanged(int)), this, SLOT(updateDialer()));



  publisher_thread_ = new boost::thread(boost::bind(&MainWindow::publishJointStates, this));


//  msg1.points.resize(1);
//  msg1.points[0].positions.resize(6);
//  msgolder.points.resize(1);
//  msgolder.points[0].positions.resize(6);
//   joint_pub =       nh_.advertise<trajectory_msgs::JointTrajectory>("set_joint_trajectory", 10);
//   joint_sub_limit = nh_.subscribe("/joint_limits",10,&MainWindow::jointsizeCallback, this);

//   spinner = boost::shared_ptr<ros::AsyncSpinner>(new ros::AsyncSpinner(1));
//   spinner->start();
//   boost::thread* publisher_thread_;

//   publisher_thread_ = new boost::thread(boost::bind(&ROSGUI::publishJointStates, this));



}

MainWindow::~MainWindow()
{
  delete ui;
}
void MainWindow::setUpHighlighter(){
  QFont font;
  font.setFamily("Courier");
  font.setFixedPitch(true);
  font.setPointSize(12);
  font.setBold(true);
  ui->editor->setFont(font);
  ui->editor->setTabStopWidth(fontMetrics().width(QLatin1Char('9'))*4);
  highlighter=new Highlighter(ui->editor->document());
}

void MainWindow::resizeEvent(QResizeEvent *event){
  QMainWindow::resizeEvent(event);
  ui->editor->setGeometry(10,0,width()-20,height()-ui->statusBar->height()-ui->mainToolBar->height()-80-15);
//  ui->outputText->setGeometry(10,ui->editor->height()+10,this->width()-20,80);
}
void MainWindow::initFileData(){
  fileName=tr("Untitled.urdf");
  filePath=QString::fromUtf8( ros::package::getPath("robot_editor").c_str()) + "/modelos"; //QDir::homePath()+"/ros_qtc_plugin/src/interpreter_gui/Script";//tr("/home/yesser/ros_qtc_plugin/src/interpreter_gui"); //QCoreApplication::applicationDirPath()
  fileSaved=true;
  isRunning=false;
}
void MainWindow::undo(){
  ui->editor->undo();
}
void MainWindow::redo(){
  ui->editor->redo();
}
void MainWindow::saveFile(){
  QString savePath=QFileDialog::getSaveFileName(this,tr("Elija la ruta y nombre del archivo a guardar"),filePath,tr("URDF File(*.urdf)"));
  if(!savePath.isEmpty()){
      QFile out(savePath);
      out.open(QIODevice::WriteOnly|QIODevice::Text);
      QTextStream str(&out);
      str<<ui->editor->toPlainText();
      out.close();
      fileSaved=true;
      QRegularExpression re(tr("(?<=\\/)\\w+\\.urdf"));
      fileName=re.match(savePath).captured();
      filePath=savePath;
      this->setWindowTitle(tr("Robot Editor URDF - ")+fileName);
    }
//  ui->actionError_Datos->setIcon(errorIcon);

}
void MainWindow::newFile(){
  MainWindow *newWindow=new MainWindow();
  QRect newPos=this->geometry();
  newWindow->setGeometry(newPos.x()+10,newPos.y()+10,newPos.width(),newPos.height());
  newWindow->show();
//  ui->actionError_Datos->setIcon(errorIcon);
}
void MainWindow::openFile(){
  if(!fileSaved){
      if(QMessageBox::Save==QMessageBox::question(this,tr("Archivo no guardado"),tr("Guardar Archivo Actual"),QMessageBox::Save,QMessageBox::Cancel))
        saveFile();
    }
  QString openPath=QFileDialog::getOpenFileName(this,tr("Seleccione el archivo para abrir"),filePath,tr("URDF File(*.urdf)"));
  if(!openPath.isEmpty()){
      QFile in(openPath);
      in.open(QIODevice::ReadOnly|QIODevice::Text);
      QTextStream str(&in);
      ui->editor->setPlainText(str.readAll());
      QRegularExpression re(tr("(?<=\\/)\\w+\\.urdf"));
      fileName=re.match(openPath).captured();
      this->setWindowTitle(tr("Robot Editor URDF - ")+fileName);
      filePath=openPath;
      fileSaved=true;
      std::ifstream selected_file(filePath.toStdString()); // "/home/yesser/ros_qtc_plugin/src/interpreter_gui/Script/firstScript.rrun"


      if(selected_file.good()){
        std::string file_contents((std::istreambuf_iterator<char>(selected_file)), std::istreambuf_iterator<char>());
        this->updateURDF(file_contents);
      }
    }
//  ui->actionError_Datos->setIcon(errorIcon);
}
void MainWindow::run(){
  trajectory_msgs::JointTrajectory msg;
  if(isRunning){
//      process.terminate();
      ui->actionRun->setIcon(runIcon);
      return;
    }
  if(!fileSaved){
//      if(QMessageBox::Save==QMessageBox::question(this,tr("Archivo no guardado"),tr("Guardar Archivo Actual？"),QMessageBox::Save,QMessageBox::Cancel))
//        saveFile();
    QFile out(filePath);
    out.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream str(&out);
    str<<ui->editor->toPlainText();
    out.close();
    fileSaved=true;


    }
  if(fileSaved){
    //if(process!=nullptr)delete process;
    isRunning=true;
    ui->statusBar->showMessage(tr("Programa En Ejecucion..."));
//    ui->outputText->clear();
    output.clear();
    error.clear();
    QString buildPath;
    QRegularExpression re(tr(".*(?=\\.urdf)"));
    buildPath=re.match(filePath).captured();
//    qDebug()<<filePath;
//    process.start("bash", QStringList() << "-c" << QString(tr("g++ ")+filePath+tr(" -o ")+buildPath+tr(";")+buildPath));
//    process.waitForStarted();

//    ui->outputText->setFocus();
    ui->actionRun->setIcon(stopIcon);


    std::ifstream selected_file(filePath.toStdString()); // "/home/yesser/ros_qtc_plugin/src/interpreter_gui/Script/firstScript.rrun"


    if(selected_file.good()){
      std::string file_contents((std::istreambuf_iterator<char>(selected_file)), std::istreambuf_iterator<char>());
      this->updateURDF(file_contents);
    }

    this->runFinished(0);


    }
}

void MainWindow::updateURDF(const std::string& urdf)
{
  XmlRpc::XmlRpcValue robot_description(urdf);
  nh_.setParam("robot_editor/robot_description", robot_description);

  boost::mutex::scoped_lock state_pub_lock(state_pub_mutex_);
//  if(robot_tree_ != NULL)
//    delete robot_tree_;
  if(robot_state_pub_ != NULL)
    delete robot_state_pub_;

//  robot_tree_ = new KDL::Tree();

  if (!urdf_model.initString(urdf))    //Si se abre desde una direccion de ruta de archivo (//home/user//..//name.urdf) .initFile
  {
      ROS_ERROR("Failed to parse urdf file in model param");
//      nh.shutdown();
      //return false;
  }

  if (!kdl_parser::treeFromUrdfModel(urdf_model, robot_tree_)){
         ROS_ERROR("Failed to construct kdl tree");
//         nh.shutdown();
      }

//  if(!kdl_parser::treeFromString(urdf, *robot_tree_))
//  {
//    ROS_ERROR("Failed to construct KDL tree");
//    return;
//  }

  this->updateWidgets(robot_tree_, urdf_model);
  // create a robot state publisher from the tree
    robot_state_pub_ = new robot_state_publisher::RobotStatePublisher(robot_tree_);

  // now create a map with joint name and positions
  joint_positions_.clear();
  const std::map<std::string, KDL::TreeElement>& segments = robot_tree_.getSegments();
  for(std::map<std::string, KDL::TreeElement>::const_iterator it=segments.begin();
    it != segments.end(); it++)
  {
    joint_positions_[it->second.segment.getJoint().getName()] = 0.0;
  }

  // refresh the preview
  robot_preview_->refresh("robot_editor/" + robot_tree_.getRootSegment()->first);


}
void MainWindow::updateWidgets(KDL::Tree& tree_, urdf::Model& model){

 njnt=0;
  if(!tree_.getChain("base_link", "tool0", kdl_chain))
      {
          ROS_ERROR("Error getting KDL chain");
//           nh.shutdown();
      }
  njnt = kdl_chain.getNrOfJoints();
  std::vector<double>joint_lower;
  std::vector<double>joint_upper;
  joint_lower.clear();
  joint_upper.clear();

  std::vector<std::string> seg_names;

  for(int i=0; i<njnt; i++)
      seg_names.push_back(kdl_chain.getSegment(i).getJoint().getName());

  for (std::map<std::string,boost::shared_ptr<urdf::Joint> >::iterator joint = model.joints_.begin(); joint != model.joints_.end(); ++joint) {
      if ( joint->second->limits && std::find(seg_names.begin(), seg_names.end(),joint->second->name)!=seg_names.end() ) {
          if (joint->second->limits->lower != joint->second->limits->upper) {
             // limited_jnt_names.push_back(joint->second->name);
              joint_lower.push_back(joint->second->limits->lower);
              joint_upper.push_back(joint->second->limits->upper);
    }
   }
  }

  ui->spinBox->setMinimum(joint_lower[0]*ToG);
  ui->spinBox->setMaximum(joint_upper[0]*ToG);
  ui->spinBox->setSingleStep(1);

  ui->spinBox_2->setMinimum(joint_lower[1]*ToG);
  ui->spinBox_2->setMaximum(joint_upper[1]*ToG);
  ui->spinBox_2->setSingleStep(1);

  ui->spinBox_3->setMinimum(joint_lower[2]*ToG);
  ui->spinBox_3->setMaximum(joint_upper[2]*ToG);
  ui->spinBox_3->setSingleStep(1);

  ui->spinBox_4->setMinimum(joint_lower[3]*ToG);
  ui->spinBox_4->setMaximum(joint_upper[3]*ToG);
  ui->spinBox_4->setSingleStep(1);

  ui->spinBox_5->setMinimum(joint_lower[4]*ToG);
  ui->spinBox_5->setMaximum(joint_upper[4]*ToG);
  ui->spinBox_5->setSingleStep(1);

  ui->spinBox_6->setMinimum(joint_lower[5]*ToG);
  ui->spinBox_6->setMaximum(joint_upper[5]*ToG);
  ui->spinBox_6->setSingleStep(1);



  ui->slider1->setMinimum(joint_lower[0]*ToG);
  ui->slider1->setMaximum(joint_upper[0]*ToG);
  ui->slider1->setSingleStep(1);

  ui->slider2->setMinimum(joint_lower[1]*ToG);
  ui->slider2->setMaximum(joint_upper[1]*ToG);
  ui->slider2->setSingleStep(1);

  ui->slider3->setMinimum(joint_lower[2]*ToG);
  ui->slider3->setMaximum(joint_upper[2]*ToG);
  ui->slider3->setSingleStep(1);

  ui->slider4->setMinimum(joint_lower[3]*ToG);
  ui->slider4->setMaximum(joint_upper[3]*ToG);
  ui->slider4->setSingleStep(1);

  ui->slider5->setMinimum(joint_lower[4]*ToG);
  ui->slider5->setMaximum(joint_upper[4]*ToG);
  ui->slider5->setSingleStep(1);

  ui->slider6->setMinimum(joint_lower[5]*ToG);
  ui->slider6->setMaximum(joint_upper[5]*ToG);
  ui->slider6->setSingleStep(1);

  switch (njnt) {

    case 0:
    {
    ui->slider1->setEnabled(false);
    ui->slider2->setEnabled(false);
    ui->slider3->setEnabled(false);
    ui->slider4->setEnabled(false);
    ui->slider5->setEnabled(false);
    ui->slider6->setEnabled(false);

    ui->spinBox->setEnabled(false);
    ui->spinBox_2->setEnabled(false);
    ui->spinBox_3->setEnabled(false);
    ui->spinBox_4->setEnabled(false);
    ui->spinBox_5->setEnabled(false);
    ui->spinBox_6->setEnabled(false);


    ui->spinBox->setValue(0);
    ui->spinBox_2->setValue(0);
    ui->spinBox_3->setValue(0);
    ui->spinBox_4->setValue(0);
    ui->spinBox_5->setValue(0);
    ui->spinBox_6->setValue(0);

    ui->slider1->setValue(0);
    ui->slider2->setValue(0);
    ui->slider3->setValue(0);
    ui->slider4->setValue(0);
    ui->slider5->setValue(0);
    ui->slider6->setValue(0);

   break;


    }

  case 1:
  {
  ui->slider1->setEnabled(true);
  ui->slider2->setEnabled(false);
  ui->slider3->setEnabled(false);
  ui->slider4->setEnabled(false);
  ui->slider5->setEnabled(false);
  ui->slider6->setEnabled(false);

  ui->spinBox->setEnabled(true);
  ui->spinBox_2->setEnabled(false);
  ui->spinBox_3->setEnabled(false);
  ui->spinBox_4->setEnabled(false);
  ui->spinBox_5->setEnabled(false);
  ui->spinBox_6->setEnabled(false);
  break;

  }
  case 2:
  {
  ui->slider1->setEnabled(true);
  ui->slider2->setEnabled(true);
  ui->slider3->setEnabled(false);
  ui->slider4->setEnabled(false);
  ui->slider5->setEnabled(false);
  ui->slider6->setEnabled(false);

  ui->spinBox->setEnabled(true);
  ui->spinBox_2->setEnabled(true);
  ui->spinBox_3->setEnabled(false);
  ui->spinBox_4->setEnabled(false);
  ui->spinBox_5->setEnabled(false);
  ui->spinBox_6->setEnabled(false);
  break;

  }

  case 3:
  {
  ui->slider1->setEnabled(true);
  ui->slider2->setEnabled(true);
  ui->slider3->setEnabled(true);
  ui->slider4->setEnabled(false);
  ui->slider5->setEnabled(false);
  ui->slider6->setEnabled(false);

  ui->spinBox->setEnabled(true);
  ui->spinBox_2->setEnabled(true);
  ui->spinBox_3->setEnabled(true);
  ui->spinBox_4->setEnabled(false);
  ui->spinBox_5->setEnabled(false);
  ui->spinBox_6->setEnabled(false);
  break;

  }

  case 4:
  {
  ui->slider1->setEnabled(true);
  ui->slider2->setEnabled(true);
  ui->slider3->setEnabled(true);
  ui->slider4->setEnabled(true);
  ui->slider5->setEnabled(false);
  ui->slider6->setEnabled(false);

  ui->spinBox->setEnabled(true);
  ui->spinBox_2->setEnabled(true);
  ui->spinBox_3->setEnabled(true);
  ui->spinBox_4->setEnabled(true);
  ui->spinBox_5->setEnabled(false);
  ui->spinBox_6->setEnabled(false);
  break;

  }

  case 5:
  {
  ui->slider1->setEnabled(true);
  ui->slider2->setEnabled(true);
  ui->slider3->setEnabled(true);
  ui->slider4->setEnabled(true);
  ui->slider5->setEnabled(true);
  ui->slider6->setEnabled(false);

  ui->spinBox->setEnabled(true);
  ui->spinBox_2->setEnabled(true);
  ui->spinBox_3->setEnabled(true);
  ui->spinBox_4->setEnabled(true);
  ui->spinBox_5->setEnabled(true);
  ui->spinBox_6->setEnabled(false);
  break;

  }

  case 6:
  {
  ui->slider1->setEnabled(true);
  ui->slider2->setEnabled(true);
  ui->slider3->setEnabled(true);
  ui->slider4->setEnabled(true);
  ui->slider5->setEnabled(true);
  ui->slider6->setEnabled(true);

  ui->spinBox->setEnabled(true);
  ui->spinBox_2->setEnabled(true);
  ui->spinBox_3->setEnabled(true);
  ui->spinBox_4->setEnabled(true);
  ui->spinBox_5->setEnabled(true);
  ui->spinBox_6->setEnabled(true);
  break;

  }

  } //end switch


}



void MainWindow::publishJointStates()
{
  ros::Rate loop_rate(10);

  while(true)
  {
    { // lock the state publisher objects and run
      //boost::mutex::scoped_lock state_pub_lock(state_pub_mutex_);
      if(robot_state_pub_ != NULL)
      {
         robot_state_pub_->publishTransforms(joint_positions_, ros::Time::now(), "robot_editor");
         robot_state_pub_->publishFixedTransforms("robot_editor");
         ROS_INFO_STREAM(joint_positions_.size());
         ROS_INFO("Published joint state info");
      }
    }
//    try {
//      boost::this_thread::interruption_point();
//    } catch(const boost::thread_interrupted& o) {
//      break; // quit the thread's loop
//    }


    loop_rate.sleep();
  }

}

void MainWindow::updateDialer()
{

    joint_positions_["joint_1"]= ui->slider1->value()/ToG;
    joint_positions_["joint_2"]= ui->slider2->value()/ToG;
    joint_positions_["joint_3"]= ui->slider3->value()/ToG;
    joint_positions_["joint_4"]= ui->slider4->value()/ToG;
    joint_positions_["joint_5"]= ui->slider5->value()/ToG;
    joint_positions_["joint_6"]= ui->slider6->value()/ToG;

}


//void MainWindow::jointsizeCallback(const std_msgs::Float32MultiArray::ConstPtr &msglimit) //Valores de los limtes de los joints
//{
//  std::cout<<"DATAOK"<< std::endl;

//  limit.data.resize(12);

//    limit = *msglimit;
//    for (int i =0; i<12;i++)
//    {
//  std::cout<< limit.data[i]<< std::endl;
//    }
//}


//trajectory_msgs::JointTrajectory MainWindow::comandos(std::string &comando){

//  std::vector<double> jointvalues(6);

//  std::vector<std::string> partes=split(comando, ' ');
//  if(partes.size()==0){
//        //gzerr<<"No se ha indicado un comando válido."<<"\r\n";
//      }else{
//        switch(partes[0][6]){
//          case '1':
//            if(partes.size()>1){
//              std::cout << "I have it 1 " << partes[1]  <<std::endl;
//              this->updateOutput(partes[1]);
//              msg1.points[0].positions[0] = std::stod(partes[1]);
//              if(msg1.points[0].positions[0]>limit.data[0] && msg1.points[0].positions[0]<limit.data[6] ){
//                std::cout<< "is ok for now"<< std::endl;
//                }
//              else {
//                msg1.points[0].positions[0] = 0.00;
//                this->updateError();
//                   }
//            }
//            break;
//          case '2':
//            if(partes.size()>1){
//              std::cout << "I have it  2 " << partes[1]  <<std::endl;
//              this->updateOutput(partes[1]);
//              msg1.points[0].positions[1] = std::stod(partes[1]);
//              if(msg1.points[0].positions[1]>limit.data[1] && msg1.points[0].positions[1]<limit.data[7] ){
//                std::cout<< "is ok for now"<< std::endl;
//                }
//              else {
//                msg1.points[0].positions[1] = 0.00;
//                this->updateError();
//                   }
//            }
//            break;

//        case '3':
//          if(partes.size()>1){
//            std::cout << "I have it  3 " << partes[1]  <<std::endl;
//            this->updateOutput(partes[1]);
//            msg1.points[0].positions[2] = std::stod(partes[1]);
//            if(msg1.points[0].positions[2]>limit.data[2] && msg1.points[0].positions[2]<limit.data[8] ){
//              std::cout<< "is ok for now"<< std::endl;
//              }
//            else {
//              msg1.points[0].positions[2] = 0.00;
//              this->updateError();
//                 }
//          }
//          break;

//        case '4':
//          if(partes.size()>1){
//            std::cout << "I have it  4 " << partes[1]  <<std::endl;
//            this->updateOutput(partes[1]);
//            msg1.points[0].positions[3] = std::stod(partes[1]);
//            if(msg1.points[0].positions[3]>limit.data[3] && msg1.points[0].positions[3]<limit.data[9] ){
//              std::cout<< "is ok for now"<< std::endl;
//              }
//            else {
//              msg1.points[0].positions[3] = 0.00;
//              this->updateError();
//                 }
//          }
//          break;

//        case '5':
//          if(partes.size()>1){
//            std::cout << "I have it  5 " << partes[1]  <<std::endl;
//            this->updateOutput(partes[1]);
//            msg1.points[0].positions[4] = std::stod(partes[1]);
//            if(msg1.points[0].positions[4]>limit.data[4] && msg1.points[0].positions[4]<limit.data[10] ){
//              std::cout<< "is ok for now"<< std::endl;
//              }
//            else {
//              msg1.points[0].positions[4] = 0.00;
//              this->updateError();
//                 }
//          }
//          break;

//          case 'm':
//            //m union posicion_radianes
//            //Mueve la unión hasta la posición en radianes indicada
//            if(partes.size()>2){
////              robot->mover(partes[1],std::stod(partes[2]));
//            }
//            break;

//          case 'w':
//            //w [union]
//            //Espera hasta que la unión halla llegado a su destino. Si no se indica la unión se espera hata terminar todas
//            ROS_INFO("eseparndo");
//            break;
//          case 's':
//            //s milisegundos
//            //Duerme los milisegundos indicados.

//            //de momento nos dormimos durante el tiempo indicado.
//            std::string tiempo(partes[1]);
//            ROS_INFO("durmiendo %d",std::stoi(tiempo));
//            boost::this_thread::sleep(boost::posix_time::milliseconds(std::stoi(tiempo)));
//            //usleep(std::stoi(tiempo));
//            ROS_INFO("despierto");
//            break;/**/
//        }
//      }
////  for (int k = 0; k < 6; k++) {
////   msg1.points[0].positions[k] =jointvalues[k]; //array [i]
////                              }
////  msgolder = msg1;
//return msg1;
//}

//std::vector<std::string> MainWindow::split(const std::string &c, char d){
//  std::vector<std::string> resultado;

//  std::stringstream cs(c);
//  std::string parte;
//  while(std::getline(cs, parte, d)){
//    resultado.push_back(parte);
//  }

//  return resultado;
//}






void MainWindow::runFinished(int code){
  ui->actionRun->setIcon(runIcon);
  isRunning=false;
  qDebug()<<tr("exit code=")<<code;
  ui->statusBar->showMessage(tr("Ready"));

}
void MainWindow::updateOutput(std::string &info)
{
  output=QString::fromLocal8Bit(info.c_str());
  //ui->outputText->setPlainText(output+tr("\n")+error);
//  ui->outputText->setPlainText(ui->outputText->toPlainText()+tr("Ejecutando Movimiento ")+output+tr("... \n"));//+tr("\n"));
}
void MainWindow::updateError(){
  error=QString("Valores Fuera del espacio de trabajo");
//  //ui->outputText->setPlainText(output+tr("\n")+error);
//  ui->outputText->setPlainText(ui->outputText->toPlainText()+error);//+tr("\n"));
//  ui->actionError_Datos->isEnabled();
//  ui->actionError_Datos->setIcon(RerrorIcon);
  isRunning=false;
}
void MainWindow::inputData(QString data){
//  if(isRunning)process.write(data.toLocal8Bit());
}
void MainWindow::closeEvent(QCloseEvent *event){
  if(!fileSaved){
      if(QMessageBox::Save==QMessageBox::question(this,tr("¿Salir sin guardar?"),tr("El archivo actual no se ha guardado"),QMessageBox::Save,QMessageBox::Cancel))
        saveFile();
      fileSaved=true;
    }
}
void MainWindow::about(){
  QMessageBox::information(this,tr("About"),tr(" Yeser M. v1.1 \n Universidad Nacional de Ingenieria \nmyalfredo03@ieee.org"),QMessageBox::Ok);
}
