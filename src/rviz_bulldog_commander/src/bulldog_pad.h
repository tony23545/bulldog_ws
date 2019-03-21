#ifndef BULLDOG_PAD_H
#define BULLDOG_PAD_H

//所需要包含的头文件
#include <ros/ros.h>
#include "std_msgs/String.h"
#include <ros/console.h>
#include <rviz/panel.h>   //plugin基类的头文件

#include <QPushButton>
#include <QLabel>
#include <QTabWidget>
#include <QString>

#include <string>

namespace rviz_bulldog_commander
{
#define STATE_WAIT 0
#define STATE_DETECTED 1
#define STATE_PICKED 2

// 所有的plugin都必须是rviz::Panel的子类
class BulldogPanel: public rviz::Panel
{
// 后边需要用到Qt的信号和槽，都是QObject的子类，所以需要声明Q_OBJECT宏
Q_OBJECT
public:
  BulldogPanel( QWidget* parent = 0 );

protected:
  QTabWidget *tab;

  //Tab 1
  QPushButton *button_auto;

  // Tab 2
  QPushButton *button_detect;
  QPushButton *button_navigation1;
  QPushButton *button_navigation2;
  QPushButton *button_arrive;
  QPushButton *button_arrive_plan;
  QPushButton *button_pick;
  QPushButton *button_reset;
  QPushButton *button_pick_plan;
  QPushButton *button_place_plan;
  QPushButton *button_place;
  QPushButton *button_power;
  QPushButton *button_gripper_activate;
  QPushButton *button_left_gripper_close;
  QPushButton *button_right_gripper_close;
  QPushButton *button_left_gripper_open;
  QPushButton *button_right_gripper_open;
  QLabel *label_display;
  QLabel *label_pick;
  QLabel *label_place;
  QLabel *label_arrive;
  QLabel *label_detect;
  QLabel *label_navigation1;
  QLabel *label_navigation2;
  QLabel *label_reset;
  QString display;

  // Tab 3

  // ROS
  ros::NodeHandle n;
  ros::Publisher pub;
  ros::Publisher left_gripper_pub;
  ros::Publisher right_gripper_pub;
  ros::Subscriber sub;

  void callback(const std_msgs::String::ConstPtr& msg);

  // Variables
  int state; //State Machine: 0-STATE_WAIT, 1-STATE_DETECTED, 2-STATE_PICKED

private Q_SLOTS:
  void button_auto_click();
  void button_detect_click();
  void button_navigation1_click();
  void button_navigation2_click();
  void button_arrive_click();
  void button_arrive_plan_click();
  void button_pick_click();
  void button_pick_plan_click();
  void button_reset_click();
  void button_place_click();
  void button_place_plan_click();
  void button_power_click();
  void button_gripper_activate_click();
  void button_left_gripper_close_click();
  void button_right_gripper_close_click();
  void button_left_gripper_open_click();
  void button_right_gripper_open_click();
  void pub_gripper(ros::Publisher *pub, std::string str);
};

} // end namespace rviz_bulldog_commander

#endif // BULLDOG_PANEL_H
