#include "main.h"
//#include "display/lvgl.h"
#include "lvglfunctions.hpp"


#include "display/lv_themes/lv_theme_templ.h"
#include "display/lv_themes/lv_theme_default.h"
#include "display/lv_themes/lv_theme_alien.h"
#include "display/lv_themes/lv_theme_night.h"
#include "display/lv_themes/lv_theme_mono.h"
#include "display/lv_themes/lv_theme_zen.h"
#include <string>

lv_style_t buttonREL;
lv_style_t buttonPR;
lv_style_t imgBtn;
lv_style_t meter;

void InterfaceInit()
{
  //Sets theme to night
  lv_theme_t * th = lv_theme_night_init(65, NULL);
  lv_theme_set_current(th);

  //Initializes state of disabled button
  lv_btn_set_state(emptyL, LV_BTN_STATE_INA);
  lv_btn_set_state(emptyM1, LV_BTN_STATE_INA);
  lv_btn_set_state(emptyM2, LV_BTN_STATE_INA);
  lv_btn_set_state(emptyM3, LV_BTN_STATE_INA);
  lv_btn_set_state(emptyR, LV_BTN_STATE_INA);
  /*
  // DISPLAY UPDATE LOOP
  while(true){
    // HOME SCREEN ACTIONS
    if(lv_scr_act() == scr0){
      // Set values of battery bars




      pros::delay(100);
    }
  }
  */
}
