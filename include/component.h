// Copyright 2018 Shanghai Fangling Software Co., Ltd. All Rights Reserved.
// Author: Yalong Ye

#ifdef DLL_IMPLEMENT  
#define DLL_API __declspec(dllexport)  
#else  
#define DLL_API __declspec(dllimport)  
#endif

#ifndef COMPONENT_H__
#define COMPONENT_H__

#include "opencv2/opencv.hpp"


#include <iostream>
#include <vector>

#include "gcodeparse/GCommand.h"
#include "gcodeparse/GCodeParse.h"
#include "obase/GCodeTypeDef.h"

using namespace std;
using namespace cv;
using namespace gcode;

//Analyze component drawing.
class Component {
 public:
  DLL_API Component();
  DLL_API Component(const Component &other);
  //Analysis gcode and draw.
  DLL_API bool LoadComponent(std::string path);
  //Set rotate angle.
  DLL_API int SetR(double R);
  //Get offset.
  DLL_API int SetOffset(double x_offset, double y_offset);
  //Set User units.
  DLL_API int SetUnit(double unit_1mm_to_pixs);
  //Get original mat
  DLL_API Mat &GetMatOriginal() {return m_img_original_;}
  //Get rotate mat
  DLL_API Mat &GetMatRotate() {return m_img_rotate_;}

  //Rotate angle.
  double R_;
  //x offset.
  double x_offset_;
  //y offset.
  double y_offset_;
  //User units.
  double unit_1mm_to_pixs_;
  //Mat height mm.
  double height_;
  //Mat height mm.
  double width_;
  //Rotate center for x mm.
  double x_center_;
  //Rotate center for y mm.
  double y_center_;

private:
  DLL_API inline void ComparePoint(double x, double y);
  DLL_API inline void UpdateMatInfo();
  DLL_API inline void DrawLine(GCommand &cmdline);
  DLL_API inline void DrawCycle(GCommand &cmdcycle);
  DLL_API inline void DrawLineRotate(GCommand &cmdline);
  DLL_API inline void DrawCycleRotate(GCommand &cmdcycle);
  DLL_API inline void CoordinateLine(GCommand &cmdline);
  DLL_API inline void CoordinateCycle(GCommand &cmdcycle);
  DLL_API inline void Draw();
  DLL_API inline void DrawRotate();

  GCodeParse gcode_parse_;
  double x_min_;
  double x_max_;
  double y_min_;
  double y_max_;
  Point2d point_start_;
  Point2d point_end_;
  Point2d centerpoint_;
  Size ellsize_;
  Mat m_img_, m_img_original_, m_img_rotate_;
  std::vector<GCommand> gcode_cmds_;
};

#endif // COMPONENT_H__