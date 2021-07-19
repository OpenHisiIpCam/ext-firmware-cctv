#ifndef KMOD_H
#define KMOD_H
/*
0000000000000000 l    d  .data  0000000000000000 .data
0000000000000000 g       .data  0000000000000000 _binary_hi3518_sio_ko_start
00000000000050bc g       .data  0000000000000000 _binary_hi3518_sio_ko_end
00000000000050bc g       *ABS*  0000000000000000 _binary_hi3518_sio_ko_size
 */

#include "stddef.h"

typedef struct
{
  char* name;
  const char* start;
  char* end;
  size_t size;
  char* params;
} kmod_item_t;

int
kmod_load(const kmod_item_t module);
int
kmod_unload(const kmod_item_t module);

#endif /*KMOD_H*/
