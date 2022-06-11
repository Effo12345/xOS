#include "api.h"
#include "define.hpp"

static lv_res_t AutonNumber(lv_obj_t * btnTemp)
{
  auton = map[btnTemp];

  return LV_RES_OK;
}
