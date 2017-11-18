#include "avatar.h"
#include "platform.h"

uint8_t avatar_get_y(struct Avatar *avatar){
  return avatar->platform->y_pos;
}

void avatar_bind_platform(struct Avatar *avatar, struct Platform *plat){
  avatar->platform = plat;
}

void avatar_fall(struct Avatar *avatar){
}