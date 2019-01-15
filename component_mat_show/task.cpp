// Copyright 2018 Shanghai Fangling Software Co., Ltd. All Rights Reserved.
// Author: Yalong Ye

#include "task.h"

#include <iostream>

using namespace std;

void Task::Run() {
  Component component;
  //Set User units.
  component.SetUnit(2.0);
  //Select parsing gcode file.
  component.LoadComponent("../≤‚ ‘G¥˙¬Î/71‘≤.TXT");
  //Set the rotation angle
  component.SetR(30.0);
  //Get offset.
  component.SetOffset(0.0, 0.0);
  //Get original mat.
  component.GetMatOriginal();
  //Get rotate mat.
  component.GetMatRotate();
  //Component into the collection.
  component_vec_.push_back(&component);
}
