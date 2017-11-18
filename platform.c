#include <stdlib.h>
#include "platform.h"

struct Platform *new_platform(void){
  
  int i;
  struct Platform *platform = malloc(sizeof(struct Platform));
  
  platform->y_pos = 0;
  
  //Initialize Holes
  for (i = 0; i < MAX_N_HOLES-1; i++){
    
    //TODO: MODULUS THE RAND AND CHECK IF IT WORKS
    platform->holes[i].size = rand();
    platform->holes[i].loc = rand();
    
  }
  
  return platform;
}
