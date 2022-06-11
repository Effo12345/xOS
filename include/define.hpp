#include "main.h"
#include <map>
#include "display/lvgl.h"

#ifndef DEFINE_H
#define DEFINE_H

//Use gif.clean() to remove the gif on reset

lv_obj_t * createBtn(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, lv_coord_t width, lv_coord_t height, const char * title, bool isHidden)
{
  //title = std::to_string(y).c_str();
  lv_obj_t * btnTemp = lv_btn_create(parent, NULL);
  //lv_obj_align(btn, NULL, align, offsetX, offsetY);
  lv_obj_set_pos(btnTemp, x, y);
  lv_obj_set_size(btnTemp, width, height);
  lv_obj_set_hidden(btnTemp, isHidden);

  lv_obj_t * label = lv_label_create(btnTemp, NULL);
  lv_label_set_text(label, title);
  lv_obj_align(label, NULL, LV_ALIGN_IN_TOP_MID, 0, 5);
  return btnTemp;
}

lv_obj_t * createImgBtn(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, const char * title, bool isHidden)
{
  //title = std::to_string(y).c_str();
  lv_obj_t * btnTemp = lv_imgbtn_create(parent, NULL);
  //lv_obj_align(btn, NULL, align, offsetX, offsetY);
  lv_obj_set_pos(btnTemp, x, y);
  lv_obj_set_hidden(btnTemp, isHidden);

  lv_obj_t * label = lv_label_create(btnTemp, NULL);
  lv_label_set_text(label, title);
  lv_obj_align(label, NULL, LV_ALIGN_IN_LEFT_MID, 0, 5);

  lv_imgbtn_set_src(btnTemp, LV_BTN_STATE_REL, "S:/usd/btn.bin");
  lv_imgbtn_set_src(btnTemp, LV_BTN_STATE_PR, "S:/usd/btnPr.bin");
  lv_imgbtn_set_src(btnTemp, LV_BTN_STATE_INA, "S:/usd/btnIna.bin");

  return btnTemp;
}

lv_obj_t * createMeter(lv_obj_t * parent, lv_coord_t x, lv_coord_t y, const char * motorName, const char * motorPort, bool isHidden)
{
  lv_obj_t * motorBackdrop = lv_obj_create(parent, NULL);
  lv_obj_set_size(motorBackdrop, 75, 50);
  lv_obj_set_pos(motorBackdrop, x, y);


  lv_obj_t * lmeter = lv_lmeter_create(motorBackdrop, NULL);
  lv_lmeter_set_range(lmeter, 0, 100);                   /*Set the range*/
  lv_lmeter_set_value(lmeter, 100);                      /*Set the current value*/
  lv_lmeter_set_scale(lmeter, 240, 21);                  /*Set the angle and number of lines*/
  lv_obj_set_size(lmeter, 50, 50);
  lv_obj_align(lmeter, NULL, LV_ALIGN_IN_TOP_LEFT, 25, 5);

  lv_obj_set_hidden(motorBackdrop, isHidden);


  lv_obj_t * label1 = lv_label_create(motorBackdrop, NULL);
  lv_label_set_text(label1, motorName);
  lv_obj_align(label1, NULL, LV_ALIGN_CENTER, 0, 0);

  lv_obj_t * label2 = lv_label_create(motorBackdrop, NULL);
  lv_label_set_text(label2, motorPort);
  lv_obj_align(label2, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, 0);

  return motorBackdrop;
}


//Left
lv_obj_t * leftMain = createBtn(lv_scr_act(), 10, 5, 150, 40, "Left full", false);
lv_obj_t * leftGrab = createBtn(lv_scr_act(), 10, 50, 150, 40, "Left grab", false);
lv_obj_t * leftWinPoint = createBtn(lv_scr_act(), 10, 95, 150, 40, "Left WP", false);
lv_obj_t * leftTall = createBtn(lv_scr_act(), 10, 140, 150, 40, "Left tall", false);
lv_obj_t * emptyL = createBtn(lv_scr_act(), 10, 185, 150, 40, "Empty", false);
//Misc
lv_obj_t * fullWP = createBtn(lv_scr_act(), 165, 5, 150, 40, "Full WP", false);
lv_obj_t * skills = createBtn(lv_scr_act(), 165, 50, 150, 40, "Skills", false);
lv_obj_t * emptyM1 = createBtn(lv_scr_act(), 165, 95, 150, 40, "Empty", false);
lv_obj_t * emptyM2 = createBtn(lv_scr_act(), 165, 140, 150, 40, "Empty", false);
lv_obj_t * emptyM3 = createBtn(lv_scr_act(), 165, 185, 150, 40, "Empty", false);
//Right
lv_obj_t * rightMain = createBtn(lv_scr_act(), 320, 5, 150, 40, "Right full", false);
lv_obj_t * rightGrab = createBtn(lv_scr_act(), 320, 50, 150, 40, "Right grab", false);
lv_obj_t * rightWinPoint = createBtn(lv_scr_act(), 320, 95, 150, 40, "Right WP", false);
lv_obj_t * rightTall = createBtn(lv_scr_act(), 320, 140, 150, 40, "Right tall", false);
lv_obj_t * emptyR = createBtn(lv_scr_act(), 320, 185, 150, 40, "Empty", false);
//Array
lv_obj_t * main_page[15] = {leftMain, leftGrab, leftWinPoint, leftTall, emptyL, fullWP,
                       skills, rightMain, rightGrab, rightWinPoint, rightTall};


std::map<lv_obj_t*, int> map { {leftMain, 1}, {leftGrab, 2}, {leftWinPoint, 3},
                               {leftTall, 4}, {fullWP, 5}, {skills, 6},
                               {rightMain, 7}, {rightGrab, 8}, {rightWinPoint, 9},
                               {rightTall, 10}};
int auton = 0;



#endif
