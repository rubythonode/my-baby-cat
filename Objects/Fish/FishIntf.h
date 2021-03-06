﻿#pragma once

#ifndef _OBJ_FISH_INTF_
#define _OBJ_FISH_INTF_

#define FISH_LEVEL_1 0
#define FISH_LEVEL_2 1
#define FISH_LEVEL_3 2
#define FISH_LEVEL_4 3

#include <Windows.h>
#include "ImageLayer/ImageLayer.h"

typedef struct _Fish {
  int level;
  int x, y;
  int width, height;
  int isMoving;
  COORD start, end;
  Image *image;
  ImageLayer *imageLayer;

  void (*init)(struct _Fish*);
  void (*update)(struct _Fish*);
  void (*move)(struct _Fish*, int);
  void (*updateRandomLevel)(struct _Fish*);
  // void (*waitForEnd)(struct _Fish*);
  // void (*addBackgroundThread)(struct _Fish*, void (*method)(struct _Fish*));
} Fish;

#endif
